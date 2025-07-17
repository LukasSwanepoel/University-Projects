#include <fstream>
#include <iostream>
#include <sstream>

int*** myArr = NULL;
int** numCols = NULL;
int numRows = 0;

void clearArray() {
    if (myArr != NULL){
        for (int i=0;i<numRows;i++){
                for (int r=0;r<*numCols[i];r++){
                    delete myArr[i][r];
                }
            delete[] myArr[i];
        }
        delete[] myArr;
        myArr = NULL;
    }
    
    if (numCols!= NULL){
        for(int i=0;i<numRows;i++){
            delete [] numCols[i];
            }
        delete [] numCols;
    }   
    numCols=NULL;
    std::cout << "Deleted array with "<< numRows <<" rows" <<std::endl;
}

void populateFromFile(std::string fileName) {
    if (myArr != NULL)
    {
    clearArray();
    }
    std::fstream file(fileName.c_str());
    std:: string line;
    //Read lines into the file
    while (std::getline(file,line)){
        numRows++;
    }
    file.close();
    //numcols memory allocation
    numCols = new int*[numRows];
    for (int i=0;i<numRows;i++){
        numCols[i]= new int;
    }
    //populate and read file
    int cols =0;int rows =0;
    std::fstream file2(fileName.c_str());
    while(getline(file2,line))
    {
        cols = 0;
        if(line.length()==0)
        {
            *numCols[rows]=0;
        }
        else
        {
            for(int i=0;i<line.length();i++){
                if(line[i]==','){
                    cols++;
                }
            }
            *numCols[rows]= ++cols;
        }
        rows++;
    }
    file2.close();
    rows=0;
   //myArr memory allocation
    myArr= new int**[numRows];
    for(int i=0;i<numRows;i++){
        myArr[i]=new int*[*numCols[i]];
        for(int r=0;r<*numCols[i];r++){
            myArr[i][r]= new int();
        }
    }
    //populate and read file
    std::string input;
    int pos = 0;
    int numColrows = 0;
    std::fstream file3(fileName.c_str());
    //population starts here
    rows =0;
    cols=0;
    while (std::getline(file3,line))
    {   
        if (numCols[rows] ==0){
            rows++; 
            continue;
        }  
        else{   
            line = line + ",";
            while (line.length() != 0)
            {
                pos = line.find(",");
                std::stringstream(line.substr(0,pos))>> *myArr[rows][cols];
                line.erase(0,pos+1);
                cols++;
            }
             rows++;
            cols=0;
        }
    }
    
   file3.close();
   std::cout<<"Created array from textfile with "<<numRows<<" rows"<<std::endl;
}

void populateFromTerminal() {
    if (myArr !=NULL){  //Clear Array
        clearArray();
    }

    std::cin >> numRows;    //populate numRows

    numCols =new int *[numRows];
    myArr = new int **[numRows];
    for (int c = 0; c < numRows; c++)
    {
        numCols[c] = new int;   //Allocate memory for num cols
    }
    
    std::string input;
    std::string input2;
    int pos = 0;
    int numColrows = 0;
    for (int i=0;i<numRows;i++){        
        std::cin>> input;
        input2 = input + ',';
        pos = 0;
        numColrows = 0;
        for (int r=0;r<input.length()+1;r++){            
            if(input.find(',') != std::string::npos)
            {
                pos = input.find(',');
                numColrows++;
                input.erase(0,pos+1);
            }       
        }        

        *numCols[i]= numColrows+1; //Populate numCols
        
        
        myArr[i]= new int*[*numCols[i]];
        for (int c = 0; c < *numCols[i]; c++)
        {
             myArr[i][c] = new int();   //Allocate memory for myArr
        }       

        for (int c = 0; c <= input2.length()+1; c++)
        {
            if((input2.find(',') != std::string::npos))
            {
                pos = input2.find(',');
                std::stringstream(input2.substr(0, pos)) >> *myArr[i][c];    //Populate myArr
                input2.erase(0,pos+1);
            }  
        }        
    }
    
    std::cout <<"Created array from terminal with "<<numRows<<" rows" <<std::endl;
}

void printArr() {
 if (myArr==NULL){
    std::cout << "Array is empty" << std::endl;
 } else {
    for (int i=0;i<numRows;i++){
        for (int r=0;r<*numCols[i];r++){     
            std::cout << *myArr[i][r];
            if (r < *numCols[i]-1){
                std::cout<<",";
            }
        }
        std::cout << std::endl;
        }
    }
 }

void printArrStructure() {
if (myArr==NULL){
    std::cout << "Array is empty" <<std::endl;
}else{
    std::cout<<numRows <<":[";
    for (int i=0;i<numRows;i++){
        if (*numCols[i]==0){
            std::cout<<"0";
        }else{
          std::cout <<*numCols[i];
        }
        if(i<numRows-1){
            std::cout<<",";
        }
    }
    std::cout<<"]"<<std::endl;
}
}

int main() {
    populateFromFile("input.txt");
   //populateFromTerminal();
    printArr();
    printArrStructure();
    clearArray();
    return 0;
}
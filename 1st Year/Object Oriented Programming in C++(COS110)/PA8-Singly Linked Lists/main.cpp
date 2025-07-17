#include "List.h"
#include "Node.h"
#include "SinglyLinked.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    Node<int> guineaPig(8);
    std::cout<<&guineaPig<<std::endl;
    if (guineaPig==8){std::cout<<"operator== works"<<std::endl;}
    std::cout<<"getData displays: "<<guineaPig.getData()<<std::endl;
    //test list from here
    SinglyList<std::string> guineaList;
    std::cout<<"empty guineaList: "<<std::endl;
    std::cout<<"Wonderland: "<<&guineaList<<std::endl;
    guineaList.insert("Tweedle Dumb",0);
    guineaList.insert("Tweedle Dee",0); 
    guineaList.insert("And The Other One",2);
    std::cout<<&guineaList<<std::endl;
    std::cout<<"The Other One was removed from idx "<<guineaList.remove("And The Other One")<<std::endl;
    std::cout<<"The Other One can't be removed "<<guineaList.remove("And The Other One")<<std::endl;
    std::cout<<"Still Wonderland but the queen got mad at the other one: "<<&guineaList<<std::endl;
    std::cout<<"[2]="<<guineaList[2]<<std::endl<<" [-3]="<<guineaList[-3]<<" and size()= "<<guineaList.size()<<std::endl;
    std::cout<<"From the North, Tweedle Dee lives at index "<<guineaList.getIndexFromFront("gcud")<<std::endl;
    std::cout<<"From the South, Tweedle Dee lives at index "<<guineaList.getIndexFromRear("hvjhv")<<std::endl;
    std::cout<<"Biggest: "<<guineaList.findBiggest()<<std::endl;
    std::cout<<"Smallest: "<<guineaList.findSmallest()<<std::endl;

    std::cout<<"run check\n";
    //testing for contains
    if (guineaList.contains("The Other One")==false){std::cout<<"contains checks for falsehood correctly"<<std::endl;}
    if (guineaList.contains("Tweedle Dee")==true){std::cout<<"contains checks for truth correctly"<<std::endl;}
    


    //testing for ()
    std::string tweedleDee="Tweedle Dee", spaghetti="hfwskhnf";
    std::string* stPtr = &spaghetti;
    std::cout<<"letter spaghetti does not exist, therefore () returns "<<guineaList(stPtr)<<std::endl;
    stPtr = &tweedleDee;
    std::cout<<"but Tweedle Dee does exist, so () returns "<<guineaList(stPtr)<<std::endl;
    guineaList.clone();
    guineaList.sort(false);
    guineaList.sort(true);

}
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    //test Tuple
    Tuple<std::string,std::string> name("Lukas","Swanepoel");
    std::cout<<"Tuple name: "<<name.getFirst()<<endl;
    std::cout<<"Tuple surname: "<<name.getSecond()<<endl;

    //test dictionary
    Dictionary<std::string, int> database;
    database.set("Tweedle Dee", 60);
    database.set("Tweedle Dumb", 20);
    database.set("The Other One", 20);

    std::cout<<database.getKeys()[0]<<"'s score is "<<database.at("Tweedle Dee")<<endl;
    database.removeAt("The Other One");
    if (database.exists("The Othe One")==false)
    {
        std::cout<<"The other one doesn't exist"<<endl;
    }
    database.swap("Tweedle Dee","Tweedle Dumb");
    std::cout<<"Tweedle Dee: "<<database.at("Tweedle Dee")<<" Tweedle Dumb: "<<database.at("Tweedle Dumb")<<endl;
    std::cout<<"CurrSize: "<<database.size()<<endl;
    database.set("Tweedle Dumb",20);
    Tuple<int,std::string*> keyswith20 = database.keysWithValue(20);//remmeber to clear memory
    std::cout<<"keyswith20 first: "<<keyswith20.getSecond()[0]<<" second: "<<keyswith20.getSecond()[1]<<" size: "<<keyswith20.getFirst()<<endl;
    if (keyswith20==keyswith20)
    {
        std::cout<<"The == operator works"<<endl;
    }

    database.clear();
    delete [] keyswith20.getSecond();

    //test scoreboard
    ScoreBoard<int> scores;
    scores.addScore("Alpha",8);
    scores.addScore("Beta",12);
    scores.addScore("Charlie",12);
    scores.addScore("Delta",10);
    scores.addScore("Echo",15);

    scores.removeScore("Echo");

    std::cout<<"Delta's score is: "<<scores.getScore("Delta")<<endl;
    Tuple<int,std::string*> poggers = scores.getHighScoreUser();
    std::cout<<"The highscore havers are "<<poggers.getSecond()[0]<<" and "<<poggers.getSecond()[1]<<". These are the top "<<poggers.getFirst()<<endl;
    delete [] poggers.getSecond();


    return 0;
}

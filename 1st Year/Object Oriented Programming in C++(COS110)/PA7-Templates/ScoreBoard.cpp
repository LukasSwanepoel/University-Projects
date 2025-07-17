#ifndef SCOREBOARD_CPP
#define SCOREBOARD_CPP
#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include <string>

template<class T>
ScoreBoard<T>::ScoreBoard()
{}

template<class T>
ScoreBoard<T>::~ScoreBoard()
{}

template<class T>
void ScoreBoard<T>::addScore(std::string user, T score)
{
    if (scores.exists(user))
    {
        if (scores.at(user)<score)
        {
            scores.set(user,score);
        }
    }
    else
    {
        scores.set(user,score);
    }
}

template<class T>
void ScoreBoard<T>::removeScore(std::string user)
{
    scores.removeAt(user);
}

template<class T>
T ScoreBoard<T>::getScore(std::string user)
{
    return scores.at(user);
}

template<class T>
T ScoreBoard<T>::getHighScore()
{
    T highest= scores.at(scores.getKeys()[0]);
    for (int i=0; i<scores.size(); i++)
    {
        if (scores.at(scores.getKeys()[i])>highest)
        {
            highest = scores.at(scores.getKeys()[i]);
        }
    }
    return highest;
}

template<class T>
Tuple<int,std::string*> ScoreBoard<T>::getHighScoreUser()
{
    return scores.keysWithValue(getHighScore());
}

;
#endif
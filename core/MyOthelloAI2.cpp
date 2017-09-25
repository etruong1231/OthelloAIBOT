

#include "MyOthelloAI2.hpp"
#include <ics46/factory/DynamicFactory.hpp>
//#include <iostream>
//#include <random>


ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI, eddiet1::MyOthelloAI2, "5 Inches Deep (EXP)");

std::pair <int,int> eddiet1::MyOthelloAI2::chooseMove(const OthelloGameState& state)
{
    std::pair<int, int> bestMove;
    int highestPoints = -100;
    
    //this help identify who is the AI
    std::string AI_player = "";
    if(state.isWhiteTurn())
        AI_player = "white";
    else
        AI_player = "black";

    for(int x = 8; x--;)
    {
        for(int y = 8;y--;)
        {
            if(state.isValidMove(x,y))
            {
                std::unique_ptr<OthelloGameState> possibleBoards = state.clone();
                possibleBoards->makeMove(x,y);
                int possiblePoints = search(possibleBoards, 5, AI_player);
                //std:: cout << possiblePoints << std::endl;
                //wants the corner pieces
                if(checkforCornerPiece(x,y))
                    return std::make_pair(x,y);
                //try not to take pieces that are near corners
                if(!checkforBeforeCornerPiece(x,y) && possiblePoints >= highestPoints)
                {
                    highestPoints = possiblePoints;
                    bestMove.first = x;
                    bestMove.second = y;
                }       
                //in case theres only corner/before corner pieces
                else if(highestPoints == -100)
                {
                    bestMove.first = x;
                    bestMove.second = y;
                }       

            }   
       }
    }
    //final best move
    return bestMove;

}
// gets the all possible point combination 
int eddiet1::MyOthelloAI2::search(std::unique_ptr<OthelloGameState>& state, int depth, std::string AI)
{
    
    int myPoints = -100;
    int enemyPoints = 100;
    int points;
    //once the depth is zero itll check the differences of points
    if(depth == 0)
       return evaluate_points(state, AI);
    else
    {
        //its the AI turn get all possible points and possiblities
        if((state->isWhiteTurn() && AI == "white")|| (state->isBlackTurn() && AI == "black"))
        {
            //all moves
            for(int x = 8; x--;)
            {
                for(int y = 8; y--;)
                {
                    if(state->isValidMove(x,y))
                    {
                        //create a clone pointer to test out new possible tiltes
                        std::unique_ptr<OthelloGameState> new_state = state->clone();
                        new_state->makeMove(x,y);
                        points = search(new_state,depth-1,AI);
                        if(points > myPoints)
                        myPoints = points;
                    }
                }
            }
            return myPoints;
        }
        //opponent turn, check for all possible points
        else
        {
            for(int x= 8; x--;)
            {
                for(int y = 8; y--;)
                {
                    if(state->isValidMove(x,y))
                    {
                        std::unique_ptr<OthelloGameState> new_state = state->clone();
                        new_state->makeMove(x,y);
                        points = search(new_state,depth-1,AI);
                        if(points < enemyPoints)
                            enemyPoints = points;
                    }
                }
            }
            return enemyPoints;
         }
     }
    
}
int eddiet1::MyOthelloAI2::evaluate_points(std::unique_ptr<OthelloGameState> & state, std::string AI)
{
    if(AI == "white")
    {
        return state->whiteScore() - state->blackScore();
    }
    else
        return state->blackScore() - state->whiteScore();
}
bool eddiet1::MyOthelloAI2::checkforCornerPiece(int x, int y)
{
    if((x == 0 && y == 0)|| (x == 7 && y == 0) || (x == 0 || y == 7) || ( x== 7 && y == 7))
        return true;
    else 
        return false;

}
bool eddiet1::MyOthelloAI2::checkforBeforeCornerPiece(int x, int y)
{
    if((x== 0 && y == 1) || (x == 0 && y == 6) || (x == 1 && y == 6) ||
    (x == 1 && y == 7) || (x ==1 && y== 1) || (  x == 1 & y == 0) || (x == 7 && y == 1) ||
    ( x == 6 && y == 1) || (x == 6 && y == 0) || (x == 7 && y == 6) ||
    ( x == 6 && y == 6) || (x == 6 && y == 7))
        return true;
    return false;
}

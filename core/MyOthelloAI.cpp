

#include "MyOthelloAI.hpp"
#include <ics46/factory/DynamicFactory.hpp>
#include <iostream>
#include <random>

ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI, eddiet1::MyOthelloAI, "4 INCHES DEEP (Required)");

std::pair <int,int> eddiet1::MyOthelloAI::chooseMove(const OthelloGameState& state)
{
    std::pair<int, int> bestMove;
    int highestPoints = -100;
    int board_width = state.board().width();
    int board_height = state.board().height();
    int depth = 0;
    
    //this help identify who is the AI
    std::string AI_player = "";
    if(state.isWhiteTurn())
        AI_player = "white";
    else
        AI_player = "black";

    //gets all possible moves
    std::vector<std::pair<int,int>> allValidMoves = allPossibleMoves(state,board_width, board_height);
    
    int movesAmount = allValidMoves.size();
    if (movesAmount <= 5)
        depth = 5;
    else
        depth = 3;
    //random shuffle so moves arent always the same if they return same high point
    random_shuffle(allValidMoves.begin(), allValidMoves.end());
    for(auto moves: allValidMoves)
    {
        std::unique_ptr<OthelloGameState> possibleBoards = state.clone();
        possibleBoards->makeMove(moves.first, moves.second);
        int possiblePoints = search(possibleBoards,depth ,AI_player);
        //std:: cout << possiblePoints << std::endl;
        //wants the corner pieces
        
        if(checkforCornerPiece(moves.first,moves.second,board_width, board_height))
            return std::make_pair(moves.first,moves.second);
        //try not to take pieces that are near corners
        if(!checkforBeforeCornerPiece(moves.first,moves.second,board_width,board_height) && possiblePoints >= highestPoints)
        {
            highestPoints = possiblePoints;
            bestMove.first = moves.first;
            bestMove.second = moves.second;
        }
        //if the corners are taken then the pieces before corner are safe
        else if(cornerTaken(possibleBoards,moves.first,moves.second, board_width, board_height) && possiblePoints >= highestPoints)
        {
            highestPoints = possiblePoints;
            bestMove.first = moves.first;
            bestMove.second = moves.second;

        }
        //if no more possible moves after corner are taken and only before corner is left
        else if(highestPoints == -100)
        {   
            bestMove.first = moves.first;
            bestMove.second = moves.second;
        }

    }
    //final best move
    return bestMove;

    

}
//get all beginning first possibleMoves
std::vector<std::pair<int,int>> eddiet1::MyOthelloAI::allPossibleMoves(const OthelloGameState& state, int board_width, int board_height)
{
    std::vector<std::pair<int,int>> allValidsMoves;
        
    for(int x=0; x < board_width; x++)
    {
        for(int y=0; y < board_height; y++)
        {
            if(state.isValidMove(x,y))
                allValidsMoves.push_back(std::make_pair(x,y));
        }

    }
    return allValidsMoves;


}
// Method overloading so we can just pass a pointer into it
std::vector<std::pair<int,int>> eddiet1::MyOthelloAI::allPossibleMoves(std::unique_ptr<OthelloGameState> & state, int board_width, int board_height)
{
    std::vector<std::pair<int,int>> allValidsMoves;
    for(int x= 0; x < board_width; x++)
    {
        for(int y=0; y < board_height; y++)
        {
            if(state->isValidMove(x,y))
            {
                allValidsMoves.push_back(std::make_pair(x,y));
            }
        }
    }
    return allValidsMoves;

}
// gets the all possible point combination 
int eddiet1::MyOthelloAI::search(std::unique_ptr<OthelloGameState>& state, int depth, std::string AI)
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
            std::vector<std::pair<int,int>> validMoves = allPossibleMoves(state, state->board().width(), state->board().height());      
         
           //iterate trhough the moves
            for(auto moves: validMoves)
            {   
                //create a clone pointer to test out new possible tiltes
                std::unique_ptr<OthelloGameState> new_state = state->clone();
                new_state->makeMove(moves.first,moves.second);
                points = search(new_state,depth-1,AI);
                if(points > myPoints)
                    myPoints = points;
            }
            
            return myPoints;
        }
        //opponent turn, check for all possible points
        else
        {
            std::vector<std::pair<int,int>> validMoves = allPossibleMoves(state, state->board().width(), state->board().height()); 
          
                for(auto moves: validMoves)
                {
                    std::unique_ptr<OthelloGameState> new_state = state->clone();
                    new_state->makeMove(moves.first,moves.second);
                    points = search(new_state,depth-1,AI);
                    if(points < enemyPoints)
                        enemyPoints = points;

                }
           
            return enemyPoints;
         }
     }
    
}
int eddiet1::MyOthelloAI::evaluate_points(std::unique_ptr<OthelloGameState> & state, std::string AI)
{
    if(AI == "white")
    {
        return state->whiteScore() - state->blackScore();
    }
    else
        return state->blackScore() - state->whiteScore();
}
bool eddiet1::MyOthelloAI::checkforCornerPiece(int x, int y, int width, int height)
{
    if((x == 0 && y == 0 )||( x == width-1 && y == 0) || ( x == 0 && y == height-1) || ( x== width-1 &&y == height-1))
        return true;
    else 
        return false;

}
bool eddiet1::MyOthelloAI::checkforBeforeCornerPiece(int x, int y,int width, int height)
{
    if((x== 0 && y == 1) || (x == 0 && y == height - 2) || (x == 1 && y == height-2) ||
    (x == 1 && y == height-1) || (x ==1 && y== 1) || (  x == 1 & y == 0) || (x == width-1 && y == 1) ||
    ( x == width - 2 && y == 1) || (x == width - 2 && y == 0) || (x == width - 1 && y == height -2) ||
    ( x == width -2 && y == height -2) || (x == width - 2 && y == height-1))
        return true;
    return false;
}
bool eddiet1::MyOthelloAI::cornerTaken(std::unique_ptr<OthelloGameState> & state, int x, int y, int width, int height)
{   
    if((x== 1 && y == 0) || ( x == width-2 && y == 0))
    {
        if((state->board().cellAt(0,0) != OthelloCell::empty) && (state->board().cellAt(width-1,0) != OthelloCell::empty))
            return true;
    }
    else if((x == 0 && y == 1) || (x == 0 && y == height - 2))
    {
        if((state->board().cellAt(0,0) != OthelloCell::empty) && (state->board().cellAt(0,height-1) != OthelloCell::empty))
            return true;
    }
    else if (( x == 1 && y == height-1) || ( x == width-2 && y == height - 1))
    {
        if((state->board().cellAt(0,height-1) !=  OthelloCell::empty) && (state->board().cellAt(width-1,height-1)!= OthelloCell::empty))
            return true;
    }
    else if (( x == width -1 && y == 1) || ( x == width -1 && y == height - 2))
    {
        if (( state->board().cellAt(width-1,0) != OthelloCell::empty) && (state->board().cellAt(width-1,height-1) != OthelloCell::empty))
            return true;
    }
    else if ((x== 1 && y == 1) || ( x== width-2 && y == height -2))
    {
        if ((state->board().cellAt(0,0) != OthelloCell::empty) && (state->board().cellAt(width-1,height-1) != OthelloCell::empty))
            return true;
    }
    else if (( x == width-2 && y == 1 ) || (x == 1 && y == height-2))
    {
        if ((state->board().cellAt(0,height-1) != OthelloCell::empty) && (state->board().cellAt(width-1,0) != OthelloCell::empty))
            return true;
    }
    return false;
}

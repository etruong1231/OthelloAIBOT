


#include "OthelloAI.hpp"
#include <vector>

namespace eddiet1{

    class MyOthelloAI2: public OthelloAI
    {
        public:
           virtual std::pair <int,int> chooseMove(const OthelloGameState& state);
           int evaluate_points(std::unique_ptr<OthelloGameState>& state, std::string AI);

           //std::vector<std::pair<int,int>> allPossibleMoves(const OthelloGameState& state,int board_width, int board_height);

           //std::vector<std::pair<int,int>> allPossibleMoves(std::unique_ptr<OthelloGameState>& state, int board_width, int board_height);

           int search(std::unique_ptr<OthelloGameState> &state, int depth,std::string AI);
           bool checkforCornerPiece(int x, int y); 
   
   
          bool checkforBeforeCornerPiece(int x, int y);

    };
}

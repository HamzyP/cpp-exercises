#pragma once
#include <utility>
#include <stdexcept>

namespace queen_attack {
class chess_board{
    private:
        std::pair <int, int> m_white;
        std::pair <int, int> m_black;

    static constexpr bool is_valid_position (std::pair<int, int> pos){
        auto&& [r, c] = pos;
        return (r >=0 && r<=7 && c>=0 && c<= 7);
    }
    
    public:
        constexpr chess_board(std::pair <int, int> white,std::pair <int, int>  black) : m_white(white), m_black(black){
            if ( !is_valid_position(white) || !is_valid_position(black)){
                throw std::domain_error("position not on board");
            } if (white == black){
                throw std::domain_error("cannot be the same position");
            } 
                };

         constexpr bool can_attack() const{
            auto&& [wr, wc] = m_white;
            auto&& [br, bc] = m_black;

             // when diff in rows == diff in cols, diagonal
             int d_row = wr - br;
             int d_col = wc - bc;
             return (d_row == 0 || d_col == 0 || d_row == d_col || d_row == -d_col);

        }
         constexpr const std::pair <int, int>& white() const{
                return m_white;
        }
         constexpr const std::pair <int, int>& black() const{
                return m_black;
        }
    
};

}  // namespace queen_attack

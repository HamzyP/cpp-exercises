#pragma once
#include <utility>
#include <stdexcept>

namespace queen_attack {
class chess_board{
    private:
        std::pair <int, int> m_white;
        std::pair <int, int> m_black;
    public:
        chess_board(std::pair <int, int> white,std::pair <int, int>  black){
            if (white.first<0 || white.second <0 || black.first <0 || black.second < 0){
                throw std::domain_error("cannot have a negative position");
            } else if (white.first == black.first && white.second == black.second){
                throw std::domain_error("cannot be the same position");
            } else if (white.first > 7 || white.second >7 || black.first >7 || black.second > 7){
                throw std::domain_error("cannot be that big");
            }

            m_white = white;
            m_black = black;
                };

         bool can_attack() const{
                if (m_white.first == m_black.first || m_white.second == m_black.second){
                return true;
                } else if (m_white.first - m_black.first == m_white.second - m_black.second ||m_white.first + m_white.second == m_black.first + m_black.second ){
                return true;
                } else{
                return false;
                }
        }
         std::pair <int, int> white() const{
                return m_white;
        }
         std::pair <int, int> black() const{
                return m_black;
        }
    
};

}  // namespace queen_attack

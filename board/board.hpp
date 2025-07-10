#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstddef>
#include <iostream>
#include <array>

#include "../node/node.hpp"

namespace tictactoe {
    enum Player {
        None,  // 0
        O,     // 1
        X      // 2
    };

    constexpr std::array<Player, 9> initial_board = {Player::None, Player::None, Player::None,
                                                     Player::None, Player::None, Player::None,
                                                     Player::None, Player::None, Player::None};

    class Board {
      public:
      inline Board() {
          state = initial_board;
          num_occupied = 0;
      }

      inline const Player& at(const size_t &idx) const  {
        return state[idx];
      }

      inline Player& at(const size_t &idx)   {
        return state[idx];
      }

      inline bool is_full() const {
          return num_occupied == 9;
      }

      inline bool is_winner(const Player &player) const {
          constexpr size_t winning_cases[8][3] = {
              {0, 1, 2},
              {3, 4, 5},
              {6, 7, 8},
              {0, 3, 6},
              {1, 4, 7},
              {2, 5, 8},
              {0, 4, 8},
              {2, 4, 7},
          };

          for (size_t i = 0; i < 8; i++) {

              bool response = true;
              for(size_t j = 0; j < 3; j++)
                  response &= player == state.at(winning_cases[i][j]);

             if (response)
                return true;
          }

          return false;
      }

      inline bool is_draw() const {
          return is_full() && !is_winner(Player::X) && !is_winner(Player::O);
      }

      inline std::vector<noderef> possibilities() const {
        std::vector<noderef> availables;
        availables.reserve(9);


        for (size_t i = 0; i < 9; i++)
            if (state[i] == Player::None)
                availables.emplace_back(Node::create(i));

        return availables;
      }

      inline friend std::ostream& operator<< (std::ostream& os, const Board &board) {
        os << "[ ";
        for (size_t i = 0; i < 9; i++)
           os << board.at(i) << " ";

        os << "]";
        return os;
      }

      private:
      std::array<Player, 9> state;
      size_t num_occupied;
    };
}

#endif

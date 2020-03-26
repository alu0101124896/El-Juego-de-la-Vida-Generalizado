#include "../include/cellX.hpp"

#include <iostream>

#include "../include/board.hpp"
#include "../include/cell.hpp"

CellX::CellX() {}

CellX::CellX(int i, int j) { set_i_j(i, j); }

int CellX::get_state() const { return 4; }

int CellX::update_state(Board& board) {
  if (get_neighbours() == 1) {
    return get_state();
  } else {
    board.decrement_population();
    return 0;
  }
}

std::ostream& CellX::print_state(std::ostream& os) const {
  return os << 'X';
}

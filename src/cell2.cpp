#include "../include/cell2.hpp"

#include <iostream>

#include "../include/board.hpp"
#include "../include/cell.hpp"

Cell2::Cell2() {}

Cell2::Cell2(int i, int j) { set_i_j(i, j); }

int Cell2::get_state() const { return 2; }

int Cell2::update_state(Board& board) {
  if ((get_neighbours() == 2) || (get_neighbours() == 4) ||
      (get_neighbours() == 5)) {
    return get_state();
  } else {
    return 0;
  }
}

std::ostream& Cell2::print_state(std::ostream& os) const {
  return os << get_state();
}

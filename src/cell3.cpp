#include "../include/cell3.hpp"

#include <iostream>

#include "../include/board.hpp"
#include "../include/cell.hpp"

Cell3::Cell3() {}

Cell3::Cell3(int i, int j) { set_i_j(i, j); }

int Cell3::get_state() const { return 3; }

int Cell3::update_state(Board& board) {
  if ((get_neighbours() == 1) || (get_neighbours() == 5)) {
    return get_state();
  } else {
    board.decrement_population();
    return 0;
  }
}

std::ostream& Cell3::print_state(std::ostream& os) const {
  return os << get_state();
}

#include "../include/cell1.hpp"

#include <iostream>

#include "../include/board.hpp"
#include "../include/cell.hpp"

Cell1::Cell1() {}

Cell1::Cell1(int i, int j) { set_i_j(i, j); }

int Cell1::get_state() const { return 1; }

int Cell1::update_state(Board& board) {
  if ((get_neighbours() == 2) || (get_neighbours() == 3)) {
    return get_state();
  } else {
    board.decrement_population();
    return 0;
  }
}

std::ostream& Cell1::print_state(std::ostream& os) const {
  return os << get_state();
}

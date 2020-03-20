#pragma once

#include <iostream>

#include "board.hpp"
#include "cell.hpp"

class Cell3 : public Cell {
 public:
  Cell3();
  Cell3(int, int);

  int get_state() const;
  int update_state(Board&);

  std::ostream& print_state(std::ostream&) const;
};

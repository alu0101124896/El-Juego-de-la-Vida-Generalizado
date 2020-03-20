#pragma once

#include <iostream>

#include "board.hpp"
#include "cell.hpp"

class Cell2 : public Cell {
 public:
  Cell2();
  Cell2(int, int);

  int get_state() const;
  int update_state(Board&);

  std::ostream& print_state(std::ostream&) const;
};

#pragma once

#include <iostream>

#include "board.hpp"
#include "cell.hpp"

class Cell1 : public Cell {
 public:
  Cell1();
  Cell1(int, int);

  int get_state() const;
  int update_state(Board&);

  std::ostream& print_state(std::ostream&) const;
};

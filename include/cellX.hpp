#pragma once

#include <iostream>

#include "board.hpp"
#include "cell.hpp"

class CellX : public Cell {
 public:
  CellX();
  CellX(int, int);

  int get_state() const;
  int update_state(Board&);

  std::ostream& print_state(std::ostream&) const;
};

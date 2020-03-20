#pragma once

#include <iostream>

#include "board.hpp"

class Board;

class Cell {
 private:
  int i, j;  // Position on board
  int neighbours;

 public:
  Cell();
  Cell(int, int);
  static Cell* create_cell(int, int, int);

  virtual int get_state() const;
  int get_i() const;
  int get_j() const;
  int get_neighbours() const;

  void set_i_j(int, int);

  virtual void count_neighbours(const Board&);
  virtual int update_state(Board&);

  virtual std::ostream& print_state(std::ostream&) const;
};

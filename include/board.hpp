#pragma once

#include "cell.hpp"

#include <iostream>
#include <vector>

class Cell;

class Board {
 private:
  int n, m;  // Dimentions of board
  int population;
  std::vector<std::vector<Cell *>> grid;

 public:
  Board();
  Board(int, int);

  int get_n() const;
  int get_m() const;
  int get_population() const;
  Cell *get_cell(int, int);
  Cell *get_cell(int i, int) const;

  void set_cell(int, int, int);

  void increment_population();
  void decrement_population();
  void print();
};

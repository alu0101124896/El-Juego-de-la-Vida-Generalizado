#include "../include/board.hpp"

#include <iostream>
#include <vector>

#include "../include/cell.hpp"

Board::Board() {}

Board::Board(int _n, int _m) {
  n = _n;
  m = _m;
  population = 0;
  for (int i = 0; i < n + 2; i++) {
    std::vector<Cell *> temp_vect;
    for (int j = 0; j < m + 2; j++) {
      temp_vect.push_back(new Cell(i, j));
    }
    grid.push_back(temp_vect);
  }
}

int Board::get_n() const { return n; }

int Board::get_m() const { return m; }

int Board::get_population() const { return population; }

Cell *Board::get_cell(int i, int j) { return grid.at(i).at(j); }

Cell *Board::get_cell(int i, int j) const { return grid.at(i).at(j); }

void Board::set_cell(int i, int j, int k) {
  delete grid.at(i).at(j);
  grid.at(i).at(j) = Cell::create_cell(i, j, k);
}

void Board::increment_population() { population++; }

void Board::decrement_population() { population--; }

void Board::print() {
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (i == 0 && j == 0) {
        std::cout << "╔";
      } else if (i == 0 && j == m + 1) {
        std::cout << "╗";
      } else if (i == n + 1 && j == 0) {
        std::cout << "╚";
      } else if (i == n + 1 && j == m + 1) {
        std::cout << "╝";
      } else if (i == 0 || i == n + 1) {
        std::cout << "═";
      } else if (j == 0 || j == m + 1) {
        std::cout << "║";
      } else {
        grid.at(i).at(j)->print_state(std::cout);
      }
    }
    std::cout << "\n";
  }
}

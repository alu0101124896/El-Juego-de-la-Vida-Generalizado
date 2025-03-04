#include "../include/cell.hpp"

#include <iostream>

#include "../include/board.hpp"
#include "../include/cell1.hpp"
#include "../include/cell2.hpp"
#include "../include/cell3.hpp"
#include "../include/cellX.hpp"

Cell::Cell() {}

Cell::Cell(int _i, int _j) {
  i = _i;
  j = _j;
}

Cell* Cell::create_cell(int i, int j, int k) {
  switch (k) {
    case 1:
      return new Cell1(i, j);
    case 2:
      return new Cell2(i, j);
    case 3:
      return new Cell3(i, j);
    case 4:
      return new CellX(i, j);
    default:
      return new Cell(i, j);
  }
}

int Cell::get_state() const { return 0; }

int Cell::get_i() const { return i; }

int Cell::get_j() const { return j; }

int Cell::get_neighbours() const { return neighbours; }

void Cell::set_i_j(int _i, int _j) {
  i = _i;
  j = _j;
}

void Cell::count_neighbours(const Board& board) {
  neighbours = 0;
  if (board.get_cell(i - 1, j - 1)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i - 1, j)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i - 1, j + 1)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i, j - 1)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i, j + 1)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i + 1, j - 1)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i + 1, j)->get_state() != 0) {
    neighbours++;
  }
  if (board.get_cell(i + 1, j + 1)->get_state() != 0) {
    neighbours++;
  }
}

int Cell::update_state(Board& board) {
  if (get_neighbours() == 3) {
    board.increment_population();
    return 1;
  } else if ((get_neighbours() == 3) || (get_neighbours() == 6) ||
             (get_neighbours() == 8)) {
    board.increment_population();
    return 2;
  } else if ((get_neighbours() == 3) || (get_neighbours() == 4) ||
             (get_neighbours() == 6)) {
    board.increment_population();
    return 3;
  } else if (get_neighbours() == 1) {
    board.increment_population();
    return 4;
  } else {
    return 0;
  }
}

std::ostream& Cell::print_state(std::ostream& os) const { return os << ' '; }

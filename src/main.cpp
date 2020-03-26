#include <chrono>
#include <iostream>
#include <thread>

#include "../include/board.hpp"
#include "../include/cell.hpp"

// 146x633 - Desktop Arch Linux
// 34x54 - Note 8T Android

int main() {
  int n_size, m_size, turns, initial_cells, i_pos, j_pos, initial_state;

  std::cout << "Dimensiones de la malla:\n";
  std::cout << "N: ";
  std::cin >> n_size;
  std::cout << "M: ";
  std::cin >> m_size;
  std::cout << "Numero de turnos: ";
  std::cin >> turns;

  Board board(n_size, m_size);

  std::cout << "Numero de celulas madre: ";
  std::cin >> initial_cells;
  for (int k = 0; k < initial_cells; k++) {
    std::cout << "Posicion de la celula madre numero " << k + 1 << ":\n";
    std::cout << "i: ";
    std::cin >> i_pos;
    std::cout << "j: ";
    std::cin >> j_pos;
    std::cout << "Tipo de celula (1, 2, 3 o 4(X)): ";
    std::cin >> initial_state;

    board.set_cell(i_pos, j_pos, initial_state);
    board.increment_population();
    board.print();
  }

  // for (int j = (m / 2) - 64; j < (m / 2) + 64; j++) {
  //   board.get_cell(n / 2, j)->set_alive(true);
  //   board.increment_population();
  // }

  for (int k = 1; k <= turns; k++) {
    for (int i = 1; i <= n_size; i++) {
      for (int j = 1; j <= m_size; j++) {
        board.get_cell(i, j)->count_neighbours(board);
      }
    }
    for (int i = 1; i <= n_size; i++) {
      for (int j = 1; j <= m_size; j++) {
        int next_state = board.get_cell(i, j)->update_state(board);
        if (next_state != board.get_cell(i, j)->get_state()) {
          board.set_cell(i, j, next_state);
        }
      }
    }
    board.print();
    std::cout << "Iteracion: " << k
              << "\t Poblacion: " << board.get_population() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

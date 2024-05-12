#include "./include/chess_gui.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ChessGUI *game = new ChessGUI();

  game->show();
  game->displayMainMenu();

  return a.exec();
}

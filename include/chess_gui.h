#ifndef CHESS_GUI_H
#define CHESS_GUI_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class ChessGUI;
}
QT_END_NAMESPACE

class ChessGUI : public QGraphicsView {
  Q_OBJECT

public:
  ChessGUI();
  ~ChessGUI();

  QGraphicsScene *scene;

  void displayMainMenu();

public slots:
  void startGame();
  void quitGame();
  void resetGame();

private:
  //   BoardView boardView;
  //   BoardView *board;
  //   PlayerView *blackPlayerView;
  //   PlayerView *whitePlayerView;

  void drawBoard();
  void drawSettingsPanel();
  void drawUserPanel();
  //   PlayerView *drawViewForUser(PlayerType player);
  void drawTitle(double yPosition, int fontSize);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void moveActivePawnToSelectedPoint(QPoint point);
  void selectPiece();
  void releaseActivePiece();

private:
  bool gameStarted = false;
};
#endif // CHESS_GUI_H

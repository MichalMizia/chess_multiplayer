#include "../include/chess_gui.h"
#include "../include/button.h"
#include "../include/constants.h"
#include "../include/utils.h"
#include "../ui/ui_chessgui.h"
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

int viewWidth = 1200;
int viewHeight = 768;

ChessGUI::ChessGUI() {
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(viewWidth, viewHeight);

  scene = new QGraphicsScene();
  scene->setSceneRect(0, 0, viewWidth, viewHeight);
  setScene(scene);

  QBrush brush;
  brush.setStyle((Qt::SolidPattern));
  QColor color = QColor(44, 41, 51);
  brush.setColor(color);
  scene->setBackgroundBrush(brush);
}

void ChessGUI::displayMainMenu() {
  scene->clear();

  double y_position = 100;
  drawTitle(y_position, 24);

  // // Create the first button
  Button *singleplayer_btn = new Button("Play Single");
  singleplayer_btn->setPos(200, 200);
  scene->addItem(singleplayer_btn);
  connect(singleplayer_btn, SIGNAL(buttonPressed()), this, SLOT(startGame()));

  // quitButton->setPos(quitXPosition, quitYPosition);
  // connect(quitButton, SIGNAL(buttonPressed()), this, SLOT(quitGame()));
  // scene->addItem(quitButton);
}

void ChessGUI::drawTitle(double yPosition, int fontSize) {
  QGraphicsSimpleTextItem *title = new QGraphicsSimpleTextItem();
  title->setText("Chess Game");
  QFont titleFont("Arial", fontSize, QFont::DemiBold);
  title->setFont(titleFont);
  title->setBrush(Qt::white);

  // // Calculate the position to center the text
  qreal x = (viewWidth - title->boundingRect().width()) / 2;

  // Set the position of the title
  title->setPos(x, yPosition);

  scene->addItem(title);
}

void ChessGUI::startGame() {

  scene->clear();

  // boardViewModel = BoardViewModel();

  // drawBoard();
  // drawSettingsPanel();
  // drawUserPanel();
  int titleYPosition = Constants::defaultMargin;
  drawTitle(titleYPosition, 40);
  gameStarted = true;
}

void ChessGUI::quitGame() { close(); }

void ChessGUI::resetGame() {
  gameStarted = false;
  scene->clear();
  // startGame();
}

void ChessGUI::mousePressEvent(QMouseEvent *event) {
  // if (!gameStarted) {
  //   QGraphicsView::mousePressEvent(event);
  //   return;
  // } else if (event->button() == Qt::RightButton) {
  //   releaseActivePawn();
  // } else if (boardViewModel.getActivePawn()) {
  //   handleSelectingPointForActivePawnByMouse(event->pos());
  // } else {
  //   PawnField *pawn = board->getPawnAtMousePosition(event->pos());
  //   selectPawn(pawn);
  // }

  QGraphicsView::mousePressEvent(event);
}

void ChessGUI::mouseMoveEvent(QMouseEvent *event) {
  // if there is a pawn selected, then make it follow the mouse
  // if (gameStarted && boardViewModel.getActivePawn()) {
  //   board->moveActivePawnToMousePosition(event->pos(),
  //                                        boardViewModel.getActivePawn());
  // }

  QGraphicsView::mouseMoveEvent(event);
}

ChessGUI::~ChessGUI() {}

#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Button : public QObject, public QGraphicsRectItem {
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  Button(QString title);

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
  void buttonPressed();

private:
  void setBackgroundColor(Qt::GlobalColor color);
};

#endif // BUTTON_H
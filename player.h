#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QObject>
#include <QtWidgets>
class Player : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
};



class Ball : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Ball();
    bool get_right();
    bool get_top();
    void set_right(bool x);
    void set_top(bool y);
    Player const * player;
public slots:
    void move();
private:
    bool move_right;
    bool move_top;
};


#endif // PLAYER_H

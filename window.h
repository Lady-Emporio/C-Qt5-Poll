#ifndef WINDOW_H
#define WINDOW_H
#include "player.h"
#include "poll_const.h"
#include <QMainWindow>

//class window : public QMainWindow
class window : public QWidget
{
    Q_OBJECT
public:
    explicit window(QWidget *parent = 0);
    QGraphicsScene * scene;
    QGraphicsView * view;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;

signals:

public slots:
};

#endif // WINDOW_H

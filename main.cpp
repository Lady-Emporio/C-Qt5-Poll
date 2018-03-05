#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "player.h"
#include "poll_const.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);//qreal x, qreal y, qreal w, qreal h
    Player * player = new Player();
    Ball * ball=new Ball;

    // add the item to the scene
    scene->addItem(player);
    scene->addItem(ball);
    ball->player=player;

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);//Sets the width of the widget to w and the height to h.
    view->show();
    player->setPos(view->width()/2,view->height() - player->rect().height()-LOW_MARGIN);

    return a.exec();
}

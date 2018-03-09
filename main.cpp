#include <QApplication>
#include "player.h"
#include "poll_const.h"
#include "window.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QGraphicsScene * scene = new QGraphicsScene();
//    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);//qreal x, qreal y, qreal w, qreal h
//    Player * player = new Player();
//    Enemy * enemy = new Enemy();
//    Ball * ball=new Ball;

//    enemy->ball=ball;
//    ball->enemy=enemy;
//    ball->player=player;

//    // add the item to the scene
//    scene->addItem(player);
//    scene->addItem(ball);
//    scene->addItem(enemy);

//    // add a view to visualize the scene
//    QGraphicsView * view = new QGraphicsView(scene);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);//Sets the width of the widget to w and the height to h.
//    view->show();
//    player->setPos(view->width()/2,view->height() - player->rect().height()-LOW_MARGIN);
//    enemy->setPos(view->width()/2,LOW_MARGIN);
    window*Game_window=new window;
    Game_window->show();
    return a.exec();
}

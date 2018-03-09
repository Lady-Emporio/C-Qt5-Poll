#include "window.h"
#include "player.h"
#include "poll_const.h"
//window::window(QWidget *parent) : QMainWindow(parent)
window::window(QWidget *parent) : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    //scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);//qreal x, qreal y, qreal w, qreal h
    Player * player = new Player();
    Enemy * enemy = new Enemy();
    Ball * ball=new Ball;

    enemy->ball=ball;
    ball->enemy=enemy;
    ball->player=player;

    // add the item to the scene
    scene->addItem(player);
    scene->addItem(ball);
    scene->addItem(enemy);

    // add a view to visualize the scene
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);//Sets the width of the widget to w and the height to h.
    //view->show();
    player->setPos(view->width()/2,view->height() - player->rect().height()-LOW_MARGIN);
    enemy->setPos(view->width()/2,LOW_MARGIN);
    leftLayout=new QVBoxLayout();
    rightLayout=new QVBoxLayout();
    mainLayout=new QHBoxLayout(this);


    QPushButton *pb1=new QPushButton("pb1");
    QPushButton *pb2=new QPushButton("pb2");
    QPushButton *pb3=new QPushButton("pb3");
    QPushButton *pb4=new QPushButton("pb4");
    leftLayout->addWidget(pb1);
    leftLayout->addWidget(pb2);
    rightLayout->addWidget(pb3);
    rightLayout->addWidget(pb4);


    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(view);
    mainLayout->addLayout(rightLayout);
    this->setLayout(mainLayout);
    this->resize(WINDOW_WIDTH+WINDOW_MARGIN_FOR_BUTTOM,WINDOW_HEIGHT);
    setWindowTitle(tr("POOl"));

}

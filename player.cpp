#include "player.h"
#include <QKeyEvent>
#include <QTimer>
#include "poll_const.h"
//#include <QDebug>
//qDebug()<<x()<<" | "<<y()<<" move_right: "<<move_right  <<" move_top: "<<move_top<<"\n";
Player::Player()
{
    this->setRect(0,0,100,10);
    this->setFlag(QGraphicsItem::ItemIsFocusable); //https://doc.qt.io/qt-5.10/qgraphicsitem.html#GraphicsItemFlag-enum
    this->setFocus();
    this->setBrush(QBrush(QColor(10, 100, 10)));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}

Ball::Ball()
{
    setRect(0,0,BALL_SIDE,BALL_SIDE);
    setPos(WINDOW_HEIGHT/2,WINDOW_HEIGHT/2);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //timer->start(100);
    timer->start( (ONE_SEC_ms/FPS));

//    QLinearGradient gradient(0, 0,20,20);
//    QGradientStops stops;
//    stops << QGradientStop(1.0, QColor(215, 100, 215));
//    gradient.setStops(stops);
//    this->setBrush(QBrush(gradient));
    this->setBrush(QBrush(QColor(215, 100, 215)));

    move_top=false;
    move_right=false;
}
bool Ball::get_right(){
    return move_right;
}

bool Ball::get_top(){
    return move_top;
}

void Ball::set_right(bool x){
    move_right=x;
}

void Ball::set_top(bool y){
    move_top=y;
}

void Ball::move()
{

if (x()<=0){
move_right=true;
}
else if (x()>=WINDOW_WIDTH-BALL_SIDE){
move_right=false;
}
if (y()<=0){
move_top=false;
}
else if (y()>=WINDOW_HEIGHT-BALL_SIDE){
move_top=true;
}
if(this->collidesWithItem(player)){
    move_top=true;
}
int X=(move_right)?BALL_SPEEND:-BALL_SPEEND;
int Y=(move_top)?-BALL_SPEEND:BALL_SPEEND;
setPos(x()+X,y()+Y);
}

#include "player.h"
#include <QKeyEvent>
#include <QTimer>
#include "poll_const.h"
//#include <QDebug>
//qDebug()<<x()<<" | "<<y()<<" move_right: "<<move_right  <<" move_top: "<<move_top<<"\n";



Player::Player()
{
    this->setRect(0,0,ALL_WIDTH,ALL_HEIGHT);
    this->setFlag(QGraphicsItem::ItemIsFocusable); //https://doc.qt.io/qt-5.10/qgraphicsitem.html#GraphicsItemFlag-enum
    this->setFocus();
    this->setBrush(QBrush(QColor(10, 100, 10)));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(x()<=0){
        setPos(x()+1,y());
        }
        else{
        setPos(x()-PLAYER_SPEEND,y());
        };
    }
    else if (event->key() == Qt::Key_Right){
        if(x()>=WINDOW_WIDTH-ALL_WIDTH){
            setPos(x()-1,y());
        }
        else{
        setPos(x()+PLAYER_SPEEND,y());
        }
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-PLAYER_SPEEND);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+PLAYER_SPEEND);
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
if(this->collidesWithItem(enemy)){
    move_top=false;
}
int X=(move_right)?BALL_SPEEND:-BALL_SPEEND;
int Y=(move_top)?-BALL_SPEEND:BALL_SPEEND;
setPos(x()+X,y()+Y);
}



Enemy::Enemy(){
    this->setRect(0,0,ALL_WIDTH,ALL_HEIGHT);
    this->setBrush(QBrush(QColor(10, 255, 255)));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start( (ONE_SEC_ms/FPS));
}

void Enemy::move(){
if (x()<=0){
    setPos(x()+EnemySPEEN,y());
}
else if(x()>=WINDOW_WIDTH-ALL_WIDTH){
    setPos(x()-EnemySPEEN,y());
}
else{
setPos(x()+(  (ball->x()>=x())?EnemySPEEN:-EnemySPEEN   ),y());
}
}

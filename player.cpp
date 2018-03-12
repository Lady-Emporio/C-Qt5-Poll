#include "player.h"
#include <QKeyEvent>
#include <QTimer>
#include "poll_const.h"

//qDebug()<<x()<<" | "<<y()<<" move_right: "<<move_right  <<" move_top: "<<move_top<<"\n";



Player::Player()
{
    this->setRect(0,0,ALL_WIDTH,ALL_HEIGHT);
    this->setFlag(QGraphicsItem::ItemIsFocusable); //https://doc.qt.io/qt-5.10/qgraphicsitem.html#GraphicsItemFlag-enum
    this->setFocus();
    this->setBrush(QBrush(QColor(10, 100, 10)));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start( (ONE_SEC_ms/FPS));
    left=false;
    right=false;
    up=false;
    down=false;
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        left=true;
    }
    else if (event->key() == Qt::Key_Right){
        right=true;
        }
    else if (event->key() == Qt::Key_Up){
        up=true;
    }
    else if (event->key() == Qt::Key_Down){
        down=true;
    }
}
void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->type()==QEvent::KeyRelease){
        switch(event->key()){
            case Qt::Key_Left:
                left=false;
                break;
            case Qt::Key_Right:
                right=false;
                break;
            case Qt::Key_Up:
                up=false;
                break;
            case Qt::Key_Down:
                down=false;
                break;
        }
    }
}

void Player::move(){
    if (left){
        if(x()<=0){
        setPos(x()+1,y());
        }
        else{
        setPos(x()-PLAYER_SPEEND,y());
        };
    }
    else if (right){
        if(x()>=WINDOW_WIDTH-ALL_WIDTH){
            setPos(x()-1,y());
        }
        else{
        setPos(x()+PLAYER_SPEEND,y());
        }
    }
    if (up){
        if(y()<=0){
            setPos(x(),y()+PLAYER_SPEEND);
        }
        else{
            setPos(x(),y()-PLAYER_SPEEND);
        }
    }
    else if (down){
        if(y()>=WINDOW_HEIGHT-10){
            setPos(x(),y()-PLAYER_SPEEND);
        }
        else{
            setPos(x(),y()+PLAYER_SPEEND);
        }

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
emit valueChanged(0);

}
else if (y()>=WINDOW_HEIGHT-BALL_SIDE){
move_top=true;
emit valueChanged(1);
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

#include <QApplication>
#include "player.h"
#include "poll_const.h"
#include "window.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window*Game_window=new window;
    Game_window->show();
    return a.exec();
}

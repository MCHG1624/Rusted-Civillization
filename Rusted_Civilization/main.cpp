#include "widget.h"

#include <QApplication>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*AllocConsole();
    SetConsoleTitle(L"Rusted Civilization Console");
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    cout<<"994"<<endl;*/
    QDesktopWidget* desktop = QApplication::desktop();
    Widget w(desktop->screenGeometry().width(),desktop->screenGeometry().height());

    w.show();
    return a.exec();
}

#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowIcon(QIcon("://server.ico"));
    w.show();

    return a.exec();
}

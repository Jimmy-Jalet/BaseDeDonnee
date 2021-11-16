#include "basededonnee.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseDeDonnee w;
    w.show();
    return a.exec();
}

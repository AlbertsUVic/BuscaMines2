#include "buscaminas.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Buscaminas w;
    w.show();
    return a.exec();
}

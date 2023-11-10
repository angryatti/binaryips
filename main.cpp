#include "binaryultimate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BinaryUltimate w;
    w.show();
    return a.exec();
}

#include "configuracion.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Configuracion w;
    w.show();



    return a.exec();
}

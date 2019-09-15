#include <QApplication>
#include "mainui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainUI mainWindow;
    mainWindow.show();

    return app.exec();
}

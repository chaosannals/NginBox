#include <QApplication>
#include <QScopedPointer>
#include "form/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QScopedPointer<MainWindow> window(new MainWindow);
    window->show();
    return application.exec();
}

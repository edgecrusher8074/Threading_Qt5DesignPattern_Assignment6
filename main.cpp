#include "mainwindow.h"

#include <QApplication>

/**
 * @brief Assignment 6 for Qt5 Design Patterns Tutorial on Udemy.
 * @details Create a threaded operation that runs in an own thread
 *          and perform stuff, whilst the UI stays enabled and
 *          responsive.
 * @author edgecrusher8074
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

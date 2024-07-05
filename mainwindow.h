#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "centralwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
        void onConnect();

private:
     static QString m_driverName;

     CentralWidget *m_centralWidget = nullptr;

};

#endif // MAINWINDOW_H

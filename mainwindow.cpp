#include <QDesktopWidget>
#include <QErrorMessage>
#include <QFileDialog>
#include <QMenuBar>
#include <QSqlDatabase>
#include <QSqlError>

#include "mainwindow.h"

QString MainWindow::m_driverName = "QSQLITE";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    menuBar()->addAction(tr("Connect on DB"), this, &MainWindow::onConnect);

    m_centralWidget = new CentralWidget(this);
    setCentralWidget(m_centralWidget);

    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onConnect() {
    if (!QSqlDatabase::isDriverAvailable(m_driverName)) {
        QErrorMessage message(this);
        message.showMessage(tr("No driver found for") + " " + m_driverName);
        message.exec();
        return;
    }

    auto const filename = QFileDialog::getOpenFileName(this, tr("Select database"), "", tr("Sqlite database files (*.sqlite)"));

    auto database = QSqlDatabase::addDatabase(m_driverName);
    database.setDatabaseName(filename);

    if (!database.open()) {
        auto error = database.lastError();
        QErrorMessage message(this);
        message.showMessage(error.nativeErrorCode() + " " + error.text());
        message.exec();
        return;
    }

    m_centralWidget->setDatabase(database.connectionName());
}

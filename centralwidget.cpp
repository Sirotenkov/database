#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>

#include "centralwidget.h"
#include "delegate.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    m_listView = new QListView(this);
    m_listView->setUniformItemSizes(false);

    auto const delegate = new Delegate(m_listView);
    m_listView->setItemDelegate(delegate);

    auto const layout = new QVBoxLayout(this);
    layout->addWidget(m_listView);
    setLayout(layout);
}

void CentralWidget::setDatabase(QString const &connectionName) {
    QSqlDatabase database = QSqlDatabase::database(connectionName);
    qDebug() << "database changed" << connectionName << database;

    auto const oldModel = m_listView->model();

    auto const model = new Model(this);
    model->setSqlDatabase(connectionName);

    m_listView->setModel(model);

    if (oldModel) {
        delete oldModel;
        qDebug() << "old model removed";
    }
}

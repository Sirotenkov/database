#include <QDebug>
#include <QSqlQuery>

#include "model.h"

Model::Model(QObject *parent) : QAbstractListModel(parent)
{

}

void Model::setSqlDatabase(QString const &connectionName) {
    auto database = QSqlDatabase::database(connectionName);
    qDebug() << "changed database" << connectionName << database;

    QSqlQuery query(database);
    query.exec("SELECT NAME, BIRTHDAY, REC_NO FROM PATIENTS");

    while (query.next()) {
        ModelItem item {query.value(0).toString(), query.value(1).toString(), query.value(2).toInt()};
        m_items.append(item);
    }
}

QVariant Model::data(const QModelIndex &index, int role) const {
    int const i = index.row();

    if (i < 0 || i >= m_items.count()) {
        qDebug() << "out of range";
        return {};
    }

    switch(role) {
    case DisplayRole:
        return m_items.at(i).NAME;
    case BirthdayRole:
        return m_items.at(i).BIRTHDAY;
    case RecNoRole:
        return m_items.at(i).REC_NO;
    default:
        return {};
    }
}

int Model::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_items.count();
}

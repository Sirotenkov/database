#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QSqlDatabase>

#include "model.h"

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = nullptr);

    void setDatabase(QString const &connectionName);

private:
    QString m_databaseName;
    QListView *m_listView = nullptr;

};

#endif // CENTRALWIDGET_H

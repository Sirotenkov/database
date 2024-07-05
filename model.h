#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QSqlDatabase>
#include <QList>

class Model: public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        BirthdayRole = Qt::UserRole + 0,
        RecNoRole = Qt::UserRole + 1,
    };

    explicit Model(QObject *parent = nullptr);

    void setSqlDatabase(QString const &connectionName);

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

private:
    struct ModelItem {
        QString NAME;
        QString BIRTHDAY;
        int REC_NO;
    };

    QList<ModelItem> m_items;

};

#endif // MODEL_H

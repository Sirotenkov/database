#pragma once
#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>

class Delegate: public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit Delegate(QObject *parent = nullptr);

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

protected:
    QModelIndex m_selectedIndex;

};

#endif // DELEGATE_H

#include <QDebug>
#include <QPainter>
#include <QSize>
#include <QMouseEvent>

#include "model.h"
#include "delegate.h"

Delegate::Delegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->save();

    auto const rect = option.rect;
    painter->drawRect(rect.adjusted(0, 0, -1, 0));
    painter->drawText(rect, index.data(Qt::DisplayRole).toString());

    painter->drawRect(rect.adjusted(200, 0, -1, 0));
    painter->drawText(rect.left() + 200, rect.y() + 15, index.data(Model::BirthdayRole).toString());

    painter->drawRect(rect.adjusted(400, 0, -1, 0));
    painter->drawText(rect.left() + 400, rect.y() + 15, index.data(Model::RecNoRole).toString());

    painter->restore();
}

QSize Delegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index == m_selectedIndex) {
        return QSize(-1, 80);
    }

    return QStyledItemDelegate::sizeHint(option, index);
}

bool Delegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) {
    if (event->type() == QEvent::MouseButtonPress) {
        m_selectedIndex = index;
        emit sizeHintChanged(index);
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class PixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PixmapItem(const QPixmap& pixmap, QGraphicsItem* parent = nullptr)
        : QGraphicsPixmapItem(pixmap, parent)
    {
        setAcceptHoverEvents(true);
    }

signals:
    void leftClicked();
    void mouseEntered();
    void mouseLeft();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            emit leftClicked();
        }
        QGraphicsPixmapItem::mousePressEvent(event);
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override
    {
        emit mouseEntered();
        QGraphicsPixmapItem::hoverEnterEvent(event);
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override
    {
        emit mouseLeft();
        QGraphicsPixmapItem::hoverLeaveEvent(event);
    }
};
#endif // PIXMAPITEM_H

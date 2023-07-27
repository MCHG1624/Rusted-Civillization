#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QMouseEvent>
#include <QtMath>
#include <QPointF>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QString>
#include <string>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QRandomGenerator>
#include <windows.h>
#include <QTextStream>

using namespace std;


class View : public QGraphicsView
{
public:
    View(int nw,int nh,int way,QGraphicsView *parent=nullptr);
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void setcursor();
private:
    QPoint m_pos;
    qreal angle;
    QGraphicsScene scene;
    QGraphicsPixmapItem* list[100][100];
    int byl[100][100];
    QString lur[2][14];
    QTimer *t1;
};

#endif // VIEW_H

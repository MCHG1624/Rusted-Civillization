#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QGraphicsOpacityEffect>
#include "view.cpp"
#include "pixmapitem.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(int w,int h,QWidget *parent = nullptr);
    ~Widget();
private:
    View *view;
    QGraphicsView *start,*tat;
    QGraphicsScene *scene,*tac;
    QGraphicsPixmapItem *back,*titlle;
    PixmapItem *exit_pm,*way1,*way2,*ertu;
    int w,h;
    QVector <QGraphicsPixmapItem*> lit;
public slots:
    void to_start_menu();
    void Exit();
    void start_game1(int i);
    void start_game2();
    void show_start_menu();

};
#endif // WIDGET_H

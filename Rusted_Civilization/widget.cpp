#include "widget.h"
Widget::Widget(int nw, int nh, QWidget *parent)
{
    w=nw;
    h=nh;
    double sc;
    this->showFullScreen();


    start=new QGraphicsView(this);
    start->setFixedSize(w,h);
    scene=new QGraphicsScene;
    start->setScene(scene);
    start->show();

    if(rand(1,3)==1)
        back=new QGraphicsPixmapItem(QPixmap(":/images/drawable/mune.png"));
    else
        back=new QGraphicsPixmapItem(QPixmap(":/images/drawable/mune2.png"));
    back->setPos((w-back->pixmap().width())/2,(h-back->pixmap().height())/2);
    scene->addItem(back);

    titlle=new QGraphicsPixmapItem(QPixmap(":/images/drawable/titlle.png"));
    sc=w*0.9/titlle->pixmap().width();
    titlle->setScale(sc);
    titlle->setPos((w-titlle->pixmap().width()*sc)/2,(h-titlle->pixmap().height()*sc)/2-150);
    scene->addItem(titlle);

    way1=new PixmapItem(QPixmap(":/images/drawable/start_glow_button.png"));
    way1->setPos((w-way1->pixmap().width())/2,h/2);
    scene->addItem(way1);
    QObject::connect(way1,&PixmapItem::leftClicked,this,[this](){Widget::start_game1(1);});
    QObject::connect(way1,&PixmapItem::mouseEntered,this,[this](){way1->setPixmap(QPixmap(":/images/drawable/start_glow_highlight_button.png"));});
    QObject::connect(way1,&PixmapItem::mouseLeft,this,[this](){way1->setPixmap(QPixmap(":/images/drawable/start_glow_button.png"));});


    way2=new PixmapItem(QPixmap(":/images/drawable/start_glow_button.png"));
    way2->setPos((w-way2->pixmap().width())/2,h/2+75);
    scene->addItem(way2);
    QObject::connect(way2,&PixmapItem::leftClicked,this,[this](){Widget::start_game1(2);});
    QObject::connect(way2,&PixmapItem::mouseEntered,this,[this](){way2->setPixmap(QPixmap(":/images/drawable/start_glow_highlight_button.png"));});
    QObject::connect(way2,&PixmapItem::mouseLeft,this,[this](){way2->setPixmap(QPixmap(":/images/drawable/start_glow_button.png"));});

    exit_pm=new PixmapItem(QPixmap(":/images/drawable/exit_dark_box.png"));
    exit_pm->setPos((w-exit_pm->pixmap().width())/2,h/2+150);
    scene->addItem(exit_pm);
    QObject::connect(exit_pm,&PixmapItem::leftClicked,this,&Widget::Exit);
    QObject::connect(exit_pm,&PixmapItem::mouseEntered,this,[this](){exit_pm->setPixmap(QPixmap(":/images/drawable/exit_white_button.png"));});
    QObject::connect(exit_pm,&PixmapItem::mouseLeft,this,[this](){exit_pm->setPixmap(QPixmap(":/images/drawable/exit_dark_box.png"));});


}

Widget::~Widget()
{

}

void Widget::to_start_menu()
{

}

void Widget::show_start_menu()
{
    //start_menu->show();
}

void Widget::Exit(void)
{
    exit(0);

}

void Widget::start_game1(int i)
{
    view=new View(w,h,i);
    view->setParent(this);
    view->setFixedSize(w,h);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //start_menu->hide();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    tac=new QGraphicsScene;

    int m=0,n=QPixmap(":/images/drawable/metal.png").width(),b=QPixmap(":/images/drawable/metal.png").height();
    for(int i=0;m<=w;i++,m+=n)
    {
        lit.resize(i+1);
        lit[i]=new QGraphicsPixmapItem(QPixmap(":/images/drawable/metal.png"));
        lit[i]->setPos(m,h-b);
        tac->addItem(lit[i]);
    }

    ertu=new PixmapItem(QPixmap(":/images/drawable/return_glow_button.png"));
    ertu->setPos(20,h-b+(b-ertu->pixmap().height())/2);
    tac->addItem(ertu);
    QObject::connect(ertu,&PixmapItem::leftClicked,this,[this](){
        tat->hide();
        view->hide();
        delete view;
        delete tat;
        start->show();
    });
    QObject::connect(ertu,&PixmapItem::mouseEntered,this,[this](){ertu->setPixmap(QPixmap(":/images/drawable/return_glow_highlight_button.png"));});
    QObject::connect(ertu,&PixmapItem::mouseLeft,this,[this](){ertu->setPixmap(QPixmap(":/images/drawable/return_glow_button.png"));});


    tat=new QGraphicsView(this);
    tat->setFixedSize(w,b);
    tat->move(0,h-b);
    tat->setScene(tac);
    tat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tat->show();
}

void Widget::start_game2()
{



}


#include "view.h"

inline int rand(int a,int b)
{
    return QRandomGenerator::global()->bounded(a, b);
}
inline QPixmap chpm(int n,int s=0)
{
    if(s==1)
    {
        switch(n)
        {
        case 1:return QPixmap(":/images/sea/1.png");
        case 2:return QPixmap(":/images/sea/2.png");
        case 3:return QPixmap(":/images/sea/3.png");
        case 4:return QPixmap(":/images/sea/4.png");
        case 5:return QPixmap(":/images/sea/5.png");
        case 6:return QPixmap(":/images/sea/6.png");
        case 7:return QPixmap(":/images/sea/7.png");
        case 8:return QPixmap(":/images/sea/8.png");
        case 9:return QPixmap(":/images/sea/9.png");
        case 10:return QPixmap(":/images/sea/10.png");
        case 11:return QPixmap(":/images/sea/11.png");
        case 12:return QPixmap(":/images/sea/12.png");
        case 13:return QPixmap(":/images/sea/13.png");
        default:return QPixmap(":/images/drawable/error.png");
        }
    }
    else if(s==2)
    {
        switch(n)
        {
        case 1:return QPixmap(":/images/land/14.png");
        case 2:return QPixmap(":/images/land/5.png");
        case 3:return QPixmap(":/images/sea/S5.png");
        default:return QPixmap(":/images/drawable/error.png");
        }
    }
    else
    {
        switch(n)
        {
        case 1:return QPixmap(":/images/land/1.png");
        case 2:return QPixmap(":/images/land/2.png");
        case 3:return QPixmap(":/images/land/3.png");
        case 4:return QPixmap(":/images/land/4.png");
        case 5:return QPixmap(":/images/land/5.png");
        case 6:return QPixmap(":/images/land/6.png");
        case 7:return QPixmap(":/images/land/7.png");
        case 8:return QPixmap(":/images/land/8.png");
        case 9:return QPixmap(":/images/land/9.png");
        case 10:return QPixmap(":/images/land/10.png");
        case 11:return QPixmap(":/images/land/11.png");
        case 12:return QPixmap(":/images/land/12.png");
        case 13:return QPixmap(":/images/land/13.png");
        case 14:return QPixmap(":/images/land/14.png");
        default:return QPixmap(":/images/drawable/error.png");
        }
    }
}

inline View::View(int nw,int nh,int way,QGraphicsView *parent)
{
    int i,j,x=1900,y=1900,ty;
    this->setSceneRect(QRect((4000-nw)/2,(4000-nh)/2,4000,4000));
    this->setScene(&scene);
    setTransformationAnchor(QGraphicsView::NoAnchor);
    setResizeAnchor(QGraphicsView::NoAnchor);
    setDragMode(QGraphicsView::ScrollHandDrag);
    viewport()->setCursor(Qt::ArrowCursor);
    //cout<<"1234p3"<<endl;
    if(way==1)
    {
        cout<<"\b";
        cout<<"loading map...(0%)"<<endl;
        list[0][0]=new QGraphicsPixmapItem(QPixmap(":/images/land/9.png"));
        list[0][0]->setPos(1900,1900);
        scene.addItem(list[0][0]);
        x=1900;
        for(i=1;i<=49;i++)
        {
            if(byl[0][i-1]==1 || byl[0][i-1]==2 || byl[0][i-1]==11)
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=2;
                else if(ty==2)ty=3;
                else ty=10;
            }
            else if(byl[0][i-1]==3 || byl[0][i-1]==6 || byl[0][i-1]==9)
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=1;
                else if(ty==2)ty=4;
                else ty=7;
            }
            else if(byl[0][i-1]==4 || byl[0][i-1]==5 || byl[0][i-1]==10 || byl[0][i-1]==12)
            {
                ty=QRandomGenerator::global()->bounded(1, 5);
                if(ty==1)ty=5;
                else if(ty==2)ty=6;
                else if(ty==3)ty=11;
                else ty=13;
            }
            else
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=8;
                else if(ty==2)ty=9;
                else ty=12;
            }
            byl[0][i]=ty;
            list[0][i]=new QGraphicsPixmapItem(chpm(byl[0][i]));
            list[0][i]->setPos(x,y);
            scene.addItem(list[0][i]);
            x+=20;
        }
        x=1900;
        y=1920;
        for(i=1;i<=49;i++)
        {
            if(byl[i-1][0]==1 || byl[i-1][0]==4 || byl[i-1][0]==12)
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=4;
                else if(ty==2)ty=7;
                else ty=10;
            }
            else if(byl[i-1][0]==3 || byl[i-1][0]==6 || byl[i-1][0]==13)
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=6;
                else if(ty==2)ty=9;
                else ty=11;
            }
            else if(byl[i-1][0]==2 || byl[i-1][0]==5 || byl[i-1][0]==10 || byl[i-1][0]==11)
            {
                ty=QRandomGenerator::global()->bounded(1, 5);
                if(ty==1)ty=8;
                else if(ty==2)ty=12;
                else if(ty==3)ty=13;
                else ty=5;
            }
            else
            {
                ty=QRandomGenerator::global()->bounded(1, 4);
                if(ty==1)ty=1;
                else if(ty==2)ty=2;
                else ty=3;
            }
            byl[i][0]=ty;
            list[i][0]=new QGraphicsPixmapItem(chpm(ty));
            list[i][0]->setPos(x,y);
            scene.addItem(list[i][0]);

            for(j=1;j<=49;j++)
            {
                if(byl[i][j-1]==1 || byl[i][j-1]==2)
                {
                    if(byl[i-1][j]==1 || byl[i-1][j]==4 || byl[i-1][j]==12)
                    {
                        ty=10;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=2;
                        else ty=3;
                    }
                }
                else if(byl[i][j-1]==3 || byl[i][j-1]==6 || byl[i][j-1]==9)
                {
                    if(byl[i-1][j]==1 || byl[i-1][j]==4 || byl[i-1][j]==12)
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=4;
                        else ty=7;
                    }
                    else
                    {
                        ty=14;
                    }
                }
                else if(byl[i][j-1]==4 || byl[i][j-1]==5)
                {
                    if(byl[i-1][j]==6 || byl[i-1][j]==3 || byl[i-1][j]==13)
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=6;
                        else ty=11;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 7);
                        if(ty==1)ty=13;
                        else if(ty==2)ty=9;
                        else ty=5;
                    }
                }
                else if(byl[i][j-1]==7 || byl[i][j-1]==8)
                {
                    if(byl[i-1][j]==3 || byl[i-1][j]==6 || byl[i-1][j]==13)
                    {
                        ty=9;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 4);
                        if(ty==1)ty=8;
                        else if(ty==2)ty=9;
                        else ty=12;
                    }
                }
                else if(byl[i][j-1]==10)
                {
                    if(byl[i-1][j]==5 || byl[i-1][j]==2 || byl[i-1][j]==10 || byl[i-1][j]==11)
                    {
                        ty=5;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=6;
                        else ty=11;
                    }
                }
                else if(byl[i][j-1]==11)
                {
                    if(byl[i-1][j]==1 || byl[i-1][j]==4 || byl[i-1][j]==12)
                    {
                        ty=10;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=2;
                        else ty=3;
                    }
                }
                else if(byl[i][j-1]==12)
                {
                    if(byl[i-1][j]==2 || byl[i-1][j]==5 || byl[i-1][j]==10 || byl[i-1][j]==11)
                    {
                        ty=5;
                    }
                    else
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=6;
                        else ty=11;
                    }
                }
                else if(byl[i][j-1]==13)
                {
                    if(byl[i-1][j]==5 || byl[i-1][j]==2 || byl[i-1][j]==10 || byl[i-1][j]==11)
                    {
                        ty=QRandomGenerator::global()->bounded(1, 3);
                        if(ty==1)ty=8;
                        else ty=12;
                    }
                    else
                    {
                        ty=9;
                    }
                }
                else
                {
                    if(byl[i-1][j]==1 || byl[i-1][j]==4 || byl[i-1][j]==12)
                    {
                        ty=4;
                    }
                    else
                    {
                        ty=1;
                    }
                }
                byl[i][j]=ty;
                list[i][j]=new QGraphicsPixmapItem(chpm(ty));
                list[i][j]->setPos(x,y);
                scene.addItem(list[i][j]);
                x+=20;
            }
            y+=20;
            x=1900;
        }
    }
    else
    {
        x=1900;
        y=1900;
        ty=rand(1,4);
        byl[0][0]=ty;
        list[0][0]=new QGraphicsPixmapItem(chpm(ty));
        list[0][0]->setPos(x,y);
        scene.addItem(list[0][0]);
        x=1920;
        for(i=1;i<=99;i++)
        {
            ty=rand(1,7);
            if(byl[0][i-1]==1)
            {
                if(ty==1)ty=2;
                else if(ty==2)ty=3;
                else ty=1;
            }
            else if(byl[0][i-1]==2)
            {
                if(ty==1)ty=1;
                else if(ty==2)ty=3;
                else ty=2;
            }
            else
            {
                if(ty==1)ty=2;
                else if(ty==2)ty=1;
                else ty=3;
            }
            byl[0][i]=ty;
            list[0][i]=new QGraphicsPixmapItem(chpm(byl[0][i],2));
            list[0][i]->setPos(x,y);
            scene.addItem(list[0][i]);
            x+=20;
        }
        y=1920;
        x=1900;
        for(i=1;i<+99;i++)
        {
            ty=rand(1,7);
            if(byl[i-1][0]==1)
            {
                if(ty==1)ty=2;
                else if(ty==2)ty=3;
                else ty=1;
            }
            else if(byl[i-1][0]==2)
            {
                if(ty==1)ty=1;
                else if(ty==2)ty=3;
                else ty=2;
            }
            else
            {
                if(ty==1)ty=2;
                else if(ty==2)ty=1;
                else ty=3;
            }
            byl[i][0]=ty;
            list[i][0]=new QGraphicsPixmapItem(chpm(byl[i][0],2));
            list[i][0]->setPos(x,y);
            scene.addItem(list[i][0]);
            for(j=1;j<=99;j++)
            {
                if(byl[i][j-1]==1)
                {
                    if(byl[i-1][j]==1)
                    {
                        ty=rand(1,100);
                        if(ty==1)ty=2;
                        else if(ty==2)ty=3;
                        else ty=1;
                    }
                    else
                    {
                        ty=rand(1,20);
                        if(ty==1)ty=2;
                        else if(ty==2)ty=3;
                        else ty=1;
                    }

                }
                if(byl[i][j-1]==2)
                {
                    if(byl[i-1][j]==1)
                    {
                        ty=rand(1,100);
                        if(ty==1)ty=1;
                        else if(ty==2)ty=3;
                        else ty=2;
                    }
                    else
                    {
                        ty=rand(1,20);
                        if(ty==1)ty=1;
                        else if(ty==2)ty=3;
                        else ty=2;
                    }

                }
                if(byl[i][j-1]==3)
                {
                    if(byl[i-1][j]==1)
                    {
                        ty=rand(1,100);
                        if(ty==1)ty=2;
                        else if(ty==2)ty=1;
                        else ty=3;
                    }
                    else
                    {
                        ty=rand(1,20);
                        if(ty==1)ty=2;
                        else if(ty==2)ty=1;
                        else ty=3;
                    }
                }
                byl[i][j]=ty;
                list[i][j]=new QGraphicsPixmapItem(chpm(byl[i][j],2));
                list[i][j]->setPos(x,y);
                scene.addItem(list[i][j]);
                x+=20;
            }
            y+=20;
            x=1900;
        }
    }
    t1=new QTimer;
    t1->start(10);
    QObject::connect(t1,&QTimer::timeout,this,&View::setcursor);
}

inline void View::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    qreal nangle = event->angleDelta().y() / 8;

    QPoint mpos=event->pos();
    if(nangle>0)
    {
        angle = qPow(2, nangle / 360.0);
        this->scale(1.2,1.2);
    }
    else
    {
        angle = qPow(2, nangle / 360.0);
        this->scale(0.8,0.8);
    }
    QTransform transform;
    transform.scale(angle, angle);
    QPointF sp0 = this->mapToScene(mpos);
    QPointF sp1 = this->mapToScene(mpos);
    QPointF delta = sp0 - sp1;
    this->centerOn(this->mapToScene(this->viewport()->rect().center()) - delta);
}

inline void View::mousePressEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    cout<<"mouse press("<<event->pos().x()<<","<<event->pos().y()<<")";
    if (event->button() == Qt::MiddleButton) {
                m_pos = event->pos();
            }
     QGraphicsView::mousePressEvent(event);
}

inline void View::mouseMoveEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    if (event->buttons() & Qt::MiddleButton) {
                QPoint delta = event->pos() - m_pos;
                QPointF viewCenter = mapToScene(viewport()->rect().center()) - delta;
                centerOn(viewCenter);
            } else {
                QGraphicsView::mouseMoveEvent(event);
            }
}

inline void View::keyPressEvent(QKeyEvent *event)
{
    setCursor(Qt::ArrowCursor);
    if(event->key()==Qt::Key_Escape)
        exit(0);

}

inline void View::setcursor()
{
    viewport()->setCursor(Qt::ArrowCursor);
}

inline void View::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    QGraphicsView::mouseReleaseEvent(event);
}

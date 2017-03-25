#include "buton.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

buton::buton(QWidget *parent) :
    QLabel(parent)
{
    QPixmap apo(":/img/selcuk.png");
    rand_x = qrand() % 740;
    setGeometry(rand_x,y,75,75);
    setPixmap(apo.scaled(75,75,Qt::IgnoreAspectRatio));
    show();

    connect(kaydirma_zamani = new QTimer(),SIGNAL(timeout()),this,SLOT(kaydir()));
    kaydirma_zamani->start(100);
}

void buton::mousePressEvent(QMouseEvent *e)
{
    e->accept();
    yakalandi();
    delete this;
}


void buton::kaydir()
{
    y += 10;
    setGeometry(rand_x,y,75,75);
    if(y >=600)
    {
        kacti();
        delete this;
    }
}

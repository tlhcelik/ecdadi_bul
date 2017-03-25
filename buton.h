#ifndef BUTON_H
#define BUTON_H

#include <QLabel>
#include <QMouseEvent>
#include "mainwindow.h"
class buton : public QLabel
{
    Q_OBJECT
public:

    explicit buton(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent*);

    QTimer *kaydirma_zamani;

    int rand_x;
    int y = -30;

public slots:
    void kaydir();

// eyvallah kardesim tekekkur ettim cansin, seviyorum seni:)
signals:
    void yakalandi();
    void kacti();

};

#endif // BUTON_H

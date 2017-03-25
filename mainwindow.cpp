#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buton.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lbl_set_color();
    zamanlayici = new QTimer();
    sayac = 0;

    connect(olusturma_zamani = new QTimer(),SIGNAL(timeout()),this,SLOT(olustur()));
    olusturma_zamani->start(500);


    connect(zamanlayici,SIGNAL(timeout()),this,SLOT(sayacArtir()));
    zamanlayici->start(1000);

    QPixmap bg(":/img/bg.jpg");
    ui->lbl_bg->setPixmap(bg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayacArtir()
{
    sayac++;
    ui->lbl_zaman_skor->setText(QString::number(sayac));
}

void MainWindow::olustur()
{
    buton *btn = new buton(this);
    connect(btn,SIGNAL(yakalandi()),this,SLOT(yakalandi_bas()));
    connect(btn,SIGNAL(kacti()),this,SLOT(kacan_bas()));


    //ui->lbl_yakala_skor->setText(QString::number(yakalanan));
    //ui->lbl_kacan_skor->setText(QString::number(1));

}

void MainWindow::lbl_set_color()
{
      ui->zaman->setText("<font color='white'>Zaman:</font>");
      ui->lbl_yakala->setText("<font color='white'>Yakalanan:</font>");
      ui->lbl_kacan->setText("<font color='white'>Kaçan:</font>");

      ui->lbl_zaman_skor->setText("<font color='white'>0</font>");
      ui->lbl_yakala_skor->setText("<font color='white'>0</font>");
      ui->lbl_kacan_skor->setText("<font color='white'>0</font>");

}

void MainWindow::yakalandi_bas()
{
    yakalanan ++;
    ui->lbl_yakala_skor->setText(QString::number(yakalanan));

}

void MainWindow::kacan_bas()
{
    kacan ++;
    ui->lbl_kacan_skor->setText(QString::number(kacan));
}

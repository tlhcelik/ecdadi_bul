#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "buton.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int sayac;
    int yakalanan =0;
    int kacan = 0;

private slots:
    void sayacArtir();
    void olustur();
    void lbl_set_color();
  //  void set_labels(int skor_yakala, int skor_kacti);
    void yakalandi_bas();
    void kacan_bas();

private:
    Ui::MainWindow *ui;
    QTimer *zamanlayici;
    QTimer *olusturma_zamani;

};

#endif // MAINWINDOW_H

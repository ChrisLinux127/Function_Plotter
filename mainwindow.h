#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPunkt(double x,double y); //Punkt hinzufügen
     void loeschen();   //Punkt loeschen
     void zeichne();    //Zeichnen
private slots:
     void on_btn_add_clicked();

     void on_btn_del_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double>X,Y;
};
#endif // MAINWINDOW_H

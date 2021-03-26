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
     void on_rbnt_sin_clicked();

     void on_rbnt_cos_clicked();

     void on_btn_settings_clicked();

     void on_bx_xMax_valueChanged(double arg1);

     void on_bx_YMax_valueChanged(double arg1);

     void on_bx_xMin_valueChanged(double arg1);

     void on_bx_yMin_valueChanged(double arg1);


     void on_rbnt_tan_clicked();

private:
    int graph_index;
    double A;
    double Omega;
    Ui::MainWindow *ui;
    QVector<double>Vect_X,Vect_Y;
};
#endif // MAINWINDOW_H

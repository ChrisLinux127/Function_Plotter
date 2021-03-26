#include "mainwindow.h"
#include "ui_mainwindow.h"
//Konstruktor:
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Plot Einstellungen:
    ui->PlotView->addGraph(); //Graph hinzufügen
    ui->PlotView->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); //Einstellung von Graph 0
    ui->PlotView->graph(0)->setLineStyle(QCPGraph::lsNone);
}
//Destruktor:
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPunkt(double x, double y)
{
    Vect_X.append(x);
    Vect_Y.append(y);
}

void MainWindow::loeschen()
{
    Vect_X.clear();
}

void MainWindow::zeichne()
{
    ui->PlotView->graph(0)->setData(Vect_X,Vect_Y);
    ui->PlotView->replot();
    ui->PlotView->update();
}

//Handler of Click() Events:
void MainWindow::on_btn_add_clicked()
{
    addPunkt(ui->bx_x->value(),ui->bx_y->value());
    zeichne();
}

void MainWindow::on_btn_del_clicked()
{

}

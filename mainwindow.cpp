#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<math.h>
//Konstruktor:
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Input Einstellungen:
    ui->bx_xMin->setMinimum(std::numeric_limits<double>::lowest());
    ui->bx_yMin->setMinimum(std::numeric_limits<double>::lowest());

    //STD Var Settings:
    A=1;    //1
    Omega=M_PI*10;  //10 Hz
    graph_index=0;

    //Plot Einstellungen:
    ui->PlotView->addGraph(); //Graph hinzufügen
    ui->PlotView->graph(graph_index)->setScatterStyle(QCPScatterStyle::ssCross); //Einstellung von Graph 0
    //ui->PlotView->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->PlotView->xAxis->setLabel("x");
    ui->PlotView->yAxis->setLabel("f(x)");
    ui->PlotView->xAxis->setRange(-10,10); //STandard
    ui->PlotView->yAxis->setRange(-10,10);
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
    ui->PlotView->graph(graph_index)->setData(Vect_X,Vect_Y);
}

void MainWindow::loeschen()
{
    Vect_X.clear();
    Vect_Y.clear();
}

void MainWindow::zeichne()
{
    ui->PlotView->replot();
    ui->PlotView->update();
}

//Btn Events:

//Plots:
void MainWindow::on_rbnt_sin_clicked()
{
    Vect_X.clear();
    Vect_Y.clear();
    for(double i=0;i<10;i=i+0.5)
    {

       addPunkt(i,sin(i));
    }
    zeichne();
}

void MainWindow::on_rbnt_cos_clicked()
{
    Vect_X.clear();
    Vect_Y.clear();
    for(double i=0;i<10;i=i+0.5)
    {

       addPunkt(i,cos(i));
    }
    zeichne();
}
void MainWindow::on_rbnt_tan_clicked()
{
    Vect_X.clear();
    Vect_Y.clear();
    for(double i=0;i<10;i=i+0.5)
    {

       addPunkt(i,tan(i));
    }
    zeichne();
}

//Fenster einstellungen:
void MainWindow::on_btn_settings_clicked()
{
    ui->PlotView->replot();
    ui->PlotView->update();
}



//Xmax:
void MainWindow::on_bx_xMax_valueChanged(double arg1)
{
    ui->PlotView->xAxis->setRangeUpper(arg1);
}
//Ymax:
void MainWindow::on_bx_YMax_valueChanged(double arg1)
{
    ui->PlotView->yAxis->setRangeUpper(arg1);
}
//Xmin:
void MainWindow::on_bx_xMin_valueChanged(double arg1)
{
    ui->PlotView->xAxis->setRangeLower(arg1);
}
//Ymin:

void MainWindow::on_bx_yMin_valueChanged(double arg1)
{
    ui->PlotView->yAxis->setRangeLower(arg1);
}

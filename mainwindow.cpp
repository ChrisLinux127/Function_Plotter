#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
//Konstruktor:
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Input Einstellungen:
    ui->bx_xMin->setMinimum(std::numeric_limits<double>::lowest());
    ui->bx_yMin->setMinimum(std::numeric_limits<double>::lowest());

    //Plot Einstellungen:
    ui->PlotView->addGraph(); //Graph hinzufügen
    ui->PlotView->graph(0)->setScatterStyle(QCPScatterStyle::ssCross); //Einstellung von Graph 0
    ui->PlotView->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->PlotView->xAxis->setLabel("x");
    ui->PlotView->yAxis->setLabel("f(x)");
    ui->PlotView->xAxis->setRange(-5,5); //STandard
    ui->PlotView->yAxis->setRange(-5,5);
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
    Vect_Y.clear();
}

void MainWindow::zeichne()
{
    ui->PlotView->graph(0)->setData(Vect_X,Vect_Y);
    ui->PlotView->replot();
    ui->PlotView->update();
}

//Btn Events:

void MainWindow::on_pushButton_clicked()
{
ui->PlotView->xAxis->setRange(ui->bx_xMin->value(),ui->bx_xMax->value());
ui->PlotView->yAxis->setRange(ui->bx_yMin->value(),ui->bx_yMin->value());
ui->PlotView->replot();
ui->PlotView->update();
}

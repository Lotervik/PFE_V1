#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Clifford.h>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->insertPlainText("∀");
}


void MainWindow::on_pushButton_2_clicked()
{
     ui->textEdit->insertPlainText("^");
}

void MainWindow::on_pushButton_clicked()
{

   string mot,sh,ch =ui->textEdit->toPlainText().toStdString();
   Clifford cl(ch);
   ui->label_2->setText(QString::fromStdString(cl.toString()));

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->insertPlainText("MIN ");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->insertPlainText("MAX ");
}




















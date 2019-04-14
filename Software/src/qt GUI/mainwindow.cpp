#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddrink.h"
#include "reDrink.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QTextStream>


void Update(QString *p1, QString *p2, QString *p3, QString *p4)
{
    QString pos1 = "Vodka";
    *p1 = pos1;
    QString pos2 = "Gin";
    *p2 = pos2;
    QString pos3 = "Rum";
    *p3 = pos3;
    QString pos4 = "Buckfast";
    *p4 = pos4;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(1200,950);
    QString pos1;
    QString pos2;
    QString pos3;
    QString pos4;
    Update(&pos1,&pos2,&pos3,&pos4);
    QTextStream p1(&pos1);
    //QString pos2 = "Gin";
    QTextStream p2(&pos2);
    //QString pos3 = "Rum";
    QTextStream p3(&pos3);
    //QString pos4 = "Buckfast";
    QTextStream p4(&pos4);
    QString pos5 = "Coca Cola";
    QTextStream p5(&pos5);
    QString pos6 = "Lemonade";
    QTextStream p6(&pos6);
    QString pos7 = "Irn Bru";
    QTextStream p7(&pos7);
    QString pos8 = "Tonic";
    QTextStream p8(&pos8);

    //ui->textBrowser->setText("<font size = 6>Vodka</font>");
    ui->textBrowser->setFontWeight(60);
    ui->textBrowser->setFontPointSize(16);
    ui->textBrowser->setText(p1.readAll());
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->setFrameStyle(QFrame::NoFrame);


    //ui->textBrowser_2->setText("<font size = 6><b>Gin</b></font>");
    ui->textBrowser_2->setFontWeight(60);
    ui->textBrowser_2->setFontPointSize(16);
    ui->textBrowser_2->setText(p2.readAll());
    ui->textBrowser_2->setAlignment(Qt::AlignCenter);
    ui->textBrowser_2->setFrameStyle(QFrame::NoFrame);

    //ui->textBrowser_3->setText("<font size = 6><i>Rum</i></font>");
    ui->textBrowser_3->setFontWeight(60);
    ui->textBrowser_3->setFontPointSize(16);
    ui->textBrowser_3->setText(p3.readAll());
    ui->textBrowser_3->setAlignment(Qt::AlignCenter);
    ui->textBrowser_3->setFrameStyle(QFrame::NoFrame);

    //ui->textBrowser_4->setText("<font size = 6><i>Buckfast</i></font>");
    ui->textBrowser_4->setFontWeight(60);
    ui->textBrowser_4->setFontPointSize(16);
    ui->textBrowser_4->setText(p4.readAll());
    ui->textBrowser_4->setAlignment(Qt::AlignCenter);
    ui->textBrowser_4->setFrameStyle(QFrame::NoFrame);

    //ui->textBrowser_5->setText("<font size = 5><b><i>Coca Cola</b></i></font>");
    ui->textBrowser_5->setFontWeight(60);
    ui->textBrowser_5->setFontPointSize(16);
    ui->textBrowser_5->setText(p5.readAll());
    ui->textBrowser_5->setAlignment(Qt::AlignCenter);
    ui->textBrowser_5->setFrameStyle(QFrame::NoFrame);

    //ui->textBrowser_6->setText("<font size = 5><b><i>Lemonade</b></i></font>");
    ui->textBrowser_6->setFontWeight(60);
    ui->textBrowser_6->setFontPointSize(16);
    ui->textBrowser_6->setText(p6.readAll());
    ui->textBrowser_6->setAlignment(Qt::AlignCenter);
    ui->textBrowser_6->setFrameStyle(QFrame::NoFrame);

   // ui->textBrowser_7->setText("<font size = 5><b><i>Irn Bru</b></i></font>");
    ui->textBrowser_7->setFontWeight(60);
    ui->textBrowser_7->setFontPointSize(16);
    ui->textBrowser_7->setText(p7.readAll());
    ui->textBrowser_7->setAlignment(Qt::AlignCenter);
    ui->textBrowser_7->setFrameStyle(QFrame::NoFrame);

    //ui->textBrowser_8->setText("<font size = 5><b><i>Tonic</b></i></font>");
    ui->textBrowser_8->setFontWeight(60);
    ui->textBrowser_8->setFontPointSize(16);
    ui->textBrowser_8->setText(p8.readAll());
    ui->textBrowser_8->setAlignment(Qt::AlignCenter);
    ui->textBrowser_8->setFrameStyle(QFrame::NoFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    addDrink aDrink;
    aDrink.setModal(true);
    aDrink.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    reDrink rDrink;
    rDrink.setModal(true);
    rDrink.exec();
}

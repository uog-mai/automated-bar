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

void UpdateArr(QStringList *p)
{
    QStringList pos = {"Vodka","Gin","Rum","Buckfast","Coca Cola","Lemonade","Irn Bru","Tonic"};
    *p = pos;
    return;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(1200,950);
    QStringList pos;
    UpdateArr(&pos);
    QTextStream p0(&pos[0]);
    QTextStream p1(&pos[1]);
    QTextStream p2(&pos[2]);
    QTextStream p3(&pos[3]);
    QTextStream p4(&pos[4]);
    QTextStream p5(&pos[5]);
    QTextStream p6(&pos[6]);
    QTextStream p7(&pos[7]);

    ui->textBrowser->setFontWeight(60);
    ui->textBrowser->setFontPointSize(16);
    ui->textBrowser->setText(p0.readAll());
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_2->setFontWeight(60);
    ui->textBrowser_2->setFontPointSize(16);
    ui->textBrowser_2->setText(p1.readAll());
    ui->textBrowser_2->setAlignment(Qt::AlignCenter);
    ui->textBrowser_2->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_3->setFontWeight(60);
    ui->textBrowser_3->setFontPointSize(16);
    ui->textBrowser_3->setText(p2.readAll());
    ui->textBrowser_3->setAlignment(Qt::AlignCenter);
    ui->textBrowser_3->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_4->setFontWeight(60);
    ui->textBrowser_4->setFontPointSize(16);
    ui->textBrowser_4->setText(p3.readAll());
    ui->textBrowser_4->setAlignment(Qt::AlignCenter);
    ui->textBrowser_4->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_5->setFontWeight(60);
    ui->textBrowser_5->setFontPointSize(16);
    ui->textBrowser_5->setText(p4.readAll());
    ui->textBrowser_5->setAlignment(Qt::AlignCenter);
    ui->textBrowser_5->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_6->setFontWeight(60);
    ui->textBrowser_6->setFontPointSize(16);
    ui->textBrowser_6->setText(p5.readAll());
    ui->textBrowser_6->setAlignment(Qt::AlignCenter);
    ui->textBrowser_6->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_7->setFontWeight(60);
    ui->textBrowser_7->setFontPointSize(16);
    ui->textBrowser_7->setText(p6.readAll());
    ui->textBrowser_7->setAlignment(Qt::AlignCenter);
    ui->textBrowser_7->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_8->setFontWeight(60);
    ui->textBrowser_8->setFontPointSize(16);
    ui->textBrowser_8->setText(p7.readAll());
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

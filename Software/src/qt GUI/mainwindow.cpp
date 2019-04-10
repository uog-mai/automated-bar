#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddrink.h"
#include "reDrink.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QTextStream>

QString Drinks(QString Filename)
{
    QFile aFile(Filename);
    if(!aFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open";
        return "Could not open";
    }
    QTextStream in(&aFile);
    QString avDrinks = in.readAll();
    aFile.close();
    return avDrinks;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QString avDrinks = "C:/Users/User/Documents/AutoBar/avDrinks.txt";
    //QTextStream in(&avDrinks);
    QString avD = Drinks(avDrinks);
    ui->textBrowser->setText(avD);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_actionAdd_triggered()
{
    addDrink aDrink;
    aDrink.setModal(true);
    aDrink.exec();
}

void MainWindow::on_actionRemove_triggered()
{
    reDrink rDrink;
    rDrink.setModal(true);
    rDrink.exec();
}
*/
QString Read(QString Filename)
{
    QFile aFile(Filename);
    if(!aFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open";
        return "Could not open";
    }
    QTextStream in(&aFile);
    QString reply = in.readAll();
    aFile.close();
    return reply;
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

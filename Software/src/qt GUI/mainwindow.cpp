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
    //this->setFixedSize(1200,950);
    ui->textBrowser->setText("<font size = 5><b><i>Vodka</b></i></font>");
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_2->setText("<font size = 5><b><i>Gin</b></i></font>");
    ui->textBrowser_2->setAlignment(Qt::AlignCenter);
    ui->textBrowser_2->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_2->setFontPointSize(26);

    ui->textBrowser_3->setText("<font size = 5><b><i>Rum</b></i></font>");
    ui->textBrowser_3->setAlignment(Qt::AlignCenter);
    ui->textBrowser_3->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_3->setFontPointSize(26);

    ui->textBrowser_4->setText("<font size = 5><b><i>Buckfast</b></i></font>");
    ui->textBrowser_4->setAlignment(Qt::AlignCenter);
    ui->textBrowser_4->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_4->setFontPointSize(26);

    ui->textBrowser_5->setText("<font size = 5><b><i>Coca Cola</b></i></font>");
    ui->textBrowser_5->setAlignment(Qt::AlignCenter);
    ui->textBrowser_5->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_5->setFontPointSize(26);

    ui->textBrowser_6->setText("<font size = 5><b><i>Lemonade</b></i></font>");
    ui->textBrowser_6->setAlignment(Qt::AlignCenter);
    ui->textBrowser_6->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_6->setFontPointSize(26);

    ui->textBrowser_7->setText("<font size = 5><b><i>Irn Bru</b></i></font>");
    ui->textBrowser_7->setAlignment(Qt::AlignCenter);
    ui->textBrowser_7->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_7->setFontPointSize(26);

    ui->textBrowser_8->setText("<font size = 5><b><i>Tonic</b></i></font>");
    ui->textBrowser_8->setAlignment(Qt::AlignCenter);
    ui->textBrowser_8->setFrameStyle(QFrame::NoFrame);
    ui->textBrowser_8->setFontPointSize(26);
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

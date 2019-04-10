#include "reDrink.h"
#include "ui_reDrink.h"
#include <QFile>
#include <QString>
#include <QDebug>

reDrink::reDrink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reDrink)
{
    ui->setupUi(this);
}

reDrink::~reDrink()
{
    delete ui;
}

void Write(QString Filename,int P)
{
    QFile aFile(Filename);
    if(!aFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Could not open";
        return;
    }
    QTextStream out(&aFile);
    out << P;
    aFile.close();
}


void reDrink::on_buttonBox_accepted()
{
    QString aDrink = "C:\\Users\\User\\Desktop\\automated-bar\\Software\\src\\qt GUI\\reDrink.txt";
    int Pos = ui->spinBox->value();
    Write(aDrink, Pos);
}

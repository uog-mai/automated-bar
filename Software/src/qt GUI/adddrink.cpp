#include "adddrink.h"
#include "ui_adddrink.h"
#include <QFile>
#include <QString>
#include <QDebug>

addDrink::addDrink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDrink)
{
    ui->setupUi(this);
}

addDrink::~addDrink()
{
    delete ui;
}

void Write(QString Filename,int P, QString D, QString S)
{
    QFile aFile(Filename);
    if(!aFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Could not open";
        return;
    }
    QTextStream out(&aFile);
    out << P << "\n" << D << "\n" << S;
    aFile.close();
}


void addDrink::on_buttonBox_accepted()
{
    QString aDrink = "C:\\Users\\User\\Desktop\\automated-bar\\Software\\src\\qt GUI\\addDrink.txt";

    //int Pos = ui->spinBox->valueChanged(int);
    QString Drink = ui->plainTextEdit->toPlainText();
    QString Syn = ui->plainTextEdit_2->toPlainText();
    int Pos = ui->spinBox->value();

    Write(aDrink, Pos, Drink, Syn);
}

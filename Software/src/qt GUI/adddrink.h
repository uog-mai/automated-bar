#ifndef ADDDRINK_H
#define ADDDRINK_H

#include <QDialog>

namespace Ui {
class addDrink;
}

class addDrink : public QDialog
{
    Q_OBJECT

public:
    explicit addDrink(QWidget *parent = nullptr);
    ~addDrink();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addDrink *ui;
};

#endif // ADDDRINK_H

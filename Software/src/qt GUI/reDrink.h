#ifndef reDrink_H
#define reDrink_H

#include <QDialog>

namespace Ui {
class reDrink;
}

class reDrink : public QDialog
{
    Q_OBJECT

public:
    explicit reDrink(QWidget *parent = nullptr);
    ~reDrink();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::reDrink *ui;
};

#endif // reDrink_H

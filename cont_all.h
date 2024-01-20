#ifndef CONT_ALL_H
#define CONT_ALL_H

#include <QWidget>

namespace Ui {
class cont_all;
}

class cont_all : public QWidget
{
    Q_OBJECT

public:
    explicit cont_all(QWidget *parent = nullptr);
    ~cont_all();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cont_all *ui;
};

#endif // CONT_ALL_H

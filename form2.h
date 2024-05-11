#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

#include "db_manage.h"

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();


signals:

    void sendHide();

private slots:
    void on_pushButton_clicked();
public slots:
    void loadDbGasto();

private:
    Ui::Form2 *ui;
    db_manage * C_db;
    QSqlDatabase db;
};

#endif // FORM2_H

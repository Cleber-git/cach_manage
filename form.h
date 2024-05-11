#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "db_manage.h"


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();


private:
    Ui::Form *ui;
    db_manage *C_db;
    QSqlDatabase db;

signals:
    void sendHideFromDivida();
private slots:
    void on_pushButton_clicked();
public slots:
    void loadDbDivida();

};

#endif // FORM_H

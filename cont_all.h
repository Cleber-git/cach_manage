#ifndef CONT_ALL_H
#define CONT_ALL_H

//#include "mainwindow.h
#include <QWidget>
#include "db_manage.h"

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
public slots:
    void ChangeSum(QString mode);
//    QString getColumn();
private:
    Ui::cont_all *ui;
    QString modeSum;
    db_manage* C_db;
//    MainWindow *mw;



};

#endif // CONT_ALL_H

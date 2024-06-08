#include "cont_all.h"
#include "ui_cont_all.h"
#include "db_manage.h"
#include "mainwindow.h"
#include <QDebug>

cont_all::cont_all(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cont_all)
{
    ui->setupUi(this);

    this->setWindowTitle("TOTAL");
    C_db = new db_manage();
//    mw = new MainWindow(this);
//    connect(this, SIGNAL(QWidget::show()), this, SLOT(getColumn()));


}



cont_all::~cont_all()
{
    delete ui;
}


void cont_all::ChangeSum(QString mode){

//    qDebug()<<"Passei pelo slot";

    QSqlDatabase db = C_db->getMDB();
    C_db->Sum(db, ui->lcdNumber, mode);

}
void cont_all::on_pushButton_clicked()
{
    hide();
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_manage.h"
#include <QDebug>
#include "form.h"
#include "cont_all.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->b_deleteDB->setEnabled(false);
    this->setWindowTitle("Banc Manage");




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    db_manage C_db;
    QSqlDatabase db;
    QString path;


    db = QSqlDatabase::addDatabase("QSQLITE");

    path =  qApp->applicationDirPath() ;
    path +=  "/cach.db";
    qDebug()<<path;

    C_db.openDB( path, db );

    QString preco = ui->valor->text();
    QString motivo = ui->motivo->text();

    C_db.insert(preco, motivo);

    ui->motivo->clear();
    ui->valor->clear();

}


void MainWindow::on_b_deleteDB_clicked()
{
    db_manage C_db;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString path;
    path =  qApp->applicationDirPath() ;
    path +=  "/cach.db";

    C_db.Delete_db( path, db );
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();

    Form *form= new Form;
    form->show();


}


void MainWindow::on_cont_all_clicked()
{
    cont_all *c_a = new cont_all();
    c_a->show();
    hide();
}


void MainWindow::on_place_button_clicked()
{
    ui->b_deleteDB->setEnabled(true);
    ui->place_button->hide();
}


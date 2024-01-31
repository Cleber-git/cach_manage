#include "form2.h"
#include "ui_form2.h"
#include "mainwindow.h"
#include "db_manage.h"
#include <QDebug>


Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    this->setWindowTitle("Tabela Geral");;

    db_manage C_db;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path;
    path = qApp->applicationDirPath() + "/cach.db";



    /////////////////////////////////////////////////////////////////////////////////


    C_db.openDB(path, db);
    C_db.show_manager(ui->tableWidget, db);

}

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    hide();
}


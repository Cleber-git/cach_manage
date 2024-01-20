#include "cont_all.h"
#include "ui_cont_all.h"
#include "db_manage.h"
#include "mainwindow.h"

cont_all::cont_all(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cont_all)
{
    ui->setupUi(this);
    this->setWindowTitle("TOTAL");

    QSqlDatabase db;
    QString path = qApp->applicationDirPath() + "/cach.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db_manage db_m;
    db_m.openDB(path, db);
    db_m.Sum(db, ui->lcdNumber);
}

cont_all::~cont_all()
{
    delete ui;
}

void cont_all::on_pushButton_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    hide();
}


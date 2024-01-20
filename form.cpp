#include "form.h"
#include "ui_form.h"
#include "db_manage.h"
#include "mainwindow.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{

    ui->setupUi(this);
    this->setWindowTitle("Tabela Geral");;

    qDebug() << "Passei pelo construtor do form";
    db_manage C_db;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path;
    path = qApp->applicationDirPath() + "\cach.db";

/////////////////////////////////////////////////////////////////////////////////

    int row = 0;

    C_db.openDB(path, db);
    C_db.show_manager(ui->tableWidget, db);







}









Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    hide();
}


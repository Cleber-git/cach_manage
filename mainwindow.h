#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString read_version();
public slots:
    void ChangeModeLabel(QString name);
private slots:
    void on_pushButton_clicked();

    void on_b_deleteDB_clicked();

    void on_pushButton_2_clicked();

    void on_cont_all_clicked();

    void on_place_button_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

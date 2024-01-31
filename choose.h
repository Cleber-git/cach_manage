#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::choose *ui;
};

#endif // CHOOSE_H

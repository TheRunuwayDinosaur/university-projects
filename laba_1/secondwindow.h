#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT
private:
    QString number = "";
    QString row = "";
    QString column = "";
    QString new_value = "";
public:
    QString get_number();
    QString get_row();
    QString get_column();
    QString get_new_value();
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_read_data_clicked();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H

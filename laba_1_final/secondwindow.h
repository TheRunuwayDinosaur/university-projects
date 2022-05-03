#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    QString get_table_number();
    QString get_table_row();
    QString get_table_column();
    QString get_table_new_value();
    ~SecondWindow();
private slots:
    void on_change_data_clicked();
private:
    QString table_number;
    QString table_row;
    QString table_column;
    QString table_new_value;
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H

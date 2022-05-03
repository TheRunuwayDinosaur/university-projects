#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow(){
    delete ui;
}

void SecondWindow::on_change_data_clicked(){
    table_number = ui->t_number->text();
    table_row = ui->t_row->text();
    table_column = ui->t_column->text();
    table_new_value = ui->t_new_value->text();
    close();
}

QString SecondWindow::get_table_number(){
    return table_number;
}

QString SecondWindow::get_table_row(){
    return table_row;
}

QString SecondWindow::get_table_column(){
    return table_column;
}

QString SecondWindow::get_table_new_value(){
    return table_new_value;
}


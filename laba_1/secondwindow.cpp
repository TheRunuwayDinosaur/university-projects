#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <mainwindow.h>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow(){
    delete ui;
}

QString SecondWindow::get_number(){
    return SecondWindow::number;
}

QString SecondWindow::get_row(){
    return SecondWindow::row;
}

QString SecondWindow::get_column(){
    return SecondWindow::column;
}

QString SecondWindow::get_new_value(){
    return SecondWindow::new_value;
}

void SecondWindow::on_read_data_clicked(){
    number = ui->table_number->text();
    row = ui->table_row->text();
    column = ui->table_column->text();
    new_value = ui->new_value->text();
    close();
}

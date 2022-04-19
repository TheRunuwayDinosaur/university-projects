#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    invoice_references.clear();
    employee_references.clear();
    accouting_for_the_receipt_and_delivery_of_goods.clear();
    product_references.clear();
    delete ui;
}

void MainWindow::start_read_file(){
    work_with_files reader;
    reader.read_file(invoice_references,employee_references,accouting_for_the_receipt_and_delivery_of_goods,product_references);
}

void MainWindow::write_in_file(){
    work_with_files writer;
    writer.write_in_file(invoice_references,employee_references,accouting_for_the_receipt_and_delivery_of_goods,product_references);
}
QList <InvoiceReferences> MainWindow::data_ir(){
    return invoice_references;
}

QList <EmployeeReferences> MainWindow::data_er(){
    return employee_references;
}

QList <AccoutingForTheReceiptAndDeliveryOfGoods> MainWindow::data_aft(){
    return accouting_for_the_receipt_and_delivery_of_goods;
}

QList <ProductReferences> MainWindow::data_pr(){
    return product_references;
}

void MainWindow::show_information_from_ir(){
    QList <InvoiceReferences> data = MainWindow::data_ir();
    for (int i = 0;i < data.size();i++){
        data[i].show_all_information();
    }
}

void MainWindow::show_information_from_er(){
    QList <EmployeeReferences> data = MainWindow::data_er();
    for (int i = 0;i < data.size();i++){
        data[i].show_all_information();
    }
}

void MainWindow::show_information_from_aft(){
    QList <AccoutingForTheReceiptAndDeliveryOfGoods> data = MainWindow::data_aft();
    for (int i = 0;i < data.size();i++){
        data[i].show_all_information();
    }
}

void MainWindow::show_information_from_pr(){
    QList <ProductReferences> data = MainWindow::data_pr();
    for (int i = 0;i < data.size();i++){
        data[i].show_all_information();
    }
}

size_t MainWindow::size_invoice_references(){
    return invoice_references.size();
}

size_t MainWindow::size_employee_references(){
    return employee_references.size();
}

size_t MainWindow::size_aft_references(){
    return accouting_for_the_receipt_and_delivery_of_goods.size();
}

size_t MainWindow::size_product_references(){
    return product_references.size();
}

void MainWindow::set_table_ir_size(){
    ui->InvoiceReferences->setRowCount(size_invoice_references());
    ui->InvoiceReferences->setColumnCount(7);
}

void MainWindow::set_table_er_size(){
    ui->EmployeeReferences->setRowCount(size_employee_references());
    ui->EmployeeReferences->setColumnCount(3);
}

void MainWindow::set_table_aft_size(){
    ui->AccoutingForTheReceiptAndDeliveryOfGoods->setRowCount(size_aft_references());
    ui->AccoutingForTheReceiptAndDeliveryOfGoods->setColumnCount(5);
}

void MainWindow::set_table_pr_size(){
    ui->ProductReferences->setRowCount(size_product_references());
    ui->ProductReferences->setColumnCount(5);
}

void MainWindow::constract_tables(){
    set_table_ir_size();
    set_table_er_size();
    set_table_aft_size();
    set_table_pr_size();
    QStringList h_ir = {"тип","id","Наименование","Ед.измерения","Количество","Цена (руб)","Сумма (руб)"};
    QStringList h_er = {"ФИО","Должность","Оклад (руб)"};
    QStringList h_aft = {"Наименование товара","Приход","Расход","Цена (руб)","Сумма (руб)"};
    QStringList h_pr = {"Наименование товара","Код товара","Код вида товара","Поставщик","Количество"};
    ui->InvoiceReferences->setHorizontalHeaderLabels(h_ir);
    ui->EmployeeReferences->setHorizontalHeaderLabels(h_er);
    ui->AccoutingForTheReceiptAndDeliveryOfGoods->setHorizontalHeaderLabels(h_aft);
    ui->ProductReferences->setHorizontalHeaderLabels(h_pr);
}


QString cur_value_in_ir_table(InvoiceReferences &data,int &pos_in_ir){
    QString value = "";
    if (pos_in_ir == 1){
        value = data.get_type();
    }
    else if (pos_in_ir == 2){
        value = QVariant(data.get_id()).toString();
    }
    else if (pos_in_ir == 3){
        value = data.get_name();
    }
    else if (pos_in_ir == 4){
        value = data.get_unit_of_measurement();
    }
    else if (pos_in_ir == 5){
        value = QVariant(data.get_count()).toString();
    }
    else if (pos_in_ir == 6){
        value = QVariant(data.get_price()).toString();
    }
    else if (pos_in_ir == 7){
        value = QVariant(data.get_current_sum()).toString();
    }
    pos_in_ir++;
    return value;
}

QString cur_value_in_er_table(EmployeeReferences &data,int &pos_in_er){
    QString value = "";
    if (pos_in_er == 1){
        value = data.get_name();
    }
    else if (pos_in_er == 2){
        value = data.get_post();
    }
    else if (pos_in_er == 3){
        value = QVariant(data.get_salary()).toString();
    }
    pos_in_er++;
    return value;
}

QString cur_value_in_aft_table(AccoutingForTheReceiptAndDeliveryOfGoods &data,int &pos_in_aft){
    QString value = "";
    if (pos_in_aft == 1){
        value = data.get_name();
    }
    else if (pos_in_aft == 2){
        value = QVariant(data.get_coming()).toString();
    }
    else if (pos_in_aft == 3){
        value = QVariant(data.get_expenditure()).toString();
    }
    else if (pos_in_aft == 4){
        value = QVariant(data.get_price()).toString();
    }
    else if (pos_in_aft == 5){
        value = QVariant(data.get_current_sum()).toString();
    }
    pos_in_aft++;
    return value;
}

QString cur_value_in_pr_table(ProductReferences &data,int &pos_in_pr){
    QString value = "";
    if (pos_in_pr == 1){
        value = data.get_name();
    }
    else if (pos_in_pr == 2){
        value = QVariant(data.get_product_code()).toString();
    }
    else if (pos_in_pr == 3){
        value = QVariant(data.get_product_type_code()).toString();
    }
    else if (pos_in_pr == 4){
        value = data.get_provider();
    }
    else if (pos_in_pr == 5){
        value = QVariant(data.get_count()).toString();
    }
    pos_in_pr++;
    return value;
}

void MainWindow::on_add_all_data_in_tables_clicked(){
    was_all_data_deleted = false;
    if (invoice_references.size() == 0){
        QMessageBox::critical(this,"Статус","Нет данных для заполнения таблиц!!!");
        return;
    }
    if (!was_all_data_show){
        QMessageBox::information(this,"Статус","Успешно!");
        was_all_data_show = true;
    }
    else QMessageBox::critical(this,"Статус","Данные уже записаны!");
    MainWindow::constract_tables();
    for (int row = 0;row < ui->InvoiceReferences->rowCount();row++){
        int pos_in_ir = 1;
        InvoiceReferences data = invoice_references[row];
        for (int column = 0;column < ui->InvoiceReferences->columnCount();column++){
            QString value = cur_value_in_ir_table(data,pos_in_ir);
            QTableWidgetItem *item = new QTableWidgetItem(value);
            item->setBackground(Qt::yellow);
            ui->InvoiceReferences->setItem(row,column,item);
        }
    }
    for (int row = 0;row < ui->EmployeeReferences->rowCount();row++){
        int pos_in_er = 1;
        EmployeeReferences data = employee_references[row];
        for (int column = 0;column < ui->EmployeeReferences->columnCount();column++){
            QString value = cur_value_in_er_table(data,pos_in_er);
            QTableWidgetItem *item = new QTableWidgetItem(value);
            item->setBackground(Qt::yellow);
            ui->EmployeeReferences->setItem(row,column,item);
        }
    }
    for (int row = 0;row < ui->AccoutingForTheReceiptAndDeliveryOfGoods->rowCount();row++){
        int pos_in_aft = 1;
        AccoutingForTheReceiptAndDeliveryOfGoods data = accouting_for_the_receipt_and_delivery_of_goods[row];
        for (int column = 0;column < ui->AccoutingForTheReceiptAndDeliveryOfGoods->columnCount();column++){
            QString value = cur_value_in_aft_table(data,pos_in_aft);
            QTableWidgetItem *item = new QTableWidgetItem(value);
            item->setBackground(Qt::yellow);
            ui->AccoutingForTheReceiptAndDeliveryOfGoods->setItem(row,column,item);
        }
    }
    for (int row = 0;row < ui->ProductReferences->rowCount();row++){
        int pos_in_pr = 1;
        ProductReferences data = product_references[row];
        for (int column = 0;column < ui->ProductReferences->columnCount();column++){
            QString value = cur_value_in_pr_table(data,pos_in_pr);
            QTableWidgetItem *item = new QTableWidgetItem(value);
            item->setBackground(Qt::yellow);
            ui->ProductReferences->setItem(row,column,item);
        }
    }
}


void MainWindow::on_read_data_from_file_clicked(){
    bool ok = MainWindow::was_data_read;
    if (ok){
        QMessageBox::critical(this,"Статус","Данные уже прочитаны!!!");
        return;
    }
    MainWindow::was_data_read = true;
    MainWindow::start_read_file();
    QMessageBox::information(this,"Статус","Данные успешно считаны и записаны во внутренний буфер");
}

void MainWindow::on_delete_all_data_from_tables_clicked(){
    if (was_all_data_deleted || invoice_references.size() == 0){
        QMessageBox::critical(this,"Статус","Таблицы пустые!!!");
        return;
    }
    QMessageBox::information(this,"Статус","Успешно!!!");
    was_all_data_deleted = true;
    was_all_data_show = false;
    ui->InvoiceReferences->setRowCount(0); ui->InvoiceReferences->setColumnCount(0);
    ui->EmployeeReferences->setRowCount(0); ui->EmployeeReferences->setColumnCount(0);
    ui->AccoutingForTheReceiptAndDeliveryOfGoods->setRowCount(0); ui->AccoutingForTheReceiptAndDeliveryOfGoods->setColumnCount(0);
    ui->ProductReferences->setRowCount(0); ui->ProductReferences->setColumnCount(0);
    for (int row = 0;row < ui->InvoiceReferences->rowCount();row++){
        for (int column = 0;column < ui->InvoiceReferences->columnCount();column++){
            delete ui->InvoiceReferences->item(row,column);
        }
    }
    for (int row = 0;row < ui->EmployeeReferences->rowCount();row++){
        for (int column = 0;column < ui->EmployeeReferences->columnCount();column++){
            delete ui->EmployeeReferences->item(row,column);
        }
    }
    for (int row = 0;row < ui->AccoutingForTheReceiptAndDeliveryOfGoods->rowCount();row++){
        for (int column = 0;column < ui->AccoutingForTheReceiptAndDeliveryOfGoods->columnCount();column++){
            delete ui->AccoutingForTheReceiptAndDeliveryOfGoods->item(row,column);
        }
    }
    for (int row = 0;row < ui->ProductReferences->rowCount();row++){
        for (int column = 0;column < ui->ProductReferences->columnCount();column++){
            delete ui->ProductReferences->item(row,column);
        }
    }
}

void MainWindow::on_change_data_in_table_clicked(){
    QTextStream out(stdout);
    SecondWindow window;
    window.setModal(true);
    window.exec();
    int number = window.get_number().toInt(),row = window.get_row().toInt(),column = window.get_column().toInt();
    QString new_value = window.get_new_value();
    if (number < 1 || number > 4){
        QMessageBox::critical(this,"Статус","Недопустимый номер таблицы!!!");
        return;
    }
    else{
        if (number == 1){
            if (row < 1 || row > ui->InvoiceReferences->rowCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение строки!!!");
                return;
            }
            if (column < 1 || column > ui->InvoiceReferences->columnCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение столбца!!!");
                return;
            }
            delete ui->InvoiceReferences->item(row - 1,column - 1);
            QTableWidgetItem *item = new QTableWidgetItem(new_value);
            item->setBackground(Qt::yellow);
            ui->InvoiceReferences->setItem(row - 1,column - 1,item);
            if (column == 1) invoice_references[row - 1].set_type(new_value);
            else if (column == 2) invoice_references[row - 1].set_id(new_value.toInt());
            else if (column == 3) invoice_references[row - 1].set_name(new_value);
            else if (column == 4) invoice_references[row - 1].set_unit_of_measurement(new_value);
            else if (column == 5) invoice_references[row - 1].set_count(new_value.toInt());
            else if (column == 6) invoice_references[row - 1].set_price(new_value.toDouble());
            else if (column == 7) invoice_references[row - 1].set_current_sum(new_value.toDouble());
        }
        else if (number == 2){
            if (row < 1 || row > ui->EmployeeReferences->rowCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение строки!!!");
                return;
            }
            if (column < 1 || column > ui->EmployeeReferences->columnCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение столбца!!!");
                return;
            }
            delete ui->EmployeeReferences->item(row - 1,column - 1);
            QTableWidgetItem *item = new QTableWidgetItem(new_value);
            item->setBackground(Qt::yellow);
            ui->EmployeeReferences->setItem(row - 1,column - 1,item);
            if (column == 1) employee_references[row - 1].set_name(new_value);
            else if (column == 2) employee_references[row - 1].set_post(new_value);
            else if (column == 3) employee_references[row - 1].set_salary(new_value.toDouble());
        }
        else if (number == 3){
            if (row < 1 || row > ui->AccoutingForTheReceiptAndDeliveryOfGoods->rowCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение строки!!!");
                return;
            }
            if (column < 1 || column > ui->AccoutingForTheReceiptAndDeliveryOfGoods->columnCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение столбца!!!");
                return;
            }
            delete ui->AccoutingForTheReceiptAndDeliveryOfGoods->item(row - 1,column - 1);
            QTableWidgetItem *item = new QTableWidgetItem(new_value);
            item->setBackground(Qt::yellow);
            ui->AccoutingForTheReceiptAndDeliveryOfGoods->setItem(row - 1,column - 1,item);
            if (column == 1) accouting_for_the_receipt_and_delivery_of_goods[row - 1].set_name(new_value);
            else if (column == 2) accouting_for_the_receipt_and_delivery_of_goods[row - 1].set_coming(new_value.toInt());
            else if (column == 3) accouting_for_the_receipt_and_delivery_of_goods[row - 1].set_expenditure(new_value.toInt());
            else if (column == 4) accouting_for_the_receipt_and_delivery_of_goods[row - 1].set_price(new_value.toDouble());
            else if (column == 5) accouting_for_the_receipt_and_delivery_of_goods[row - 1].set_current_sum(new_value.toDouble());
        }
        else{
            if (row < 1 || row > ui->ProductReferences->rowCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение строки!!!");
                return;
            }
            if (column < 1 || column > ui->ProductReferences->columnCount()){
                QMessageBox::critical(this,"Статус","Недопустимое значение столбца!!!");
                return;
            }
            delete ui->ProductReferences->item(row - 1,column - 1);
            QTableWidgetItem *item = new QTableWidgetItem(new_value);
            item->setBackground(Qt::yellow);
            ui->ProductReferences->setItem(row - 1,column - 1,item);
            if (column == 1) product_references[row - 1].set_name(new_value);
            else if (column == 2) product_references[row - 1].set_product_code(new_value.toInt());
            else if (column == 3) product_references[row - 1].set_product_type_code(new_value.toInt());
            else if (column == 4) product_references[row - 1].set_provider(new_value);
            else if (column == 5) product_references[row - 1].set_count(new_value.toInt());
        }
    }
}

void MainWindow::on_write_data_in_file_clicked(){
    MainWindow::write_in_file();
    QMessageBox::information(this,"Статус","Данные успешно записаны!!!");
}


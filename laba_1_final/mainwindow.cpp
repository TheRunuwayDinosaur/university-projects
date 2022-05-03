#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    model_ir->setRowCount(size_invoice_references());
    model_ir->setColumnCount(7);
    QStringList h_ir = {"тип","id","Наименование","Ед.измерения","Количество","Цена (руб)","Сумма (руб)"};
    model_ir->setHorizontalHeaderLabels(h_ir);
}

void MainWindow::set_table_er_size(){
    model_er->setRowCount(size_employee_references());
    model_er->setColumnCount(3);
    QStringList h_er = {"ФИО","Должность","Оклад (руб)"};
    model_er->setHorizontalHeaderLabels(h_er);
}

void MainWindow::set_table_aft_size(){
    model_aft->setRowCount(size_aft_references());
    model_aft->setColumnCount(5);
    QStringList h_aft = {"Наименование товара","Приход","Расход","Цена (руб)","Сумма (руб)"};
    model_aft->setHorizontalHeaderLabels(h_aft);
}

void MainWindow::set_table_pr_size(){
    model_pr->setRowCount(size_product_references());
    model_pr->setColumnCount(5);
    QStringList h_pr = {"Наименование товара","Код товара","Код вида товара","Поставщик","Количество"};
    model_pr->setHorizontalHeaderLabels(h_pr);
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

void MainWindow::constract_tables(){
    set_table_ir_size();
    set_table_er_size();
    set_table_aft_size();
    set_table_pr_size();
    ui->tableInvoiceReferences->setModel(model_ir);
    ui->tableEmployeeReferences->setModel(model_er);
    ui->tableAFT->setModel(model_aft);
    ui->tableProductReferences->setModel(model_pr);
    for (int row = 0;row < model_ir->rowCount();row++){
        InvoiceReferences data = invoice_references[row];
        int pos_in_ir = 1;
        for (int column = 0;column < model_ir->columnCount();column++){
            QString value = cur_value_in_ir_table(data,pos_in_ir);
            QModelIndex index = model_ir->index(row,column);
            model_ir->setData(index,value);
        }
    }
    for (int row = 0;row < model_er->rowCount();row++){
        EmployeeReferences data = employee_references[row];
        int pos_in_er = 1;
        for (int column = 0;column < model_er->columnCount();column++){
            QString value = cur_value_in_er_table(data,pos_in_er);
            QModelIndex index = model_er->index(row,column);
            model_er->setData(index,value);
        }
    }
    for (int row = 0;row < model_aft->rowCount();row++){
        AccoutingForTheReceiptAndDeliveryOfGoods data = accouting_for_the_receipt_and_delivery_of_goods[row];
        int pos_in_aft = 1;
        for (int column = 0;column < model_aft->columnCount();column++){
            QString value = cur_value_in_aft_table(data,pos_in_aft);
            QModelIndex index = model_aft->index(row,column);
            model_aft->setData(index,value);
        }
    }
    for (int row = 0;row < model_pr->rowCount();row++){
        ProductReferences data = product_references[row];
        int pos_in_pr = 1;
        for (int column = 0;column < model_pr->columnCount();column++){
            QString value = cur_value_in_pr_table(data,pos_in_pr);
            QModelIndex index = model_pr->index(row,column);
            model_pr->setData(index,value);
        }
    }
}

void MainWindow::on_read_data_in_file_clicked(){
    if (file_was_readed){
        QMessageBox::critical(this,"Статус","Данные уже прочитаны!!!");
        return;
    }
    work_with_files *reader = new work_with_files;
    reader->read_file(invoice_references,employee_references,accouting_for_the_receipt_and_delivery_of_goods,product_references);
    file_was_readed = true;
    delete reader;
    QMessageBox::information(this,"Статус","Данные успешно прочитаны!");
}

void MainWindow::on_write_data_in_file_clicked(){
    if (!file_was_readed){
        QMessageBox::critical(this,"Статус","Нет данных для записи!!!");
        return;
    }
    work_with_files *writer = new work_with_files;
    writer->write_in_file(invoice_references,employee_references,accouting_for_the_receipt_and_delivery_of_goods,product_references);
    delete writer;
    QMessageBox::information(this,"Статус","Успешно!");
}

void MainWindow::on_add_all_tables_clicked(){
    if (invoice_references.size() == 0){
        QMessageBox::critical(this,"Статус","Нет данных для заполнения таблиц!!!");
        return;
    }
    if (was_table_constracted){
        QMessageBox::critical(this,"Статус","Таблицы уже заполнены!!!");
        return;
    }
    QMessageBox::information(this,"Статус","Успешно!");
    constract_tables();
    was_table_constracted = true;
}

void MainWindow::on_clear_all_tables_clicked(){
    if (!was_table_constracted){
        QMessageBox::critical(this,"Статус","Таблицы пустые!!!");
        return;
    }
    QMessageBox::information(this,"Статус","Успешно!");
    model_ir->clear(); model_er->clear();
    model_aft->clear(); model_pr->clear();
    was_table_constracted = false;
}

void MainWindow::on_change_data_in_table_clicked(){
    if (!was_table_constracted){
        QMessageBox::critical(this,"Статус","Таблицы пустые!!!");
        return;
    }
    SecondWindow *window = new SecondWindow;
    window->setModal(true);
    window->exec();
    int number = window->get_table_number().toInt();
    int row = window->get_table_row().toInt();
    int column = window->get_table_column().toInt();
    QString new_value = window->get_table_new_value();
    if (number < 1 || number > 4){
        QMessageBox::critical(this,"Статус","Некорректный номер таблицы!!!");
        return;
    }
    if (number == 1){
        if (row < 1 || row > model_ir->rowCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер строки!!!");
            return;
        }
        if (column < 1 || column > model_ir->columnCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер столбца!!!");
            return;
        }
        row--; column--;
        QModelIndex index = model_ir->index(row,column);
        model_ir->setData(index,new_value);
        if (column == 0) invoice_references[row].set_type(new_value);
        else if (column == 1) invoice_references[row].set_id(new_value.toInt());
        else if (column == 2) invoice_references[row].set_name(new_value);
        else if (column == 3) invoice_references[row].set_unit_of_measurement(new_value);
        else if (column == 4) invoice_references[row].set_count(new_value.toInt());
        else if (column == 5) invoice_references[row].set_price(new_value.toDouble());
        else if (column == 6) invoice_references[row].set_current_sum(new_value.toDouble());
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else if (number == 2){
        if (row < 1 || row > model_er->rowCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер строки!!!");
            return;
        }
        if (column < 1 || column > model_er->columnCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер столбца!!!");
            return;
        }
        row--; column--;
        QModelIndex index = model_er->index(row,column);
        model_er->setData(index,new_value);
        if (column == 0) employee_references[row].set_name(new_value);
        else if (column == 1) employee_references[row].set_post(new_value);
        else if (column == 2) employee_references[row].set_salary(new_value.toDouble());
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else if (number == 3){
        if (row < 1 || row > model_aft->rowCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер строки!!!");
            return;
        }
        if (column < 1 || column > model_aft->columnCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер столбца!!!");
            return;
        }
        row--; column--;
        QModelIndex index = model_aft->index(row,column);
        model_aft->setData(index,new_value);
        if (column == 0) accouting_for_the_receipt_and_delivery_of_goods[row].set_name(new_value);
        else if (column == 1) accouting_for_the_receipt_and_delivery_of_goods[row].set_coming(new_value.toInt());
        else if (column == 2) accouting_for_the_receipt_and_delivery_of_goods[row].set_expenditure(new_value.toInt());
        else if (column == 3) accouting_for_the_receipt_and_delivery_of_goods[row].set_price(new_value.toDouble());
        else if (column == 4) accouting_for_the_receipt_and_delivery_of_goods[row].set_current_sum(new_value.toDouble());
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else{
        if (row < 1 || row > model_pr->rowCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер строки!!!");
            return;
        }
        if (column < 1 || column > model_pr->columnCount()){
            QMessageBox::critical(this,"Статус","Некорректный номер столбца!!!");
            return;
        }
        row--; column--;
        QModelIndex index = model_pr->index(row,column);
        model_pr->setData(index,new_value);
        if (column == 0) product_references[row].set_name(new_value);
        else if (column == 1) product_references[row].set_product_code(new_value.toInt());
        else if (column == 2) product_references[row].set_product_type_code(new_value.toInt());
        else if (column == 3) product_references[row].set_provider(new_value);
        else if (column == 4) product_references[row].set_count(new_value.toInt());
        QMessageBox::information(this,"Статус","Успешно!");
    }
    delete window;
}

MainWindow::~MainWindow(){
    invoice_references.clear();
    employee_references.clear();
    accouting_for_the_receipt_and_delivery_of_goods.clear();
    product_references.clear();
    delete ui;
}

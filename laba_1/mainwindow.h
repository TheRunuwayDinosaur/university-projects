#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <work_with_files.h>
#include <accoutingforthereceiptanddeliveryofgoods.h>
#include <employeereferences.h>
#include <invoicereferences.h>
#include <productreferences.h>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <secondwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool was_all_data_show = false;
    bool was_all_data_deleted = false;
    bool was_data_read = false;
    bool was_data_writed = false;
    QList <InvoiceReferences> invoice_references;
    QList <EmployeeReferences> employee_references;
    QList <AccoutingForTheReceiptAndDeliveryOfGoods> accouting_for_the_receipt_and_delivery_of_goods;
    QList <ProductReferences> product_references;
    Ui::MainWindow *ui;
public:
    MainWindow(QWidget *parent = nullptr);
    void start_read_file();
    void write_in_file();
    QList <InvoiceReferences> data_ir();
    QList <EmployeeReferences> data_er();
    QList <AccoutingForTheReceiptAndDeliveryOfGoods> data_aft();
    QList <ProductReferences> data_pr();
    void show_information_from_ir();
    void show_information_from_er();
    void show_information_from_aft();
    void show_information_from_pr();
    size_t size_invoice_references();
    size_t size_employee_references();
    size_t size_aft_references();
    size_t size_product_references();
    void set_table_ir_size();
    void set_table_er_size();
    void set_table_aft_size();
    void set_table_pr_size();
    void constract_tables();
    ~MainWindow();
private slots:

    void on_add_all_data_in_tables_clicked();
    void on_read_data_from_file_clicked();
    void on_delete_all_data_from_tables_clicked();
    void on_change_data_in_table_clicked();
    void on_write_data_in_file_clicked();
};
#endif // MAINWINDOW_H

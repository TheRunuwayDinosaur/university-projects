#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <invoicereferences.h>
#include <accoutingforthereceiptanddeliveryofgoods.h>
#include <employeereferences.h>
#include <productreferences.h>
#include <work_with_files.h>
#include <QMessageBox>
#include <secondwindow.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool file_was_readed = false;
    bool was_table_constracted = false;
    QList <InvoiceReferences> invoice_references;
    QList <EmployeeReferences> employee_references;
    QList <AccoutingForTheReceiptAndDeliveryOfGoods> accouting_for_the_receipt_and_delivery_of_goods;
    QList <ProductReferences> product_references;
    Ui::MainWindow *ui;
    QStandardItemModel *model_ir = new QStandardItemModel,*model_er = new QStandardItemModel,*model_aft = new QStandardItemModel,*model_pr = new QStandardItemModel;
public:
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_read_data_in_file_clicked();
    void on_add_all_tables_clicked();
    void on_clear_all_tables_clicked();
    void on_write_data_in_file_clicked();
    void on_change_data_in_table_clicked();
};
#endif // MAINWINDOW_H

#ifndef WORK_WITH_FILES_H
#define WORK_WITH_FILES_H

#include <QFile>
#include <QList>
#include <QString>
#include <accoutingforthereceiptanddeliveryofgoods.h>
#include <employeereferences.h>
#include <invoicereferences.h>
#include <productreferences.h>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QWidget>
#include <QDataStream>

class work_with_files{
private:
    QFile fileIn;
    QFile fileOut;
public:
    void write_in_file(QList <InvoiceReferences> &invoice_references,QList <EmployeeReferences> &employee_references,QList <AccoutingForTheReceiptAndDeliveryOfGoods> &accouting_for_the_receipt_and_delivery_of_goods,QList <ProductReferences> &product_reference);
    void read_file(QList <InvoiceReferences> &invoice_references,QList <EmployeeReferences> &employee_references,QList <AccoutingForTheReceiptAndDeliveryOfGoods> &accouting_for_the_receipt_and_delivery_of_goods,QList <ProductReferences> &product_reference);
};

#endif // WORK_WITH_FILES_H

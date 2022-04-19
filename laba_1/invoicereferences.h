#ifndef INVOICEREFERENCES_H
#define INVOICEREFERENCES_H

#include <QString>
#include <QTextStream>

class InvoiceReferences{
private:
    QString type;
    int id;
    QString name;
    QString unit_of_measurement;
    int count;
    double price;
    double current_sum;
public:
    InvoiceReferences(
        QString type_ = "",
        int id_ = -1,
        QString name_ = "",
        QString unit_of_measurement_ = "",
        int count_ = 0,
        double price_ = 0.,
        double current_sum_ = 0.
    ){
        type = type_,id = id_,name = name_,
        unit_of_measurement = unit_of_measurement_,
        count = count_,price = price_,current_sum = current_sum_;
    };
    void set_type(QString type_);
    void set_id(int id_);
    void set_name(QString name_);
    void set_unit_of_measurement(QString unit_of_measurement_);
    void set_count(int count_);
    void set_price(double price_);
    void set_current_sum(double current_sum_);
    void show_all_information();
    QString get_type();
    int get_id();
    QString get_name();
    QString get_unit_of_measurement();
    int get_count();
    double get_price();
    double get_current_sum();
};

#endif // INVOICEREFERENCES_H

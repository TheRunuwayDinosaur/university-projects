#include "invoicereferences.h"

void InvoiceReferences::set_type(QString type_){
    type = type_;
}

void InvoiceReferences::set_id(int id_){
    id = id_;
}

void InvoiceReferences::set_name(QString name_){
    name = name_;
}

void InvoiceReferences::set_unit_of_measurement(QString unit_of_measurement_){
    unit_of_measurement = unit_of_measurement_;
}

void InvoiceReferences::set_count(int count_){
    count = count_;
}

void InvoiceReferences::set_price(double price_){
    price = price_;
}

void InvoiceReferences::set_current_sum(double current_sum_){
    current_sum = current_sum_;
}

void InvoiceReferences::show_all_information(){
    QTextStream out(stdout);
    out << InvoiceReferences::type << ' ' << InvoiceReferences::id << ' ' << InvoiceReferences::name << ' ' << InvoiceReferences::unit_of_measurement << ' ' << InvoiceReferences::count << ' ' << InvoiceReferences::price << ' ' << InvoiceReferences::current_sum << "\n";
}

QString InvoiceReferences::get_type(){
    return InvoiceReferences::type;
}

int InvoiceReferences::get_id(){
    return InvoiceReferences::id;
}

QString InvoiceReferences::get_name(){
    return InvoiceReferences::name;
}

QString InvoiceReferences::get_unit_of_measurement(){
    return InvoiceReferences::unit_of_measurement;
}

int InvoiceReferences::get_count(){
    return InvoiceReferences::count;
}

double InvoiceReferences::get_price(){
    return InvoiceReferences::price;
}

double InvoiceReferences::get_current_sum(){
    return InvoiceReferences::current_sum;
}

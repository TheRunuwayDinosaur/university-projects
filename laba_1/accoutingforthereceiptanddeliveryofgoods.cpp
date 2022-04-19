#include "accoutingforthereceiptanddeliveryofgoods.h"

void AccoutingForTheReceiptAndDeliveryOfGoods::set_name(QString name_){
    name = name_;
}

void AccoutingForTheReceiptAndDeliveryOfGoods::set_coming(int coming_){
    coming = coming_;
}

void AccoutingForTheReceiptAndDeliveryOfGoods::set_expenditure(int expenditure_){
    expenditure = expenditure_;
}

void AccoutingForTheReceiptAndDeliveryOfGoods::set_price(double price_){
    price = price_;
}

void AccoutingForTheReceiptAndDeliveryOfGoods::set_current_sum(double current_sum_){
    current_sum = current_sum_;
}

void AccoutingForTheReceiptAndDeliveryOfGoods::show_all_information(){
    QTextStream out(stdout);
    out << AccoutingForTheReceiptAndDeliveryOfGoods::name << ' ' << AccoutingForTheReceiptAndDeliveryOfGoods::coming << ' ' << AccoutingForTheReceiptAndDeliveryOfGoods::expenditure << ' ' << AccoutingForTheReceiptAndDeliveryOfGoods::price << ' ' << AccoutingForTheReceiptAndDeliveryOfGoods::current_sum << "\n";
}

QString AccoutingForTheReceiptAndDeliveryOfGoods::get_name(){
    return AccoutingForTheReceiptAndDeliveryOfGoods::name;
}

int AccoutingForTheReceiptAndDeliveryOfGoods::get_coming(){
    return AccoutingForTheReceiptAndDeliveryOfGoods::coming;
}

int AccoutingForTheReceiptAndDeliveryOfGoods::get_expenditure(){
    return AccoutingForTheReceiptAndDeliveryOfGoods::expenditure;
}

double AccoutingForTheReceiptAndDeliveryOfGoods::get_price(){
    return AccoutingForTheReceiptAndDeliveryOfGoods::price;
}

double AccoutingForTheReceiptAndDeliveryOfGoods::get_current_sum(){
    return AccoutingForTheReceiptAndDeliveryOfGoods::current_sum;
}

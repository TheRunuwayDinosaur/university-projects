#ifndef ACCOUTINGFORTHERECEIPTANDDELIVERYOFGOODS_H
#define ACCOUTINGFORTHERECEIPTANDDELIVERYOFGOODS_H

#include <QString>
#include <QTextStream>

class AccoutingForTheReceiptAndDeliveryOfGoods{
private:
    QString name;
    int coming;
    int expenditure;
    double price;
    double current_sum;
public:
    AccoutingForTheReceiptAndDeliveryOfGoods(
        QString name_ = "",
        int coming_ = -1,
        int expenditure_ = -1,
        double price_ = 0.,
        double current_sum_ = 0.
    ){
        name = name_,coming = coming_,
        expenditure = expenditure_,price = price_,
        current_sum = current_sum_;
    };
    void set_name(QString name_);
    void set_coming(int coming_);
    void set_expenditure(int expenditure_);
    void set_price(double price_);
    void set_current_sum(double current_sum_);
    void show_all_information();
    QString get_name();
    int get_coming();
    int get_expenditure();
    double get_price();
    double get_current_sum();
};

#endif // ACCOUTINGFORTHERECEIPTANDDELIVERYOFGOODS_H

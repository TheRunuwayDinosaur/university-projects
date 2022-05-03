#ifndef PRODUCTREFERENCES_H
#define PRODUCTREFERENCES_H


#include <QString>
#include <QTextStream>

class ProductReferences{
private:
    QString name;
    int product_code;
    int product_type_code;
    QString provider;
    int count;
public:
    ProductReferences(
            QString name_ = "",
            int product_code_ = -1,
            int product_type_code_ = -1,
            QString provider_ = "",
            int count_ = 0
    ){
        name = name_,product_code = product_code_,
        product_type_code = product_type_code_,
        provider = provider_,count = count_;
    };
    void set_name(QString name_);
    void set_product_code(int product_code_);
    void set_product_type_code(int product_type_code_);
    void set_provider(QString provider_);
    void set_count(int count_);
    void show_all_information();
    QString get_name();
    int get_product_code();
    int get_product_type_code();
    QString get_provider();
    int get_count();
};

#endif // PRODUCTREFERENCES_H

#include "productreferences.h"

void ProductReferences::set_name(QString name_){
    name = name_;
}

void ProductReferences::set_product_code(int product_code_){
    product_code = product_code_;
}

void ProductReferences::set_product_type_code(int product_type_code_){
    product_type_code = product_type_code_;
}

void ProductReferences::set_provider(QString provider_){
    provider = provider_;
}

void ProductReferences::set_count(int count_){
    count = count_;
}

void ProductReferences::show_all_information(){
    QTextStream out(stdout);
    out << ProductReferences::name << ' ' << ProductReferences::product_code << ' ' << ProductReferences::product_type_code << ' ' << ProductReferences::provider << ' ' << ProductReferences::count << "\n";
}

QString ProductReferences::get_name(){
    return ProductReferences::name;
}

int ProductReferences::get_product_code(){
    return ProductReferences::product_code;
}

int ProductReferences::get_product_type_code(){
    return ProductReferences::product_type_code;
}

QString ProductReferences::get_provider(){
    return ProductReferences::provider;
}

int ProductReferences::get_count(){
    return ProductReferences::count;
}

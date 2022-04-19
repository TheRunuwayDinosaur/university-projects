#include "employeereferences.h"

void EmployeeReferences::set_name(QString name_){
    name = name_;
}

void EmployeeReferences::set_post(QString post_){
    post = post_;
}

void EmployeeReferences::set_salary(double salary_){
    salary = salary_;
}

void EmployeeReferences::show_all_information(){
    QTextStream out(stdout);
    out << EmployeeReferences::name << ' ' << EmployeeReferences::post << ' ' << EmployeeReferences::salary << "\n";
}

QString EmployeeReferences::get_name(){
    return EmployeeReferences::name;
}

QString EmployeeReferences::get_post(){
    return EmployeeReferences::post;
}

double EmployeeReferences::get_salary(){
    return EmployeeReferences::salary;
}

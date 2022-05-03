#ifndef EMPLOYEEREFERENCES_H
#define EMPLOYEEREFERENCES_H


#include <QString>
#include <QTextStream>

class EmployeeReferences{
private:
    QString name;
    QString post;
    double salary;
public:
    EmployeeReferences(
        QString name_ = "",
        QString post_ = "",
        double salary_ = 0.
    ){
        name = name_,post = post_,salary = salary_;
    };
    void set_name(QString name_);
    void set_post(QString post_);
    void set_salary(double salary_);
    void show_all_information();
    QString get_name();
    QString get_post();
    double get_salary();
};
#endif // EMPLOYEEREFERENCES_H

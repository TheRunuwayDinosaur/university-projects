#include "work_with_numbers.h"

work_with_numbers::work_with_numbers(){

}

QString work_with_numbers::cast_in_str(QVector<int> &numbers){
    QString result = "";
    for (auto& num : numbers){
        QString str_num = QVariant(num).toString();
        if (num > 99) result += str_num;
        else if (num > 9){
            if (result.size() > 0) result.remove(str_num.size() - 1,2);
            result += str_num;
        }
        else{
            if (result.size() > 0) result.remove(result.size() - 1,1);
            result += str_num;
        }
    }
    return result;
}

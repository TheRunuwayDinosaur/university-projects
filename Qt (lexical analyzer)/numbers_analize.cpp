#include "numbers_analize.h"

numbers_analize::numbers_analize(){

}

std::tuple <int,int,int> numbers_analize::is_correct(QVector<int> &numbers){
    QVector <int> numbers_length;
    for (auto val : numbers){
        int temp_val = val,cur_len = 0;
        while(temp_val > 0){
            cur_len++;
            temp_val /= 10;
        }
        numbers_length.push_back(cur_len);
    }
    for (int i = 0;i < numbers_length.size() - 1;i++){
        if (numbers_length[i] <= numbers_length[i + 1]) return std::make_tuple(-1,numbers_length[i],numbers_length[i + 1]);
    }
    if (numbers_length.front() == 3){
        if (numbers_length.size() > 2 && numbers[1] > 9 && numbers[1] < 20) return std::make_tuple(0,-1,-1);
    }
    else if (numbers_length.front() == 2){
        if (numbers_length.size() > 1 && numbers[0] > 9 && numbers[0] < 20) return std::make_tuple(0,-1,-1);
    }
    return std::make_tuple(1,-1,-1);
}

QString numbers_analize::get_error(int &type,int &len_fr, int &len_sc){
    QString error = "";
    if (type == 0) error = "Десятки принадлежат к исключениям [10;19], а поэтому после них не может быть единиц!!!";
    if (len_fr < len_sc){
        if (len_fr == 1){
            if (len_sc == 2) error = "Единицы не могут стоять перед десятками!!!";
            else error = "Единицы не могут стоять перед сотнями!!!";
        }
        else error = "Десятки не могут стоять перед сотнями!!!";
    }
    else{
        if (len_fr == 1) error = "Единицы не могут стоять рядом с единицами!!!";
        else if (len_fr == 2) error = "Десятки не могут стоять рядом с десятками!!!";
        else if (len_fr == 3) error = "Сотни не могут стоять рядом с сотнями!!!";
    }
    return error;
}

#include "words_analize.h"

words_analize::words_analize(){
    number_for_str["один"] = 1,number_for_str["два"] = 2,number_for_str["три"] = 3;
    number_for_str["четыре"] = 4,number_for_str["пять"] = 5,number_for_str["шесть"] = 6;
    number_for_str["семь"] = 7,number_for_str["восемь"] = 8,number_for_str["девять"] = 9;
    number_for_str["десять"] = 10,number_for_str["одиннадцать"] = 11,number_for_str["двенадцать"] = 12;
    number_for_str["тринадцать"] = 13,number_for_str["четырнадцать"] = 14,number_for_str["пятнадцать"] = 15;
    number_for_str["шестнадцать"] = 16,number_for_str["семнадцать"] = 17,number_for_str["восемнадцать"] = 18;
    number_for_str["девятнадцать"] = 19,number_for_str["двадцать"] = 20,number_for_str["тридцать"] = 30;
    number_for_str["сорок"] = 40,number_for_str["пятьдесят"] = 50,number_for_str["шестьдесят"] = 60;
    number_for_str["семьдесят"] = 70,number_for_str["восемьдесят"] = 80,number_for_str["девяносто"] = 90;
    number_for_str["сто"] = 100,number_for_str["двести"] = 200,number_for_str["триста"] = 300;
    number_for_str["четыреста"] = 400,number_for_str["пятьсот"] = 500,number_for_str["шестьсот"] = 600;
    number_for_str["семьсот"] = 700,number_for_str["восемьсот"] = 800,number_for_str["девятьсот"] = 900;
}

QString words_analize::is_correct(QVector<QString> &words){
    for (auto& word : words){
        if (number_for_str.find(word) == number_for_str.end()) return word;
    }
    return "";
}

QVector<int> words_analize::cast_in_number(QVector<QString> &words){
    QVector <int> numbers;
    for (auto& word : words){
        numbers.push_back(number_for_str[word]);
    }
    return numbers;
}

#ifndef NUMBERS_ANALIZE_H
#define NUMBERS_ANALIZE_H
#include <QVector>
#include <QDebug>

class numbers_analize
{
public:
    numbers_analize();
    std::tuple <int,int,int> is_correct(QVector <int> &numbers);
    QString get_error(int &type,int &len_fr,int &len_sc);
};

#endif // NUMBERS_ANALIZE_H

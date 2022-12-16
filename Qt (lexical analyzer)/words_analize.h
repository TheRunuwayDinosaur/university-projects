#ifndef WORDS_ANALIZE_H
#define WORDS_ANALIZE_H
#include <QString>
#include <QMap>
#include <QVector>
class words_analize
{
public:
    words_analize();
    QString is_correct(QVector <QString> &words);
    QVector <int> cast_in_number(QVector <QString> &words);
private:
    QMap <QString,int> number_for_str;
};

#endif // WORDS_ANALIZE_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Главное окно");
}

MainWindow::~MainWindow(){
    delete ui;
    delete first_step;
    delete second_step;
    delete third_step;
}


void MainWindow::on_analize_clicked(){
    ui->resut_le->setText("");
    QString text = ui->textEdit->toPlainText();
    if (text.size() == 0){
        QMessageBox::critical(this,"Статус","Поле ввода пустое!!!");
    }
    else{
        QVector <QString> words;
        QString cur_word = "";
        text.push_back(' ');
        for (auto& ch : text){
            if (ch == ' '){
                if (cur_word.size() > 0) words.push_back(cur_word);
                cur_word = "";
            }
            else cur_word += ch;
        }
        first_step = new words_analize();
        QString correct = first_step->is_correct(words);
        if (correct > "") QMessageBox::critical(this,"Статус",QString("Слово '%1', не является корректным числом").arg(correct));
        else{
            QVector <int> numbers = first_step->cast_in_number(words);
            second_step = new numbers_analize();
            int type = std::get<0>(second_step->is_correct(numbers));
            int len_fr = std::get<1>(second_step->is_correct(numbers));
            int len_sc = std::get<2>(second_step->is_correct(numbers));
            if (type == -1 || type == 0){
                QString error = second_step->get_error(type,len_fr,len_sc);
                QMessageBox::critical(this,"Статус",error);
            }
            else{
                //QMessageBox::information(this,"Статус","Успешно!");
                third_step = new work_with_numbers();
                ui->resut_le->setText(third_step->cast_in_str(numbers));
            }
        }
    }
}

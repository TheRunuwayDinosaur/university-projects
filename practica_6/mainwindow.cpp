#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter *painter = new QPainter(this);
    painter->setPen(QPen(Qt::red,5,Qt::SolidLine));
    QPointF center(ui->centralwidget->width() / 2 - 100,ui->centralwidget->height() / 2 - 200);
    QRectF root(center,QSize(200,100));
    QPointF text_root(ui->centralwidget->width() / 2 - 12,ui->centralwidget->height() / 2 - 150);
    QLineF the_left_line_from_the_root(QPointF(300,135),QPointF(100,135));
    QLineF the_right_line_from_the_root(QPointF(500,135),QPointF(700,135));
    QLineF the_left_down_from_the_root(QPoint(100,135),QPointF(100,175));
    QLineF the_right_down_from_the_root(QPoint(700,135),QPointF(700,175));
    QLineF the_upper_left_line_is_a_hexagon(QPointF(75,175),QPointF(125,175));
    QLineF the_upper_right_line_is_a_hexagon(QPointF(725,175),QPointF(675,175));
    QLineF diagonal_left_line(QPointF(75,175),QPointF(60,200));
    QLineF diagonal_right_line(QPointF(125,175),QPointF(140,200));
    QLineF diagonal_down_left_line(QPointF(60,200),QPointF(75,225));
    QLineF diagonal_down_right_line(QPoint(140,200),QPoint(125,225));
    QLineF the_down_left_hexagon(QPointF(75,225),QPointF(125,225));
    QLineF diagonal_right_left_line(QPointF(675,175),QPointF(660,200));
    QLineF diagonal_right_right_line(QPointF(725,175),QPointF(740,200));
    QLineF diagonal_down_right_left_line(QPointF(660,200),QPointF(675,225));
    QLineF diagonal_down_right_rught_line(QPointF(740,200),QPointF(725,225));
    QLineF the_down_right_hexagon(QPointF(725,225),QPointF(675,225));
    QLineF right_right_from_hexagon(QPointF(740,200),QPointF(760,200));
    QLineF right_left_from_hexagon(QPointF(660,200),QPointF(640,200));
    QLineF left_right_from_hexagon(QPointF(140,200),QPointF(160,200));
    QLineF left_left_from_hexagon(QPointF(60,200),QPointF(40,200));
    QLineF left_down_left_from_hexagon(QPointF(40,200),QPointF(40,300));
    QLineF left_down_right_from_hexagon(QPointF(160,200),QPointF(160,300));
    QLineF right_down_left_from_hexagon(QPointF(640,200),QPointF(640,300));
    QLineF right_down_right_from_hexagon(QPointF(760,200),QPointF(760,300));
    painter->drawText(QPointF(93,200),"1.2");
    painter->drawText(QPointF(693,200),"1.3");
    painter->drawRect(root);
    painter->drawText(text_root,"Root");
    painter->drawLine(the_left_line_from_the_root);
    painter->drawLine(the_right_line_from_the_root);
    painter->drawLine(the_left_down_from_the_root);
    painter->drawLine(the_right_down_from_the_root);
    painter->drawLine(the_upper_right_line_is_a_hexagon);
    painter->drawLine(the_upper_left_line_is_a_hexagon);
    painter->drawLine(diagonal_left_line);
    painter->drawLine(diagonal_right_line);
    painter->drawLine(diagonal_down_left_line);
    painter->drawLine(diagonal_down_right_line);
    painter->drawLine(the_down_left_hexagon);
    painter->drawLine(diagonal_right_left_line);
    painter->drawLine(diagonal_right_right_line);
    painter->drawLine(diagonal_down_right_left_line);
    painter->drawLine(diagonal_down_right_rught_line);
    painter->drawLine(the_down_right_hexagon);
    painter->drawLine(right_right_from_hexagon);
    painter->drawLine(right_left_from_hexagon);
    painter->drawLine(left_right_from_hexagon);
    painter->drawLine(left_left_from_hexagon);
    painter->drawLine(left_down_left_from_hexagon);
    painter->drawLine(left_down_right_from_hexagon);
    painter->drawLine(right_down_right_from_hexagon);
    painter->drawLine(right_down_left_from_hexagon);
    painter->drawEllipse(617,300,50,50);
    painter->drawEllipse(737,300,50,50);
    painter->drawEllipse(17,300,50,50);
    painter->drawEllipse(137,300,50,50);
    painter->drawText(QPointF(27,325),"1.2.1");
    painter->drawText(QPointF(147,325),"1.2.2");
    painter->drawText(QPointF(747,325),"1.3.2");
    painter->drawText(QPointF(627,325),"1.3.1");
    painter->drawText(QPointF(35,35),"Студент: Скаев С.А.");
    painter->drawText(QPointF(35,55),"Группа: БИСО-04-20");
    painter->drawText(QPointF(35,75),"Рисунок выполнен средствами QPainter");
}



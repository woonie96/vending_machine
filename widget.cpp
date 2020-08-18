#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbmilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::change(){
    int change_value = 0;
    for (int i=0 ; i<4; i++) {
        if (money >= input[i]){
        change_value = money / input[i];
        change_coin[i] = change_value;
        money -= input[i]*change_value;
        }
    }
}

void Widget::changeMoney(int diff){
    int check=0;
    money+=diff;
    for (check; check<3; check++)
    {
        if (money < price[check])
            break;
    }
    if (check == 0) {
        ui->pbcoffee->setEnabled(false);
        ui->pbtea->setEnabled(false);
        ui->pbmilk->setEnabled(false);
    }
    if (check == 1) {
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(false);
        ui->pbmilk->setEnabled(false);
    }
    if (check == 2) {
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbmilk->setEnabled(false);
    }
    if (check >2){

         ui->pbcoffee->setEnabled(true);
         ui->pbtea->setEnabled(true);
         ui->pbmilk->setEnabled(true);

    }
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
   changeMoney(50);
}

void Widget::on_pb100_clicked()
{
   changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbmilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreset_clicked()
{
    change();
    QMessageBox m;
    m.information(nullptr,"Hello", QString("Change is 500: %1, 100: %2, 50: %3, 10: %4").arg(change_coin[0]).arg(change_coin[1]).arg(change_coin[2]).arg(change_coin[3]));
    money=0;
    ui->lcdNumber->display(money);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbmilk->setEnabled(false);
}

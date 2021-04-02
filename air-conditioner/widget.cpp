#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("便携式小空调");
    this->setFixedSize(1144,569);
    open_sound = new QSound(":/image/ac-work.wav",this);
    button_sound = new QSound(":/image/di.wav",this);
    ui->label_stat->hide();
    ui->label_temp->hide();
    ui->label_temp_2->hide();
    ui->frame->setStyleSheet("background-color: rgb(255, 255, 255);");
    m_open = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::palySound_open_play()
{
   open_sound->play();
}

void Widget::palySound_button_play()
{
    button_sound->play();
}

void Widget::palySound_open_stop()
{
    open_sound->stop();
}

void Widget::palySound_button_stop()
{
    button_sound->stop();
}

void Widget::on_pushButton_up_clicked()  //up
{

    if(!m_open) return ;
    palySound_button_play();
    int temp = ui->label_temp->text().toInt();
    if(temp>=31)
        return;
    else
        temp++;

    ui->label_temp->setText(QString::number(temp));
}

void Widget::on_pushButton_down_clicked()
{

    if(!m_open) return ;
    palySound_button_play();
    int temp = ui->label_temp->text().toInt();
    if(temp<=18)
        return;
    else
        temp--;
    ui->label_temp->setText(QString::number(temp));
}

void Widget::on_pushButton_light_clicked()
{
    if(!m_open) return ;
    palySound_button_play();
    QPixmap pix;
    pix.load(":/image/stat_light.png");
    ui->label_stat->setPixmap(pix);
}

void Widget::on_pushButton_clod_clicked()
{
    if(!m_open) return ;
    palySound_button_play();
    QPixmap pix;
    pix.load(":/image/stat_clod.png");
    ui->label_stat->setPixmap(pix);
}

void Widget::on_pushButton_close_clicked(bool checked)
{

    if(checked)
    {
        palySound_button_play();
        palySound_open_play();
        m_open = true;
        ui->label_stat->show();
        ui->label_temp->show();
        ui->label_temp_2->show();
        ui->frame->setStyleSheet("border-image: url(:/image/wind.png);");
    }else
    {
        palySound_button_play();
        palySound_open_stop();
        m_open = false;
        ui->label_stat->hide();
        ui->label_temp->hide();
        ui->label_temp_2->hide();
        ui->frame->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
}




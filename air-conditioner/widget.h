#ifndef WIDGET_H
#define WIDGET_H
#include <QUrl>
#include <QWidget>
#include <QPaintEvent>
#include <QMediaPlayer>
#include <QSound>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void palySound_open_play();
    void palySound_button_play();
    void palySound_open_stop();
    void palySound_button_stop();


private slots:
    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_light_clicked();

    void on_pushButton_clod_clicked();

    void on_pushButton_close_clicked(bool checked);
private:
    QSound *open_sound;
QSound *button_sound;
    bool  m_open;
    Ui::Widget *ui;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
    static constexpr uint8_t NUM_CLIP = 10;

    QVBoxLayout* layoutClip;
    QLabel* labelClip[NUM_CLIP];

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

#include "const.h"

class Widget : public QDialog
{
Q_OBJECT
    QVBoxLayout* layoutClip;
    QLabel* labelClip[NUM_CLIP];
    QString strClip[NUM_CLIP];

private slots:
    void slotNewClip();

public:
    Widget(QDialog *parent = 0);
    ~Widget();
    void createLabel(uint8_t idx, QString str);
};

#endif // WIDGET_H

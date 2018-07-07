#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QKeyEvent>

#include "const.h"

class Widget : public QDialog
{
Q_OBJECT
    QVBoxLayout* layoutClip;
    QLabel* labelClip[NUM_CLIPS];
    QString strClip[NUM_CLIPS];
    uint8_t idxSelectedClip;

private slots:
    void slotNewClip();

public:
    Widget(QDialog *parent = 0);
    ~Widget();
    void updateLabel(uint8_t idx, QString str);
    void keyPressEvent(QKeyEvent* event);
    void focusInEvent(QFocusEvent* event);
    void updateSelectedClip();
};

#endif // WIDGET_H

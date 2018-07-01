#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    /* setting the geometry for the main window */
    QRect rect = QApplication::desktop()->screenGeometry();
    this->setGeometry(rect.width() - 300, rect.height() - 400, 300, 400);

    /* creating placeholders for clips */
    QFrame* line;
    layoutClip = new QVBoxLayout(this);
    for( uint8_t i=0; i<NUM_CLIP; i++) {
        labelClip[i] = new QLabel("label0");
        layoutClip->addWidget(labelClip[i]);

        line = new QFrame;
        line->setFrameStyle(QFrame::HLine | QFrame::Sunken);
        layoutClip->addWidget(line);
    }
}

Widget::~Widget() {
}

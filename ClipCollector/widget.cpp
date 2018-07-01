#include "widget.h"

#include <QClipboard>
#include <QDebug>

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

    QObject::connect( QApplication::clipboard(), SIGNAL(dataChanged()), this, SLOT(handleNewClip()) );
}

Widget::~Widget() {
}

void Widget::handleNewClip() {
    qDebug() << "New clip: " << QApplication::clipboard()->text();

    for( uint8_t i=NUM_CLIP-1; i!=0; i--) {
        labelClip[i]->setText(labelClip[i-1]->text());
    }
    labelClip[0]->setText(QApplication::clipboard()->text());
}

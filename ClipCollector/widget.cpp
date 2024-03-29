#include "widget.h"
#include "const.h"

#include <QClipboard>
#include <QDebug>
#include <QPalette>

Widget::Widget(QWidget *parent) : QWidget(parent), idxSelectedClip(0) {
    /* some defaults */
    this->setFocusPolicy(Qt::StrongFocus);

    /* creating placeholders for clips */
    QFrame* line;
    layoutClip = new QVBoxLayout(this);
    for( uint8_t i=0; i<NUM_CLIPS; i++) {
        labelClip[i] = new QLabel();
        layoutClip->addWidget(labelClip[i]);
        line = new QFrame;
        line->setFrameStyle(QFrame::HLine | QFrame::Sunken);
        layoutClip->addWidget(line);
    }

    /* setting the geometry for the main window */
    QRect screen = QApplication::desktop()->screenGeometry();
    uint16_t heightTaskbar = screen.height() - QApplication::desktop()->availableGeometry().height();
    uint16_t heightWindow = (labelClip[0]->sizeHint().height() + line->sizeHint().height() + HEIGHT_PADDING) * NUM_CLIPS;
    this->setGeometry(screen.width() - WIDTH_WINDOW,
                      screen.height() - heightWindow - heightTaskbar,
                      WIDTH_WINDOW,
                      heightWindow);
    this->setFixedSize(WIDTH_WINDOW, heightWindow);

    /* create the first clip */
    updateLabel(0, QApplication::clipboard()->text());

    /* Listen to any clipboard event */
    QObject::connect( QApplication::clipboard(), SIGNAL(dataChanged()), this, SLOT(slotNewClip()) );
}

Widget::~Widget() {
}

void Widget::slotNewClip() {
    qDebug() << "New Clip: " << QApplication::clipboard()->text();
    pushLabel(QApplication::clipboard()->text());
}

void Widget::pushLabel(QString str) {
    /* push down each label */
    for( uint8_t i=NUM_CLIPS-1; i>0; i--) {
        updateLabel(i, strClip[i-1]);
    }

    /* set the topmost label with clipboard content */
    updateLabel(0, str);
}

void Widget::updateLabel(uint8_t idx, QString str) {
    /* set the clip as string */
    strClip[idx] = str;

    /* trim the string to fit display */
    if(str.length() > LENGTH_CLIP)
        str.resize(LENGTH_CLIP);
    if( str.indexOf('\n') != -1 )
        str.resize(str.indexOf('\n'));
    if(str.length() != strClip[idx].length())
        str.append("...");

    /* display the string */
    labelClip[idx]->setText(str);
}

void Widget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Up:
        if(idxSelectedClip > 0)
            idxSelectedClip--;
        highlightSelectedClip();
        break;

    case Qt::Key_Down:
        if(idxSelectedClip < NUM_CLIPS-1)
            idxSelectedClip++;
        highlightSelectedClip();
        break;

    case Qt::Key_Enter:
    case Qt::Key_Return:
        pushLabel(strClip[idxSelectedClip]);
        idxSelectedClip = 0;
        highlightSelectedClip();
        QApplication::clipboard()->setText(strClip[idxSelectedClip]);
        this->setWindowState(Qt::WindowMinimized);
        break;

    case Qt::Key_Escape:
        this->setWindowState(Qt::WindowMinimized);
        break;

    default:
        QWidget::keyPressEvent(event);
    }
}

void Widget::focusInEvent(QFocusEvent* event) {
    highlightSelectedClip();
    QWidget::focusInEvent(event);
}

void Widget::highlightSelectedClip() {
    labelClip[idxSelectedClip]->setStyleSheet( "QLabel { color: blue }" );
    for( uint8_t i=0; i<NUM_CLIPS; i++) {
        if(i==idxSelectedClip)
            labelClip[i]->setStyleSheet( "QLabel { color: blue }" );
        else
            labelClip[i]->setStyleSheet( "QLabel { color: black }" );
    }
}

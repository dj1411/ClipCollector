#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
    labelClip[0] = new QLabel("label1");
    labelClip[1] = new QLabel("label2");
//    for(unsigned char i; i<MAX_CLIPS; i++) {
//        labelClip[i] = new QLabel("label", this);
//    }

    layoutLabel = new QVBoxLayout();
    layoutLabel->addWidget(labelClip[0]);
    layoutLabel->addWidget(labelClip[1]);
    this->setLayout(layoutLabel);
}

MainWindow::~MainWindow() {
}

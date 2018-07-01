#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    static constexpr unsigned char MAX_CLIPS = 10;

    QLabel* labelClip[MAX_CLIPS];
    QVBoxLayout* layoutLabel;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H

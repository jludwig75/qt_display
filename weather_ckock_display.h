#pragma once

#include <QFrame>
#include <QGuiApplication>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QScreen>
#include <QVBoxLayout>


class MyDisplay : public QWidget {
    Q_OBJECT
public:
    MyDisplay();
    virtual ~MyDisplay(){}
    void show();
private slots:
    void onBackButtonClicked();
    void onForwardButtonClicked();
private:
    void draw();
    QWidget mainWindow;
    QVBoxLayout mainLayout;
    QLabel pixelDrawingArea;
    QFrame buttonFrame;
    QPushButton backwardButton;
    QPushButton forwardButton;
    QHBoxLayout buttonLayout;
};

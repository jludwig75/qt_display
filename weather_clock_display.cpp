#include "weather_ckock_display.h"


MyDisplay::MyDisplay() :
    mainWindow(),
    mainLayout(&mainWindow),
    pixelDrawingArea(),
    buttonFrame(),
    backwardButton("<<"),
    forwardButton(">>"),
    buttonLayout(&buttonFrame) {
}

void MyDisplay::show() {
    mainWindow.setWindowTitle("Weather Clock");

    // Create a label for the pixel drawing area
    pixelDrawingArea.setFixedSize(300, 400);
    pixelDrawingArea.setAutoFillBackground(true);
    pixelDrawingArea.setStyleSheet("background-color: white; border: 1px solid black;");

    // Create a frame to contain forward and backward buttons
    buttonFrame.setFrameStyle(QFrame::Box);

    connect(&backwardButton, &QPushButton::clicked, this, &MyDisplay::onBackButtonClicked);
    connect(&forwardButton, &QPushButton::clicked, this, &MyDisplay::onForwardButtonClicked);

    // Create a layout for the buttons
    buttonLayout.addWidget(&backwardButton);
    buttonLayout.addWidget(&forwardButton);

    // Add the pixel drawing area and button frame to the main layout
    mainLayout.addWidget(&pixelDrawingArea);
    mainLayout.addWidget(&buttonFrame);

    // Center the window on the screen
    int windowWidth = 300;
    int windowHeight = 400;
    auto screenGeometery = QGuiApplication::primaryScreen()->geometry();
    mainWindow.setGeometry(
        screenGeometery.width() / 2 - windowWidth / 2,
        screenGeometery.height() / 2 - windowHeight / 2,
        windowWidth,
        windowHeight
    );

    draw();

    // Show the main window
    mainWindow.show();
}

void MyDisplay::onBackButtonClicked() {
    // Code to execute when the button is clicked
    qDebug("Back Button Clicked");
}

void MyDisplay::onForwardButtonClicked() {
    // Code to execute when the button is clicked
    qDebug("Forward Button Clicked");
}

void MyDisplay::draw() {
    QPixmap pixMap(300, 400);
    pixMap.fill(Qt::white);

    QPainter painter(&pixMap);
    painter.setPen(Qt::black);
    painter.drawLine(29, 39, 269, 359);
    painter.drawLine(29, 359, 269, 39);
    painter.drawLine(29, 39, 269, 39);
    painter.drawLine(269, 359, 269, 39);
    painter.drawLine(29, 359, 269, 359);
    painter.drawLine(29, 359, 29, 39);
    painter.end();

    pixelDrawingArea.setPixmap(pixMap);
}

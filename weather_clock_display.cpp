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
    QPixmap pixmap(300, 400);
    
    QPainter painter(&pixmap);

    auto mid_x = pixmap.width() / 2;
    auto mid_y = pixmap.height() - 100;

    // Set background color
    painter.fillRect(0, 0, pixmap.width(), pixmap.height(), Qt::white);

    // Draw a stem
    painter.setPen(QPen(Qt::darkGreen, 5));
    painter.drawLine(mid_x, pixmap.height(), mid_x, mid_y);

    // Draw petals
    painter.setPen(QPen(Qt::red, 3));
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(mid_x - 41, mid_y - 41, 40, 40);
    painter.drawEllipse(mid_x + 1, mid_y - 41, 40, 40);
    painter.drawEllipse(mid_x - 41, mid_y + 1, 40, 40);
    painter.drawEllipse(mid_x + 1, mid_y + 1, 40, 40);

    // Draw a center
    painter.setPen(QPen(Qt::yellow, 5));
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(mid_x - 10, mid_y - 10, 20, 20);

    painter.end();

    pixelDrawingArea.setPixmap(pixmap);
}

#include <QApplication>

#include "weather_ckock_display.h"


int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    MyDisplay display;
    display.show();

    return app.exec();
}

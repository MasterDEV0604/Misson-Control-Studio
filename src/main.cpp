#include <QApplication>
#include <QFile>
#include "ui/MainWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QFile themeFile("assets/styles/dark_ops.qss");
    if (themeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        app.setStyleSheet(QString::fromUtf8(themeFile.readAll()));
    }

    missionx::MainWindow window;
    window.resize(1720, 980);
    window.show();
    return app.exec();
}

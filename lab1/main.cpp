#include <QApplication>
#include "model.h"
#include "controller.h"
#include "view.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Model model;
    MainWindow mainWindow;
    InputDialog inputDialog(&mainWindow);
    Controller controller(&model, &mainWindow, &inputDialog);

    QObject::connect(&mainWindow, &MainWindow::openInputDialog,
                     &controller, &Controller::onOpenInputDialog);
    QObject::connect(&inputDialog, &InputDialog::dataSubmitted,
                     &controller, &Controller::onSubmitData);

    mainWindow.show();
    return app.exec();
}

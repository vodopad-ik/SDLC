#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"

class MainWindow;
class InputDialog;

class Controller : public QObject {
    Q_OBJECT

public:
    Controller(Model *model, MainWindow *mainWindow, InputDialog *inputDialog, QObject *parent = nullptr);

public slots:
    void onOpenInputDialog();
    void onSubmitData(double weight, bool isLbs);

private:
    Model *m_model;
    MainWindow *m_mainWindow;
    InputDialog *m_inputDialog;
};

#endif // CONTROLLER_H

#include "controller.h"
#include "model.h"
#include "view.h"
#include <QMessageBox>

Controller::Controller(Model *model, MainWindow *mainWindow, InputDialog *inputDialog, QObject *parent)
    : QObject(parent), m_model(model), m_mainWindow(mainWindow), m_inputDialog(inputDialog) {

    connect(m_model, &Model::dataChanged, this, [this]() {
        QString unitStr = (m_model->unit() == Model::KG) ? "кг" : "фунты";
        m_mainWindow->showResult(m_model->weight(), unitStr, m_model->proteinNorm());
    });

    connect(m_model, &Model::errorOccurred, this, [this](const QString &msg) {
        QMessageBox::warning(m_inputDialog, "Ошибка", msg);
    });
}

void Controller::onOpenInputDialog() {
    if (m_model->weight() > 0) {
        m_inputDialog->setLastValues(m_model->weight(), m_model->unit() == Model::LBS);
    }
    m_inputDialog->open();
}

void Controller::onSubmitData(double weight, bool isLbs) {
    Model::Unit unit = isLbs ? Model::LBS : Model::KG;
    m_model->setWeight(weight, unit);
}

#include "model.h"

Model::Model(QObject *parent) : QObject(parent) {}

double Model::weight() const { return m_weight; }
Model::Unit Model::unit() const { return m_unit; }
double Model::proteinNorm() const { return m_proteinNorm; }
QString Model::lastError() const { return m_lastError; }

void Model::setWeight(double weight, Unit unit) {
    if (weight <= 0) {
        m_lastError = "Вес должен быть положительным числом.";
        emit errorOccurred(m_lastError);
        return;
    }

    m_lastError.clear();
    m_weight = weight;
    m_unit = unit;
    calculate();
    emit dataChanged();
}

void Model::calculate() {
    double weightKg = (m_unit == LBS) ? m_weight * 0.453592 : m_weight;
    m_proteinNorm = weightKg * 1.6;
}

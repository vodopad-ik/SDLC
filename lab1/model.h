#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>

class Model : public QObject {
    Q_OBJECT

public:
    enum Unit { KG, LBS };

    explicit Model(QObject *parent = nullptr);

    double weight() const;
    Unit unit() const;
    double proteinNorm() const;
    QString lastError() const;

    void setWeight(double weight, Unit unit);

signals:
    void dataChanged();
    void errorOccurred(const QString &message);

private:
    void calculate();

    double m_weight = 0.0;
    Unit m_unit = KG;
    double m_proteinNorm = 0.0;
    QString m_lastError;
};

#endif // MODEL_H

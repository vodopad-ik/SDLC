#include "view.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Калькулятор суточной нормы протеина");
    resize(400, 250);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QLabel *title = new QLabel("Суточная норма протеина", this);
    title->setStyleSheet("font-size: 16px; font-weight: bold;");
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    m_weightLabel = new QLabel("Вес: не введён", this);
    m_normLabel = new QLabel("Норма протеина: —", this);

    QGroupBox *resultBox = new QGroupBox("Результат", this);
    QVBoxLayout *resultLayout = new QVBoxLayout(resultBox);
    resultLayout->addWidget(m_weightLabel);
    resultLayout->addWidget(m_normLabel);

    m_resultLabel = new QLabel("Нажмите «Ввести данные» для расчёта.", this);
    m_resultLabel->setAlignment(Qt::AlignCenter);
    resultLayout->addWidget(m_resultLabel);

    mainLayout->addWidget(resultBox);

    QPushButton *btnInput = new QPushButton("Ввести данные", this);
    connect(btnInput, &QPushButton::clicked, this, &MainWindow::openInputDialog);
    mainLayout->addWidget(btnInput);

    mainLayout->addStretch();
}

void MainWindow::showResult(double weight, const QString &unitStr, double proteinNorm) {
    m_weightLabel->setText(QString("Вес: %1 %2").arg(weight, 0, 'f', 2).arg(unitStr));
    m_normLabel->setText(QString("Суточная норма протеина: %1 г").arg(proteinNorm, 0, 'f', 1));
    m_resultLabel->setText("Расчёт завершён.");
}

InputDialog::InputDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Ввод данных");
    resize(300, 180);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Введите вес:", this));
    m_weightEdit = new QLineEdit(this);
    m_weightEdit->setPlaceholderText("Например, 75");
    layout->addWidget(m_weightEdit);

    layout->addWidget(new QLabel("Единица измерения:", this));
    m_unitCombo = new QComboBox(this);
    m_unitCombo->addItem("Килограммы (кг)", false);
    m_unitCombo->addItem("Фунты (lbs)", true);
    layout->addWidget(m_unitCombo);

    QPushButton *btnSubmit = new QPushButton("Рассчитать", this);
    connect(btnSubmit, &QPushButton::clicked, this, &InputDialog::onSubmit);
    layout->addWidget(btnSubmit);

    layout->addStretch();
}

void InputDialog::setLastValues(double weight, bool isLbs) {
    m_weightEdit->setText(QString::number(weight, 'f', 2));
    m_unitCombo->setCurrentIndex(isLbs ? 1 : 0);
}

void InputDialog::onSubmit() {
    bool ok;
    double weight = m_weightEdit->text().toDouble(&ok);
    if (!ok || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите корректное положительное число.");
        return;
    }

    bool isLbs = m_unitCombo->currentData().toBool();
    emit dataSubmitted(weight, isLbs);
    accept();
}

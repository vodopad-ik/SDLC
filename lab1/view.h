#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void showResult(double weight, const QString &unitStr, double proteinNorm);

signals:
    void openInputDialog();

private:
    QLabel *m_resultLabel;
    QLabel *m_weightLabel;
    QLabel *m_normLabel;
};

class InputDialog : public QDialog {
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    void setLastValues(double weight, bool isLbs);

signals:
    void dataSubmitted(double weight, bool isLbs);

private slots:
    void onSubmit();

private:
    QLineEdit *m_weightEdit;
    QComboBox *m_unitCombo;
};

#endif // VIEW_H

#ifndef DEMODIALOG_H
#define DEMODIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>

class DemoDialog : public QDialog {
    Q_OBJECT

public:
    DemoDialog( QWidget* parent = nullptr );
    ~DemoDialog();

    void setTablesName(QStringList tables);
    QString getInput() const;

signals:
    void applied();

private:
    QComboBox* m_tables;
    QLineEdit* m_edit;
};

#endif // DEMODIALOG_H

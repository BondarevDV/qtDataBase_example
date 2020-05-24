#ifndef DEMODIALOG_H
#define DEMODIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QDebug>

class DemoDialog : public QDialog {
    Q_OBJECT

public:
    DemoDialog( QWidget* parent = nullptr );
    ~DemoDialog();

    void setTablesName(QStringList tables);
    QString getInput() const;

signals:
    void applied();
    void chooseTable(QString tableName);

public slots:
    void accept_data();


private:
    QComboBox* m_tables;
    QLineEdit* m_edit;
};

#endif // DEMODIALOG_H

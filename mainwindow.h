#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql/QtSql>
#include <database.h>
#include "tablemodelsql.h"
#include "demodialog.h"
#include "qcustomplot.h"
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotRangeChanged(const QCPRange &newRange);
    void on_ActionOpenDB_triggered();

    void on_ActionReload_triggered();
    void setupModel(const QString tableName);

    void on_ActionLineChart_triggered();

    void on_ActionBuildBarChart_triggered();

private:
    Ui::MainWindow *ui;
    /*
     * диалоговое окно для выбора таблиц
    */
    DemoDialog* dlg;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
     * и моделью представления таблицы базы данных
     * */
    CDataBase        *db;
    DataTableModel  *model;
    QCPGraph *graphic;          // Объявляем график
    QCPBarsGroup *group;
    QCPBars *fossil;
private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */

    void createUI();
    void initChart();
};
#endif // MAINWINDOW_H

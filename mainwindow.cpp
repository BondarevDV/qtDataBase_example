#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Первым делом необходимо создать объект, который будет использоваться для работы с данными нашей БД
     * и инициализировать подключение к базе данных
     * */
    db = new CDataBase();
    db->connectToDataBase();


    this->setupModel(TABLE,
                     QStringList() << "time"
                                   << "value"
                                   << "Number"
               );
    this->createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);
    //model->select();

    //auto time = model->record(4).value("Time").toInt();
    //auto data = model->data();
    //auto size = model->rowCount();
    //model->setEditStrategy(QSqlTableModel::OnFieldChange);

    //qDebug()<< time;
    //qDebug()<< size;

    //qDebug()<< data;
    auto record = model->record(0);
    //qDebug()<< QDateTime::fromTime_t(record.value("time").toInt())<<":"<<record.value("value").toInt()<<":"<<record.value("Number").toInt();
    QString fmt = "dd-MM-yyyy hh:mm:ss";
    uint time_stamp = record.value("time").toUInt();

    qDebug() << QDateTime::fromTime_t(time_stamp).toString(fmt);

}

void MainWindow::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    //ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select(); // Делаем выборку данных из таблицы
}


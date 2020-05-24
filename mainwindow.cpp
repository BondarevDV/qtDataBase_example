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

    dlg = new DemoDialog(this);
    dlg->setTablesName(db->tables());
    connect(dlg, SIGNAL(chooseTable(QString)), this, SLOT(setupModel(QString)));


//    this->setupModel(TABLE);
//    this->createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel(const QString tableName )
{
    qDebug()<< "setup model" ;
    QStringList headers;
    headers = QStringList() << "time"
                            << "value"
                            << "Number";
    model = new DataTableModel(this);
    model->setTable(tableName);
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);

    this->createUI();
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


void MainWindow::on_ActionOpenDB_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                QString::fromUtf8("Выберите один, или более файлов"),
                                QDir::currentPath(),
                                "Images (*.png *.xpm *.jpg);;All files (*.*)");
}

void MainWindow::on_ActionReload_triggered()
{
    dlg->show();
}

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
    while (model->canFetchMore())
    {
        model->fetchMore();
    }

}

void MainWindow::initChart()
{
    ui->customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
    ui->customPlot->xAxis->setDateTimeFormat("dd-MM-yyyy hh:mm:ss");  // Устанавливаем формат даты и времени

    // Настраиваем шрифт по осям координат
    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

    // Автоматическое масштабирование тиков по Оси X
    ui->customPlot->xAxis->setAutoTickStep(true);

    /* Делаем видимыми оси X и Y по верхней и правой границам графика,
     * но отключаем на них тики и подписи координат
     * */
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTicks(false);
    ui->customPlot->yAxis2->setTicks(false);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setTickLabels(false);

    ui->customPlot->yAxis->setTickLabelColor(QColor(Qt::red)); // Красный цвет подписей тиков по Оси Y
    ui->customPlot->legend->setVisible(true);   //Включаем Легенду графика
    // Устанавливаем Легенду в левый верхний угол графика
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    // Инициализируем график и привязываем его к Осям
    graphic = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(graphic);  // Устанавливаем график на полотно
    graphic->setPen(QPen(QColor(Qt::red))); // Устанавливаем цвет графика
    graphic->setAntialiased(false);         // Отключаем сглаживание, по умолчанию включено
    graphic->setLineStyle(QCPGraph::lsLine); // График в виде импульсных тиков

    /* Подключаем сигнал от Оси X об изменении видимого диапазона координат
     * к СЛОТу для переустановки формата времени оси.
     * */
    qDebug()<<"row count = "<<model->rowCount();
    // Объявляем вектора времени и доходов
    QVector<double> x(model->rowCount());
    QVector<double> y(model->rowCount()); // initialize with entries 0..100

    auto getQDateTime = [] (QString time) {
        return QDateTime::fromString(time, "dd-MM-yyyy hh:mm:ss").toTime_t();
    };

    for (int i=0; i < model->rowCount(); ++i)
    {

      y[i] = model->record(i).value("value").toDouble(); // x goes from -1 to 1
      x[i] = getQDateTime(model->record(i).value("time").toString()); // let's plot a quadratic function
    }

    graphic->setData(x, y);              // Устанавливаем данные
    ui->customPlot->rescaleAxes();       // Масштабируем график по данным
    ui->customPlot->replot();            // Отрисовываем график

}


void MainWindow::slotRangeChanged(const QCPRange &newRange)
{
    /* Если область видимости графика меньше одного дня,
     * то отображаем часы и минуты по Оси X,
     * в противном случае отображаем дату "День Месяц Год"
     * */
    //ui->customPlot->xAxis->setDateTimeFormat((newRange.size() <= 86400)? "hh:mm" : "dd MMM yy");
}

void MainWindow::on_ActionOpenDB_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                QString::fromUtf8("Выберите один, или более файлов"),
                                QDir::currentPath(),
                                "Data Base (*.db );;All files (*.*)");
}

void MainWindow::on_ActionReload_triggered()
{
    dlg->show();
}

void MainWindow::on_ActionLineChart_triggered()
{
    initChart();
}

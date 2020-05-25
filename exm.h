#ifndef EXM_H
#define EXM_H
//ui->customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
//ui->customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
//ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
//ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
//ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
//ui->customPlot->xAxis->setDateTimeFormat("dd-MM-yyyy hh:mm:ss");  // Устанавливаем формат даты и времени

//qDebug()<<"choosing table: "<<dlg->getInput();
//QSqlQueryModel* modelMain = new QSqlQueryModel(model);
////modelMain->setQuery("SELECT Number FROM data12 GROUP BY Number");

////    modelMain->setQuery(QString("SELECT * FROM %1 WHERE Number == %2").arg(dlg->getInput()).arg(0));

////    qDebug()<<"Number of relatives: "<< modelMain->data(modelMain->index(0, 0)).toString();
////    qDebug()<<"Numbers: "<< modelMain->record(0).value("Number").toInt();
////    qDebug()<<"Numbers: "<< modelMain->lastError();
////    ui->tableView->setModel(modelMain);
////    while (modelMain->canFetchMore()) {
////        modelMain->fetchMore();
////    }
//group = new QCPBarsGroup(ui->customPlot);
//// запрос получить список групп
//modelMain->setQuery(QString("SELECT Number FROM %1 GROUP BY Number").arg(dlg->getInput()));
////qDebug()<<modelMain->rowCount();
////    QVector<double>* datax;
////    QVector<double>* datay;
//QCPBars *bars;
//QVector<double> datax;
//QVector<double> datay;
//QSet<int> groups_number;
//QSqlQueryModel* model_querry_group = new QSqlQueryModel(model); //
//int number; // число для группировки
//for (int i = 0; i < 1; ++i) {
//    number = modelMain->record(i).value("Number").toInt();
//    groups_number.insert(modelMain->record(i).value("Number").toInt());
//    //datax = new QVector<double>();
//    //datay = new QVector<double>();
//    // выборка значение по группе
//    model_querry_group->setQuery(QString("SELECT * FROM %1 WHERE Number == %2").arg(dlg->getInput()).arg(number));
//    qDebug()<<"-----------------------------------"<<model_querry_group->rowCount();
//    for (int j = 0; j < model_querry_group->rowCount(); ++j) {
//        qDebug()<<model_querry_group->record(i).value("time").toInt();
//        qDebug()<<model_querry_group->record(i).value("value").toInt();
//        qDebug()<<model_querry_group->record(i).value("number").toInt();
//        datax.push_back(model_querry_group->record(i).value("time").toInt());
//        datay.push_back(model_querry_group->record(i).value("value").toInt());


//    }
//    bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
//    bars->setData(datax, datay);
//    bars->setBrush(QColor(0, 0, 255, 50));
//    bars->setPen(QColor(0, 0, 255));
//    bars->setWidth(0.15);
//    bars->setBarsGroup(group);
//}
////    group = new QCPBarsGroup(ui->customPlot);
////    QVector<QCPBars*> v_bars(modelMain->rowCount());
////    QCPBars *bars;// = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
////    for (int i = 0; i < modelMain->rowCount(); i++) {
////        bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
////        v_bars.push_back(bars);
////    }
////    qDebug()<<"Size v_bars: "<<v_bars.count();
////ui->tableView->setModel(modelMain);

////QSqlQueryModel model;
//     //model.setQuery("SELECT * FROM employee");
////    model->setQuery();
//ui->customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
//ui->customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
//ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
//ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси

////    QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4;
////    QVector<double> datay1 = QVector<double>() << 0.6 << 0.5 << 0.3 << 0.15;
////    QVector<double> datay2 = QVector<double>() << 0.3 << 0.28 << 0.2 << 0.1;
////    QVector<double> datay3 = QVector<double>() << 0.33 << 0.31 << 0.27 << 0.13;

////    group = new QCPBarsGroup(ui->customPlot);
////    QCPBars *bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
////    bars->setData(datax, datay1);
////    bars->setBrush(QColor(0, 0, 255, 50));
////    bars->setPen(QColor(0, 0, 255));
////    bars->setWidth(0.15);
////    bars->setBarsGroup(group);
////    bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
////    bars->setData(datax, datay2);
////    bars->setBrush(QColor(180, 00, 120, 50));
////    bars->setPen(QColor(180, 00, 120));
////    bars->setWidth(0.15);
////    bars->setBarsGroup(group);
////    bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
////    bars->setData(datax, datay3);
////    bars->setBrush(QColor(255, 154, 0, 50));
////    bars->setPen(QColor(255, 154, 0));
////    bars->setWidth(0.15);
////    bars->setBarsGroup(group);
////    ui->customPlot->xAxis->setRange(0.1, 4.9);
////    ui->customPlot->yAxis->setRange(0, 0.7);
//ui->customPlot->replot();

//// Сброс всех установок графика:
//ui->customPlot->removePlottable(fossil);
#endif // EXM_H

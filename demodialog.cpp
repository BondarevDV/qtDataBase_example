#include "demodialog.h"


DemoDialog::DemoDialog( QWidget* parent ) : QDialog( parent ) {
    QBoxLayout* layout = new QHBoxLayout;
    this->setWindowTitle("Выбрать таблицу для загрузки");
    m_tables = new QComboBox;
    //m_edit = new QLineEdit;
    layout->addWidget( m_tables );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accept_data() ) );
    layout->addWidget( okBtn );

//    QPushButton* applyBtn = new QPushButton( "Apply" );
//    connect( applyBtn, SIGNAL( clicked() ), SIGNAL( applied() ) );
//    layout->addWidget( applyBtn);

    QPushButton* cancelBtn = new QPushButton( "Cancel" );
    connect( cancelBtn, SIGNAL( clicked() ), SLOT( reject() ) );
    layout->addWidget( cancelBtn );

    setLayout( layout );
}

DemoDialog::~DemoDialog() {
}

void DemoDialog::setTablesName(const QStringList tables)
{
    for (int i = 0; i < tables.size(); ++i)
            m_tables->addItem(tables.at(i));

}

QString DemoDialog::getInput() const {
    return m_tables->currentText();
}

void DemoDialog::clear()
{
    m_tables->clear();
}

void DemoDialog::accept_data()
{
    qDebug()<<"accept: "<< getInput();
    emit chooseTable(getInput());
    this->close();
}



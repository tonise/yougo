#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMaximumSize(500,40);
    this->setMinimumSize(500,40);
    this->setStyleSheet("QWidget{border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px; }");

    QObject::connect(ui->cmdLineEdit,SIGNAL(returnPressed()),this,SLOT(on_submitButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_submitButton_clicked()
{
  QProcess *process=new QProcess;
  QString startProgram=ui->cmdLineEdit->text();
  process->start(startProgram.trimmed());
  ui->cmdLineEdit->clear();
  this->close();

}



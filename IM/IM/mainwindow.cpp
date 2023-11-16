#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//////////////////////////////////////////////////////////////////////////////
    ui->IPTableWidget->setFocusPolicy(Qt::NoFocus);
    ui->IPTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->IPTableWidget->setColumnCount(1);
    QStringList Header;
    Header<<"IP地址";
    ui->IPTableWidget->setHorizontalHeaderLabels(Header);
    ui->IPTableWidget->setRowCount(254);
    QList<QHostAddress> IPList=QNetworkInterface().allAddresses();
    QString SIP=IPList.at(10).toString().section('.',0,2);
    for(int i=0;i<254;i++)
    {
        ui->IPTableWidget->setItem(i,0,new QTableWidgetItem(SIP+"."+QString::number(i+1)));
    }
////////////////////////////////////////////////////////////////////////////////////////
    MyUDPSocket=new QUdpSocket(this);
    connect(MyUDPSocket,SIGNAL(readyRead()),this,SLOT(ReadData()));
    MyUDPSocket->bind(QHostAddress::Any,2100);
}

MainWindow::~MainWindow()
{
    MyUDPSocket->abort();
    delete MyUDPSocket;
    delete ui;
}

void MainWindow::on_MessPushButton_clicked()
{
    QByteArray Ba=ui->TxTextEdit->toPlainText().toLocal8Bit();
    if(!Ba.isEmpty())
    {
        int TxCount=MyUDPSocket->writeDatagram(Ba,
                                               QHostAddress(ui->CurrentLabel->text()),
                                               2100);
        if(TxCount != Ba.size())
        {
            QMessageBox::about(NULL,
                              "Send infor",
                              "this data send failed!");
        }
        else
        {
            ui->RxTextEdit->append("你对"+
                                   ui->CurrentLabel->text()+
                                   "说:"+
                                   ui->TxTextEdit->toPlainText());
            ui->TxTextEdit->clear();
        }
    }
}

void MainWindow::on_FilePushButton_clicked()
{

}

void MainWindow::on_IPTableWidget_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem *tableWidgetItem=ui->IPTableWidget->item(index.row(),0);
    QString str=tableWidgetItem->text();
    ui->CurrentLabel->setText(str);
}

void MainWindow::ReadData(void)
{
    QByteArray Ba;
    QHostAddress SIP;
    quint16 SPort;
    while(MyUDPSocket->hasPendingDatagrams())
    {
       Ba.resize(MyUDPSocket->pendingDatagramSize());
       MyUDPSocket->readDatagram(Ba.data(),Ba.size(),&SIP,&SPort);
       if(!Ba.isEmpty())
       {
           ui->RxTextEdit->append(SIP.toString().section(':',-1,-1)+"对你说:"+QString::fromLocal8Bit(Ba));
       }
    }
}

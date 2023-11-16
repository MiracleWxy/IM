#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_MessPushButton_clicked();
    void on_FilePushButton_clicked();
    void on_IPTableWidget_doubleClicked(const QModelIndex &index);

    void ReadData(void);

private:
    Ui::MainWindow *ui;
    QUdpSocket *MyUDPSocket;
};

#endif // MAINWINDOW_H

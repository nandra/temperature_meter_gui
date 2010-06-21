#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ico = new QSystemTrayIcon(this);

    this->meter = new temperature();
    this->timer = new QTimer(this);

    if(this->meter->init() < 0) {
        qDebug() << "No device connected";
        QPixmap pixmap(16,16);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        QString string;
        string = "-°C";
        painter.drawText(0,0,16,16,Qt::AlignHCenter | Qt::AlignVCenter, string);

        ico->setIcon(QIcon(pixmap));
        ico->show();
        return;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(update_temperature()));
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->meter;
}

void MainWindow::update_temperature()
{
    int stat = 0, len;
    unsigned char buff[35];
    memset(buff, 0 , sizeof(buff));
    stat = meter->get_status();

    switch(stat) {

    case 0x80:
         printf("SPI ready (communication mode)\n");
         break;

    default:
         if (stat >= 0x40 && stat <= 0x63) {
             printf("SPI data %x\n", stat);
             len = meter->write_read_spi_data(buff, stat-0x40, 0);
             printf("len = %d\n", len);
             buff[len] = '\0';
             QString str;

             str.append((char *)&buff[0]);
             QPixmap pixmap(25,16);
             pixmap.fill(Qt::transparent);
             QPainter painter(&pixmap);
             QString string;
             string = str;
             painter.drawText(0,0,25,16,Qt::AlignHCenter | Qt::AlignVCenter, string);

             ico->setIcon(QIcon(pixmap));

             ico->show();

             ui->label->setText(str);
         } else {
            printf("Unkown SPI response!\n");
         }
         break;
    }

}

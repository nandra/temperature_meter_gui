#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->meter = new temperature();
    this->timer = new QTimer(this);

    this->meter->init();

    connect(timer, SIGNAL(timeout()), this, SLOT(update_temperature()));
    timer->start(200);
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
             printf("SPI data %d\n", stat);
             len = meter->write_read_spi_data(buff, stat, 0);
              buff[len] = '\0';
              QString str;

              str.append((char *)&buff[0]);

              ui->label->setText(str);
         } else {
            printf("Unkown SPI response!\n");
         }
         break;
    }

}

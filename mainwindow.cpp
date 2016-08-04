#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pCamera = new QCamera;
    m_pImageCap = new QCameraImageCapture(m_pCamera);
    m_pCamera->setViewfinder(new QVideoWidget(ui->label));
    m_pCamera->start();

    connect(m_pImageCap, SIGNAL(imageCaptured(int,QImage)),
            this, SLOT(slot_save_h264(int ,QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_pImageCap->capture();
}

void MainWindow::slot_save_h264(int ,QImage image)
{
    qDebug() << image.format();
    image.toPixelFormat(QImage::Format_RGB888);
    qDebug() << image.format();
    //AVFrame *pframe = avcodec_alloc_frame();
    int w = image.width();
    int h = image.height();


    if (image.save("a.yuv"))
    {
        qDebug() << "save";
    }
    else
        qDebug() << "not save";
}

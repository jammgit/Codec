#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//必须加以下内容,否则编译不能通过,为了兼容C和C99标准
#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif

//引入ffmpeg头文件
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
}
#include <QObject>
#include <QCamera>
#include <QImage>
#include <QWidget>
#include <QPoint>
#include <QCameraImageCaptureControl>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QLabel>

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
    void on_pushButton_clicked();
    void slot_save_h264(int ,QImage);

private:
    Ui::MainWindow *ui;

    QCamera *m_pCamera;
    QCameraImageCapture *m_pImageCap;
};

#endif // MAINWINDOW_H

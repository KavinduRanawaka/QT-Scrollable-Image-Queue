#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create scroll area and layout
    scrollWidget = new QWidget(this);
    layout = new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(layout);

    // Set up scroll area
    ui->scrollArea->setWidget(scrollWidget);
    ui->scrollArea->setWidgetResizable(true);

    // Set image paths (replace with your own images)
    imagePaths << ":/images/1.jpg" << ":/images/2.jpg"
               << ":/images/3.jpg" << ":/images/4.jpg" << ":/images/5.jpg";

    setupImages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupImages()
{
    for (const QString &path : imagePaths) {
        QLabel *imgLabel = new QLabel;
        imgLabel->setPixmap(QPixmap(path).scaled(200, 200, Qt::KeepAspectRatio));
        layout->addWidget(imgLabel);
        imageLabels.append(imgLabel);
    }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();

    if (delta > 0)
        scrollUp();
    else if (delta < 0)
        scrollDown();
}

void MainWindow::scrollUp()
{
    // Take last widget and move it to the top
    QWidget *last = imageLabels.takeLast();
    layout->removeWidget(last);
    layout->insertWidget(0, last);
    imageLabels.insert(0, static_cast<QLabel*>(last));
}

void MainWindow::scrollDown()
{
    // Take first widget and move it to the bottom
    QWidget *first = imageLabels.takeFirst();
    layout->removeWidget(first);
    layout->addWidget(first);
    imageLabels.append(static_cast<QLabel*>(first));
}

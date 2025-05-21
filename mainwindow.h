#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QWheelEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::MainWindow *ui;
    QWidget *scrollWidget;
    QVBoxLayout *layout;
    QList<QLabel*> imageLabels;
    QStringList imagePaths;

    void setupImages();
    void scrollUp();
    void scrollDown();
};
#endif // MAINWINDOW_H

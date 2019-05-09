#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_build_clicked();

    void on_build_sp_clicked();

    void on_pushButton_clicked();

    void on_delete_all_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QColor *c;
    QColor *c_spectr;
};

#endif // MAINWINDOW_H

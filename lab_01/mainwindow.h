#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include "core_func.h"
#include "my_draw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    canvas_t canvas;
    data_t data;
    int fov = 120;

private slots:

    void on_rot_dial_actionTriggered(int action);

    void on_scl_dial_actionTriggered(int action);

    void on_move_dial_actionTriggered(int action);

    void on_prot_ox_btn_clicked();
    void on_prot_oy_btn_clicked();
    void on_prot_oz_btn_clicked();

    void on_nrot_ox_btn_clicked();
    void on_nrot_oy_btn_clicked();
    void on_nrot_oz_btn_clicked();

    void on_pscl_ox_btn_clicked();
    void on_pscl_oy_btn_clicked();
    void on_pscl_oz_btn_clicked();

    void on_nscl_ox_btn_clicked();
    void on_nscl_oy_btn_clicked();
    void on_nscl_oz_btn_clicked();

    void on_pmv_ox_btn_clicked();
    void on_pmv_oy_btn_clicked();
    void on_pmv_oz_btn_clicked();

    void on_nmv_ox_btn_clicked();
    void on_nmv_oy_btn_clicked();
    void on_nmv_oz_btn_clicked();

    void on_show_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

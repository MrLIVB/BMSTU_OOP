#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = shared_ptr<QGraphicsScene>(new QGraphicsScene(this));
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene.get());

    ui->angle_lbl_2->setText(QString("Rotation angle = %1").arg(ui->rot_dial->value()));
    ui->coefficient_lbl_2->setText(QString("Scale coefficient = %1").arg(ui->scl_dial->value() / 10.0));
    ui->div_lbl_2->setText(QString("Coordinates step = %1").arg(ui->move_dial->value()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_show_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open model", "E:\\study\\4sem\\OOP\\lab_03\\data",\
                                                    "Text file (*.txt)");
    QByteArray name = fileName.toLatin1();
    LoadCommand load = LoadCommand(name.data());

    interface.execute(load);

    sendDrawCommand();
}

void MainWindow::sendDrawCommand()
{
    QDrawCommand draw(scene, QPen(Qt::black), QPen(Qt::black));
    interface.execute(draw);
}

void MainWindow::on_rot_dial_actionTriggered(int action)
{
    ui->angle_lbl_2->setText(QString("Rotation angle = %1").arg(ui->rot_dial->value()));
}

void MainWindow::on_scl_dial_actionTriggered(int action)
{
    ui->coefficient_lbl_2->setText(QString("Scale coefficient = %1").arg(ui->scl_dial->value() / 10.0));
}

void MainWindow::on_move_dial_actionTriggered(int action)
{
    ui->div_lbl_2->setText(QString("Coordinates step = %1").arg(ui->move_dial->value()));
}

void MainWindow::on_pmv_ox_btn_clicked()
{
    const double _x = ui->move_dial->value();
    MoveCommand mov(_x, 0, 0);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_pmv_oy_btn_clicked()
{
    const double _y = ui->move_dial->value();
    MoveCommand mov(0, _y, 0);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_pmv_oz_btn_clicked()
{
    const double _z = ui->move_dial->value();
    MoveCommand mov(0, 0, _z);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_nmv_ox_btn_clicked()
{
    const double _x = ui->move_dial->value();
    MoveCommand mov(-_x, 0, 0);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_nmv_oy_btn_clicked()
{
    const double _y = ui->move_dial->value();
    MoveCommand mov(0, -_y, 0);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_nmv_oz_btn_clicked()
{
    const double _z = ui->move_dial->value();
    MoveCommand mov(0, 0, -_z);
    interface.execute(mov);

    sendDrawCommand();
}

void MainWindow::on_pscl_ox_btn_clicked()
{
    const double _x = ui->scl_dial->value() / 10.;
    ScaleCommand scl(_x, 1, 1);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_nscl_ox_btn_clicked()
{
    const double _x = 1 / (ui->scl_dial->value() / 10.);
    ScaleCommand scl(_x, 1, 1);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_pscl_oy_btn_clicked()
{
    const double _y = ui->scl_dial->value() / 10.;
    ScaleCommand scl(1, _y, 1);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_nscl_oy_btn_clicked()
{
    const double _y = 1 / (ui->scl_dial->value() / 10.);
    ScaleCommand scl(1, _y, 1);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_pscl_oz_btn_clicked()
{
    const double _z = ui->scl_dial->value() / 10.;
    ScaleCommand scl(1, 1, _z);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_nscl_oz_btn_clicked()
{
    const double _z = 1 / (ui->scl_dial->value() / 10.);
    ScaleCommand scl(1, 1, _z);
    interface.execute(scl);

    sendDrawCommand();
}

void MainWindow::on_prot_ox_btn_clicked()
{
    const double _x = ui->move_dial->value() / 10.;
    RotateCommand rot(_x, 0, 0);
    interface.execute(rot);

    sendDrawCommand();
}

void MainWindow::on_nrot_ox_btn_clicked()
{
    const double _x = ui->move_dial->value() / 10.;
    RotateCommand rot(-_x, 0, 0);
    interface.execute(rot);

    sendDrawCommand();
}

void MainWindow::on_prot_oy_btn_clicked()
{
    const double _y = ui->move_dial->value() / 10.;
    RotateCommand rot(0, _y, 0);
    interface.execute(rot);

    sendDrawCommand();
}

void MainWindow::on_nrot_oy_btn_clicked()
{
    const double _y = ui->move_dial->value() / 10.;
    RotateCommand rot(0, -_y, 0);
    interface.execute(rot);

    sendDrawCommand();
}

void MainWindow::on_prot_oz_btn_clicked()
{
    const double _z = ui->move_dial->value() / 10.;
    RotateCommand rot(0, 0, _z);
    interface.execute(rot);

    sendDrawCommand();
}

void MainWindow::on_nrot_oz_btn_clicked()
{
    const double _z = ui->move_dial->value() / 10.;
    RotateCommand rot(0, 0, -_z);
    interface.execute(rot);

    sendDrawCommand();
}

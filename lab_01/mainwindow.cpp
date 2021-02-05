#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas.scene.scene = new QGraphicsScene(this);
    canvas.scene.scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());


    ui->graphicsView->setScene(canvas.scene.scene);
    ui->angle_lbl_2->setText(QString("Rotation angle = %1").arg(ui->rot_dial->value()));
    ui->coefficient_lbl_2->setText(QString("Scale coefficient = %1").arg(ui->scl_dial->value() / 10.0));
    ui->div_lbl_2->setText(QString("Coordinates step = %1").arg(ui->move_dial->value()));

    canvas.view_point.z = ui->graphicsView->width() / tan(fov / 2 * M_PI / 180);
    canvas.view_point.y = 0;
    canvas.view_point.x = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    core(canvas, data, delete_a);
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

void MainWindow::on_show_btn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, ("Open file"), QDir::currentPath(), "Text file (*.txt)");
    data.filename.string = filename;


    results rc = core(canvas, data, start_a);
    if (rc == no_file)
    {
        QMessageBox::warning(this, "Loading", "There is no file!");
        return;
    }
    else if (rc == empty_file)
    {
        QMessageBox::warning(this, "Loading", "File is empty!");
        return;
    }
    else if (rc == incorrect_format)
    {
        QMessageBox::warning(this, "Loading", "Incorrect format!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_prot_ox_btn_clicked()
{
    data.transform.x = -ui->rot_dial->value();
    data.transform.y = 0;
    data.transform.z = 0;
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_prot_oy_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = -ui->rot_dial->value();
    data.transform.z = 0;
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_prot_oz_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = 0;
    data.transform.z = -ui->rot_dial->value();
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nrot_ox_btn_clicked()
{
    data.transform.x = ui->rot_dial->value();
    data.transform.y = 0;
    data.transform.z = 0;
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nrot_oy_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = ui->rot_dial->value();
    data.transform.z = 0;
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nrot_oz_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = 0;
    data.transform.z = ui->rot_dial->value();
    results rc = core(canvas, data, rotate_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Rotate", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pscl_ox_btn_clicked()
{
    data.transform.x = ui->scl_dial->value() / 10.;
    data.transform.y = 1;
    data.transform.z = 1;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pscl_oy_btn_clicked()
{
    data.transform.x = 1;
    data.transform.y = ui->scl_dial->value() / 10.;
    data.transform.z = 1;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pscl_oz_btn_clicked()
{
    data.transform.x = 1;
    data.transform.y = 1;
    data.transform.z = ui->scl_dial->value() / 10.;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nscl_ox_btn_clicked()
{
    data.transform.x = -ui->scl_dial->value() / 10.;
    data.transform.y = 1;
    data.transform.z = 1;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nscl_oy_btn_clicked()
{
    data.transform.x = 1;
    data.transform.y = -ui->scl_dial->value() / 10.;
    data.transform.z = 1;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nscl_oz_btn_clicked()
{
    data.transform.x = 1;
    data.transform.y = 1;
    data.transform.z = -ui->scl_dial->value() / 10.;
    results rc = core(canvas, data, scale_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Scale", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pmv_ox_btn_clicked()
{
    data.transform.x = ui->move_dial->value();
    data.transform.y = 0;
    data.transform.z = 0;
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pmv_oy_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = -ui->move_dial->value();
    data.transform.z = 0;
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_pmv_oz_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = 0;
    data.transform.z = ui->move_dial->value();
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nmv_ox_btn_clicked()
{
    data.transform.x = -ui->move_dial->value();
    data.transform.y = 0;
    data.transform.z = 0;
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nmv_oy_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = ui->move_dial->value();
    data.transform.z = 0;
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

void MainWindow::on_nmv_oz_btn_clicked()
{
    data.transform.x = 0;
    data.transform.y = 0;
    data.transform.z = -ui->move_dial->value();
    results rc = core(canvas, data, move_a);
    if (rc == no_model)
    {
        QMessageBox::warning(this, "Move", "Model isn't loaded!");
        return;
    }
    core(canvas, data, paint_a);
}

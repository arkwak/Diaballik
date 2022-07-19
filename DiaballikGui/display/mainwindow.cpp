#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("Img/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setWindowTitle("Diaballik - Acceuil");
    gameWindow = new GameWindow(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{

    if (!ui->BluePlayerName->text().isEmpty() &&
            !ui->RedPlayerName->text().isEmpty())
    {
        gameWindow = new GameWindow(this);
        hide();
        gameWindow->setBlueName(ui->BluePlayerName->text());
        gameWindow->setRedName(ui->RedPlayerName->text());
        if (ui->Five->isChecked())
        {
            _size = 5;
        }
        if (ui->Seven->isChecked())
        {
            _size = 7;
        }
        if (ui->Nine->isChecked())
        {
            _size = 9;
        }
        if (ui->checkBox->isChecked()) {
            variant = true;
        }else{
            variant = false;
        }
        gameWindow->createBoard(_size,variant);
        gameWindow->show();
    }
}
void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

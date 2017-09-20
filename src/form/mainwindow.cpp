#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->actionVisible);
    menu->addAction(ui->actionQuit);
    tray.setIcon(QIcon("NginBox.ico"));
    tray.setContextMenu(menu);
    tray.show();

    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionVisible, &QAction::toggled, this, &MainWindow::setVisible);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "nginxview.h"
#include "ui_nginxview.h"
#include <QString>
#include <QStringList>
#include <QDir>
#include <QDebug>

NginxView::NginxView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NginxView),
    setting("nginx.ini", QSettings::IniFormat)
{
    ui->setupUi(this);
    ui->directoryEdit->setText(setting.value("directory").toString());
    connect(ui->ableButton, &QPushButton::toggled, this, &NginxView::setAble);
}

NginxView::~NginxView()
{
    if (process.isOpen()) stop();
    delete ui;
}

void NginxView::setAble(bool able)
{
    if (able && !process.isOpen()) start();
    else stop();
}

void NginxView::start()
{
    QStringList argument;
    QDir directory(ui->directoryEdit->text());
    QString nginx = directory.filePath("nginx");
    setting.setValue("directory", directory.path());
    argument << "-p" << directory.path();
    process.start(nginx, argument);
}

void NginxView::stop()
{
    QProcess helper;
    QStringList argument;
    QDir directory(ui->directoryEdit->text());
    QString nginx = directory.filePath("nginx");
    argument << "-p" << directory.path()
             << "-s" << "stop";
    helper.execute(nginx, argument);
}

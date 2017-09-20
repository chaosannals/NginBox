#include "phpview.h"
#include "ui_phpview.h"
#include <QDir>
#include <QString>
#include <QStringList>
#include <QDebug>

PHPView::PHPView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PHPView),
    setting("php.ini", QSettings::IniFormat)
{
    ui->setupUi(this);
    ui->directoryEdit->setText(setting.value("directory").toString());
    connect(ui->ableButton, &QPushButton::toggled, this, &PHPView::setAble);
}

PHPView::~PHPView()
{
    if (process.isOpen()) stop();
    delete ui;
}

void PHPView::setAble(bool able)
{
    if (able && !process.isOpen())start();
    else stop();
}

void PHPView::start()
{
    qDebug() << "Start";
    QStringList argument;
    QDir directory(ui->directoryEdit->text());
    QString php = directory.filePath("php-cgi");
    setting.setValue("directory", directory.path());
    argument << "-b" << "127.0.0.1:9000"
             << "-c" << directory.filePath("php.ini");
    process.start(php, argument);
}

void PHPView::stop()
{
    process.kill();
}

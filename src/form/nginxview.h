#ifndef NGINXVIEW_H
#define NGINXVIEW_H

#include <QWidget>
#include <QProcess>
#include <QSettings>

namespace Ui { class NginxView; }

class NginxView : public QWidget
{
    Q_OBJECT
public:
    explicit NginxView(QWidget *parent = 0);
    ~NginxView();
public slots:
    void setAble(bool able);
private slots:
    void start();
    void stop();
private:
    Ui::NginxView *ui;
    QProcess process;
    QSettings setting;
};

#endif // NGINXVIEW_H

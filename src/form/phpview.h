#ifndef PHPVIEW_H
#define PHPVIEW_H

#include <QWidget>
#include <QProcess>
#include <QSettings>

namespace Ui { class PHPView; }

/**
 * @brief The PHPView class
 */
class PHPView : public QWidget
{
    Q_OBJECT
public:
    explicit PHPView(QWidget *parent = 0);
    ~PHPView();
private slots:
    void setAble(bool able);
    void start();
    void stop();
private:
    Ui::PHPView *ui;
    QProcess process;
    QSettings setting;
};

#endif // PHPVIEW_H

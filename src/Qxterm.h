#ifndef QXTERM_H
#define QXTERM_H

#include <QWidget>


class QProcess;

class Terminal : public QWidget
{
    Q_OBJECT

public:
    Terminal(QWidget * = 0);
    ~Terminal();

    bool isRunning();

public slots:
    bool start();
    bool tryTerminate();

protected slots:
    void termProcessExited();

signals:
    void exited();

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    int cols, rows;
    QProcess *termProcess;
};

#endif // QXTERM_H

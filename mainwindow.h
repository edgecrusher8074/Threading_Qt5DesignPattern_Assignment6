#pragma once

#include <QMainWindow>
#include <QFuture>
#include <QFutureWatcher>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void progressUpdate(int value);

private slots:
    void handleStart();
    void handleFinished();

    void handleProgressUpdate(int value);

private:
    void performUpdate(int timeSpan);

private:
    Ui::MainWindow *ui;
    QFuture<void> m_future;
    QFutureWatcher<void> m_futureWatcher;
};

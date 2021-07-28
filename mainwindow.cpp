#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QtConcurrent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->m_pushButtonStart, &QPushButton::clicked, this, &MainWindow::handleStart);
    connect(&m_futureWatcher, &QFutureWatcher<void>::finished, this, &MainWindow::handleFinished);
    connect(ui->m_spinBoxProgess, &QSpinBox::editingFinished, this, &MainWindow::handleStart);
    connect(this, &MainWindow::progressUpdate, this, &MainWindow::handleProgressUpdate);
    handleProgressUpdate(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleStart()
{
    ui->m_pushButtonStart->setEnabled(false);
    m_future = QtConcurrent::run(this, &MainWindow::performUpdate, ui->m_spinBoxProgess->value());
    m_futureWatcher.setFuture(m_future);
}

void MainWindow::handleFinished()
{
    ui->m_pushButtonStart->setEnabled(true);
}

void MainWindow::handleProgressUpdate(int value)
{
    ui->m_progressBar->setValue(value);
}

void MainWindow::performUpdate(int timeSpan)
{
    double sleep = static_cast<double>(timeSpan)*1000.0/100.0;
    for(int i= 0; i < 100; i++)
    {
        emit progressUpdate(i+1);
        QThread::currentThread()->msleep(static_cast<int>(sleep));
    }
}


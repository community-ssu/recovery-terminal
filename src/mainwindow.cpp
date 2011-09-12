#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_X11BypassTransientForHint);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    QTermWidget *widget = new QTermWidget(1, this);
    connect(widget, SIGNAL(finished()), qApp, SLOT(quit()));
    this->setCentralWidget(widget);
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    timer->start();

    widget->sendText("# If you're seeing this, chances are hildon-desktop crashed and stopped working\n");
    widget->sendText("# This is a recovery terminal, please attempt to fix your issue and try to restart\n");
    widget->sendText("# hildon-desktop by using the command /usr/bin/hildon-desktop\n");
    widget->sendText("# Type 'exit' to quit this terminal window");

    if (QFile("/usr/bin/root").exists())
        widget->sendText("root\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimerTimeout()
{
    this->activateWindow();
    this->centralWidget()->setFocus();
}

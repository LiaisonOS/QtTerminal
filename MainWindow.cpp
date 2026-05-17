//
// Author  : Sylvain Deguire (VA2OPS)
// Date    : May 2026
// Purpose : QtTerminal main window — embeds QTermWidget to run a command.
//

#include "MainWindow.h"
#include <QApplication>
#include <QScreen>

MainWindow::MainWindow(const QString &title,
                       const QString &command,
                       const QString &workdir,
                       QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(title);

    QTermWidget *term = new QTermWidget(0, this);

    // Apply a clean dark color scheme
    term->setColorScheme("WhiteOnBlack");
    term->setTerminalFont(QFont("Monospace", 10));

    if (!workdir.isEmpty())
        term->setWorkingDirectory(workdir);

    if (!command.isEmpty())
        term->setShellProgram("/bin/bash");
    else
        term->setShellProgram("/bin/bash");

    QStringList args;
    if (!command.isEmpty()) {
        args << "-c" << command;
        term->setArgs(args);
    }

    connect(term, &QTermWidget::finished, this, &MainWindow::onFinished);

    setCentralWidget(term);

    // Reasonable default size
    resize(800, 500);

    term->startShellProgram();
}

void MainWindow::onFinished()
{
    QApplication::quit();
}

//
// Author  : Sylvain Deguire (VA2OPS)
// Date    : May 2026
// Purpose : QtTerminal main window.
//

#pragma once

#include <QMainWindow>
#include <QString>
#include <qtermwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &title,
                        const QString &command,
                        const QString &workdir,
                        QWidget *parent = nullptr);

private slots:
    void onFinished();
};

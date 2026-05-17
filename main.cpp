//
// Author  : Sylvain Deguire (VA2OPS)
// Date    : May 2026
// Purpose : Lightweight terminal emulator for LiaisonOS.
//           Replaces xfce4-terminal for et-supervisor managed apps.
//           Usage: QtTerminal --title "Chattervox" -e "chattervox chat"
//

#include <QApplication>
#include <QCommandLineParser>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("QtTerminal");
    app.setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption({"title", "Window title", "title", "Terminal"});
    parser.addOption({"e", "Command to run", "command"});
    parser.addOption({"working-directory", "Working directory", "dir"});
    parser.process(app);

    QString title   = parser.value("title");
    QString command = parser.value("e");
    QString workdir = parser.value("working-directory");

    MainWindow w(title, command, workdir);
    w.show();

    return app.exec();
}

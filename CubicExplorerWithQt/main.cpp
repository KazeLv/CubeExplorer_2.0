#include "CubeExplorerWithQt.h"
#include "CubeRecognizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CubeExplorerWithQt w;

	iniHSVMap();
	iniRecMap();
	iniRecogVars();

	w.setWindowTitle(QStringLiteral("Rubik's Cube Explorer"));
	w.setWindowIcon(QIcon("./Resources/icon.png"));
	w.show();
	return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QWidget>


int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_ForceRasterWidgets);
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}

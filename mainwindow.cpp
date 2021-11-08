#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <private/qabstractstate_p.h>
#include <private/qobject_p.h>
#include <private/qabstractitemmodel_p.h>

#include "3rdparty/pdfium-win-x64/include/fpdfview.h"

class QPdfBookmarkModelPrivate : public QAbstractItemModelPrivate
{
public:
	QPdfBookmarkModelPrivate()
		: QAbstractItemModelPrivate()

	{
	}
};

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	testPdf();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::testPdf()
{
	FPDF_InitLibrary();
	FPDF_DOCUMENT doc;
	FPDF_PAGE page;
	doc = FPDF_LoadDocument("C:\\Users\\zhangpf\\Project\\KTodo\\build\\1.pdf", nullptr);
	if (doc == NULL)
	{
		qDebug() << "123" << endl;
	}
	int numPages = FPDF_GetPageCount(doc);
	printf("document has %d pages\n", numPages);

	FPDF_DestroyLibrary();
}

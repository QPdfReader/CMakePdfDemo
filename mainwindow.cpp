#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>


#include "qpdfdocument.h"

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
	QPdfDocument pdfDoc;
	QPdfDocument::DocumentError docError = pdfDoc.load("C:\\Users\\zhangpf\\Project\\KTodo\\build\\1.pdf");
	qDebug() << docError << endl;
	int nCount = pdfDoc.pageCount();
	qDebug() << nCount << endl;
}

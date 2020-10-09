#include <iostream>
#include "window.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QImage>
#include <QtGui>
#include <QApplication>
#include <QMessageBox>

//The include tower begins!
//Please direct all complaints about the include tower to Alexander Wiecking or Michael Eddins; whoever happens to be closer.


Window::Window() : QMainWindow()
{
	m_toolbar = new QToolBar(this);
	addToolBar(m_toolbar);
	m_importmenu = new QAction(tr("Import"));
	m_savemenu = new QAction(tr("Save"));
	m_modify = new QAction(tr("Modify"));
	m_stats = new QAction(tr("Stats"));
	m_quit = new QAction(tr("Quit"));

	m_toolbar->addSeparator();
	m_toolbar->addAction(m_importmenu);
	m_toolbar->addAction(m_savemenu);
	
	m_toolbar->addSeparator();
	m_toolbar->setMovable(false);
	m_toolbar->addAction(m_modify);
	m_toolbar->addAction(m_stats);
	m_toolbar->addSeparator();
	m_toolbar->addAction(m_quit);
	m_toolbar->addSeparator();
	m_display = new QLabel(this);
	m_layout = new QVBoxLayout();
	m_loaded_image = new QImage;

	connect(m_importmenu, SIGNAL(triggered()), this, SLOT(import_image()));
	connect(m_savemenu, SIGNAL(triggered()), this, SLOT(save_image()));
	connect(m_modify, SIGNAL(triggered()), this, SLOT(modify_image()));
	connect(m_stats, SIGNAL(triggered()), this, SLOT(stats()));
	connect(m_quit, SIGNAL(triggered()), this, SLOT(close()));
	this->layout()->setMenuBar(m_toolbar);
	setCentralWidget(m_display);
	this->show();
}

Window::~Window()
{
}
void Window::import_image()
{
	bool ok;
	QString filename = QInputDialog::getText(this, tr("Load"), tr("Enter the name and extension of the file:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
	QImage image;
	image.load(filename);
	m_display->setPixmap(QPixmap::fromImage(image));	
	m_loaded_image->load(filename);

	for (int x = 0; x < image.width(); ++x) {
		for (int y = 0; y < image.height(); ++y) {
			m_tree.insert(image.pixel(x, y));
			m_tree.find(image.pixel(x, y))->list().push_back(QPoint(x, y));
		}
	} //Nested for loops - for when you're just too lazy.
	m_tree.print();
}

void Window::save_image()
{
	bool ok;
	QString filename = QInputDialog::getText(this, tr("Save"), tr("Enter the name and extension of the file you want to save:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
	m_loaded_image->save(filename, nullptr, -1);
}

void Window::modify_image()
{
	bool ok;
	int red = QInputDialog::getInt(this, tr("Red"), tr("Enter the 'Red' value of the color you want to remove (try the stats function to get a list of colors in the image):"), 0, 0, 255, 1, &ok);

	int green = QInputDialog::getInt(this, tr("Green"), tr("Enter the 'Green' value of the color you want to remove:"), 0, 0, 255, 1, &ok);

	int blue = QInputDialog::getInt(this, tr("Blue"), tr("Enter the 'Blue' value of the color you want to remove:"), 0, 0, 255, 1, &ok);

	int alpha = QInputDialog::getInt(this, tr("Alpha"), tr("Enter the 'Alpha' value of the color you want to remove (255 by default):"), 0, 0, 255, 1, &ok);

	QColor color = QColor(red, green, blue, alpha);
	QRgb key = color.rgb();
	Node* found = m_tree.find(key);
	if(!found) {
		QMessageBox msgBox;
		msgBox.setWindowTitle(tr("Error"));
		msgBox.setText("No matching color was found in the image.");
		msgBox.exec();
		return;
	}
	QColor nullcolor = QColor(255, 255, 255, 255);
	for (QPoint p : found->list()) {
		m_loaded_image->setPixelColor(p, nullcolor);
	}
	m_tree.remove(key);
	cout << "Removing color." << endl;
	m_display->setPixmap(QPixmap::fromImage(*m_loaded_image));
}

void Window::stats()
{

}

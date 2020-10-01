#include <iostream>
#include "window.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

//The include tower begins!
//Please direct all complaints about the include tower to Alexander Wiecking or Michael Eddins; whoever happens to be closer.


Window::Window() : QMainWindow()
{
	m_menu = menuBar()->addMenu(tr("&File"));
	m_toolbar = new QToolBar(this);
	addToolBar(m_toolbar);
	m_importmenu = new QAction(tr("Import"));
	m_savemenu = new QAction(tr("Save"));
	m_modify = new QAction(tr("Modify"));
	m_stats = new QAction(tr("Stats"));
	m_quit = new QAction(tr("Quit"));

	m_menu->addAction(m_importmenu);
	m_menu->addAction(m_savemenu);
	m_menu->addAction(m_quit);

	m_menu->addSeparator();
	m_toolbar->setMovable(false);

	m_toolbar->addAction(m_modify);
	m_toolbar->addAction(m_stats);
	m_toolbar->addSeparator();

	connect(m_importmenu, SIGNAL(triggered()), this, SLOT(import_image()));
	connect(m_savemenu, SIGNAL(triggered()), this, SLOT(save_image()));
	connect(m_modify, SIGNAL(triggered()), this, SLOT(modify_image()));
	connect(m_stats, SIGNAL(triggered()), this, SLOT(stats()));
	connect(m_quit, SIGNAL(triggered()), this, SLOT(close()));

	this->show();
}

Window::~Window()
{
}
void Window::import_image()
{
}

void Window::save_image()
{
}

void Window::modify_image()
{
}

void Window::stats()
{
}

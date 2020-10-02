#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QAction>
#include "tree.h"

#ifndef __WINDOW_H
#define __WINDOW_H

class QVBoxLayout;
class QMouseEvent;
class QMenuBar;
class QMenu;
class QImage;
class QLabel;

class Window : public QMainWindow
{
	Q_OBJECT
	private:
		QToolBar* m_toolbar;
		QAction* m_filemenu;
		QAction* m_savemenu;
		QAction* m_importmenu;
		QAction* m_modify;
		QAction* m_stats;
		QAction* m_quit;
		QLabel* m_display;
		QVBoxLayout* m_layout;
		QImage* m_loaded_image;
		Tree m_tree;

	private slots:
		void import_image();
		void save_image();
		void modify_image();
		void stats();
	public:
		Window();
		~Window();
};


#endif


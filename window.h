#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QAction>


#ifndef __WINDOW_H
#define __WINDOW_H

class QHBoxLayout;
class QMouseEvent;
class QMenuBar;
class QMenu;

class Window : public QMainWindow
{
	Q_OBJECT
	private:
		QMenu* m_menu;
		QToolBar* m_toolbar;
		QAction* m_filemenu;
		QAction* m_savemenu;
		QAction* m_importmenu;
		QAction* m_modify;
		QAction* m_stats;
		QAction* m_quit;
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


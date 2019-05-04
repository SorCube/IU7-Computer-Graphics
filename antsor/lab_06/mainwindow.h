#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>

#include "point.h"
#include "polygon.h"
#include "painter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QImage *image, std::vector<Polygon> *polygons,
						Polygon *pl, Painter *p, QWidget *parent = 0);
	~MainWindow();
	void set_scene(QGraphicsScene *scene);
	void add_point(Point p);
	void end_polygon();
	void lock_disable(bool d);
	void cur_coord(Point p);
	
private slots:
	void on_palEdgeBtn_released();
	
	void on_palFillBtn_released();
	
	void on_palBgBtn_released();
	
	void on_addButton_released();
	
	void on_lockButton_released();
	
	void on_clearButton_released();
	
	void on_fillButton_released();
	
private:
	Ui::MainWindow *ui;
	
	Painter *painter;
	QImage *img;
	
	std::vector<Polygon> *polygon_set;
	Polygon *new_polygon;
	
	QColor color_edge;
	QColor color_fill;
	QColor color_bg;
};

#endif // MAINWINDOW_H

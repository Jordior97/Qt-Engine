#ifndef SHAPERENDERERWIDGET_H
#define SHAPERENDERERWIDGET_H

#include <QWidget>

namespace Ui {
class ShapeRendererWidget;
}

class ShapeRendererWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShapeRendererWidget(QWidget *parent = 0);
    ~ShapeRendererWidget();

private slots:
    void on_actionFillColor_triggered();

private:
    Ui::ShapeRendererWidget *ui;
};

#endif // SHAPERENDERERWIDGET_H

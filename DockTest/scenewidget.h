#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QObject>
#include <QWidget>

class Scene;
enum StrokeStyle;

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    bool GetScene(Scene* scenePointer);

private:
    void SetPainter(QColor fillColor, QColor strokeColor, StrokeStyle strokeStyle, int lineSize, QBrush& brush, QPen& pen, QPainter& painter);

    void DrawCircle(int posX, int posY, int radius, QPainter& painter);
    void DrawSquare(int posX, int posY, int size, QPainter& painter);
    void DrawTriangle(int posX, int posY, int size, QPainter& painter);

signals:

public slots:    

private:

    void paintEvent(QPaintEvent *event) override;

    Scene* scene = nullptr;

};

#endif // SCENEWIDGET_H

#ifndef OPENGLSCENE_H
#define OPENGLSCENE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>


class OpenGLScene : public QOpenGLWidget,
                    protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    explicit OpenGLScene(QWidget *parent = nullptr);
    ~OpenGLScene() override;

    // OpenGL function calls
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

signals:

public slots:

    void finalizeGL();
};

#endif // OPENGLSCENE_H

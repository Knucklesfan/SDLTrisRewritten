// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef GLWIDGET_H
#define GLWIDGET_H


#include <QOpenGLWidget>
#include "previewcamera.h"
#include "qwidget.h"
#include <QMouseEvent>
#include <QCoreApplication>
#include <glm/glm.hpp>
#include <math.h>
#include <QTimer>

class TransformObject;
class texture;
class shader;
class cube;
class model;
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    glm::vec3 camerapos;
    glm::vec3 camerarot;

public slots:
    void cleanup();


signals:

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void setupVertexAttribs();
    int rotate = 0;
    shader* shad;
    shader* litshad;
    std::vector<TransformObject*> elements;
    model* mod;
    model* heavy;
    model* petah;
    QTimer timer;
    static bool m_transparent;

    //all of this is used for debugging mostly only.
    QMap<int, bool> keys;
    previewCamera* cam;
    bool move; //Is the user moving the debug camera?
};

#endif

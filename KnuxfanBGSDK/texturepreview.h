// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TEXTPREVIEW_H
#define TEXTPREVIEW_H


#include <QOpenGLWidget>
#include "qwidget.h"
#include <QMouseEvent>
#include <QCoreApplication>
#include <math.h>
#include <QTimer>
#include <vector>

class texture;
class shader;
class cube;
class skybox;
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class TexturePreview : public QOpenGLWidget
{
    Q_OBJECT

public:
    TexturePreview(QWidget *parent = nullptr);
    ~TexturePreview();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    int previewtexture = 0;
    int backgroundtexture = 0;

public slots:
    void cleanup();

signals:

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void setupVertexAttribs();
    int rotate = 0;
    std::vector<texture*> t;
    shader* shad;
    shader* skyshad;

    cube* cub;
    skybox* box;
    QTimer timer;
    static bool m_transparent;
};

#endif

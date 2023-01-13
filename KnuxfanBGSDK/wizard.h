#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QtWidgets>

class TextureDialog : public QDialog
{
public:
    TextureDialog();
    QCheckBox* flipH;
    QCheckBox* flipV;
    QLineEdit *filepath;
    QComboBox *pixelcombo;
    QLabel *image;
private slots:
    void flip();
    void loadimage();
};

class ShaderDialog : public QDialog
{
public:
    ShaderDialog();
    QLineEdit *vertpath;
    QLineEdit *fragpath;
private slots:
    void loadvertex();
    void loadfragment();
};

class AboutDialog : public QDialog
{
public:
    AboutDialog();
};

#endif // WIZARD_H

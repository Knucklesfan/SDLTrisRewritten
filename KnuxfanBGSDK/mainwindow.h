#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addtexture_clicked();

    void on_texturetable_itemClicked(QTableWidgetItem *item);

    void on_deletetexture_clicked();

    void on_texturecombo_currentIndexChanged(int index);

    void on_addshader_clicked();

    void on_removeshader_clicked();

    void on_actionAbout_triggered();

    void on_refreshtexture_clicked();

    void on_camerax_valueChanged(double arg1);

    void on_cameray_valueChanged(double arg1);

    void on_cameraz_valueChanged(double arg1);

    void on_camerarx_valueChanged(double arg1);

    void on_camerary_valueChanged(double arg1);

    void on_camerarz_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    void updateTextureTable();
    void updateShaderTable();

};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wizard.h"
#include "editorutils.h"
#include <QDebug>
#include <algorithm>
#include <assimp/Importer.hpp>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addtexture_clicked()
{
    TextureDialog *dialog = new TextureDialog;
    dialog->setWindowTitle("Texture Picker");
    dialog->setModal(true);
    int dialogCode = dialog->exec();
    if(dialogCode == QDialog::Accepted)
    {
        texture* t = new texture(dialog->filepath->text().toStdString(),dialog->pixelcombo->currentIndex(),dialog->flipH->checkState(),dialog->flipV->checkState());
        editorutils::textures.push_back(t);
        updateTextureTable();
    }
    if(dialogCode == QDialog::Rejected){
        QMessageBox Msgbox;
        Msgbox.setText("Texture addition cancelled.");
        Msgbox.setModal(true);
        Msgbox.setWindowTitle("Texture Picker");
        Msgbox.exec();
    }
}

void MainWindow::updateTextureTable() {
    ui->texturetable->setRowCount(0);
    ui->texturecombo->clear();
    ui->objecttexturepreviewcombo->clear();
    ui->objecttexturepreviewcombo->addItem("Use defined textures");

    for(int i = 0; i < editorutils::textures.size();i++) {
        ui->texturetable->insertRow(ui->texturetable->rowCount());
        ui->texturetable->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->texturetable->setItem(i, 1, new QTableWidgetItem(QString(editorutils::textures[i]->name.c_str())));
        ui->texturetable->setItem(i, 2, new QTableWidgetItem(
                                      QString((editorutils::textures[i]->type).c_str())+ " " + QString((editorutils::textures[i]->flipv)?"V":"") + QString((editorutils::textures[i]->fliph)?"H":"") )
                                  );
        ui->texturetable->setItem(i, 3, new QTableWidgetItem(QString(editorutils::textures[i]->path.c_str())));
        ui->texturecombo->addItem(QString(editorutils::textures[i]->name.c_str()));
        ui->objecttexturepreviewcombo->addItem(QString(editorutils::textures[i]->name.c_str()));

    }
}
void MainWindow::updateShaderTable() {
    ui->shadertable->setRowCount(0);
    for(int i = 0; i < editorutils::shaders.size();i++) {
        ui->shadertable->insertRow(ui->texturetable->rowCount());
        ui->shadertable->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->shadertable->setItem(i, 1, new QTableWidgetItem(QString(editorutils::shaders[i]->vert.c_str())));
        ui->shadertable->setItem(i, 2, new QTableWidgetItem(QString(editorutils::shaders[i]->frag.c_str())));
    }
}

void MainWindow::on_texturetable_itemClicked(QTableWidgetItem *item)
{
    ui->texturepreview->previewtexture = item->row();

}


void MainWindow::on_deletetexture_clicked()
{
    if(ui->texturetable->currentItem()) {
        std::swap(editorutils::textures[ui->texturetable->currentItem()->row()], editorutils::textures.back());
        editorutils::textures.pop_back();
    }
    updateTextureTable();
}


void MainWindow::on_texturecombo_currentIndexChanged(int index)
{
    ui->texturepreview->backgroundtexture = index;

}


void MainWindow::on_addshader_clicked()
{
    ShaderDialog *dialog = new ShaderDialog;
    dialog->setWindowTitle("Shader Creator");
    dialog->setModal(true);
    int dialogCode = dialog->exec();
    if(dialogCode == QDialog::Accepted)
    {
        shader* s = new shader(dialog->vertpath->text().toStdString(),dialog->fragpath->text().toStdString());
        if(s->success) {
            editorutils::shaders.push_back(s);
            updateShaderTable();
        }
        else {
            QMessageBox Msgbox;
            Msgbox.setText("Shader compilation failed.\nThe issue is as follows:\n" + QString(s->error.c_str()));
            Msgbox.setModal(true);
            Msgbox.setWindowTitle("Shader Creator");
            Msgbox.exec();

        }

    }
    if(dialogCode == QDialog::Rejected){
        QMessageBox Msgbox;
        Msgbox.setText("Shader addition cancelled.");
        Msgbox.setModal(true);
        Msgbox.setWindowTitle("Shader Creator");
        Msgbox.exec();
    }

}


void MainWindow::on_removeshader_clicked()
{
    if(ui->shadertable->currentItem()) {
        std::swap(editorutils::shaders[ui->shadertable->currentItem()->row()], editorutils::shaders.back());
        editorutils::shaders.pop_back();
    }
    updateShaderTable();

}


void MainWindow::on_actionAbout_triggered()
{
    AboutDialog *dialog = new AboutDialog;
    dialog->setWindowTitle("About Phoenix");
    dialog->show();

}




void MainWindow::on_refreshtexture_clicked()
{
    updateTextureTable();

}


void MainWindow::on_camerax_valueChanged(double arg1)
{
    ui->previewview->camerapos.x = arg1;
}


void MainWindow::on_cameray_valueChanged(double arg1)
{
    ui->previewview->camerapos.y = arg1;

}


void MainWindow::on_cameraz_valueChanged(double arg1)
{
    ui->previewview->camerapos.z = arg1;

}


void MainWindow::on_camerarx_valueChanged(double arg1)
{
    ui->previewview->camerarot.x = arg1;

}


void MainWindow::on_camerary_valueChanged(double arg1)
{
    ui->previewview->camerarot.y = arg1;

}


void MainWindow::on_camerarz_valueChanged(double arg1)
{
    ui->previewview->camerarot.z = arg1;

}


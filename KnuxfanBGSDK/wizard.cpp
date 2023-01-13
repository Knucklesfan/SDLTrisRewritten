#include "wizard.h"

AboutDialog::AboutDialog() {

    QVBoxLayout *mainpage = new QVBoxLayout;
    QVBoxLayout *bottom = new QVBoxLayout;
    QVBoxLayout *top = new QVBoxLayout;

    QLabel* logo = new QLabel();
    QImage myImage;
    myImage.load("./editorassets/logo.png");
    logo->setPixmap(QPixmap::fromImage(myImage).scaled(256,256));
    logo->setAlignment(Qt::AlignHCenter);

    QLabel* truename = new QLabel("Horizon");
    QFont truenamefont = truename->font();
    truenamefont.setPointSize(48);
    truename->setFont(truenamefont);
    truename->setAlignment(Qt::AlignHCenter);

    QLabel* bgenginer = new QLabel("Background Engineer of the modern era");
    QFont bgenginerfont = bgenginer->font();
    bgenginerfont.setPointSize(10);
    bgenginer->setFont(bgenginerfont);
    bgenginer->setAlignment(Qt::AlignHCenter);

    QLabel* credits = new QLabel("BirdPlumberEngine 0.1 background tool\nDeveloped by Knuxfan 2022-2023");
    QFont creditsfont = credits->font();
    creditsfont.setPointSize(6);
    credits->setFont(creditsfont);
    credits->setAlignment(Qt::AlignHCenter);

    top->addWidget(logo);
    top->addWidget(truename);
    top->addWidget(bgenginer);
    bottom->addWidget(credits);
    top->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    mainpage->addLayout(top);
    bottom->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    mainpage->addLayout(bottom);

    this->setLayout(mainpage);

}

TextureDialog::TextureDialog() {
        QVBoxLayout *mainpage = new QVBoxLayout;
        QHBoxLayout *mainlayout = new QHBoxLayout;
        QLabel *nameLabel = new QLabel("Filename:");

        QPushButton *nameButton = new QPushButton("Open");
        filepath = new QLineEdit;

        QVBoxLayout *imageholder = new QVBoxLayout;

        image = new QLabel();
        imageholder->addWidget(image);

        QHBoxLayout *flipholder = new QHBoxLayout;

        flipH = new QCheckBox("Flip H");
        flipholder->addWidget(flipH);
        flipV = new QCheckBox("Flip V");
        flipholder->addWidget(flipV);
        imageholder->addLayout(flipholder);

        connect(flipV, &QCheckBox::clicked,this,&TextureDialog::flip);
        connect(flipH, &QCheckBox::clicked,this,&TextureDialog::flip);

        connect(nameButton, &QPushButton::clicked,this,&TextureDialog::loadimage);
        QHBoxLayout *hlayout = new QHBoxLayout;
        hlayout->addWidget(nameButton);
        hlayout->addWidget(filepath);

        QLabel *pixellabel = new QLabel("Pixel Format:");
        pixelcombo = new QComboBox;
        pixelcombo->addItem("RGB");
        pixelcombo->addItem("RGBA");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(nameLabel, 0, 0);
        layout->addLayout(hlayout, 0, 1);

        layout->addWidget(pixellabel, 1, 0);
        layout->addWidget(pixelcombo, 1, 1);
        mainlayout->addLayout(layout);
        mainlayout->addLayout(imageholder);
        mainpage->addLayout(mainlayout);
        QHBoxLayout *returnbuttons = new QHBoxLayout;
        QPushButton *cancelbutton = new QPushButton("Cancel");
        QPushButton *addbutton = new QPushButton("Add");
        QObject::connect(addbutton, SIGNAL(clicked()), this, SLOT(accept()));
        QObject::connect(cancelbutton, SIGNAL(clicked()), this, SLOT(reject()));

        returnbuttons->addWidget(cancelbutton);
        returnbuttons->addWidget(addbutton);

        mainpage->addLayout(returnbuttons);
        this->setLayout(mainpage);
}

void TextureDialog::flip() {
    QString filename = filepath->text();
    QImage myImage;
    myImage.load(filename);
    image->setPixmap(QPixmap::fromImage(myImage.mirrored(flipH->checkState(),flipV->checkState())).scaled(256,256));
}
void TextureDialog::loadimage() {
    QString filename = QFileDialog::getOpenFileName(this, "Open File","/home","");
    filepath->setText(filename);
    QImage myImage;
    myImage.load(filename);
    image->setPixmap(QPixmap::fromImage(myImage).scaled(256,256));
}

ShaderDialog::ShaderDialog() {
        QVBoxLayout *mainpage = new QVBoxLayout;
        QHBoxLayout *mainlayout = new QHBoxLayout;
        QLabel *vertlabel = new QLabel("Vertex Shader:");

        QPushButton *vertbutton = new QPushButton("Open");
        vertpath = new QLineEdit;
        QLabel *fraglabel = new QLabel("Fragment Shader:");

        QPushButton *fragbutton = new QPushButton("Open");
        fragpath = new QLineEdit;

        connect(vertbutton, &QPushButton::clicked,this,&::ShaderDialog::loadvertex);
        connect(fragbutton, &QPushButton::clicked,this,&ShaderDialog::loadfragment);

        QHBoxLayout *hvlayout = new QHBoxLayout; //vertex
        hvlayout->addWidget(vertbutton);
        hvlayout->addWidget(vertpath);

        QHBoxLayout *hflayout = new QHBoxLayout; //fragment
        hflayout->addWidget(fragbutton);
        hflayout->addWidget(fragpath);


        QGridLayout *vertlayout = new QGridLayout;
        vertlayout->addWidget(vertlabel, 0, 0);
        vertlayout->addLayout(hvlayout, 0, 1);
        vertlayout->addWidget(fraglabel, 1, 0);
        vertlayout->addLayout(hflayout, 1, 1);

        mainlayout->addLayout(vertlayout);
        mainpage->addLayout(mainlayout);
        QHBoxLayout *returnbuttons = new QHBoxLayout;
        QPushButton *cancelbutton = new QPushButton("Cancel");
        QPushButton *addbutton = new QPushButton("Add");
        QObject::connect(addbutton, SIGNAL(clicked()), this, SLOT(accept()));
        QObject::connect(cancelbutton, SIGNAL(clicked()), this, SLOT(reject()));

        returnbuttons->addWidget(cancelbutton);
        returnbuttons->addWidget(addbutton);

        mainpage->addLayout(returnbuttons);
        this->setLayout(mainpage);
}
void ShaderDialog::loadvertex() {
    QString filename = QFileDialog::getOpenFileName(this, "Open File","/home","");
    vertpath->setText(filename);
}
void ShaderDialog::loadfragment() {
    QString filename = QFileDialog::getOpenFileName(this, "Open File","/home","");
    fragpath->setText(filename);
}

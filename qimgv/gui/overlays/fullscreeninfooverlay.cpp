#include "fullscreeninfooverlay.h"
#include "ui_fullscreeninfooverlay.h"

FullscreenInfoOverlay::FullscreenInfoOverlay(FloatingWidgetContainer *parent) :
    OverlayWidget(parent),
    ui(new Ui::FullscreenInfoOverlay)
{
    ui->setupUi(this);
    setPosition(FloatingWidgetPosition::TOPLEFT);
    this->setHorizontalMargin(0);
    this->setVerticalMargin(0);
    ui->nameLabel->setText("No file opened");
    if(parent)
        setContainerSize(parent->size());
}

FullscreenInfoOverlay::~FullscreenInfoOverlay() {
    delete ui;
}

void FullscreenInfoOverlay::setInfo(QString pos, QString fileName, QString info) {
    ui->posLabel->setText(pos);
    ui->nameLabel->setText(fileName);
    ui->infoLabel->setText(info);
    // the bar used to be capped at 600px which cut off long file names and the
    // info text; let it grow with its contents, but never wider than the window
    int containerWidth = containerSize().width();
    if(containerWidth > 0)
        setMaximumWidth(containerWidth);
    this->adjustSize();
}

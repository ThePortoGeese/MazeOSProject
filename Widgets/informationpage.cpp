#include "informationpage.h"
#include "ui_informationpage.h"

informationPage::informationPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::informationPage)
{
    ui->setupUi(this);
}

informationPage::~informationPage()
{
    delete ui;
}

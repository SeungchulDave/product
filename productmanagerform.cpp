#include "productmanagerform.h"
#include "ui_productmanagerform.h"

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, "100");

}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;
}

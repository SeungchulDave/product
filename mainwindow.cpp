#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"
#include "ordermanagerform.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ClientManagerForm *clientForm1 = new ClientManagerForm(0);
//    clientForm1->show();
    clientForm = new ClientManagerForm(this);
    clientForm->setWindowTitle(tr("고객 정보"));
    connect(clientForm, SIGNAL(destroyed()),
            clientForm, SLOT(deleteLater()));

//    ui->tabWidget->addTab(clientForm, "&Client Info");

    ProductManagerForm *productForm = new ProductManagerForm(this);
    productForm->setWindowTitle(tr("제품 정보"));
  connect(productForm, SIGNAL(destroyed()), productForm, SLOT(deleteLater()));
   OrderManagerForm *orderForm = new OrderManagerForm(this);
   orderForm->setWindowTitle(tr("주문 정보"));
   connect(orderForm, SIGNAL(destroyed()), orderForm, SLOT(deleteLater()));


    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);
    ui->mdiArea->addSubWindow(productForm);
    ui->mdiArea->addSubWindow(orderForm);
    ui->mdiArea->setActiveSubWindow(cw);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    if(clientForm != nullptr) {
        clientForm->setFocus();
    }
}


#include "dialog.h"
#include "ui_dialog.h"
#include "mydvs.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen bluepen(Qt::blue);
    QPen redpen(Qt::red);

    bluepen.setWidth(4);
    redpen.setWidth(4);

    MyDVS *myDVS128;
    myDVS128 = new MyDVS();

    int counter = 0;

    if(myDVS128->dvs128_init())
    {
        for(counter = 0;counter<5;counter++)
        {
            myDVS128->dvs128_run_single();
        }
        auto begin = myDVS128->events_buffer.begin(),
             end = myDVS128->events_buffer.end();
        while(begin != end)
        {
             if(begin -> polarity == 1)
             {
                painter.setPen(redpen);
                painter.drawPoint((begin -> x)*5,(begin -> y)*5);
             }
             else if(begin -> polarity == 0)
             {
                painter.setPen(bluepen);
                painter.drawPoint((begin -> x)*5,(begin -> y)*5);
             }
             begin++;
         }
        myDVS128->events_buffer.clear();
        myDVS128->dvs128_deinit();
    }
    else
    {
        cout<<"open failed"<<endl;
    }
}

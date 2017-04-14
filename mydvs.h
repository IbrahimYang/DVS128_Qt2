/*****************************************************************************
*******************Ibrahim,CBICR,Tsinghua University**************************
******************************************************************************
File name:    dvs128_class.h
Description:  the header file of dvs128_class.cpp
Author:       Ibrahim Yang
Version:      V1.0
Date:         2017-4-12
History:      inilabs->libcaer VLOGroup->dvs-reconstruction libusb-1.0
*****************************************************************************/
#ifndef MYDVS_H
#define MYDVS_H

#include <libcaer/libcaer.h>
#include <libcaer/devices/dvs128.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <queue>

#include <QtCore>
#include <QtGui>

using namespace std;
using namespace cv;

/*************************************************
Struct:       Event
Description:  the struct save the event data for dvs128
Calls:        none
Called By:    MyDVS128::run()
Input:        none
Output:       none
Return:       none
Others:       none
*************************************************/
typedef struct
{
   int x;
   int y;
   float t;
   bool polarity;
}Event;

/*************************************************
Class:        MyDVS128
Description:  the class for dvs128
Calls:        none
Called By:    functions in dvs128_class.cpp
Input:        none
Output:       none
Return:       none
Others:       none
*************************************************/
class MyDVS : public QObject
{
    Q_OBJECT
public:
    MyDVS() = default;
    void dvs128_run_single();
    void dvs128_run();
    void dvs128_stop(void);
    bool dvs128_init(void);
    void dvs128_deinit(void);
    std::vector<Event> events_buffer;

protected:
    caerDeviceHandle dvs128_handle;
    bool running_ = true;
};

#endif // MYDVS_H

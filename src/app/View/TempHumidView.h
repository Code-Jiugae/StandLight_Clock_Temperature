#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once
#include "LCD.h"

class TempHumidView
{
private:
    LCD *lcd;
public:
    int checkTemp = 0;
    TempHumidView(LCD *lcd);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);
};

#endif
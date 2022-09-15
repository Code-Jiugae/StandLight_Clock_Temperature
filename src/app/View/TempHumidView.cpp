#include "TempHumidView.h"
#include <wiringPi.h>
#include <iostream>

TempHumidView::TempHumidView(LCD *lcd)
{
    this->lcd = lcd;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    static unsigned int prevWarningTime = 0;

    if((int)temp >= 28)
    {
        lcd->backLightWarning = 1;
        lcd->LcdClear();
        sprintf(buff, "Warning!");
        lcd->WriteStringXY(0, 5, buff);

        if(millis() - prevWarningTime > 500)
        {
            prevWarningTime = millis();
            lcd->backLightState = !(lcd->backLightState);
        }
    }
    else
    {
        lcd->backLightWarning = 0;
        sprintf(buff, "%.1fC ", temp);
        lcd->WriteStringXY(0, 5, buff);

        sprintf(buff, "%.1f%% ", humid);
        lcd->WriteStringXY(0, 11, buff);
    }
    
    std::cout << temp << std::endl;
}
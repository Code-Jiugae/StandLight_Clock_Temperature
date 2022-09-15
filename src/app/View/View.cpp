#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    char buff[30];
    int state = 0;
    sprintf(buff, "sw:%d", state);
    lcd->WriteStringXY(0, 0, buff);
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
    this->lcd = lcd;
}

View::~View()
{
}

void View::setState(int state)
{
    lightState = state;
    char buff[30];
    sprintf(buff, "sw:%d", state);
    lcd->WriteStringXY(0, 0, buff);
}

void View::lightView()
{
    switch (lightState)
    {
    case LIGHT_OFF:
        lightOff();
        break;

    case LIGHT_1:
        lightOn_1();
        break;
    case LIGHT_2:
        lightOn_2();
        break;
    case LIGHT_3:
        lightOn_3();
        break;
    case LIGHT_4:
        lightOn_4();
        break;
    case LIGHT_5:
        lightOn_5();
        break;
    }
}

void View::lightOn_1()
{
    lcd->backLightOn();
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    lcd->backLightOff();
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}
#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include <time.h>

int main()
{
    std::cout << "Hello World!" << std::endl;
    time_t timeSec;
    struct tm *timeData;

    ClockCheck clockCheck;
    Button modeButton(27);
    Button powerButton(28);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));

    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);

    Service service(&view);
    ClockService clockService(&clockView);

    Controller control(&service, &clockService);
    Listener listener(&modeButton, &powerButton, &control, &clockCheck);

    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(50);
    }

    return 0;
}
#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "wiringPi.h"
#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"

class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    ClockCheck *clockCheck;
    Controller *controller;
    DHT11 *dht11;

public:
    Listener(Button *modebutton, Button *powerButton, Controller *control, ClockCheck *clock, DHT11 *dht11);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT11.h"
#include "TempHumidService.h"

class Controller
{
private:
    int lightState;
    Service *service;
    ClockService *clockService;
    TempHumidService *tempHumidService;

public:
    Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
};

#endif /* __CONTROLLER_H__ */
#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once

#include "DHT11.h"
#include "TempHumidView.h"

class TempHumidService
{

private:
    TempHumidView *tempHumidView;

public:
    TempHumidService(TempHumidView *tempHumidView);
    ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
};

#endif
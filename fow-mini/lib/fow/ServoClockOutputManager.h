/*
    Copyright (c) 2017-2018 Declan Freeman-Gleason. All rights reserved.

    This file is part of Ferries Over Winslow.

    Ferries Over Winslow is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Ferries Over Winslow is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this Ferries Over Winslow.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef IS_SERVO_CLOCK

#ifndef ServoClockOutputManager_h
#define ServoClockOutputManager_h

#include <functional>
#include "FerryHelper.h"
#include "OutputManagerInterface.h"
#include <Wire.h>
#include "PercentageServo.h"

class ServoClockOutputManager : public OutputManagerInterface {
  public:
    ServoClockOutputManager();

    void update(std::function<DataManager::FerryData (int)> dataSupplier);
    void calibrate();
  private:
    const int servoMaxPosition = 170;
    const int servoMinPosition = 10;
    const int lightIntensity = 5;
    const int dockLightIntensity = 255;
    const int departingDockLightPin = 2;
    const int arrivingDockLightPin = 15;

    void updateLightMode(FerryHelper::Modes mode);
    void updateOutput(DataManager::FerryData data, PercentageServo* servo, FerryHelper* lights, int* departingDockLightVal, int* arrivingDockLightVal);

    PercentageServo primaryServo = PercentageServo(servoMinPosition, servoMaxPosition, false);
    PercentageServo secondaryServo = PercentageServo(servoMinPosition, servoMaxPosition, false);
    FerryHelper* primaryLights;
    FerryHelper* secondaryLights;
    OutputManagerInterface::States state = OutputManagerInterface::States::UNCALIBRATED;
};

#endif

#endif

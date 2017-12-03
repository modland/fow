/*
    Copyright (c) 2017 Declan Freeman-Gleason. All rights reserved.

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

#ifndef DataManager_h
#define DataManager_h

#include "ConnectionManager.h"

class DataManager {
  public:
    DataManager(ConnectionManager* conn);

    long refreshRate = 5000; // in milliseconds

    void update();
    double getProgress();
  private:
    unsigned long lastUpdated = 0;
    double startProgress;
    double endProgress;

    void processResponse(String resp);

    ConnectionManager* connection;
};

#endif

// wykonanie zapytań do zasilacza
auto voltage = hvDevice->getVoltage(channelData->noOfHVChannel);
auto monitoredVoltage = hvDevice->monitorVoltage(channelData->noOfHVChannel);
auto monitoredCurrent = hvDevice->monitorCurrent(channelData->noOfHVChannel);

// aktualizacja przesyłanej do systemu WinCC OA struktury
channelData->highVoltage = voltage;
channelData->highVoltageMonitored = monitoredVoltage;
channelData->currentMonitored = monitoredCurrent;
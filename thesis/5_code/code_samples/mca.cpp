// mcaRefreshIntervals to kontener zawierający odcinki czasu, 
// na jakie podzielny został czas oczekiwania na zakończenie pomiaru
for(const auto& currentRefreshInterval : mcaRefreshIntervals)
{
    // oczekiwanie na sygnał STOP przez currentRefreshInterval milisekund
    waitStatus = GGSS_SIG_WAIT_MSEC(m_sigSTOP, currentRefreshInterval);
    if(waitStatus) // sygnał przechwycony - działanie GGSS zostaje przerwane
    {
        break;
    }
    else if(shouldRefreshMca) // sygnał nie przechwycony
    {
        // przeniesienie danych zawartych w buforze MCA do pamięci RAM
        boost::recursive_mutex::scoped_lock lk(_ggss_mutex);
        ChannelData& channelData = *m_GetChannel(channel);
        MCB& mcbForChannel = m_GetMCB(channelData.nameOfMcb);
        mcbForChannel.GetData();
    }
}

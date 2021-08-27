for(ChannelDatas::iterator i = m_ChannelDataHandlers.begin(); 
    i != m_ChannelDataHandlers.end(); 
    ++i)
{
    i->second->highVoltage = 0.0;
}
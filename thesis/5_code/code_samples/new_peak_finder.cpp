boost::optional<unsigned> peakIndex{boost::none};
boost::optional<unsigned> peakValue{boost::none};
std::vector<double> foundPeaks{};
for(size_t i{fitParams.lowerRange}; i < fitParams.upperRange; ++i)
{
    if(smoothData.at(i) > meanInRange)
    {
        if(peakValue == boost::none || smoothData.at(i) > peakValue)
        {
            peakValue = smoothData.at(i);
            peakIndex = i;
        }
    }
    else if(smoothData.at(i) < meanInRange && peakIndex != boost::none)
    {
        foundPeaks.push_back(peakIndex.value());
        peakIndex = boost::none;
        peakValue = boost::none;
    }
}
if(peakIndex != boost::none)
{
    foundPeaks.push_back(peakIndex.value());
}
return foundPeaks.empty() ? DEFAULT_PEAK_POSITION : foundPeaks.back();
void initializeArgonGaussFit(const std::vector<double>& data, FitParams& parameters)
{
    std::unique_ptr<PeakFinder> peakFinder{ new BaselinePeakFinderWithSmoothing() };
    parameters.startParams["pp0"] = peakFinder->find(data, parameters);
    parameters.startParams["w0"] = 0.21 * parameters.startParams["pp0"];
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    parameters.startParams["a0"] = 0.8 * sum;
}
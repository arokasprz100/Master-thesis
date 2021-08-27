struct CaenHVParams
{
public:
    CaenHVParams() : ramp(0), maxError(3)
    {
        for(unsigned i = 0; i < 4; ++i)
        {
            a[i] = 1.0;
            b[i] = 0.0;
        }
    }
    double ramp;
    double maxError;
    double a[4];
    double b[4];
};

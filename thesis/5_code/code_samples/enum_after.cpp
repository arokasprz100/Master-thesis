enum class SeverityLevel : char
{
    trace = 0, audit = 1, debug = 2, info = 3,
    warning = 4, error = 5, fatal = 6
};

// przykład wykorzystania: konieczne zastosowanie jawnej konwersji do 
// typu całkowitoliczbowego (za pomocą static_cast)
const SeverityLevel& severityLevel = manip.get();
stream << severityLevelStrings[static_cast<int>(severityLevel)];


enum SeverityLevel : char
{
    trace, audit, debug, info,
    warning, error, fatal
};

// przykład wykorzystania: niejawna konwersja do wartości całkowitoliczbowej 
// w celu użycia jako indeks tablicy
SeverityLevel level = manip.get();
stream << severityLevelStrings[level];
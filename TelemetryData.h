#ifndef H_TELEMETRY_DATA
#define H_TELEMETRY_DATA


class TelemetryData
{
    //The ID of data when sent in user data or when stored in an array of telemetry data
    //The enum makes sure that there is no overlap while the 'MAX' member keeps track of the
    //'size' of the enum
    enum DataIndex
    {
        NO_DATA,
        ANALOG1,
        ANALOG2,
        LINK_QUALITY,
        enum_size //Used for defining the size of the enum when storing an array of values
    };
}

#endif

#ifndef H_TELEMETRY_DATA
#define H_TELEMETRY_DATA

#include <stdint.h>
#include <stdlib.h>


class TelemetryData
{
public:
    typedef uint32_t ValueType;

    static const uint8_t MAX_NAME_LEN = 32;

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


    TelemetryData();
    TelemetryData(const char* name, DataIndex dataIndex);
    TelemetryData(const TelemetryData& other);
    TelemetryData& operator=(const TelemetryData& other);

    ~TelemetryData();

    void setValue(ValueType value);
    const char* getName() const;
    ValueType getValue() const;
    DataIndex getDataIndex() const;

private:
    DataIndex dataIndex;

    char* name;
    ValueType value;
};

#endif

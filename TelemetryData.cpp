#include "TelemetryData.h"

#include <Arduino.h>
#include <string.h>

TelemetryData::TelemetryData()
{
    dataIndex = NO_DATA;

    name = new char[MAX_NAME_LEN];
    name = strcpy(name, "Placeholder");
}
TelemetryData::TelemetryData(const char* name, DataIndex dataIndex)
{
    //this->name = name;
    this->name = strcpy(this->name, name);
    this->dataIndex = dataIndex;
    this->value = 0;
}
TelemetryData::TelemetryData(const TelemetryData& other)
{ 
    *this = other;
}
TelemetryData& TelemetryData::operator=(const TelemetryData& other)
{
    this->name = new char[MAX_NAME_LEN];

    this->name = strcpy(this->name, other.name);

    this->dataIndex = other.dataIndex;
    this->value = other.value;

    return *this;
}
TelemetryData::~TelemetryData()
{
    delete[] name;
}

void TelemetryData::setValue(ValueType value)
{
    this->value = value;
}
const char* TelemetryData::getName() const
{
    return name;
}
TelemetryData::ValueType TelemetryData::getValue() const
{
    return value;
}
TelemetryData::DataIndex TelemetryData::getDataIndex() const
{
    return dataIndex;
}

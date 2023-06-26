#include "simulatorutils.h"

SimulatorUtils::SimulatorUtils(){}
void SimulatorUtils::SetTemperatureUnit(qint16 newTemperatureUnit){ this->temperatureUnit = newTemperatureUnit; }
void SimulatorUtils::SetPressureUnit(qint16 newPressureUnit){ this->pressureUnit = newPressureUnit; }
void SimulatorUtils::SetTemperatureValue(qint16 newTemperatureValue){ this->temperatureValue = newTemperatureValue; }
void SimulatorUtils::SetAngleValue(qint16 newAngleOfRotationValue){ this->angleOfRotationValue = newAngleOfRotationValue; }
void SimulatorUtils::SetHumidityValue(qint16 newHumidityValue){ this->humidityValue = newHumidityValue; }
void SimulatorUtils::SetPressureValue(qint16 newPressureValue){ this->pressureValue = newPressureValue; }
void SimulatorUtils::SetTheme(bool newThemeType){ this->themeType = newThemeType; }
void SimulatorUtils::SetTemporaryValue(qint16 newTemporaryValue) { this->temporaryValue = newTemporaryValue; }
void SimulatorUtils::SetPowerState(bool newPowerState){ this->powerState = newPowerState; }
void SimulatorUtils::SetTemperatureUnitSoftware(qint16 newTemperatureUnitSoftware){ this->temperatureUnitSoftware = newTemperatureUnitSoftware; }
void SimulatorUtils::SetPressureUnitSoftware(qint16 newPressureUnitSoftware){ this->pressureUnitSoftware = newPressureUnitSoftware; }

qint16 SimulatorUtils::GetTemperatureUnit(){ return this->temperatureUnit; }
qint16 SimulatorUtils::GetPressureUnit(){ return this->pressureUnit; }
qint16 SimulatorUtils::GetTemperatureValue(){ return this->temperatureValue; }
qint16 SimulatorUtils::GetAngleValue(){ return this->angleOfRotationValue; }
qint16 SimulatorUtils::GetHumidityValue(){ return this->humidityValue; }
qint16 SimulatorUtils::GetPressureValue(){ return this->pressureValue; }
qint16 SimulatorUtils::GetTemporaryValue(){ return this->temporaryValue; }
qint16 SimulatorUtils::GetTemperatureUnitSoftware(){ return this->temperatureUnitSoftware;                                                    }
qint16 SimulatorUtils::GetPressureUnitSoftware(){ return this->pressureUnitSoftware ;}
bool SimulatorUtils::GetTheme(){ return this->themeType; }
bool SimulatorUtils::GetPowerState() { return this->powerState; }

void SimulatorUtils::CheckPossibleTemperatureValue()
{
    switch(GetTemperatureUnit())
    {
        case CELSIUS:
            if(GetTemperatureValue() >= Constants::maximumTemperatureInCelsius) { SetTemperatureValue(Constants::maximumTemperatureInCelsius); }
            if(GetTemperatureValue() <= Constants::minimumTemperatureInCelsius) { SetTemperatureValue(Constants::minimumTemperatureInCelsius); }
            break;
        case FHARENHEIT:
            if(GetTemperatureValue() >= Constants::maximumTemperatureInFharenheit) { SetTemperatureValue(Constants::maximumTemperatureInFharenheit); }
            if(GetTemperatureValue() <= Constants::minimumTemperatureInFharenheit) { SetTemperatureValue(Constants::minimumTemperatureInFharenheit); }
            break;
        case KELVIN:
            if(GetTemperatureValue() >= Constants::maximumTemperatureInKelvins) { SetTemperatureValue(Constants::maximumTemperatureInKelvins); }
            if(GetTemperatureValue() <= Constants::minimumTemperatureInKelvins) { SetTemperatureValue(Constants::minimumTemperatureInKelvins); }
            break;
    }
}

void SimulatorUtils::CheckPossiblePressureValue()
{
    switch(GetPressureUnit())
    {
        case KILOPASKALS:
            if(GetPressureValue() >= Constants::maximumPressureInKilopaskals) { SetPressureValue(Constants::maximumPressureInKilopaskals); }
            if(GetPressureValue() <= Constants::minimumPressureInKilopaskals) { SetPressureValue(Constants::minimumPressureInKilopaskals); }
            break;
        case MMHG:
            if(GetPressureValue() >= Constants::maximumPressureInMMHg) { SetPressureValue(Constants::maximumPressureInMMHg); }
            if(GetPressureValue() <= Constants::minimumPressureInMMHg) { SetPressureValue(Constants::minimumPressureInMMHg); }
            break;
    }
}

void SimulatorUtils::CheckPossibleHumidityValue()
{
    if(GetHumidityValue() >= Constants::maximumHumidityValue) { SetHumidityValue(Constants::maximumHumidityValue); }
    if(GetHumidityValue() <= Constants::minimumHumidityValue) { SetHumidityValue(Constants::minimumHumidityValue); }
}

void SimulatorUtils::CheckPossibleAngleValue()
{
    if(GetAngleValue() >= Constants::maximumAngleValue) { SetAngleValue(Constants::maximumAngleValue); }
    if(GetAngleValue() <= Constants::minimumAngleValue) { SetAngleValue(Constants::minimumAngleValue); }
}

qint16 UnitConverter::ConvertCelsiusToFharenheit(qint16 valueInCelsius){ return (valueInCelsius * 1.8) + 32; }
qint16 UnitConverter::ConvertCelsiusToKelvins(qint16 valueInCelsius){ return valueInCelsius + 273; }
qint16 UnitConverter::ConvertFharenheitToCelsius(qint16 valueInFharenheit){ return (valueInFharenheit - 32) / 1.8; }
qint16 UnitConverter::ConvertFharenheitToKelvins(qint16 valueInFharenheit){ return /*valueInFharenheit + 459.67) * 5 / 9;*/
                                                                                    (valueInFharenheit - 32) * 5 / 9 + 273; }
qint16 UnitConverter::ConvertKelvinsToCelsius(qint16 valueInKelvins){ return valueInKelvins - 273; }
qint16 UnitConverter::ConvertKelvinsToFharenheit(qint16 valueInKelvins){ return /*valueInKelvins * 9 / 5 - 459.67;*/
            (valueInKelvins - 273) * 9 / 5 + 32 ;}
qint16 UnitConverter::ConvertMMHGToKilopaskals(qint16 ValueInMMofMercury){ return ValueInMMofMercury * 0.133322; }
qint16 UnitConverter::ConvertKilopaskalsToMMHG(qint16 ValueInKilopaskals){ return ValueInKilopaskals / 0.133322; }

QSettings fileWithParameters("ConfigurableFileWithSimulatorParameters", QSettings::IniFormat);
QSettings fileWithTCPSettings("ConfigurableFileWithParametersForNetworking", QSettings::IniFormat);

void SimulatorUtils::ReadParametersFromFile()
{
    SetTemperatureValue(fileWithParameters.value("TemperatureValue").toInt());
    SetTemperatureUnit(fileWithParameters.value("TemperatureUnit").toInt());
    SetPressureValue(fileWithParameters.value("PressureValue").toInt());
    SetPressureUnit(fileWithParameters.value("PressureUnit").toInt());
    SetHumidityValue(fileWithParameters.value("HumidityValue").toInt());
    SetAngleValue(fileWithParameters.value("AngleValue").toInt());
}

void SimulatorUtils::WriteParametersInFile()
{
    fileWithParameters.setValue("TemperatureValue", GetTemperatureValue());
    fileWithParameters.setValue("TemperatureUnit", GetTemperatureUnit());
    fileWithParameters.setValue("PressureValue", GetPressureValue());
    fileWithParameters.setValue("PressureUnit", GetPressureUnit());
    fileWithParameters.setValue("HumidityValue", GetHumidityValue());
    fileWithParameters.setValue("AngleValue", GetAngleValue());
}

void NetworkController::ReadTCPSettingsFromFile()
{
    SetRequestInterval(fileWithTCPSettings.value("RequestInterval").toInt());
    SetHOST(fileWithTCPSettings.value("HOST").toString());
    SetPORT(fileWithTCPSettings.value("PORT").toInt());
}
qint16 NetworkController::GetRequestInterval(){ return this->requestInterval; }
qint16 NetworkController::GetPORT(){ return this->PORT; }
QString NetworkController::GetHOST(){ return this->HOST; }
void NetworkController::SetRequestInterval(qint16 newRequestInterval){ this->requestInterval = newRequestInterval; }
void NetworkController::SetHOST(QString newHOST){ this->HOST = newHOST; }
void NetworkController::SetPORT(qint16 newPORT){ this->PORT = newPORT; }

qint16 RequestFromSoftwareToSimulator::GetTypeOfRequest(){ return this->typeOfRequest; }
qint16 ResponseFromSimulatorToSoftware::GetTemperatureValue(){ return this->temperatureValue; }
qint16 ResponseFromSimulatorToSoftware::GetPressureValue(){ return this->pressureValue; }
qint16 ResponseFromSimulatorToSoftware::GetHumidityValue(){ return this->humidityValue; }
qint16 ResponseFromSimulatorToSoftware::GetPressureUnit(){ return this->pressureUnit; }
qint16 ResponseFromSimulatorToSoftware::GetTemperatureUnit(){ return this->temperatureUnit; }
qint16 ResponseFromSimulatorToSoftware::GetAngleValue(){ return this->angleValue; }
qint16 ResponseFromSimulatorToSoftware::GetThemeType(){ return this->themeType; }













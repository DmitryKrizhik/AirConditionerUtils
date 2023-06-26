#ifndef SIMULATORUTILS_H
#define SIMULATORUTILS_H

#include "SimulatorUtils_global.h"
#include <iostream>
#include "QDebug"
#include <QtGui/QTouchEvent>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomAttr>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <thread>
#include <string>
#include <QSettings>


enum ResolutionType
{
    RESOLUTION800x600,
    RESOLUTION1024x768
};
enum ThemeType
{
    LIGHTTHEME,
    DARKTHEME
};
enum PressureUnit
{
    KILOPASKALS,
    MMHG
};
enum TemperatureUnit
{
    CELSIUS,
    KELVIN,
    FHARENHEIT
};

enum Numbers
{
    ZERO,
    ONE
};

enum PowerState
{
    OFF,
    ON
};

enum Networking
{
    GETDATA,
    STARTSIMULATING,
    STOPSIMULATING
};

struct SIMULATORUTILS_EXPORT SimulatorUtils
{
    SimulatorUtils();

    void SetTemperatureUnit(qint16 newTemperatureUnit);
    void SetPressureUnit(qint16 newPressureUnit);
    void SetTemperatureValue(qint16 newTemperatureValue);
    void SetAngleValue(qint16 newAngleOfRotationValue);
    void SetHumidityValue(qint16 newHumidityValue);
    void SetPressureValue(qint16 newPressureValue);
    void SetTemporaryValue(qint16 newTemporaryValue);
    void SetTheme(bool newThemeType);
    void SetPowerState(bool newPowerState);
    void SetHOST(QString newHOST);
    void SetPORT(qint16 newPORT);
    void SetPressureUnitSoftware(qint16 newPressureUnitSoftware);
    void SetTemperatureUnitSoftware(qint16 newTemperatureUnitSoftware);

    qint16 GetTemperatureUnit();
    qint16 GetPressureUnit();
    qint16 GetTemperatureValue();
    qint16 GetAngleValue();
    qint16 GetHumidityValue();
    qint16 GetPressureValue();
    qint16 GetTemporaryValue();
    qint16 GetTemperatureUnitSoftware();
    qint16 GetPressureUnitSoftware();
    bool GetTheme();
    bool GetPowerState();

    void CheckPossibleTemperatureValue();
    void CheckPossiblePressureValue();
    void CheckPossibleHumidityValue();
    void CheckPossibleAngleValue();
    void ReadParametersFromFile();
    void WriteParametersInFile();

private:
    qint16 temperatureUnit;
    qint16 pressureUnit;
    qint16 pressureUnitSoftware;
    qint16 temperatureUnitSoftware;
    bool themeType;
    bool powerState;
    qint16 temperatureValue;
    qint16 angleOfRotationValue;
    qint16 humidityValue;
    qint16 pressureValue;
    qint16 temporaryValue;
};

struct NetworkController
{

    void SetHOST(QString newHOST);
    void SetPORT(qint16 newPORT);
    QString GetHOST();
    qint16 GetPORT();
    qint16 GetRequestInterval();
    void SendResponseFromSimulator();
    void SendRequestFromSoftware();
    void ReadTCPSettingsFromFile();
    void SetRequestInterval(qint16 newRequestInterval);
    QTcpServer server;
    QTimer timer;
    QTcpSocket socket;
private:
    QString HOST;
    qint16 PORT;
    qint16 requestInterval;
};

struct UnitConverter
{
    qint16 ConvertCelsiusToFharenheit(qint16 TemperatureValue);
    qint16 ConvertCelsiusToKelvins(qint16 TemperatureValue);
    qint16 ConvertFharenheitToCelsius(qint16 TemperatureValue);
    qint16 ConvertFharenheitToKelvins(qint16 TemperatureValue);
    qint16 ConvertKelvinsToCelsius(qint16 TemperatureValue);
    qint16 ConvertKelvinsToFharenheit(qint16 TemperatureValue);
    qint16 ConvertMMHGToKilopaskals(qint16 PressureValue);
    qint16 ConvertKilopaskalsToMMHG(qint16 PressureValue);
};

struct RequestFromSoftwareToSimulator
{
     qint16 typeOfRequest;
     qint16 GetTypeOfRequest();
};
struct ResponseFromSimulatorToSoftware {

    void SetTemperatureValue(qint16 newTemperatureValue);
    void SetPressureValue(qint16 newPressureValue);
    void SetHumidityValue(qint16 newHumidityValue);
    void SetPressureUnit(qint16 newPressureUnit);
    void SetTemperatureUnit(qint16 newTemperatureUnit);
    void SetAngleValue(qint16 newAngleValue);
    qint16 GetTemperatureValue();
    qint16 GetPressureValue();
    qint16 GetHumidityValue();
    qint16 GetPressureUnit();
    qint16 GetTemperatureUnit();
    qint16 GetAngleValue();
    qint16 GetThemeType();
private:
    qint16 temperatureValue;
    qint16 pressureValue;
    qint16 humidityValue;
    qint16 pressureUnit;
    qint16 temperatureUnit;
    qint16 angleValue;
    bool themeType;
};

struct Constants
{
    static const qint16 rValueWindowLightTheme = 180;
    static const qint16 gValueWindowLightTheme = 186;
    static const qint16 bValueWindowLightTheme = 207;
    static const qint16 rValueButtonLightTheme = 157;
    static const qint16 gValueButtonLightTheme = 164;
    static const qint16 bValueButtonLightTheme = 199;
    static const qint16 rValueWindowText = 242;
    static const qint16 gValueWindowText = 245;
    static const qint16 bValueWindowText = 252;
    static const qint16 rValueButtonText = 242;
    static const qint16 gValueButtonText = 245;
    static const qint16 bValueButtonText = 252;
    static const qint16 rValueWindowDarkTheme = 99;
    static const qint16 gValueWindowDarkTheme = 107;
    static const qint16 bValueWindowDarkTheme = 133;
    static const qint16 rValueButtonDarkTheme = 99;
    static const qint16 gValueButtonDarkTheme = 107;
    static const qint16 bValueButtonDarkTheme = 133;
    static const qint16 horizontalSmallResolitionValue = 800;
    static const qint16 verticalSmallResolitionValue = 600;
    static const qint16 horizontalBigResolitionValue = 1024;
    static const qint16 verticalBigResolitionValue = 768;
    static const qint16 minimumTemperatureInFharenheit = 50;
    static const qint16 maximumTemperatureInFharenheit = 95;
    static const qint16 minimumTemperatureInCelsius = 10;
    static const qint16 maximumTemperatureInCelsius = 35;
    static const qint16 minimumTemperatureInKelvins = 283;
    static const qint16 maximumTemperatureInKelvins = 308;
    static const qint16 minimumPressureInMMHg = 525;
    static const qint16 maximumPressureInMMHg = 900;
    static const qint16 minimumPressureInKilopaskals = 70;
    static const qint16 maximumPressureInKilopaskals = 120;
    static const qint16 maximumHumidityValue = 80;
    static const qint16 minimumHumidityValue = 30;
    static const qint16 minimumAngleValue = -45;
    static const qint16 maximumAngleValue = 45;
};

static SimulatorUtils SimUtils;
static UnitConverter Converter;
static NetworkController Controller;
#endif

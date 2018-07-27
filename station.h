#ifndef STATION_H
#define STATION_H
#include <QString>
#include<QList>
#include<QByteArray>
#include<QProcess>
#include <QDebug>
#include<QTime>
#include<QString>
class  Station
{
public:
    QString stationvalues, direcao,id, luminosidade, temperatura,pressao, altitude,umidade,velocidade, pluviometro;
    QStringList listOfData;
    void processData(),getWeatherValues();

};

#endif // STATION_H

#include "station.h"
#include <typeinfo>
#include <QDebug>
#include <QString>
void Station::processData(){
    getWeatherValues();
    if(stationvalues.contains('@')){
        stationvalues.remove(stationvalues.indexOf('@'),1);
        stationvalues.remove(stationvalues.indexOf('\n'),1);


    }
    listOfData = stationvalues.split('|');
    id= listOfData[0];
    luminosidade = listOfData[1];
    temperatura = listOfData[2];
    pressao = listOfData[3];
    altitude = listOfData[4];
    umidade = listOfData[5];
    velocidade = listOfData[6];
    pluviometro = listOfData[7];
    direcao =  listOfData[8];

}
void Station::getWeatherValues()
{

    QProcess* process = new QProcess() ;


    process->setReadChannel(QProcess::StandardOutput);

    process->start("mosquitto_sub -t weatherstation");
    for(int i=0; i<2;i++){

        process->waitForStarted();
        process->canReadLine();
        process->state();
        process->exitCode();
        process->waitForReadyRead(-1);
        //QByteArray teste = process->readAllStandardOutput();
        stationvalues = process->readAllStandardOutput();



    }

}

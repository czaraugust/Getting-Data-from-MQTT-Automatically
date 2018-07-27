#include <QCoreApplication>
#include <QDebug>
#include <station.h>
int main()
{
Station stn =  Station();

    while(1){


        stn.processData();
        qDebug() <<  stn.id << stn.luminosidade << stn.temperatura << stn.pressao << stn.altitude << stn.umidade << stn.velocidade << stn.pluviometro << stn.direcao;


    }


}

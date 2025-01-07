//
// Created by jacob on 13/11/2024.
//

#include <iostream>
#include "Dron.h"
#include "cmath"




double euclideanDistance(double a1, double a2, double a3){
    return sqrt(pow(a1,2)+pow(a2,2)+pow(a3,2));
}


Dron::Dron(igvCamara c) {
    alfa=M_PI/2;
    beta=M_PI;
    puntVision= *(new igvPunto3D(c.getR().getX(),c.getR().getY(),c.getR().getZ()));
    posDron=*(new igvPunto3D(c.getP0().getX(),c.getP0().getY(),c.getP0().getZ()));
    vArriba=*(new igvPunto3D(c.getV().getX(),c.getV().getY(),c.getV().getZ()));

    double a1=posDron[0]-puntVision[0];
    double a2=posDron[1]-puntVision[1];
    double a3=posDron[2]-puntVision[2];

    campoDeVision=euclideanDistance(a1,a2,a3);

    incAngulo=0.1;
}

void Dron::avanza() {

    double var0=(puntVision[0]-posDron[0]);
    double var1=(puntVision[1]-posDron[1]);
    double var2=(puntVision[2]-posDron[2]);
    posDron[0]+= var0;
    puntVision[0]+= var0;

    posDron[1]+= var1;
    puntVision[1]+= var1;

    posDron[2]+= var2;
    puntVision[2]+= var2;

}

void Dron::retrocede() {



    double var0=(puntVision[0]-posDron[0]);
    double var1=(puntVision[1]-posDron[1]);
    double var2=(puntVision[2]-posDron[2]);
    posDron[0]-= var0;
    puntVision[0]-= var0;

    posDron[1]-= var1;
    puntVision[1]-= var1;

    posDron[2]-= var2;
    puntVision[2]-= var2;


}


void Dron::miraArriba() {


    alfa-=incAngulo;
    puntVision[0]=(campoDeVision*sin(alfa)*cos(beta))+posDron[0];
    puntVision[1]=(campoDeVision*cos(alfa))+posDron[1];
    puntVision[2]=(campoDeVision*sin(alfa)*sin(beta))+posDron[2];

}

void Dron::miraAbajo() {

    alfa+=incAngulo;
    puntVision[0]=(campoDeVision*sin(alfa)*cos(beta))+posDron[0];
    puntVision[1]=(campoDeVision*cos(alfa))+posDron[1];
    puntVision[2]=(campoDeVision*sin(alfa)*sin(beta))+posDron[2];


}

void Dron::miraIzquierda() {


    beta-=incAngulo;
    puntVision[0]=(campoDeVision*sin(alfa)*cos(beta))+posDron[0];
    puntVision[1]=(campoDeVision*cos(alfa))+posDron[1];
    puntVision[2]=(campoDeVision*sin(alfa)*sin(beta))+posDron[2];


}

void Dron::miraDerecha() {



    beta+=incAngulo;
    puntVision[0]=(campoDeVision*sin(alfa)*cos(beta))+posDron[0];
    puntVision[1]=(campoDeVision*cos(alfa))+posDron[1];
    puntVision[2]=(campoDeVision*sin(alfa)*sin(beta))+posDron[2];


}



#pragma once
//El TSE es el sujeto (subject)
class ObserverTSE;
#include <iostream>
#include <string>

using namespace std;

class TSE {
private:
	ObserverTSE * partidosPoliticos[10];// 10 subscriptores
	int can;
	int tam;
	string dato;//Esto es lo que se envia
public:
	TSE();
	void Subscribir(ObserverTSE *);
	void setDato(string);
	string getDato();
	void Notificar();
};

/*
La clase sujeto es : 
Una clase con informacion que se desea conocer por parte de los subscriptores
Se encarga de notificar a la clase observadora 


*/
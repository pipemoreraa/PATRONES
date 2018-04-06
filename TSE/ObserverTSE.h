#pragma once
//El observer TSE el es el observador del TSE 
//CLASE ABSTRACTA
class TSE;
#include <iostream>
using namespace std;
class ObserverTSE {
protected:
	TSE * partido;
	TSE * getTSE();
public:
	ObserverTSE(TSE *);
	virtual void Actualizar() = 0;
};
/*
La clase observador es :
Una clase abstracta que se encarga de actualizar a los subscriptores


*/
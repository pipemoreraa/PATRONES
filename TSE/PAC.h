#pragma once
#include"TSE.h"
#include "ObserverTSE.h"
#include <string>

class PAC : public ObserverTSE {
public:
	PAC(TSE * partido) : ObserverTSE(partido) {}
	void Actualizar() {
		string dato = getTSE()->getDato();
		cout << "Para PAC Dato: " << dato << endl;
	}
};
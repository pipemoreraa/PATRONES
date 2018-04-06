#pragma once
#include"TSE.h"
#include "ObserverTSE.h"
#include <string>

class RN : public ObserverTSE {
public:
	RN(TSE * partido) : ObserverTSE(partido) {}
	void Actualizar() {
		string dato = getTSE()->getDato();
		cout << "Para el RN Dato: " << dato << endl;
	}
};
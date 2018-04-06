#include"ObserverTSE.h"
#include "TSE.h"

TSE::TSE()
{
	can = 0;
	tam = 10;
	for (int i = 0; i < tam; i++) {
		partidosPoliticos[i] = NULL;
	}
}

void TSE::Subscribir(ObserverTSE * nuevoPartido)
{
	/**/
	partidosPoliticos[can++] = nuevoPartido;
}

void TSE::setDato(string dato)
{
	/**/
	this->dato = dato;
	Notificar();
}

string TSE::getDato()
{
	/**/
	return dato;
}

void TSE::Notificar()
{
	/**/
	for (int i = 0; i < can; i++) {
		partidosPoliticos[i]->Actualizar();
	}
}

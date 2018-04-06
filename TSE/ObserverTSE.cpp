#include "TSE.h"
#include "ObserverTSE.h"


TSE * ObserverTSE::getTSE()
{
	return partido;
}

ObserverTSE::ObserverTSE(TSE * partidoSubscrito)
{
	partido = partidoSubscrito;
	partido->Subscribir(this);
}

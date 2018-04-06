#include <iostream>

using namespace std;

#include "TSE.h"
#include "ObserverTSE.h"
#include "PAC.h"
#include "RN.h"
int main() {
	TSE datos;
	PAC dato1(&datos);
	RN dato2(&datos);
	datos.setDato("10%");
	cout << endl;
	cout << endl;
	datos.setDato("20%");
	//datos.Notificar();
	cout << endl;

	getchar();
	return 0;
}
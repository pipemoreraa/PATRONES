#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ComponenteVisual {
public:
	virtual void Dibujar() = 0;
};

class Decorador : public ComponenteVisual {
private:
	ComponenteVisual * _componenteVisual;
public:
	Decorador(ComponenteVisual * componenteVisual) : _componenteVisual(componenteVisual){}
	virtual void Dibujar() = 0;
};

class Auto : public ComponenteVisual {
private:
	string marca;
	string modelo;
	float precio;
public:
	Auto(string _marca, string _modelo, float _precio) : marca(_marca), modelo(_modelo), precio(_precio) {}
	void Dibujar() {cout << "El " << marca << " cuenta con :";}
	string toString() {
		stringstream out;
		out << "|AUTO| \nMarca: " << marca << "\nModelo: " << modelo << "\nPrecio: " << precio;
		out << endl;
		return out.str();
	}
};

class DecoradorMP3 : public Decorador {
private:
	Auto * _Auto;
public:
	DecoradorMP3(ComponenteVisual *  componenteVisual) : Decorador(componenteVisual){}
	void Dibujar() {cout << " Mp3 |";}
};

class DecoradorAireAcondicionado :public Decorador {
public:
	DecoradorAireAcondicionado(ComponenteVisual * componenteVisual) : Decorador(componenteVisual){}
	void Dibujar() {cout << " Aire Acondicionado |";}
};

class DecoradorArosLujo : public Decorador {
public:
	DecoradorArosLujo(ComponenteVisual * componenteVisual) : Decorador(componenteVisual) {}
	void Dibujar() { cout << " Aros de lujo |"; }
};

class DecoradorAsientosCuero : public Decorador {
public:
	DecoradorAsientosCuero(ComponenteVisual * componenteVisual) : Decorador(componenteVisual) {}
	void Dibujar() { cout << " Asientos de cuero |"; }
};


int main() {
	Auto * Toyota = new Auto("TOYOTA", "LEXUS", 25000.312);
	cout << Toyota->toString();
	Toyota->Dibujar();
	
	DecoradorMP3 * _decoradorMp3 = new DecoradorMP3(Toyota);
	_decoradorMp3->Dibujar();
	
	DecoradorAireAcondicionado * _decoradorAire = new DecoradorAireAcondicionado(_decoradorMp3);
	_decoradorAire->Dibujar();

	DecoradorArosLujo * _arosLujo = new DecoradorArosLujo(_decoradorAire);
	_arosLujo->Dibujar();
	
	DecoradorAsientosCuero * _asientoCuero = new DecoradorAsientosCuero(_arosLujo);
	_asientoCuero->Dibujar();
	
	cout << endl << endl;

	Auto * Audi = new Auto("Audi", "A4" , 65000.313);
	cout << Audi->toString();
	Audi->Dibujar();

	DecoradorMP3 * _decoradorMp3A = new DecoradorMP3(Audi);
	_decoradorMp3A->Dibujar();
	
	DecoradorAireAcondicionado * _decoradorAireA = new DecoradorAireAcondicionado(_decoradorMp3A);
	_decoradorAireA->Dibujar();
	
	DecoradorArosLujo * _arosLujoA = new DecoradorArosLujo(_decoradorAireA);
	_arosLujoA->Dibujar();
	
	DecoradorAsientosCuero * _asientoCueroA = new DecoradorAsientosCuero(_arosLujoA);
	_asientoCueroA->Dibujar();
	
	cout << endl << endl;

	Auto * Volvo = new Auto("Volvo", "XC90", 100000.0001);
	cout << Volvo->toString();
	Volvo->Dibujar();
	DecoradorMP3 * _decoradorMp3B = new DecoradorMP3(Volvo);
	_decoradorMp3B->Dibujar();

	DecoradorAireAcondicionado * _decoradorAireB = new DecoradorAireAcondicionado(_decoradorMp3B);
	_decoradorAireB->Dibujar();

	DecoradorArosLujo * _arosLujoB = new DecoradorArosLujo(_decoradorAireB);
	_arosLujoB->Dibujar();

	//DecoradorAsientosCuero * _asientoCueroB = new DecoradorAsientosCuero(_arosLujoB);
	//_asientoCueroB->Dibujar();
	cout << endl << endl;
	cout << "eni no estuvo aqui" << endl;
	getchar();
	return 0;
}
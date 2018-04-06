#include <iostream>
using namespace std;

class Plato {  //ComponenteVisual
public:
	virtual void PAN() = 0;
	virtual float Total() = 0;
};

class Ingrediente : public Plato {//Decorador
protected:
	Plato * ptrPlato;
public:
	Ingrediente(Plato * _ptrPlato) : ptrPlato(_ptrPlato) {};
	virtual void PAN() = 0;//Dibujar
	virtual float Total() = 0;
};

class Pizza : public Plato {
private:
	float precioBase;
	unsigned short int tamanno;
	bool lugar;
public:
	Pizza(unsigned short int _tamanno, bool _lugar) : precioBase(3000), tamanno(_tamanno), lugar(_lugar) {}
	string toString() {}
	void PAN() { cout << "La pizza lleva: " << endl; }
	float Total() { return precioBase; }
};

class Queso : public Ingrediente {
private:
	float precio;
public:
	Queso(Plato * ptrPlato) : Ingrediente(ptrPlato), precio(500) {}
	void PAN() { ptrPlato->PAN(); cout << "Soy un quesito 7u7r" << endl; }
	float Total() { return ptrPlato->Total() + precio; }
};

class Carne : public Ingrediente {
private:
	float precio;
	bool picante;
public:
	Carne(Plato * ptrPlato, bool _picante = false) : Ingrediente(ptrPlato), picante(_picante) {
		(picante) ? precio = 800 : precio = 500;
	}
	void PAN() { ptrPlato->PAN(); cout << "Soy carne 7u7r" << endl; }
	float Total() { return ptrPlato->Total() + precio; }
};

class Pinna : public Ingrediente {
private:
	float precio;
public:
	Pinna(Plato * ptrPlato) : Ingrediente(ptrPlato), precio(100) {}
	void PAN() { ptrPlato->PAN(); cout << "Soy pinna 7u7r" << endl; }
	float Total() { return ptrPlato->Total() + precio; }
};

int main() {
	Pizza * Hawaiiana = new Pizza(16, 1);
	Carne * carnita = new Carne(Hawaiiana, 1);
	carnita->PAN();
	cout << "Precio total: " << carnita->Total() << endl;
	Queso* quesito = new Queso(carnita);
	quesito->PAN();
	cout << "Precio total: "<< quesito->Total() << endl;
	getchar();
}
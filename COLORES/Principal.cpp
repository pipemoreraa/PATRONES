#include <iostream>
#include <Windows.h>
using namespace std;

class Pintura {
public:
	void SetColor(int ForgC)
	{
		WORD wColor;
		//This handle is needed to get the current background attribute

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		//csbi is used for wAttributes word

		if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
		{
			//To mask out all but the background attribute, and to add the color
			wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
			SetConsoleTextAttribute(hStdOut, wColor);
		}
		return;
	}
};

class ColorAbstracto {
public:
	virtual void Pintar() = 0;
};

class Lienzo : public ColorAbstracto {
	Pintura * ptr;
public:
	void Pintar() {
		ptr->SetColor(0);
		cout << "Color selecionado: " << endl;
	}
};

class Color : public ColorAbstracto {
protected:
	ColorAbstracto * _colorPtr;
public:
	Color(ColorAbstracto * colorPtr) : _colorPtr(colorPtr) {}
	virtual void Pintar() = 0;
};


class ColorRojo : public Color {
	Pintura * ptr;
public:
	ColorRojo(ColorAbstracto * colorPtr) :Color(colorPtr) {}
	void Pintar() {
		_colorPtr->Pintar();
		ptr->SetColor(4);
		cout << "*" << endl;
	}
};

class ColorVerde : public Color {
	Pintura * ptr;
public:
	ColorVerde(ColorAbstracto * colorPtr) :Color(colorPtr) {}
	void Pintar() {
		_colorPtr->Pintar();
		ptr->SetColor(2);
		cout << "*" << endl;
	}
};

class ColorAzul : public Color {
	Pintura * ptr;
public:
	ColorAzul(ColorAbstracto * colorPtr) :Color(colorPtr) {}
	void Pintar() {
		_colorPtr->Pintar();
		ptr->SetColor(1);
		cout << "*" << endl;
	}
};

int main() {
	system("color F0");
	ColorRojo * CR = new ColorRojo(new Lienzo());
	CR->Pintar();
	ColorVerde * CV = new ColorVerde(CR);
	CV->Pintar();
	ColorAzul * CA = new ColorAzul(CV);
	CA->Pintar();
	getchar();
	return 0;
}

/*
0 = Negro       8 = Gris
1 = Azul        9 = Azul claro
2 = Verde       A = Verde claro
3 = Aguamarina        B = Aguamarina claro
4 = Rojo        C = Rojo claro
5 = Púrpura     D = Púrpura claro
6 = Amarillo    E = Amarillo claro
7 = Blanco      F = Blanco brillante
*/
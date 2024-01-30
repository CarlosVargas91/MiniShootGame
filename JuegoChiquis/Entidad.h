#pragma once
enum Direccion
{
	Arriba,
	Abajo,
	Derecha,
	Izquierda
};
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int fila, columna;
	int ancho, alto;
	int c_filas, c_columnas;

public:
	int getX() { return x; }
	int getY() { return y; }
	int getDX() { return dx; }
	int getDY() { return dy; }
	int getFila() { return fila; }
	int getColumna() { return columna; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getNumFilas() { return c_filas; }
	int getNumColumnas() { return c_columnas; }
};
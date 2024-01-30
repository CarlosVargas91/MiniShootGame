#pragma once
#include "Entidad.h"
#include "Arreglo_BalaJugador.h"
#include <ctime>
using namespace System;

class Jugador : public Entidad
{
private:
	Arreglo_Bala_Jugador* balas;
	Direccion direccion_player;
	int vidas;

public:
	Jugador(int vidas)
	{
		x = 900;
		y = 590;
		this->vidas = vidas;
		c_columnas = 5;
		c_filas = 4;
		dx = dy = 11;
		columna = fila = 0;
		balas = new Arreglo_Bala_Jugador();
		direccion_player = Direccion::Izquierda;

	}
	~Jugador()
	{
		delete balas;
	}

	int GetVidas() { return vidas; }
	void setVidas(int v) { vidas = v; }
	void RestarVida() { vidas--; }
	void Mostrar(Graphics^g, Bitmap^img)
	{
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}
	}

	void Mover(Direccion direccion, int ancho_form, int alto_form)
	{
		switch (direccion)
		{
		case Direccion::Arriba:
		{
			if (y - dy > 0)
				y -= dy;
			this->direccion_player = Direccion::Arriba;
			fila = 2;
			break;
		}
		case Direccion::Abajo:
		{
			if ((y + alto + dy) < alto_form)
				y += dy;
			this->direccion_player = Direccion::Abajo;
			fila = 3;
			break;
		}

		case Direccion::Derecha:
		{
			if ((x + ancho + dx) < ancho_form)
				x += dx;
			this->direccion_player = Direccion::Derecha;
			fila = 1;
			break;
		}

		case Direccion::Izquierda:
		{
			if (x - dx > 0)
				x -= dx;
			this->direccion_player = Direccion::Izquierda;
			fila = 0;
			break;
		}
		}
	}

	Bala_Jugador* getBala(int pos) {
		return balas->getBala(pos);
	}
	void Agregar_Bala(double mousex, double mousey) {
		balas->Agregar_Bala(x, y, mousex, mousey, ancho, alto);
	}
	void mostrar_bala(Graphics^ g, Bitmap^ img) {
		balas->Mostrar_Bala_Jugador(g, img);
	}
	void mover_bala() {
		balas->Mover_Bala_Jugador();

	}

	void eliminar_bala(int pos) {
		balas->Eliminar_Bala(pos);
	}
	int getCantidad_Balas() {
		return balas->getCantidad_Balas();
	}
};

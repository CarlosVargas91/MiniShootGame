#pragma once
#include "Entidad.h"
#include <iostream>
using namespace System;

class Bala_Jugador : public Entidad
{
	int random_mensajes;

public:
	Bala_Jugador(int x, int y, int dx, int dy) {
		Random j;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		//
		random_mensajes = j.Next(1, 5);
		System::Threading::Thread::Sleep(8);
		columna = fila = 0;

	}

	~Bala_Jugador() {}

	void Mostrar(Graphics^ g, Bitmap^ img) 
	{
		alto = img->Height / 1;
		ancho = img->Width / 1;
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		switch (random_mensajes) {
		case 1: g->DrawString("Mucha fiesta", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 2: g->DrawString("Te echo al Piscuis", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 3: g->DrawString("Estoy chiquito", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 4: g->DrawString("Auxilio me desmayo", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		}
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == 1) {
			columna = 0;
		}

	}

	void mover() 
	{
		x += dx;
		y += dy;
	}
};

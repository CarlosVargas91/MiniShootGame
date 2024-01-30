#pragma once
#include"Entidad.h"
using namespace System;
class Bala_Asintomatico :public Entidad
{
public:
	Bala_Asintomatico(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dy = dy;
		this->dx = dx;
		columna = fila = 0;
	}
	void mostrar(Graphics^ g, Bitmap^ img) {

		alto = img->Height / 1;
		ancho = img->Width / 1;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

		columna++;
		if (columna == 1) {
			columna = 0;
		}

	}
	void mover() {
		x += dx;
		if (dx > 0) {
			fila = 0;
		}
		else {
			fila = 1;
		}
		y += dy;

	}
};

#pragma once
#include "Entidad.h"
using namespace System;

class Bala_Saludable :public Entidad {

public:
	Bala_Saludable(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 18;
	}

	~Bala_Saludable() {}
	void Mostar(Graphics^g) {
		Brush^ br = gcnew SolidBrush(Color::DarkGreen);
		g->FillEllipse(br, x, y, ancho, alto);
	}
	void Mover() {
		x += dx;
		y += dy;
	}
};

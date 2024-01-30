#pragma once
#include "Entidad.h"
#include "Arreglo_Bala_Asitntomatico.h"
#include <ctime>

using namespace System;

class Asintomatico :public Entidad
{
private:
	Direccion direccion;
	Arreglo_Balas_Asintomatico* balas;

public:
	Asintomatico() 
	{
		Random j;
		x = j.Next(200, 1000);
		System::Threading::Thread::Sleep(40);
		y = j.Next(200, 680);
		System::Threading::Thread::Sleep(40);
		dx = 5;
		dy = 5;
		fila = columna = 0;
		balas = new Arreglo_Balas_Asintomatico();
	}

	~Asintomatico() {

	}

	void Mostrar(Graphics^ g, Bitmap^ img) 
	{
		alto = img->Height / 4;
		ancho = img->Width / 3;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == 3) 
		{
			columna = 0;
		}
	}

	void setMostrar(Graphics^ g, Bitmap^ img) {
		Mostrar(g, img);
	}

	void Mover(Direccion direccion, int anchoform, int altoform) {
		switch (direccion) {

		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;
			this->direccion = Direccion::Arriba;
			fila = 3;
			break;
		case Direccion::Abajo:
			if (y + alto + dy < altoform)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 0;
			break;

		case Direccion::Derecha:
			if (x + ancho + dx < anchoform)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 2;
			break;

		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 1;
			break;
		}
	}

	void agregar_Bala() {
		balas->Agregar_Bala(direccion, x, y, ancho, alto);
	}
	void eliminar_bala(int pos) {
		balas->eliminar_bala(pos);
	}
	void mostrar_balaene(Graphics^ g, Bitmap^ img) {
		balas->mostrar_bala_asinto(g, img);
	}
	void moverbala_ene() {
		balas->mover_bala_asinto();
	}
	int getCantBalasEne() {
		return balas->getCantBalasAsinto();
	}
	Bala_Asintomatico* getBalita(int i) {
		return balas->getBalita(i);
	}
};
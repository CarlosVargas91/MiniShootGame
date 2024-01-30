#pragma once
#include "Bala_Jugador.h"
class Arreglo_Bala_Jugador {

private:
	Bala_Jugador** balaj;
	int cant;
public:
	Arreglo_Bala_Jugador() {
		cant = 0;
		balaj = new Bala_Jugador * [cant];
	}

	Bala_Jugador* getBala(int pos) {
		return balaj[pos];
	}
	int getCantidad_Balas() {
		return cant;
	}
	void Agregar_Bala(int x, int y, double mousex, double mousey, int ancho, int alto) {
		Bala_Jugador** aux = new Bala_Jugador * [cant + 1];
		for (int i = 0; i < cant; ++i)
			aux[i] = balaj[i];
		x = x + (ancho / 2);
		y = y + (alto / 2);
		double cateto1 = mousex - x;
		double cateto2 = mousey - y;
		double hipo = Math::Sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
		double V = 40;
		double constante = V / hipo;
		double dx = constante * cateto1;
		double dy = constante * cateto2;

		aux[cant] = new Bala_Jugador(x, y, dx, dy);
		balaj = aux;
		cant++;
	}
	void Eliminar_Bala(int pos) {
		//
		Bala_Jugador** aux = new Bala_Jugador * [cant - 1];
		delete balaj[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = balaj[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = balaj[i + 1];

		balaj = aux;
		cant--;

	}
	void Mostrar_Bala_Jugador(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant; ++i) {
			balaj[i]->Mostrar(g, img);
		}
	}
	void Mover_Bala_Jugador() {
		for (int i = 0; i < cant;++i) {
			balaj[i]->mover();
		}
	}
};

#pragma once
#include "Bala_Saludable.h"

class Arreglo_Bala_Saludable {
	Bala_Saludable** bala_salu;
	int cant;
public:
	Arreglo_Bala_Saludable() {
		cant = 0;
		bala_salu = new Bala_Saludable * [cant];
	}


	void agregar_Bala_Saludable(int index, int dy, int dx, int x, int y, int ancho, int alto) {
		Bala_Saludable** aux = new Bala_Saludable * [cant + 1];

		for (int i = 0; i < cant; ++i)

			aux[i] = bala_salu[i];

		int dx1 = 0, dy1 = 0;

		if (index == 1) {
			if (dy > 0) {
				dy1 += 20;
			}
			else {
				dy1 -= 20;
			}
		}
		else {
			if (dx > 0) {
				dx1 += 20;
			}
			else {
				dx1 -= 20;
			}
		}


		aux[cant] = new Bala_Saludable(x + ancho / 2, y + alto / 2, dx1, dy1);

		bala_salu = aux;
		cant++;


	}

	void eliminar_bala_salu(int pos) {
		Bala_Saludable** aux = new Bala_Saludable * [cant - 1];
		delete bala_salu[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = bala_salu[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala_salu[i + 1];


		cant--;
		bala_salu = aux;
	}
	void mostrar_bala_salu(Graphics^ g) {
		for (int i = 0; i < cant; ++i) {

			bala_salu[i]->Mostar(g);
		}
	}
	void mover_bala_salu() {
		for (int i = 0; i < cant; ++i) {

			bala_salu[i]->Mover();
		}
	}
	Bala_Saludable* getBalitasalu(int i) {
		return bala_salu[i];
	}

	int getCantBalassalu() {
		return cant;
	}
};

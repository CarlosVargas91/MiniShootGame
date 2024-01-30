#pragma once
#include "Bala_Asintomatico.h"
class Arreglo_Balas_Asintomatico {
private:
	Bala_Asintomatico** bala_asi;
	int cant;

public:
	Arreglo_Balas_Asintomatico() {
		cant = 0;
		bala_asi = new Bala_Asintomatico * [cant];
	}

	void Agregar_Bala(Direccion direccion, int x, int y, int ancho, int alto) {
		Bala_Asintomatico** aux = new Bala_Asintomatico * [cant + 1];
		for (int i = 0; i < cant;++i)
			aux[i] = bala_asi[i];
		System::Threading::Thread::Sleep(10);
		int dx = 0, dy = 0;

		switch (direccion) {
		case Direccion::Arriba: dy -= 19; break;
		case Direccion::Abajo: dy += 19; break;
		case Direccion::Derecha: dx += 19; break;
		case Direccion::Izquierda:dx -= 19; break;


		}
		/// 

		aux[cant] = new Bala_Asintomatico(x + ancho / 2, y + alto / 2, dx, dy);
		bala_asi = aux;
		cant++;

	}
	void eliminar_bala(int pos) {
		Bala_Asintomatico** aux = new Bala_Asintomatico * [cant - 1];
		delete bala_asi[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = bala_asi[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala_asi[i + 1];


		cant--;
		bala_asi = aux;
	}

	void mostrar_bala_asinto(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant; ++i) {

			bala_asi[i]->mostrar(g, img);
		}
	}

	void mover_bala_asinto() {
		for (int i = 0; i < cant; ++i) {

			bala_asi[i]->mover();
		}
	}
	Bala_Asintomatico* getBalita(int pos) {
		return bala_asi[pos];
	}

	int getCantBalasAsinto() {
		return cant;
	}

};

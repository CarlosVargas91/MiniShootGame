#pragma once
#include"Asintomatico.h"
class Arreglo_Asintomaticos {
private:
	Asintomatico** asinto;
	int cant_asintomatico;

public:
	Arreglo_Asintomaticos() {
		cant_asintomatico = 0;
		asinto = new Asintomatico * [cant_asintomatico];
	}
	int getcantidad_asintomatico() {
		return cant_asintomatico;
	}
	Asintomatico* getAsintomatico(int pos) {
		return asinto[pos];
	}
	void agregar_asintomatico(int n) {

		for (int m = 0; m < n; ++m) {
			Asintomatico** tmp = new Asintomatico * [cant_asintomatico + 1];
			for (int i = 0; i < cant_asintomatico; ++i)
				tmp[i] = asinto[i];
			tmp[cant_asintomatico] = new Asintomatico();
			asinto = tmp;
			cant_asintomatico++;


		}
	}
	void eliminar_asintomatico(int pos) {
		Asintomatico** aux = new Asintomatico * [cant_asintomatico - 1];
		delete asinto[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = asinto[i];
		for (int i = pos; i < cant_asintomatico - 1; ++i)
			aux[i] = asinto[i + 1];


		cant_asintomatico--;
		asinto = aux;
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img, Bitmap^ b) {
		for (int i = 0; i < cant_asintomatico; ++i) {
			asinto[i]->Mostrar(g, img);
			//faltaba el mostrar
			//asinto[i]->mostrar_balaene(g, b);


		}
	}

};


#pragma once
#include "Saludable.h"
#include<iostream>
class Arreglo_Saludables {

private:
	Saludable** salu;
	int cant_saludables;
public:
	Arreglo_Saludables() {
		cant_saludables = 0;
		salu = new Saludable * [cant_saludables];
	}

	int getCantidad_Salubale() { return cant_saludables; }

	Saludable* getSaludable(int pos) {
		return salu[pos];
	}

	void Mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant_saludables; ++i) {
			salu[i]->Mostrar(g, img);
			//Faltaba el mostrar bala
			//salu[i]->mostrar_balaene(g);

		}

	}
	void Agregar_Saludable(int n) {
		Random j;
		for (int m = 0; m < n; ++m) {
			Saludable** aux = new Saludable * [cant_saludables + 1];

			for (int i = 0; i < cant_saludables; ++i)
				aux[i] = salu[i];
			aux[cant_saludables] = new Saludable(j.Next(800, 1000), j.Next(600, 700));
			System::Threading::Thread::Sleep(30);
			salu = aux;
			cant_saludables++;

		}
	}

	void Eliminar_Saludable(int pos) {
		Saludable** aux = new Saludable * [cant_saludables];
		delete salu[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = salu[i];

		for (int i = pos; i < cant_saludables - 1; ++i)
			aux[i] = salu[i + 1];
		cant_saludables--;
		salu = aux;
	}

};
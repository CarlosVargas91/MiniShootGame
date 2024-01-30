#pragma once
#include "JujadorFritos.h"
#include "Arreglo_Asintomaticos.h"
#include "Arreglo_Saludablesh.h"
#include "Ambulancia.h"
#include "Policia.h"

using namespace System::Windows::Forms;

class Juego {
	Jugador* jugador;
	Ambulancia* ambu;
	Arreglo_Asintomaticos* asinto;
	Arreglo_Saludables* salu;
	Policia* poli;
	int puntos = 0;
	int tiempo;
	int cont;
	clock_t inicio;
	int cool_down, cool_down2;
	bool rojo;
	bool verde;
	int cool_down_asi;
	int cont_asi;
	int cool_down_salu;
	int cont_salu;
	int pos_saludable;
	int pos_asintomatico;
	int capturados;


public:
	Juego(int tiempo_inicial, int vidas) {
		Random j;
		cool_down = 0;
		cool_down2 = 0;
		jugador = new Jugador(vidas);
		ambu = new Ambulancia();
		poli = new Policia();
		asinto = new Arreglo_Asintomaticos();
		salu = new Arreglo_Saludables();
		verde = false;
		rojo = false;
		tiempo = tiempo_inicial;
		cool_down_asi = 0;
		cont_asi = 0;
		cool_down_salu = 0;
		cont_salu = 0;
		pos_saludable = 0;
		pos_asintomatico = 0;
		capturados = 0;
	}

	~Juego() {
		jugador = nullptr;
		ambu = nullptr;
		poli = nullptr;
		asinto = nullptr;
		salu = nullptr;
	}



	int getPuntos() { return puntos; }
	bool getVerde() { return verde; }
	bool getRojo() { return rojo; }
	int Cantidad_Asinto() { return cont_asi; }
	int Cantidad_Saludables() { return cont_salu; }
	int getVidas_Jugador() { return jugador->GetVidas(); }
	int getPosicion_Saludable() { return pos_saludable; }
	int getPosicion_Asintomatico() { return pos_asintomatico; }
	int getCapturados() { return capturados; }
	int getContador_Asinto() { return cont_asi; }
	int getContador_Saludable() { return cont_salu; }


	int Tiempo() {

		if ((double(clock() - inicio) / CLOCKS_PER_SEC) >= 1) {
			//balas
			cool_down++;
			cool_down2++;

			//personajes
			cool_down_asi++;
			cool_down_salu++;
			tiempo--;

			inicio = clock();
		}
		return tiempo;
	}


	void Tiempo_asintomatico() {
		if (cool_down_asi == 3) {
			cont_asi++;
			asinto->agregar_asintomatico(1);
		}

		if (cool_down_asi == 3) {
			/// <summary>
			/// /falto el =0
			/// </summary>
			cool_down_asi = 0;
		}
	}

	void Tiempo_saludable() {
		if (cool_down_salu == 3) {
			cont_salu++;
			salu->Agregar_Saludable(1);
		}

		if (cool_down_salu == 3) {
			/// <summary>
			/// ////
			/// </summary>
			cool_down_salu = 0;
		}
	}


	void Disparar(double mousex, double mousey) {
		jugador->Agregar_Bala(mousex, mousey);
	}

	void Mostar_Jugador(Graphics^ g, Bitmap^ img, Bitmap^ bala) {
		jugador->Mostrar(g, img);
		jugador->mostrar_bala(g, bala);
	}
	void Mover_Jugador(Keys key, int ancho_form, int alto_form) {

		if (key == Keys::Up) {
			jugador->Mover(Direccion::Arriba, ancho_form, alto_form);
		}
		else if (key == Keys::Down) {
			jugador->Mover(Direccion::Abajo, ancho_form, alto_form);
		}
		else if (key == Keys::Right) {
			jugador->Mover(Direccion::Derecha, ancho_form, alto_form);
		}
		else if (key == Keys::Left) {
			jugador->Mover(Direccion::Izquierda, ancho_form, alto_form);
		}

	}

	////////////////////////////////////////////
	//ASINTOMATICO
	void mover_asintomatico(int ancho1, int alto1) {
		for (int i = 0; i < asinto->getcantidad_asintomatico(); ++i) {

			if (asinto->getAsintomatico(i)->getX() - 1 > jugador->getX() + 20) {
				asinto->getAsintomatico(i)->Mover(Direccion::Izquierda, ancho1, alto1);

			}
			else if (asinto->getAsintomatico(i)->getX() < jugador->getX() + 20) {
				asinto->getAsintomatico(i)->Mover(Direccion::Derecha, ancho1, alto1);

			}
			else if (asinto->getAsintomatico(i)->getY() - 1 > jugador->getY()) {
				asinto->getAsintomatico(i)->Mover(Direccion::Arriba, ancho1, alto1);
			}
			else if (asinto->getAsintomatico(i)->getY() < jugador->getY()) {
				asinto->getAsintomatico(i)->Mover(Direccion::Abajo, ancho1, alto1);
			}

			if (cool_down == 3) {
				//asinto->getAsintomatico(i)->agregar_Bala();
				asinto->getAsintomatico(i)->agregar_Bala();

			}
			asinto->getAsintomatico(i)->moverbala_ene();
		}

		if (cool_down == 3) {

			cool_down = 0;
		}
		jugador->mover_bala();
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img, Bitmap^ b) {
		asinto->mostrar_asintomatico(g, img, b);
	}


	/////////
	//Saludable
	void mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		salu->Mostrar_Saludable(g, img);
	}


	void mover_Saludable(int ancho1, int alto1) {
		for (int i = 0; i < salu->getCantidad_Salubale(); ++i) {
			Random j;
			j.Next(1, 3);
			salu->getSaludable(i)->Mover(ancho1, alto1, 1);
			/// <summary>
			/// ///////
			/// </summary>
			/// <param name="ancho1"></param>
			/// <param name="alto1"></param>
			if (cool_down2 == 2) {
				//salu->getSaludable(i)->agregar_Bala(1);
				salu->getSaludable(i)->agregar_Bala(1);

			}
			salu->getSaludable(i)->moverbala_ene();
		}

		if (cool_down2 == 2) {

			cool_down2 = 0;
		}

	}

	/////////////////////////
	//////Ambulancia
	void Mostrar_ambulancia1(Graphics^ g, Bitmap^ img) {
		ambu->MostrarAmbulancia(g, img);
	}

	void Mover_ambulncia1(int pos, int ancho_form, int alto_form) {

		if (asinto->getAsintomatico(pos)->getX() >= ambu->getX() + 20) {
			ambu->Mover_Ambulancia(Direccion::Derecha, ancho_form, alto_form);

		}
		else if (asinto->getAsintomatico(pos)->getX() + 20 <= ambu->getX() - 2) {
			ambu->Mover_Ambulancia(Direccion::Izquierda, ancho_form, alto_form);

		}
		else if (asinto->getAsintomatico(pos)->getY() >= ambu->getY()) {
			ambu->Mover_Ambulancia(Direccion::Abajo, ancho_form, alto_form);
		}
		else if (asinto->getAsintomatico(pos)->getY() <= ambu->getY()) {
			ambu->Mover_Ambulancia(Direccion::Arriba, ancho_form, alto_form);
		}



	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//6.- Policia

	void Mostrar_Policia(Graphics^ g, Bitmap^ img) {
		poli->mostrar_Policia(g, img);
	}


	void Mover_Policia(int ancho1, int alto1, int pos) {

		if (salu->getSaludable(pos)->getX() >= poli->getX() + 2) {
			poli->mover_Policia(Direccion::Derecha, ancho1, alto1);

		}
		else if (salu->getSaludable(pos)->getX() + 30 <= poli->getX()) {
			poli->mover_Policia(Direccion::Izquierda, ancho1, alto1);
		}

		else if (salu->getSaludable(pos)->getY() >= poli->getY()) {
			poli->mover_Policia(Direccion::Abajo, ancho1, alto1);
		}

		else if (salu->getSaludable(pos)->getY() <= poli->getY()) {
			poli->mover_Policia(Direccion::Arriba, ancho1, alto1);
		}


	}

	void Colision_Jugador_asi() {
		Rectangle juga;
		Rectangle asinto_1;
		for (int i = 0; i < asinto->getcantidad_asintomatico(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			asinto_1 = Rectangle(asinto->getAsintomatico(i)->getX(), asinto->getAsintomatico(i)->getY(),
				asinto->getAsintomatico(i)->getAncho(), asinto->getAsintomatico(i)->getAlto());

			if (juga.IntersectsWith(asinto_1)) {
				jugador->RestarVida();
			}
		}


	}


	void colision_jugador_salu() {
		Rectangle juga;
		Rectangle saludab;
		for (int i = 0; i < salu->getCantidad_Salubale(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			saludab = Rectangle(salu->getSaludable(i)->getX(), salu->getSaludable(i)->getY(),
				salu->getSaludable(i)->getAncho(), salu->getSaludable(i)->getAlto());
			if (juga.IntersectsWith(saludab)) {
				jugador->RestarVida();
			}
		}
	}


	void Colision_balas_asintomaticoxjugador() {

		Rectangle bala_asinto;
		Rectangle juga;
		Bala_Asintomatico* Bala;

		for (int enemigo_a = 0; enemigo_a < asinto->getcantidad_asintomatico(); ++enemigo_a) {

			for (int bala_asi = 0; bala_asi < asinto->getAsintomatico(enemigo_a)->getCantBalasEne(); ++bala_asi) {
				Bala = asinto->getAsintomatico(enemigo_a)->getBalita(bala_asi);
				bala_asinto = Rectangle(Bala->getX(), Bala->getY(), Bala->getAncho(), Bala->getAlto());
				juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());

				if (juga.IntersectsWith(bala_asinto)) {
					jugador->RestarVida();
					asinto->getAsintomatico(enemigo_a)->eliminar_bala(bala_asi--);
				}

			}
		}

	}

	void colison_balas_desaludable_ajugador() {
		Rectangle bala_salu;
		Rectangle juga;
		Bala_Saludable* BAL1;


		for (int saludable = 0; saludable < salu->getCantidad_Salubale(); ++saludable) {

			for (int bal = 0; bal < salu->getSaludable(saludable)->getCantBalasEne1(); ++bal) {
				BAL1 = salu->getSaludable(saludable)->getBalita1(bal);
				bala_salu = Rectangle(BAL1->getX(), BAL1->getY(), BAL1->getAncho(), BAL1->getAlto());
				juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());

				if (bala_salu.IntersectsWith(juga)) {
					salu->getSaludable(saludable)->eliminar_bala(bal--);
					jugador->RestarVida();
				}
			}

		}


	}

	void Colision_disparo_jugadorxsaludable() {
		Rectangle bala;
		Rectangle saludable;
		Bala_Jugador* Bala;

		for (int b = 0; b < jugador->getCantidad_Balas(); ++b) {
			Bala = jugador->getBala(b);

			bala = Rectangle(Bala->getX(), Bala->getY(), Bala->getAncho(), Bala->getAlto());

			for (int e_salu = 0; e_salu < salu->getCantidad_Salubale(); ++e_salu) {
				saludable = Rectangle(salu->getSaludable(e_salu)->getX(), salu->getSaludable(e_salu)->getY(),
					salu->getSaludable(e_salu)->getAncho(), salu->getSaludable(e_salu)->getAlto());

				if (bala.IntersectsWith(saludable)) {
					verde = true;
					puntos += 10;
					jugador->eliminar_bala(b--);
					pos_saludable = e_salu;
				}


			}

		}


	}


	void colision_disparo_jugadorxasi() {

		Rectangle bala;//jugador

		Rectangle r_asintomatico;
		Bala_Jugador* BALA;

		for (int b = 0; b < jugador->getCantidad_Balas(); ++b)
		{
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int a = 0; a < asinto->getcantidad_asintomatico(); ++a)
			{

				r_asintomatico = Rectangle(asinto->getAsintomatico(a)->getX(), asinto->getAsintomatico(a)->getY(), asinto->getAsintomatico(a)->getAncho(), asinto->getAsintomatico(a)->getAlto());
				if (bala.IntersectsWith(r_asintomatico))
				{

					rojo = true;
					pos_asintomatico = a;
					jugador->eliminar_bala(b--);
					puntos += 10;

				}


			}

		}

	}



	void colision_policixsaludables(Graphics^ g, Bitmap^ img, int ancho_form, int alto_form) {
		Rectangle saludable;
		Rectangle policia;

		if (getVerde() == true) {
			Mostrar_Policia(g, img);
			Mover_Policia(ancho_form, alto_form, getPosicion_Saludable());
			policia = Rectangle(poli->getX(), poli->getY(), poli->getAncho(), poli->getAlto());
			saludable = Rectangle(salu->getSaludable(getPosicion_Saludable())->getX(), salu->getSaludable(getPosicion_Saludable())->getY(),
				salu->getSaludable(getPosicion_Saludable())->getAncho(), salu->getSaludable(getPosicion_Saludable())->getAlto());

			if (policia.IntersectsWith(saludable)) {
				verde = false;
				capturados++;
				poli->setXY();
				salu->Eliminar_Saludable(getPosicion_Saludable());
			}

		}


	}


	void colisionambulancia_asi(Graphics^ g, Bitmap^ img, int ancho_form, int alto_form) {
		Rectangle r_asinto;
		Rectangle ambulancia;
		if (getRojo() == true) {
			Mostrar_ambulancia1(g, img);
			Mover_ambulncia1(getPosicion_Asintomatico(), ancho_form, alto_form);
			ambulancia = Rectangle(ambu->getX(), ambu->getY(), ambu->getAncho(), ambu->getAlto());
			r_asinto = Rectangle(asinto->getAsintomatico(getPosicion_Asintomatico())->getX(), asinto->getAsintomatico(getPosicion_Asintomatico())->getY(),
				asinto->getAsintomatico(getPosicion_Asintomatico())->getAncho(), asinto->getAsintomatico(getPosicion_Asintomatico())->getAlto());

			if (ambulancia.IntersectsWith(r_asinto)) {
				rojo = false;
				capturados++;
				ambu->setXY();
				asinto->eliminar_asintomatico(getPosicion_Asintomatico());

			}
		}
	}

	void cambiar_rojo(Graphics^ g, Bitmap^ img) {
		if (getRojo() == true) {
			asinto->getAsintomatico(getPosicion_Asintomatico())->setMostrar(g, img);
		}
	}
	void cambiar_verde(Graphics^ g, Bitmap^ img) {
		if (getVerde() == true) {
			salu->getSaludable(getPosicion_Saludable())->setMostar(g, img);
		}
	}
};
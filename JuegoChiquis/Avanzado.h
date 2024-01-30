#pragma once
#include <ctime>
#include "juego.h"

namespace JuegoChiquis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Avanzado
	/// </summary>
	public ref class Avanzado : public System::Windows::Forms::Form
	{
	public:
		Avanzado(int tiempo, int vida)
		{
			InitializeComponent();
			Random j;
			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			juego = new Juego(tiempo, vida);

			juga = gcnew Bitmap("imagenes/jugador.png");
			asi = gcnew Bitmap("imagenes/asintomatico.png");
			saludable = gcnew Bitmap("imagenes/saludable.png");
			ambulancia = gcnew Bitmap("imagenes/ambulancia.png");

			policia = gcnew Bitmap("imagenes/policia.png");
			rojo = gcnew Bitmap("imagenes/rojo1.png");
			verde = gcnew Bitmap("imagenes/verde1.jpg");
			san_juan = gcnew Bitmap("imagenes/san_juan.png");
			policia = gcnew Bitmap("imagenes/policia.png");
			bala = gcnew Bitmap("imagenes/energy.png");

			balajuga = gcnew Bitmap("imagenes/blanco.png");
			total_enemys = j.Next(4, 7);
			System::Threading::Thread::Sleep(3);
			x = 0;
			y = 0;
			ancho_form = this->Width;
			alto_form = this->Height;
			ganaste = false;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Avanzado()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ g;
		Bitmap^ juga;
		Bitmap^ rojo;
		Bitmap^ verde;
		Bitmap^ asi;
		Bitmap^ saludable;
		Bitmap^ ambulancia;
		Bitmap^ policia;
		Bitmap^ san_juan;
		Bitmap^ bala;
		Bitmap^ balajuga;

		Juego* juego;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;

		int x, y, total_enemys;
		int ancho_form, alto_form;
		int vidas, tiempo1;
		bool ganaste;
	internal: System::Windows::Forms::Timer^ timer1;

	private:

	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Label^ l_puntos;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ l_vidas;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ l_tiempo;
	private: System::Windows::Forms::Label^ label5;
	private: System::ComponentModel::IContainer^ components;


	public: bool getGanaste() {
		return ganaste;
	}
	public: int getTotal_Enemigos() {
		return total_enemys;
	}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label = (gcnew System::Windows::Forms::Label());
			this->l_puntos = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->l_vidas = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->l_tiempo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Avanzado::timer1_Tick);
			// 
			// label
			// 
			/*this->label->Location = System::Drawing::Point(0, 0);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(100, 23);
			this->label->TabIndex = 0;*/
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->ForeColor = System::Drawing::Color::Red;
			this->label->Location = System::Drawing::Point(35, 41);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(98, 29);
			this->label->TabIndex = 0;
			this->label->Text = L"Puntos";
			// 
			// l_puntos
			// 
			/*this->l_puntos->Location = System::Drawing::Point(0, 0);
			this->l_puntos->Name = L"l_puntos";
			this->l_puntos->Size = System::Drawing::Size(100, 23);
			this->l_puntos->TabIndex = 0;*/
			this->l_puntos->AutoSize = true;
			this->l_puntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l_puntos->Location = System::Drawing::Point(152, 41);
			this->l_puntos->Name = L"l_puntos";
			this->l_puntos->Size = System::Drawing::Size(28, 29);
			this->l_puntos->TabIndex = 1;
			this->l_puntos->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(248, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas";
			// 
			// l_vidas
			// 
			this->l_vidas->AutoSize = true;
			this->l_vidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l_vidas->Location = System::Drawing::Point(362, 41);
			this->l_vidas->Name = L"l_vidas";
			this->l_vidas->Size = System::Drawing::Size(28, 29);
			this->l_vidas->TabIndex = 2;
			this->l_vidas->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(485, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Tiempo";
			// 
			// l_tiempo
			// 
			this->l_tiempo->AutoSize = true;
			this->l_tiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l_tiempo->Location = System::Drawing::Point(606, 41);
			this->l_tiempo->Name = L"l_tiempo";
			this->l_tiempo->Size = System::Drawing::Size(28, 29);
			this->l_tiempo->TabIndex = 3;
			this->l_tiempo->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(772, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(248, 78);
			this->label5->TabIndex = 9;
			this->label5->Text = L"OBJETIVO: 500 PTS -\r\nMATAR MITAD\r\n   ENEMIGOS";
			// 
			// Avanzado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1371, 1055);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->l_tiempo);
			this->Controls->Add(this->l_vidas);
			this->Controls->Add(this->l_puntos);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label);
			this->Name = L"Juego_Avanzado";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego_Avanzado";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Avanzado::Juego_Avanzado_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Avanzado::Juego_Avanzado_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->DrawImage(san_juan, 0, 0, Rectangle(x, y, san_juan->Width, san_juan->Height), GraphicsUnit::Pixel);
		juego->Mostar_Jugador(bf->Graphics, juga, balajuga);
		if (juego->getContador_Asinto() < getTotal_Enemigos()) {
			juego->Tiempo_asintomatico();
		}
		if (juego->getContador_Saludable() < getTotal_Enemigos()) {
			juego->Tiempo_saludable();

		}


		juego->mostrar_asintomatico(bf->Graphics, asi, bala);
		juego->mover_asintomatico(ancho_form, alto_form);

		juego->mostrar_Saludable(bf->Graphics, saludable);
		juego->mover_Saludable(ancho_form, alto_form);

		juego->colisionambulancia_asi(bf->Graphics, ambulancia, ancho_form, alto_form);
		juego->Colision_balas_asintomaticoxjugador();
		juego->colision_disparo_jugadorxasi();
		juego->Colision_disparo_jugadorxsaludable();
		juego->Colision_Jugador_asi();
		juego->colision_jugador_salu();
		juego->colision_policixsaludables(bf->Graphics, policia, ancho_form, alto_form);
		juego->colison_balas_desaludable_ajugador();

		juego->cambiar_rojo(bf->Graphics, rojo);
		juego->cambiar_verde(bf->Graphics, verde);

		bf->Render(g);


		int puntos = juego->getPuntos();
		l_puntos->Text = puntos + "";

		if (juego->getCapturados() == getTotal_Enemigos() || puntos >= 500) {
			timer1->Enabled = false;
			MessageBox::Show("Felicidades, ganaste el juego");
			this->Hide();
			ganaste = true;
		}

		int v = juego->getVidas_Jugador();
		l_vidas->Text = v + "";
		if (v == 0) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Hide();
		}

		int t = juego->Tiempo();
		l_tiempo->Text = t + "";
		if (t == 0) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Hide();
		}
	}

private: System::Void Juego_Avanzado_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	juego->Mover_Jugador(e->KeyCode, ancho_form, alto_form);

}
private: System::Void Juego_Avanzado_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	juego->Disparar(e->X, e->Y);
}

};
}

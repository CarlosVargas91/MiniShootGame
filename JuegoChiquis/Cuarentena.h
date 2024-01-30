#pragma once
#include "Avanzado.h"

namespace JuegoChiquis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Cuarentena
	/// </summary>
	public ref class Cuarentena : public System::Windows::Forms::Form
	{
	public:
		Cuarentena(void)
		{
			InitializeComponent();
			mapa = gcnew Bitmap("imagenes/menuprincipal.png");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Cuarentena()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Bitmap^ mapa;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbx_tiempo;
	private: System::Windows::Forms::TextBox^ tbx_vidas;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbx_tiempo = (gcnew System::Windows::Forms::TextBox());
			this->tbx_vidas = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(125, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(258, 101);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Avanzado";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Cuarentena::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(862, 376);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(246, 101);
			this->button2->TabIndex = 1;
			this->button2->Tag = L"";
			this->button2->Text = L"Principiante";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(171, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Introduce tiempo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(968, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Introduce vidas";
			// 
			// tbx_tiempo
			// 
			this->tbx_tiempo->Location = System::Drawing::Point(283, 43);
			this->tbx_tiempo->Name = L"tbx_tiempo";
			this->tbx_tiempo->Size = System::Drawing::Size(100, 22);
			this->tbx_tiempo->TabIndex = 4;
			// 
			// tbx_vidas
			// 
			this->tbx_vidas->Location = System::Drawing::Point(1072, 43);
			this->tbx_vidas->Name = L"tbx_vidas";
			this->tbx_vidas->Size = System::Drawing::Size(100, 22);
			this->tbx_vidas->TabIndex = 5;
			// 
			// Cuarentena
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1532, 1055);
			this->Controls->Add(this->tbx_vidas);
			this->Controls->Add(this->tbx_tiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Cuarentena";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cuarentena";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Cuarentena::Cuarentena_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cuarentena_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		g->DrawImage(mapa, 0, 0, Rectangle(0, 0, 1200, 852), GraphicsUnit::Pixel);

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tbx_tiempo->Text != "" && tbx_vidas->Text != "") {
			Avanzado^ esc1 = gcnew Avanzado(Convert::ToInt32(tbx_tiempo->Text), Convert::ToInt32(tbx_vidas->Text));
			esc1->ShowDialog();
		}

	}
};
}

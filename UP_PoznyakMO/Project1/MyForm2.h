#pragma once
#include <fstream>
#include <cstdlib> 
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> 
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

/* подключение созданной dll */
#include "dllochka.h"

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	char values[100], value;
	char vektor[10][10];
	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;

	private: Thread^ myThread;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Изначальный файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(388, 94);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 141);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(388, 187);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(136, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Сортировка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 331);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Позняк Михаил Олегович";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(282, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Диагональ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 351);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

static void vektor_sort(vector<char>& v) {

	/* сортировка вектора и запись его в файл*/

		sort(v.begin(), v.end());
		writeTo("vektora.txt", v);
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	/* вывод 100 латинских бкув из файла в textBox1 */

	String^ Filename = "bukavbI.txt";
	StreamReader^ file = File::OpenText(Filename);
	textBox1->Text = file->ReadToEnd();

	/* создание десяти векторов */

			vector<char> v1;
			vector<char> v2;
			vector<char> v3;
			vector<char> v4;
			vector<char> v5;
			vector<char> v6;
			vector<char> v7;
			vector<char> v8;
			vector<char> v9;
			vector<char> v10;

	/* открытие файла со 100 латинскими буквами*/

			ifstream f;
			f.open("bukavbI.txt");

	/* заполнение и сортировка десяти векторов с помощью десяти потоков */

			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v1.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v2.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v3.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v4.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v5.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v6.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v7.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v8.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v9.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v10.push_back(value);
			}
			thread potok1(vektor_sort, v1);
			potok1.join();
			thread potok2(vektor_sort, v2);
			potok2.join();
			thread potok3(vektor_sort, v3);
			potok3.join();
			thread potok4(vektor_sort, v4);
			potok4.join();
			thread potok5(vektor_sort, v5);
			potok5.join();
			thread potok6(vektor_sort, v6);
			potok6.join();
			thread potok7(vektor_sort, v7);
			potok7.join();
			thread potok8(vektor_sort, v8);
			potok8.join();
			thread potok9(vektor_sort, v9);
			potok9.join();
			thread potok10(vektor_sort, v10);
			potok10.join();
			f.close();
			
			
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	/* вывод отсортированных векторов в textBox2 */

		String^ Filename = "vektora.txt";
		StreamReader^ file = File::OpenText(Filename);
		textBox2->Text = file->ReadToEnd();
}
private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {

	/* вывод даты и времени в label1 */

	struct tm* date;
	char Current_date[100];
	const time_t timer = time(NULL);
	date = localtime(&timer);
	strftime(Current_date, 100, "%d.%m.%Y %H:%M:%S", date);
	System::String^ strCLR = gcnew System::String(Current_date);
	label1->Text += strCLR;
	srand(time(0));
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	/* добавление звездочек по диагонали */

	std::vector<char> v11;
	ifstream f;
	f.open("vektora.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j) {
				f >> vektor[i][j];
				vektor[i][j] = '*';
				v11.push_back(vektor[i][j]);
			}
			else {
				f >> vektor[i][j];
				v11.push_back(vektor[i][j]);
			}
		}
		writeTo1("vektora1.txt", v11);
		v11.clear();
	}

	/* вывод результата в textBox2 */

	String^ Filename = "vektora1.txt";
	StreamReader^ file = File::OpenText(Filename);
	textBox2->Text = file->ReadToEnd();
}
};
}

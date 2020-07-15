#pragma once
#include <string>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include"MainFormPresenter.h"
#include"Client.h"
#include"Messages.h"

using namespace msclr::interop;

namespace ClientCLIDplaychat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			mes = new FMessage();
			
			mes->fl = 0;
			//
			//TODO: добавьте код конструктора
			//
		}
		void setConnected()
		{
			this->label2->Text = "connected";
			this->label2->Update();
		}
		void addMessage(std::string name, std::string messages)
		{
			Messages^ message = gcnew Messages();
			message->setName(name);
			message->setMessages(messages);
			this->flowLayoutPanel1->Controls->Add(message);
		}

		

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
		Client	*client_;
		int second = 0;
		FMessage *mes;
		
		
		
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Label^  label2;

		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::TextBox^  textBox3;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

		private:
			
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


		#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(369, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ћогин поьзовател€";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(372, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(403, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(570, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"нет соединени€";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(106, 140);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(168, 22);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(293, 139);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(374, 80);
			this->textBox3->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 140);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(88, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"отправить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(165, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"кому";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(457, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"текст сообщени€";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 225);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(897, 270);
			this->flowLayoutPanel1->TabIndex = 10;
			this->flowLayoutPanel1->AutoScroll = true;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 507);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		std::string name = marshal_as<std::string>(this->textBox1->Text->ToString());
		client_ = new Client("127.0.0.1", 8087, name, "MySession",mes);
	}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		std::string name = marshal_as<std::string>(this->textBox2->Text->ToString());
		std::string text = marshal_as<std::string>(this->textBox3->Text->ToString());
		
		client_->sendMessage(name, text);
		
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	second++;
	if (second == 1)
	{
		second = 0;
		if (mes->fl == 1)
		{
			this->addMessage(std::string(mes->name), std::string(mes->data));
			mes->fl = 0;
		}
		if (mes->fl == 2)
		{
			this->setConnected();
			mes->fl = 0;
		}
	}
}
};
}

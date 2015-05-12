#pragma once
#include "scientific_calculator.h"
namespace ScientificCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CalcUI
	/// </summary>
	public ref class CalcUI : public System::Windows::Forms::Form
	{
#define EMPTY_STR L""
#define DEFAULT_VAL L"0"
	private:
		enum class CulculationActions
		{
			None,
			Add,
			Sub,
			Mul,
			Div,
			Pow,
			Sqrt,
			Log,
			Fact,
			Tan,
			Sin,
			Cos,
			Mod
		};

		// Поля

		CulculationActions _lastAction;
		double _lastResult;

		// Властивості

		property String ^Output
		{
			String ^get()
			{
				return _outputTxb->Text;
			}
			void set(String ^val)
			{
				_outputTxb->Text = val;
			}
		}

		// Mетод

		void ClearOutput();
		void ShowValue();
		bool NotEmptyOutput();
		void ExctractValueFromForm();
		double StoreResult();
		void Calculate();

		// події зворотнього виклику

		Void OnBackspaceBtnClick(Object^  sender, EventArgs^  e);
		Void OnClearBtnClick(Object^  sender, EventArgs^  e);
		Void OnInvertBtnClick(Object^  sender, EventArgs^  e);
		Void OnResultBtnClick(Object^  sender, EventArgs^  e);
		Void OnTypeNumberClick(Object^  sender, EventArgs^  e);
		Void OnSingleNumberOperationBtnClick(Object^  sender, EventArgs^  e);
		Void OnOperationBtnClick(Object^  sender, EventArgs^  e);
	protected:
		/// <summary>
		/// Звільнити всі ресурси, які є used.
		/// </summary>
		~CalcUI()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		CalcUI(void)
		{
			InitializeComponent();
			ClearOutput();
			//
			//TODO: Додати код конструктора тут
			//
		}
		// Згенерований код
	private:
		TextBox^  _outputTxb;
		GroupBox^  groupBox1;
		Button^  _zeroNumbBtn;
		Button^  _commaBtn;
		Button^  _divBtn;
		Button^  _mulBtn;
		Button^  _subBtn;
		Button^  _plusBtn;
		Button^  _resultBtn;
		Button^  _clearBtn;
		Button^  _oneNumbBtn;
		Button^  _twoNumbBtn;
		Button^  _threeNumbBtn;
		Button^  _fourNumbBtn;
		Button^  _fiveNumbBtn;
		Button^  _sixNumbBtn;
		Button^  _sevenNumbBtn;
		Button^  _nineNumbBtn;
		Button^  _eightNumbBtn;
		Button^  _invertBtn;
		Button^  _modBtn;
		Button^  _powBtn;
		Button^  _sqrtBtn;
		Button^  _factBtn;
		Button^  _cosBtn;
		Button^  _sinBtn;
		Button^  _tanBtn;
		Button^  _logBtn;
		Button^  _backspaceBtn;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обов'язковий метод для підтримки конструктора
		/// Вміст цього методу з редактором коду.
		/// </summary>
		void InitializeComponent(void)
		{
			this->_outputTxb = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->_backspaceBtn = (gcnew System::Windows::Forms::Button());
			this->_modBtn = (gcnew System::Windows::Forms::Button());
			this->_cosBtn = (gcnew System::Windows::Forms::Button());
			this->_sinBtn = (gcnew System::Windows::Forms::Button());
			this->_tanBtn = (gcnew System::Windows::Forms::Button());
			this->_logBtn = (gcnew System::Windows::Forms::Button());
			this->_powBtn = (gcnew System::Windows::Forms::Button());
			this->_sqrtBtn = (gcnew System::Windows::Forms::Button());
			this->_factBtn = (gcnew System::Windows::Forms::Button());
			this->_oneNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_twoNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_threeNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_fourNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_fiveNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_sixNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_sevenNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_nineNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_eightNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_invertBtn = (gcnew System::Windows::Forms::Button());
			this->_zeroNumbBtn = (gcnew System::Windows::Forms::Button());
			this->_commaBtn = (gcnew System::Windows::Forms::Button());
			this->_divBtn = (gcnew System::Windows::Forms::Button());
			this->_mulBtn = (gcnew System::Windows::Forms::Button());
			this->_subBtn = (gcnew System::Windows::Forms::Button());
			this->_plusBtn = (gcnew System::Windows::Forms::Button());
			this->_resultBtn = (gcnew System::Windows::Forms::Button());
			this->_clearBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// _outputTxb
			// 
			this->_outputTxb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_outputTxb->Location = System::Drawing::Point(12, 12);
			this->_outputTxb->Name = L"_outputTxb";
			this->_outputTxb->Size = System::Drawing::Size(228, 26);
			this->_outputTxb->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->_backspaceBtn);
			this->groupBox1->Controls->Add(this->_modBtn);
			this->groupBox1->Controls->Add(this->_cosBtn);
			this->groupBox1->Controls->Add(this->_sinBtn);
			this->groupBox1->Controls->Add(this->_tanBtn);
			this->groupBox1->Controls->Add(this->_logBtn);
			this->groupBox1->Controls->Add(this->_powBtn);
			this->groupBox1->Controls->Add(this->_sqrtBtn);
			this->groupBox1->Controls->Add(this->_factBtn);
			this->groupBox1->Controls->Add(this->_oneNumbBtn);
			this->groupBox1->Controls->Add(this->_twoNumbBtn);
			this->groupBox1->Controls->Add(this->_threeNumbBtn);
			this->groupBox1->Controls->Add(this->_fourNumbBtn);
			this->groupBox1->Controls->Add(this->_fiveNumbBtn);
			this->groupBox1->Controls->Add(this->_sixNumbBtn);
			this->groupBox1->Controls->Add(this->_sevenNumbBtn);
			this->groupBox1->Controls->Add(this->_nineNumbBtn);
			this->groupBox1->Controls->Add(this->_eightNumbBtn);
			this->groupBox1->Controls->Add(this->_invertBtn);
			this->groupBox1->Controls->Add(this->_zeroNumbBtn);
			this->groupBox1->Controls->Add(this->_commaBtn);
			this->groupBox1->Controls->Add(this->_divBtn);
			this->groupBox1->Controls->Add(this->_mulBtn);
			this->groupBox1->Controls->Add(this->_subBtn);
			this->groupBox1->Controls->Add(this->_plusBtn);
			this->groupBox1->Controls->Add(this->_resultBtn);
			this->groupBox1->Controls->Add(this->_clearBtn);
			this->groupBox1->Location = System::Drawing::Point(12, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(228, 265);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// _backspaceBtn
			// 
			this->_backspaceBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_backspaceBtn->Location = System::Drawing::Point(11, 25);
			this->_backspaceBtn->Name = L"_backspaceBtn";
			this->_backspaceBtn->Size = System::Drawing::Size(37, 34);
			this->_backspaceBtn->TabIndex = 11;
			this->_backspaceBtn->Text = L"<-";
			this->_backspaceBtn->UseVisualStyleBackColor = true;
			this->_backspaceBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnBackspaceBtnClick);
			// 
			// _modBtn
			// 
			this->_modBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_modBtn->Location = System::Drawing::Point(11, 65);
			this->_modBtn->Name = L"_modBtn";
			this->_modBtn->Size = System::Drawing::Size(37, 34);
			this->_modBtn->TabIndex = 11;
			this->_modBtn->Tag = L"12";
			this->_modBtn->Text = L"Mod";
			this->_modBtn->UseVisualStyleBackColor = true;
			this->_modBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _cosBtn
			// 
			this->_cosBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_cosBtn->Location = System::Drawing::Point(11, 105);
			this->_cosBtn->Name = L"_cosBtn";
			this->_cosBtn->Size = System::Drawing::Size(37, 34);
			this->_cosBtn->TabIndex = 12;
			this->_cosBtn->Tag = L"11";
			this->_cosBtn->Text = L"Cos";
			this->_cosBtn->UseVisualStyleBackColor = true;
			this->_cosBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnSingleNumberOperationBtnClick);
			// 
			// _sinBtn
			// 
			this->_sinBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sinBtn->Location = System::Drawing::Point(11, 145);
			this->_sinBtn->Name = L"_sinBtn";
			this->_sinBtn->Size = System::Drawing::Size(37, 34);
			this->_sinBtn->TabIndex = 13;
			this->_sinBtn->Tag = L"10";
			this->_sinBtn->Text = L"Sin";
			this->_sinBtn->UseVisualStyleBackColor = true;
			this->_sinBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnSingleNumberOperationBtnClick);
			// 
			// _tanBtn
			// 
			this->_tanBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_tanBtn->Location = System::Drawing::Point(11, 185);
			this->_tanBtn->Name = L"_tanBtn";
			this->_tanBtn->Size = System::Drawing::Size(37, 34);
			this->_tanBtn->TabIndex = 14;
			this->_tanBtn->Tag = L"9";
			this->_tanBtn->Text = L"Tan";
			this->_tanBtn->UseVisualStyleBackColor = true;
			this->_tanBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnSingleNumberOperationBtnClick);
			// 
			// _logBtn
			// 
			this->_logBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_logBtn->Location = System::Drawing::Point(11, 225);
			this->_logBtn->Name = L"_logBtn";
			this->_logBtn->Size = System::Drawing::Size(37, 34);
			this->_logBtn->TabIndex = 15;
			this->_logBtn->Tag = L"7";
			this->_logBtn->Text = L"Log";
			this->_logBtn->UseVisualStyleBackColor = true;
			this->_logBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnSingleNumberOperationBtnClick);
			// 
			// _powBtn
			// 
			this->_powBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_powBtn->Location = System::Drawing::Point(54, 65);
			this->_powBtn->Name = L"_powBtn";
			this->_powBtn->Size = System::Drawing::Size(37, 34);
			this->_powBtn->TabIndex = 16;
			this->_powBtn->Tag = L"5";
			this->_powBtn->Text = L"Pow";
			this->_powBtn->UseVisualStyleBackColor = true;
			this->_powBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _sqrtBtn
			// 
			this->_sqrtBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sqrtBtn->Location = System::Drawing::Point(97, 65);
			this->_sqrtBtn->Name = L"_sqrtBtn";
			this->_sqrtBtn->Size = System::Drawing::Size(37, 34);
			this->_sqrtBtn->TabIndex = 17;
			this->_sqrtBtn->Tag = L"6";
			this->_sqrtBtn->Text = L"Sqrt";
			this->_sqrtBtn->UseVisualStyleBackColor = true;
			this->_sqrtBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _factBtn
			// 
			this->_factBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_factBtn->Location = System::Drawing::Point(140, 65);
			this->_factBtn->Name = L"_factBtn";
			this->_factBtn->Size = System::Drawing::Size(37, 34);
			this->_factBtn->TabIndex = 18;
			this->_factBtn->Tag = L"8";
			this->_factBtn->Text = L"Fact";
			this->_factBtn->UseVisualStyleBackColor = true;
			this->_factBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnSingleNumberOperationBtnClick);
			// 
			// _oneNumbBtn
			// 
			this->_oneNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_oneNumbBtn->Location = System::Drawing::Point(54, 185);
			this->_oneNumbBtn->Name = L"_oneNumbBtn";
			this->_oneNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_oneNumbBtn->TabIndex = 10;
			this->_oneNumbBtn->Tag = L"1";
			this->_oneNumbBtn->Text = L"1";
			this->_oneNumbBtn->UseVisualStyleBackColor = true;
			this->_oneNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _twoNumbBtn
			// 
			this->_twoNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_twoNumbBtn->Location = System::Drawing::Point(97, 185);
			this->_twoNumbBtn->Name = L"_twoNumbBtn";
			this->_twoNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_twoNumbBtn->TabIndex = 9;
			this->_twoNumbBtn->Tag = L"2";
			this->_twoNumbBtn->Text = L"2";
			this->_twoNumbBtn->UseVisualStyleBackColor = true;
			this->_twoNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _threeNumbBtn
			// 
			this->_threeNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_threeNumbBtn->Location = System::Drawing::Point(140, 185);
			this->_threeNumbBtn->Name = L"_threeNumbBtn";
			this->_threeNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_threeNumbBtn->TabIndex = 8;
			this->_threeNumbBtn->Tag = L"3";
			this->_threeNumbBtn->Text = L"3";
			this->_threeNumbBtn->UseVisualStyleBackColor = true;
			this->_threeNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _fourNumbBtn
			// 
			this->_fourNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_fourNumbBtn->Location = System::Drawing::Point(54, 145);
			this->_fourNumbBtn->Name = L"_fourNumbBtn";
			this->_fourNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_fourNumbBtn->TabIndex = 7;
			this->_fourNumbBtn->Tag = L"4";
			this->_fourNumbBtn->Text = L"4";
			this->_fourNumbBtn->UseVisualStyleBackColor = true;
			this->_fourNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _fiveNumbBtn
			// 
			this->_fiveNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_fiveNumbBtn->Location = System::Drawing::Point(97, 145);
			this->_fiveNumbBtn->Name = L"_fiveNumbBtn";
			this->_fiveNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_fiveNumbBtn->TabIndex = 6;
			this->_fiveNumbBtn->Tag = L"5";
			this->_fiveNumbBtn->Text = L"5";
			this->_fiveNumbBtn->UseVisualStyleBackColor = true;
			this->_fiveNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _sixNumbBtn
			// 
			this->_sixNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sixNumbBtn->Location = System::Drawing::Point(140, 145);
			this->_sixNumbBtn->Name = L"_sixNumbBtn";
			this->_sixNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_sixNumbBtn->TabIndex = 5;
			this->_sixNumbBtn->Tag = L"6";
			this->_sixNumbBtn->Text = L"6";
			this->_sixNumbBtn->UseVisualStyleBackColor = true;
			this->_sixNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _sevenNumbBtn
			// 
			this->_sevenNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sevenNumbBtn->Location = System::Drawing::Point(54, 105);
			this->_sevenNumbBtn->Name = L"_sevenNumbBtn";
			this->_sevenNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_sevenNumbBtn->TabIndex = 4;
			this->_sevenNumbBtn->Tag = L"7";
			this->_sevenNumbBtn->Text = L"7";
			this->_sevenNumbBtn->UseVisualStyleBackColor = true;
			this->_sevenNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _nineNumbBtn
			// 
			this->_nineNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_nineNumbBtn->Location = System::Drawing::Point(140, 105);
			this->_nineNumbBtn->Name = L"_nineNumbBtn";
			this->_nineNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_nineNumbBtn->TabIndex = 3;
			this->_nineNumbBtn->Tag = L"9";
			this->_nineNumbBtn->Text = L"9";
			this->_nineNumbBtn->UseVisualStyleBackColor = true;
			this->_nineNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _eightNumbBtn
			// 
			this->_eightNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_eightNumbBtn->Location = System::Drawing::Point(97, 105);
			this->_eightNumbBtn->Name = L"_eightNumbBtn";
			this->_eightNumbBtn->Size = System::Drawing::Size(37, 34);
			this->_eightNumbBtn->TabIndex = 2;
			this->_eightNumbBtn->Tag = L"8";
			this->_eightNumbBtn->Text = L"8";
			this->_eightNumbBtn->UseVisualStyleBackColor = true;
			this->_eightNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _invertBtn
			// 
			this->_invertBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_invertBtn->Location = System::Drawing::Point(140, 25);
			this->_invertBtn->Name = L"_invertBtn";
			this->_invertBtn->Size = System::Drawing::Size(37, 34);
			this->_invertBtn->TabIndex = 1;
			this->_invertBtn->Text = L"+/-";
			this->_invertBtn->UseVisualStyleBackColor = true;
			this->_invertBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnInvertBtnClick);
			// 
			// _zeroNumbBtn
			// 
			this->_zeroNumbBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_zeroNumbBtn->Location = System::Drawing::Point(54, 225);
			this->_zeroNumbBtn->Name = L"_zeroNumbBtn";
			this->_zeroNumbBtn->Size = System::Drawing::Size(80, 34);
			this->_zeroNumbBtn->TabIndex = 0;
			this->_zeroNumbBtn->Tag = L"0";
			this->_zeroNumbBtn->Text = L"0";
			this->_zeroNumbBtn->UseVisualStyleBackColor = true;
			this->_zeroNumbBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _commaBtn
			// 
			this->_commaBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_commaBtn->Location = System::Drawing::Point(140, 225);
			this->_commaBtn->Name = L"_commaBtn";
			this->_commaBtn->Size = System::Drawing::Size(37, 34);
			this->_commaBtn->TabIndex = 0;
			this->_commaBtn->Tag = L",";
			this->_commaBtn->Text = L",";
			this->_commaBtn->UseVisualStyleBackColor = true;
			this->_commaBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnTypeNumberClick);
			// 
			// _divBtn
			// 
			this->_divBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_divBtn->Location = System::Drawing::Point(183, 25);
			this->_divBtn->Name = L"_divBtn";
			this->_divBtn->Size = System::Drawing::Size(37, 34);
			this->_divBtn->TabIndex = 0;
			this->_divBtn->Tag = L"4";
			this->_divBtn->Text = L"/";
			this->_divBtn->UseVisualStyleBackColor = true;
			this->_divBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _mulBtn
			// 
			this->_mulBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_mulBtn->Location = System::Drawing::Point(183, 65);
			this->_mulBtn->Name = L"_mulBtn";
			this->_mulBtn->Size = System::Drawing::Size(37, 34);
			this->_mulBtn->TabIndex = 0;
			this->_mulBtn->Tag = L"3";
			this->_mulBtn->Text = L"x";
			this->_mulBtn->UseVisualStyleBackColor = true;
			this->_mulBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _subBtn
			// 
			this->_subBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_subBtn->Location = System::Drawing::Point(183, 105);
			this->_subBtn->Name = L"_subBtn";
			this->_subBtn->Size = System::Drawing::Size(37, 34);
			this->_subBtn->TabIndex = 0;
			this->_subBtn->Tag = L"2";
			this->_subBtn->Text = L"-";
			this->_subBtn->UseVisualStyleBackColor = true;
			this->_subBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _plusBtn
			// 
			this->_plusBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_plusBtn->Location = System::Drawing::Point(183, 145);
			this->_plusBtn->Name = L"_plusBtn";
			this->_plusBtn->Size = System::Drawing::Size(37, 34);
			this->_plusBtn->TabIndex = 0;
			this->_plusBtn->Tag = L"1";
			this->_plusBtn->Text = L"+";
			this->_plusBtn->UseVisualStyleBackColor = true;
			this->_plusBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnOperationBtnClick);
			// 
			// _resultBtn
			// 
			this->_resultBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_resultBtn->Location = System::Drawing::Point(183, 185);
			this->_resultBtn->Name = L"_resultBtn";
			this->_resultBtn->Size = System::Drawing::Size(37, 74);
			this->_resultBtn->TabIndex = 0;
			this->_resultBtn->Text = L"=";
			this->_resultBtn->UseVisualStyleBackColor = true;
			this->_resultBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnResultBtnClick);
			// 
			// _clearBtn
			// 
			this->_clearBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_clearBtn->Location = System::Drawing::Point(54, 25);
			this->_clearBtn->Name = L"_clearBtn";
			this->_clearBtn->Size = System::Drawing::Size(80, 34);
			this->_clearBtn->TabIndex = 0;
			this->_clearBtn->Text = L"C";
			this->_clearBtn->UseVisualStyleBackColor = true;
			this->_clearBtn->Click += gcnew System::EventHandler(this, &CalcUI::OnClearBtnClick);
			// 
			// CalcUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(248, 322);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->_outputTxb);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"CalcUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Інженерний калькулятор";
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

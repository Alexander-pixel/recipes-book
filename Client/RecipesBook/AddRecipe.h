#pragma once
#include "RecipeBook.h"
#include "FillerInterface.h"

#define fileName "list_client.json"

namespace RecipesBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AddRecipe : public System::Windows::Forms::Form
	{
		FillerInterface^ mainForm;
	public:
		AddRecipe(void);

		AddRecipe(FillerInterface^ f_interface);

	protected:
		~AddRecipe();
	private: System::Windows::Forms::Label^ NameLabel;
	protected:
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::Button^ CancelButton;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ ingredientsTextBox;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ cookingStepsTextBox;
	private: System::Windows::Forms::TextBox^ weightTextBox;
	private: System::Windows::Forms::Label^ weightLabel;
	private: System::Windows::Forms::Label^ caloriesLabel;
	private: System::Windows::Forms::TextBox^ caloriesTextBox;
	private: System::Windows::Forms::Label^ cuisineLabel;
	private: System::Windows::Forms::TextBox^ cuisineTextBox;
	private: System::Windows::Forms::Label^ typeLabel;
	private: System::Windows::Forms::TextBox^ typeTextBox;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ingredientsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cookingStepsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->weightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->weightLabel = (gcnew System::Windows::Forms::Label());
			this->caloriesLabel = (gcnew System::Windows::Forms::Label());
			this->caloriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cuisineLabel = (gcnew System::Windows::Forms::Label());
			this->cuisineTextBox = (gcnew System::Windows::Forms::TextBox());
			this->typeLabel = (gcnew System::Windows::Forms::Label());
			this->typeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// NameLabel
			// 
			this->NameLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameLabel->Location = System::Drawing::Point(10, 57);
			this->NameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(353, 39);
			this->NameLabel->TabIndex = 20;
			this->NameLabel->Text = L"Enter title:";
			this->NameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameTextBox->Location = System::Drawing::Point(10, 100);
			this->nameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(353, 38);
			this->nameTextBox->TabIndex = 18;
			// 
			// CancelButton
			// 
			this->CancelButton->BackColor = System::Drawing::Color::Red;
			this->CancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CancelButton->Location = System::Drawing::Point(9, 819);
			this->CancelButton->Margin = System::Windows::Forms::Padding(4);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(353, 47);
			this->CancelButton->TabIndex = 17;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = false;
			this->CancelButton->Click += gcnew System::EventHandler(this, &AddRecipe::CancelButton_Click);
			// 
			// addButton
			// 
			this->addButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(9, 764);
			this->addButton->Margin = System::Windows::Forms::Padding(4);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(353, 47);
			this->addButton->TabIndex = 16;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = false;
			this->addButton->Click += gcnew System::EventHandler(this, &AddRecipe::addButton_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 6);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(353, 40);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Add new recipe to the recipe book";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(10, 140);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(353, 39);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Enter ingredient:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ingredientsTextBox
			// 
			this->ingredientsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ingredientsTextBox->Location = System::Drawing::Point(10, 182);
			this->ingredientsTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ingredientsTextBox->Name = L"ingredientsTextBox";
			this->ingredientsTextBox->Size = System::Drawing::Size(354, 38);
			this->ingredientsTextBox->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 222);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(353, 39);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Enter cooking steps:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cookingStepsTextBox
			// 
			this->cookingStepsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cookingStepsTextBox->Location = System::Drawing::Point(10, 265);
			this->cookingStepsTextBox->Margin = System::Windows::Forms::Padding(4);
			this->cookingStepsTextBox->Multiline = true;
			this->cookingStepsTextBox->Name = L"cookingStepsTextBox";
			this->cookingStepsTextBox->Size = System::Drawing::Size(354, 150);
			this->cookingStepsTextBox->TabIndex = 28;
			// 
			// weightTextBox
			// 
			this->weightTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weightTextBox->Location = System::Drawing::Point(11, 545);
			this->weightTextBox->Margin = System::Windows::Forms::Padding(4);
			this->weightTextBox->Name = L"weightTextBox";
			this->weightTextBox->Size = System::Drawing::Size(353, 38);
			this->weightTextBox->TabIndex = 32;
			// 
			// weightLabel
			// 
			this->weightLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->weightLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->weightLabel->Location = System::Drawing::Point(11, 502);
			this->weightLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->weightLabel->Name = L"weightLabel";
			this->weightLabel->Size = System::Drawing::Size(354, 39);
			this->weightLabel->TabIndex = 31;
			this->weightLabel->Text = L"Enter weight:";
			this->weightLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// caloriesLabel
			// 
			this->caloriesLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->caloriesLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->caloriesLabel->Location = System::Drawing::Point(11, 419);
			this->caloriesLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->caloriesLabel->Name = L"caloriesLabel";
			this->caloriesLabel->Size = System::Drawing::Size(353, 39);
			this->caloriesLabel->TabIndex = 30;
			this->caloriesLabel->Text = L"Enter calories:";
			this->caloriesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// caloriesTextBox
			// 
			this->caloriesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->caloriesTextBox->Location = System::Drawing::Point(11, 462);
			this->caloriesTextBox->Margin = System::Windows::Forms::Padding(4);
			this->caloriesTextBox->Name = L"caloriesTextBox";
			this->caloriesTextBox->Size = System::Drawing::Size(353, 38);
			this->caloriesTextBox->TabIndex = 29;
			// 
			// cuisineLabel
			// 
			this->cuisineLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->cuisineLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cuisineLabel->Location = System::Drawing::Point(10, 587);
			this->cuisineLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cuisineLabel->Name = L"cuisineLabel";
			this->cuisineLabel->Size = System::Drawing::Size(353, 39);
			this->cuisineLabel->TabIndex = 33;
			this->cuisineLabel->Text = L"Enter cuisine:";
			this->cuisineLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cuisineTextBox
			// 
			this->cuisineTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cuisineTextBox->Location = System::Drawing::Point(10, 630);
			this->cuisineTextBox->Margin = System::Windows::Forms::Padding(4);
			this->cuisineTextBox->Name = L"cuisineTextBox";
			this->cuisineTextBox->Size = System::Drawing::Size(353, 38);
			this->cuisineTextBox->TabIndex = 34;
			// 
			// typeLabel
			// 
			this->typeLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->typeLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->typeLabel->Location = System::Drawing::Point(9, 672);
			this->typeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->typeLabel->Name = L"typeLabel";
			this->typeLabel->Size = System::Drawing::Size(353, 39);
			this->typeLabel->TabIndex = 35;
			this->typeLabel->Text = L"Enter type:";
			this->typeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// typeTextBox
			// 
			this->typeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->typeTextBox->Location = System::Drawing::Point(9, 715);
			this->typeTextBox->Margin = System::Windows::Forms::Padding(4);
			this->typeTextBox->Name = L"typeTextBox";
			this->typeTextBox->Size = System::Drawing::Size(353, 38);
			this->typeTextBox->TabIndex = 36;
			// 
			// AddRecipe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(398, 868);
			this->Controls->Add(this->typeTextBox);
			this->Controls->Add(this->typeLabel);
			this->Controls->Add(this->cuisineTextBox);
			this->Controls->Add(this->cuisineLabel);
			this->Controls->Add(this->weightTextBox);
			this->Controls->Add(this->weightLabel);
			this->Controls->Add(this->caloriesLabel);
			this->Controls->Add(this->caloriesTextBox);
			this->Controls->Add(this->cookingStepsTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ingredientsTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->addButton);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddRecipe";
			this->Text = L"AddRecipe";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}

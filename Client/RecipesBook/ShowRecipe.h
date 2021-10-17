#pragma once

#include "FillerInterface.h"
#include "RecipeBook.h"
#include <map>

#define fileName "list_client.json"


namespace RecipesBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class ShowRecipe : public System::Windows::Forms::Form
	{
		FillerInterface^ mainForm;
	public:

		ShowRecipe(void);
		ShowRecipe(Dish& d);
		ShowRecipe(FillerInterface^ f_interface, Dish& d);

	private: System::Windows::Forms::TextBox^ typeTextBox;
	private: System::Windows::Forms::Label^ typeLabel;
	private: System::Windows::Forms::TextBox^ cuisinetextBox;
	private: System::Windows::Forms::Label^ cuisineLabel;

	protected:
		~ShowRecipe();

	private: System::Windows::Forms::TextBox^ cookingStepsTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ ingredientsTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::TextBox^ recipeTextBox;
	private: System::Windows::Forms::Button^ editButton;



	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ closeButton;
	private: System::Windows::Forms::Label^ caloriesLabel;
	private: System::Windows::Forms::TextBox^ caloriesTextBox;
	private: System::Windows::Forms::TextBox^ weightTextBox;
	private: System::Windows::Forms::Label^ weightLabel;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cookingStepsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ingredientsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->recipeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->caloriesLabel = (gcnew System::Windows::Forms::Label());
			this->caloriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->weightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->weightLabel = (gcnew System::Windows::Forms::Label());
			this->typeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->typeLabel = (gcnew System::Windows::Forms::Label());
			this->cuisinetextBox = (gcnew System::Windows::Forms::TextBox());
			this->cuisineLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// cookingStepsTextBox
			// 
			this->cookingStepsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cookingStepsTextBox->Location = System::Drawing::Point(9, 214);
			this->cookingStepsTextBox->Margin = System::Windows::Forms::Padding(4);
			this->cookingStepsTextBox->Multiline = true;
			this->cookingStepsTextBox->Name = L"cookingStepsTextBox";
			this->cookingStepsTextBox->ReadOnly = true;
			this->cookingStepsTextBox->Size = System::Drawing::Size(570, 150);
			this->cookingStepsTextBox->TabIndex = 36;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(9, 171);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(569, 39);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Cooking steps:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ingredientsTextBox
			// 
			this->ingredientsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ingredientsTextBox->Location = System::Drawing::Point(9, 131);
			this->ingredientsTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ingredientsTextBox->Name = L"ingredientsTextBox";
			this->ingredientsTextBox->ReadOnly = true;
			this->ingredientsTextBox->Size = System::Drawing::Size(570, 38);
			this->ingredientsTextBox->TabIndex = 34;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 88);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(569, 39);
			this->label2->TabIndex = 33;
			this->label2->Text = L"Ingredient:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// NameLabel
			// 
			this->NameLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameLabel->Location = System::Drawing::Point(9, 6);
			this->NameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(569, 39);
			this->NameLabel->TabIndex = 32;
			this->NameLabel->Text = L"Recipe title:";
			this->NameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// recipeTextBox
			// 
			this->recipeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recipeTextBox->Location = System::Drawing::Point(9, 49);
			this->recipeTextBox->Margin = System::Windows::Forms::Padding(4);
			this->recipeTextBox->Name = L"recipeTextBox";
			this->recipeTextBox->ReadOnly = true;
			this->recipeTextBox->Size = System::Drawing::Size(570, 38);
			this->recipeTextBox->TabIndex = 31;
			// 
			// editButton
			// 
			this->editButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->editButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editButton->Location = System::Drawing::Point(9, 820);
			this->editButton->Margin = System::Windows::Forms::Padding(4);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(569, 47);
			this->editButton->TabIndex = 30;
			this->editButton->Text = L"Edit";
			this->editButton->UseVisualStyleBackColor = false;
			this->editButton->Click += gcnew System::EventHandler(this, &ShowRecipe::editButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteButton->Location = System::Drawing::Point(9, 765);
			this->deleteButton->Margin = System::Windows::Forms::Padding(4);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(569, 47);
			this->deleteButton->TabIndex = 29;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &ShowRecipe::deleteButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->BackColor = System::Drawing::Color::Red;
			this->closeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeButton->Location = System::Drawing::Point(7, 875);
			this->closeButton->Margin = System::Windows::Forms::Padding(4);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(569, 47);
			this->closeButton->TabIndex = 37;
			this->closeButton->Text = L"Close";
			this->closeButton->UseVisualStyleBackColor = false;
			this->closeButton->Click += gcnew System::EventHandler(this, &ShowRecipe::closeButton_Click);
			// 
			// caloriesLabel
			// 
			this->caloriesLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->caloriesLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->caloriesLabel->Location = System::Drawing::Point(9, 366);
			this->caloriesLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->caloriesLabel->Name = L"caloriesLabel";
			this->caloriesLabel->Size = System::Drawing::Size(569, 39);
			this->caloriesLabel->TabIndex = 38;
			this->caloriesLabel->Text = L"Calories:";
			this->caloriesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// caloriesTextBox
			// 
			this->caloriesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->caloriesTextBox->Location = System::Drawing::Point(9, 409);
			this->caloriesTextBox->Margin = System::Windows::Forms::Padding(4);
			this->caloriesTextBox->Name = L"caloriesTextBox";
			this->caloriesTextBox->ReadOnly = true;
			this->caloriesTextBox->Size = System::Drawing::Size(570, 38);
			this->caloriesTextBox->TabIndex = 39;
			// 
			// weightTextBox
			// 
			this->weightTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weightTextBox->Location = System::Drawing::Point(9, 492);
			this->weightTextBox->Margin = System::Windows::Forms::Padding(4);
			this->weightTextBox->Name = L"weightTextBox";
			this->weightTextBox->ReadOnly = true;
			this->weightTextBox->Size = System::Drawing::Size(570, 38);
			this->weightTextBox->TabIndex = 41;
			// 
			// weightLabel
			// 
			this->weightLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->weightLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->weightLabel->Location = System::Drawing::Point(9, 449);
			this->weightLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->weightLabel->Name = L"weightLabel";
			this->weightLabel->Size = System::Drawing::Size(569, 39);
			this->weightLabel->TabIndex = 40;
			this->weightLabel->Text = L"Weight:";
			this->weightLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// typeTextBox
			// 
			this->typeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->typeTextBox->Location = System::Drawing::Point(9, 660);
			this->typeTextBox->Margin = System::Windows::Forms::Padding(4);
			this->typeTextBox->Name = L"typeTextBox";
			this->typeTextBox->ReadOnly = true;
			this->typeTextBox->Size = System::Drawing::Size(570, 38);
			this->typeTextBox->TabIndex = 45;
			// 
			// typeLabel
			// 
			this->typeLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->typeLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->typeLabel->Location = System::Drawing::Point(9, 617);
			this->typeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->typeLabel->Name = L"typeLabel";
			this->typeLabel->Size = System::Drawing::Size(569, 39);
			this->typeLabel->TabIndex = 44;
			this->typeLabel->Text = L"Type:";
			this->typeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cuisinetextBox
			// 
			this->cuisinetextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cuisinetextBox->Location = System::Drawing::Point(9, 577);
			this->cuisinetextBox->Margin = System::Windows::Forms::Padding(4);
			this->cuisinetextBox->Name = L"cuisinetextBox";
			this->cuisinetextBox->ReadOnly = true;
			this->cuisinetextBox->Size = System::Drawing::Size(570, 38);
			this->cuisinetextBox->TabIndex = 43;
			// 
			// cuisineLabel
			// 
			this->cuisineLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->cuisineLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cuisineLabel->Location = System::Drawing::Point(9, 534);
			this->cuisineLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cuisineLabel->Name = L"cuisineLabel";
			this->cuisineLabel->Size = System::Drawing::Size(569, 39);
			this->cuisineLabel->TabIndex = 42;
			this->cuisineLabel->Text = L"Cuisine:";
			this->cuisineLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ShowRecipe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(584, 928);
			this->Controls->Add(this->typeTextBox);
			this->Controls->Add(this->typeLabel);
			this->Controls->Add(this->cuisinetextBox);
			this->Controls->Add(this->cuisineLabel);
			this->Controls->Add(this->weightTextBox);
			this->Controls->Add(this->weightLabel);
			this->Controls->Add(this->caloriesTextBox);
			this->Controls->Add(this->caloriesLabel);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->cookingStepsTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ingredientsTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->recipeTextBox);
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->deleteButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ShowRecipe";
			this->Text = L"ShowRecipe";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void editButton_Click(System::Object^ sender, System::EventArgs^ e);
		
		private: System::Void closeButton_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}

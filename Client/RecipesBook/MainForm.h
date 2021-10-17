#pragma once

#include "AddRecipe.h"
#include "ShowRecipe.h"
#include "Client.h"
#include "FillerInterface.h"

#define fileName "list_client.json"

namespace RecipesBook 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MainForm : public System::Windows::Forms::Form, public FillerInterface
	{
		int counter;

	public:
		MainForm(void);

		void from_json(const nlohmann::json& j, Product& val);

		void to_json(nlohmann::json& j, const Product& val);

		Dish GetNewDish(const nlohmann::json& j, int position);

		void SaveRecipesToFile(std::string file, std::string recipes);

		Dish GetDishByTitle(RecipeBook recipesBook, String^ title);

		void FillPreviousRecipesOnForm(RecipeBook recipesBook);

		void FillSortedRecipes(RecipeBook recipesBook);

	    virtual void FillRecipes(RecipeBook book);

	    virtual RecipeBook GetActualMenu(std::string file);

	protected:
		~MainForm();
	private: System::Windows::Forms::ComboBox^ sortingComboBox;
	protected:
	private: System::Windows::Forms::Label^ TopText;
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::GroupBox^ elementOne;

	private: System::Windows::Forms::Label^ titleLabel_1;
	private: System::Windows::Forms::Button^ openButton_1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::Label^ titleLabel_2;


	private: System::Windows::Forms::Button^ openButton_2;

	private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::Label^ titleLabel_3;


	private: System::Windows::Forms::Button^ openButton_3;

	private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::Label^ titleLabel_4;


	private: System::Windows::Forms::Button^ openButton_4;

	private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::Label^ titleLabel_5;


	private: System::Windows::Forms::Button^ openButton_5;

	private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::Label^ titleLabel_6;


	private: System::Windows::Forms::Button^ openButton_6;

	private: System::Windows::Forms::Button^ nextPageButton;
	private: System::Windows::Forms::Button^ previousPageButton;
	private: System::Windows::Forms::Button^ addRecipeButton;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sortingComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->TopText = (gcnew System::Windows::Forms::Label());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->elementOne = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_1 = (gcnew System::Windows::Forms::Label());
			this->openButton_1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_2 = (gcnew System::Windows::Forms::Label());
			this->openButton_2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_3 = (gcnew System::Windows::Forms::Label());
			this->openButton_3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_4 = (gcnew System::Windows::Forms::Label());
			this->openButton_4 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_5 = (gcnew System::Windows::Forms::Label());
			this->openButton_5 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->titleLabel_6 = (gcnew System::Windows::Forms::Label());
			this->openButton_6 = (gcnew System::Windows::Forms::Button());
			this->nextPageButton = (gcnew System::Windows::Forms::Button());
			this->previousPageButton = (gcnew System::Windows::Forms::Button());
			this->addRecipeButton = (gcnew System::Windows::Forms::Button());
			this->elementOne->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// sortingComboBox
			// 
			this->sortingComboBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sortingComboBox->FormattingEnabled = true;
			this->sortingComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"По-умолчанию", L"Сортировка по национальностям",
					L"Сортировка по типу блюда"
			});
			this->sortingComboBox->Location = System::Drawing::Point(8, 67);
			this->sortingComboBox->Margin = System::Windows::Forms::Padding(2);
			this->sortingComboBox->Name = L"sortingComboBox";
			this->sortingComboBox->Size = System::Drawing::Size(247, 27);
			this->sortingComboBox->TabIndex = 0;
			// 
			// TopText
			// 
			this->TopText->BackColor = System::Drawing::Color::Moccasin;
			this->TopText->Dock = System::Windows::Forms::DockStyle::Top;
			this->TopText->Font = (gcnew System::Drawing::Font(L"Times New Roman", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TopText->ForeColor = System::Drawing::Color::MidnightBlue;
			this->TopText->Location = System::Drawing::Point(0, 0);
			this->TopText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TopText->Name = L"TopText";
			this->TopText->Size = System::Drawing::Size(1038, 59);
			this->TopText->TabIndex = 1;
			this->TopText->Text = L"Welcome to recipe book!";
			this->TopText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// searchTextBox
			// 
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->Location = System::Drawing::Point(261, 67);
			this->searchTextBox->Margin = System::Windows::Forms::Padding(4);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(646, 30);
			this->searchTextBox->TabIndex = 3;
			// 
			// searchButton
			// 
			this->searchButton->AutoSize = true;
			this->searchButton->BackColor = System::Drawing::Color::Chartreuse;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->searchButton->Location = System::Drawing::Point(913, 65);
			this->searchButton->Margin = System::Windows::Forms::Padding(2);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(115, 35);
			this->searchButton->TabIndex = 4;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &MainForm::searchButton_Click);
			// 
			// elementOne
			// 
			this->elementOne->Controls->Add(this->titleLabel_1);
			this->elementOne->Controls->Add(this->openButton_1);
			this->elementOne->Location = System::Drawing::Point(10, 135);
			this->elementOne->Margin = System::Windows::Forms::Padding(4);
			this->elementOne->Name = L"elementOne";
			this->elementOne->Padding = System::Windows::Forms::Padding(4);
			this->elementOne->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->elementOne->Size = System::Drawing::Size(332, 285);
			this->elementOne->TabIndex = 5;
			this->elementOne->TabStop = false;
			// 
			// titleLabel_1
			// 
			this->titleLabel_1->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_1->Location = System::Drawing::Point(8, 19);
			this->titleLabel_1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_1->Name = L"titleLabel_1";
			this->titleLabel_1->Size = System::Drawing::Size(316, 232);
			this->titleLabel_1->TabIndex = 1;
			this->titleLabel_1->Text = L"name";
			this->titleLabel_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_1
			// 
			this->openButton_1->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_1->Location = System::Drawing::Point(8, 255);
			this->openButton_1->Margin = System::Windows::Forms::Padding(4);
			this->openButton_1->Name = L"openButton_1";
			this->openButton_1->Size = System::Drawing::Size(316, 31);
			this->openButton_1->TabIndex = 0;
			this->openButton_1->Text = L"Open More";
			this->openButton_1->UseVisualStyleBackColor = false;
			this->openButton_1->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->titleLabel_2);
			this->groupBox1->Controls->Add(this->openButton_2);
			this->groupBox1->Location = System::Drawing::Point(350, 135);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox1->Size = System::Drawing::Size(332, 285);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			// 
			// titleLabel_2
			// 
			this->titleLabel_2->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_2->Location = System::Drawing::Point(8, 19);
			this->titleLabel_2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_2->Name = L"titleLabel_2";
			this->titleLabel_2->Size = System::Drawing::Size(316, 232);
			this->titleLabel_2->TabIndex = 1;
			this->titleLabel_2->Text = L"name";
			this->titleLabel_2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_2
			// 
			this->openButton_2->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_2->Location = System::Drawing::Point(8, 255);
			this->openButton_2->Margin = System::Windows::Forms::Padding(4);
			this->openButton_2->Name = L"openButton_2";
			this->openButton_2->Size = System::Drawing::Size(316, 31);
			this->openButton_2->TabIndex = 0;
			this->openButton_2->Text = L"Open More";
			this->openButton_2->UseVisualStyleBackColor = false;
			this->openButton_2->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->titleLabel_3);
			this->groupBox2->Controls->Add(this->openButton_3);
			this->groupBox2->Location = System::Drawing::Point(690, 135);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox2->Size = System::Drawing::Size(332, 285);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			// 
			// titleLabel_3
			// 
			this->titleLabel_3->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_3->Location = System::Drawing::Point(8, 19);
			this->titleLabel_3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_3->Name = L"titleLabel_3";
			this->titleLabel_3->Size = System::Drawing::Size(316, 232);
			this->titleLabel_3->TabIndex = 1;
			this->titleLabel_3->Text = L"name";
			this->titleLabel_3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_3
			// 
			this->openButton_3->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_3->Location = System::Drawing::Point(8, 255);
			this->openButton_3->Margin = System::Windows::Forms::Padding(4);
			this->openButton_3->Name = L"openButton_3";
			this->openButton_3->Size = System::Drawing::Size(316, 31);
			this->openButton_3->TabIndex = 0;
			this->openButton_3->Text = L"Open More";
			this->openButton_3->UseVisualStyleBackColor = false;
			this->openButton_3->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->titleLabel_4);
			this->groupBox3->Controls->Add(this->openButton_4);
			this->groupBox3->Location = System::Drawing::Point(10, 428);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox3->Size = System::Drawing::Size(332, 285);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			// 
			// titleLabel_4
			// 
			this->titleLabel_4->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_4->Location = System::Drawing::Point(8, 19);
			this->titleLabel_4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_4->Name = L"titleLabel_4";
			this->titleLabel_4->Size = System::Drawing::Size(316, 232);
			this->titleLabel_4->TabIndex = 1;
			this->titleLabel_4->Text = L"name";
			this->titleLabel_4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_4
			// 
			this->openButton_4->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_4->Location = System::Drawing::Point(8, 255);
			this->openButton_4->Margin = System::Windows::Forms::Padding(4);
			this->openButton_4->Name = L"openButton_4";
			this->openButton_4->Size = System::Drawing::Size(316, 31);
			this->openButton_4->TabIndex = 0;
			this->openButton_4->Text = L"Open More";
			this->openButton_4->UseVisualStyleBackColor = false;
			this->openButton_4->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->titleLabel_5);
			this->groupBox4->Controls->Add(this->openButton_5);
			this->groupBox4->Location = System::Drawing::Point(350, 428);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4);
			this->groupBox4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox4->Size = System::Drawing::Size(332, 285);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			// 
			// titleLabel_5
			// 
			this->titleLabel_5->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_5->Location = System::Drawing::Point(8, 19);
			this->titleLabel_5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_5->Name = L"titleLabel_5";
			this->titleLabel_5->Size = System::Drawing::Size(316, 232);
			this->titleLabel_5->TabIndex = 1;
			this->titleLabel_5->Text = L"name";
			this->titleLabel_5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_5
			// 
			this->openButton_5->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_5->Location = System::Drawing::Point(8, 255);
			this->openButton_5->Margin = System::Windows::Forms::Padding(4);
			this->openButton_5->Name = L"openButton_5";
			this->openButton_5->Size = System::Drawing::Size(316, 31);
			this->openButton_5->TabIndex = 0;
			this->openButton_5->Text = L"Open More";
			this->openButton_5->UseVisualStyleBackColor = false;
			this->openButton_5->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->titleLabel_6);
			this->groupBox5->Controls->Add(this->openButton_6);
			this->groupBox5->Location = System::Drawing::Point(690, 428);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4);
			this->groupBox5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox5->Size = System::Drawing::Size(332, 285);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			// 
			// titleLabel_6
			// 
			this->titleLabel_6->BackColor = System::Drawing::Color::Beige;
			this->titleLabel_6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLabel_6->Location = System::Drawing::Point(8, 19);
			this->titleLabel_6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->titleLabel_6->Name = L"titleLabel_6";
			this->titleLabel_6->Size = System::Drawing::Size(316, 232);
			this->titleLabel_6->TabIndex = 1;
			this->titleLabel_6->Text = L"name";
			this->titleLabel_6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openButton_6
			// 
			this->openButton_6->BackColor = System::Drawing::Color::DarkOrange;
			this->openButton_6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton_6->Location = System::Drawing::Point(8, 255);
			this->openButton_6->Margin = System::Windows::Forms::Padding(4);
			this->openButton_6->Name = L"openButton_6";
			this->openButton_6->Size = System::Drawing::Size(316, 31);
			this->openButton_6->TabIndex = 0;
			this->openButton_6->Text = L"Open More";
			this->openButton_6->UseVisualStyleBackColor = false;
			this->openButton_6->Click += gcnew System::EventHandler(this, &MainForm::openButton_1_Click);
			// 
			// nextPageButton
			// 
			this->nextPageButton->BackColor = System::Drawing::SystemColors::Menu;
			this->nextPageButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nextPageButton->ForeColor = System::Drawing::Color::DarkGreen;
			this->nextPageButton->Location = System::Drawing::Point(827, 719);
			this->nextPageButton->Margin = System::Windows::Forms::Padding(2);
			this->nextPageButton->Name = L"nextPageButton";
			this->nextPageButton->Size = System::Drawing::Size(195, 47);
			this->nextPageButton->TabIndex = 9;
			this->nextPageButton->Text = L"Next Page";
			this->nextPageButton->UseVisualStyleBackColor = false;
			this->nextPageButton->Click += gcnew System::EventHandler(this, &MainForm::nextPageButton_Click);
			// 
			// previousPageButton
			// 
			this->previousPageButton->BackColor = System::Drawing::SystemColors::Menu;
			this->previousPageButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->previousPageButton->ForeColor = System::Drawing::Color::Red;
			this->previousPageButton->Location = System::Drawing::Point(8, 719);
			this->previousPageButton->Margin = System::Windows::Forms::Padding(2);
			this->previousPageButton->Name = L"previousPageButton";
			this->previousPageButton->Size = System::Drawing::Size(216, 47);
			this->previousPageButton->TabIndex = 10;
			this->previousPageButton->Text = L"Previous Page";
			this->previousPageButton->UseVisualStyleBackColor = false;
			this->previousPageButton->Click += gcnew System::EventHandler(this, &MainForm::previousPageButton_Click);
			// 
			// addRecipeButton
			// 
			this->addRecipeButton->BackColor = System::Drawing::SystemColors::Menu;
			this->addRecipeButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addRecipeButton->ForeColor = System::Drawing::Color::ForestGreen;
			this->addRecipeButton->Location = System::Drawing::Point(228, 719);
			this->addRecipeButton->Margin = System::Windows::Forms::Padding(2);
			this->addRecipeButton->Name = L"addRecipeButton";
			this->addRecipeButton->Size = System::Drawing::Size(595, 47);
			this->addRecipeButton->TabIndex = 11;
			this->addRecipeButton->Text = L"Add recipe";
			this->addRecipeButton->UseVisualStyleBackColor = false;
			this->addRecipeButton->Click += gcnew System::EventHandler(this, &MainForm::addRecipeButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Bisque;
			this->ClientSize = System::Drawing::Size(1038, 768);
			this->Controls->Add(this->addRecipeButton);
			this->Controls->Add(this->previousPageButton);
			this->Controls->Add(this->nextPageButton);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->elementOne);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->TopText);
			this->Controls->Add(this->sortingComboBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Recipes Book";
			this->elementOne->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void openButton_1_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void addRecipeButton_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void nextPageButton_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void previousPageButton_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e);
	
};
}

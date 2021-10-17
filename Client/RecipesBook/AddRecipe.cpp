#include "AddRecipe.h"
#include <msclr\marshal_cppstd.h>
#include <map>

inline RecipesBook::AddRecipe::AddRecipe(void)
{
	InitializeComponent();
}

inline RecipesBook::AddRecipe::AddRecipe(FillerInterface^ f_interface)
{
	InitializeComponent();

	mainForm = f_interface;
}

inline RecipesBook::AddRecipe::~AddRecipe()
{
	if (components)
	{
		delete components;
	}
}

inline System::Void RecipesBook::AddRecipe::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Dish dish;

	if (nameTextBox->Text != "" && ingredientsTextBox->Text != "" && cookingStepsTextBox->Text != ""
		&& caloriesTextBox->Text != "" && weightTextBox->Text != "" && cuisineTextBox->Text != ""
		&& typeTextBox->Text != "")
	{
		msclr::interop::marshal_context context;
		std::string title = context.marshal_as<std::string>(nameTextBox->Text);
		std::string cookingSteps = context.marshal_as<std::string>(cookingStepsTextBox->Text);
		std::string ingredients = context.marshal_as<std::string>(ingredientsTextBox->Text);
		int calories = Int32::Parse(caloriesTextBox->Text);
		int weight = Int32::Parse(weightTextBox->Text);
		Cuisine enum_cuisine = Ukrainian;
		DishType enum_type = Salad;

		std::map<std::string, Cuisine> from_string_to_Cuisine =
		{
			{ "������������� �����", Indonesian },{ "�������� �����", Turkish },{ "���������� �����", Thai },
			{ "��������� �����", Spanish },{ "�������� �����", Japanese },{ "������������ �����", Moroccan },
			{ "��������� �����", Indian },{ "����������� �����", Italian },{ "���������� �����", French },
			{ "��������� �����", Chinese },{ "���������� �����", Ukrainian },{ "������� �����", Russian }
		};

		std::map<std::string, DishType> from_string_to_DishType =
		{
			{ "�������� �������", ColdSnacks },{ "������� �������", HotAppetizers },{ "�����", Salad },
			{ "������ �����", FirstCourses },{ "������ �����", SecondCourse },{ "������", SideDishes },
			{ "������", Desserts },{ "����", Sauce },{ "�������", Drink }
		};

		std::string cuisine = context.marshal_as<std::string>(cuisineTextBox->Text);
		std::string type = context.marshal_as<std::string>(typeTextBox->Text);

		auto res_find_cuisine = from_string_to_Cuisine.find(cuisine);
		auto res_find_type = from_string_to_DishType.find(type);

		if (res_find_cuisine == from_string_to_Cuisine.end())
		{
			MessageBox::Show("����� ����� ��� � ������!");
		}
		else 
		{
			enum_cuisine = res_find_cuisine->second;
		}

		if (res_find_type == from_string_to_DishType.end())
		{
			MessageBox::Show("������ ���� ����� ��� � ������!");
		}
		else
		{
			enum_type = res_find_type->second;
		}

		std::string delimiter = ", ";
		size_t pos = 0;
		std::string token;
		std::vector<Product> all_products;

		while ((pos = ingredients.find(delimiter)) != std::string::npos)
		{
			token = ingredients.substr(0, pos);
			all_products.push_back(Product(token, "", 0, 0));
			ingredients.erase(0, pos + delimiter.length());
		}

		dish = Dish(all_products, enum_cuisine, calories, weight, title, enum_type, cookingSteps);
		RecipeBook recipeBook = mainForm->GetActualMenu(fileName);
		recipeBook.AddDish(dish);
		MessageBox::Show("�� ������� �������� ������!");
		mainForm->FillRecipes(recipeBook);
		recipeBook.Print();
	}
	else
	{
		MessageBox::Show("��� ���� ������ ���� ���������!");
	}
	
}

inline System::Void RecipesBook::AddRecipe::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

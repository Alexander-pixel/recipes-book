#include "MainForm.h"
#include <msclr\marshal_cppstd.h>

using namespace System::Windows::Forms;

void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RecipesBook::MainForm form;
    form.AutoSize = true;
    Application::Run(% form);
}

inline System::Void RecipesBook::MainForm::openButton_1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ button = (Button^)sender;
	RecipeBook recipesBook = GetActualMenu(fileName);

	Dish d;
	String^ recipeName;

	if (button->Name[button->Name->Length - 1] == '1')
	{
		recipeName = titleLabel_1->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}
	else if (button->Name[button->Name->Length - 1] == '2')
	{
		recipeName = titleLabel_2->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}
	else if (button->Name[button->Name->Length - 1] == '3')
	{
		recipeName = titleLabel_3->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}
	else if (button->Name[button->Name->Length - 1] == '4')
	{
		recipeName = titleLabel_4->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}
	else if (button->Name[button->Name->Length - 1] == '5')
	{
		recipeName = titleLabel_5->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}
	else if (button->Name[button->Name->Length - 1] == '6')
	{
		recipeName = titleLabel_6->Text;
		d = GetDishByTitle(recipesBook, recipeName);
	}

	counter = 0;
	ShowRecipe form(this, d);
	form.ShowDialog();
}

inline System::Void RecipesBook::MainForm::searchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sortingComboBox->Text == "По-умолчанию" || sortingComboBox->Text == "")
	{
		RecipeBook book = GetActualMenu(fileName);
		FillRecipes(book);
	}
	else if (searchTextBox->Text != "")
	{
		//std::string result = msclr::interop::marshal_as<std::string>(searchTextBox->Text);

		msclr::interop::marshal_context context;
		std::string result = context.marshal_as<std::string>(searchTextBox->Text);

		if (sortingComboBox->Text == "Сортировка по национальностям")
		{
			std::map<std::string, Cuisine> from_string_to_Cuisine =
			{
				{ "Индонезийская кухня", Indonesian },{ "Турецкая кухня", Turkish },{ "Тайванская кухня", Thai },
				{ "Испанская кухня", Spanish },{ "Японская кухня", Japanese },{ "Марокканская кухня", Moroccan },
				{ "Индийская кухня", Indian },{ "Итальянская кухня", Italian },{ "Французкая кухня", French },
				{ "Китайская кухня", Chinese },{ "Украинская кухня", Ukrainian },{ "Русская кухня", Russian }
			};

			auto find_result = from_string_to_Cuisine.find(result);

			if (find_result == from_string_to_Cuisine.end())
			{
				MessageBox::Show("Такой кухни нет в списке");
			}
			else
			{
				RecipeBook tmp = GetActualMenu(fileName);

				RecipeBook sortCuisine = tmp.GetByCuisine(find_result->second);

				FillSortedRecipes(sortCuisine);
			}
		}
		else if (sortingComboBox->Text == "Сортировка по типу блюда")
		{
			std::map<std::string, DishType> from_string_to_DishType =
			{
				{ "Холодная закуска", ColdSnacks },{ "Горячая закуска", HotAppetizers },{ "Салат", Salad },
				{ "Первое блюдо", FirstCourses },{ "Второе блюдо", SecondCourse },{ "Гарнир", SideDishes },
				{ "Десерт", Desserts },{ "Соус", Sauce },{ "Напиток", Drink }
			};

			auto find_result = from_string_to_DishType.find(result);

			if (find_result == from_string_to_DishType.end())
			{
				MessageBox::Show("Такого типа блюда нет в списке");
			}
			else
			{
				RecipeBook tmp = GetActualMenu(fileName);

				RecipeBook sortCuisine = tmp.GetByType(find_result->second);

				FillSortedRecipes(sortCuisine);
			}
		}

	}

}

inline System::Void RecipesBook::MainForm::addRecipeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddRecipe form(this);
	form.ShowDialog();
}

inline System::Void RecipesBook::MainForm::nextPageButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	RecipeBook recipesBook = GetActualMenu(fileName);
	FillRecipes(recipesBook);

	previousPageButton->Enabled = true;
}

inline System::Void RecipesBook::MainForm::previousPageButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	RecipeBook recipesBook = GetActualMenu(fileName);

	FillPreviousRecipesOnForm(recipesBook);
	nextPageButton->Enabled = true;
}

inline RecipesBook::MainForm::~MainForm(void)
{
	if (components)
	{
		delete components;
	}
}

inline void RecipesBook::MainForm::FillRecipes(RecipeBook book)
{
	std::vector<Dish> recipe = book.GetRecipes();

	if (counter + 6 < recipe.size())
	{
		nextPageButton->Enabled = true;

		String^ title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_1->Text = title;

		title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_2->Text = title;

		title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_3->Text = title;

		title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_4->Text = title;

		title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_5->Text = title;

		title = gcnew String(recipe[counter++].GetTitle().c_str());
		titleLabel_6->Text = title;

	}
	else
	{
		nextPageButton->Enabled = false;
	}

}

inline RecipeBook RecipesBook::MainForm::GetActualMenu(std::string file)
{
	nlohmann::json j;
	std::fstream fin(file);
	fin >> j;

	if (fin.is_open())
	{
		std::cout << "File is open." << std::endl;
		try
		{
			RecipeBook recipeBook;
			for (int i = 1; i <= 24; i++)
			{
				recipeBook.AddDish(GetNewDish(j, i));
			}

			return recipeBook;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	else
	{
		std::cout << "File not found." << std::endl;
	}
	return RecipeBook();
}

void RecipesBook::MainForm::from_json(const nlohmann::json& j, Product& val)
{
	std::string title, type;
	int calories, weight;

	j.at("productTitle").get_to(title);
	j.at("productType").get_to(type);
	j.at("calories").get_to(calories);
	j.at("weight").get_to(weight);

	val = Product(title, type, calories, weight);
}

void RecipesBook::MainForm::to_json(nlohmann::json& j, const Product& val)
{
	j["productTitle"] = val.GetProductTitle();
	j["productType"] = val.GetProductType();
	j["calories"] = val.GetCalories();
	j["weight"] = val.GetWeight();
}

Dish RecipesBook::MainForm::GetNewDish(const nlohmann::json& j, int position)
{
	std::vector<Product> products_for_dish;
	Dish dishforbook;

	for (const auto& dish : j["dish" + std::to_string(position)].items())
	{
		for (const auto& products : dish.value()["products"])
		{
			for (const auto& product : products)
			{
				Product prod;
				from_json(product, prod);
				products_for_dish.push_back(prod);
			}
		}

		dishforbook.SetCuisine(dish.value()["cuisine"].get<Cuisine>());
		dishforbook.SetCalories(dish.value()["calories"].get<int>());
		dishforbook.SetWeight(dish.value()["weight"].get<int>());
		dishforbook.SetTitle(dish.value()["title"].get<std::string>());
		dishforbook.SetType(dish.value()["dishType"].get<DishType>());
		dishforbook.SetProducts(products_for_dish);
		dishforbook.SetCookingSteps(dish.value()["cookingSteps"].get<std::string>());

		products_for_dish.clear();
	}

	return dishforbook;
}

void RecipesBook::MainForm::SaveRecipesToFile(std::string file, std::string recipes)
{
	std::ofstream of(file);

	if (of.is_open())
	{
		of << recipes;
	}
	else
	{
		MessageBox::Show("Could not save information to file.");
	}
}

Dish RecipesBook::MainForm::GetDishByTitle(RecipeBook recipesBook, String^ title)
{
	for (int i = 0; i < recipesBook.GetRecipes().size(); i++)
	{
		String^ recipeTitle = gcnew String(recipesBook.GetRecipes()[i].GetTitle().c_str());
		if (title == recipeTitle)
		{
			return recipesBook.GetRecipes()[i];
		}
	}
	return Dish();
}

void RecipesBook::MainForm::FillPreviousRecipesOnForm(RecipeBook recipesBook)
{
	std::vector<Dish> recipe = recipesBook.GetRecipes();

	if (counter - 6 > 0)
	{
		previousPageButton->Enabled = true;

		String^ title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_1->Text = title;

		title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_2->Text = title;

		title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_3->Text = title;

		title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_4->Text = title;

		title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_5->Text = title;

		title = gcnew String(recipe[--counter].GetTitle().c_str());
		titleLabel_6->Text = title;
	}
	else
	{
		previousPageButton->Enabled = false;
	}
}

void RecipesBook::MainForm::FillSortedRecipes(RecipeBook recipesBook)
{
	const int count_recipes = recipesBook.GetRecipes().size();
	std::vector<Dish> recipe = recipesBook.GetRecipes();
	int current_position = 0;
	String^ title;

	if (count_recipes > 6)
	{
		int pages = count_recipes / 6;

		for (int i = 0; i < pages; i++)
		{
			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_1->Text = title;

			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_2->Text = title;

			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_3->Text = title;

			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_4->Text = title;

			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_5->Text = title;

			title = gcnew String(recipe[current_position++].GetTitle().c_str());
			titleLabel_6->Text = title;
		}
	}
	else
	{
		nextPageButton->Enabled = false;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_1->Text = title;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_2->Text = title;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_3->Text = title;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_4->Text = title;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_5->Text = title;

		title = gcnew String(recipe[current_position++].GetTitle().c_str());
		titleLabel_6->Text = title;
	}
	searchTextBox->Text = "";
	sortingComboBox->Text = "По-умолчанию";
}

RecipesBook::MainForm::MainForm(void)
{
	InitializeComponent();

	counter = 0;
	previousPageButton->Enabled = false;

	// get last version of recipes book
	try
	{
		Client client;
		std::string recipes = client.RecieveMessageFromServer();
		SaveRecipesToFile(fileName, recipes);

		// save last version of recipes book to file
		RecipeBook recipesBook = GetActualMenu(fileName);

		// fill first 6 recipes
		FillRecipes(recipesBook);
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show("Нет доступа к серверу!");
		//this->Close();
	}
}

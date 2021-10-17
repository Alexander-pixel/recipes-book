#include "ShowRecipe.h"
#include <msclr\marshal_cppstd.h>


inline System::Void RecipesBook::ShowRecipe::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	std::string res = context.marshal_as<std::string>(recipeTextBox->Text);
	RecipeBook book = mainForm->GetActualMenu(fileName);

	for (int i = 0; i < book.GetRecipes().size(); i++)
	{
		if (res == book.GetRecipes()[i].GetTitle())
		{
			book.DeleteDish(book.GetRecipes()[i]);
			break;
		}
	}

	MessageBox::Show("You have successfully deleted recipe.");

	mainForm->FillRecipes(book);
	this->Close();
}

inline RecipesBook::ShowRecipe::~ShowRecipe(void)
{
	if (components)
	{
		delete components;
	}
}

inline System::Void RecipesBook::ShowRecipe::editButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	recipeTextBox->ReadOnly = false;
	cookingStepsTextBox->ReadOnly = false;
	caloriesTextBox->ReadOnly = false;
	weightTextBox->ReadOnly = false;
	
	if (recipeTextBox->Text != "" && cookingStepsTextBox->Text != ""
		&& caloriesTextBox->Text != "" && weightTextBox->Text != "")
	{
		msclr::interop::marshal_context context;
		std::string title = context.marshal_as<std::string>(recipeTextBox->Text);
		std::string cookingSteps = context.marshal_as<std::string>(cookingStepsTextBox->Text);
		int calories = Int32::Parse(caloriesTextBox->Text);
		int weight = Int32::Parse(weightTextBox->Text);

		RecipeBook book = mainForm->GetActualMenu(fileName);
		Dish result;
		
		for (int i = 0; i < book.GetRecipes().size(); i++)
		{
			if (title == book.GetRecipes()[i].GetTitle())
			{
				result = book.GetRecipes()[i];
				book.DeleteDish(book.GetRecipes()[i]);
				break;
			}
		}

		book.AddDish(Dish(result.GetProducts(), result.GetCuisine(), calories, weight,
			title, result.GetType(), cookingSteps));

		MessageBox::Show("Рецепт был успешно изменен!");
		mainForm->FillRecipes(book);
		book.Print();
	}
	else
	{
		MessageBox::Show("Все поля должны содержать текст!");
	}
}

inline System::Void RecipesBook::ShowRecipe::closeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

inline RecipesBook::ShowRecipe::ShowRecipe(void)
{
	InitializeComponent();
}

inline RecipesBook::ShowRecipe::ShowRecipe(Dish& d)
{
	InitializeComponent();

	String^ title = gcnew String(d.GetTitle().c_str());
	recipeTextBox->Text = title;

	std::string all_products;
	for (size_t i = 0; i < d.GetProducts().size(); i++)
	{
		if (i != d.GetProducts().size() - 1)
		{
			all_products += d.GetProducts()[i].GetProductTitle() + ", ";
		}
		else
		{
			all_products += d.GetProducts()[i].GetProductTitle();
		}
	}

	title = gcnew String(all_products.c_str());
	ingredientsTextBox->Text = title;

	title = gcnew String(d.GetCookingSteps().c_str());
	cookingStepsTextBox->Text = title;

	title = gcnew String(std::to_string(d.GetCalories()).c_str());
	caloriesTextBox->Text = title;

	title = gcnew String(std::to_string(d.GetWeight()).c_str());
	weightTextBox->Text = title;
}

inline RecipesBook::ShowRecipe::ShowRecipe(FillerInterface^ f_interface, Dish& d)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	mainForm = f_interface;

	String^ title = gcnew String(d.GetTitle().c_str());
	recipeTextBox->Text = title;

	std::string all_products;
	for (size_t i = 0; i < d.GetProducts().size(); i++)
	{
		if (i != d.GetProducts().size() - 1)
		{
			all_products += d.GetProducts()[i].GetProductTitle() + ", ";
		}
		else
		{
			all_products += d.GetProducts()[i].GetProductTitle();
		}
	}

	title = gcnew String(all_products.c_str());
	ingredientsTextBox->Text = title;

	title = gcnew String(d.GetCookingSteps().c_str());
	cookingStepsTextBox->Text = title;

	title = gcnew String(std::to_string(d.GetCalories()).c_str());
	caloriesTextBox->Text = title;

	title = gcnew String(std::to_string(d.GetWeight()).c_str());
	weightTextBox->Text = title;

	std::map<Cuisine, std::string> from_Cuisine_to_string =
	{
		{ Indonesian, "Индонезийская кухня",},{ Turkish, "Турецкая кухня" },{Thai,"Тайванская кухня"},
		{Spanish, "Испанская кухня" },{ Japanese ,"Японская кухня" },{ Moroccan, "Марокканская кухня" },
		{ Indian, "Индийская кухня" },{Italian, "Итальянская кухня" },{ French, "Французкая кухня" },
		{Chinese, "Китайская кухня" },{Ukrainian, "Украинская кухня" },{Russian, "Русская кухня"}
	};

	std::map<DishType, std::string> from_DishType_to_string =
	{
		{ ColdSnacks, "Холодная закуска" },{ HotAppetizers, "Горячая закуска" },{ Salad, "Салат" },
		{FirstCourses, "Первое блюдо" },{ SecondCourse, "Второе блюдо" },{ SideDishes, "Гарнир" },
		{Desserts, "Десерт" },{ Sauce,"Соус" },{Drink, "Напиток" }
	};

	cuisinetextBox->Text = gcnew String(from_Cuisine_to_string.find(d.GetCuisine())->second.c_str());
	typeTextBox->Text = gcnew String(from_DishType_to_string.find(d.GetType())->second.c_str());


}
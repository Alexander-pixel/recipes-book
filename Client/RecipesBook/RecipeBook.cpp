#include "RecipeBook.h"

RecipeBook::RecipeBook()
{
    _title = "";
}

RecipeBook::RecipeBook(std::vector<Dish> recipes, std::string title)
{
    _recipes = recipes;
    _title = title;
}

void RecipeBook::AddDish(Dish dish)
{
    _recipes.push_back(dish);
}

void RecipeBook::DeleteDish(Dish dish)
{
    try
    {
        for (auto it = _recipes.begin(); it != _recipes.end(); it++)
        {
            if (it->GetTitle() == dish.GetTitle())
            {
                _recipes.erase(it);
                break;
            }
        }
    }
    catch (const std::exception&)
    {
        std::cout << "Error" << std::endl;
    }
    
}

RecipeBook RecipeBook::GetByCuisine(Cuisine cuisine)
{
    RecipeBook result;

    for (auto recipe : _recipes)
    {
        if (recipe.GetCuisine() == cuisine)
            result.AddDish(recipe);
    }
    return result;
}

RecipeBook RecipeBook::GetByType(DishType dishType)
{
    RecipeBook result;
    for (auto recipe : _recipes)
        if (recipe.GetType() == dishType)
            result.AddDish(recipe);
    return result;
}

RecipeBook RecipeBook::GetByProduct(Product& product)
{
    RecipeBook result;
    for (auto recipe : _recipes)
        if (recipe.IsUsed(product))
            result.AddDish(recipe);
    return result;
}

void RecipeBook::Print()const
{
    for (int i = 0; i < _recipes.size(); i++)
    {
        _recipes[i].Print();
        std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
    }
}

std::string RecipeBook::GetTitle()const
{
    return _title;
}

void RecipeBook::SetTitle(std::string title)
{
    _title = title;
}

std::vector<Dish> RecipeBook::GetRecipes()const
{
    return _recipes;
}
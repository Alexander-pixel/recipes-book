#pragma once

#include "Dish.h"

class RecipeBook
{
    std::vector<Dish> _recipes;
    std::string _title;

public:
    RecipeBook();
    RecipeBook(std::vector<Dish> recipes, std::string title);

    void AddDish(Dish dish);
    void DeleteDish(Dish dish);

    void SetTitle(std::string title);
    std::string GetTitle()const;

    std::vector<Dish> GetRecipes()const;

    void Print()const;

    RecipeBook GetByCuisine(Cuisine cuisine);
    RecipeBook GetByType(DishType dishType);
    RecipeBook GetByProduct(Product& product);
};

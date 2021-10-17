#include "Dish.h"

Dish::Dish()
{
    _cuisine = Indonesian;
    _calories = 0;
    _weight = 0;
    _title = "";
    _dishType = Salad;
}

Dish::Dish(std::vector<Product> products, Cuisine cuisine, int calories, int weight, std::string title, DishType dishType, std::string cookingSteps)
{
    _products = products;
    _cuisine = cuisine;

    if (calories > 0)
        _calories = calories;
    else
        _calories = 0;

    if (weight > 0)
        _weight = weight;
    else
        _weight = 0;

    _title = title;
    _dishType = dishType;
    _cookingSteps = cookingSteps;
}

void Dish::AddProduct(const Product& product)
{
    _products.push_back(product);
}

void Dish::DeleteProduct(Product product)
{
    std::vector<Product>::iterator it1;
    for (auto it = _products.begin(); it != _products.end(); it++)
        if (*it == product)
            it1 = it;

    _products.erase(it1);
}

Cuisine Dish::GetCuisine()const
{
    return _cuisine;
}

void Dish::SetCuisine(Cuisine cuisine)
{
    _cuisine = cuisine;
}

int Dish::GetCalories()const
{
    return _calories;
}

void Dish::SetCalories(int calories)
{
    if (calories > 0)
        _calories = calories;
    else
        _calories = 0;
}

int Dish::GetWeight()const
{
    return _weight;
}

void Dish::SetWeight(int weight)
{
    if (weight > 0)
        _weight = weight;
    else
        _weight = 0;
}

std::string Dish::GetTitle()const
{
    return _title;
}

void Dish::SetTitle(std::string title)
{
    _title = title;
}

DishType Dish::GetType()const
{
    return _dishType;
}

void Dish::SetType(DishType dishType)
{
    _dishType = dishType;
}

void Dish::Print()const
{
    std::cout << "Dish title: " << _title << std::endl;
    std::cout << "Cuisine: " << _cuisine << std::endl;
    std::cout << "Calories: " << _calories << std::endl;
    std::cout << "Weight: " << _weight << std::endl;
    std::cout << "Dish type: " << _dishType << std::endl;
    std::cout << "Cooking steps: " << _cookingSteps << std::endl;
    for (auto item : _products)
    {
        item.Print();
    }
}

bool Dish::operator==(const Dish& r)
{
    return this->_title == r._title;
}

bool Dish::IsUsed(Product product)
{
    for (auto item : _products)
        if (item.GetProductTitle() == product.GetProductTitle())
            return true;
    return false;
}

std::vector<Product> Dish::GetProducts()const
{
    return _products;
}

void Dish::SetProducts(std::vector<Product> products)
{
    _products = products;
}

void Dish::SetCookingSteps(std::string cookingSteps)
{
    _cookingSteps = cookingSteps;
}

std::string Dish::GetCookingSteps()const
{
    return _cookingSteps;
}
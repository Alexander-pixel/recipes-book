#pragma once

#include "Product.h"
#include "Cuisine.h"
#include "DishType.h"
#include <vector>

class Dish
{
    std::vector<Product> _products;
    Cuisine _cuisine;
    int _calories;
    int _weight;
    std::string _title;
    DishType _dishType;
    std::string _cookingSteps;
public:
    Dish();
    Dish(std::vector<Product> products, Cuisine cuisine, int calories, int weight, std::string title, DishType dishType, std::string cookingSteps);

    void AddProduct(const Product& product);
    void DeleteProduct(Product product);

    std::string GetCookingSteps()const;
    void SetCookingSteps(std::string cookingSteps);

    Cuisine GetCuisine()const;
    void SetCuisine(Cuisine cuisine);

    int GetCalories()const;
    void SetCalories(int calories);

    int GetWeight()const;
    void SetWeight(int weight);

    std::string GetTitle()const;
    void SetTitle(std::string title);

    std::vector<Product> GetProducts()const;
    void SetProducts(std::vector<Product> products);

    DishType GetType()const;
    void SetType(DishType dishType);

    void Print()const;

    bool operator==(const Dish& r);

    bool IsUsed(Product product);
};
#include "Product.h"

Product::Product()
{
    _productType = "";
    _productTitle = "";
    _calories = 0;
    _weight = 0;
}

Product::Product(std::string productTitle, std::string productType, int calories, int weight)
{
    _productType = productType;
    _productTitle = productTitle;

    if (calories > 0)
        _calories = calories;
    else
        _calories = 0;

    if (weight > 0)
        _weight = weight;
    else
        _weight = 0;
}

void Product::SetProductTitle(std::string productTitle)
{
    _productTitle = productTitle;
}

std::string Product::GetProductTitle()const
{
    return _productTitle;
}

void Product::SetProductType(std::string productType)
{
    _productType = productType;
}

std::string Product::GetProductType()const
{
    return _productType;
}

void Product::SetCalories(int calories)
{
    if (calories > 0)
        _calories = calories;
    else
        _calories = 0;
}

int Product::GetCalories()const
{
    return _calories;
}

int Product::GetWeight()const
{
    return _weight;
}

void Product::SetWeight(int weight)
{
    if (weight > 0)
        _weight = weight;
    else
        _weight = 0;
}

void Product::Print()const
{
    std::cout << "Product Title: " + _productTitle << std::endl;
    std::cout << "Product Type: " + _productType << std::endl;
    std::cout << "Calories: " << _calories << std::endl;
    std::cout << "Weight: " << _weight << std::endl;
}

bool Product::operator==(const Product& r)
{
    return this->_productTitle == r._productTitle;
}

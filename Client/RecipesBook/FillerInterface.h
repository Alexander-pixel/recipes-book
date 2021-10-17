#pragma once

#include "RecipeBook.h"

public interface class FillerInterface
{
public:
	void FillRecipes(RecipeBook book);

	RecipeBook GetActualMenu(std::string file);
};


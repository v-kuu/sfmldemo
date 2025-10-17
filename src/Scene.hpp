#pragma once

#include "IObject.hpp"
#include <vector>
#include <memory>

struct	Scene
{
		Scene(void);

		std::vector<std::unique_ptr<IObject>> objects;
};

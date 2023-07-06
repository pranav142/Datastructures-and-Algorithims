#include <iostream>
#include <vector>


int get_index_best_item(std::vector<std::tuple<int, int>>& items)
{
	int best_value_per_weight = 0;
	int best_index = -1;

	for (int i = 0; i < items.size(); i++) 
	{	
		double weight = std::get<0>(items[i]);
		double value = std::get<1>(items[i]);

		if (weight > 0)
		{
			double value_per_weight = value / weight;

			if (value_per_weight > best_value_per_weight)
			{
				best_value_per_weight = value_per_weight;
				best_index = i;
			}
		}
	}

	return best_index;
}

int calculate_amount_to_steal(int item_weight, int carrying_capacity)
{
	if (item_weight > carrying_capacity)
		return carrying_capacity;
	else 
		return item_weight;
}
std::tuple<int, std::vector<int>> loot_max_value(std::vector<std::tuple<int, int>>& items, int carrying_capacity)
{	
	std::vector<int> amounts(items.size(), 0);
	int value_stolen = 0;
	for(int i = 0; i < items.size(); i++)
	{	
		if (carrying_capacity == 0)
			return std::make_tuple(value_stolen, amounts);
		int best_index  = get_index_best_item(items);
		double item_weight = std::get<0>(items[best_index]);
		double item_value  = std::get<1>(items[best_index]);
		double amount_stolen = calculate_amount_to_steal(item_weight, carrying_capacity);
		value_stolen += amount_stolen * (item_value / item_weight);
		std::get<0>(items[best_index]) -= amount_stolen;
		amounts[best_index] += amount_stolen;
		carrying_capacity -= amount_stolen;
	}
	return std::make_tuple(value_stolen, amounts);
}
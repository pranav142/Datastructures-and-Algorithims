#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<int, int>> find_best_group(const std::vector<int>& children_ages)
{
	/*This funciton takes a group of childrens age and creates group where no child in each group
	is more than two years apart o(n) complexity; if you have to sort childrens age then o(nlog(n))*/
	int left = 0;
	std::vector<std::tuple<int, int>> segments;

	while (left < children_ages.size())
	{	
		int left_age = children_ages[left];
		int right_age = children_ages[left] + 2;
		segments.push_back(std::make_tuple(left_age, right_age));
		
		left++;
		while (left < children_ages.size() && children_ages[left] <= right_age)
		{
			left++;
		}	
	}

	return segments;
}
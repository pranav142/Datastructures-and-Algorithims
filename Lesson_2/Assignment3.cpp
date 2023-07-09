#include <iostream>
#include <vector>
#include <algorithm>


/* Problem 1 */
int find_minimum_coins(int& amount)
{
	const int DIME = 10;
	const int NICKEL = 5;
	const int PENNY = 1;
	int num_coins = 0;

	while (amount > 0)
	{
		if (amount >= DIME)
			amount -= DIME;
		else if (amount >= NICKEL)
			amount -= NICKEL;
		else
			amount -= PENNY;

		num_coins++;
	}

	return num_coins;
}

/* Problem 3 */
int find_max_index(std::vector<int>& vec)
{
	int largest_index = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] > vec[largest_index])
			largest_index = i;
	}

	return largest_index;
}

int find_maximum_ad_revenue(std::vector<int>& num_clicks, std::vector<int>& ad_pay)
{	
	int ad_revenue = 0;
	while(!num_clicks.empty())
	{
		int largest_num_clicks_index = find_max_index(num_clicks);
		int largest_ad_pay_index = find_max_index(ad_pay);
		ad_revenue += num_clicks[largest_num_clicks_index] * ad_pay[largest_ad_pay_index];
		std::vector<int>::iterator clicks_it = num_clicks.begin() + largest_num_clicks_index;
		std::vector<int>::iterator ad_it = ad_pay.begin() + largest_ad_pay_index;
		num_clicks.erase(clicks_it);
		ad_pay.erase(ad_it);
	}

	return ad_revenue;
}
/* Problem 4 */

std::tuple<int, int> calculate_new_intersection(std::tuple<int, int> tuple1, std::tuple<int, int> tuple2)
{
	int tuple1Min = std::get<0>(tuple1);
	int tuple1Max = std::get<1>(tuple1);

	int tuple2Min = std::get<0>(tuple2);
	int tuple2Max = std::get<1>(tuple2);

	int newIntersectionMin = std::max(tuple1Min, tuple2Min);
	int newIntersectionMax = std::min(tuple1Max, tuple2Max);

	if (newIntersectionMin > newIntersectionMax) {
		return std::make_tuple(0, -1);
	}

	return std::make_tuple(newIntersectionMin, newIntersectionMax);
}

bool is_intersecting(std::tuple<int, int> a, std::tuple<int, int> b)
{
	int tuple1Min = std::get<0>(a);
	int tuple1Max = std::get<1>(a);

	int tuple2Min = std::get<0>(b);
	int tuple2Max = std::get<1>(b);

	return (tuple1Min <= tuple2Max) && (tuple1Max >= tuple2Min);
}

void remove_indicies(std::vector<std::tuple<int, int>>& segments, std::vector<int> indexes_to_delete)
{
	std::sort(indexes_to_delete.begin(), indexes_to_delete.end(), std::greater<int>());

	for (const auto& index : indexes_to_delete)
	{
		segments.erase(segments.begin() + index);
	}
}

int intersections(std::vector<std::tuple<int, int>>& segments)
{
	std::tuple<int, int> intersection_segment = segments[0];
	segments.erase(segments.begin());
	std::vector<int> indexes_to_delete;

	if (segments.size() == 1)
		return std::get<1>(segments[0]);

	for (auto i = 0; i < segments.size(); i++)
	{
		if (is_intersecting(intersection_segment, segments[i]))
		{
			intersection_segment = calculate_new_intersection(intersection_segment, segments[i]);
			indexes_to_delete.push_back(i);
		}
	}

	remove_indicies(segments, indexes_to_delete);

	return std::get<1>(intersection_segment);
}

std::vector<int> find_least_segment_intersections(std::vector<std::tuple<int, int>>& segments)
{	
	std::vector<int> intersection_points;
	while (!segments.empty())
	{
		intersection_points.push_back(intersections(segments));
	}

	return intersection_points;
}

/* Problem 5 */

std::vector<int> find_max_prizes(int& num_candies)
{	
	std::vector<int> candy_distribution;
	if (num_candies == 0)
	{
		candy_distribution.push_back(0);
		return candy_distribution;
	}
		
	candy_distribution.push_back(1);
	num_candies -= 1;
	int index = 1;

	while (num_candies)
	{
		if (num_candies < candy_distribution[index - 1] + 1)
		{
			candy_distribution[index - 1] += num_candies;
			num_candies = 0;
		}
		else 
		{
			candy_distribution.push_back(candy_distribution[index - 1] + 1);
			num_candies -= candy_distribution[index];
		}

		index++;
	}

	return candy_distribution;
}
#include <iostream>
#include <vector>

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
#pragma once
#include<vector>
#include<tuple>

int find_minimum_waiting_time(std::vector<int>&, const std::vector<int>&);

int find_max_salary(const std::vector<int>&);

std::vector<std::tuple<int, int>> find_best_group(const std::vector<int>&);

int get_index_best_item(std::vector<std::tuple<int, int>>&);

std::tuple<int, std::vector<int>> loot_max_value(std::vector<std::tuple<int, int>>&, int);

int find_minimum_coins(int&);

int find_maximum_ad_revenue(std::vector<int>& num_clicks, std::vector<int>& ad_pay);

std::vector<int> find_least_segment_intersections(std::vector<std::tuple<int, int>>& segments);

std::vector<int> find_max_prizes(int& num_candies);
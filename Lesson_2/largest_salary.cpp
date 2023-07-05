#include <iostream>
#include <string>
#include <vector>

/*
* 
* This Program takes a list of numbers and arranges them 
* to create the largest value
* 
*/


int find_max_index(const std::vector<int>& vec)
{
    int max_value = vec[0];
    size_t max_index = 0;

    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] > max_value) {
            max_value = vec[i];
            max_index = i;
        }
    }

    return max_index;
}

int find_max_salary(std::vector<int>& vec)
{
    std::string max_salary;

    while (!vec.empty())
    {
        int max_index = find_max_index(vec);
        int max_value = vec[max_index];

        max_salary += std::to_string(max_value);

        vec.erase(vec.begin() + max_index);
    }

    return std::stoi(max_salary);
}
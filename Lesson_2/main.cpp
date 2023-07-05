#include <iostream>
#include <vector>

int find_minimum_waiting_time(std::vector<int>&, const std::vector<int>&);

int find_max_salary(const std::vector<int>&);

int main()
{
    /*
    std::vector<int> arr = { 1, 5, 4, 3, 5 };

    int max_salary = find_max_salary(arr);

    std::cout << max_salary << std::endl;
    */

    std::vector<int> wait_times = { 10, 20 , 15 };
    std::vector<int> patients   = { 0 , 0  , 0 };

    int waiting_time = find_minimum_waiting_time(patients, wait_times);

    std::cout << waiting_time << std::endl;

    for (size_t p : patients)
    {
        std::cout << p << " ";
    }
}
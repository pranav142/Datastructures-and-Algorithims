#include "main.h"

int main()
{
    /* max salary problem */
    /*
    std::vector<int> arr = { 1, 5, 4, 3, 5 };

    int max_salary = find_max_salary(arr);

    std::cout << max_salary << std::endl;
    */

    /* Patients in a queue problem */
    /*std::vector<int> wait_times = { 10, 20 , 15 };
    std::vector<int> patients   = { 0 , 0  , 0 };

    int waiting_time = find_minimum_waiting_time(patients, wait_times);

    std::cout << waiting_time << std::endl;

    for (size_t p : patients)
    {
        std::cout << p << " ";
    }*/

    /* Celebration Party Problem */
    /*std::vector<int> childrens_ages= { 1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9 };

    std::vector<std::tuple<int, int>> groups = find_best_group(childrens_ages);

    for (const auto& group : groups) {
        int start = std::get<0>(group);
        int end = std::get<1>(group);
        std::cout << "Group: (" << start << ", " << end << ")" << std::endl;
    }*/

    /* Lotting Problem */

    /*std::vector<std::tuple<int, int>> items = { {5, 30}, {4, 28}, {3, 24} };
    int best_item_index = get_index_best_item(items);
    if (best_item_index == 2) std::cout << "passed got value "<< best_item_index << std::endl;
    else std::cout << "best_item_index failed";*/

    /*std::vector<std::tuple<int, int>> items = {{5, 30}, {4, 28}, {3, 24}};
    int carrying_capacity = 9;
    std::tuple<int, std::vector<int>> loot = loot_max_value(items, carrying_capacity);
    std::vector<int> amounts = std::get<1>(loot);

    std::cout << std::get<0>(loot) << std::endl;

    for (int i = 0; i < amounts.size(); i++)
    {
        std::cout << "amount taken of item number " << i << ": " << amounts[i] << std::endl;
    }*/

    /* Assignment 3 Money Change Problem */

    /*int amount = 28;
    std::cout << find_minimum_coins(amount) << std::endl;
    */

    /* Assignment 3 Find max revenue problem */

    /*std::vector<int> a = { 1, 3, -5 };
    std::vector<int> b = { -2, 4, 1 };
    std::cout << find_maximum_ad_revenue(a, b) << std::endl;*/
    
    /* Assignment 3 Find Segments*/
    /*std::vector<std::tuple<int, int>> segments = { {1, 3}, {2, 5}, {3, 6} };
    std::vector<int> intersections = find_least_segment_intersections(segments);

    for (auto& intersection : intersections)
    {
        std::cout << intersection << std::endl;
    }*/


    /* Assignment 3 Find Max Prizes*/
    /*int num_candies = 2;
    std::vector<int> candy_distribution = find_max_prizes(num_candies);

    std::cout << candy_distribution.size() << std::endl;
    for (auto& item : candy_distribution)
    {
        std::cout << item << " ";
    }*/

    int array[] = { 1, 2, 3, 4, 5, 6, 7 }; 
   
    std::cout<<binary_search_recursive(array, 0, 6, 5)<<std::endl;

}
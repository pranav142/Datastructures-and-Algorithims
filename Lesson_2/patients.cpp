#include <iostream>
#include <vector>
#include <limits>

int find_minimum_waiting_time(std::vector<int>& patients,const std::vector<int>& wait_times)
{
    int waiting_time = 0;
    int number_of_patients = patients.size();

    for (int i = 0; i < number_of_patients; i++)
    {
        int tmin = std::numeric_limits<int>::max();
        int min_index = 0;

        for (int j = 0; j < number_of_patients; j++)
        {
            if (patients[j] == 0 && wait_times[j] < tmin)
            {
                tmin = wait_times[j];
                min_index = j;
            }
        }

        patients[min_index] = 1; 

        waiting_time += (number_of_patients - i - 1) * tmin;
    }

    return waiting_time;
}
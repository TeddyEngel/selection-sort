//
//  main.cpp
//  SelectionSort
//
//  Created by Teddy Engel on 18/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <vector>
#include <iostream>

#define INVALID -1

// Returns the smallest value index in passed vector, or -1
int FindSmallestValue(std::vector<int>& values)
{
    int pos = INVALID;
    int i = 0;

    for (i = 0; i != values.size(); i++)
    {
        if (pos == INVALID || values[pos] > values[i])
            pos = i;
    }
    return pos;
}

void SelectionSort(std::vector<int>& values, std::vector<int>& result)
{
    int smallestIndex = -1;
    int pos = INVALID;
    int i = 0, j = 0;
    
    while (values.size() > 0)
    {
        pos = FindSmallestValue(values);
        result.push_back(values[pos]);
        values.erase(values.begin() + pos);
    }
}

void PrintVector(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i != values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }
}

int main(int argc, const char* argv[]) {
    std::vector<int> values = {10, 0, 2, 5, -4, 3, 2};
    std::vector<int> result;
    
    std::cout << "Unsorted collection:" << std::endl;
    PrintVector(values);
    SelectionSort(values, result);
    std::cout << "Sorted collection:" << std::endl;
    PrintVector(result);
    return 0;
}

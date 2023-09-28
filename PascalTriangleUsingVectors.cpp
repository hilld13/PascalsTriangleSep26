/*
 * Donovan Hill
 * T00520124
 * Copyright 2023
 *
 */

#include <iostream>
#include <vector>

void level(int levelNum, std::vector<unsigned int>& levelElements)
{
    // base case is the top two levels who's elements are always '1'
    // calculations only occur after this.
    if (levelNum == 0) {
        // there's only one element and it is a '1'
        levelElements[0] = 1;
        
        for (int i=0; i<levelNum+1; i++)
            std::cout << levelElements.at(i) << " \t";
        std::cout << std::endl;
        
        return;
    }
    
    std::vector<unsigned int> prevLevelElements(levelNum+1);
    
    level((levelNum-1), prevLevelElements);
    
    // the bracketing elements are always equal to the bracketing elements above
    levelElements.front() = prevLevelElements.front();
    levelElements.at(levelNum) = prevLevelElements.at(levelNum-1);  // can't use "back()" because the back may be invalid data.
    
    for (int i=1; i<(levelNum); i++)
    {
        levelElements[i] = prevLevelElements.at(i-1) + prevLevelElements.at(i);
    }
    
    for (int i=0; i<levelNum+1; i++)
        std::cout << levelElements.at(i) << " \t";
    std::cout << std::endl;
}

int main ()
{
    int levels;
    do
    {
        std::cout << "Enter a positive integer: ";
        std::cin >> levels;
    } while ( levels < 0 );
    
    std::vector<unsigned int> levelElements(levels+1);
    
    level(levels, levelElements);
    
    return 0;
}

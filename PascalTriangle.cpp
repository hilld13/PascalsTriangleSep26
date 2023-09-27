/*
 * Donovan Hill
 * T00520124
 * Copyright 2023
 *
 */

#include <iostream>
using namespace std;

void level(int levelNum, unsigned int levelElements[])
{
    // base case is the top two levels who's elements are always '1'
    // calculations only occur after this.
    if (levelNum == 0) {
        // there's only one element and it is a '1'
        levelElements[0] = 1;
        
        cout << "Level = " << levelNum << "\t";
        for (int i=0; i<levelNum+1; i++)
            //cout << "i:" << i << ":" << levelElements[i] << "\t";
            cout << levelElements[i] << " \t";
        cout << endl;
        
        return;
    }
    
    unsigned int* prevLevelElements = new unsigned int[levelNum+1];
    
    level((levelNum-1), prevLevelElements);
    
    // the bracketing elements are always equal to the bracketing elements above
    levelElements[0] = prevLevelElements[0];
    levelElements[levelNum] = prevLevelElements[levelNum-1];
    
    if (levelNum > 1) {
        for (int i=1; i<(levelNum); i++)
        {
            levelElements[i] = prevLevelElements[i-1] + prevLevelElements[i];
        }
    }
    
    cout << "Level = " << levelNum << "\t";
    for (int i=0; i<levelNum+1; i++)
        //cout << "i:" << i << ":" << levelElements[i] << "\t";
        cout << levelElements[i] << " \t";
    cout << endl;

    delete[] prevLevelElements;
}

int main ()
{
    int levels;
    do
    {
        cout << "Enter a positive integer: ";
        cin >> levels;
    } while ( levels < 0 );
    
    unsigned int* levelElements = new unsigned int[levels+1];
    
    level(levels, levelElements);

    delete[] levelElements;
    
    return 0;
}

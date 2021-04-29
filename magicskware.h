#ifndef MAGICSKWARE_H
#define MAGICSKWARE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//constants
const int GRID_MIN=6;
const int GRID_MAX=10;
const int GRID_NUM_MAX=9;
const int GRID_NUM_MIN=1;

class skware
{

  private:
    int ** puzzle;
    int rows;
  public:
    //desc:display_puzzle prints out a grid of a given size of numbers with 5 numbers blanked out.
    //pre:size initalized
    //post:text to screen.
    void display_puzzle(int size);

    //desc:solves the puzzle
    //pre:size and soln initalized
    //post:output to screen.
    void solve(int size);

    //constructor to initalize a skware.
    skware(int size);

    //copy constructor to make a deep copy.
    skware(const skware& puzz);

    //copy assignment operator
    skware& operator=(const skware& puzz);

    //destructor
    ~skware();

    //compares two puzzles to see if they're equal.
    bool operator==(const skware& puzz);
    
};

#endif
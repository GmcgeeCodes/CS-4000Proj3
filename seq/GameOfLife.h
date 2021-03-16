/*
 * Name: Gerald McGee
 * GameOfLife.h
 * Spring 2021
 * CS4000 
*/

#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std; 

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
class GameOfLife {

  public:
    vector<vector<int> > SimulateLife(vector<vector<int> > &board, int life_cycles);
    vector<vector<int> > getTheNext(vector<vector<int> > &board);
    int cells_alive(vector <vector<int> > &board, int xTemp, int yTemp);

  private:
  
};
#endif
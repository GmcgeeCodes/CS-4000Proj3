/*
 * Name: Gerald McGee
 * GameOfLife.h parallel version
 * Spring 2021
 * CS4000 
*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <future>
#include <unistd.h>
#include <thread>


using namespace std; 

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
class GameOfLife {

  public:
    vector<vector<int> > SimulateLife(vector<vector<int> > &board, int life_cycles);
    static void getTheNext(vector<vector<int> > &board, vector<vector<int> > &nxt, int threadNumber, int threadCount);
    static int cells_alive(vector <vector<int> > &board, int xTemp, int yTemp);

  private:
  
};
#endif
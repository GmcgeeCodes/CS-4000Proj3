/*
 * Name: Gerald McGee
 * GameOfLifePar.cc parallel version
 * Spring 2021
 * CS4000 
*/
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include "GameOfLife.h"
#include <future>
#include <unistd.h>

using namespace std;

void GameOfLife::getTheNext(vector<vector<int> > &board ,vector<vector<int> > &nxt, int threadNumber, int threadCount){
    int size = board.size();
    for(int i = threadNumber; i < size; i += threadCount)
	{
        for(int j = 0; j < size; j++)
		{
            if(board[i][j] == 2)
			{
               nxt[i][j] = 2;
            }
			else
			{
				int alive = cells_alive(board, i, j);
				if(alive == 2)
				{
                   nxt[i][j] = board[i][j];
                }
				else if(alive == 3)
				{
                   nxt[i][j] = 1;
				}
				else
				{
					nxt[i][j] = 0;
				}				
			}   
		}
	}

}
vector<vector<int> > GameOfLife::SimulateLife(vector<vector<int> > &board, int life_cycles){
	int size = board.size();
    for(int i = 0; i < life_cycles; i++){
        vector<vector<int> > temp;
        temp.resize(size);
		
        for(int j = 0; j < size; j++){
            temp[j].resize(size);
        }

		int threadCount = thread::hardware_concurrency();
        thread threads[threadCount];
		
        for(int k = 0; k < threadCount; k++){
            threads[k] = thread(getTheNext, board, temp, k, threadCount);
        }

        for(size_t i = 0; i < threadCount; ++i)
            threads[i].join();

        board = temp;
    }
    return board;
}
int GameOfLife::cells_alive(vector<vector<int> > &board, int xTemp, int yTemp)
{
	int aliveCells = 0;
    int size = board.size();
    for(int i = xTemp - 1; i <= xTemp + 1; i++)
	{
        for(int j = yTemp - 1; j <= yTemp + 1; j++)
		{
			int overflowTempI, overflowTempJ;
            if(i == -1)
			{
				overflowTempI = (size + i) % size;
			}
			else if(i == size)
			{
				overflowTempI = i % size;
			}
			else
			{
				overflowTempI = i;
			}
			if(j == -1)
			{
				overflowTempJ = (size + j) % size;
			}
			else if(j == size)
			{
				overflowTempJ = j % size;
			}
			else
			{
				overflowTempJ = j;
			}
			
            if(board[overflowTempI][overflowTempJ] != 0 && !(overflowTempI == xTemp && overflowTempJ == yTemp))
			{
                aliveCells++;
			}
        }
    }
    return aliveCells;
}
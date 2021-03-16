#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "GameOfLife.h"

using namespace std;

vector<vector<int> > GameOfLife::getTheNext(vector<vector<int> > &board){
    int aliveCells; 
    int size = board.size();
	vector<vector<int> > nBoard;

		for(int i = 0; i < size; i++)
		{
			nBoard.push_back(vector<int>());
			for(int j = 0; j < size; j++)
			{
				aliveCells = 0;
				if(board[i][j] == 2)
				{
					nBoard[i].push_back(2);
				}
				else
				{
					aliveCells = cells_alive(board,i,j);

					if(aliveCells == 2)
					{
						nBoard[i].push_back(board[i][j]);
					}
					else if(aliveCells == 3)
					{
						nBoard[i].push_back(1);
					}
					else
					{
						nBoard[i].push_back(0);
					}
				}
			}
		}
    return nBoard;

}
vector<vector<int> > GameOfLife::SimulateLife(vector<vector<int> > &board, int life_cycles){
	for(int i = 0; i < life_cycles; i++){
		board = getTheNext(board);
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
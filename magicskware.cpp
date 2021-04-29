#include "magicskware.h"

void skware::display_puzzle(int size) 
{
  // deletecount is number of grid spaces that have been deleted
  int delete_count = 0;
  // rand row and col are tbe positions that a num will get deleted at.
  int rand_row;
  int rand_col;
  do 
  {
	  // gets a random row and column
	  rand_row = rand() % (size);
	  rand_col = rand() % (size);
	  // ensures that 5 total are deleted.
	  if (puzzle[rand_row][rand_col] != -1) 
    {
		  delete_count += 1;
		  puzzle[rand_row][rand_col] = -1;
	  }
  }while(delete_count<5);
  //outputs the grid and sums 
  for(int i=0;i<size;i++)
  {
	  for (int j = 0; j < size; j++) {
		  if (puzzle[i][j] != -1) 
      {
			  cout << puzzle[i][j] << "  ";
		  } 
      else {
			  cout << "   ";
		  }
	  }
	  cout << puzzle[i][size];
	  cout << "\n";
  }
  for(int j=0;j<size;j++)
  {
		cout << puzzle[size][j] << " ";
  }
  cout<<endl;
}

void skware::solve(int size) 
{
	// x and y coordinates for the horizontal and vertical blanks.
	int xH, yH;
	int xV, yV;
	// number of horizontal, vertical, and total blanks.
	int blank_countH, blank_countV, blank_count;
	// sum of a row or column.
	int numSumHorz, numSumVert;
	do 
  {
		blank_count = 0;
		for (int i = 0; i < size; i++) 
    {
			blank_countH = 0;
			numSumHorz = 0;
      //adds up number of blanks, getting the position if just one blank in row.
			for (int j = 0; j < size; j++) 
      {
        //adds to row sum if not blank
				if (puzzle[i][j] != -1) 
        {
					numSumHorz += puzzle[i][j];
				} 
        else if (puzzle[i][j] == -1) 
        {
					xH = i;
					yH = j;
					blank_countH++;
				}
			}
      //sets blank to sum - sum sans the blank.
			if (blank_countH == 1) 
      {
				puzzle[xH][yH] = puzzle[i][size] - numSumHorz;
			}
		}

		for (int i = 0; i < size; i++) 
    {
			blank_countV = 0;
			numSumVert = 0;
      //adds up number of blanks, getting the position if just one blank in column.
			for (int j = 0; j < size; j++) 
      {
				if (puzzle[j][i] != -1) 
        {
          //adds to column sum if not blank
					numSumVert += puzzle[j][i];
				} 
        else if (puzzle[j][i] == -1) 
        {
					xV = i;
					yV = j;
					blank_countV++;
				}
			}
      //sets blank to value if only blank in column.
			if (blank_countV == 1) 
      {
				puzzle[yV][xV] = puzzle[size][i] - numSumVert;
			}
		}
    //counts total number of blanks remaining in puzzle.
		for (int i = 0; i < size; i++) 
    {
			for (int j = 0; j < size; j++) 
      {
				if (puzzle[i][j] == -1) 
        {
					blank_count++;
				}
			}
		}
    //runs until all blanks gone.
  }while (blank_count != 0);
	cout << endl;
  //prints out the solution for the grid with blanks filled.
	for (int i = 0; i < size; i++) 
  {
		for (int j = 0; j < size; j++) 
    {
			if (puzzle[i][j] != -1) 
      {
				cout << puzzle[i][j] << "  ";
			} 
      else {
				cout << "   ";
			}
		}
		cout << puzzle[i][size];
		cout << "\n";
	}
	for (int j = 0; j < size; j++) 
  {
		cout << puzzle[size][j] << " ";
	}
	cout << endl;
}

skware::skware(int size) 
{
	rows = size + 1;
	// initalizes 2d array
	puzzle = new int *[size + 1];
	for (int i = 0; i < size + 1; i++) 
  {
		puzzle[i] = new int[size + 1];
	}
	// fills normal grid
	for (int i = 0; i < size; i++) 
  {
		for (int j = 0; j < size; j++) 
    {
			puzzle[i][j] = rand() % (GRID_NUM_MAX - GRID_NUM_MIN + 1) + GRID_NUM_MIN;
		}
	}
	// fills sums
	int sum;
	for (int i = 0; i < size; i++) 
  {
		sum = 0;
		for (int j = 0; j < size; j++) 
    {
			sum += puzzle[i][j];
		}
		puzzle[i][size] = sum;
	}
	for (int i = 0; i < size; i++) 
  {
		sum = 0;
		for (int j = 0; j < size; j++) 
    {
			sum += puzzle[j][i];
		}
		puzzle[size][i] = sum;
	}
}

skware::skware(const skware &puzz): rows(puzz.rows)
{
  //creates new puzzle, and sets the rows to that of a given puzzle.
	puzzle = new int* [rows];
	for (int i = 0; i < rows; i++) 
  {
		puzzle[i] = new int[rows];
	}
	for (int i = 0; i < rows; i++) 
  {
		for (int j = 0; j < rows; j++) 
    {
			puzzle[i][j] = puzz.puzzle[i][j];
		}
	}
}

skware& skware::operator=(const skware &puzz) 
{
  //checks if puzzle's are the same.
	if (puzzle != puzz.puzzle) 
  {
		rows = puzz.rows;
    //deletes data present in the puzzle.
    for(int i=0;i<rows;i++)
    {
      delete[] puzzle[i];
    }
		delete[] puzzle;
    //initalizes new puzzle to given puzzle.
		puzzle = new int *[rows];
		for (int i = 0; i < rows; i++) 
    {
			puzzle[i] = new int[rows];
		}
		for (int i = 0; i < rows; i++) 
    {
			for (int j = 0; j < rows; j++) 
      {
				puzzle[i][j] = puzz.puzzle[i][j];
			}
		}
	}
  //returns copy of the made skware.
	return *this;
}

skware::~skware() 
{
  //deletes data.
  for(int i=0;i<rows;i++)
  {
    delete [] puzzle[i];
  }
  delete [] puzzle;
}

//checks if two puzzles equal.
bool skware::operator==(const skware& puzz)
{
	bool puzzles_diff=true;
  for(int i=0;i<rows-1;i++)
  {
    for(int j=0;j<rows-1;j++)
    {
      if(puzzle[i][j]==puzz.puzzle[i][j])
      {
        puzzles_diff=false;
      }
    }
  }
  return puzzles_diff;
}
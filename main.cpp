// name: Alex Obermeyer
// filename:magicskware.cpp
// description:This program runs a magic "skware" game.
#include "magicskware.h"
int main() 
{
  // seeds random
  srand(time(0));
	// again is whether the user wants another puzzle.
	bool again;
	// play_input gets a char that represnts the answer to if the user wants to
	// play a puzzle.
	char play_input;
	// solut_input gets whether the user is ready for a solution.
	char solut_input;
	// grid size is the size of the grid that the user wants.
	string grid_size;
	// intro
	cout << "\t\tWelcome to the Magic Skware game!\n\n";
	cout << "Would you like to play a puzzle? (y for yes, anything else for no: ";
	cin >> play_input;
	do 
  {
		// if they want to play / play again.
		if(play_input == 'y') 
    {
			again = true;
			do 
      {
				// gets size, keeps size in range.
				cout << "Enter a size for the grid (6-10): ";
				cin >> grid_size;
				if (grid_size!="6"&& grid_size!="7"&&grid_size!="8"&&grid_size!="9"&&grid_size!="10") 
        {
					cout << "Please re-enter a size in the given range.\n";
				}
			} while (grid_size!="6"&&grid_size!="7"&&grid_size!="8"&&grid_size!="9"&&grid_size!="10");
			// makes a puzzle and it's copy.
			skware puzz = skware(stoi(grid_size));
			skware soln = skware(puzz);
			// outputs puzzle unsolved.
			cout << "\t\tHere's your puzzle!\n\n";
			puzz.display_puzzle(stoi(grid_size));
			// gets user input for solution.
			do 
      {
				cout << "\nEnter 'y' to get a solution to the puzzle: ";
				cin >> solut_input;
				if (solut_input != 'y') {
					cout << "Make sure to enter 'y'!\n";
				}
			} while (solut_input != 'y');
			// solves puzzle, outputs whether it matches the solution.
			puzz.solve(stoi(grid_size));
      if(soln==puzz)
      {
        cout<<"\nThe solution doesn't match the original.\n";
      }
	    else
      {
        cout<<"\nThe solution does match the original.\n";
      }
			// gets whether again or not.
			cout << "\nWould you like another puzzle? (y for yes, anything "
					"else for no): ";
			cin >> play_input;

		} 
    else 
    {
			again = false;
		}

	} while (again);
	// ending.
	cout << "\n\t\tThanks for playing!";
	return 0;
}
/* Filename: clock.cpp
 *
 * Author: Dhruv Gala (dmg7937)
 * Author: Nikita Nair (nxn7419)
 *
 * Version: 1.0 11/26/2014
 *
 * Description: This is the cpp file for clock puzzle.
 *				the input while running this program is the number of hours on the clock, 
 *				the time currently on the clock(i.e. the time when the clock died) and the
 *				the actual or valid time at the moment.
 *				This file uses MySolver.h as the framework for the algorithm applied.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "MySolver.h"

using namespace std;

class myClock: public myFramework<int>
{
	public:

		int total_no_of_hrs, broken_clock_time, valid_time;
		char **input;

		myClock(char **input) 
		{
			this->total_no_of_hrs = atoi(input[1]);
			this->broken_clock_time = atoi(input[2]);
			this->valid_time = atoi(input[3]);
			this->input = input;
		}
/*
 *Function Name: ifReachedGoal
 *
 *@param: int 
 *
 *@return: bool
 *
 * Description: if the current config passed matches to the goal config then return true.
 * 
 */
		bool ifReachedGoal(int forThisConfig)
		{
			return (forThisConfig == atoi(input[3])); 
		}

/*
 *Function Name: nextPossibleCOnfig
 *
 *@param: int 
 *
 *@return: vector<int>
 *
 * Description: two possible moves for each config is computed and stored in configList.
 * 
 */
		vector<int> nextPossibleConfig(int forThisConfig)
		{
			vector<int> configList;
			int prevTime;
			int nextTime;

			nextTime = (forThisConfig + 1) % total_no_of_hrs;
			
			if((forThisConfig-1) == 0)	
				prevTime = total_no_of_hrs;
			else
				prevTime = (forThisConfig - 1) % total_no_of_hrs;

			configList.push_back(prevTime);
			configList.push_back(nextTime);
			return configList;
		}

/*
 *Function Name: atStartConfig
 *
 *@return: int
 *
 * Description: returns the configuration at the start.
 * 
 */
		int atStartConfig()
		{
			return broken_clock_time;
		}

/*
 *Function Name: displayResult
 *
 *@param: vector<int>
 *@param: map<int, int> 
 *
 * Description: displays only the shortest means of changing the hour hand to reset the time to goal configuration (i.e. the valid time)
 * 
 */
		void displayResult(vector<int> current, map<int,int> seen)
		{
	
			vector<int> temp;
			map< int,int> ::iterator mIT;
			
			mIT= seen.find(current.back());
			temp.push_back(mIT->first);
			current.back()=mIT->second;
			
			if(mIT->first != mIT->second)
				displayResult(current,seen);
			
			for (vector<int>::reverse_iterator rIT = temp.rbegin() ; rIT != temp.rend(); ++rIT)
			{
				cout << *rIT << " ";
					if(*rIT != atoi(input[3]))
						cout << "--> ";
			}

		}

/*
 *Function Name: noSoltionFound
 *
 * Description: if no solution is found for the very problem then this function is called.
 * 
 */
		void noSolutionFound()
		{
			cout<< "\n No solution for the given problem !"; 
		}

/*
 *Function Name: givenInput
 *
 * Description: prints the given input by the user.
 * 
 */
		void givenInput()
		{
			cout << "\nThe hours on the clock: " << total_no_of_hrs;
			cout << "\nThe time at which clock died: " << broken_clock_time;
			cout << "\nTrue time at present: " << valid_time << "\n";
			cout << "\nThe solution is: ";
		}

};

/*
 *Function Name: main
 *
 *@param: int 
 *@param: char**
 *
 *@return: int
 *
 * Description: This function checks if the given command to run the program has valid number of arguments
 *				and hence runs the program by passing the arguments to the various functions by means of using the framework.
 * 
 */
int main(int argc, char* argv[]) 
{

    MySolver <int> solveThis;
    cout << "=========== The Dead Clock Problem ==========";
	if(argc == 4)
	{
		myClock thisClock(argv);
		thisClock.givenInput();
		solveThis.solveIt(thisClock);
	}
	else 
	{
		cout << "Please check the number of arguments and run the program again \n" ;
		return 0;
	}
	cout << "\n================= END =================\n";
	return 0;
}
/* Filename: variableClock.cpp
 *
 * Author: Dhruv Gala (dmg7937)
 *
 * Version: 1.0 12/10/2014
 *
 * Description: This is the cpp file for clock puzzle with a variation.
 *				the input while running this program is the number of hours on the clock, 
 *				the time currently on the clock(i.e. the time when the clock died) ,the
 *				actual or valid time at the moment and 'n' number of variables that
 *				are the variables by which the clock hour hand could be moved.
 *				This file uses MySolver.h as the framework for the algorithm applied.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "MySolver.h"

using namespace std;

class myVariableClock: public myFramework<int>
{
	public:
		int total_no_of_hrs, broken_clock_time, valid_time;
		char **input;
		int totalArguments;

		myVariableClock(int argc, char **input) 
		{
			this->total_no_of_hrs = atoi(input[1]);
			this->broken_clock_time = atoi(input[2]);
			this->valid_time = atoi(input[3]);
			this->input = input;
			this->totalArguments = totalArguments;
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
			int nextTime = 0;
			for(int variableArgument = 4; variableArgument < totalArguments && atoi(input[variableArgument]) != 0; variableArgument++)
			{
				
				nextTime = (forThisConfig + atoi(input[variableArgument])) % total_no_of_hrs;
				if(nextTime > total_no_of_hrs)
					nextTime -= total_no_of_hrs;
				if(nextTime < 0)
					nextTime += total_no_of_hrs;

				if(nextTime == 0)
					nextTime = total_no_of_hrs;

				configList.push_back(nextTime);
			}
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
			cout << "\nThe hours on the clock      : " << total_no_of_hrs;
			cout << "\nThe time at which clock died: " << broken_clock_time;
			cout << "\nTrue time at present        : " << valid_time ;
			for(int allArguments = 4; allArguments < argc; allArguments++)
				cout<<"\nChange the clock by         : " << atoi(input[allArguments]);
			cout << "\n\nThe solution is: \n";
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
 * Description: The main function sets the clock up with all the variable arguments to change
 *				the broken clock so as it reaches the valid time and then outputs the same.
 * 
 */
int main(int argc, char* argv[])
{

	MySolver <int> solveThis;
	cout << "=========== The variable dead Clock Problem ==========\n";
	myVariableClock changeThisClock(argc, argv);	
	changeThisClock.givenInput();
	solveThis.solveIt(changeThisClock);
	cout << "\n============ END ===============\n";

	return 0;
}
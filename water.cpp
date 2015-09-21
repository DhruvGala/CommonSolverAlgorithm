/* Filename: water.cpp
 *
 * Author: Dhruv Gala (dmg7937)
 * Author: Nikita Nair (nxn7419)
 *
 * Version: 1.0 11/27/2014
 *
 * Description: This is the cpp file for water-jug puzzle.
 *				the input when running this program can vary. A user can input as many jug he/she wishes to enter.
 *				a basic sample is <the final amount of water needed> following by the maximum capacity of each jugs that the user wishes to enter.
 *				This file uses MySolver.h as the framework for the algorithm applied.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "MySolver.h"

using namespace std;

class myWater: public myFramework <vector<int> >
{
	public:

		char **input;
		int totalArguments;

		myWater(char **input,int &totalArguments) 
		{
			this->input=input;
			this->totalArguments=totalArguments;	
		}

/*
 *Function Name: atStartConfig
 *
 *@return: vector<int>
 *
 * Description: It sets all the jugs mentioned in the arguments to zero.
 * 
 */
		vector<int> atStartConfig()
		{
			vector<int> setJugsToZero;
			for(int i=2; i < totalArguments ; i++)
			{
				setJugsToZero.push_back(0);
			}
		return setJugsToZero;
		}

/*
 *Function Name: ifReachedGoal
 *
 *@param: vector<int> 
 *
 *@return: bool
 *
 * Description: If anyJug matches the goal configuration then return true.
 * 
 */
		bool ifReachedGoal (vector<int> forThisConfig)
		{
			for (vector<int>::iterator anyJug = forThisConfig.begin() ; anyJug != forThisConfig.end(); ++anyJug)
			{
				if ( *anyJug == atoi(input[1])) 
					return true;
			}
		return false;
		}

/*
 *Function Name: nextPossibleConfig
 *
 *@param: vector<int>
 *
 *@return: vector<vector<int> >
 *
 * Description: this method conputes all the possible configurations that are possible by taking valid moves 
 *				possible on the current configuration and stores all the valid possible configuration in a configList.
 * 
 */
		vector<vector<int> > nextPossibleConfig(vector<int> forThisConfig)
		{
			vector <int> copy =  forThisConfig;
			vector<vector<int> > configList;	
			for (unsigned int jugA = 0 ; jugA < forThisConfig.size(); jugA++)
			{   
		   		if(forThisConfig.at(jugA) != 0)
		   		{
		   			copy.at(jugA) = 0;
					if(ifConfigNotSame(copy, forThisConfig))
					{
						configList.push_back(copy);
						copy =  forThisConfig;
					}
				}
					
				if(forThisConfig.at(jugA)!= atoi(input[jugA+2]))
				{
					copy.at(jugA)= atoi(input[jugA+2]);
					if(ifConfigNotSame(copy,forThisConfig))
					{
						configList.push_back(copy);
						copy =  forThisConfig;
					}		
				}

				for (unsigned int jugB = 0 ; jugB < forThisConfig.size(); jugB++)
				{
					if(jugA!=jugB)
					{
						int maxCapacityOfJugA = atoi(input[jugA+2]);
						int volumeInJugA = copy.at(jugA);
						int volumeInJugB = copy.at(jugB);
						int totalCurrrentVolume = volumeInJugA + volumeInJugB;

						if(maxCapacityOfJugA >= totalCurrrentVolume )
						{
							copy.at(jugA) = totalCurrrentVolume;
							copy.at(jugB) = 0;
						}

						if(maxCapacityOfJugA < totalCurrrentVolume)
						{
							copy.at(jugA) = maxCapacityOfJugA;
							copy.at(jugB) = totalCurrrentVolume - maxCapacityOfJugA;
						}
						
						if(ifConfigNotSame(copy,forThisConfig))
						{
							configList.push_back(copy);
							copy =  forThisConfig;
						}
						
					}

				}

			}
			return configList;
		}

/*
 *Function Name: ifConfogNotSame
 *
 *@param: vector<int>
 *@param: vector<int>
 *
 *@return: bool
 *
 * Description: returns true if configA is not equal to configB
 * 
 */
		bool ifConfigNotSame(vector<int> configA, vector<int> configB)
		{
			return (configA != configB);
		}
		
/*
 *Function Name: displayResult
 *
 *@param: vector<vector<int> >
 *@param: map<vector<int>,vector<int>
 *
 * Description: displays the solution of transitions of all the jugs.
 * 
 */
		void displayResult(vector<vector<int> > current, map <vector<int>,vector<int> > seen)
		{
			vector<vector<int> > temp;
			map<vector<int>,vector<int> > :: iterator mIT;
			
			mIT= seen.find(current.back());
			temp.push_back(mIT->first);
			current.back()=mIT->second;
			
			if(mIT->first != mIT->second)
				displayResult(current,seen);

			for (vector<vector<int> > :: reverse_iterator possibleSolutions = temp.rbegin() ;possibleSolutions != temp.rend(); ++possibleSolutions)
			{
				vector<int> thisSolution = *possibleSolutions;
				for (vector<int>::iterator quantitiesOfJugs = thisSolution.begin() ; quantitiesOfJugs != thisSolution.end(); ++quantitiesOfJugs)
				{
					cout << *quantitiesOfJugs << "  ";				
				}
			cout << "\n";
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
			cout << "No solution for this problem!" << "\n";
		}

};

/*
 *Function Name: main
 *
 *@param: int
 *@param: char**
 *
 * Description: The main function which calls all the function for generating the solution of the given problem.
 * 
 */

int main(int argc, char* argv[]) {

    cout << "=========== The Water Jug Problem ==========\n";
	
	MySolver <vector<int> > solveThis;
	myWater waterJugProblem(argv,argc);
	solveThis.solveIt(waterJugProblem);	
	
	cout << "=================== END ===================\n";

	return 0;
}
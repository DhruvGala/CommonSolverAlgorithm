/* Filename: MySolver.h
 *
 * Author: Dhruv Gala (dmg7937)
 * Author: Nikita Nair (nxn7419)
 *
 * Version: 1.0 11/26/2014
 *
 * Description: This is the common header file for all the puzzle problems.
 *				This file contains the base framework for all the puzzles.
 *				It contains myFramework class and MySolver class which together act as the framework
 *				for solving each and every puzzle.
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;


template<typename T>

class myFramework 
{

	public:

		virtual bool ifReachedGoal(T forThisConfig) = 0;
		virtual vector<T> nextPossibleConfig(T forThisConfig) = 0;
		virtual T atStartConfig() = 0;
		virtual void displayResult(vector<T> current , map<T,T> seen) = 0;
		virtual void noSolutionFound() = 0;
};


template<typename T>

class MySolver
{
	public:

/*
 *Funtion Name: solveIt
 *
 *@param: &thisPuzzle
 *
 *Description: this function checks if the top of the queue is the goal configuration,
 *				maintains a queue of all the possible configuration for each and every action that is possible on
 *				the current configuration.
 *
 */
		void solveIt(myFramework<T> &thisPuzzle)
		{
			vector<T> atStartConfig;
			vector<T> currentConfig;
			vector<vector<T> > myConfigQ;
			map<T,T> seenSoFar;

			atStartConfig.push_back(thisPuzzle.atStartConfig());							//defines a pure virtual function.
			bool ifReachedGoal = thisPuzzle.ifReachedGoal(thisPuzzle.atStartConfig());		//checks if at start config equals to the goal config 
																							// and stroes in a boolean variable.
			myConfigQ.push_back(atStartConfig);			
			seenSoFar.insert(make_pair(thisPuzzle.atStartConfig(),thisPuzzle.atStartConfig()));

			if(ifReachedGoal)																//at start if goal config is encountered then simply display it.
			{
				thisPuzzle.displayResult(atStartConfig,seenSoFar);
				return;			
			}

			while (!myConfigQ.empty() && !ifReachedGoal) 
			{

				currentConfig = myConfigQ.front();
				myConfigQ.erase(myConfigQ.begin());
				
				vector<T> nextPossibleConfig = thisPuzzle.nextPossibleConfig(currentConfig.back());

				for (typename :: vector<T> :: iterator configIT = nextPossibleConfig.begin(); configIT != nextPossibleConfig.end(); ++configIT) 
				{	
					typename :: map<T,T> :: iterator mapIt;
					mapIt = seenSoFar.find(*configIT);

					if(mapIt == seenSoFar.end())											//if the iterator of vector points to the end of 
																							//all the seen config i.e. no same config has occured prior
					{
						vector<T> thisTempConfig;
						thisTempConfig.push_back(*configIT);								//the top config is copied to temp variable
						seenSoFar.insert(make_pair(*configIT,currentConfig.back()));		//makes pair to store as an individual entity.
						
						if (thisPuzzle.ifReachedGoal(*configIT))							//if match found then display
						{
							thisPuzzle.displayResult(thisTempConfig,seenSoFar);
							return;
						}

						else 																//if not then add this config to the queue
						{
							myConfigQ.push_back(thisTempConfig);						
						}

					}
				}			
			}
			thisPuzzle.noSolutionFound();
		}
};
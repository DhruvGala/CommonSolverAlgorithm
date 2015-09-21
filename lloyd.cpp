/* Filename: lloyd.cpp
 *
 * Author: Dhruv Gala (dmg7937)
 * Author: Nikita Nair (nxn7419)
 *
 * Version: 1.0 11/29/2014
 *
 * Description: This is the cpp file for lloyd puzzle.
 *				A choice of input and output is provided to the user, using direct as well as file stream input and output is possible.
 *				the initital two arguments contain the dimension of the problem.
 *				The next two matrix formed arguments are the initial and the goal state of the puzzle.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "MySolver.h"
using namespace std;

class myLloyd: public myFramework <vector<char> > 
{
	public:
		int rowsOfPuzzle;
		int columnsOfPuzzle;
		vector<char> atStartPuzzle;
		vector<char> goalPuzzle;
		istream *isp;
		ifstream ifs;
		ostream *osp;
		ofstream ofs;

		myLloyd(char **argv, int &argc)
		{
			if(argv[1][0] == '-' && argv[1][1]=='\0')
				isp = &cin;
			else
			{
				ifs.open(argv[1]);
				isp = &ifs;
			}
			istream &is = *isp;

			if(argv[2][0]=='-' && argv[2][1]=='\0')
				osp = &cout;
			else
			{
				ofs.open(argv[2]);
				osp = &ofs;
			}

			is >> rowsOfPuzzle >> columnsOfPuzzle;

			for(unsigned int i = 0; i<(rowsOfPuzzle*columnsOfPuzzle);i++)
			{
				char c;
				is >> c;
				atStartPuzzle.push_back(c);
			}

			for(unsigned int i=0; i<(rowsOfPuzzle*columnsOfPuzzle);i++)
			{
				char c;
				is >> c;
				goalPuzzle.push_back(c);
			}
		}


/*
 *Function Name: ifReachedGoal
 *
 *@param: vector<int> 
 *
 *@return: bool
 *
 * Description: returns true is the configuration passed matches to the goal configuration.
 * 
 */
		bool ifReachedGoal(vector <char> forThisConfig)
		{
			return (forThisConfig == goalPuzzle);
		}


/*
 *Function Name: atStartConfig
 *
 *@return: vector<int>
 *
 * Description: Returns the start state of the puzzle passed in the argument
 * 
 */
		vector<char> atStartConfig()
		{
			return atStartPuzzle;
		}


/*
 *Function Name: nextPossibleConfig
 *
 *@param: vector<char>
 *
 *@return: vector<vector<char> >
 *
 * Description: this method conputes all the possible configurations that are possible by taking valid moves 
 *				possible on the current configuration and stores all the valid possible configuration in a configList.
 * 
 */
		vector<vector<char> > nextPossibleConfig(vector<char> forThisConfig)
		{
			vector<char> copy = forThisConfig;
			vector<vector<char> > configList;

			for(unsigned int pos = 0; pos < copy.size(); ++pos)
			{
				copy = forThisConfig;

				if(blank(copy,pos) == true && pos >= columnsOfPuzzle)
					copy = slideDown(copy,pos);
				if(ifConfigNotSame(copy, forThisConfig))
				{
					configList.push_back(copy);
					copy = forThisConfig;
				}

				if(blank(copy,pos) == true && ((pos + columnsOfPuzzle) < copy.size()))
					copy = slideUp(copy,pos);
				if(ifConfigNotSame(copy, forThisConfig))
				{
					configList.push_back(copy);
					copy = forThisConfig;	
				}

				if(blank(copy,pos) == true && ((pos & columnsOfPuzzle) != 0))
					copy = slideRight(copy,pos);
				if(ifConfigNotSame(copy, forThisConfig))
				{
					configList.push_back(copy);
					copy = forThisConfig;
				}

				if(blank(copy,pos) == true && (pos % columnsOfPuzzle != (columnsOfPuzzle -1)))
					copy = slideLeft(copy,pos);
				if(ifConfigNotSame(copy, forThisConfig))
				{
					configList.push_back(copy);
					copy = forThisConfig;
				}
			}
			return configList;
		}


/*
 *Function Name: blank
 *
 *@param: vector<char>
 *@param: int
 *
 *@return: bool
 *
 * Description: Returns true if blank "." is encountered in the config at the passed position.
 * 
 */
		bool blank(vector<char> thisConfig, int position)
		{
			return (thisConfig[position] == '.');
		}


/*
 *Function Name: ifConfogNotSame
 *
 *@param: vector<char>
 *@param: vector<char>
 *
 *@return: bool
 *
 * Description: returns true if configA is not equal to configB
 * 
 */
		bool ifConfigNotSame(vector<char> ConfigA, vector<char> ConfigB)
		{
			return (ConfigA != ConfigB);
		}


/*
 *Function Name: slideDown
 *
 *@param: vector<char>
 *@param: int
 *
 *@return: vector<char>
 *
 * Description: slide the puzzle block down and store the new config
 * 
 */
		vector<char> slideDown(vector<char> thisConfig, int position)
		{
			char swap = thisConfig[position];
			thisConfig[position] = thisConfig[position - columnsOfPuzzle];
			thisConfig[position - columnsOfPuzzle] = swap;
			return thisConfig;
		}


/*
 *Function Name: slideUp
 *
 *@param: vector<char>
 *@param: int
 *
 *@return: vector<char>
 *
 * Description: slide the puzzle block up and store the new config
 * 
 */
		vector<char> slideUp(vector<char> thisConfig, int position)
		{
			char swap = thisConfig[position];
			thisConfig[position] = thisConfig[position + columnsOfPuzzle];
			thisConfig[position + columnsOfPuzzle] = swap;	
			return thisConfig;
		}


/*
 *Function Name: slideRight
 *
 *@param: vector<char>
 *@param: int
 *
 *@return: vector<char>
 *
 * Description: slide the puzzle block right and store the new config
 * 
 */
		vector<char> slideRight(vector<char> thisConfig, int position)
		{
			char swap = thisConfig[position];
			thisConfig[position] = thisConfig[position - 1];
			thisConfig[position - 1] = swap;
			return thisConfig;
		}


/*
 *Function Name: slideLeft
 *
 *@param: vector<char>
 *@param: int
 *
 *@return: vector<char>
 *
 * Description: slide the puzzle block left and store the new config
 * 
 */
		vector<char> slideLeft(vector<char> thisConfig, int position)
		{
			char swap = thisConfig[position];
			thisConfig[position] = thisConfig[position + 1];
			thisConfig[position + 1] = swap;
			return thisConfig;
		}

/*
 *Function Name: displayResult
 *
 *@param: vector<vector<char> >
 *@param: map<vector<char>,vector<char>
 *
 * Description: displays the solution of transitions and sliding of the blocks to reach the goal state of the puzzle.
 * 
 */
		void displayResult(vector<vector<char> > current, map <vector<char>,vector<char> > seen)
		{
			vector<vector<char> > temp;
			map<vector<char>,vector<char> > :: iterator mIT;
			mIT = seen.find(current.back());
			temp.push_back(mIT->first);
			current.back() = mIT->second;

			if(mIT->first != mIT->second)
				displayResult(current,seen);

			ostream &os = *osp;

			for(vector<vector<char> > :: reverse_iterator rIT = temp.rbegin() ; rIT != temp.rend(); ++rIT)
			{
				vector<char> thisFormation = *rIT;
				for(int block = 0; block < thisFormation.size() ; ++block)
				{
					os << thisFormation[block];

					if((block+1)%rowsOfPuzzle == 0)
						os << "\n";
				}
				os << "\n";	
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
			ostream &os = *osp;
			os << "No solution found for this specific puzzle!\n";
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
int main(int argc, char *argv[])
{
	if(argc != 3)
		cout << "Invalid number of arguments!\n";
	else
	{
		cout << "\n========= The Sam Lloyd Puzzle Problem ==========\n";
		MySolver <vector<char> > solveThis;
		myLloyd lloydPuzzle(argv,argc);
		solveThis.solveIt(lloydPuzzle);
		cout << "\n================== E N D ====================\n";
	}

	return 0;
}
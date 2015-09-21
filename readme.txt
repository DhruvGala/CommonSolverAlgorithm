/* Filename: readme.txt
 *
 * Author: Dhruv Gala (dmg7937)
 * Author: Nikita Nair (nxn7419)
 *
 * Version: 1.0 11/30/2014
 */

Part-1: The Dead Clock Puzzle

Files Needed : MySolver.h  clock.cpp

Compile : g++ clock.cpp

No. of input values : 3 integers

Input : ./a.out 'no. of hours in the clock' 'time where the clock stopped' 'current time to be set'
Output : Path to reach to the current time from where it had stopped.


Description:

MySolver.h
This is the header file which has the base framework for all the puzzles. This is the common header file for all the puzzle problems. 
This file contains the base framework for all the puzzles. 
It contains myFramework class and MySolver class which together act as the framework for solving each and every puzzle.


clock.cpp
This is the cpp file for clock puzzle. the input while running this program is the number of hours on the clock, 
the time currently on the clock(i.e. the time when the clock died) and the the actual or valid time at the moment. 
This file uses MySolver.h as the framework for the algorithm applied.




Part-2: The Water Jug Puzzle

Files Needed : MySolver.h  water.cpp

Compile : g++ water.cpp

No. of input values : 3 to n integers

Input : ./a.out 'the final amount of water needed in the jug' 'water capacity of 1st jug' 'water capacity of 2nd jug' 'water capacity of 3rd jug' ......             		'water capacity of n jug'
Output : The water amount in each jug in each iteration till the goal capacity has been reached.

MySolver.h :
This is the header file which has the base framework for all the puzzles. This is the common header file for all the puzzle problems. 
This file contains the base framework for all the puzzles. 
It contains myFramework class and MySolver class which together act as the framework for solving each and every puzzle.


water.cpp :
This is the cpp file for water-jug puzzle. the input when running this program can vary. A user can input as many jug he/she wishes to enter. A basic sample is <the final amount of water needed> following by the maximum capacity of each jugs that the user wishes to enter. This file uses MySolver.h as the framework for the algorithm applied.





Part-3: The Sam Lloyd Puzzle

Files Needed : MySolver.h  lloyd.cpp input.txt output.txt

Compile : g++ lloyd.cpp

No. of input values : if using file to get input and write ouput in file --> input.txt output.txt
		      if using file to get input and write ouput on command line --> input.txt -
		      if using command line to give input and write ouput in file --> - output.txt
		      if using command line to give input and write ouput on command line --> - - 

Input : ./a.out 'the input and ouput command values as mention above in the no. of input values'
Output : The puzzle configuration in each iteration till goal state is reached


Description: 

MySolver.h :
This is the header file which has the base framework for all the puzzles. This is the common header file for all the puzzle problems. 
This file contains the base framework for all the puzzles. 
It contains myFramework class and MySolver class which together act as the framework for solving each and every puzzle.


lloyd.cpp :
This is the cpp file for lloyd puzzle. 
A choice of input and output is provided to the user, using direct as well as file stream input and output is possible. 
The initital two arguments contain the dimension of the problem.
The next two matrix formed arguments are the initial and the goal state of the puzzle.
note. when ran the code on 3 * 3 matrix takes long time to output the solution as we have used vector<vector> to store all configurations.


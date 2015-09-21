/* Filename: readMe_part4.txt
 *
 * Author: Dhruv Gala (dmg7937)
 *
 * Version: 1.0 12/10/2014
 */

Part-4: The Variable Dead Clock Puzzle

Files Needed : MySolver.h  variableClock.cpp

Compile : g++ variableClock.cpp

No. of input values : n number of integers

Input : ./a.out 'no. of hours in the clock' 'time where the clock stopped' 'current time to be set' 'n number of variables to change the clock by'
Output : Path to reach to the current time from where it had stopped.


Description:

MySolver.h
This is the header file which has the base framework for all the puzzles. This is the common header file for all the puzzle problems. 
This file contains the base framework for all the puzzles. 
It contains myFramework class and MySolver class which together act as the framework for solving each and every puzzle.


variableClock.cpp
This is the cpp file for clock puzzle with a variation.
the input while running this program is the number of hours on the clock, the time currently on the clock(i.e. the time when the clock died) ,
the actual or valid time at the moment and 'n' number of variables that are the variables by which the clock hour hand could be moved.
This file uses MySolver.h as the framework for the algorithm applied.
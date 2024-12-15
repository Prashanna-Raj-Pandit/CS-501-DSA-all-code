#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <queue> 

//#include "ArrayQueue.h"

using namespace std;

int main ()
{


	queue<int> waitingLine;		// waiting line of some sort, post office
								// car wash, etc. it's a queue of enterTime
  	int   washTime,				// Time (in min) it takes to wash a car
								// similar to serviceTime in bank HW4
     	  currentTime,			// loop counter       
	      timeLeft = 0,			// minutes left for the current car being washed
								// initially 0 as no car in wash room
	      carsWashed = 0,		// keeping track of total number of cars washed
	      enterTime,			// the min at which a car enter the queue
	      waitingTime,			// waiting time for the car just dequeued (or poped)
	      totalWaitingTime=0,	// total waiting time, from all cars
	      simulationTime;		// simulation time
	float prob,					// probability of arrival at any moment.
	      random;				// current random number between 0 and 1

	int wt;

    cout << "Enter the amount of time needed to wash one car\n";
	cin >> washTime ;
	cout << "Enter total time of simulation in minutes\n";
	cin >> simulationTime;   
  	cout << "Enter the probability of car arrival at a particular time\n";

	cin >> prob; 


	int seed = clock() % 100;	// use clock time as seed
	cout << seed << endl;		// check seed value for different runs
	srand(seed);				// initialize the rand function
  
	// loop around one minute at a time, using current_time
	for (currentTime = 1; currentTime <= simulationTime; currentTime++)
	{
	//	cout << "queue length is "
		//	<< waitingLine.size() << endl;

		// function call rand() will return a random number
		// between 0 and RAND_MAX. Therefore, rand()/float (RAND_MAX)
		// will get us a random number between 0 and 1.
		// to use rand(), we must include stdlib.h
		random = rand() / float(RAND_MAX);

	//	cout << "random is " << random << " ";

		// if random < prob, a car enter the queue waitingline
		// with a tag containing the current time.

		if (random <= prob)
			waitingLine.push(currentTime);

		if (timeLeft > 0)
			timeLeft--;  // reduce time by one for the current car in wash room

	  // if there is no wash time left for the car in the
	  // wash room, AND there are still car in the waitingline,
	  // dequeue the front car to start the next wash cycle

		if ((timeLeft == 0)  // wash room is empty
			&& (!waitingLine.empty()))
		{
			enterTime = waitingLine.front(); // retrieve enter time of the car
											  // at front of queue
			waitingLine.pop();
			waitingTime = currentTime - enterTime;
			totalWaitingTime += waitingTime;  // add to total
			carsWashed++;
			timeLeft = washTime; // start washing the next car
		}
	} // end of for
	// empty the queue and added the wait time for the cars that did not get washed
	int carsNotWashed = 0;
	while (!waitingLine.empty())
	{
		int ET = waitingLine.front(); // ET = enterTime
		totalWaitingTime += simulationTime - ET;
		waitingLine.pop();
		carsNotWashed++;

	}
		cout << setiosflags(ios::showpoint || ios::fixed);
		cout << setprecision(2);

		cout << "\n\n" << carsWashed << " cars washed\n";
		if (carsWashed+carsNotWashed > 0)
			cout << " The average waiting time is "
			<< totalWaitingTime / float(carsWashed+carsNotWashed)/60 << " minutes"
			<< endl;
	
	return 0;
}

#include "FunctionName.h" // gets the header will all of the functions names
#include "stdafx.h" // gets the stdafx that has all of the library's listed for each program to run.


void Name() //first function to allow the player to put their name in
{
	string PlayerName = ""; // player name holder
	cout << "Hello today is your first day at the CIA please enter your name " << endl;
	cin >> PlayerName; // player name input

	cout << "Hello, " << PlayerName << " welcome to your first day at the CIA." << endl; // simply to show that the name was stored and can be used again.
	return;
}

// this is the Jumaingi game that we did at the beginning of the semester but edited a bit
int Simulation()
{
	//stores the amount of gold pieces to be found as an int
	const int GOLD_PIECES = rand() % 100 + 1;

	// adventures store the number of adventures on the quest as an int
	// killed store the number of adventures killed on the quest as an int
	// suvivors store the number of left over adventures as an int
	// leader stores the name input as a string
	int adventures, killed, suvivors;
	string leader;

	//get the information
	//cout is diplaying the words
	cout << "Welcome to the CIA training simulation\n\n";
	cout << "Please enter some info for the training simulation.\n\n";
	cout << "How many operatives would you like to lead?: ";
	cin >> adventures;
	// storing the number input in the adventures slot

	cout << "How many operatives are you willing to lose to take down the target?: ";

	cin >> killed;
	// storing the number input in the kiled slot

	suvivors = adventures - killed;
	// storing the number in the suvivors slot after it is calculated

	cout << "Enter operation leaders name: ";

	cin >> leader;
	// storing the name input in the leader slot

	//Tell the story
	//Uses the adventures number that was input and stored and displays it
	cout << "\nA group of " << adventures << " CIA operatives have been brought into Russia to take down thier target.\n ";
	//Uses the leader name that was input and stored and displays it
	cout << "\nThe group is being lead by " << leader << ".\n";

	cout << "\nWhile going after the target many dangers will appear and not all the operatives will get out alive...\n ";
	//Uses the leader name that was input and stored and displays it
	cout << "\nThe operatives are begining to question their leader " << leader << ".\n";
	//Uses the suvivors number that was calculated and stored and displays it
	cout << "\nOne particular fight ends up taking out several operatives leaving only " << suvivors << " operatives left to finish the mission.\n";

	cout << "\nThe group is starting to give up.\n";

	cout << "\nIt's danger after danger with no hope of getting the target.\n ";

	cout << "\nUntil they see it, the finish, a mountain of gold to be split among the group. \n";
	cout << "\nIt seems as though the operatives have decided to go into the private sector... \n";
	//Uses the GOLD_PIECES that was created and displays it
	cout << "\nThe group split " << GOLD_PIECES << " gold.\n";

	// % finds the left over pieces after passing out gold to the suvivors and then displays it
	cout << "\nThe extras were " << (GOLD_PIECES % suvivors);
	//Uses the leader name that was input and stored and displays it
	cout << " given to " << leader << " as thanks for leading the group.\n" << endl;
	//It kept running without stopping so I made it using the same thing we did in class during game on

	return 0;
}

void Search() // this is the skynet program that we did in class. This is the version where the usuer only has to hit and the computer will guess for them
{
	srand(static_cast<unsigned int>(time(0))); //  Seed random number generator so that its not the same every time.
											   //  By using the time on the computer the numbers change based on time

	int TargetLoaction = rand() % 64 + 1; // Random number between 1 and 64
	int tries = 0; // Number of tries to find the target
	int Search; // Holds the number they guessed

	cout << "\tWelcome to Target Search. This simulation will be the computer tring to find the enemy target. \n\n";
	system("pause");
	int low = 0; // this defines the starting low number for the equation that the computer will run
	int high = 64; // this defines the starting high number for the equation that the computer will run
	int targetLocationPrediction; // this is the holder for each guess and will change each time until it is equal to the target location

	do // The do while loop forces the program to run at least once and then again and again until the computer finds the right number

	{
		// Its a little different than what was done in class but it works and is less typing.
		//Basically the high is added to the low and then divided by two each time, the high or low is increased or decreased respectivly if the guess is two high or low.
		// During the next run though the number is either lower or higher depending on if the pervious guess was to high or to low.
		targetLocationPrediction = ((high + low) / 2); // the equation has () in it to make sure the computer does the equation correctly instead of just reading right to left.

		++tries; // Counts the number of tries the computer takes to get the right number. it is added to during each loop cycle
		cout << "\nSearching Sector: \n";
		cout << targetLocationPrediction;
		cout << "\n";
		system("pause"); // pauses the game each time so that the player can see what the guess was and cotinue to the next guess
		if (targetLocationPrediction > TargetLoaction) // compares the guess to the real number and decides if it is to high and runs the loop again
		{
			cout << "The enemy is not here better search lower.\n\n";
			high = targetLocationPrediction; // changes the high number to the guess number that was to high
		}
		else if (targetLocationPrediction < TargetLoaction) // compares the guess to the real number and decides if it is to low and runs the loop again
		{
			cout << "The enemy is not here better search higher.\n\n";
			low = targetLocationPrediction; // changes the low number to the guess number that was to low
		}
		else // do this if the guess is not to high or to low
		{
			cout << "\nTarget found sending in operatives........";
			cout << "\nTries to find target: " << tries << "\n";
		}

	} while (targetLocationPrediction != TargetLoaction); // forces the loop to go again and again until the the targetLocationPrediction is the same as TargetLoaction

	return ; // returns an int to main since that what the type is.
}

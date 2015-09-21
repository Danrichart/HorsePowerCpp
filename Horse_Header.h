#ifndef Horse_Header_h
#define Horse_Header_h

//include all necessary files and defines MAX
#include <iostream>
#include <string>
#include <time.h>
#define MAX 4
#include <cstdlib>
#include <stdio.h>
using namespace std;

class Horse{
	//creates position and id properties as private
	int position;
	int id;
public:
	//Horse class constructor with null paramater
	//makes current horse position 0 and id 0
	Horse(){
		position = 0;
		id = 0;
	}
	//getter for position
	int getPosition(){
		return position;
	}
	//setter for id
	void setId(int x){
		id = x;
	}
	//getter for id
	int getId(){
		return id;
	}
	//method that increases current Horse position by 1
	void advance(){
		position += 1;
	}
	
};

class Race {
	//creates length and winnerId properties to private
	int length;
	int winnerId;
	Horse h[4];
public:
	//null constructor initalizes length to 25, winnder id to -1, and sets horses[0-3] to ids 1-4
	Race(){
		length = 25;
		winnerId = -1;
		for (int i = 0; i < MAX; i++){
			h[i].setId(i + 1);
		}
			
	}

	//print out of lane of current horse
	void printLane(Horse h){

		//for loop for the length of the race object(25)
		for (int x = 0; x < length; x++){
			//if current horse = length of race set winner to current horses id
			if (h.getPosition() == length - 1){
				winnerId = h.getId();
			}
			//if current horse position = x, then print id instead of . 
			if (x == h.getPosition()){
				cout << h.getId();
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}

	// starts main loop for race
	void start(){	
		srand(time(NULL)); //seed time
		int ran; // int for random integer
		
		// while loop that works as long as there is no winner initalized
		while (winnerId == -1){

			//for loop to printLane for all horses
			for (int x = 0; x < MAX; x++){
				printLane(h[x]);
			}

			//for loop that creates a random int between 0 and 1.
			//if ran = 1, then horse.advances + 1
			//otherwise move to next horse and do not advance their position
			for (int i = 0; i < MAX; i++){
				ran = rand() % 2;
				if (ran == 1){
					h[i].advance();
				}
				else{
					continue;
				}
			}
			// Prompts user to press enter to continue to next round
			cout << "Press enter to continue\n";
			cin.ignore();
		}

		//once winnerId is initalized, exit loop and print horse id for current winner
		printf("Horse %d wins!\n\n", winnerId);
	}

};


#endif
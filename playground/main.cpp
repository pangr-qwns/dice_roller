//
//  main.cpp
//  playground
//
//  Created by Raymond Pang on 11/26/19.
//  Copyright © 2019 Raymond Pang. All rights reserved.
//

#include <iostream>     /* cout, cin, all that basic good stuff */
#include <stdlib.h>     /* srand, rand */
#include <vector>

using namespace std;

int generate_random_number(int min, int max) {
	// generate a random number between min and max
	// citation: http://www.math.uaa.alaska.edu/~afkjm/csce211/fall2018/handouts/RandomFunctions.pdf
	return (rand() % (max-1)) + min;
}

int main(int argc, const char * argv[]) {

	// initialize random seed to any number
	srand(100);
	
	// create a vector where the index is the sum of the two rolls and the value
	// is the frequency
	vector<int> sums(41, 0);
	
	for (int i = 0; i < 500; ++i) {
		// generate secret number between 2 and 20
		int dice_one_faces = generate_random_number(2, 20);
		int dice_two_faces = generate_random_number(2, 20);
		
		// generate random roll from 1 to the number of faces
		int dice_one_roll = generate_random_number(1, dice_one_faces);
		int dice_two_roll = generate_random_number(1, dice_two_faces);
		
		// sum of the two rolls
		int sum = dice_one_roll + dice_two_roll;
		
		// add to vector of frequencies of sum of rolls
		sums[sum] += 1;
	}
	
	// print frequencies
	for (int i = 0; i < sums.size(); ++i) {
		cout << "sums[" << i << "]: " << sums[i] << endl;
	}
	
	// create histogram
	
	return 0;
}

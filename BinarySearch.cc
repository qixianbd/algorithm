//============================================================================
// Name        : job_finder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


int binarySearch(int array[], int begin, int end, int elem)
{
	int mid = 0;
	while(begin <= end){
		mid = (int) ((long)begin + end)/2;
		if(elem == array[mid]){
			return mid;
		}
		else if(elem < array[mid]){
			end = mid -1;
		}
		else{
			begin = mid + 1;
		}
	}
	return -1;
}




int main(void) {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int result = binarySearch(array, 0, 7, 8);
	std::cout << "result = " << result << std::endl;
	result = binarySearch(array, 0, 7, 3);
	std::cout << "result = " << result << std::endl;
	result = binarySearch(array, 0, 7, 0);
	std::cout << "result = " << result << std::endl;
	result = binarySearch(array, 0, 7, 7);
	std::cout << "result = " << result << std::endl;

	std::vector<int> newarray;
	//std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), back_inserter(newarray));
	int i = 0;
	while(std::cin){
		int value = 0;
		std::cin >> value;
		newarray.push_back(value);
	}
	std::cout << "dfasdas" << std::endl;
	std::cout << newarray[0] << std::endl;
	std::copy(newarray.begin(), newarray.end(), std::ostream_iterator<int>(std::cout, "\n"));

	return EXIT_SUCCESS;
}

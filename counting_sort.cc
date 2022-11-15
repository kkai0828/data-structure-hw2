
//code from https://www.geeksforgeeks.org/implementing-counting-sort-using-map-in-c/?ref=gcse
//#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
// C++ implementation of the approach
// Function to sort the array using counting sort
void countingSort(vector<int> arr, int n)
{

	// Map to store the frequency
	// of the array elements
	map<int, int> freqMap;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		freqMap[*i]++;
	}

	int i = 0;

	// For every element of the map
	for (auto it : freqMap) {

		// Value of the element
		int val = it.first;

		// Its frequency
		int freq = it.second;
		for (int j = 0; j < freq; j++)
			arr[i++] = val;
	}

/*	// Print the sorted array
	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i << " ";
	}*/
}




int main()
{
       for(int k = 15; k<=30;k++){
          float T = 0;
          for(int t = 0; t < 10; t++){
              int SIZEOFARR = pow(2,k);
              vector <int> Myvector;
              for (int i = 0; i< SIZEOFARR; i++){
                  Myvector.push_back( rand()%1001 );
              }
              auto arrsize = sizeof(Myvector) / sizeof(Myvector[0]);
              clock_t Startime = clock();
              countingSort(Myvector,Myvector.size());
              clock_t Endtime = clock();
              T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
              Myvector.clear();
          }
          printf("When k = %d, It takes %.2f (s).\n",k ,T/10);
      }
      return 0;
}

// This code is contributed by rathbhupendra



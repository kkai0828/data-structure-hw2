//https://www.geeksforgeeks.org/counting-sort/
// C++ Program for counting sort
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
#define RANGE 255

// The main function that sort
// the given string arr[] in
// alphabetical order
void countSort(vector<int> arr)
{
    // The output character array
    // that will have sorted arr
    int output[strlen(arr)];

    // Create a count array to store count of individual
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    /*
       For Stable algorithm
       for (i = sizeof(arr)-1; i>=0; --i)
       {
       output[count[arr[i]]-1] = arr[i];
       --count[arr[i]];
       }

       For Logic : See implementation
       */

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

// Driver code
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
              countSort(Myvector);
              clock_t Endtime = clock();
              T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
              Myvector.clear();
          }
          printf("When k = %d, It takes %.2f (s).\n",k ,T/10);
      }
      return 0;
}

// This code is contributed by rathbhupendra



//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/?ref=gcse
/* C++ implementation of QuickSort using Hoare's
   partition scheme. */
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/* This function takes first element as pivot, and places
   all the elements smaller than the pivot on the left side
   and all the elements greater than the pivot on
   the right side. It returns the index of the last element
   on the smaller side*/
int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met.
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
void quickSort(vector<int> arr, int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
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
              quickSort(Myvector,0,arrsize-1);
              clock_t Endtime = clock();
              T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
              Myvector.clear();
          }
          printf("When k = %d, It takes %.2f (s).\n",k ,T/10);
      }
      return 0;
}



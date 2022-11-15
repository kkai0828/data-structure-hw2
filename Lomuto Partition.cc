// https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/?ref=gcse
/* C++ implementation QuickSort using Lomuto's partition
   Scheme.*/
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
void quickSort(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
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
              quickSort(Myvector ,0,arrsize-1);
              clock_t Endtime = clock();
              T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
              Myvector.clear();
          }
          printf("When k = %d, It takes %.2f (s).\n",k ,T/10);
      }
      return 0;
}



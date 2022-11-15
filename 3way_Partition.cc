//https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/?ref=gcse
// C++ program for 3-way quick sort
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(vector<int> a, int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];

    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (a[++i] < v)
            ;

        // From right, find the first element smaller than
        // or equal to v
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done
        if (i >= j)
            break;

        // Swap, so that smaller goes on left greater goes
        // on right
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(vector<int> a, int l, int r)
{
    if (r <= l)
        return;

    int i, j;

    // Note that i and j are passed as reference
    partition(a, l, r, i, j);

    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
}

// A utility function to print an array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
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
              quicksort(Myvector ,0,arrsize-1);
              clock_t Endtime = clock();
              T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
              Myvector.clear();
          }
          printf("When k = %d, It takes %.2f (s).\n",k ,T/10);
      }
      return 0;
}



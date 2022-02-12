#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(log N)

    Where 'N' is the number of elements in the given array/list.
*/

// An auxilliary function to partition the array/list based on a pivot.
void partition(vector<int> &arr, int beg, int last, int &start, int &mid)
{
 int pivot = arr[last];
 int end = last;

 // Iterate while mid is not greater than end.
 while (mid <= end)
 {
  // Place the element at the starting if it's value is less than pivot.
  if (arr[mid] < pivot)
  {
   swap(arr[mid], arr[start]);
   mid = mid + 1;
   start = start + 1;
  }

  // Place the element at the end if it's value is greater than pivot.
  else if (arr[mid] > pivot)
  {
   swap(arr[mid], arr[end]);
   end = end - 1;
  }

  else
  {
   mid = mid + 1;
  }
 }
}

// An auxiallary function to sort the array.
void quicksort(vector<int> &arr, int beg, int last)
{
 // Base case when the size of array is 1.
 if (beg >= last)
 {
  return;
 }

 // To handle the case when there are only 2 elements in the array.
 if (last == beg + 1)
 {
  if (arr[beg] > arr[last])
  {
   swap(arr[beg], arr[last]);
   return;
  }
 }

 int start = beg, mid = beg;

 // Function to partition the array.
 partition(arr, beg, last, start, mid);

 // Recursively sort the left and the right partitions.
 quicksort(arr, beg, start - 1);
 quicksort(arr, mid, last);
}

vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
 // Call the quicksort function.
 quicksort(arr, 0, arr.size() - 1);

 // Return the array/list after sorting.
 return arr;
}
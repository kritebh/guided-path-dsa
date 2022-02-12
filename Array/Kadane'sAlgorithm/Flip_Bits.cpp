#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Time Complexity: O(N)
    Space complexity: O(1)

    Where N is the length of the array.
*/

int flipBits(int *arr, int n)
{
 int totalOnes = 0;

 // Initialize overall maximum difference for any subArray
 int maxVal = 0;

 // Initialize current difference
 int currMax = 0;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] == 1)
  {
   totalOnes++;
  }

  // Value to be considered for finding maximum sum
  int val = 0;
  if (arr[i] == 1)
  {
   val = -1;
  }
  else
  {
   val = 1;
  }
  currMax = max(val, currMax + val);
  maxVal = max(maxVal, currMax);
 }

 maxVal = max(0, maxVal);
 int result = totalOnes + maxVal;
 return result;
}
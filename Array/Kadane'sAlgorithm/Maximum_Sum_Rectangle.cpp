#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

#include <climits>
#include <vector>
int kadane(vector<int> array, int n)
{
 int tempSum = 0;
 int maxSum = INT_MIN;
 for (int i = 0; i < n; i++)
 {
  tempSum += array[i];
  if (tempSum > maxSum)
  {
   maxSum = tempSum;
  }
  if (tempSum < 0)
  {
   tempSum = 0;
  }
 }
 return maxSum;
}

int maxSumRectangle(vector<vector<int>> &arr, int n, int m)
{
 // write your code here
 int maxSum = INT_MIN;
 for (int i = 0; i < m; i++)
 {
  vector<int> temp_arr(n);
  for (int j = i; j < m; j++)
  {
   for (int k = 0; k < n; k++)
   {
    temp_arr[k] += arr[k][j];
   }
   maxSum = max(maxSum, kadane(temp_arr, n));
  }
 }
 return maxSum;
}

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Tutorial : https://www.youtube.com/watch?v=qnoOu5Usb4o

#include <climits>

long long kadane(vector<int> &arr, int n, int k)
{
 long long curr_sum = 0;
 long long max_sum = INT64_MIN;
 for (int i = 0; i < (n * k); i++)
 {
  curr_sum += arr[i % n];
  max_sum = max(max_sum, curr_sum);
  if (curr_sum < 0)
  {
   curr_sum = 0;
  }
 }
 return max_sum;
}

long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
 long long maxSum = 0;
 if (k == 1)
 {
  maxSum = kadane(arr, n, k);
  return maxSum;
 }

 long long arrSum = 0;
 for (int i = 0; i < n; i++)
 {
  arrSum += arr[i];
 }

 if (arrSum <= 0)
 {
  /* ans = kadane of first 2 copies  */
  maxSum = kadane(arr, n, 2);
 }
 else if (arrSum > 0)
 {
  /* ans = kadane of first 2 copies + (k-2) * arrSum */
  maxSum = kadane(arr, n, 2);
  maxSum += (long long)(k - 2) * (long long)arrSum;
 }

 return maxSum;

 //     vector<int> concat;
 //     for(int i = 0;i < (n*k);i++)
 //     {
 //         concat.push_back(arr[i%(n)]);
 // 	}
 //     long long curr_sum = 0;
 //     long long max_sum = INT64_MIN;
 //     for(int i = 0;i < (n*k); i++)
 //     {
 //         curr_sum += concat[i];
 //         max_sum = max(max_sum, curr_sum);
 //         if(curr_sum < 0)
 //         {
 //             curr_sum = 0;
 //         }
 // 	}
 //     return max_sum;
}
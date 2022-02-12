#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

#include <climits>
long long maxSubarraySum(int arr[], int n)
{
 /*
     Don't write main().
     Don't read input, it is passed as function argument.
     No need to print anything.
     Taking input and printing output is handled automatically.
 */
 long long currSum = 0;
 long long maxSum = INT64_MIN;

 for (int i = 0; i < n; i++)
 {
  currSum += arr[i];

  if (currSum < 0)
  {
   currSum = 0;
  }

  maxSum = max(maxSum, currSum);
 }
 return maxSum;
}
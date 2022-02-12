#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
int bestInsertPos(vector<int> arr, int n, int m)
{
 if (n == 0)
 {
  return 0;
 }

 /* lower_bound return the index of element in array if present,
 and if not then the index i is returned such that arr[i-1] < target,
 and so i is exactly the index target would be placed in a sorted array */
 int index = lower_bound(arr.begin(), arr.end(), m) - arr.begin();

 return index;
}
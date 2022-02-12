#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int *getProductArrayExceptSelf(int *arr, int n)
{
 // Write your code here
 int mod = 1e9 + 7;
 int *suffix = new int[n];
 int *prefix = new int[n];
 int prod = 1;
 for (int i = 0; i < n; i++)
 {
  prefix[i] = prod;
  prod = (prod * arr[i]) % mod;
 }
 prod = 1;
 for (int i = n - 1; i >= 0; i--)
 {
  suffix[i] = prod;
  prod = (prod * arr[i]) % mod;
 }
 int *ans = new int[n];
 for (int i = 0; i < n; i++)
 {
  ans[i] = (prefix[i] * suffix[i]) % mod;
 }
 return ans;
}
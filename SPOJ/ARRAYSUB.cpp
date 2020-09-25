// ARRAYSUB - subarrays
// #datastructures #sliding-window-1 #data-structure-1
// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

// Input
// the number n denoting number of elements in the array then after a new line we have the numbers of the array and then k in a new line

// n < 10^6
// k < 10^5
// 1 <= k <= n

// and each element of the array is between 0 and 10^6

// (Edited: In fact, n <= 10^5)

// Output
// print the output array

// Example
// Input:
// 9
// 1 2 3 1 4 5 2 3 6
// 3

// Output:
// 3 3 4 5 5 5 6

#include<iostream>
#include<algorithm>
 #include <vector>
  #include <deque>
using namespace std;

int main() {
	int n,k;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++)
	cin>>nums[i];
	cin>>k;
	vector <int> v;
        deque <int> dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // int n = nums.size();
        for(int i=k;i<n;i++)
        {
            cout<<nums[dq.front()]<<" ";
            // v.insert(v.begin(),nums[dq.front]);
            v.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            
        }
        v.push_back(nums[dq.front()]);
        cout<<nums[dq.front()]<<" ";
	return 0;
}

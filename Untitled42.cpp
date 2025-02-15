//STL Lower Bound-STL
//You are given  integers in sorted order. Also, you are given  queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.
//
//Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by clicking here.
//
//Input Format
//
//The first line of the input contains the number of integers . The next line contains  integers in sorted order. The next line contains , the number of queries. Then  lines follow each containing a single integer .
//
//Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.
//
//Constraints
//
//
//,where  is  element in the array.
//
//
//Output Format
//
//For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.
//
//If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.
//
//You have to output each query in a new line.
//
//Sample Input
//
// 8
// 1 1 2 2 6 9 9 15
// 4
// 1
// 4
// 9
// 15
//Sample Output
//
// Yes 1
// No 5
// Yes 6
// Yes 8

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    //taking input
    int n{};
    cin >> n;
    vector<int> v;
    for (int i{0}; i < n; ++i)
    {
        int t{};
        cin >> t;
        v.push_back(t);
    }
    // s is number of queries
    int s;
    cin >> s;
    // foreach query, get the value and print necessary value
    for (int i{0}; i < s; ++i)
    {
        int num{}; cin >> num;
        // lower bound returns an iterator type variable
        vector<int>::iterator x;
        x = lower_bound(v.begin(), v.end(), num);
        // getting the index of the lowerbound in the vector
        int pos = x - v.begin(); 
        // if value of lb = the query num, then yes it exists
        // in the vector exists
        if (v[pos] == num) cout << "Yes "<< pos+1;
        else cout << "No "<< pos+1;
        cout << endl;
    }
    
    return 0;
}

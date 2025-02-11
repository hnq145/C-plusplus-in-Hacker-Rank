//STL Vector-Erase
//You are provided with a vector of  integers. Then, you are given  queries. For the first query, you are provided with  integer, which denotes a position in the vector. The value at this position in the vector needs to be erased. The next query consists of  integers denoting a range of the positions in the vector. The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.
//The following are some useful vector functions:
//
//erase(int position):
//
//Removes the element present at position.  
//Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)
//erase(int start,int end):
//
//Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
//Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)
//Input Format
//
//The first line of the input contains an integer .The next line contains  space separated integers(1-based index).The third line contains a single integer ,denoting the position of an element that should be removed from the vector.The fourth line contains two integers  and  denoting the range that should be erased from the vector inclusive of a and exclusive of b.
//
//
//Constraints
//
//
//
//Output Format
//
//Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.
//
//Sample Input
//
//6
//1 4 6 2 8 9
//2
//2 4
//Sample Output
//
//3
//1 8 9
//Explanation
//
//The first query is to erase the 2nd element in the vector, which is 4. Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2~4, which means the 2nd and 3rd elements should be removed. Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n; // Read the size of the vector

    vector<int> v(n); // Declare a vector of size n

    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Read the elements of the vector
    }

    int q1;
    cin >> q1; // Read the index to erase
    v.erase(v.begin() + q1 - 1); // Erase the element at index q1

    int q2, q3;
    cin >> q2 >> q3; // Read the range [q2, q3) to erase
    v.erase(v.begin() + q2 - 1, v.begin() + q3 - 1); // Erase the elements in the given range

    cout << v.size() << endl; // Print the size of the vector

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // Print the elements of the vector
    }   
    return 0;
}

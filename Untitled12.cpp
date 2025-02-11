//Other Concepts C++ Class Template Specialization
//You are given a main function which reads the enumeration values for two different types as input, then prints out the corresponding enumeration names. Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown.
//
//Input Format
//
//The first line contains , the number of test cases.
//Each of the  subsequent lines contains two space-separated integers. The first integer is a color value, , and the second integer is a fruit value, .
//
//Constraints
//
//Output Format
//
//The locked stub code in your editor prints  lines containing the color name and the fruit name corresponding to the input enumeration index.
//
//Sample Input
//
//2
//1 0
//3 3
//Sample Output
//
//green apple
//unknown unknown
//Explanation
//
//Since , there are two lines of output.
//
//The two input index values,  and , correspond to green in the color enumeration and apple in the fruit enumeration. Thus, we print green apple.
//The two input values,  and , are outside of the range of our enums. Thus, we print unknown unknown.
#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template<class T>
struct Traits
{
    static std::string name(int);
};

template<>
std::string Traits<Color>::name(int n)
{
    if(n==(int)Color::green)return std::string("green");
    if(n==(int)Color::red)return std::string("red");   
    if(n==(int)Color::orange)return std::string("orange");
    return std::string("unknown");
};

template <>
std::string Traits<Fruit>::name(int n)
{
    if(n==(int)Fruit::apple)return std::string("apple");
    if(n==(int)Fruit::orange)return std::string("orange");   
    if(n==(int)Fruit::pear)return std::string("pear");
    return std::string("unknown");   
}


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}


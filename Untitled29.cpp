//Classes Box It!
//Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .
//
//The default constructor of the class should initialize , , and  to .
//
//The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.
//
//The copy constructor BoxBox ) should set  and  to 's  and , respectively.
//
//Apart from the above, the class should have  functions:
//
//int getLength() - Return box's length
//int getBreadth() - Return box's breadth
//int getHeight() - Return box's height
//long long CalculateVolume() - Return the volume of the box
//Overload the operator  for the class Box. Box   Box  if:
//
// < 
// <  and ==
// <  and == and ==
//Overload operator  for the class Box().
//If  is an object of class Box:
//
// should print ,  and  on a single line separated by spaces.
//
//For example,
//
//Box b1; // Should set b1.l = b1.b = b1.h = 0;
//Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
//b2.getLength();	// Should return 2
//b2.getBreadth(); // Should return 3
//b2.getheight();	// Should return 4
//b2.CalculateVolume(); // Should return 24
//bool x = (b1 < b2);	// Should return true based on the conditions given
//cout<<b2; // Should print 2 3 4 in order.
//Constraints
//
//
//Two boxes being compared using the  operator will not have all three dimensions equal.

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box {
private:
    int length, breadth, height;

public:
    // Constructors
    Box() : length(0), breadth(0), height(0) {}
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}
    Box(const Box& box) : length(box.length), breadth(box.breadth), height(box.height) {}

    // Getter functions
    int getLength() { return length; }
    int getBreadth() { return breadth; }
    int getHeight() { return height; }

    // Calculate volume
    long long CalculateVolume() { return static_cast<long long>(length) * breadth * height; }

    // Operator overloading <
    bool operator<(const Box& b) {
        if (length < b.length)
            return true;
        else if (length == b.length && breadth < b.breadth)
            return true;
        else if (length == b.length && breadth == b.breadth && height < b.height)
            return true;
        else
            return false;
    }

    // Operator overloading <<
    friend ostream& operator<<(ostream& out, const Box& B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}

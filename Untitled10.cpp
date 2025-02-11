//Other Concepts Overload Operators 
//You are given a class - Complex.
//
//class Complex
//{
//public:
//    int a,b;
//};
//Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:
//
//type operator sign (parameters) { /*... body ...*/ }
//You need to overload operators + and << for the Complex class.
//
//The operator + should add complex numbers according to the rules of complex addition:
//
//(a+ib)+(c+id) = (a+c) + i(b+d)  
//Overload the stream insertion operator << to add "" to the stream:
//
//cout<<c<<endl;
//The above statement should print "" followed by a newline where  and .
//
//Input Format
//
//The overloaded operator + should receive two complex numbers ( and ) as parameters. It must return a single complex number.
//
//The overloaded operator << should add "" to the stream where  is the real part and  is the imaginary part of the complex number which is then passed as a parameter to the overloaded operator.
//
//Output Format
//
//As per the problem statement, for the output, print "" followed by a newline where  and .
//
//Sample Input
//
//3+i4
//5+i6
//Sample Output
//
//8+i10
//Explanation
//
//Given output after performing required operations (overloading + operator) is 8+i10.

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator +(Complex t,Complex r){
    Complex temp;
    temp.a=t.a+r.a;
    temp.b=t.b+r.b;
    return temp;
}
ostream & operator<<(ostream &dout,Complex x){
    dout<<x.a<<"+i"<<x.b;
    return dout;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}


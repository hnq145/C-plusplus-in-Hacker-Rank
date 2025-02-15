//Other Concepts Attending Workshops
//A student signed up for  workshops and wants to attend the maximum number of workshops where no two workshops overlap. You must do the following:
//
//Implement  structures:
//
//struct Workshop having the following members:
//
//The workshop's start time.
//The workshop's duration.
//The workshop's end time.
//struct Available_Workshops having the following members:
//
//An integer,  (the number of workshops the student signed up for).
//An array of type Workshop array having size .
//Implement  functions:
//
//Available_Workshops* initialize (int start_time[], int duration[], int n)
//Creates an Available_Workshops object and initializes its elements using the elements in the  and  parameters (both are of size ). Here,  and  are the respective start time and duration for the  workshop. This function must return a pointer to an Available_Workshops object.
//
//int CalculateMaxWorkshops(Available_Workshops* ptr)
//Returns the maximum number of workshops the student can attendówithout overlap. The next workshop cannot be attended until the previous workshop ends.
//
//Note: An array of unknown size () should be declared as follows:
//
//DataType* arrayName = new DataType[n];
//Input Format
//
//Input from stdin is handled by the locked code in the editor; you simply need to write your functions to meet the specifications of the problem statement above.
//
//Constraints
//
//Output Format
//
//Output to stdout is handled for you.
//
//Your initialize function must return a pointer to an Available_Workshops object.
//Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.
//
//Sample Input
//
//6
//1 3 0 5 5 8
//1 1 6 2 4 1
//Sample Output
//
//CalculateMaxWorkshops should return .
//
//Explanation
//
//The first line denotes , the number of workshops.
//The next line contains  space-separated integers where the  integer is the  workshop's start time.
//The next line contains  space-separated integers where the  integer is the  workshop's duration.
//
//The student can attend the workshops  and  without overlap, so CalculateMaxWorkshops returns  to main (which then prints  to stdout).

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    friend ostream &operator<<(ostream &os, const Workshops &obj);
    int start_time;
    int end_time;
    int duration;
    bool operator<(const Workshops &rhs){
    return (this->end_time < rhs.end_time);
    }
};
ostream &operator<<(ostream &os, const Workshops &obj){
    os << obj.start_time << ": " << obj.end_time << ": "
    << obj.duration << "\n";
    return os;
}
struct Available_Workshops{
    int n;
    vector<Workshops> vec;
};
Available_Workshops* initialize(int start_time[], int duration[], int num)
{
    Available_Workshops *avail = new Available_Workshops;
    avail->n = num;
    Workshops test;
    for(int i{0}; i < num; i++){
        test.start_time = start_time[i];
        test.duration = duration[i];
        test.end_time = start_time[i] + duration[i];
        avail->vec.push_back(test);
    }
    sort(avail->vec.begin(), avail->vec.end());
    return avail;
}
int CalculateMaxWorkshops(Available_Workshops *test){
    int w_count = 1;
    int test_end_time = test->vec.at(0).end_time;
    for(int i{1}; i < test->n; i++){
        if(test_end_time <= test->vec.at(i).start_time){
            w_count++;
            test_end_time = test->vec.at(i).end_time;
        }
    }
    return w_count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}


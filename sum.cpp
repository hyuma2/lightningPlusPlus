#include <iostream>
using namespace std;
int main(){
    int count, sum, in, setCount;
    cout << "Please enter how many numbers you'd like to sum." << endl;
    cin >> setCount;
    cout << "Please enter the numbers you'd like to sum." << endl;
    count = 0;
    sum = 0;
    while(count < setCount){
        cin >> in;
        sum += in;
        count++;
    }
    cout << "The average is \"" << sum / (count * 1.0) << "\"." << endl;
}
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    srand(time(0));
    cout << "Enter a number: " << endl;
    int i, h, t;
    cin >> h;
    t = 0;
    while(i != h){
        i = rand() % 100000000;
        cout << i << "\n";
        t++;
        }
    cout << "The program found " << h <<" in " << t << " attempts." << endl;
    return(0);
}
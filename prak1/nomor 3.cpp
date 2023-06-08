#include <iostream>

using namespace std;

int main() {
    int count = 10, *temp, sum = 7;
    temp = &count;
    *temp = 32;
    temp = &sum;
    *temp = count;
    sum = *temp * 4;
    cout << "count = " << count << ", *temp = " << *temp << ", sum = " << sum ;
    
    return 0;
}
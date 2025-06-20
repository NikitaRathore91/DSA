#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    string time;
    for (int i = 0; i < t; i++) {
        cin >> time;
        if ((time[0] - '0') * 10 + (time[1] - '0') >= 13) {
            if ((time[0] - '0') * 10 + (time[1] - '0') < 22) {
                cout << "0" << ((time[0] - '0') * 10 + (time[1] - '0') - 12) << time[2] << time[3] << time[4] << " PM" << endl;
            } else {
                cout << ((time[0] - '0') * 10 + (time[1] - '0') - 12) << time[2] << time[3] << time[4] << " PM" << endl;
            }
        } 
        else if (time == "00:00") {
            cout << "12:00 AM" << endl;
        } 
        
        else if (time == "00:59") {
            cout << "12:59 AM" << endl;
        }
        
         else if ((time[0] - '0') * 10 + (time[1] - '0') == 12) {
            cout << time << " PM" << endl;
        } 
        
        else {
            cout << time << " AM" << endl;
        }
    }
    return 0;
}
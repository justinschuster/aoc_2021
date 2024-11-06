#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    string myText;
    ifstream infile("/home/justin/projects/aoc_2021/day1/input.txt");

    if (!infile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
 
    int last = -1;
    int count = 0;
    while (getline (infile, myText)) {
        int curr = stoi(myText);
        if (last < curr && last != -1) {
            count++;
        }
        last = curr;
    }

    cout << count << endl;

    infile.close();
    return 0;
}

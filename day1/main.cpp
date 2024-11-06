#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void readFile(const char* filename, list<string>& lines) {
    lines.clear();
    ifstream file(filename);
    string s;
    while(getline(file, s))
        lines.push_back(s);
}

int main(void) {
    const char* filename = "/home/justin/projects/aoc_2021/day1/input.txt";
    list<string> lines;
    readFile(filename, lines);

    int last = -1;
    int count = 0;
    for (const auto& line : lines) {
        int curr = stoi(line);
        if (curr > last && last != -1) {
            count++;
        }
        last = curr;
    }

    cout << "Part One: " << count << endl;

    // Part Two
    count = 0;
    auto l_front = lines.begin();
    int total = 0;
    int curr_sum = 0;
    int last_sum = 0;
    while (total < lines.size()) {
        for (int i = 1; i < 5; i++) {
            advance(l_front, 1);
            curr_sum = curr_sum + stoi(*l_front);
        }
        total = total + 4;

        if (last_sum < curr_sum && last_sum != 0) {
            count++;
        }
        last_sum = curr_sum;
    }

    cout << count << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
using namespace std;

int main(int argc, char* argv[])
{
    string s = "";

    if (argc == 1) {
        cout << "Missing argument" << endl;
        return 0;
    }

    if (argc == 2) {
        s = string(argv[1]);
        if (s == "") {
            cout << "seach string is empty!" << endl;
            return 0;
        }
    }

    if (argc >= 3) {
        cout << "Too many arguments" << endl;
        return 0;
    }

    ifstream infile("data");
    string line;
    while(getline(infile, line))
    {
        if (line.rfind(s) != string::npos) {
            cout << line << endl;
            return 0;
        }
    }

    cout << "Not found" << endl;
    return 0;
}

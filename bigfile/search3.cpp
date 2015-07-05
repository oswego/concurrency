#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
using namespace std;

inline string int2str(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

void search(string datafile, string s)
{
    ifstream infile(datafile);
    string line;
    while(getline(infile, line))
    {
        if (line.rfind(s) != string::npos) {
            cout << line << endl;
            return;
        }
    }
}

int main(int argc, char* argv[])
{
    string datafile = "";
    string s = "";

    if (argc <= 2) {
        cout << "Missing arguments" << endl;
        return 0;
    }

    if (argc == 3) {
        datafile = string(argv[1]);
        s = string(argv[2]);
        if (datafile == "" || s == "") {
            cout << "datafile or seach string is empty!" << endl;
            return 0;
        }
    }

    if (argc >= 4) {
        cout << "Too many arguments" << endl;
        return 0;
    }

    thread t {search, datafile, s};
    t.join();

    return 0;
}

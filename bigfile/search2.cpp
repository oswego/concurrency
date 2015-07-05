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

void search(int index, string s)
{
    string datafile = "./splitted/data" + int2str(index);

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

    for (int i = 1; i <= 100; i++)
    {
        thread t {search, i, s};
        t.join();
    }

    return 0;
}

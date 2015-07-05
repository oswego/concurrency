#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
using namespace std;

template<typename T>
inline string convert2str(T input)
{
    stringstream ss;
    ss << input;
    return ss.str();
}

void split(string cmd)
{
    cout << cmd << endl;
    system(cmd.c_str());
}

int main()
{
    long long i = 1;
    int j = 1;
    while (i < 100000000)
    {
        // sed -n '1,+999999p' data > ./splitted/data1
        string cmd = "sed -n '";
        string start = convert2str<long long>(i++);
        cmd.append(start);
        cmd.append(",+999999p' data > ./splitted/data");
        string index = convert2str<int>(j++);
        cmd.append(index);

        thread t {split, cmd};
        t.join();

        i += 999999;
    }

    return 0;
}

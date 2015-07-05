#include <fstream>
using namespace std;

int main()
{
    ofstream ofs("data", ofstream::out);
    for (long long i = 1; i <= 100000000; ++i)
    {
        ofs << "data" << i << endl;
    }
    ofs.close();

    return 0;
}

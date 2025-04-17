#include <iostream>
using namespace std;

int main(void)
{
    int tests[10];
    int test;
    int num_elms;

    do {
    cout << "How many numbers? ";
    cin >> num_elms;
    }
    while (num_elms >= (sizeof(tests) / sizeof(tests[0])));
    for (int i = 0; i < num_elms; i++)
    {
        cout << "Please type a number: ";
        cin >> test;
        tests[i] = test;
    }
    return 0;
}

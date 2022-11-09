#include <iostream>
using namespace std;

void Init(int t[], const int size, int i)
{
    if (i < size)
    {
        t[i] = -20 + rand() % 58;
        Init(t, size, i + 1);
        return;
    }
}

void Print(int t[], const int size, int i)
{
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << t[i];
        if (i != size - 1)
            cout << ", ";
        else cout << "}" << endl;
        Print(t, size, i + 1);
        return;
    }
}

int SumElement(int t[], const int size, int i)
{
    if (i < size)
    {
        if (t[i] % 5 != 0 && t[i] < 0)
            return t[i] + SumElement(t, size, i + 1);
        else
            return SumElement(t, size, i + 1);
    }
    else return 0;
}

int CountElement(int t[], const int size, int i)
{
    if (i < size)
    {
        if (t[i] % 5 != 0 && t[i] < 0)
            return t[i] + CountElement(t, size, i + 1);
        else
            return CountElement(t, size, i + 1);
    }
    else return 0;
}

void ReplaceElement(int t[], const int size, int i)
{
    if (i < size)
    {
        if (t[i] % 5 != 0 && t[i] < 0)
            t[i] = 0;
        ReplaceElement(t, size, i + 1);
        return;
    }
}

int main()
{
    srand(time(0));

    const int size = 22;
    int t[size];

    Init(t, size, 0);
    Print(t, size, 0);
    cout << "Array sum by condition = " << SumElement(t, size, 0) << endl;
    cout << "Count element by condition = " << CountElement(t, size, 0) << endl;
    ReplaceElement(t, size, 0);
    Print(t, size, 0);

    return 0;
}

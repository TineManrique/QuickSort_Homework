#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int partition(int* input, int l, int r);
void QuickSort(int* input, int l, int r);

int main()
{
    int x = 0, size=10000;
    int number[10000];
    string line;
    fstream myfile;
    myfile.open("data10k.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        stringstream(line)>>number[x];
        x++;
    }

    QuickSort(number, 0, size);

    for(x = 0; x<10000; x++)
    {
        cout<<number[x]<<endl;
    }
    myfile.close();

    return 0;
}

void QuickSort(int* number, int l, int r)
{
    if ( l < r )
    {
        int j = partition(number, l, r);
        QuickSort(number, l, j-1);
        QuickSort(number, j+1, r);
    }
}
int partition(int* number, int l, int r)
{
    while ( l < r )
    {
        while ( number[l] < number[r] )
            l++;

        while ( number[r] > number[r] )
            r--;

        if ( number[l] == number[r] )
            l++;
        else if ( l < r )
        {
            int hold = number[l];
            number[l] = number[r];
            number[r] = hold;
        }
    }
    return r;
}

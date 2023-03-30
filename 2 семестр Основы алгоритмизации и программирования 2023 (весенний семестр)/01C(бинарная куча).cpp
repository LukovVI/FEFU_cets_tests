#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class BinHeap
{
private:

    long long link[100000];
    long long size;
    long long deep;

    void rebalansup(BinHeap & heap, long long lin)
    {
        long long compared = link[lin];
        lin = compared + 1;
        long long comdeep = 0;
        long long swap;

        while (lin > 1)
        {
            comdeep++;
            lin = lin / 2;
        }
        long long swid = (compared-1)/2;
        while (comdeep > 0 && list[compared][0] > list[swid][0])
        {
            swap = list[compared][0];
            list[compared][0] = list[swid][0];
            list[swid][0] = swap;
            swap = list[compared][1];
            list[compared][1] = list[swid][1];
            list[swid][1] = swap;
            link[list[swid][1]] = swid;
            link[list[compared][1]] = compared;
            compared = swid;
            comdeep--;
            swid = (compared - 1) / 2;
        }
    }
    void rebalansdown(BinHeap & heap, int lin)
    {
        long long compared = link[lin];
        long long swap, swid;
        bool chek = false;


        while (compared * 2 + 1 < size)
        {   
            chek = false;
            if (list[compared][0] < list[compared * 2 + 1][0])
            {
                swid = compared * 2 + 1;
                chek = true;
            }
            if (compared * 2 + 2 < size && list[compared][0] < list[compared * 2 + 2][0] && list[compared * 2 + 1][0] < list[compared * 2 + 2][0])
            {
                swid = compared * 2 + 2;
                chek = true;
            }
            if(!chek) break;

            swap = list[compared][0];
            list[compared][0] = list[swid][0];
            list[swid][0] = swap;
            swap = list[compared][1];
            list[compared][1] = list[swid][1];
            list[swid][1] = swap;
            link[list[swid][1]] = swid;
            link[list[compared][1]] = compared;
            compared = swid;

        }
    }

public:
    long long list[100000][2];
    BinHeap() : size(0), deep(0)
    {}
    void append(long long elem)
    {
        list[size][0] = elem;
        list[size][1] = size;
        link[size] = size;
        size++;
        long long s = size;
        deep = 0;
        while (s > 1)
        {
            deep++;
            s = s / 2;
        }
        rebalansup(*this, size - 1);
    }
    void add(int lin, int change)
    {
        list[link[lin]][0] += change;
        if (change > 0) rebalansup(*this, lin);
        else rebalansdown(*this, lin);
    }

};

int main()
{
    long long n, m, l, num, change;

    ifstream ifs("input.txt");
    ofstream ofs("output.txt");

    ifs >> n >> m;

    BinHeap list;

    for (int i = 0; i < n; i++)
    {
        ifs >> change;
        list.append(change);
    }

    for (int i = 0; i < m; i++)
    {
        ifs >> num >> change;
        num--;
        list.add(num, change);
        ofs << list.list[0][0] << endl;
    }

    return 0;
}


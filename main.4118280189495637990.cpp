//                                                              
//                         

//                    
//                      

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

vector<int> heap =
{
15,40,42,-15,30,35,5
};

void build_heap()
{
    for (int i; i<7; i++)
        {cout << heap[i];
        cout << '\t';}
        cout << endl;

}

bool swap(int& a,int& b)
{
    assert (true);
    int c;
    c = b;
    b = a;
    a = c;

    return true;

}

void push_up()
{
     for (int i = 0; i<7; i++)
            {
            if(heap[i]<heap[2*i+1]&&2*i+1<7)
            swap(heap[i],heap[2*i+1]);
            if(heap[i]<heap[2*i+2]&&2*i+2<7)
            swap(heap[i],heap[2*i+2]);
            }
            cout << "phase 1:   ";
            build_heap();
}

void push_down()
{
    for (int q = 0; q<7; q++)
    {
        for (int r=0; r<7; r++)
        {
            if (heap[r]>heap[r+1]&&r+1<7)
                swap(heap[r],heap[r+1]);
        }
    }
    cout << "phase 2:   ";
    build_heap();
}

//                

int main()
{
cout << "original:    ";
build_heap();

push_up();

push_down();

}


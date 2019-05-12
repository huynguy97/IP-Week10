#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> Data = {15, 40, 42, -15, 30, 35, 5};

void print_tree()
{
assert(Data.size() <= 6);
//                                             
    cout << "\t\t";
    for(int i = 0; i < Data.size(); i++)
    {
        if(i == 1 || i == 2 || i == 5)
            cout << "\t";
        cout << Data[i] << "\t";
        if(i == 0 || i == 2 || i == 6)
        {
            cout << endl;
        }
    }
}

void swap_number(int a, int b)
{
assert(true);
//                                                      
    int placeholder = 0;
    placeholder = Data[a];
    Data[a] = Data[b];
    Data[b] = placeholder;
}

void push_up(int a)
{
assert(a < Data.size() && a >= 0);
//                                                                                                             
    if(Data[(a-1)/2] < Data[a])
    {
        swap_number((a-1)/2,a);
        //             
    }
}
void build_heap(int size)
{
assert(size < Data.size() && size >= 0);
//                                          
    for(int i=0; i < size; i++)
    {
        push_up(i);
        for(int j = i; j > 0; j = (j-1)/2)
        {
            push_up(j);
        }
    }
}
void swap(int size)
{
assert(size < Data.size() && size >= 0);
//                                                              
    swap_number(0,size);
}

void push_down(int size)
{
assert(size < Data.size() && size >= 0);
//                                                                                                                 
    int j;
    for(int i=0; Data[i] < Data[2*i+1] || Data[i] < Data[2*i+2]; i = 2*i+j)
    {
        if(Data[i] < Data[2*i+1] && Data[2*i+1] > Data[2*i+2] && 2*i+1 <= size)
        {
            swap_number(i,2*i+1);
            j=1;
        }
        else if(Data[i] < Data[2*i+2] && 2*i+2 <= size)
        {
            swap_number(i,2*i+2);
            j=2;
        }
        else
        {
            return;
        }
    }
}

void pick_heap()
{
assert(Data.size() != 0);
//                                                                                                                        
    for(int i = 1; i < Data.size(); i++)
    {
        swap(Data.size()-i);
        push_down(Data.size()-i-1);
    }
}

int main()
{
    build_heap(Data.size()-1);
    pick_heap();
    for(int out = 0; out < Data.size() - 1; out++)
    {
        cout << Data[out] << ", ";
    }
    cout << Data[Data.size()-1];
    return 0;
}
/*                                                               */

/*
 
  
                                                                      
                                                  

  
                                                                          
                                                                          

 
  
          
              
                 

          
              
                 

          
              
                 

  
                                     
                                     
                                                               
                                     
                                      
                                      

                                                                                    

                                                                          
*/


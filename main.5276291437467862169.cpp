//                                     

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void swapEl (vector<int>& heap, int& i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    i = j;
}
//                                   

void push_up(vector<int>& heap, int pos)
{
    while (heap[pos] > heap[(pos-1)/2])
    {
        swapEl(heap, pos, (pos-1)/2);
        if (pos == 0)
            break;
    }
}
//                                                                       

void build_heap(vector<int>& heap)
{
    for (int i=1; i<heap.size(); i++)
        push_up(heap, i);
}
//                                                       

void push_down(vector<int>& heap, int l)
{
    int pos = 0;
    if (l > 2)
        while (heap[pos] < heap[2*pos+1] || heap[pos] < heap[2*pos+2])
        {
            if (heap[2*pos+1] > heap[2*pos+2])
                swapEl(heap, pos, 2*pos+1);
            else
                swapEl(heap, pos, 2*pos+2);
            if (pos*2+1 >= l)
                break;
            if (pos*2+2 >= l)
            {
                if (heap[pos] < heap[2*pos+1])
                    swapEl(heap, pos, 2*pos+1);
                break;
            }
        }
    else if (l == 2)
        if (heap[pos] < heap[1])
            swapEl(heap, pos, pos+1);
}
//                                                                                  

void pick_heap(vector<int>& heap)
{
    int pos;
    for (int i=heap.size()-1; i>0; i--)
    {
        pos = i;
        swapEl(heap, pos, 0);
        push_down(heap, i);
    }
}
//                                                       

void heap_sort(vector<int>& heap)
{
    build_heap(heap);
    pick_heap(heap);
}
//                                                         

int main()
{
    vector<int> x{15, 40, 42, -15, 30, 35, 5};
    heap_sort(x);
    for (int i=0; i<x.size(); i++)
        cout << x[i] << "\t";
}

/*
  

    
  
  

    
     
      

          
            
              
    
    

          
            
              
       
        

          
            
              
            
            

           
            
              
               
                

                    
                    
                    
                    
                    
                    
*/


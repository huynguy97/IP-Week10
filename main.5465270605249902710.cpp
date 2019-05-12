#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//                       

/*
                                                                                                                                                                       
                                         
                                                                                                                                                                                           
                                              
*/

/*                             */

void swap (int& a, int& b)
{
//                
    assert(true);
/*                 
                                     
*/
    const int HELP = b;
    b = a;
    a = HELP;
}

int size (vector<int>& v)
{
    return static_cast<int> (v.size());
}

void push_up (vector<int>& heap, int c)
{
//                
    assert(c < size(heap) && 0 <= c);
/*                 
                                                                                                                
*/
    while (heap[c] > heap[(c-1)/2])
    {
        swap (heap[c], heap[(c-1)/2]);
        c = (c-1)/2;
    }
}

void build_heap(vector<int>& heap)
{
//              
assert(size(heap) > 0);
/*               
                           
*/
    for(int i = 1; i < size(heap); i++)
    {
        push_up(heap, i);
    }
}

void push_down (vector<int>& heap, int i)
{
//                
    assert(i < size(heap) && 0 <= i);
/*                 
                                                                                                         
*/
    int p = 0;
    while (2*p+2 < i)
    {
        if (heap[2*p+1] >= heap[2*p+2])
        {
            if (heap[p] < heap[2*p+1])
            {
                swap(heap[p], heap[2*p+1]);
                p = 2*p+1;
            }
        }
        else
        {
            if (heap[p] < heap[2*p+2])
            {
                swap(heap[p], heap[2*p+2]);
                p = 2*p+2;
            }
        }
    }
    if (2*p+1 < i)
    {
        if (heap[p] < heap[2*p+1])
        {
            swap(heap[p], heap[2*p+1]);
            p = 2*p+1;
        }
    }
}

void pick_heap(vector<int>& heap)
{
//                 
    assert (true);
/*                  
                                                
*/
    for (int i = size(heap) - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        push_down(heap, i);
    }
}

/*
     
        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

     
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
*/

/*         
                                                                                                                                                                                       
                              

                                                                                                                

                                                                                                                                                                                  
                              

                                                                                                               

                                                                                                                                                              
*/

int main()
{
    vector<int> heap;
    heap.push_back(15);
    heap.push_back(40);
    heap.push_back(42);
    heap.push_back(-15);
    heap.push_back(30);
    heap.push_back(35);
    heap.push_back(5);
    build_heap(heap);
    pick_heap(heap);
    for (int i = 0; i < size(heap); i++)
    {
        cout << heap[i] << endl;
    }
    return 0;
}


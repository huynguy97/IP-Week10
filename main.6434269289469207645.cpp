#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
//                       
using namespace std;
void push_up (int& a, int& b)
{
    assert(true);
    /*              
                                 
    */
    const int temp = a;
    a = b;
    b = temp;
}
void build_heap(vector<int>& heap)
{
    assert(true);
    /*              
                    
    */
    for (int i = 1; i < heap.size(); i++)
    {
        while(heap[i] > heap[(i-1)/2] && i != 0)
        {
            push_up(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
}

void swapping(int& a, int& b)
{
    assert(true);
    /*              
                                 
    */
    const int temp = a;
    a = b;
    b = temp;
}

void push_down(vector<int>& heap, int border)
{
    assert(true);
    /*              
                                                                  
                                                                      
    */
    int i = 0;
    while((heap[i] < heap[2*i+1] || heap[i] < heap[2*i+2]) && 2*i+2 < border)
    {
        if (heap[2*i+1] >= heap[2*i+2])
        {
            const int temp = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = temp;
            i = 2*i+1;
        }
        else
        {
            const int temp = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = temp;
            i = 2*i+2;
        }
    }
}

void pick_heap(vector<int>& heap)
{
    assert(true);
    /*              
                                                                       
    */
    int i = 0;
    while(heap[0] > heap[1])
    {
        swapping(heap[0], heap[heap.size()-1-i]);
        push_down(heap, heap.size()-1-i);
        i++;;
    }
}

int main()
{
    assert(true);
    /*              
                                                                                       
    */
    vector<int> heap = {15,40,42,-15,30,5};
    cout << "Starting array:\t\t{";
    for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if(!(i == heap.size()-1))
            {
                cout << ",";
            }
        }
    cout << "}\n";
    build_heap(heap);
    cout << "After build_heap:\t{";
    for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if(!(i == heap.size()-1))
            {
                cout << ",";
            }
        }
    cout << "}\n";
    pick_heap(heap);
    cout << "Final array:\t\t{";
    for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if(!(i == heap.size()-1))
            {
                cout << ",";
            }
        }
    cout << "}";
    return 0;
}
/*                    
       
                                                                        
                                                                             

                                                                        
                                                                               
                               

       
  
        
       
       
          
           
          
         

       
       
          
           
          
         

       
       
          
           
          
         

        
       
                   
       
                   
       
                   
       
                   
       
                   

  
                                                                                          
                                                                           
                                                                                                             
                                                                                                       
                                          
                                                                                                          
                                                                                                                
                     */


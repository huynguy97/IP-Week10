#include <iostream>
#include <vector>
#include <cassert>

//                                              

using namespace std;

void print_heap(vector<int>& heap)
{
    assert(heap.size() >= 0);

    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << ' ';
    }
    cout << endl;
}

void swap_heap(vector<int>& heap, int i, int j)
{
    assert(i >= 0 && i < heap.size() &&
           j >= 0 && j < heap.size());

    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

bool push_up(vector<int>& heap, int& i)
{
    assert(i >= 0 && i < heap.size());

    int parent = (i-1)/2;
    if (heap[i] > heap[parent]) {
        swap_heap(heap, i, parent);
        i = parent;
        return true;
    }
    return false;
}

void build_heap(vector<int>& heap)
{
    assert(heap.size() >= 0);

    bool changed;
    for (int i = 0; i < heap.size(); i++) {
        do {
            changed = push_up(heap, i);
        } while (changed);
    }
}

bool push_down(vector<int>& heap, int heapsize)
{
    assert(heap.size() >= 0 &&
           heapsize >= 0 && heapsize <= heap.size());

    int i = 0;
    while (i < heapsize) {
        int child = i;
        if (2*i+1 < heapsize) {
            if (heap[i] < heap[2*i+1])
                child = 2*i+1;
            if (2*i+2 < heapsize && heap[child] < heap[2*i+2])
                child = 2*i+2;
            if (i != child) {
                swap_heap(heap, i, child);
                i = child;
            }
            else
                return false;
        } else
            return false;
    }
}

void pick_heap(vector<int>& heap)
{
    assert(heap.size() >= 0);

    for (int i = heap.size()-1; i > 0; i--) {
        swap_heap(heap, 0, i);
        push_down(heap, i);
    }
}

int main()
{
    vector<int> heap = {15, 40, 42, -15, 30, 35, 5};
    build_heap(heap);
    print_heap(heap);
    pick_heap(heap);
    print_heap(heap);
    return -1;
}

/*
           
          
                                                                         
                                                    
          
                                                                        
                                         

           
                   
                      
                       
                         
                          
                           

                      
                       
                         
                          
                           

                      
                       
                         
                          
                           

                      
                       
                         
                          
                           

                     
                                            
                                            
                                            
                                            
                                            
                                            
          
                             
                                  
                                  
                                     

*/


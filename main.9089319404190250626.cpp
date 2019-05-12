#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;
/*
                                  
                                  
  
 */

/*       
                                                                                                                                                   
                                                                                                                           
*/

/*        
           
                               
  
                      
                       
                         
                          
                          
  
                      
                       
                         
                          
                          
  
                      
                       
                         
                          
                          
  
           
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
  
  
                                                       
                                                                     
                                   
                                                                                                         
            
*/

void push_up(vector<int>& heap, int i)
{
    //              
    assert(heap.size()>0 && i>=0 && i <= heap.size());
    //               
    //                                                  
    int help = heap[i];
    if( (i-1)/2 < heap.size()-1 && i < heap.size()-1 && i > 0)
    {
        if(heap[i] > heap[(i-1)/2])
        {
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = help;
        }
    }
}

void build_heap(vector<int>& heap)
{
    //              
    assert(heap.size()>0);
    //               
    //                                                                                                                
    for(int i = heap.size(); i > 0; i--)
        push_up(heap, i);
}

void show_vector(vector<int>& vec)
{
    //              
    assert(vec.size()>0);
    //               
    //                                    
    for(int i =0; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << endl;
}

void swap(vector<int>& heap, int i , int parent)
{
    //              
    assert(heap.size()>0 && i>=0 && i<=heap.size() && parent>=0 && parent<=heap.size());
    //               
    //                                    
    int help = heap[parent];
    heap[parent] = heap[i];
    heap[i] = help;
}

void push_down(vector<int>& heap, int bound)
{
    //              
    assert(heap.size()>0 && bound>=0 && bound<=heap.size());

    //               
    //                                                                                                                                           
    int largest_child;
    int index = 0;
    int parent = 0;
    bool is_heap = false;
    while(!is_heap && (heap[parent] < heap [(2*parent)+1] || heap[parent] < heap[(2*parent)+2]))
    {
        if((2*parent)+1 < bound && (2*parent)+2 < bound)
        {
            if(heap[(2*parent)+1] > heap[(2*parent)+2])
            {
                index = (2*parent)+1;

            }
            else
            {
                index = (2*parent)+2;
            }
            largest_child = heap[index];
            if(largest_child > heap[parent])
            {
                swap(heap, index , parent);
                parent = index;
            }
            else
                is_heap = true;
        }
        else
            is_heap = true;

    }

}

void pick_heap(vector<int>& heap)
{
    //              
    assert(heap.size()>0);
    //               
    //             
    for(int i =heap.size(); i > 2 ; i--)
    {
        show_vector(heap);
        swap(heap, i-1, 0);
        push_down(heap, i-1 );
    }
}

void heap_sort(vector<int>& heap)
{
    //              
    assert(heap.size()>0);
    //               
    //               
    build_heap(heap);
    pick_heap(heap);
}

int main() {

    vector<int> heap = {15, 40, 42, -15, 30, 35, 5};
    show_vector(heap);
//                     
//
//                      
//                 
//                    
//                          
//                    
//                      

    heap_sort (heap);
    show_vector(heap);

    return 0;
}

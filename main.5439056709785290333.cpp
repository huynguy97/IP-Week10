//                                              
//                                               
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

/*
                                                                             
                                                      

                                                                                  
                                                                              

*/

/*
             
          
           
             
              
               

          
           
             
              
               

          
           
             
              
               

          
           
             
              
               

          
           
             
              
               

        
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      

  
                                                                         
                    
                                                              
                                                                              
                      
                                                     

                                                                    
*/

//                          

void push_up(vector<int>& heap, int position)
{//             
    assert((unsigned)position<=heap.size());
    //                                                                        
    while(heap[position]>heap[(position-1)/2])
    {
        swap(heap[position], heap[(position-1)/2]);
        position = (position-1)/2;
    }
}

void build_heap(vector<int>& heap)
{//             
    assert(true);
//                                                                                        

    for (int i=1;(unsigned)i<heap.size();i++)
    {
        push_up(heap, i);
    }
}

void swap(vector<int>& heap, int unsorted)
{
    //             
    assert((unsigned)unsorted<heap.size());
    //                                                                                 
    //            
    if (heap[0]>heap[unsorted])
        swap(heap[0], heap[unsorted]);
}

void push_down(vector<int>& heap, int unsorted)
{
    //             
    assert((unsigned)unsorted<heap.size());
    //                                                                                       
    //                                                                            
    //                                                                                       
    int position=0;

    while (position*2+2<unsorted && heap[position]<max(heap[2*position+1], heap[2*position+2]))
    {
        int newposition;
        if (heap[position*2+2]>heap[position*2+1])
            newposition = position*2+2;
        else
            newposition = position*2+1;

        swap(heap[position], heap[newposition]);
        position = newposition;
    }

    if (position*2+1<unsorted && heap[position*2+1]>heap[position])
    {
        swap(heap[position], heap[position*2+1]);
        position = position*2+1;
    }
}

void pick_heap(vector<int>& heap)
{
    //              
    assert(true);
    //                                                                               
    //                                                                                        

    for(int unsorted = heap.size()-1; unsorted>0; unsorted--)
    {
        swap(heap, unsorted);
        push_down(heap, unsorted-1);
    }
}

int main()
{
    vector<int> heap = {15, 40, 42, -15, 30, 35, 5} ;
    build_heap(heap);
    pick_heap(heap);

    for (int i=0;(unsigned)i<heap.size();i++)
    {
        cout << heap[i] << "  ";
    }
}


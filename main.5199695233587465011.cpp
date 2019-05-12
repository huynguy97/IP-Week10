//                                                 
//                                            

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//              
//                                                                          
//                                                                         
//                                                                       
//                                                     
//
//                                                                          
//                                                                        
//                                                                   
//                                                                          
//                                                                       
//                                                                    
//                                                                        
//                                                                      
//                          

//              
//            
//            
//                                                     
//                                                                                                      
//                                                                                                      
//                                                                                                       
//                                                                                                        
//                                                                                                         
//                                                                                                          
//                                                                                                          
//                                                                                                           
//                                                                                                            
//
//                                                                          
//                                                                          
//                                                                           
//                                                                            
//                                                                             
//                                                                              
//                                                                              
//                                                                               
//                                                                                
//
//            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//                                            
//
//            
//                                                                     
//                                                          
//                                                                                                               
//                                                                                                              
//                                                         
//                                                             
//                                                                                                             
//                                                                                          
//                                                            
//                                                                                                               
//                                                                                                              
//                                                         
//                                                            
//                                                                                                               
//                                                                                          
//                                                                         
//                                                                                                              
//                                                                                         

//              
//                                                   
void push_up(vector<int>& heap, int i)
{
    //             
    assert(i >= 0 && i <= heap.size());
    //              
    //                                                                                  
    //                                                            

    while (heap[i] > heap[(i-1)/2])
    {
        const int HEAP = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = HEAP;
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& heap)
{
    //             
    assert(true);
    //              
    //                                                                          
    //                                

    for (int i = 0; i < heap.size(); i++)
        push_up(heap, i);
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << ' ';
    cout << endl;
}

void swap(vector<int>& heap, int i)
{
    //             
    assert(i <= heap.size());
    //              
    //                                                                                                       

    const int SWAP = heap[0];
    heap[0] = heap[i];
    heap[i] = SWAP;
}

void push_down(vector<int>& heap, int i, int heapsize)
{
    //             
    assert(i >= 0 && i <= heap.size());
    //              
    //                                                                                   
    //                                                                           

    while ((2*i+1 < heapsize && heap[i] < heap[2*i+1]) || (2*i+2 < heapsize && heap[i] < heap[2*i+2]))
    {

        if (2*i+2 < heapsize && heap[i] < heap[2*i+1] && heap[i] < heap[2*i+2])
        {
            if (heap[2*i+1] >= heap [2*i+2])
            {
                const int LEFTCHILD = heap[i];
                heap[i] = heap[2*i+1];
                heap[2*i+1] = LEFTCHILD;
                i = 2*i+1;
            }
            else
            {
                const int RIGHTCHILD = heap[i];
                heap[i] = heap[2*i+2];
                heap[2*i+2] = RIGHTCHILD;
                i = 2*i+2;
            }
        }

        else if (heap[i] < heap[2*i+1] && (!(heap[i] < heap[2*i+2]) || (2*i+2 >= heapsize)))
        {
            const int LEFTCHILD = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = LEFTCHILD;
            i = 2*i+1;
        }

        else if (heap[i] < heap[2*i+2] && (!(heap[i] < heap[2*i+1]) || (2*i+1 >= heapsize)))
        {
            const int RIGHTCHILD = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = RIGHTCHILD;
            i = 2*i+2;
        }
    }
}

void pick_heap(vector<int>& heap)
{
    //             
    assert(true);
    //              
    //                                                                       

    int n = 0;

    while (heap.size()-n > 0)
    {
        swap(heap, heap.size()-1-n);
        n++;
        push_down(heap, 0, heap.size()-n);

        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << ' ';
        cout << endl;
    }
}

int main()
{
    vector<int> heap = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
    cout << "HEAP SORT WITH VECTOR {2, 14, 30, 29, 42, 30, 11, -5, 0, 51}" << endl;
    cout << "\nPhase 1:\n" << endl;
    build_heap(heap);
    cout << "\nPhase 2:\n" << endl;
    pick_heap(heap);
    return 0;
}


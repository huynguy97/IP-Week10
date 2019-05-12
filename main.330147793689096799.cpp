#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
                          
                         
*/

/*
       
                                                                                                     
                                                                         
*/

/*
       
        
            
               
                
                  
                   
                    

               
                
                  
                   
                    

               
                
                  
                  
                   
               
                
                  
                  
                   
            
                              
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                              
        
                                                            
                                                                                                       
                                                   
                                                  
                                                                                                      
                                                                
*/

vector<int> sortvec = {471, 341, 461, 238, 65, 90, 414, 261, 105, 206, 251, 445, 62, 172, 299, 456, 207, 98, 99, 432, 367, 290, 435, 204, 160,
                       470, 18, 342, 182, 53, 305, 448, 237, 169, 136, 180, 360, 28, 121, 138, 154, 468, 188, 228, 287, 193, 269, 85, 106, 205,
                       370, 94, 379, 495, 45, 50, 6, 257, 210, 364};

int int_vector_size(vector<int>& vec)
{
    //              
    assert(true);
    //               
    //                                                            
    return static_cast<int>(vec.size());
}

int pos_maximum(int a, int b)
{
    //              
    assert(true);
    //               
    //                                                                                  
    if(a>b)
        return 1;
    return 2;
}

bool push_up(vector<int>& heap, int length)
{
    //              
    assert(length >= 0);
    //               
    //                                                                                                   
    for(int i = 1; i < length; i++)
    {
        if(heap[i] > heap[(i-1)/2])
        {
            int temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
            return true;
        }
    }
    return false;
}

void build_heap(vector<int>& sortvec, int length)
{
    //              
    assert(length >= 0);
    //               
    //                                                                                                    
    while(push_up(sortvec, length));
}

void swap(vector<int>& sortvec, int& length)
{
    //              
    assert(length >= 0);
    //               
    //                                                                                             
    //                   
    int temp = sortvec[0];
    sortvec[0] = sortvec[length-1];
    sortvec[length-1] = temp;
    length--;
}

void push_down(vector<int>& heap, int length)
{
    //              
    assert(length >= 0);
    //               
    //                                                                                                  
    //                                                                                            
    int i = 0;
    while((2*i+2) < length && (heap[i] < heap[2*i+1] || heap[i] < heap[2*i+2]))
    {
        int max = pos_maximum(heap[2*i+1], heap[2*i+2]);
        int temp = heap[i];
        heap[i] = heap[2*i+max];
        heap[2*i+max] = temp;
        i = 2*i+max;
    }
}

void pick_heap(vector<int>& heap, int length)
{
    //              
    assert(length >= 0);
    //               
    //                                                      
    while(length > 0)
    {
        swap(heap, length);
        push_down(heap, length);
    }
}

int main()
{
    int length = int_vector_size(sortvec);
    build_heap(sortvec, length);
    pick_heap(sortvec, length);
    for(int i = 0; i < length-1; i++)
        cout << sortvec[i] << ',';
    cout << sortvec[length-1];
}


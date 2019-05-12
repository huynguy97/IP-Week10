#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

/*
                            
                       

        
       
                                                                                              
       
                                                                                                                                               

       
                
                            
              
              
                  
                  
                   

                            
              
              
                  
                  
                   

                            
              
              
                  
                  
                   

                            
              
              
                  
                  
                   

                
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

       

       
*/

vector<int> heap {15, 40, 42, -15, 30, 35, 5, 2, 45, 5322};
vector<int> phase_2 (heap.size());

void swap (vector<int>& vec_heap, int i, int j)
{
    //               
    assert(i >= 0 && j >= 0 && i < vec_heap.size() && j < vec_heap.size());
    //                
    //                                      
    const int aids = vec_heap[i];
    vec_heap[i] = vec_heap[j];
    vec_heap[j] = aids;
}

void push_up (vector<int>& output, int i)
{
    //               
    assert(i >= 0 && i < output.size());
    //                
    //                                                                                           
    int j = (i-1)/2;
    if (output[j] < output[i])
    {
        swap (output, j, i);
    }
}

void push_down (vector<int>& heap, int i)
{
    //               
    assert(i >= 0 && i < heap.size());
    //                
    //                                                                                                                                                           

    cout << "push_down" << endl;
    for (int k=0; k < heap.size(); k++)
    {
        cout << heap[k] << ' ';
    }
    cout << endl;
    int count;
    while(count != 0)
    {
        count = 0;
        cout << (2*i+1 < phase_2.size()-1) << " " << (heap[2*i+1] >= heap[2*i+2] || 2*i+2 > heap.size()-1) << " " << (heap[i] < heap[2*i+1]);
            if (2*i+1 < phase_2.size()-1 && (heap[2*i+1] >= heap[2*i+2] || (2*i+2) > heap.size()-1) && heap[i] < heap[2*i+1])
        {
            swap(heap, 2*i+1, i);
            i = 2*i+1;
            cout << "Swap 1" << endl;
            count++;
        }
        if(2*i+2 < phase_2.size()-1 && heap[i] < heap[2*i+2])
        {
            swap(heap, 2*i+2, i);
            i = 2*i+2;
            cout << "Swap 2" << endl;
            count++;
        }
        for (int k=0; k < heap.size(); k++)
    {
        cout << heap[k] << ' ';
    }
    cout << endl;
    }

}

void pick_heap (vector<int>& heap, vector<int>& phase_2)
{
    //               
    assert(true);
    //                
    //                  

    for(int i = 0; i< heap.size(); i++)
    {
        swap(heap, 0, heap.size()-1);
        phase_2[heap.size()-1] = heap[heap.size()-1];
        heap.pop_back();

        for(int j = 0; j< heap.size(); j++)
        {
            cout << "help";
            push_down(heap, 0);
        }
    }

    for (int k=0; k < phase_2.size(); k++)
    {
        cout << phase_2[k] << ' ';
    }
}

void build_heap (vector<int>& output)
{
    //               
    assert(true);
    //                
    //                                                
    for (int i = 1; i < output.size(); i++)
    {
        push_up(output, i);
    }

    /*
                                         
     
                                 
     
    */
}

int main()
{
    vector<int> vec_heap = heap;

    /*
                         
                                           
     
                                   
     
    */

    build_heap(vec_heap);
    pick_heap(vec_heap, phase_2);
}


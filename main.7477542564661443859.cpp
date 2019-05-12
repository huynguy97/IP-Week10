#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

//                                  
//                                  

/*
       
                                                    
                                                                                        

       
     
                      
                       
                         
                            
                         

                      
                       
                         
                            
                         

                      
                       
                         
                            
                         

                      
                       
                         
                            
                         

   
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  

  
                                               
                                                                  
                                                 
          
*/

void show_vector (vector<int>& heap)
{
    //              
    assert(true);
    //                                    
    for (int i =0; i < heap.size(); i++)
    {
        cout << heap[i]<< "\t";
    }
    cout << endl;
}

bool push_up(vector<int>& heap, int i)
{
    //              
    assert(true);
    //                                                                                                   

    int parent = heap[(i-1)/2];
    int child = heap[i];
    if (child > parent)
    {
        heap[(i-1)/2] = child;
        heap[i] = parent;
        return true;
    }
    return false;
}
int can_push_down(vector<int>& heap, int i)
{
    //              
    assert(true);
    //                                                                              
    int parent = heap[i];
    int child_1 = heap[2*i+1];
    int child_2 = heap[2*i+2];
    if (2*i+1 >= heap.size() && 2*i+2 >= heap.size())
        return -1;
    if (2*i+1 >= heap.size())
        return 2*i+2;
    if (2*i+2 >= heap.size())
        return 2*i+1;
    if (child_1 > parent || child_2 > parent)
    {
        if (child_2 > child_1)
            return 2*i+2;
        else
            return 2*i+1;
    }
    return -1;
}

void push_down(vector<int>& heap, int i, int index)
{
    //              
    assert(true);
    //                                                

    int parent = heap[i];
    if (2*i+1 < heap.size() - index && 2*i+2 < heap.size() - index)
    {
        int child_1 = heap[2*i+1];
        int child_2 = heap[2*i+2];
        if (child_1 > parent || child_2 > parent)
        {
            if (child_2 > child_1)
            {
                heap[i] = child_2;
                heap[2 * i + 2] = parent;
            }
            else
            {
                heap[i] = child_1;
                heap[2 * i + 1] = parent;
            }
        }
    }
    if (2*i+1 < heap.size() - index && 2*i+2 >= heap.size() - index)
    {
        if (heap[2*i+1] > parent)
        {
            heap[i] = heap[2*i+1];
            heap[2 * i + 1] = parent;
        }
    }
}

void swap(vector<int>& heap, int index)
{
    //              
    assert(true);
    //               

    int swp = heap[0];
    heap[0] = heap[heap.size() - index];
    heap[heap.size() - index] = swp;
}

void build_heap(vector<int>& heap)
{
    //              
    assert(true);
    //               

    for (int i = 0; i < heap.size(); i++)
    {
        while (push_up(heap, i))
        {
            int q = (i-1)/2;
            push_up(heap,q);
        }
    }
    push_up(heap,1);
}

void pick_heap(vector<int>& heap)
{
    //              
    assert(true);
    //               
    //

    int big = 0;
    int index = 1;
    swap(heap, index);
    while (can_push_down(heap, 0) != -1 && index < heap.size())
    {
        while (can_push_down(heap, big) != -1)
        {
            int swp = can_push_down(heap, big);
            push_down(heap, big, index);
            big = swp;
        }
        index++;
        swap(heap, index);
        big = 0;
    }
}

int main()
{
    //              
    assert(true);
    //               
    //                                              
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "How many integers do you want to sort?" << endl;
    cin >> a;
    vector<int> heap;
    for(b; b< a; b++)
    {
        cout << "Type an integer:" << "\t";
        cin >> c;
        heap.push_back(c);
    }
    cout << endl;
    show_vector(heap);
    build_heap(heap);
    show_vector(heap);
    pick_heap(heap);
    show_vector(heap);
}


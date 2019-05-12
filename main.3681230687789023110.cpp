#include <iostream>
#include <cassert>
#include <vector>
//                      
//                  
using namespace std;

/*
           
                                         
                                                          
                                                                                                                      

           
        
      
             
               
                 
                  
                   
      
             
               
                 
                  
                   
      
             
               
                 
                  
                   
      
             
               
                 
                  
                   

        

                            
     
                               
         
                               
         
                               
     
                                   
          
                                   
     
                                       
     
                                           
     
                                               
          
                                

                     
                                 
          
          
*/

void show_vector(vector<int>& heap_array)
{
    for(int i = 0; i < heap_array.size(); i++)
        cout << heap_array[i] << " ";
}
int parent_int(int child)
{ //                            
    if(child%2 == 0)
        return child/2 -1;
    else
        return (child - 1)/2;
    //                                                  
}

void push_up(vector<int>& heap_array, int child)
{ //   
    assert(child < heap_array.size());
    while(heap_array[child] > heap_array[parent_int(child)])
    {
        int help = heap_array[child];
        heap_array[child] = heap_array[parent_int(child)];
        heap_array[parent_int(child)] = help;
        child = parent_int(child);
    }
}
void build_heap(vector<int>& heap_array, int child)
{
    for(int i = 0; i < heap_array.size(); i++)
        push_up(heap_array, child);
}

int largest_child(vector<int>& heap_array, int parent, int int_max)
{
    int child_1 = 2*parent + 1;
    int child_2 = 2*parent + 2;
    if((heap_array[child_1] > heap_array[parent]) && child_1  < int_max ||
       ((heap_array[child_2] > heap_array[parent]) && child_2  < int_max))
    {
        if((heap_array[child_2] > heap_array[child_1]) && child_2 < int_max)
            return 2;
        return 1;
    }
    return 0;
}
void push_down(vector<int>& heap_array, int parent, int int_max)
{
    while(largest_child(heap_array, parent, int_max ) != 0)
    {
        int larg_child = largest_child(heap_array, parent, int_max);
        int help = heap_array[parent];
        heap_array[parent] = heap_array[2* parent + larg_child];
        heap_array[2* parent + larg_child] = help;
        parent = 2*parent + larg_child;

    }
}
void swapping(vector<int>& heap_array, int index)
{
    int help = heap_array[0];
    heap_array[0] =  heap_array[index];
    heap_array[index] = help;
}
void pick_heap(vector<int>& heap_array)
{
    int index = heap_array.size() -1;
    int int_max = (heap_array.size());
    while(index > 0)
    {
    swapping(heap_array, index);
    push_down(heap_array, 0, index);
    index--;
    }
}
vector<int> heap_array = {2,14,30,29,42,30,11,-5,0,51} ;
int main()
{

    for(int i= 0; i < heap_array.size() ; i++)
            build_heap(heap_array, i);
    pick_heap(heap_array);
    show_vector(heap_array);

    return 0;
}


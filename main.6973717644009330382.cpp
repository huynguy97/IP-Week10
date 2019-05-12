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
/*
       
        
             
               
                 
                  
                   

             
               
                 
                  
                   

             
               
                 
                  
                   

             
               
                 
                  
                   

             
               
                 
                  
                   

             
               
                 
                  
                   

        
                            
                            
                            
                            
                            
                            

       
                                                                                                                           
                                                                       
                                                   
                                                         
                                                                                                                                            
*/
void show_tree (vector<int> int_list)
{
    cout << "{";
    for(int i = 0; i < int_list.size(); i++)
    {
        cout << int_list[i] << ", ";
    }
    cout << "}" << endl;
}

void swap (vector<int>& int_list, int a, int b)
{
    assert(a >= 0 && b >=0 && a < int_list.size() && b < int_list.size());
    /*         
                                                           
    */

    int dummy = int_list[a];
    int_list[a] = int_list[b];
    int_list[b] = dummy;
}

void push_up(vector<int>& int_list, int index)
{
    assert(index >= 0 && index < int_list.size());
    /*         
                                                                            
    */

    int parent_index = (index-1)/2;
    while(int_list[index] > int_list[parent_index])
    {
        swap(int_list, index, parent_index);
        index = parent_index;
        parent_index = (index-1)/2;
    }
}

void build_heap (vector<int>& int_list)
{
    assert(true);
    /*         
                                           
    */

    for(int i = 1; i < int_list.size(); i++)
    {
        push_up(int_list, i);
    }
}

void push_down(vector<int>& int_list, int max_index)
{
    assert(max_index < int_list.size());
    /*         
                                                                                                                        
    */

    int index = 0;
    int child_index1 = 2*index + 1;
    int child_index2 = 2*index + 2;

    if(child_index1 >= max_index)
    {
        child_index1 = index;
    }
    if(child_index2 >= max_index)
    {
        child_index2 = index;
    }

    while(int_list[index] < max(int_list[child_index1], int_list[child_index2]))
    {
        if(int_list[child_index1] < int_list[child_index2])
        {
            swap(int_list, index, child_index2);
            index = child_index2;
        }
        else
        {
            swap(int_list, index, child_index1);
            index = child_index1;
        }
        child_index1 = 2*index + 1;
        child_index2 = 2*index + 2;

        if(child_index1 >= max_index)
        {
            child_index1 = index;
        }
        if(child_index2 >= max_index)
        {
            child_index2 = index;
        }
    }
}

void pick_heap (vector<int>& int_list)
{
    assert(true);
    /*         
                                    
    */
    for(int i = int_list.size() - 1; i > 0; i--)
    {
        swap(int_list, 0, i);
        push_down(int_list, i);
    }
}

int main()
{
    vector<int> int_list = {15, 40, 42, -15, 30, 35, 5};
    build_heap(int_list);
    pick_heap(int_list);
    show_tree(int_list);
}


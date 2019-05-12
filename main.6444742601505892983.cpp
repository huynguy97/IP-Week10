#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                              
//                                          

void swap(vector <int>& values, int parent, int child)
{
    assert(true);
    //                                        
    int storage = values[parent];
    values[parent] = values[child];
    values[child] = storage;
}

void push_down(vector <int>& values, int n, int i)
{
    assert(true);
    //                                                                                                                 
    int parent = i;
    int child_1 = 2*i + 1;
    int child_2 = 2*i + 2;

    if (child_1 < n && values[child_1] > values[parent])
        parent = child_1;
    if (child_2 < n && values[child_2] > values[parent])
        parent = child_2;
    if (parent != i)
    {
        swap(values,i,parent);
        push_down(values, n, parent);
    }
}

void push_up (vector<int>& values, int parent, int& child)
{
    assert(true);
    //                             
    assert(parent >= 0 && parent < values.size() - 1 && child > 0 && child <= values.size() - 1);
    int storage = values[parent];
    values[parent] = values[child];
    values[child] = storage;
}

void build_heap(vector<int>& values)
{
    assert(values.size() >= 0);
    //                                                                    
    for (int i = 0; i < 10; i++)
    {
        int child = i, child_1 = 2*i+1, child_2 = 2*i+2;
        if(values[i] < values[child_1] && (child_1) <= values.size() - 1)
        {
            push_up(values,i,child_1);
        }
        if(values[i] < values[child_2] && (child_2) <= values.size() - 1)
        {
            push_up(values,i,child_2);
        }
        if(values[i] > values[(i-1)/2] && ((i-1)/2) > 0)
        {
            int parent = ((child-1)/2);
            while (values[child] > values[parent])
            {
                push_up(values,(parent-1)/2, child);
                parent = ((child-1)/2);
            }
        }
    }
}

void pick_heap (vector <int>& values)
{
    assert(true);
    //                                         
    for (int i = values.size()-1; i >= 0; i--)
    {

        int child = i;
        swap(values,0,child);
        push_down(values,child,0);
    }
}

int main()
{
    vector <int> values = {2,14,30,29,42,30,11,-5,0,51} ;
    //                                                                        
    build_heap(values);
    pick_heap(values);
    cout << "          " << values[0] <<endl;
    cout << "      " << values[1] << "       " <<values[2] <<endl;
    cout << "    " << values[3] << "   " <<values[4] << "    " << values[5] << "   " <<values[6] <<endl;
    cout << " " << values[7] << " " <<values[8] << " " << values[9];
    return 0;
}

/*

                                                                      
                                                                          
                              
           

                                                                                   
                                                                                  
                                                                    
         

    

  
           
               
                 

           
               
                 

           
               
                 

     
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             

                                            
                                              
                                                                                           
                                                                      
                                                    
                                                                                                                                  

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                              

/*               
                                                      
 
                   
                   
                   
                         
                         
                                                                                                                         
                                                                                      
                                                                                    
                         
                         
                                                                                                                                         
                                                                                                                                                                            
                                                                                                                                                              
                                         
 
                                       
     
                   
                          
                                                                               
         
                                 
                              
         
                     
     
                                                                                              

           
                                    
              
                
                        
                  
                   

              
                
                 
                  
                  

               
                
                                               
                  
                    

       
*/
vector <int> unsorted = {2,14,30,29,42,30,11,-5,0,51};

void swap (vector <int>& test, int child)
{
    int parent = (child-1)/2;
    int a = test[child];
    int b = test[parent];
    test[parent] = a;
    test[child] = b;
}

bool one_push_up (vector <int>& test, int child)
{
    if (child == 0)
        return false;
    int parent = (child-1)/2;
    if (test[child] > test[parent])
    {
        swap(test, child);
    }
    else
        return false;
    return true;

}

void push_up (vector <int>& test, int child)
{
    int i = child;
    while (one_push_up(test, i))
    {
        one_push_up(test, i);
        i = (i-1)/2;
    }
}

void build_heap (vector <int>& test)
{
    //   
    //    
    int vsize = test.size();
    for (int i = 0; i < vsize; i++)
    {
        push_up(test, i);
    }
}

void swap2 (vector <int>& test, int low)
{
    int a = test[0];
    int b = test[low];
    test [0] = b;
    test [low] = a;
}

bool one_push_down (vector <int>& test, int parent)
{
    int vsize = test.size();
    int child1 = 2*parent + 1;
    int child2 = 2*parent + 2;
    if (test[child1] > test[child2])
    {
        if (test[child1] > test[parent])
        {
            swap(test, child1);
        }
        else
            return false;
    }
    else
    {
        if (test[child2] > test[parent])
        {
            swap(test, child2);
        }
        else return false;
    }
    return true;
}

void push_down (vector <int>& test, int parent)
{
    int i = parent;
    while (one_push_down(test, i))
    {
        one_push_down(test, i);
        if (one_push_down(test, 2*i + 1))
        {
            i = 2*i + 1;
        }
        if (one_push_down(test, 2*i + 2))
        {
            i = 2*i + 2;
        }
    }
}

void pick_heap (vector <int>& test)
{
    int vsize = test.size();
    swap2(test, vsize -1);
    push_down(test, 0);

}

int main()
{
    build_heap(unsorted);
    pick_heap(unsorted);
    for (int i = 0; i < 10; i++)
    {
        cout << unsorted[i] << endl;
    }
    return 0;
}


#include <iostream>

using namespace std;

#include <vector>
#include <cassert>

//                       

/*
       

                                                                                              
                                                             

                                                                                          
                                                                       

       

                          
          
              
                 
                     
              
                  
                     

       
                                               
                                                   
                                      
                                                    
                                      
                                                        
                                  
                                                        
                                      
                                                        
                                                         

                                                         
                                                                
                                                                                                   
                                                                 
                                                                                                  
*/

void push_up (vector<int>& elements, int index)
{//              
    assert (index >= 0);
/*                
                                                                                                    
*/
    while (index != 0)
    {
        if (index%2 == 0)
        {
            if (elements[index] > elements[(index-2)/2])
            {
                swap(elements[index], elements[(index-2)/2]);
            }
        }
        if (index%2 == 1)
        {
            if (elements[index] > elements[(index-1)/2])
            {
                swap(elements[index], elements[(index-1)/2]);
            }
        }
        index--;
    }
}

void build_heap (vector<int>& elements, int length)
{//              
    assert (true);
/*                
                                                               
*/
    for (int i = 1; i < length; i++)
    {
        push_up(elements, i);
    }
}

void push_down (vector<int>& elements, int notSorted)
{//              
    assert(notSorted >= 0);
/*                
                                                                                                     
*/
    swap (elements[0], elements[notSorted]);
    build_heap(elements, notSorted);
}

void pick_heap (vector<int>& elements)
{//              
    assert (true);
/*                 
                                                                                                      
*/
    int notSorted = elements.size()-1;
    while (notSorted != 0)
    {
        push_down(elements, notSorted);
        notSorted--;
    }
}

int main()
{
    vector<int> elements = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
    build_heap(elements, elements.size());
    pick_heap(elements);
    for (int i = 0; i < elements.size(); i++)
        cout << elements[i] << " ";
    return 0;
}


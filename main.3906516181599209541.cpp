#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

vector<int> A {15, 40, 42, -15, 30, 35, 5};
//                                            

void push_up (vector<int>& data, int index)
{
//                
    assert( index >=0 && index <= data.size() - 1);
//                 
//                                                                                          

    int i = index;
    int z = (i-1)/2;
    while (z >= 0 && data[i] > data[z])
    {
        swap(data[i], data[z]);
        i = z;
        z = (i-1)/2;
    }
}

void build_heap (vector<int>& data)
{
//                
    assert( true);
//                 
//                                  

    for (int index = 0; index <= data.size() - 1; index++)
        if (data[index] > data[(index-1)/2])
            push_up(data, index);
}

void push_down (vector<int>& data, int index)
{
//                
    assert( index >=0 && index <= data.size() - 1);
//                 
//                                                                                        

    int x = 0;
    int child1 = 2 * x + 1;
    int child2 = 2 * x + 2;

    swap(data[0], data[index]);

    while (((child1 <= index - 1 && data[child1] > data[x]) || (child2 <= index - 1 &&data[child2] > data[x])))
    {
        if (data[x] < data[child1] && (child2 > index - 1 || data[child1] >= data[child2]))
        {
                swap(data[x], data[child1]);
                x = child1;
        } else if (data[x] < data[child2] && child2 <= index - 1 && data[child2] >= data[child1])
        {
            swap(data[x], data[child2]);
            x = child2;
        }
        child1 = 2 * x + 1;
        child2 = 2 * x + 2;
    }
}

void pick_heap (vector<int>& data)
{
//                
    assert( true);
//                 
//                      

    for (int index = data.size() - 1; index >= 0; index--)
        push_down(data, index);
}

int main()
{
    build_heap(A);
    cout << "Heap built: " << endl;
    for (int x = 0; x <= A.size() - 1; x++)
       cout << A[x] << endl;
    pick_heap(A);
    cout << "\nHeap picked: " << endl;
    for (int x = 0; x <= A.size() - 1; x++)
        cout << A[x] << endl;
    return 0;
}

/*
                
  
                                                                                   
  
                                                                
                
  
        
              
                  
                     

              
                  
                     

              
                  
                     

              
                  
                     

              
                  
                     

              
                  
                     

              
                  
                     

        
                                  
                                  
                                  
                                  
                                  
                                  
                                  

  
                                                                    
                                                            
                                                                      
                                                            
                                                            
*/


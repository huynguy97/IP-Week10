#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                                                      
//                                                  

void swap(int& a, int& b)
{
    const int HELP = a;
    a = b;
    b = HELP;
}

void push_up(vector<int>& data, int index)
{
    //             
    assert(index >= 0);
    /*              
                                                                                        
    */

    while (index > 0 && data[(index - 1) / 2] < data[index]) {
        swap(data[(index - 1) / 2], data[index]);
        index = (index - 1) / 2;
    }
}

void build_heap(vector<int>& data)
{
    //             
    assert(true);
    /*              
                  
    */
    for (int i = 0; i < data.size(); i++)
        push_up(data, i);
}

void push_down(vector<int>& data, int length)
{
    //             
    assert(length >= 0);
    /*              
                                                                                                                              
    */
    int index = 0;
    while ((index * 2 + 1 < length && data[index * 2 + 1] > data[index]) || (index * 2 + 2 < length && data[index * 2 + 2] > data[index])) {
        if (index * 2 + 2 < length && data[index * 2 + 2] > data[index * 2 + 1]) {
            swap(data[index], data[index * 2 + 2]);
            index = index * 2 + 2;
        } else {
            swap(data[index], data[index * 2 + 1]);
            index = index * 2 + 1;
        }
    }
}

void pick_heap(vector<int>& data)
{
    //             
    assert(true);
    /*              
                                        
    */

    for (int i = data.size() - 1; i > 0; i--) {
        swap(data[i], data[0]);
        push_down(data, i);
    }
}

void heap_sort(vector<int>& data)
{
    //             
    assert(true);
    /*              
                   
    */

    build_heap(data);
    pick_heap(data);
}

int main()
{
    vector<int> data = {2, 5, 4, 3, 0, -3, 45, 6, 324, 6, 37, 42};
    heap_sort(data);
    for (int i = 0; i < data.size(); i++)
        cout << data[i] << ' ';

    return 0;
}

/*
       
                                                     
                                                       

       
  
                            
        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

  
                  
                       
                    
                      
                      
*/



#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;
/*

                     
                     

 
 
                                                                                                                           

 
                                                                                                                                       

  
      
                  
                    
                      
                        
                         

                      
                  
                    
                      
                        
                         

                  
                    
                      
                        
                         
                 
                  
                    
                      
                        
                         

                      

      

                                 
                                
                                    
                                
                                    
                                
                                    
                                
                                    
                                
                                    
                                
      

 
                                                                           
                                                   
*/

vector<int> data = {15, 40, 42, -15, 30, 35, 5};

void swap (int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}

void push_up (int& x, int& y)
{
    if (x > y)
    {
        swap (x, y);

    }
}

void build_heap (vector<int>& data)
{

    for ( int i = 0; i < data.size()-1 ; i++)
    {
        push_up(data[i], data[((i-1)/2)]);
        if (data[i] > data[((i-1)/2)])
        {
            i=((i-1)/2)-1;
        }
    }

}

void push_down (int t, int i)
{
    while (i > 2t+1 && (data[2*t+1] > data[t] || data[2*t+2 > data[t]))
    if (data[t] < data[2*t+1] && data[2*t+1] >= data[2*t+2] && 2*t+1 < i)
{
    swap (data[t], data[2*t+1])
        t=2*t+1
    };
   if (data[t] < data[2*t+2] && data[2*t+2] >= data[2*t+1] && 2*t+2 < i)
{
    swap (data[t], data[2*t+2])
        t=2*t+2
    };
    if (data[t] < data[2*t+1]  && 2*t+2 == i)
{
    swap (data[t], data[2*i+1])
        t=2*t+1
    };

}
}
void pick_heap (vector<int>& data)
{

        i = data.size() -1;

    while (i>0)
    { int t=0
        swap(data[t], data[i]);
        i--
        push_down(t, i)
    }
}
//                                                                                                                    
int main()
{
    build_heap (data);
    pick heap (data);

}


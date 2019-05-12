//                                                                 
#include <iostream>
#include <cassert>
#include<vector>
using namespace std;

/*
       
                                                                                                                          
                                                                                                       

       
  
               
                
                   
                    
                     

              
                
                   
                    
                     

              
                
                   
                    
                     

               
                
                   
                    
                     

              
                
                   
                    
                      

               
                
                   
                    
                      

              
                
                   
                    
                      

               
                
                  
                    
                      

               
                
                  
                    
                      

               
                
                  
                    
                      

               
                
                  
                    
                      

              
                
                  
                    
                      

              
                
                   
                    
                      

               
                
                  
                    
                      

                  
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      

  
                                                                                                                               
                                                                                                                                 
                                                                                             
                                                                                                                                                  
*/

const int N = 7;
vector<int> data = {15, 40, 42, -15, 30, 35, 5};

void swap_1 (int child, int parent)
{
//               
    assert(-1 < child && -1 < parent && parent < N && child < N );
/*               
                                                                                                           
                                                                                                   
*/
    const int HELP = data[child];
    data [child] = data [parent];
    data [parent] = HELP;
}

void push_up (int child, int parent)
{
//               
    assert(-1 < child && -1 < parent && parent < N && child < N );
/*               
                                                                                                                                                                                               
                                                                                                                            
*/
    while (data [child] > data [parent])
    {
        swap_1(child, parent);
        child = parent;
        parent = (child-1)/2;
    }
}

void build_heap()
{
//               
    assert(true);
/*               
                                 
*/
    for (int child = 0; child < N ; child++)
    {
        int parent = (child-1)/2;
        push_up(child, parent);
    }
}

int find_big_child (int parent)
{
//               
    assert(-1 < parent && parent < N);
/*               
                                                        
*/
    if (data[2*parent+1] > data[2*parent +2])
        return (2*parent+1);
    return (2*parent+2);

}

void push_down (int counter)
{
//               
    assert(-1 < counter && counter < N);
/*               
                                                                                                                                                                                              
*/
    int parent = 0;
    int big_child = find_big_child (parent);

    while (data [big_child] > data [parent] && big_child < counter )
    {
        swap_1(big_child, parent);
        parent = big_child;
        big_child = find_big_child (parent);
    }
}

void pick_heap ()
{
//               
    assert(true);
/*               
                                   
*/
    int counter = N-1;
    while (counter != 0)
    {
        swap_1(0, counter);
        counter--;
        push_down(counter);
    }
}

int main()
{

    build_heap();
//                              
//   
//                             
//   

    pick_heap ();
    for (int i = 0; i < N; i++)
    {
       cout << data [i] <<endl;
    }
    return 0;
}



//                                 
//                             

/*
      
                                                                       
                                                             

                                                                     
                                                                   
                                                                 

      
  
       
         
          
            
             
              

         
          
            
             
              

         
          
            
             
              

                                       
         
          
            
             
              

                                      
                                     
         
          
            
             
              

       
        
          
            
             
                 
                            
         
          
           
             
                 
                            
         
          
            
             
                 
                            

                                      
         
          
            
             
                 
                            

         
          
            
             
                 
                            

                                      
         
          
            
             
                   
                            

         
          
            
             
                   
                            

         
           
              
                
                   
                            

          
           
             
               
                   
                            

          
           
             
               
                   
                            

          
           
             
               
                    
                            

         
           
             
               
                    
                            

         
           
             
               
                    
                            

         
           
                
               
                    
                            

                                      
           
                 
               
                    
                            

           
           
                 
               
                    
                            

  
                                                                 
                       

                                                                        
                                                             
                                      

                                                                   
                       

                                                           
                                                                          

                                                             
                                                                         
                            
*/

#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>

using namespace std;

bool operator<< (ostream& os, vector<int> a)
{
    for (int i = 0; i <= a.size() - 1; i++)
        cout << a[i] << endl;
    cout << endl;
    return true;
}

void swap_element(int i, int j, vector<int>& to_be_sorted)
{//             
    assert(i >= 0 && j >= 0);
//              
//                                                                     
//                                           
//              
    int stored = to_be_sorted[i];
    to_be_sorted[i] = to_be_sorted[2*i+j];
    to_be_sorted[2*i+j] = stored;
}

void check_parent(int i, vector<int>& to_be_sorted)
{//             
    assert(i >= 0 && i <= to_be_sorted.size());
//              
//                                                                      
//              
    while (i)
    {
        int parent = (i-1)/2;
        if (to_be_sorted[i] > to_be_sorted[parent])
            {
                swap_element(i, parent, to_be_sorted);
                i = parent;
            }
        else
            i = 0;
    }
}

void push_up(int i, int j, vector<int>& to_be_sorted)
{//             
    assert(to_be_sorted.size() > i >= 0 && j >= 0);
//              
//                                                                                                                                     
//              
    if (to_be_sorted[i] < to_be_sorted[2*i+j])
    {
        swap_element(i, j, to_be_sorted);
        check_parent(i, to_be_sorted);
    }
}

void build_heap(vector<int>& to_be_sorted, int vector_size)
{//             
    assert(vector_size <= to_be_sorted.size());
//              
//                                                                                       
//              
    for (int i = 0; i < vector_size - 1; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (2*i+j <= vector_size - 1)
                push_up(i, j, to_be_sorted);
        }
    }
}

void push_down(int& vector_size, vector<int>& to_be_sorted)
{//             
    assert(vector_size <= to_be_sorted.size());
//              
//                                                                                                                         
//              
    swap_element(0, vector_size - 1, to_be_sorted);
}

void pick_heap(int& vector_size, vector<int>& to_be_sorted)
{//             
    assert(vector_size <= to_be_sorted.size());
//              
//                                                                                                                       
//                                              
//              
    while (vector_size > 0)
    {
        build_heap(to_be_sorted, vector_size);
        push_down(vector_size, to_be_sorted);
        vector_size--;
    }
}

int main()
{
    vector<int> to_be_sorted = {15, 40, 42, -15, 30, 35, 5};
    int vector_size = to_be_sorted.size();
    pick_heap(vector_size, to_be_sorted);
    cout << to_be_sorted;
    return 0;
}


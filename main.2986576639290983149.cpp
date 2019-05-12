#include <iostream>
#include <vector>

using namespace std;

//                        

/*
      
                                                                                                                                                                                        
                                                                                                                             
*/

/*
      
                      

            
              
               
                
                 

            
              
               
                
                 

            
              
               
                
                 

            
             
              
               
                

            
             
              
               
                

            
             
              
              
              
                  
            
             
              
              
              

            
             
              
         
         

          
           
            
         
          

           
            
             
       
       

           
            
             
       
       

          
           
            
      
      

          
           
            

          
           
            

          
           
             

          
         
         

           
         
        

          

                    
                                              
                            
                            
                            
                            
                            
                            
                            
                            
                            

   
                                
          
*/

vector<int> heap = {15, 40, 42, -15, 30, 35, 5};

void push_up(vector<int>& heap, int n)
{
    for (int i=1; i != n ;i++)
    {
        if (heap[i-1] <= heap[i])
        {
          swap(heap[i], heap[i-1]);
        }
        cout << heap[i-1] << ", ";
    }
    cout << heap[n-1];
}

void build_heap(vector<int>& heap, int n)
{
    for (int i=1; i!=n)
}

int main()
{
    int n = heap.size();
    push_up(heap, n);

    return 0;
}


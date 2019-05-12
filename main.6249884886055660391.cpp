#include <iostream>
#include <cmath>

using namespace std;
//                       

/*       
                                                                                       
                                                                                        
                                                                                                                                        
                                          

      
          
        
          
           
            
             

        
          
           
            
             

        
          
           
            
             

        
          
           
            
             

       
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

  
                                                                       
                                                                                             
                                                                                           
                                                                     
                
                                               

*/

//       
const int N = 7;
int heap[] = {15, 40, 42, -15, 30, 35, 5};
int push_up (int heap[N], int i){
    while (i>0){
        if (heap[i] > heap[(i-1)/2]){
            int H = heap[i];
            heap[i]=heap[(i-1)/2];
            heap[(i-1)/2] = H;
            i=(i-1)/2;
        }
    }
}

int build_heap (int heap[N]){
    for (int i=1; i<N; i++){
        push_up(heap, i);
        cout << heap[i] << "\t";
    }
    return heap[N];
}

int swap(int heap[N], int i){
    int H = heap[i];
    heap[i]=heap[0];
    heap[0] = H;
    return heap[N];
}

int push_down(int heap[N], int i){
    if (heap[2*i+2]<=heap[2*i+1] && heap[i]<heap[2*i+1]){
        int H = heap[i];
        heap[i]=heap[2*i+1];
        heap[2*i+1] = H;
    }
    else if (heap[2*i+1]<heap[2*i+2] && heap[i]<heap[2*i+2]){
        int H = heap[i];
        heap[i]=heap[2*i+2];
        heap[2*i+2] = H;
    }
    return heap[N];
}

int pick_heap(int heap[N]){
    swap(heap, N-1);
    for(int n=N; n>0; n--)
        push_down(heap, n);
    return heap[N];

}

int main()
{
    pick_heap(heap);
    //                 
    //                 
    //                               

    return 0;
}

/*                                 
                             
                        
                            
                        
     
                                  
                        
                            
                        
     
                   
 */

/*                                 
             
                              
                        
                        
                    
         
     

                                                        
                                       
                            
                                
                            
                    
         
     
                                           
                                         
                            
                                  
                              
                      
         
     
                   
 */


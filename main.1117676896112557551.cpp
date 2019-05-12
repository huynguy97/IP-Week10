/*
                       
             
              
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int array_size = 7;
vector<int> start_vector = {15, 40, 42, -15, 30, 35, 5};

int size(vector<int>& data)
{
    return static_cast<int>(data.size());
}

void show_heap(vector<int>& heap)
{
    //             
    assert(size(heap) >= 7);
    //                                                            
    cout << "\t  " << heap[0] << endl;
    cout << "\t/   \\ " << endl;
    cout << "       " << heap[1] << "    " << heap[2] << endl;
    cout << "      /  \\  /  \\ " << endl;
    cout << "    " << heap[3] << "  " << heap[4] << " " << heap[5] << "  " << heap[6] << endl;
    cout << endl;
}

void print_array(vector<int>& data)
{
     //             
    assert(true);
    //                                                          
    cout << '{';
    for(int i = 0; i < size(data); i++)
    {
        cout << data[i];
        if(i != size(data)-1)
            cout << ',';
    }
    cout << '}' << endl;
}

void swap_elements(vector<int>& data, int i, int j)
{
    //             
    assert(size(data) > 0 && i < size(data) && j < size(data));
    //                                                           
    int element = data[i];
    data[i] = data [j];
    data[j] = element;
}

void push_up(vector<int>& heap, int i)
{
    //             
    assert(size(heap) > 0 && i < size(heap) && i >= 0);
    //                                                                           

    int index = i;
    int parent_index = (index-1)/2;

    while(heap[index] > heap[parent_index] && parent_index < size(heap) && parent_index >= 0) //                                                                     
    {
        swap_elements(heap, index, parent_index);
        index = (index-1)/2; //                                     
        parent_index = (index-1)/2;
    }
}
int get_child_index(vector<int>& heap, int i)
{
    //             
    assert(size(heap) > 0 && i < size(heap) && i>= 0);
    //                                                                         
    if(heap[2*i+1] >= heap[2*i+2])
        return 2*i+1;
    else
        return 2*i+2;
}

void push_down(vector<int>& heap, int i, int until)
{
    //             
    assert(size(heap) > 0 && i < size(heap) && i >=0);
    //                                                                                  

    int index = i;
    int child_index = get_child_index(heap,index);

    while(heap[index] < heap[child_index] && child_index < until && child_index >= 0) //                                                                                                                            
    {
        swap_elements(heap, index, child_index);
        index = child_index;
        child_index = get_child_index(heap,index);
    }
}

void build_heap(vector<int>& heap)
{
    //             
    assert(size(heap) > 0 );
    //                                                
    show_heap(heap);
    for(int i = 0; i < size(heap); i++) //                                                                
    {
        push_up(heap,i);
        show_heap(heap);
    }
}

void pick_heap(vector<int>& heap)
{
    //             
    assert(size(heap) > 0 );
    //                                   
    print_array(heap);
    for(int i = size(heap)-1; i >= 0; i--) //                       
    {
        swap_elements(heap, 0, i);
        push_down(heap,0, i-1);
        print_array(heap);
    }
}

/*                                      

                                     
 
                   
                          
                                                                 
                                      
                                
                                                              
                                          
                                                                                              
                 
 

                                       
 
                    
                           
                                                               
                
                                       
     
                        
                             
                        
     
                        
 

                                                       
 
                   
                                                               
                                                                 
                          
                       
                      
 

                                          
 
                   
                                                       
                                                                                 

                  
                                   

                                                                                                                                                                     
     
                                                 
                                                                    
                                   
     
 
                                                 
 
                   
                                                      
                                                                               
                                  
                     
        
                     
 

                                                       
 
                                    
                                                      
                                                                                        

                  
                                                  

                                                                                                                                                                                                                   
     
                                                
                            
                                                  
     
 

                                      
 
                   
                            
                                                      
                    
                                                                                                         
     
                        
                        
     
 

                                     
 
                   
                            
                                         
                      
                                                                    
     
                                  
                               
                          
     
 
*/

int main()
{
    //                        
    build_heap(start_vector);
    pick_heap(start_vector);

    return 0;
}

/* 
       
                                                                                                                 
                                                                                               

       
                        
            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

            
             
               
                
                 

                    
                          
                          
                          
                          
                          
                          
                          
                          

  
                                                                                                                                                                                               
                                                         

                                                          
                                                       

                                                                                                    
 */


#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*                                
                  
                                                           
                    
                 
                                                                          
                                              

                            
        
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
             
        
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
             
           
                                            
                                                           
                    
                 
                                                                          
                                              

                            
        
	  
           
             
              
               
	  
           
             
              
                                 
                                                           
                    
                 
                                                                          
                                              

                            
        
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
             
        
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
             
           
                                                                                             
                                 
                                                                              
                                        
                                                                                  
                                                                       
                                                                                          
                                                                                                                         

	  
           
             
              
               
	  
           
             
              
               
             
        
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
             
           
                                                                                             
                                 
                                                                              
                                        
                                                                                  
                                                                       
                                                                                          
                                                                                                                         

                                                                   
                                 
                                                                              
                                        
                                                                                  
                                                                       
                                                                                          
                                                                                                                         
                                             
                                                           
                    
                 
                                                                          
                                              

                            
        
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
	  
           
             
              
               
             
        
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
             
           
                                                                                             
                                 
                                                                              
                                        
                                                                                  
                                                                       
                                                                                          
                                                                                                                         

      */

vector<int> tree ; //              

void swap_two(int i, int j)
{
    int help=tree[i];
    tree[i]=tree[j];
    tree[j]=help;
}

void push_up (int i)
{
    assert(i<tree.size());
    while (tree[(i-1)/2]<=tree[i] && i>0)
    {
        swap_two(i,(i-1)/2);
        i=(i-1)/2;
    }
}

void build_heap ()
{
    assert(true);
    for (int i=1; i<tree.size(); i++)
        push_up(i);
}

void swop(int N) //                
{
    assert(N<=tree.size());
    swap_two(0,N);
}

void push_down (int heap_size)
{
    assert(heap_size>=1 && heap_size<=tree.size());
    int i=0;
    while( (2*i+1<heap_size && tree[i]<tree[2*i+1]) ||
           (2*i+2<heap_size && tree[i]<tree[2*i+2])  )
    {
        if (2*i+2<heap_size)
        {
            if(tree[2*i+1]<tree[2*i+2])
            {
                swap_two(i,2*i+2);
                i=2*i+2;
            }
            else
            {
                swap_two(i,2*i+1);
                i=2*i+1;
            }
        }
        else
        {
            swap_two(i,2*i+1);
            i=2*i+1;
        }
    }
}

void pick_heap()
{
    for (int i=1; i<tree.size(); i++)
    {
        swop(tree.size()-i);
        push_down (tree.size()-i);
    }
}

void heap_sort()
{
    build_heap();
    pick_heap();
}

int main()
{
    int amount;
    int input;
    cout << "How many elements do you want to sort?" << endl;
    cin >> amount;
    cout << "Enter the elements splitted by enters" << endl;
    for (int i=0; i<amount; i++)
    {
        cin >> input;
        tree.push_back(input);
    }
    heap_sort();
    cout << '{';
    for (int j=0; j<amount-1; j++)
        cout << tree[j] << ", ";
    cout << tree[amount-1] << '}';
    return 0;
}


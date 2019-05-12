#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//                      

//      
//                                                                                            
//                                                                        
//                                                                              
//                                                                                     
//                                                                                     
//                                   

//      
/*
   
                      
  
              
                
                  
                   
                    

        
          
              
                
                  
                   
                    
          
              
                
                  
                   
                    
          
              
                
                  
                   
                    

        
                                                      
      
                       
           
                       
      
                       
           
                       
      
                       
           
                       
      
                       
           
                       
      
                       
           
                      

   
                                                                                                                                                                    
                                                                            
                                                                                                                                                                    
                                                                              
                                                                           
*/

//      
int parent_index(int child)
{//              
    assert(true) ;
/*               
                                                 
*/
    if (child%2 == 0)
        return (child/2) - 1 ;
    else
        return (child-1)/2 ;
}

void push_up(vector<int>& integers, int child)
{//              
    assert(child < integers.size()) ;
/*               
                                                                        
*/
    bool larger_than_parent = (integers[child] > integers[parent_index(child)]) ;
    while (larger_than_parent)
    {
        int help = integers[parent_index(child)];
        integers[parent_index(child)] = integers[child];
        integers[child] = help ;
        child = parent_index(child);
        larger_than_parent = (integers[child] > integers[parent_index(child)]) ;
    }
}

void build_heap(vector<int>& integers)
{//              
    assert(true) ;
/*               
                                           
*/
    for (int i = 0 ; i < integers.size() ; i++)
        push_up(integers, i) ;
}

void swap_phase2(vector<int>& integers, int index)
{//              
    assert(index < integers.size()) ;
/*               
                                                                                 
*/
    int help = integers[0] ;
    integers[0] = integers[index] ;
    integers[index] = help ;
}

int largest_child(vector<int>& integers, int index, int max_index)
{//              
    assert(index < integers.size()) ;
/*               
                                                                                                                         
*/
    if (integers[(2*index)+1] > integers[index] && (2*index)+1 <= max_index)
    {
        if (integers[(2*index)+2] > integers[index] && (2*index)+2 <= max_index)
        {
            if (integers[(2*index)+1] > integers[(2*index)+2])
                return 1 ;
            return 2 ;
        }
        return 1 ;
    }
    if (integers[(2*index)+2] > integers[index] && (2*index)+2 <= max_index)
        return 2 ;
    else
        return 0 ;
}

void push_down(vector<int>& integers, int max_index)
{//              
    assert(max_index < integers.size()) ;
/*               
                                                                                      
*/
    int element = 0 ;
    int res;
    while ((res = largest_child(integers, element, max_index)) != 0)
    {
        int help = integers[element] ;
        integers[element] = integers[(2*element)+res] ;
        integers[(2*element)+res] = help ;
        element = (2*element)+res ;
    }
}

void pick_heap(vector<int>& integers)
{//              
    assert(true) ;
/*               
                                              
*/
    int index = integers.size()-1 ;
    while (index > 0)
    {
        swap_phase2(integers, index) ;
        push_down(integers, index - 1) ;
        index-- ;
    }
}

vector<int> integers = {2,14,30,29,42,30,11,-5,0,51} ;

int main()
{   //          
    build_heap(integers) ;
    pick_heap(integers) ;
    for (int i = 0 ; i < integers.size() ; i++)
        cout << integers[i] << ' ';
    cout << endl;
    return 0;
}


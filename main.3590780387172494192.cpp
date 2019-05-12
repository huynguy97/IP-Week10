/*      

                            
                            

      

                                   
                                   
                                   

                                   

 
                                                                              
                                                                              
                                                                              
 
                                                                              
                                                                              
 
                                                                              
 

                              
                               
                        

      

                
                                        
          
          
            
             
              

                                                         
          
          
            
             
              

                                                     
          
          
            
             
              

                                                                    
          
          
            
             
              

                                                             
          
          
            
             
              

                                                                        
          
          
            
             
              

                                               
          
          
            
             
              

                                                 
          
          
            
             
              

                                     

                         
                                                
                                              

                                                             
                                                                                                           
                      

                                                           
                                              

                                                             
                                                                                                
                      

                                                  
                                              

                                                                
                                                                                          
                      

                                                   
                                              

                                                                 
                                                                                            
                      

                                                  
                                              

                                                                                                               
                      

                                                   
                                              

                                                                                 
                      

                              

                                                   
                                                                                                   
                                                                                                                                                                                     
                                                                                                                                                                                             
                                                  
  */

#include <iostream>
using namespace std;
#include <vector>
#include <cassert>

void dump(vector<int> a)
{ //           
    assert(true);
  //             
  //                                                        
  //                                                 
  for(int i; i < a.size(); i++)
    cout << a[i] << ' ';
  cout << endl;
}

int parent(int i)
{
  //           
  assert(i >= 0);
  //             
  //                                 
  if(i % 2 != 0)
    return i / 2;
  return (i - 1) / 2;
}

void swap_with_parent(vector<int>& a, int i)
{
  //           
  assert(i >= 0 && i < a.size());
  //             
  //                        
  int h = a[parent(i)];
  a[parent(i)] = a[i];
  a[i] = h;
}

void push_up(vector<int>& a, int i)
{
  //            
  assert(true);
  //             
  //                                                 
  //     
  if(i == 0 || i >= a.size())
    return;

  int c = a[i]; //                              
  int last_parent = parent(i);
  int last_index = i;
  while(c > a[last_parent])
  {
    swap_with_parent(a, last_index);
    last_index = last_parent;
    last_parent = parent(last_parent);
  }
}

void build_heap(vector<int>& a)
{
  //            
  assert(true);
  //            
  //                                                     
  //                      
  for(int i = 0; i < a.size(); i++)
    push_up(a, i);
}

void swap(vector<int>& a, int i)
{
  //            
   assert(true);
  //             
  //              
  int h = a[i];
  a[i] = a[0];
  a[0] = h;
}

void push_down(vector<int>& a, int i)
{
  //            
  assert(true);
  //             
  //              
  int h = a[i];
  a[i] = a[parent(i)];
  a[parent(i)] = h;
}

void heap_sort(vector<int>& a)
{
//            
assert(true);
//             
//                              
//                    
  int l = a.size()-1;
  for(int i = 0; i < a.size(); i++ ) {
    swap(a, l);
    int h = a[0];
    l--;

    int last_child = 0;
    while((h < a[2*last_child + 1] || h < a[2*last_child + 2]) &&
    (2*last_child + 1 <= l || 2*last_child + 1 <= l))
    {
      if(a[2*last_child + 1] > a[2*last_child + 2] || 2*last_child+2>=l)
        last_child = 2*last_child + 1;
      else
        last_child = 2*last_child + 2;
      push_down(a, last_child);
    }
  }
  if(a[0] > a[1]) swap(a, 1);
}

int main() {
  vector<int> a = {51, 42, 30, 2, 30 ,14, 11, -5, 0, 29};
  build_heap(a);
  heap_sort(a);
  dump(a);
  return 0;
}


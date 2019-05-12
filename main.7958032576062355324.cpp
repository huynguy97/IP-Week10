#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//                                 
//                             

/*
        

   
                  
                                                               
                                                                                    

   
                                  
                                                                               
                                                                                                           

       
   

            
                
                   
                     
                      
                        

                
                   
                     
                      
                        

                
                   
                     
                      
                        

                
                   
                     
                      
                        

                
                   
                     
                      
                        

                
                   
                     
                      
                        

                
                   
                     
                      
                        

             
                                   
                                            
                                      
                                      
                                            
                                      
                                            
                                      
                                            
                                      
                                            
                                            
       

  
                                                                                                              
                                                          

                                                                                                         
                                                                   

                                                                                                               
                                                                                               
                                                                       

                                                                                              
*/

vector<int> example_vector = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
vector<int> part2_exe_vector = {15, 20, 42, -15, 30, 35, 5};

int size (vector<int>& v)
{
//                
    assert (true);
//                 
//                                                       
    return static_cast<int> (v.size());
}

void swap (vector<int>& v, int pos)
{
    //               
    assert(size(v) >= 0 && pos >= 0 && pos < size(v));
    /*                 
                                                                      
    */
    int save = v[pos];
    v[pos] = v[0];
    v[0] = save;
}

void push_up (vector<int>& v , int pos)
{
    //               
    assert(size(v) >= 0 && pos >= 0 && pos < size(v));
    /*                 
                                                                                    
                                                                        
    */
    while (v[pos] > v[(pos-1)/2] && pos > 0)
    {
        int save = v[pos];
        v[pos] = v[(pos-1)/2];
        v[(pos-1)/2] = save;
        pos = (pos-1)/2;
    }
}

void build_heap (vector<int>& v)
{
    //               
    assert(size(v) >= 0);
    /*                 
                                                                 
                                 
    */

    for (int i = 1; i < size(v); i++)
        push_up(v, i);

}

int check_child (vector<int>&v, int pos, int i)
{
    //               
    assert(size(v) >= 0 && pos >= 0 && pos < size(v) && i < size(v) && i >= 0);
    /*                 
                                                                    
                             
                                                          
    */
    if (2*pos+1 >= i)
        return pos;
    if (2*pos+2 >= i)
        return 2*pos+1;
    if (v[2*pos+1] > v[2*pos+2])
        return 2*pos+1;
    else
        return 2*pos+2;
}

void push_down (vector<int>& v, int i)
{
    //               
    assert(size(v) >= 0 && i < size(v) && i >= 0);
    /*                 
                                                                        
                                                
    */
    int pos = 0;
    while (pos < size(v) && v[pos] < v[check_child(v, pos, i)])
    {
        int save = v[pos];
        int save_pos = check_child(v, pos, i);
        v[pos] = v[save_pos];
        v[save_pos] = save;
        pos = save_pos;
    }
}

void pick_heap (vector<int>& v)
{
    //               
    assert(size(v) >= 0);
    /*                 
                                    
                                                                    
                                                   
    */

    for (int i = size(v) - 1; i > 0; i--)
    {
        swap(v, i);
        push_down(v, i);
    }
}

void show_vector (vector<int>& v)
{//               
    assert(size(v) >= 0);
    /*                 
                          
    */

    for (int i = 0; i < size(v); i++)
        cout << v[i] << ' ';
    cout << endl;
}

int main()
{
    build_heap(example_vector);
    pick_heap(example_vector);
    show_vector(example_vector);
    build_heap(part2_exe_vector);
    pick_heap(part2_exe_vector);
    show_vector(part2_exe_vector);

    return 0;
}


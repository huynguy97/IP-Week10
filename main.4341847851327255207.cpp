/*                                                            
                          
                                    
                                    
                                                             */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> v = {15, 40, 42, -15, 30, 35, 5};

/*                                                            
                 
                                                             */

void push_up (vector<int>& v, int i)
{
/*              */ assert (i >= 0);
/*               
                                                                                       
                                                              */
    while (v[i] > v[(i-1)/2])
    {
        const int SWAP_PARENT = v[i];
        v[i] = v[(i-1)/2];
        v[(i-1)/2] = SWAP_PARENT;
    }
}

bool build_heap (vector<int>& v)
{
/*              */ assert (true);
/*               
                                                         
                                                   
                                                  */
    for (int i = 0; i < v.size(); i++)
    {
        push_up (v, i);
    }
    cout << "\nVector values after build_heap: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    return true;
}

void swap (vector<int>& v, int i)
{
/*              */ assert (i >= 0 && i < v.size());
/*               
                                      */
    const int SWAP = v[i];
    v[i] = v[0];
    v[0] = SWAP;
}

void push_down (int i, int j)
{
/*              */ assert (0 <= i && i < v.size() && j == 0);
/*               
                                                                           
                                              
                                                                        */
    int big_child = 0;
    if (i > 1)
    {
        if (i>2)
        {
            while (v[j] < v[(2*j)+1] || ((v[j] < v[(2*j)+2] && j < i)))
            {
                if (v[2*j+1] > v[2*j+2])
                    big_child = (2*j+1);
                else if (v[2*j+2] > v[2*j+1])
                    big_child = (2*j+2);
                if (big_child < i)
                {
                    const int SWAP_CHILD = v[j];
                    v[j] = v[big_child];
                    v[big_child] = SWAP_CHILD;
                    i--;
                }
                j = big_child;
            }
        }
        else if (i > 1 )v[j] < v[(2*j)+1])
        {
            const int SWAP_CHILD = v[j];
            v[j] = v[(2*j)+1];
            v[(2*j)+1] = SWAP_CHILD;
            i--;
        }
    }
}

void pick_heap (vector<int>& v)
{
/*              */ assert (build_heap);
/*               
                                                                           
                                                                                                                */
    for (int i = v.size()-1; i >= 0; i--)
    {
        swap(v, i);
        push_down(i, 0);
    }
    cout << "\nSorted vector values: \t\t";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "\n" << endl;
}

int main()
{
    cout << "Initial vector values: \t\t";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    build_heap(v);
    pick_heap(v);
    return 0;
}

/*                                                                          
                     
                                                                            

       
                             
                                 
                                                                    
                                           

                                     
                              
                                                                                
                                                                                                 

       
                                                                    

                               
                  
                       
                         

                  
                       
                         

                  
                       
                         

                                                                          
                       
                         

                              
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        

                                            

                         
                                          
                                                                        
                                                

                            
                                    
                                                                                             

                            
                                          
                                                                        
                                                

                           
                                    
                                                                               
                                                                                
                                                                              

                                                        

                                                                                  */


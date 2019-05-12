//                        
//                           

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
vector<int> ex2a = {15, 40, 42, -15, 30, 35, 5};

/*
       
                                                                                          
                                                                                                                                                                    
*/
vector<int> swap(vector<int> vect, int i, int j)
{
    //     
    //                                             
    //      
    //                                      
    const int dummy = vect[i];
    vect[i] = vect[j];
    vect[j] = dummy;
    return vect;
}

vector<int> push_up(vector<int>& vect, int i)
{
    //     
    assert(vect.size() > 0 && i >= 0);
    //      
    //                                                                                     
    for( ; vect[i] > vect[(i-1)/2]; i = (i-1)/2)
    {
        vect = swap(vect, i, (i-1)/2);
    }
    return vect;
}

vector<int> build_heap(vector<int>& vect)
{
    //     
    assert(vect.size()>0);
    //      
    //                                       
    for(int i = 0;i<vect.size();i++)
    {
        push_up(vect, i);
    }
    return vect;
}

vector<int> push_down(vector<int>& vect, int i)
{
    //     
    //                                   
    //      
    //                                                                                
    int j;
    for( ; i<vect.size(); i = 2*i + j)
    {
        if(2*i+1 > vect.size() && 2*i + 2 > vect.size())
        {
            break;
        }
        else if(2*i+2 > vect.size())
        {
            if(vect[2*i+1] > vect[i])
            {
                vect = swap(vect, 2*i+1, i);
                j = 1;
            }
        }
        else if(vect[i] < vect[2*i + 1] || vect[i] < vect[2*i + 2])
        {
            if(vect[2*i + 1] <= vect[2*i + 2])
            {
                vect = swap(vect, 2*i+2, i);
                j = 2;
            }
            else if(vect[2*i + 2] < vect[2*i + 1])
            {
                vect = swap(vect, 2*i+1, i);
                j = 1;
            }
        }
    }
    return vect;
}

vector<int> pick_heap(vector<int>& vect)
{
    //     
    assert(vect.size() > 0);
    //      
    //                                                            
    vector<int> picked_vect;
    //                                                                                  
    //                                                                        
    for(int i = 0; i<vect.size(); i++)
    {
        picked_vect.push_back(0);
    }
    int n = vect.size();
    while(vect[0] >= vect[n-1] && n >=1)
    {
        vect = swap(vect, 0, n-1);
        picked_vect[n-1] = vect[n-1];
        vect.pop_back();
        n = vect.size();
        push_down(vect, 0);
    }
    return picked_vect;
}

vector<int> Heap_sort(vector<int>& vect)
{
    //     
    assert(vect.size() > 0);
    //      
    //                                                                                 
    vect = build_heap(vect);
    for(int i = 0; i<vect.size(); i++)
    {
        if(i == vect.size()-1)
        {
            cout << vect[i] << endl;
        }
        else{
        cout << vect[i] << ",";
        }
    }
    vect = pick_heap(vect);
    for(int i = 0; i<vect.size(); i++)
    {
        if(i == vect.size()-1)
        {
            cout << vect[i] << endl;
        }
        else{
        cout << vect[i] << ",";
        }
    }
    return vect;
    //                                                                                                 
    //                                                                                 
}

int main()
{
    vector<int> ex1a = {15, 40, 42, -15, 30, 35, 5};
    Heap_sort(ex1a);
    return 0;
}

/*
                      
  
  
                                   
      
          
           
             
              
               
                                                                       
                      
          
           
             
              
               
                     
          
           
             
              
               
                             
          
           
             
              
               
      
          
           
             
              
               
                                            
                                                 
                  

            
           
                                                                                                       
       
                                                  
      
                                                  
       
                                                   
      
                                                    
      
                                                     
        
                                                     
       
                                                       
      
                                                        
      
                                                         
         
                                                           
        
                                                             
                           

                                                           
                                                                                                                               
                                                                                                    
                                                                                                                                                                     
                                                                                                            
                                                                                                                                                                        
                                                                                       
*/


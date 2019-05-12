#include <iostream>
#include <vector>
#include <cassert>
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
//                                                                                        
//                                                                                                                                 
//             
//
//        
//
//            
//               
//                  
//                   
//                    
//
//
//            
//               
//                  
//                   
//                    
//
//
//            
//               
//                  
//                   
//                    
//
//            
//               
//                  
//                   
//                    
//
//                              
//                              
//                               
//                              
//
//                              
//                              
//
//                               
//                              
//
//                              
//                              
//
//                             
//
//                              
//
//                   
//                            
//                     
//                           
//
//        

void Swap(int& a, int& b)
{
//               
assert(true);
//                                                                  
    const int Extra = a;
    a = b;
    b = Extra;
}

void push_up (vector<int>& v, int index)
{
//               
assert(index >= 0 && index < static_cast<int>(v.size()));
//                                                
    while(index > 0 && v[index] > v[(index-1)/2])
    {
        Swap(v[index], v[(index-1)/2]);
        index = (index-1)/2;
    }
}

void build_heap(vector<int>& v)
{
//               
assert(true);
//                                      
    for(int i=0; i < static_cast<int>(v.size()); i++)
        push_up(v, i);
}

void push_down(vector<int>& v, int index, int i)
{
//               
assert(index >= 0 && index < i);
//                                                                                                            

    int child_1 = (2*index)+1;
    int child_2 = (2*index)+2;
    while (child_1 < i && (v[index] < v[child_1] || v[index] < v[child_2]))
    {

        if(child_2 > i)
            {
            if(v[child_1] > v[index])
                {
                Swap(v[index], v[child_1]);
                index = child_1;
                }
            }
        else
        {
        if(v[child_1] >= v[child_2] && v[index] < v[child_1])
            {
             Swap(v[index], v[child_1]);
            index = child_1;
            }
        else if(v[child_2] > v[child_1] && v[index] < v[child_2])
           {

            Swap(v[index], v[child_2]);
            index = child_2;
           }
        }
        child_1 = (2*index)+1;
        child_2 = (2*index)+2;
    }
}

void pick_heap(vector<int>& v)
{
//               
assert(true);
//                                                                   

    Swap(v[0], v[static_cast<int>(v.size())-1]);
    for (int i = static_cast<int>(v.size())-2; i>0; i--)
    {
        push_down(v, 0, i);
        Swap(v[0], v[i]);
    }

}

int main()
{
    vector<int> v = {42, 30, 40, -15, 15, 35, 5};
    build_heap(v);
    for(int i= 0; i < static_cast<int>(v.size()) ; i++)
    {
        cout<< v[i] << '\t';

    }
    cout << endl;
    pick_heap(v);
    for(int i= 0; i < static_cast<int>(v.size()) ; i++)
    {

        cout<< v[i] << '\t';
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/* 
                             
                        
*/

/* 
    
                                                         
                                                                             
                                                              
    
                                                                  
                                                           
                                                                                       
                                                                                       
                                 

    

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

        
         
           
            
             

                    
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     

  
        
                                                                      
                                                                                                
           
                                                                                                   
                 
          
                   
          
                                                                       
                                                                                             
*/

void swap(int& a, int& b){
    //              
    assert(true);
    //                       
    int tmp = a;
    a = b;
    b = tmp;
}
void push_up(vector<int>& vec, size_t index){
    //             
    assert(true);
    //              
    //                                                              
    size_t child = index;
    while(child){
        size_t parent = (child - 1) / 2;
        if(vec[child] > vec[parent])
            swap(vec[child], vec[parent]);
        child = parent;
    }
}
void push_down(vector<int>& vec, size_t heap_end){
    //             
    assert(true);
    //              
    //                                                     
    size_t parent = 0;
    while(true){
        size_t left = parent * 2 + 1;
        size_t right = parent * 2 + 2;

        //                 
        if(left >= heap_end)
            return;

        //                  
        if(right >= heap_end){
            if(vec[parent] < vec[left])
                swap(vec[parent], vec[left]);
            return;
        }

        if(vec[left] > vec[right] && vec[parent] < vec[left]){
            swap(vec[parent], vec[left]);
            parent = left;
        }
        else if(vec[parent] < vec[right]){
            swap(vec[parent], vec[right]);
            parent = right;
        }
        else return;
    }
}
void build_heap(vector<int>& vec){
    //              
    assert(true);
    //              
    //              
    for(size_t i = 0; i < vec.size(); i++)
        push_up(vec, i);
}
void pick_heap(vector<int>& vec){
    //              
    assert(true);
    //              
    //              
    for(int i = vec.size() - 1; i > 0; i--){
        swap(vec[0], vec[i]);
        push_down(vec, i);
    }
}
void heap_sort(vector<int>& vec){
    //              
    assert(true);
    //               
    //              
    build_heap(vec);
    pick_heap(vec);
}

int main()
{
    vector<int> vec = {-5, 0, 2, 11, 14, 29, 30, 30, 42, 51};
    vector<int> vec2 = {
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
        90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    };

    heap_sort(vec);
    heap_sort(vec2);
    for(size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << endl;
    for(size_t i = 0; i < vec2.size(); i++)
        cout << vec2[i] << ", ";
    return 0;
}


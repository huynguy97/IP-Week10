#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                           
//                           

int size(vector<int> v) {
//              
    assert(true);
//                                              
    return static_cast<int>(v.size());
}

void print_vector(vector<int> vector) {
//                  
    assert(true);
//                                     
    for(int i = 0; i < size(vector); i++)
        cout << vector[i] << "\t";
    cout << endl;
}

void swap(int& a, int& b) {
//              
    assert(true);
//                                                           
    const int temp = a;
    a = b;
    b = temp;
}

void push_up(vector<int>& vector, int index) {
//              
    assert(index >= 0 && index < size(vector));
//                                                                                              
    int parent_index = (index-1)/2;
    while(vector[index] > vector[parent_index] && parent_index >= 0) {
        swap(vector[index], vector[parent_index]);
        index = parent_index;
        parent_index = (index-1)/2;
    }
}

void push_down(vector<int>& vector, int max_index) {
//              
    assert(max_index >= 0);
/*                                                                      
                                                                   */
    int index = 0;
    int largest_child = 0;
    while(2*index+2 < size(vector)) {
        if(vector[2*index+1] > vector[2*index+2] || 2*index+2 > size(vector)) {
            largest_child = 2*index+1;
        } else {
            largest_child = 2*index+2;
        }
        if(2*index+2 > max_index) {
            largest_child = 2*index+1;
            if (2*index+1 > max_index) {
                largest_child = index;
            }
        }
        if(vector[index] < vector[largest_child]) {
            swap(vector[index],vector[largest_child]);
            index = largest_child;
        } else {
            index = size(vector);
        }
    }
}

void build_heap(vector<int>& vector) {
//              
    assert(true);
//                                                              
    for(int i = 0; i < size(vector); i++) {
        push_up(vector, i);
    }
}

void pick_heap(vector<int>& vector) {
//              
    assert(true);
/*                                                                                                   
                                           
*/
    int max_index = size(vector)-1;
    while(max_index > 0) {
        swap(vector[0], vector[max_index]);
        max_index--;
        push_down(vector, max_index);
    }
}

void heap_sort(vector<int>& vector) {
//              
    assert(true);   
//                                    
    build_heap(vector);
    pick_heap(vector);
}

int main() {
//              
    assert(true);
/*                                                                    
                                                                   
*/
    vector<int> exampleVector = {15, 40, 42, -15, 30, 35, 5};
    
    print_vector(exampleVector);
    heap_sort(exampleVector);
    print_vector(exampleVector);

    return 0;
}
/*
        
       
                                                         

             
                                                          

        
                               
        
       
         
           
            
             

       
         
           
            
             
     

       
         
           
            
             
     

       
         
           
            
             
     

       
         
           
            
             
     

       
         
           
            
             
     

       
         
           
            
             
     

       
         
           
            
             
     

        
                            
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                       

  
                  
                                                                                                                       

                       
                                                                                                   
                                                                                            

                    
                                                                                                                 
                                                                   

                      
                                                                                                  

                      
                                                                                            
                                                                                                           
*/

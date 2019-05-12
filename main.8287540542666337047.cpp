#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
//                       
//           
//                                                                                  
//                                                                                   
/*
                                                   

                         

                                                   
          
           
             
              
               

                                                    
          
           
             
              
               

                                                      
          
           
             
              
               

                                                    
          
           
             
              
               

                                                   
          
           
             
              
               

                                                   
          
           
             
              
               

                           

                                                                                    
                      

                                                                                                
                      

                                                                              
                      

                                                                                       
                      

                                                                                                 
                      

                                                                                        
                      

                                                                                                   
                      

                                                                                         
                      

                                                                                                     
                      

                                                                                      
                      

                                                                                         
                       

                                          
                                                  
                                          
                                           
                                                                                                                                        
*/

vector<int> arr = {15, 40, 42, -15, 30, 35, 5};
const int size_of_array = arr.size();

void print_arr(vector<int>& arr){
    //             
    assert(true);
    //              
    //                    
    for(int i = 0; i < size_of_array; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
}

void push_up(vector<int>& arr, int el1, int j){
    //             
    assert(j <= size_of_array);
    //              
    //                                                     
    arr[j] = arr[(j-1)/2];
    arr[(j-1)/2] = el1;
}

void swap(vector<int>& arr, int i, int j){
    //             
    assert(i < size_of_array && j < size_of_array);
    //              
    //                                                          
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void push_down(vector<int>& arr, int i){
    //             
    assert(i < size_of_array);
    //              
    //                                                                                        
    for(int j = 0; j < size_of_array; j++){
            int z = (j*2)+1;
            int d1 = 0;
            int d2 = 1;
            if(z+1 < i && arr[z] < arr[z+1]){
                d1 = 1;
                d2 = 0;
            }
            if(arr[j] < arr[z+d1] && z+d1 < i){
                swap(arr, j, z+d1);
                j = z-1;
            } else if(arr[j] < arr[z+d2] && z+d2 < i){
                swap(arr, j, z+d2);
                z = z;
            } else {break;}
        }
}

void pick_heap(vector<int>& arr){
    //             
    assert(true);
    //              
    //                             
    for(int i = size_of_array; i > 0; i--){
        if(arr[0] > arr[i]){
            swap(arr, i, 0);
            push_down(arr, i);
        }
    }
    cout << "Heap is sorted" << endl;
}

void build_heap(vector<int>& arr){
    //             
    assert(true);
    //              
    //               
    for(int i = 1; i < size_of_array; i++){
            for(int j = i; j > 0; j = (j-1)/2){
                if(arr[j] > arr[(j-1)/2]){
                    push_up(arr, arr[j], j);
                } else {
                    break;
                }
        }
    }
    cout << "Heap is build" << endl;
}

int main()
{
    print_arr(arr);
    build_heap(arr);
    print_arr(arr);
    pick_heap(arr);

    cout << "end result" << endl;
    print_arr(arr);
    return 0;
}


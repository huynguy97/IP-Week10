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

void push_up(vector<int>& A, int i) {
    //             
    assert(0 <= i && i < A.size());
    //              
    //                                                                               
    int parent = (i-1)/2;
    if(0 <= parent) {
        while(A.at(parent) < A.at(i)) {
            int temp = A.at(i);
            A.at(i) = A.at(parent);
            A.at(parent) = temp;

            i = parent;
            parent = (i-1)/2;
        }
    }
}

void build_heap(vector<int>& A) {
    //              
    assert(true);
    //               
    //            
    for(int k = 0; k < A.size(); k++){
        push_up(A, k);
    }
}

void swap(vector<int>& A, int last_index){
    //              
    assert(last_index >= 0 && last_index < A.size());
    //                
    //                                                         
    int temp = A.at(last_index);
    A.at(last_index) = A.at(0);
    A.at(0) = temp;
}

void push_down(vector<Track>& A, int last_index) {
    //              
    assert(last_index >= 0 && last_index < A.size());
    //                                    

    int i = 0;
    int ch1 = 2*i + 1;
    int ch2 = 2*i + 2;
    int changeIndex;
    if(A.at(ch1) >= A.at(ch2) || ch2 > last_index)
        changeIndex = ch1;
    else
        changeIndex = ch2;
    while(ch1 <= last_index){
        if(A.at(ch1) >= A.at(ch2) || ch2 > last_index)
            changeIndex = ch1;
        else
            changeIndex = ch2;
        if(A.at(changeIndex) > A.at(i)){
            Track temp = A.at(i);
            A.at(i) = A.at(changeIndex);
            A.at(changeIndex) = temp;
            i = changeIndex;
        }
        else{
            return;
        }
        ch1 = 2*i + 1;
        ch2 = 2*i + 2;
    }
}

void pick_heap(vector<int>& A) {
    //              
    assert(true);
    //               
    //                
    for(int i = A.size() - 1; i > 0; i--){
        swap(A, i);
        push_down(A, i - 1);
    }
}

void heap_sort(vector<int>& A){
    //              
    assert(true);
    //              
    //                
    build_heap(A);
    pick_heap(A);
}

int main()
{
    vector<int> A = {15, 40, 42, -15, 30, 35, 5};
    heap_sort(A);
    for(int i = 0; i < A.size(); i++){
        cout << A.at(i) << " ";
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                        

void display(vector<int> data){
    assert(true);

    //                                                                     
    cout << "[";
    for(int i=0;i<data.size()-1;i++){
        cout<< data[i]<<", ";
    }
    cout << data[data.size()-1] << "]" <<endl;
}

void swap(int a, int b, vector<int>& data){
    assert(a<data.size() && b<data.size());

    //                                                              

    const int temp = data[b];
    data[b] = data[a];
    data[a] = temp;
}

void push_up(vector<int>& data, int& i){
    assert(true);

    //                                                                                                                          

    const int temp = data[(i-1)/2];
    data[(i-1)/2] = data[i];
    data[i] = temp;
    i = (i-1)/2;
}

void push_down(vector<int>& data, int& curr, int bound){
    assert(bound<=data.size());

    //                                                                                                                                                               

    while(true){
        int leftChild = 2*curr+1;
        int rightChild = 2*curr+2;
        if(rightChild>=bound){
            if(leftChild<bound && data[curr]<data[leftChild]) swap(curr,leftChild,data);
            return;
        }

        int biggest = leftChild;
        if(data[rightChild]>data[leftChild]) biggest = rightChild;

        if(data[curr]<data[biggest]) swap(curr,biggest,data);

        curr = biggest;
    }
}

void build_heap(vector<int>& data){
    assert(true);

    //                                                                                                             

    for(int i=1;i<data.size();i++){
        while(data[i]>data[(i-1)/2]){
            push_up(data,i);
        }
    }
}

void pick_heap(vector<int>& data){
    assert(true);

    //                                                                                                                                                                        

    for(int i=data.size()-1;i>0;i--){
        int curr = 0;
        swap(curr,i,data);
        push_down(data,curr,i);
    }
}

void heap_sort(vector<int>& data){
    assert(data.size()>0);

    //                                                          
    build_heap(data);
    pick_heap(data);
}

int main()
{
    vector<int> data = {2,14,30,29,42,30,11,-5,0,51};
    heap_sort(data);
    display(data);
    return 0;
}

/*
       
                         
                                                              
                                                             
                                                              
             

                      
                                                                    
                                                                   
                                                                    
                  

       
          
               
                 
                   
                    
                     

               
                 
                   
                    
                     

               
                 
                   
                    
                     

               
                 
                   
                    
                     

                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   

                                                                                                                   
                                                                  
                                                                                                                                       
                                                               
                                                                                 
                                                                                     
                                                                                                                                                
*/


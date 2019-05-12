/* 
                   
                                   
  
                                        
 */

#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

/*
         
                                                                                                                                        
                                                                                                 
   
          
                      
                        
                          
                             
                             
   
                      
                        
                          
                             
                             
        
                      
                        
                          
                             
                             
 
                      
                        
                          
                             
                             

                      
                        
                          
                             
                             
   
   
                                                                                                                                                                                                                                                                                                                                                                                                      
 */

void swap (vector<int>& data, int  i, int  j )
{//	              
	assert ( i >= 0 && j >= 0 ) ;	//                         
						            //                         
//                                                                
	const int HELP = data [i];
	data [i] = data [j] ;
	data [j] = HELP;
}

int get_parent_index(int i){
    int parent = (i-1)/2;
    if(parent < 0){
        return 0;
    }
    return parent;
}

int get_child_left(vector<int> data, int i){
    int childl = 2*i+1;
    if(childl > data.size()-1 ){
        return -1;
    }
    return childl;
}

int get_child_right(vector<int> data, int i){
    int childr = 2*i+2;
    if(childr > data.size()-1 ){
        return -1;
    }
    return childr;
}

void push_up(vector<int>& data, int i, int parent){
    while(data[i] > data[parent]){
        swap(data, parent, i);
        i = parent;
        parent = get_parent_index(i);
        
    }
}

int biggerchild(int left, int right){
    if(left > right) return left;
    else if(left == right) return left;
    else return right;
}

void push_down(vector<int>& data, int index){
    int leftchild = get_child_left(data, index);
    int rightchild = get_child_right(data, index);
    int maxchild = biggerchild(leftchild, rightchild);
    
    while(data[index] > data[maxchild]){
        swap(data, index, maxchild);
        index = maxchild;
        leftchild = get_child_left(data, index);
        rightchild = get_child_right(data, index);
        maxchild = biggerchild(leftchild, rightchild);
        cout << index << " " << leftchild << " " << rightchild << endl;
    }
}

void build_heap(vector<int>& data, int size){
  
    for(int i = 0; i< data.size()-1; i++){
        push_up(data, i, get_parent_index(i));
    }
}

void pick_heap(vector<int>& data, int size, int index){
    swap(data, index, size);
    push_down(data, index);     
    
}

void heapSort(vector<int>& data, int size) 
{ 
    build_heap(data, size); 
    
    for (int x : data) 
        cout << x << " ";
    cout << endl;
  
    //                                         
    for (int i=size-1; i>=0; i--) 
    {     
        //                                    
        pick_heap(data, i, 0); 
    } 
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    vector<int> data(arr, arr + n); 
    
    heapSort(data, data.size());
    
    for (int x : data) 
        cout << x << " "; 
}


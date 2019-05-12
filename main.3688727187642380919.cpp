/*
                         
                          
 */

#include <iostream>
#include <vector>

using namespace std;

int findParent(int index) {
    return (index - 1) / 2;
}

int findLeftChild(int index) {
    return (index * 2) + 1;
}

void swapElement(vector<int> &arr, int a, int b, int ael, int bel) {
    arr[a] = bel;
    arr[b] = ael;
}

void pushBack(vector<int>& arr, int a, int b) {
    int root = a;

    int leftchild = findLeftChild(root);

    while (leftchild <= b) {
        int child = leftchild;
        int swap = root;
        if (arr[swap] < arr[child]) {
            swap = child;
        }
        if (child + 1 <= b && arr[swap] < arr[child + 1]) {
            swap = child + 1;
        }
        if (swap == root) {
            return;
        } else {
            swapElement(arr, root, swap, arr[root], arr[swap]);
            root = swap;
        }
        leftchild = findLeftChild(root);
    }
}

void pushUp(vector<int>& arr, int a, int b) {
    int child = b;
    while (child > a) {
        int parent = findParent(child);
        if (arr[parent] < arr[child]) {
            swapElement(arr, parent, child, arr[parent], arr[child]);
            child = parent;
        } else {
            return;
        }
    }
}

void buildHeap(vector<int> &arr, int c) {
    int end = 1;

    while (end < c) {
        pushUp(arr, 0, end);
        end++;
    }
}

void printArray(vector<int> arr) {
    cout << endl << "{";

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ",";
    }

    cout << arr[arr.size() - 1];

    cout << "}" << endl;
}

void pickHeap(vector<int>& arr, int end) {
    for (;end > 0; end--) {
        pushBack(arr, 0, end);
        swapElement(arr, end, 0, arr[end], arr[0]);
    }
}

int main() {
    vector<int> arr;

    arr = {15, 40, 42, -15, 30, 35, 5};

    cout << "Input array:" << endl;
    printArray(arr);

    int end = arr.size() - 1;

    buildHeap(arr, end);

    pickHeap(arr, end);

    cout << endl << "Sorted array:" << endl;
    printArray(arr);
}

/*
       
                                       
   
                                                                                                                                                                             
                                                                                                                                                                             
                                                                
                                                                                                                                                                
                                                                                                                                                                                                      
                                                                                                                                                               
                                                                                                                                                                                             
                                                                                                                                                                                                                       
                                                                                                                        
                                                         
                                                                                                
                                                                                
                                                                                    
                                                                                                                                                                                 
   
                                                                                               
                                                                                                                                                              
                                                                                                                                                                    
 */

/*
       

        
                        
             
       
       
        
         
          
           
            

                          
       
       
        
         
          
           
            

                           
       
       
        
         
          
           
            

                          
       
       
        
         
          
           
            

        
                     
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

           
                                                                                                                                              
                                                                                                                                             
                                                                                                                       
                                                               

 */

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*                                                                   
                 
                                 
                              
                                                                   */

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

int size(vector<int> v) { return static_cast<int>(v.size()); }

void swap2(vector<int> &tree, int i1, int i2) {
  assert(i1 >= 0 && i2 >= 0 && i1 < size(tree) && i2 < size(tree));
  //                                                                          
  int temp = tree[i1];
  tree[i1] = tree[i2];
  tree[i2] = temp;
}

void printVector(vector<int> &tree) {
  assert(true);
  //                                                  
  for (int i = 0; i < size(tree); i++) {
    cout << tree[i] << ",";
  }
  cout << endl;
}

void push_up(vector<int> &tree, int index) {
  assert(index >= 0 && index < size(tree));
  //                                                                     
  //                                                      
  do {
    int parentIndex = (index - 1) / 2;
    if (tree[index] > tree[parentIndex]) {
      swap2(tree, index, parentIndex);
    }
    index = parentIndex;
  } while (index != 0);
}

void push_down(vector<int> &tree, int maximum) {
  assert(maximim <= size(tree) && maximium > 0)
      //                                                                  
      //                                                             
      int index = 0;
  do {
    int child1 = (index * 2) + 1;
    int child2 = (index * 2) + 2;
    if (tree[child1] > tree[child2]) {
      //                                     
      if (tree[index] < tree[child1] && child1 < maximum) {
        swap2(tree, child1, index);
      }
      index = child1;
    } else {
      //                                     
      if (tree[index] < tree[child2] && child2 < maximum) {
        swap2(tree, child2, index);
      }
      index = child2;
    }
  } while (index < maximum);
}

void build_heap(vector<int> &tree) {
  assert(true);
  //                                      
  for (int i = 1; i < size(tree); i++) {
    push_up(tree, i);
    printVector(tree);
  }
}

void pick_heap(vector<int> &tree) {
  assert(true);
  //                                                                          
  //                                                                         
  //                                                                           
  //       
  for (int i = size(tree) - 1; i > 0; i--) {
    swap2(tree, 0, i);
    push_down(tree, i);
    printVector(tree);
  }
}

int main(int argc, char const *argv[]) {
  vector<int> v = {15, 40, 42, -15, 30, 35, 5};
  build_heap(v);
  cout << "Heap is build" << endl;
  pick_heap(v);
  cout << "Vector is sorted!" << endl;
  printVector(v);
  return 0;
}


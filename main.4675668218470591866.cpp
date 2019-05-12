/*                                                                    
                                                                      
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*       
                                                                            
                                    
                                                                          
                                                                             
                                                           
 */

/*       
                                        
               
                                                                         
                                                                         
                                                                          
                                                                           
                                                                            
  
               
                                                
                                             
                                             
                                                
                                             
                                                
                                             
                                             
                                                
                                             
                                             
                                                
                                                          
                                                
                                           
  
                         
  	                                                                         
                                                                             
                                                                          
                                                                            
                                                 
 */

void swap(vector<int>& v, int i, int j) {
//                
	assert(i >= 0 && j >= 0);	//                           
						        //                           
//                                                                         
	const int temp = v[i];
	v[i] = v[j] ;
	v[j] = temp;
}

/*                                                                      
 */
void heapify(vector<int>& v, int size, int i) {
//                
    assert(true);
/*                 
                                                                               
                          
*/
    int max = i;
    int lchild = 2 * i + 1;
    int rchild = lchild + 1;                        //        

    if (lchild < size && v[lchild] > v[max]) {
        max = lchild;
    }

    if (rchild < size && v[rchild] > v[max]) {
        max = rchild;
    }

    if (max != i) {
        swap(v[i], v[max]);
        heapify(v, size, max);
    }
}

void build_heap(vector<int>& v, int size) {
//                
    assert(size > 0);
/*                 
                                    
*/
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(v, size, i);
    }
}

void heap_sort(vector<int>& v, int size) {
//                
    assert(size > 0);
/*                 
                                                                 
*/
    for (int i = size - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main() {
    vector<int> data = {4, 5, 3, 0, 6, 9, 1, 0};
    int size = data.size();

    cout << "Data before sorting: " << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;

    build_heap(data, size);
    heap_sort(data, size);

    cout << "Data after sorting: " << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
    return 0;
}


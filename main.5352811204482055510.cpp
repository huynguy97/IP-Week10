#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/*
                             
                         
                           
*/

void push_up(vector<int>& values, unsigned long i) {
    //               
    assert(i < values.size());
    //                
    //                                                                                                    

    for (unsigned long next; i > 0; i = next) {
        next = (i - 1) / 2;

        int value = values[i], parent = values[next];

        if (value > parent) {
            values[next] = value;
            values[i] = parent;
        } else {
            next = 0; //                                                             
        }
    }
}

void build_heap(vector<int>& values) {
    //               
    assert(true);
    //                
    //                                    

    for (unsigned long i = 1; i < values.size(); ++i) {
        push_up(values, i);
    }
}

void swap(vector<int>& values, unsigned long heap_size) {
    //               
    assert(heap_size <= values.size());
    //                
    //                                                                               

    int temp = values[0];

    values[0] = values[heap_size - 1];
    values[heap_size - 1] = temp;
}

void push_down(vector<int>& values, unsigned long heap_size) {
    //               
    assert(heap_size <= values.size());
    //                
    //                                                                                                                    

    unsigned long i = 0;
    for (unsigned long next; i * 2 + 1 < heap_size; i = next) {
        next = i * 2 + 1;

        if (next + 1 < heap_size && values[next + 1] > values[next]) {
            ++next;
        }

        int value = values[i], child = values[next];

        if (value < child) {
            values[next] = value;
            values[i] = child;
        } else {
            next = values.size(); //                                                
        }
    }
}

void print(const vector<int>& values) {
    //               
    assert(true);
    //                
    //                                             

    cout << "{ ";
    for (unsigned long i = 0; i < values.size(); ++i) {
        if (i > 0)
            cout << ", ";
        cout << values[i];
    }

    cout << " }" << endl;
}

void pick_heap(vector<int>& values) {
    //               
    assert(true);
    //                
    //                                                   

    for (unsigned long heap_size = values.size(); heap_size > 1; ) {
        swap(values, heap_size);
        --heap_size;
        push_down(values, heap_size);
    }
}

int main() {
    vector<int> values = { 15, 40, 42, -15, 30, 35, 5 };

    build_heap(values);

    pick_heap(values);

    cout << "Sorted: ";
    print(values);

    return 0;
}

/*
      
                                                                                                      
      
                                                                                                                                   
  
      
                                   
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
            
  
      
                                                                                                                                                             
                                                                                                
                                                      
                           
  
     
            
  
 */


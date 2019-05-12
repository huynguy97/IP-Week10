#include <iostream>
#include <cassert>
#include <vector>
#include <cassert>

using namespace std;

//                            
//                             

int size (vector<int>& vect){
    return static_cast<int>(vect.size());
}

void elm_swap (vector<int>& vect, int elm_id_1, int elm_id_2 ) {
    assert (true);
    //                                                                            
    const int HELP = vect[elm_id_1];
    vect[elm_id_1] = vect[elm_id_2];
    vect[elm_id_2] = HELP;
}

void push_up (vector<int>& vect, int elm_id) {
    assert(elm_id < size (vect));
    //                                                                                                       
    while (vect[elm_id] > vect[(elm_id-1)/2]) {
        elm_swap(vect, elm_id, (elm_id-1)/2);
        elm_id = (elm_id-1)/2;
    }
}

void push_down (vector<int>& vect, int elm_id, int size) {
    assert (elm_id <= size);
    //                                                                                                                          
    bool right_place = false;
    while (!right_place) {
        if (2 * elm_id + 2 <= size) {
            int proper_child_id = 0;
            if (vect[2 * elm_id + 1] > vect[2 * elm_id + 2]){
                proper_child_id = 2 * elm_id + 1;
            } else {
                proper_child_id = 2 * elm_id + 2;
            }

            if (vect[elm_id] < vect[proper_child_id]) {
                elm_swap(vect, elm_id, proper_child_id);
                elm_id = proper_child_id;
            }
            else {
                right_place = true;
            }
        }
        else if (2 * elm_id + 1 <= size) {
            if (vect[2* elm_id + 1] > vect[elm_id]) {
                elm_swap(vect, elm_id, 2*elm_id +1);
                elm_id = 2*elm_id + 1;
            }
            else {
                right_place = true;
            }
        }
        else {
            right_place = true;
        }
    }
}

void build_heap (vector<int>& to_be_heap) {
    assert (true);
    //                                                           
    cout << endl << "Building heap..." << endl << endl;
    for (int i = 1; i < size(to_be_heap); i++){
        if (to_be_heap[i] > to_be_heap[(i-1)/2]){
            push_up(to_be_heap, i);
        }
    }
}

void show_vector (vector<int> vect){
    assert(true);
    //                                                           
    for (int i = 0; i < size(vect); i++){
        cout << vect[i] << " ";
    }
}

void show_vector_with_bar (vector<int> vect, int bar_id){
    assert(true);
    //                                                                                                 
    for (int i = 0; i < size(vect); i++){
        cout << vect[i];
        if (i == bar_id) {
            cout << '|';
        }
        cout << " ";
    }
}

void pick_heap (vector<int>& vect) {
    assert (true);
    //                                         
    cout << endl << "Picking heap..." << endl;
    int sorted_elm_id = size(vect)-1;
    while (sorted_elm_id > 0) {
        cout << endl;
        elm_swap(vect, 0, sorted_elm_id);
        //                                                                                         
        sorted_elm_id = sorted_elm_id - 1;
        push_down(vect, 0, sorted_elm_id);
        show_vector_with_bar(vect, sorted_elm_id);
        cout << endl;
    }
    cout << endl;
    show_vector_with_bar(vect, sorted_elm_id - 1);
    cout << endl << endl;
}

int main()
{
    vector<int> vect = {15, 40, 42, -15, 30, 35, 5, 8, 67, 7, 5, 88};
    build_heap(vect);
    cout << "The heap is:" << endl << endl;
    show_vector(vect);
    cout << endl;
    pick_heap(vect);
    cout << endl;
    cout << endl << "The final (sorted) array is:" << endl << endl;
    show_vector(vect);
    cout << endl;
    return 0;
}

/*

                                                            

                                                                           

                                                                                       

              
                
                  
                   
                    

              
                
                  
                   
                    

              
                
                  
                   
                    

              
                
                  
                   
                    

                                

                                

                                

                                

                                

                                

                                

                                

                                

                                

                                

                                

             

                                                                                                                                                                       
                                                          

                                                                                                                     

                                                                                                                                                                         
                                                            

                                                                                              

*/


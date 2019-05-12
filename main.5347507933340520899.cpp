//                                              

/*        
                                                                         
                                     
                                                                      
                                                                                 
                                           
*/

/*        
                       

                          
              
                  
                    

                                        
                        
              
                  
                    

                        
              
                  
                    

                                         
                        
              
                  
                    

                                        
                                        

                                                      

                           
                           

                        
                           

                          
                           

                        
                           

                          
                           

                        
                           

                          
                           

                         
                           

                           
                           

                        
                           

                                    
                           

            
                                                                                        
                                                            

                                                                                            
                        

              
                                                                                        
                                                            

              
                                                                                                   
                        

              
                                                               
                                                          

                                                                                
                                                                          
*/

//        

#include <iostream>
#include <vector>
#include <cassert>
#include <time.h> //                                            

using namespace std;

int length = 100;

void swap(vector<int>& vec, int i, int j){
    //                
    assert(i >= 0 && i < static_cast<int>(vec.size()) && j >= 0 && j < static_cast<int>(vec.size()));
    //                                                          
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void push_up(vector<int>& vec, int index){
    //                
    assert(index >= 0 && index < static_cast<int>(vec.size()));
    //                                                                                    
    int i = index;
    while (i > 0 && vec[i] > vec[(i-1)/2]){
        swap(vec, i, (i-1)/2);
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& vec){
    //                
    assert(vec.size() > 0);
    //                                                                
    for (int i = 0; i < static_cast<int>(vec.size()); i++){
        push_up(vec, i);
    }
}

void push_down(vector<int>& vec, int index, int sorted){
    //                
    assert(index >= 0 && index < static_cast<int>(vec.size())
        && sorted >= 0 && sorted < static_cast<int>(vec.size()));
    //                                                                                           
    int i = index;
    int child_1;
    int child_2;
    bool done = 2*i+1 >= static_cast<int>(vec.size()); //                                                       
    while (!done){
        if (2*i+1 < sorted){ //                                            
            child_1 = vec[2*i+1];
        } else {
            child_1 = vec[i] - 1;
        }
        if (2*i+2 < sorted){ //                                            
            child_2 = vec[2*i+2];
        } else {
            child_2 = vec[i] - 1;
        }
        if (child_1 > vec[i]){
            if (child_2 > child_1){ //                         
                swap(vec, i, 2*i+2);
                i = 2*i+2;
            } else { //                         
                swap(vec, i, 2*i+1);
                i = 2*i+1;
            }
        } else if (child_2 > vec[i]) { //                         
            swap(vec, i, 2*i+2);
            i = 2*i+2;
        } else { //                                               
            done = true;
        }
        if (2*i+1 >= static_cast<int>(vec.size())){ //                                 
            done = true;
        }
    }
}

bool is_heap(vector<int>& vec){
    //                
    assert(true);
    //                                                
    int vec_size = static_cast<int>(vec.size());
    for (int i = 0; i < vec_size; i++){
        if (2*i+2 < vec_size){
            if (vec[i] < vec[2*i+2]) return false;
        }
        if (2*i+1 < vec_size){
            if (vec[i] < vec[2*i+1]) return false;
        }
    }
    return true;
}

void pick_heap(vector<int>& vec){
    //                
    assert(is_heap(vec));
    //                                
    int i = static_cast<int>(vec.size()) - 1;
    while (vec[0] > vec[i]){
        swap(vec, 0, i);
        push_down(vec, 0, i);
        i--;
    }
}

void heap_sort(vector<int>& vec){
    //                
    assert(vec.size() > 0);
    //                                                
    build_heap(vec);
    pick_heap(vec);
}

vector<int> generate_random_vector(int length) {
    //                
    assert(length > 0);
    //                                                                                 
    vector<int> output;
    srand(time(NULL));
    for (int i = 0; i < length; i++){
        output.push_back(rand()%(2*length) - length);
    }
    return output;
}

int main() {
    vector<int> vector_of_integers = generate_random_vector(length);
    cout << "Original vector:" << endl << endl;
    for (int i = 0; i < static_cast<int>(vector_of_integers.size()); i++){
        cout << vector_of_integers[i] << " ";
    }
    heap_sort(vector_of_integers);
    cout << endl << endl << "Sorted vector:" << endl << endl;
    for (int i = 0; i < static_cast<int>(vector_of_integers.size()); i++){
        cout << vector_of_integers[i] << " ";
    }
    cout << endl;
    return 0;
}


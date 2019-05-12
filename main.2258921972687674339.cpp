/*
                      
                          

       
                                                                                
                                                                
                                                                              
                                                                            

       
  
          
            
             
              
               

          
            
             
              
               

          
            
             
              
               

          
            
             
              
               

          
            
             
              
               

          
            
             
              
               

          
            
             
              
               

                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             

  
                        
                            
                        
                            

                            

*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> vec = {-5, 10, 23, -4, 0, 6};
const int SIZE = vec.size();

void print(){
//               
    assert(true);
//                                                

    cout << "{";
    for(int i = 0; i < SIZE; i++){
        cout << vec[i];
        if(i + 1 != SIZE)
            cout << ", ";
    }
    cout << "}" << endl;
}

void swapper(int index1, int index2){
//                                          
    assert(index1 >= 0 && index2 >= 0 && index1 < SIZE && index2 < SIZE);
//                                                                       

    int temp = vec[index1];
    vec[index1] = vec[index2];
    vec[index2] = temp;
}

bool parent_smaller(int index){
//               
    assert(true);
//                                                                          

    return vec[index] > vec[(index - 1) / 2];
}

void push_up(int index){
//               
    assert(true);
//                                                                                        

    while(parent_smaller(index)){
        swapper(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void build_heap(){
//               
    assert(true);
//                                        

    for(int i = 1; i <SIZE; i++){
        push_up(i);
    }
}

int biggest_child(int index, int unsorted){
//               
    assert(true);
//                                                                     

    if(index * 2 + 1 < unsorted){
        if(index * 2 + 2 < unsorted){
            if(vec[index * 2 + 1] > vec[index * 2 + 2])
                return index * 2 + 1;
            else
                return index * 2 + 2;
        }

        return index * 2 + 1;
    }

    return false;
}

bool child_bigger(int indexParent, int indexChild){
//               
    assert(true);
//                                                                     

    return vec[indexParent] < vec[indexChild];
}

void push_down(int unsorted){
//               
    assert(true);
//                                                               

    int index = 0;
    int indexChild = biggest_child(index, unsorted);

    while(indexChild && child_bigger(index, indexChild)){
        swapper(index, indexChild);
        index = indexChild;
        indexChild = biggest_child(index, unsorted);
    }
}

void pick_heap(){
//               
    assert(true);
//                               

    int unsorted = SIZE;

    while(unsorted > 0){
        swapper(0, unsorted - 1);
        unsorted--;
        push_down(unsorted);
    }
}

int main()
{
    build_heap();
    pick_heap();
    print();

    return 0;
}


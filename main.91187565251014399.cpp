//                        
//                     

#include <iostream>
#include <cassert>

using namespace std;

const int LENGTH = 7;

void show_array(int A [LENGTH]){
    //              
    assert(true);
    //                                                

    for (int i=0; i<LENGTH; i++) cout << A [i] << ", ";
    cout << endl;
}

void switches (int A[LENGTH], int one, int two){
    //                                                       
    assert(one >= 0 && two >= 0 && one < LENGTH && two < LENGTH);
    //                                                      

    const int HELP = A[one];
    A[one] = A[two];
    A[two] = HELP;
}

void push_up(int A[LENGTH], int index){
    //                                                
    assert( 0 <= index && index <LENGTH );
    //                                                                             

    int parent = (index - 1)/2;
    while (A[parent] < A[index] && index != 0){
        switches(A, parent, index);
        index = parent;
        parent = (index-1)/2;
    }

}

void build_heap(int A[LENGTH]){
    //             
    assert(true);
    //                                      

    for (int i=0; i<LENGTH; i++) push_up(A, i);

}

void push_down (int A[LENGTH], int unsorted_length){
    //                                                           
    assert(unsorted_length > 0 && unsorted_length <= LENGTH);
    //                                                                                  

    int index = 0;

    bool swapped = true;

    while(swapped){
        swapped = false;
        int child1 = 2*index +1;
        int child2 = 2*index +2;

        if (child1 < unsorted_length && child2 < unsorted_length){
            int maxchild;
            if (A[child1] > A[child2]) maxchild = child1;
            else maxchild = child2;
            if ( A[maxchild] > A[index] ){
                swapped = true;
                switches(A, maxchild, index);
                index = maxchild;
            }

        }
        else if (child1 < unsorted_length){
            if (A[child1] > A [index]){
                swapped = true;
                switches(A, child1, index);
                index = child1;
            }

        }

    }

}

void pick_heap(int A[LENGTH]){
    //             
    assert(true);
    //                                   

    int unsorted_length = LENGTH;

    while(unsorted_length != 1){
        switches(A, 0, unsorted_length-1);
        unsorted_length--;
        push_down(A, unsorted_length);
    }

}

int main()
{
    int test [LENGTH]={15, 40, 42, -15, 30, 35, 5};

    show_array(test);

    build_heap(test);
    pick_heap(test);

    show_array(test);

    return 0;
}

/*
       
                                                                                                                    
                                                                                                     

       
   
                
           
            
                  
                
                     
              

                       
            
                  
                
                     
              

                       
            
                  
                
                     
              
                                         
                       
            
                  
                
                     
              
                                           

                                    
                                        
                                        
                                    
                                        
                                    
                                         
                                    
                                          
                                    
                                   
                            
   
                                                                                                                             

                                                                                                                   

                                                                                                                                 

                                                                                                                    

*/


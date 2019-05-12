#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void print_vector(vector<int> numbers)
{
    //             
    assert(true);
    //              
    //                                             
    for (int i =0; i < numbers.size(); i++){
        cout << numbers[i] << ", ";
    }
}

void swap ( vector<int>& numbers, int a, int b) {
    //             
    assert (true);
    //              
    //                                

    //                                                                                                                         
    int c = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = c;
}

void push_up(vector<int>& numbers, int i){
    //              
    assert (i >= 0);

    //               
    //                                                        

    while (numbers[i] > numbers[((i-1)/2)] ){

            //                                                                                                                                            
        swap(numbers, i , ((i-1)/2) );

    }
}

void build_heap(vector<int>& numbers)
{
    //              
    assert (true);
    //              
    //                                                      

    for (int i = 1; i <= numbers.size(); i++)
    {
        push_up(numbers,i);

        //                                         
    }
}

void push_down(vector<int>& numbers, int last){
    //             
    assert(true);
    //              
    //                                                                                           
    //                                                               
    int current = 0;
    int child1 = (2*current) + 1;
    int child2 = (2*current)  + 2;
    while (child1 <= last){
        //                                                                                          
        int biggest_child = child1;
        if (child2 <= last && numbers[child2] > numbers[biggest_child]){
            biggest_child = child2;
        }
        if (numbers[biggest_child] > numbers[current] ){
            //                                                                                                    
            swap(numbers, current, biggest_child);
            current = biggest_child;
            child1 = (2*current) + 1;
            child2 = (2*current)  + 2;
        } else {
            child1 = numbers.size() + 1;
        }
    }
}

void pick_heap(vector<int>& numbers) {
    //            
    assert(true);
    //              
    //                                                                    
    int last = numbers.size() - 1;
    while (last > 0 ){

        swap(numbers, 0,last);
        last--;
        push_down(numbers, last);

        //                       
    }
}

void heap_sort(vector<int>& numbers) {
    //             
    assert(true);
    //              
    //                               
    build_heap(numbers);
    pick_heap(numbers);
}

int main()
{
    vector <int> numbers  = {15, 40, 42, -15, 30, 35, 5};

    heap_sort(numbers);
    print_vector(numbers);
    return 0;
}

/*
                                                                                                                    
                                                                                  

   

                         
 
              
              
                  
                    
                     

 
              
              
                  
                    
                     

 
              
              
                  
                    
                     

 
              
              
                  
                    
                     

                           

                                 
                               
                               
                               
                               
                               
                               
                               
                               
                                

                        
                              
                         
                             
                                                                                               
*/


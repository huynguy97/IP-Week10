#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
string boop = "boop";

/*
                                                           

      
  
                                                                                                         
                                                                                

  
                                                                        
                                                                   

      
  
                                                                                                                                                    
                                                                                                                                                           
                                                                                                                                                                 

                                                                                                             
                                                                                                                      
                                                                                                                         

        
                                                                                                  
                                                                                                  
                                                                                                  
                                                                                                  
                                                                                                  
                                                                                              

  
        	                                                                                                           
           	                                                            
         	                                                                                                                    
                                                                                        
          	                                                                      

         	                                                                                          
                                           
                                                                                                          
                                                                                                                   
                                                             
	  
*/

void push_up(vector <int>& vec, int i){
    assert(true);
    /*
                                                                   
    */
    int temp;
    temp = vec[(i-1)/2];
    vec[(i-1)/2] = vec[i];
    vec[i] = temp;

}

void build_heap(vector <int>& vec){
    assert(true);
    /*
                                                                        
    */
    for(int i = 0; i < vec.size(); i++){
        while(i != 0 && vec[i] > vec[(i-1)/2]){
            push_up(vec, i);
            i = (i-1)/2;
        }
    }
}
void display(vector <int>& vec){
    assert(true);
    /*
                                    
    */
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl << endl;
}
void swap(vector <int>& vec, int i, int max_i){
    assert(true);
    /*
                                                                            
    */
    int temp;
    temp = vec[max_i];
    vec[max_i] = vec[i];
    vec[i] = temp;
}

void push_down(vector <int>& vec, int max_i){
    assert(true);
    /*
                                                                                                                    
    */
    int i = 0;
    bool done = false;
    while (!done)
    {
        int choice = i;
        if( 2*i + 1 < max_i)
        {
            if(vec[i]<vec[2*i+1])
            {
                choice=2*i+1;
            }
        }
        if(2*i+2<max_i)
        {
            if(vec[i]<vec[2*i+2] && vec[2*i+1]<vec[2*i+2])
            {
                choice=2*i+2;
            }
        }
        if(choice!=i) swap(vec,i,choice);
        else
        {
            done = true;
        }
        i = choice;
    }
}

void pick_heap(vector <int>& vec){
    assert(true);
    /*
                                                                                         
    */
    int max_i = vec.size() - 1;
    while(max_i > 0){
        swap(vec, 0, max_i);
        push_down(vec, max_i);
        display(vec);
        max_i --;
    }
}

void heapsort(vector <int>& vec){
    assert(true);
    /*
                                                                                                        
    */
    vector <int> sorted;
    build_heap(vec);
    cout << "Built Heap: ";
    display(vec);
    pick_heap(vec);
}

int main()
{
    vector <int> vec = {15, 40, 42, -15, 30, 35, 5};
    cout << "Starting heap: ";
    display(vec);
    heapsort(vec);
    cout << "Sorted heap: ";
    display(vec);
    return 0;
}


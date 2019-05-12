/*         
                                                                                    
                                                                                  
                                                                                           

                                                                                            
                                                                        
*/

/*         
                                                                               
                  
                   
                     
                      
                       
                                                                        
                         
      
                  
                   
                     
                      
                       
      
                  
                   
                     
                      
                       
                         
      
                  
                   
                     
                      
                       
                         
                         
                                                           
                                                                                     
                                                                                          
             
                 
                   
                     
                      
                        

                  
                   
                    
                      
                        

                  
                   
                     
                      
                        
                                                                               
                 
                   
                     
                      
                        

                  
                   
                    
                      
                        
                                                                          
                  
                   
                    
                      
                        

                  
                   
                    
                      
                        
                                                                          
                  
                   
                    
                      
                        

                  
                   
                    
                      
                        
                                                                                  
                                                                              
                 
                   
                     
                      
                        

                                                        
                  
                   
                     
                      
                        
                            

                                                                                      
                                                                                           
                                                                                                 
                                                                                                  
                                                                                                            
                                                                                                     
                                                                                            
                                                
                                                                                                    
                                                                                                  
                   
                                                                                                              
                                                                                                           

*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void print_vector(vector<int>& number_list)
{
    //            
    assert(true);
    /*               
                                                                                                           
                                     
    */
    for(unsigned int i=0; i < number_list.size(); i++){
        cout << number_list[i] << ' ';
    }
    cout << endl;
}

void swap_numbers(int position_1, int position_2, vector<int>& number_list)
{
    //            
    assert( 0 <= position_1 && position_1 < number_list.size() );
    assert( 0 <= position_2 && position_2 < number_list.size() );
    assert( position_1 != position_2 );
    /*               
                                                                                                        
                         
    */
    int help = number_list[position_1];
    number_list[position_1] = number_list[position_2];
    number_list[position_2] = help;
}

void push_up(int position, vector<int>& number_list)
{
    //            
    assert( 0 <= position && position < number_list.size());
    /*               
                                                                                                         
                                                                                                 
    */
    //                                                                      
    while(number_list[position] > number_list[(position-1)/2]){
        swap_numbers(position, (position-1)/2, number_list);
        position = (position-1)/2;
    }
}

void push_down(int position, vector<int>& number_list, int max_index)
{
    //            
    assert( 0 <= position && position < max_index);
    assert( 0 <= max_index && max_index < number_list.size() );
    /*               
                                                                                                           
                           
    */
    //                                                                              
    while(true){
        //                                                                         
        if(position*2 + 2 < max_index){
            //                                
            if(number_list[position*2 + 2] > number_list[position*2 + 1]){
                //                                                                                    
                if(number_list[position*2 + 2] > number_list[position]){
                    swap_numbers(position, position*2 + 2, number_list);
                    position = position*2 + 2;
                //                                                                                        
                //                                                                       
                } else{
                    return;
                }
            //                                                                                                  
            //                                  
            } else if(number_list[position*2 + 1] > number_list[position]){
                swap_numbers(position, position*2 + 1, number_list);
                position = position*2 + 1;
            //                                   
            } else{
                return;
            }
        //                                     
        } else if(position*2 + 1 < max_index){
            //                                                 
            //                               
            if(number_list[position*2 + 1] > number_list[position]){
                swap_numbers(position, position*2 + 1, number_list);
                position = position*2 + 1;
            //                                                                          
            } else{
                return;
            }
        //                               
        } else{
            return;
        }
    }
}

void build_heap(vector<int>& number_list)
{
    //            
    assert(true);
    /*               
                                                         
    */
    for(unsigned int i = 0; i<number_list.size(); i++){
        push_up(i, number_list);
    }
}

void pick_heap(vector<int>& number_list)
{
    //            
    assert(true);
    //                                                      
    /*               
                                  
    */
    for(int i = number_list.size() - 1; i > 0; i--){
        swap_numbers(0, i , number_list);
        push_down(0, number_list, i);
    }
}

void heap_sort(vector<int>& number_list)
{
    //            
    assert(true);
    /*               
                                  
    */
    build_heap(number_list);
    pick_heap(number_list);
}

int main()
{
    vector<int> number_list = {15, 40, 42, -15, 30, 35, 5};
    heap_sort(number_list);
    print_vector(number_list);
    vector<int> number_list2 = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
    heap_sort(number_list2);
    print_vector(number_list2);
}


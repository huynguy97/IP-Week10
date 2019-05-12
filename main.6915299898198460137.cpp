#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>

using namespace std;

void print(const vector<int>& to_sort)
{
    cout << "    " << to_sort[0] << endl ;
    cout << "   /   \\" << endl ;
    cout << "  " << to_sort[1] << "    " << to_sort[2] << endl ;
    cout << " / \\   / \\" << endl ;
    cout << to_sort[3] << " " << to_sort[4] << " " << to_sort[5] << " " << to_sort[6] <<  endl ;
}

ostream& operator<< (ostream& out, const vector<int>& vec)
{
    print (vec);
    return out;
}

int parent_of(int index)
{//            
    assert(index >= 0);
//             
//                                                    

    return (index - 1) / 2;
}

void push_up(vector<int>& to_sort, int at_index)
{//            
    assert(at_index > 0);
//             
//                                              
    int parent = parent_of(at_index);

    if(to_sort[parent] < to_sort[at_index])
        swap(to_sort[parent], to_sort[at_index]);

    if(parent > 0)
        push_up(to_sort, parent);
}

void push_down(vector<int>& to_sort, int at_index, int heap)
{//            
    assert(true);
//             
//                                                  

    int child1 = (2 * at_index) + 1;
    int child2 = (2 * at_index) + 2;

    if(child1 < heap)
    {
        if(child2 < heap && to_sort[child1] < to_sort[child2])
        {
            swap(to_sort[at_index], to_sort[child2]);
            //                        
            push_down(to_sort, child2, heap);
        }
        else if(to_sort[at_index] < to_sort[child1])
        {
            swap(to_sort[at_index], to_sort[child1]);
            //                        
            push_down(to_sort, child1, heap);
        }
    }
}

void build_heap(vector<int>& to_sort)
{//            
    assert(true);
//             
//                

    int size_vector = to_sort.size();

    for(int i = 0; i < size_vector; i++)
    {
        if(i != 0)
        {
            if(to_sort[parent_of(i)] < to_sort[i])
                push_up(to_sort, i);
        }
        //                        
    }
}

void pick_heap(vector<int>& to_sort)
{//            
    assert(true);
//             
//                                                       

    int size_vector = to_sort.size();

    for(int i = size_vector -1; i > 0; i--)
    {
        swap(to_sort[i], to_sort[0]);
        //                        
        push_down(to_sort, 0, i);
    }
}

//                                                    
//                                                    

int main()
{
    vector<int> to_sort = {15, 40, 42, -15, 30, 35, 5};

    cout << to_sort << endl;

    build_heap(to_sort);
    pick_heap(to_sort);

    cout << to_sort << endl;

    return 0;
}

/*
       
                    
                                                                                            

                          
                                                                                                              
                            

       

  

          

       
         
           
           
            

       

       
         
           
           
            

       

       
         
           
           
            

       

       
         
           
           
            

       

       
         
           
           
            

         
    

                            

         

                            

         

                            

    

                            

         

                            

    

                            

         

                            

    

                            

         

                            

    

                            

                     
    

                            

                

                            

  

        
                                                                                
                                                                              
                                                                                   
                                                                       

           
                                                              
                                                                               
                                                                

          
                                                                                
                                                                                
                                                                                     
                                                                                        
                                      
                                                          

          
                                                               
                                                                                 
                                                                

          
                                                                                   
                                                                          
*/


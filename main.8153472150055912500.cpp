//                                      
//                                       

/*       
                                                                                                                
                                 
                                                                                                                         
                  
*/

/*       
          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

          
           
            
              
              
               
                

                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void read_vector(vector<int>& v)
{
    //              
    assert(true);
    /*
                   
                                                               
                                                                                      
    */

    int number_of_el, el;

    cin>>number_of_el;

    while (number_of_el > 0)
    {
        cin>>el;
        v.push_back(el);
        number_of_el--;
    }
}

int size (vector<int>& v)
{
    //              
    assert(true);
    /*
                   
                                                         
    */

    return static_cast<int> (v.size ());
}

//                                                                                                         
void push_up (vector<int>& v, int i)
{
    //              
    assert(i - 1 >= 0);
    /*
                   
                                                                                                                  
                                                      
    */

    while(i - 1 >= 0 && v[i] >= v[(i - 1) / 2])
    {
        const int VALUE = v[i] ;
        v[i] = v [( i - 1) / 2] ;
        v [( i - 1) / 2] = VALUE ;
        i = (i - 1) / 2 ;
    }
}

//                                                                                                                    
void build_heap (vector<int>& v)
{
    //              
    assert(true) ;
    /*
                   
                                                              
    */

    for (int i = 1 ; i < size(v) ; i++)
        push_up(v, i);
}

void swap_elements (vector<int>& v, int i)
{
    //              
    assert(i <= size(v)) ;
    /*
                   
                                                                                                 
    */

    const int VALUE = v[0] ;
    v[0] = v[i] ;
    v[i] = VALUE ;
}

bool maximum (int a, int b)
{
    //              
    assert(true);
    /*
                   
                                                                      
    */

    return a>b;
}

//                                                                                                                                           
//             
void push_down (vector<int>& v, int i)
{
    //              
    assert(i <= size(v));
    /*
                   
                                                                                             
                                             
    */

    int index = 0;

    while (index < (i-1)/2 && (v[index] < v[2*index + 1] || v[index] < v[2*index + 2]))
        if (maximum(v[2*index + 1], v[2*index + 2]) == 1)
        {
            const int VALUE = v[index] ;
            v[index] = v[2*index + 1] ;
            v[2*index + 1] = VALUE ;
            index = 2*index + 1 ;
        }
        else
        {
            const int VALUE = v[index] ;
            v[index] = v[2*index + 2] ;
            v[2*index + 2] = VALUE ;
            index = 2*index + 2 ;
        }
}

//                                                                                          
void pick_heap(vector<int>& v)
{
    //              
    assert(true);
    /*
                   
                                 
    */

    int length = size(v);

    while(length - 1 > 0)
    {
        swap_elements(v, length - 1);
        length--;
        push_down(v, length - 1);
    }
}

int main()
{
    vector<int> heap;

    read_vector(heap);
    build_heap(heap);
    pick_heap(heap);

    for(int i = 0 ; i < size(heap) ; i++)
        cout << heap[i] << " " ;

    return 0;
}


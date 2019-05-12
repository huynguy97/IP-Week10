#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <math.h>

using namespace std;

vector<int> number_list = {15, 40, 42, -15, 30, 35, 5};
//     
int list_size () { return number_list.size(); }

//    
void swap (int index_i, int index_j, vector<int>& number_list) { swap(number_list[index_i], number_list[index_j]); }

//    
int parent (int index)
{//              
    assert(0 <= index & index <= list_size());
  /*               
                               
  */
    return max(int(floor((index-1)/2)), 0 );
}

//    
vector<int> children (int index, int heap_size)
{//              
    assert(0 <= index & index <= heap_size);
  /*               
                                                              */
    vector<int> children (0);
    if (2*index+1 < heap_size)
    {
        children.push_back(2*index+1);
        if (2*index+2 < heap_size)
            children.push_back(2*index+2);
    }
    return children;
}

//    
bool has_childs (int index, int heap_size)
{//              
    assert( 0 <= index & index <= heap_size);
  /*               
                                              */
    return (children(index, heap_size).size() > 0);
}

//    
bool has_bigger_childs (vector<int> number_list, int index, int heap_size)
{//              
    assert(has_childs(index, heap_size));
  /*               
                                                                     */
    if (children(index, heap_size).size() == 2)
        return number_list[index] < number_list[children(index, heap_size)[0]] || number_list[index] < number_list[children(index, heap_size)[1]];
    else
        return number_list[index] < number_list[children(index, heap_size)[0]];
}

//    
void print_vector( vector<int> number_list )
{//              
    assert(list_size() > 0);
  /*               
                                                                 
     */
    cout << '{';
    for (int i=0; i<number_list.size(); i++)
    {
        cout << number_list[i];
        if (i < list_size()-1)
            cout << ", ";
    }
    cout << '}' << endl;
}

//    
void show_heap (vector<int> number_list)
{ //              
    assert(list_size() > 0);
  /*               
                                                  
  */
    cout << "- - - - -" << endl;
    cout << number_list[0] << endl;
    for (int i = 0; i < list_size(); i = (i * 2) + 2)
    {
        for (int j = 0; j < (i * 2) + 2; j++)
            if (i+j+1 < list_size())
                cout << number_list[i+j+1] << ' ';
        cout << endl;
    }
    cout << "- - - - -" << endl;
}

//                             
void push_up (vector<int>& number_list, int& index)
{ //              
    assert(list_size() > 0 & 0 <= index & index < list_size());
  /*               
                                                                                                           
  */
    while (number_list[index] > number_list[parent(index)])
    {
        swap(index, parent(index), number_list);
        index = parent(index);
        show_heap(number_list);
    }
}

//                                                                                        
void push_down (vector<int>& number_list, int heap_size)
{ //              
    assert(list_size() > 0 & 0 <= heap_size & heap_size < list_size());
  /*               
                                                                                                          
  */
    int index = 0;
    while ( has_childs(index, heap_size) && has_bigger_childs(number_list, index, heap_size) )
    {
        int child = children(index, heap_size)[0];
        if (number_list[children(index, heap_size)[0]] < number_list[children(index, heap_size)[1]])
        {
            child = children(index, heap_size)[1];
        }

        swap(index, child, number_list);
        index = child;
    }
}

//     
void build_heap (vector<int>& number_list)
{  //              
    assert(list_size() > 0);
  /*               
                                 
  */
    for (int i=0; i < list_size(); i++)
    {
        push_up(number_list, i);
    }
}

//     
void pick_heap (vector<int>& number_list)
{  //              
    assert(list_size() > 0);
  /*               
                                
  */
    for (int i=0; i < list_size(); i++)
    {
        swap(0, list_size()-1-i, number_list);
        print_vector(number_list);
        push_down(number_list, list_size()-1-i);
    }
}

//     
int main()
{//              
    assert(true);
  /*               
                                               
  */
    cout << "initial setup :" << endl;
    print_vector(number_list);
    show_heap (number_list);
    cout << "build heap" << endl;
    build_heap(number_list);
    cout << "pick heap" << endl;
    print_vector(number_list);
    pick_heap(number_list);
    cout << "sorted list: "; print_vector(number_list);

    return 0;
}

/*
        
                                                                                                    
        
                                                                                                          

        
               
                            
         
        
          
           
         
          
         
  
     
           
         
         
  
     
           
         
         
  
     
           
         
         
                            
                            
                            
                            
                            
                            
                            
                            
                                         
*/


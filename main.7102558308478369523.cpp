#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
                                                  

                                  
                                                

                                                  

                                          
                                          

                                                  
*/

/*
                                                    
 
                                                                                               
                                             
 
                                                                                              
                                                                             
 
                                                                                        
                                                                                       
                        
 
                                                                                                  
                                                                                                    
                                                                            
 
 
                                   
 
                                                      
 
               
                                                                                
                                                                                 
                                                                                  
                                                                                    
                                                                                    
                                                                                     
 
               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
 
                                                                                           
                                                                                             
                                                                                           
 
                                                                                             
                                                                                          
 
                                                                                             
                                                                                          
                                                                                               
 
                                                                                           
                                                                                            
 
                                                                                      
                                                                                    
                                                                    
                             
                                                           
*/

typedef int El;

int size(vector<El>& v)
{   //              
    assert(true);
    //                
    //                                             
    return static_cast<int>(v.size());
}

void swap(vector<El>& v, int index_1, int index_2)
{   //              
    assert(index_1 >= 0 && index_1 < size(v) && index_2 >= 0 && index_2 < size(v));
    //                
    //                                                            
    El HELP = v[index_1];
    v[index_1] = v[index_2];
    v[index_2] = HELP;
}

int parent_index(int index)
{   //              
    assert(index > 0);
    //                
    //                                                              
    return (index - 1)/2;
}

void push_up(vector<El>& v, int index)
{   //              
    assert(index > 0 && index < size(v));
    //                
    //                                                                                                       

    int index_parent = parent_index(index);
    while (v[index] > v[index_parent] && index > 0)
    {
        swap(v, index, index_parent);
        index = index_parent;
        if (index > 0)
            index_parent = parent_index(index);
    }
}

void build_heap(vector<El>& v)
{   //              
    assert(true);
    //                
    //                                                                                                         
    int v_size = size(v);

    for (int i=1; i<v_size; i++)
        push_up(v, i);
}

int greatest_child_index(vector<El>& v, int index, int max_search_index)
{   //              
    assert(index >= 0 && index < size(v) && max_search_index < size(v) && max_search_index >= 0);
    //                
    //                                                                      
    //                                                                    
    int child_index_1 = 2*index + 1;
    int child_index_2 = 2*index + 2;

    int output = -1;

    if (child_index_1 <= max_search_index && child_index_2 <= max_search_index)
    {
        if (v[child_index_1] > v[child_index_2])
            output = child_index_1;
        else
            output = child_index_2;
    } else {
        if (child_index_1 <= max_search_index)
            output = child_index_1;

        if (child_index_2 <= max_search_index)
            output = child_index_2;
    }

    return output;
}

void push_down(vector<El>& v, int index, int max_search_index)
{   //              
    assert(index >= 0 && index < size(v) && max_search_index < size(v) && max_search_index >= 0);
    //                
    //                                                                                                                                              

    int index_greatest_child = greatest_child_index(v, index, max_search_index);
    while (index_greatest_child > 0 && v[index] < v[index_greatest_child] && index <= max_search_index)
    {
        swap(v, index, index_greatest_child);
        index = index_greatest_child;
        if (index <= max_search_index)
            index_greatest_child = greatest_child_index(v, index, max_search_index);
    }
}

void pick_heap(vector<El>& v)
{   //              
    assert(true);
    //                
    //                                                          
    //                                                                                                                                                                    

    for (int max_search_index = size(v)-1; max_search_index > 0; max_search_index--)
    {
        swap(v, 0, max_search_index);
        push_down(v, 0, max_search_index-1);
    }
}

ostream& operator<< (ostream& out, vector<El>& v)
{//               
    assert (true) ;
/*                 
                                                           
*/
    int v_size = size(v);
    out << '{';
    for (int i=0; i<v_size; i++)
    {
        out << v[i];
        if (i < (v_size-1))
            out << ',';
    }
	out << '}';
	return out ;
}

int main()
{
    vector<El> v = {37, 42, 3, 2, 1, 0}; //                                        

    cout << "Welcome to the heap sorting machine!" << endl << endl;
    cout << "Sorting the following vector using heap sort: " << v << endl << endl;
    build_heap(v); //        
    cout << "The vector after phase 1: " << v << endl << endl;
    pick_heap(v); //        
    cout << "The vector after phase 2: " << v << endl;
    return 0;
}


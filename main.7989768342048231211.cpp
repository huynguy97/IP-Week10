/*
                                                      
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

int parent (int i)
{
    //               
    assert (i >= 0);
    //                                                                

    if (i > 0)
        return (i-1) / 2;
    else
        return i;
}

int left_child (vector<int>& input, int i, int tree_size)
{
    //               
    assert (i >= 0);
    //                                                                

    int child = 2 * i + 1;

    if (child >= tree_size)
        return i;
    else
        return child;
}

int right_child (vector<int>& input, int i, int tree_size)
{
    //               
    assert (i >= 0);
    //                                                                

    int child = 2 * i + 2;

    if (child >= tree_size)
        return i;
    else
        return child;
}

int max_child (vector<int>& input, int i, int tree_size)
{
    //               
    assert (i >= 0 && tree_size > 0);

    //                                                                                              

    if (input[left_child(input, i, tree_size)] > input[right_child(input, i, tree_size)])
        return left_child(input, i, tree_size);
    else
        return right_child(input, i, tree_size);
}

void swap (vector<int>& data, int  i, int  j)
{
    //               
	assert (i >= 0 && j >= 0);
    //                                                                 

	const int HELP = data[i];
	data[i] = data[j];
	data[j] = HELP;
}

void build_heap (vector<int>& input)
{
    //               
    assert (true);
    //                                                                                                                                          

    for (int i = 0; i < input.size(); i++)
    {
        int j = i;

        while (input[j] > input[parent(j)])
        {
            swap (input, j, parent(j));
            j = parent(j);
        }
    }
}

void push_down (vector<int>& input, int tree_size)
{
    //               
    assert (tree_size > 0);
    //                                                                                                      

    int i = 0;

    int largest_child = max_child(input, i, tree_size);

    while (input[i] < input[largest_child])
    {
        swap(input, i, largest_child);
        i = largest_child;
        largest_child = max_child(input, i, tree_size);
    }
}

void pick_heap (vector<int>& input)
{
    //               
    assert (true);
    //                                                                                                                             

    int n = input.size() - 1;

    swap(input, 0, n);

    while (n > 1)
    {
        push_down(input, n);
        n--;
        swap(input, 0, n);
    }
}

void display_array (vector<int> input)
{
    //               
    assert (true);
    //                                                                              

    cout << "{" << input[0];

    for (int i = 1; i < input.size(); i++)
        cout << ", " << input[i];

    cout << "}" << endl;
}

int main()
{
    //                                                     
    vector<int> intvector = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};

    build_heap(intvector);

    pick_heap(intvector);

    display_array(intvector);

	return 0;
}

/*
                                                                                                                                       
                                                                                                                            

                                  
                 
        
        
          
           
           

                          
    
        
        
          
           
           

    
        
        
          
           
           

    
        
        
          
           
           

    
        
        
          
           
           

    
        
        
          
           
           

    
        
        
          
           
           

    
        
        
          
           
           

                          
                                            
                  
                            
                         

                             
                        
                                                       
                        
                        

                    
                        
                         

                             
                    
                                                       
                    

                    
                    
                         

                             
                
                                                        
                

                    
                
                         

                             
            
                                                         
            

                    
            
                         

                             
        
                                                       
        

                    
        
                        
                         
                                          

                                                                                                     
                                                                                                                        
                                                                                                      
                                                                                                                                                                                
                                                                                  
*/


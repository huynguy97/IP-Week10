#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#define NDEBUG

using namespace std;

//                          
//                            
//                          

//       
/*             
                                                                   
                                                                           
                                          
  
                 
                                                        
                                                                                                    
                                                                                         
                                        
 */

//       
/*   
                  
                                                    
                      
   		   
   	         
              
               
                
  
                           
    	   
   	         
              
               
                
  
    	   
   	         
              
               
                
  
    	   
   	         
              
               
                
  
    	   
   	         
              
               
                
  
                        
  
                  
                    
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
  
                                                                            
                                                                          
                                                                           
                                                                         
  
                                                             
                                     
 */

vector<int> heap = {15, 40, 42, -15, 30, 35, 5};

#include <cassert>
void print_vector()
{
	//             
	assert(true);
	//              
	//                                 
	int size = heap.size();
	for(int i = 0; i < size; i++)
	{
		cout << heap[i] << ",";
	}
	cout << endl;
}

void push_up(int child_location)
{ //              
	assert (true);
  //                                                                                                            
	int parent_location = ((child_location - 1) / 2);

	if(parent_location < 0)
	{
		return;
	}

	int parent = heap[parent_location];
	int child = heap[child_location];

	while(child > parent)
	{
		heap [child_location] = parent;
		heap [parent_location] = child;

		child_location = parent_location;
		parent_location = ((child_location - 1) / 2);

		if(parent_location < 0)
		{
			return;
		}

		child = heap[child_location];
		parent = heap[parent_location];
	}
}

void build_heap()
{
	//             
	assert(true);
	//              
	//                                
	int size = heap.size();
	for (int i = 0; i < size; i++)
	{
		push_up(i);
	}
}

void swap(int to_swap)
{
	//             
	assert(true);
	//              
	//                                                                                                   
	int swop = heap[to_swap];
	heap[to_swap] = heap[0];
	heap[0] = swop;
}

void push_down(int sorted)
{
	//             
	assert(true);
	//              
	//                                                                                                  
	//                                    
	int parent_location = 0;
	int parent = heap[parent_location];
	int child1_location = 2 * parent_location + 1;
	int child2_location = 2 * parent_location + 2;
	int child1 = heap[child1_location];
	int child2 = heap[child2_location];

	while(child1 > parent || child2 > parent)
	{
		if(child1 > child2 && child1_location < sorted)
		{
			heap[child1_location] = parent;
			heap[parent_location] = child1;
			parent_location = child1_location;
		}
		else if(child2_location < sorted)
		{
			heap[child2_location] = parent;
			heap[parent_location] = child2;
			parent_location = child2_location;
		}
		else
		{
			return;
		}

		parent = heap[parent_location];
		child1_location = 2 * parent_location + 1;
		child2_location = 2 * parent_location + 2;
		child1 = heap[child1_location];
		child2 = heap[child2_location];

	}
}

void pick_heap()
{
	//             
	assert(true);
	//              
	//                                                                                   
	int size = heap.size();
	for (int i = size - 1; i >= 0; i--)
	{
		swap(i);
		push_down(i);
	}
}

int main()
{
	print_vector();
	build_heap();
	print_vector();
	pick_heap();
	print_vector();

	//                                                                    
	//                                        
	int i;
	cin >> i;
	return 0;
}


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*

                                                     

      
       
                                                                          

             
                                                                                                    

      
                            
  

      
  				      
			  				  
		   		  		  		 

        

					  
			  				  
		   		  		  		 

                                        
					  
			  				  
		   		  		  		 

                                        
					  
			  				  
		   		  		  		 

                                        

                                                                

        
                               
                               
                               
                               
                               
                               
                               
                               
                               
                               
                            
*/

vector<int> heap = {2,14,30,29,42,30,11,-5,0,51};

void swap (int a, int b)
{
    assert(true);

    int helper = heap[a];
    heap[a] = heap[b];
    heap[b] = helper;

}

void build_heap (int n)
{
    int parent = 0;
    int new_child = 0;
    int new_parent = 0;

    for(int i = 0; i < n; i++)
    {
        parent = ((i-1)/2);
        if(parent >= 0)
        {
            new_child = i;
            new_parent = parent;
            while ((heap[new_child] > heap[new_parent]))
            {
                swap(new_child, new_parent);
                new_child = new_parent;
                new_parent = (new_child-1)/2;
            }

            cout << heap[0] << ", " << heap[1] << ", " << heap[2] << ", " <<
            heap[3] << ", " << heap[4] << ", " << heap[5] <<", " << heap[6] <<
            ", " << heap[7] << ", " << heap[8] <<", " << heap[9] << endl;
        }
    }
}

void push_down (int n)
{
    int left_child = 0;
    int right_child = 0;
    int parent = 0;

    for(int i = 0; i < n; i++)
    {
        if (2*i+2 < n)
        {
            left_child = 2*i+1;
            right_child = 2*i+2;
            parent = i;

            while(2*parent+2 < (n-1))
            {
                left_child = 2*parent+1;
                right_child = 2*parent+2;
                cout << "p: " << heap[parent] << " lc: " <<heap[left_child] << " rc: " << heap[right_child] << endl ;

                if (((heap[left_child] > heap[right_child])))
                {
                    if(heap[parent] < heap[left_child])
                        swap(parent, left_child);
                          cout << heap[parent] << " swapped with " <<heap[left_child] << endl;
                        parent = left_child;
                }
                if ((heap[right_child] >= heap[left_child]))
                {
                    if(heap[parent] < heap[right_child])
                        swap(parent, right_child);
                        cout << heap[parent] << " swapped with  " <<heap[right_child] << endl;
                        parent = right_child;
                }
            }
        }
    }
}

void pick_heap (int n)
{
    n--;
    swap(0, n);
    for(int k = n; k > 0; k--)
    {
        push_down(k);
        swap(0, k-1);
    }
    swap(0,1);

    cout << heap[0] << ", " << heap[1] << ", " << heap[2] << ", " <<
    heap[3] << ", " << heap[4] << ", " << heap[5] <<", " << heap[6] <<
    ", " << heap[7] << ", " << heap[8] <<", " << heap[9] << endl;

}

int main()
{

    cout << heap[0] << ", " << heap[1] << ", " << heap[2] << ", " <<
    heap[3] << ", " << heap[4] << ", " << heap[5] <<", " << heap[6] <<
    ", " << heap[7] << ", " << heap[8] <<", " << heap[9] << endl;

    cout << "Start:" << endl;
    build_heap(heap.size());
    cout << "After Sorting:" << endl;
    pick_heap(heap.size());

}


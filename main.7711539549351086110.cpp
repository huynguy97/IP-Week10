#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
/*                                                                                                             
       

                                                  
     
                                 
                                  
                                  
                             
                             
                                    
                                       
                                                      
                             
                             
                                                        
                                                   
                                                   
                                                        
     
                                                                                                          

                                       
     
                   
                          
                                                                               
         
                                 
                              
         
                     
     
                                                                                                               

     
                                                                             

        

                                                               
                                                                 
                                                                   
                                                                   
                                                                    

                                                                
                                                                 
                                                                   
                                                                   
                                                                    

         

                                                                
                                                                 
                                                                   
                                                                  
                                                                    

                                                                
                                                                 
                                                                   
                                                            
                                                                    

                                                                
                                                                 
                                                                   
                                                           
                                                                     

                                                                
                                                                 
                                                                    

                                                                     

                                                              
                                                             
                                                             

                                                                       

                            

  
                   
                                                                         
                                                                                              
                                                                                              
                                                                                                             
                                                                                                                           */
typedef int El ;

void display_vector(vector<El> data)
{
    int length = data.size();
    cout << " { " ;
    for (int i=0; i<length-1;i++)
        cout << data[i] << ", ";
    if (length>0)
        cout << data[length-1];
    cout << " } " << endl;
}

void swap (vector<El>& data, int  i, int  j )
{//	              
	assert ( i >= 0 && j >= 0 && i < data.size() && j < data.size()) ;
//                                                                
	const El HELP = data [i];
	data [i] = data [j] ;
	data [j] = HELP;
}

void push_up(vector<El>& data, int  i, int heap_end)
{//	              
	assert ( i >= 0 && i < heap_end ) ;
//                                                                                                                                            
	int parent = i;
	int child = parent*2+1;
	while ( child <= heap_end)
    {
        if (child + 1 <= heap_end && data[child] < data[child + 1])
            child = child +1;
        if (data[parent] < data[child])
        {
            swap(data, parent, child);
            parent = child;
            child = parent*2+1;
        }
        else
            return;
    }
}
void build_heap(vector<El>& data)
{//	              
	assert (true) ;
//                                                                                      

    const int length = data.size();
    int start = (length -2 )/2 ;
    while ( start >= 0)
    {
        push_up(data, start, length-1);
        start--;
    }
}

void heap_sort(vector<El>& data)
{//	              
	assert (true) ;
//                                                                                                                                                      
//                                                                                                                       

    build_heap(data);
//                         
    int heap_end = data.size()-1;
    while (heap_end > 1)
    {
        swap(data,0,heap_end);
        heap_end--;
        push_up(data,0,heap_end);
//                             
    }
    swap(data,0,1);
//                         
}

int main()
{
    vector<El> data1 = {15, 40, 42, -15, 30, 35, 5};
    display_vector(data1);
    heap_sort(data1);
    cout << " after heap_sort: " << endl;
    display_vector(data1);
    cout << endl;

	vector<El> data2 = {22, 0, 2, -15, 30, 32, 5 , -2 , 22, 42 , 17};
    display_vector(data2);
    heap_sort(data2);
    cout << " after heap_sort: " << endl;
    display_vector(data2);

	return 0;
}


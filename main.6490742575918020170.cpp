#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
/*
             
                            
                       
*/

/*
                                                
                                       
                                                                                                                  
                                                                                                                    
                                      
                                                                  
                                                                                                                           
                                                                                                          
                                                                                                                       
                                                                                
                                                     

                               
           
          
           
             
              
                                          

          
           
             
              
                                                     

          
           
             
              
                                                     

          
           
             
              
                                                     

                                                        

           

                                                                   

                                                                                                                        
                                                                                                        
                                                                                                        

                                                                                                                        
                                                                                                        

                                                                                                                          
                                                                                                          

                                                                                                                           
                                                                                                          

                                                                                                                                

                                                                                                                                   

                                

           
                                                                                                                         
                                                                                                                     
                                                                                                 

              
                                                                                                                           
                                                                                         

             
                                                                                                                                  
                                                                                                                          
                                                                                                                       

             
                                                                                                                               
                                                           

             
                                                                                                                       
                                                                        
*/

ostream& operator<< (ostream& out, const vector<int>& data)
{
    //             
    assert(true);
    /*                                                           
    */
    out << "{";
    int length = data.size();
    int i;
    for(i = 0; i < length-1; i++)
        out << data[i] << ", ";
    out << data[i] << "}";
    return out;
}

void swap_v(vector<int>& data, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    /*                                         
                                            
    */
    const int HELP = data[i];
    data[i] = data[j];
    data[j] = HELP;
}

void push_up(vector<int>& data, int i)
{
    //              
    assert(i >= 0 && i < data.size());
    /*                                                                                                                  
                                                                                              
    */
    for( ; data[i] > data[(i-1)/2]; i = (i-1)/2)
        swap_v(data, i, (i-1)/2);
}

void build_heap(vector<int>& data)
{
    //              
    assert(true);
    /*                                                                                              
    */
    int length = data.size();
    for(int i = 0; i < length; i++)
        push_up(data, i);

    cout << "\nHeap of the data: " << data;
}

int maximum (vector<int>& data, int a, int b)
{
    //              
    assert(a >= 0 && b >= 0 && a < data.size() && b < data.size());
    /*                                                                                
    */
    if(data[a] >= data[b])
        return a;
    else
        return b;
}

void push_down (vector<int>& data, int border)
{
    //              
    assert(border < data.size());
    /*                                                                                                             
                                                                                                           
    */
    int i = 0;
    int help;
    while(2*i+1 < border || 2*i+2 < border)
    {
        if(2*i+1 < border && 2*i+2 < border)
        {
            if(data[i] < data[2*i+1] || data[i] < data[2*i+2])
            {
                help = maximum(data, 2*i+1, 2*i+2);
                swap_v(data, i, maximum(data, 2*i+1, 2*i+2));
                i = help;
            }
            else return;
        }
        if(2*i+1 < border && 2*i+2 >= border)
        {
            if(data[i] < data[2*i+1])
            {
                help = 2*i+1;
                swap_v(data, i, 2*i+1);
                i = help;
            }
            else return;
        }
    }
}

void pick_heap(vector<int>& data)
{
    //              
    assert(true);
    /*                                                      
    */
    int length = data.size();
    for(int i = length-1; i >= 0; i--)
    {
        swap_v(data, 0, i);
        push_down(data, i);
    }
}

void heap_sort (vector<int>& data)
{
    //              
    assert(true);
    /*                                                                       
    */
    build_heap(data);
    pick_heap(data);

    cout << "\nSorted data: " << data;
}

int main()
{
    cout << "Hello world" << endl;
    vector<int> A = {15, 40, 42, -15, 30, 35, 5};
    cout << "Original data: " << A;
    heap_sort(A);
    return 0;
}


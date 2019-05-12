/*                                                                             
               
                                                   
                                                   

                                                                               
          
                                                                             */

#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>

using namespace std;

/*                                                                             
                        
                                                                             */

void show_tree (vector<int>& data)
{
//                
    assert(true);
//                 
//                                
    assert(true);

    int end_of_line = 0;
    int row         = 1;

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << "\t";
        if (i == end_of_line)
        {
            cout << endl;
            end_of_line += pow(2,row);
            row++;
        }
    }
    cout << endl;
}

ostream& operator<< (ostream& out, const vector<int>& data)
{
//                
    assert(true);
//                 
//                                                                         

    out << '[' << "\t";
    for (int i = 0; i < data.size(); i++)
        out << data[i] << "\t";
    out << ']' << endl;
    return out;
}

/*                                                                             
                     
                                                                             */

void push_up (vector<int>& data, int child)
{
//                
    assert (child >= 1);
//                 
//                                                                 

    int parent = ( child - 1 ) / 2;

    const int HELP = data[parent];
    data[parent]   = data[child];
    data[child]    = HELP;
}

void build_heap (vector<int>& data)
{
//                
    assert (data.size() > 0);
//                 
//                                                                                   

    int  parent;
    bool is_heap = false;

    while (!is_heap)
    {
        int HEAP_COUNTER = 0;
        for (int child = 1; child < data.size(); child++)
        {
            parent =  ( child - 1 ) / 2;
            if (data[child] > data[parent])
                push_up(data,child);
            else
                HEAP_COUNTER++;
        }
        is_heap = HEAP_COUNTER == data.size()-1;
    }
}

void swap (vector<int>& data, int last)
{
//                
    assert(true);
//                 
//                                

    const int HELP  = data[0];
    data[0]         = data[last];
    data[last]      = HELP;
}

int push_down (vector<int>& data, int parent, int last)
{
//                
    assert(true);
//                 
//                                                                           
//                                                                           
//                                                                            
//                                                           

    int child1 = 2*parent+1;
    int child2 = 2*parent+2;

    if  (child1 < last || child2 < last)
        if (data[parent] < max(data[child1],data[child2]))
        {
            if (data[child1] > data[child2])
            {
                const int HELP = data[child1];
                data[child1]   = data[parent];
                data[parent]   = HELP;
                return child1;
            }
            else
            {
                const int HELP = data[child2];
                data[child2]   = data[parent];
                data[parent]   = HELP;
                return child2;
            }
        }
    return parent;
}

bool is_sorted (vector<int>& data)
{
//                
    assert(true);
//                 
//                                        

    for (int i = 1; i < data.size(); i++)
        if (data[i-1] > data[i])
            return false;
    return true;
}

void pick_heap (vector<int>& data)
{
//                
    assert(true);
//                 
//                                                                             
//                                                                             
//                                                                            
//                                                             

    build_heap(data);

    int counter = data.size()-1;
    int parent, child;

    while (!is_sorted(data))
    {
        swap(data, counter);
        counter--;

        parent = 0;
        child  = push_down(data, parent, counter);
        while (parent != child)
        {
            parent = child;
            child  = push_down(data,child, counter);
        }
    }
}

/*                                                                             
                                                         
                                                                             */

int main()
{
    vector<int> input = {15,40,42,-15,30,35,5};

    cout << "The initial, unsorted vector-of-integers looks like: " << endl << input << endl;
    pick_heap(input);
    cout << endl << "The sorted vector-of-integers looks like: " << endl << input;

    return 0;
}

/*                                                                             
                                                  
                                                                             */

//                                                                               
//                                          
//
//                                                                             
//                                                            
//                                                                    

/*                                                                             
                                 
                                                                             */

//  
//                                                    
//                                                   
//
//                                                             
//                
//                        
//                           
//
//                                                                   
//                                                                   
//                                                                   
//                                                                   
//                                                                   
//                                                                   
//
//                                         
//                                                    

//  
//               
//                      
//                                  
//                      
//                                

/*                                                                             
                                      
                                                                             */

//                                                                             
//                                                                               
//                                 


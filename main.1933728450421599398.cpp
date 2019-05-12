//              
//                            

#include <iostream>
#include<vector>
#include <cassert>

using namespace std;

vector<int> v;

const bool DEBUG = true;

ostream& operator<< (ostream& out, const vector<int> v)
{//               
    assert (true) ;
/*                 
                                                                  
*/
    out << "{";
    for(int i = 0; i < v.size(); i++)
    {
        out << v[i];
        if(i < (v.size() - 1))
            out << ",";
    }
    out << "}";
    return out ;
}

void swap(const int& a,const int& b, vector<int>& v)
{//               
    assert(a >= 0 && a < v.size() && b >= 0 && b < v.size());

    const int c = v[b];
    v[b] = v[a];
    v[a] = c;
    if(DEBUG) cout << v << endl;
    /*                 
                                                                      
    */
}

void push_up(int current, vector<int>& v)
{//               
    assert(current >= 0 && current < v.size());

    int parent = (current - 1)/2;
    while(v[current] > v[parent])
    {
        swap(current, parent, v);
        current = parent;
        parent = (current - 1)/2;
    }
    /*                 
                                                                                                                         
    */
}

void build_heap(vector<int>& v)
{//               
    assert(true); //                          

    for(int i = 0; i < v.size(); i++)
        push_up(i, v);
    /*                 
                                                          
    */
}

void push_down(int& firstSorted, vector<int>& v)
{//               
    assert(firstSorted >= 0 && firstSorted < v.size());

    swap(firstSorted, 0, v);
    int current = 0;
    int childOne = 2 * 0 + 1;
    int childTwo = childOne + 1;
    bool finished = false;

    while(!finished)
    {
        if(childTwo < firstSorted)
        {
            if(v[childOne] > v[childTwo] && v[childOne] > v[current])
            {
                swap(childOne, current, v);
                current = childOne;
            }
            else
                if(v[childTwo] > v[current])
                {
                    swap(childTwo, current, v);
                    current = childTwo;
                }
                else
                    finished = true;
        }
        else
        {
            if(childOne < firstSorted)
                if(v[childOne] > v[current])
                    swap(childOne, current, v);
            finished = true;
        }
        childOne = 2 * current + 1;
        childTwo = childOne + 1;
    }

    /*                 
                                                                                        
                                                                                                                        
    */
}

void pick_heap(vector<int>& v)
{//               
    assert(true); //                          

    for(int i = v.size() - 1; i >= 0; i--)
        push_down(i, v);

    /*                 
                                                            
    */
}

void heap_sort(vector<int>& v)
{//               
    assert(true); //                          
    build_heap(v);
    pick_heap(v);

    /*                 
                                                            
    */
}

int main()
{
    v.push_back(15);
    v.push_back(40);
    v.push_back(42);
    v.push_back(-15);
    v.push_back(30);
    v.push_back(35);
    v.push_back(5);
    cout << "Initial vector:" << endl << v << endl;
    heap_sort(v);
    cout << "Final vector:" << endl << v << endl;
    return 0;
}

/*
                                                                                                                                                
           
                                                                                                                                  

                                                                                                                         

           
                        
                         
                           
                            
                             

                        
                         
                           
                            
                             

                        
                         
                           
                            
                             

                        
                         
                           
                            
                             

                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          

                                                                   

                                                                                                                                     
                                                                                                              
                                                                                                                                     
                                                                                                                
                                                                                                             

*/


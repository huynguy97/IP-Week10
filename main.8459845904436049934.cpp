//                              
//                                

//                                                                                                                                        

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
//                      
//                                                   

vector<int> test = {15 ,40, 42, -15, 30, 35, 5};

int vsize (vector<int>& v)
{
    return static_cast<int> (v.size());
}

void swap(int& a, int& b)
{
    //                
    assert(true);

    //                 
    //
    int c = a;
    a = b;
    b = c;
}

void print_tree (vector<int>& v, int length)
{
    //                
    //                                                            
    assert(length <= 10);

    //                 
    //                                       

    int e = 0;
    string tree = "xxxxxx0\n"
                  "xxxxx/xxxx\\\n"
                  "xx0xxxxx0\n"
                  "xx/xx\\xxxxx/x\\\n"
                  "0x0x0x0\n\n";

    for (int i = 0; i < tree.length(); i++)
    {
        if(tree [i] == 'x')
            cout << " ";

        else if (tree [i] == '0')
        {
            if (v [e] >= 0)
                cout << " ";

            cout << v [e];

            if (v [e] < 10)
                cout << " ";

            e++;
        }

        else
            cout << tree [i];
    }
}

void push_up(vector<int>& v, int index_child)
{
    //                                                                                          
    //                
    assert(index_child >= 0 && index_child < vsize(v));

    //                 
    //                                                                                                                                                             
    int index_parent = (index_child-1)/2;

    while (v [index_child] > v [index_parent] && index_parent >= 0)
    {
        swap (v [index_child], v [index_parent]);
        index_child = index_parent;
        index_parent = (index_child-1)/2;
    }

}

void build_heap(vector<int>& v)
{
    //                
    assert(true);

    //                 
    //                                                                          

    cout << "Phase 1:" << endl;
    for (int i = 0; i < vsize(v); i++)
    {
        push_up(v, i);
        print_tree(v, vsize(v));
    }
}

void push_down(vector<int>& v, int sorted_index)
{
    //                
    assert(sorted_index < vsize(v));

    //                 
    //                                                                                                                                                                     

    int index_parent = 0;
    int index_biggest_child = 0;

    if (v [2*index_parent+1] > v [2*index_parent+2])
        index_biggest_child = 2*index_parent+1;
    else
        index_biggest_child = 2*index_parent+2;

    while (v  [index_parent] < v [index_biggest_child] && index_biggest_child < sorted_index)
    {
        swap(v  [index_parent], v [index_biggest_child]);

        index_parent = index_biggest_child;

        if (v [2*index_parent+1] > v [2*index_parent+2])
            index_biggest_child = 2*index_parent+1;
        else
            index_biggest_child = 2*index_parent+2;
    }
}

void pick_heap(vector<int>& v)
{
    //                
    assert(true);

    //                 
    //                                                                                                           

    cout << "Phase 2:" << endl;
    for(int sorted_index = vsize(v)-1; sorted_index >= 0; sorted_index--)
    {
        swap(v[0], v[sorted_index]);
        push_down(v, sorted_index);

        //                  
        cout << "{";
        for(int i = 0; i < vsize(v); i++)
        {
            cout << v[i] << ", ";
        }
        cout << "}" << endl;
    }

}

void heap_sort(vector<int>& v)
{
    //                
    assert(true);

    //                 
    //                                                     

    //                           
    build_heap(v);

    //                           
    pick_heap(v);
}

int main ()
{
    string exit;

    heap_sort(test);

    cout << "\nEnter 'stop' to exit " << endl;
    while (exit != "stop")
        cin >> exit;

    return 0;
}

/*
       
                                                                                                        
                                                                                                                                  

       
                
                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                 
                   
                     
                      
                       

                
                                    
                                    
                                    
                                    
                                    
                                    
                                    

       

 */

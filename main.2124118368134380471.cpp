#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

/*
                           
                      
*/

/*
  
      
                                                                                                      

                                                                                      

*/

/*
  
                    

                  
                   
                     
                      
                       

                  
                   
                     
                      
                       

                  
                   
                     
                      
                       

                  
                   
                     
                      
                       

                    

                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  

      
                                                                                                      
                                                                                       
                                                                                                        
                                   

*/
vector<int> Tree ={2,14,30,29,42,30,11,-5,0,51};
//                            

bool test = true;

int size (vector <int>& v)
{
    return static_cast<int> (v.size ());
}

void push_up(vector <int>& Tree, int i)
{
    //              
    assert(i>=0 && i<size(Tree));
    /*
                   
                                                                               
                                               
                                       
    */

    int help;
    int loc = i;
    while (Tree [loc]> Tree[(loc-1)/2] && loc != 0)
        {
            help = Tree [loc];
            Tree[loc] = Tree[(loc-1)/2];
            Tree[(loc-1)/2] = help;
            loc = (loc-1)/2;
        }
}

void build_heap (vector <int>& Tree)
{
    //              
    assert(size(Tree)>1);
    /*
                                                                                 
    */

    for (int i = 0; i<size(Tree); i++)
    {
        push_up(Tree, i);
        if (test)
        {
        cout<< "build_heap {";
        for (int k = 0; k<size(Tree)-1; k++)
            {
                cout<< Tree [k] << ",";
            }
                cout << Tree [size(Tree)-1] << "}" <<endl;
        }
    }
}

void swap(vector <int>& Tree, int i)
{
    //              
    assert(i>0 && i<size(Tree));
    /*
                                                   
    */

    int temp = Tree[0];
    Tree[0] = Tree [i];
    Tree[i] = temp;

    if(test)
    {
        cout<< "swap: {";
    for (int x = 0; x<size(Tree)-1; x++)
        {
            cout<< Tree [x] << ",";
        }
            cout << Tree [size(Tree)-1] << "}" <<endl;
    }
}

void push_down(vector<int>& Tree, int i)
{
   //              
    assert(i>0 && i<size(Tree));
    /*
                                                                                     
    */

   int temp = 0;
    while ( temp*2+1 < i && (Tree [temp] < Tree [temp*2+1] || Tree [temp] < Tree [temp*2+2] ))
    {
        if ((Tree [temp*2+1] > Tree [temp*2+2] || temp*2+2 > i) && Tree [temp] < Tree [temp*2+1])
        {
            int loc = Tree [temp];
            Tree [temp] = Tree [temp*2+1];
            Tree [temp*2+1] = loc;
            temp = temp*2+1;
        }
        else
         {
             if (temp*2+2 < i)
             {
                int loc = Tree [temp];
                Tree [temp] = Tree [temp*2+2];
                Tree [temp*2+2] = loc;
                temp = temp*2+2;
             }
             else
             {
                 temp = i;
             }
         }
    if (test)
    {
        cout<< "push_down: {";
    for (int j = 0; j<size(Tree)-1; j++)
        {
            cout<< Tree [j] << ",";
        }
            cout << Tree [size(Tree)-1] << "}" <<endl;
    }
    }
}

void pick_heap (vector<int>& Tree)
{
    //              
    assert(size(Tree) > 0);
    /*
                   
                                                                                 
    */

    for (int i = size(Tree)-1; i > 0; i--)
    {
        swap(Tree, i);
        push_down(Tree, i);
    }
}

void heap_sort (vector<int>& Tree)
{
    build_heap(Tree);
    pick_heap(Tree);
    cout<< "result: {";
    for (int j = 0; j<size(Tree)-1; j++)
        {
            cout<< Tree [j] << ",";
        }
            cout << Tree [size(Tree)-1] << "}" <<endl;
}

int main()
{
 heap_sort(Tree);
}


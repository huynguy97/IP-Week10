/*                                                 
                         
                                  
                                                  
                                                 */

/*
                                                 

                                                                           

    

                
         
          
            
             
               

                
         
          
            
             
               

                   
         
          
           
             
                

         
          
           
             
                

         
          
           
             
                

         
          
            
             
               

        
          
             
             
               

         
          
            
             
               

*/
/*                                                                                   
           
                                                                                   */

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

vector<int> a = {15,40,42,-15,30,35,5};
int length = static_cast<int> (a.size());

void print_heap(vector<int>& a, int length)
{
    /*                */
    assert(length == 7);
    /*                 
                              */
    int e = 0;
    //                          
    string heap = "xxxxxx0xxxxxx\n"
                  "xxxxx/xxx\\xxxxx\n"
                  "xx0xxxx0xxx\n"
                  "xx/xx\\xxx/xx\\xx\n"
                  "0x0x0x0\n\n";
    for (char i : heap) {
        if(i == 'x')
            cout << " ";
        else if (i == '0')
        {
            if (a[e] >= 0)
                cout << " ";
            cout << a[e];
            if (a[e] < 10)
                cout << " ";
            e++;
        }
        else
            cout << i;
    }
}

/*            
                                                                              
                                                                                 
                                                                        
                                                                        
                               */
void push_up(vector<int>& a, int i, int length)
{
    /*                */
    assert(i >= 0 && i < length);
    /*                 
                                                
                                     */
    int parent = (i-1)/2; /*   */
    while(parent >= 0 && a[i] > a[parent])
    {
        swap(a[i], a[parent]);
        i = parent;
        parent = (i-1)/2;
    }
}

/*            
                                                                               
                                                                                 
                                                                           
                                                                        
                                */
void push_down(vector<int>& a, int s, int length)
{
    /*                */
    assert(s > 0 && s < length);
    /*                 
                                                                    
                                     */
    int i = 0;
    int child1 = 2*i+1;
    int child2 = child1+1;
    int highestChild = a[child1] > a[child2] ? child1 : child2;

    while(highestChild < s && a[i] < a[highestChild])
    {
        swap(a[i], a[highestChild]);
        i = highestChild;
        int child_l = 2*i+1;
        int child_r = child_l+1;
        highestChild = a[child_l] > a[child_r] ? child_l : child_r;
    }
}

/*            
                                                                            
                                                                          
          */
void build_heap(vector<int>& a, int length)
{
    /*                */
    assert(true);
    /*                 
                                                             */
    for (int i = 0; i < length; i++)
    {
        push_up(a, i, length);
    }
    print_heap(a, length);
}

void swap(int& a, int& b)
{
    /*                */
    assert(true);
    /*                 
                          */
    int t = a;
    a = b;
    b = t;
}

/*            
                                                               
                                          
                                   */
void pick_heap(vector<int>& a, int length)
{
    /*                */
    assert(true);
    /*                 
                                                                    */
    for (int i = length - 1; i > 0; i--) {
        swap(a[i], a[0]);
        push_down(a, i, length);
        print_heap(a, length);
    }
}

int main() {
    cout << "original array:" << endl;
    print_heap(a, length);
    cout << "heapified array:" << endl;
    build_heap(a, length);
    cout << "heap sorting steps:" << endl;
    pick_heap(a, length);
    return 0;
}


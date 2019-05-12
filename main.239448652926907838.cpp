#include <iostream>
#include <vector>
using namespace std;

/*       
                                                                                                                                
                                                                                                  
  
         
     
          
              
                      
                         
                          

              
                      
                         
                          

              
                      
                         
                          

              
                      
                         
                          

            
              
                      
                         
                          
             
                      
                           
                          

              
                     
                           
                          

              
                      
                          
                          

             
                      
                            
                          

              
                     
                            
                          

              
                     
                             
                          

              
                     
                             
                          

              
                     
                             
                          

               
                     
                             
                          

              
                      
                             
                          

             
                        
                             
                          

               
                       
                             
                          

                
                       
                             
                          

                                                                                              
 */

vector<int> numbers = {2,14,30,29,42,30,11,-5,0,51};

void swap (vector<int>& vector1, int a, int b)
{
    int help;
    help = vector1[b];
    vector1[b] = vector1[a];
    vector1[a] = help;
}

void push_up (vector<int>& vector, int i)
{
    int parent_node = (i-1)/2;
    while (vector[i] > vector[parent_node])
    {
        swap(vector, i, parent_node);
        i = parent_node;
        parent_node = (i-1)/2;
    }
}

void build_heap (vector<int>& vector)
{
    for (int i = 1; i < vector.size(); i++)
    {
        push_up(numbers, i);
    }
}

void push_down (vector<int>& vector, int i)
{
    int parent_node = (i-1)/2;
    while (vector[parent_node] > vector[i])
    {
        swap(vector, parent_node, i);
        i = parent_node;
        parent_node = (i-1)/2;
    }
}

void pick_heap (vector<int>& vector)
{
    for (int i = vector.size() -1; i >= 0; i--)
    {
        swap(vector, i, 0);
        push_down(vector, i);
    }
}

int main()
{
    cout << "The unsorted vector is:" << endl << "{";
    for (int i = 0; i < numbers.size()-1; i++)
    {
        cout << numbers [i] << ", ";
    }
    cout << numbers[numbers.size()-1];
    cout << "}" << endl;

    build_heap(numbers);

    cout << "After push up, the vector is:" << endl << "{";
    for (int i = 0; i < numbers.size()-1; i++)
    {
        cout << numbers [i] << ", ";
    }
    cout << numbers[numbers.size()-1];
    cout << "}" << endl;

    pick_heap(numbers);

    cout << "The sorted vector is:" << endl << "{";
    for (int i = 0; i < numbers.size()-1; i++)
    {
        cout << numbers [i] << ", ";
    }
    cout << numbers[numbers.size()-1];
    cout << "}" << endl;
    return 0;
}

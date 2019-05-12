//                          
//                    

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> my_vector = {3, 6, 16, 8, 26, 20, 30};

void printvector(const vector<int>& my_vector)
{
    //              
    assert(my_vector.size() >= 0);
    //                
    //                                                           
    cout << "{";
    for (int i=0; i<my_vector.size(); i++)
    {
        if (i == my_vector.size()-1)
        {
            cout << my_vector[i];
        }
        else cout << my_vector[i] << ", ";
    }
    cout << "}" << endl;
}

vector<int> push_up(vector<int>& my_vector, int i)
{
    //              
    assert(my_vector.size() > 0 && i >= 0);
    //                
    //                                                                                                                                                                                      
    bool on_top = false;
    while (!on_top)
    {
        if (my_vector[i] >= my_vector[(i-1)/2] && i > (i-1)/2) //                                                   
        {
            swap(my_vector[i], my_vector[(i-1)/2]);
            i = (i-1)/2;    //                                                                       
        }
        else
            on_top = true; //                                                                                           
    }
    return my_vector;
}

vector<int> push_down(vector<int>& my_vector, int i, int last_sorted)
{
    //              
    assert(my_vector.size() >= 0 && i >= 0);
    //                
    //                                                                                   
    int child_left = 2*i+1;
    int child_right = 2*i+2;
    while (2*i+2 < last_sorted)
    {
        if ((my_vector[i] <= my_vector[child_left] || my_vector[i] <= my_vector[child_right]))
        {
            if (my_vector[child_left] >= my_vector[child_right])
            {
                swap(my_vector[i], my_vector[child_left]); //                            
                i = 2*i + 1; //                            
            }
            else
            {
                swap(my_vector[i], my_vector[child_right]); //                             
                i = 2*i + 2; //                            
            }
        }
    }
    return my_vector;
}

vector<int> build_heap(vector<int>& my_vector)
{
    //              
    assert(my_vector.size() > 0);
    //                
    //                                                                    
    for (int i=0; i<my_vector.size(); i++)
    {
        push_up(my_vector, i);
    }
    return my_vector;
}

vector<int> pick_heap(vector<int>& my_vector)
{
    //              
    assert(my_vector.size() > 0);
    //                
    //                                                                                                                                                       
    for (int i = 0;i<my_vector.size();i++)
    {
        swap(my_vector[0], my_vector[my_vector.size()-1-i]); //                                                                    
        int last_sorted = my_vector.size()-1-i;
        push_down(my_vector, 0, last_sorted);
    }
    return my_vector;
}

int main()
{
    printvector(my_vector);
    build_heap(my_vector);
    printvector(my_vector);
    pick_heap(my_vector);
    printvector(my_vector);
    return -1;
}

/*       
                                                                                                                                             
                                                                                                                                                                     

      
                                               
        

                                                                      
                                                                       
                                                                         
                                                                          
                                                                           

        
  

                                    
                                              
                                               
                                                      
                                              
                                                                                 
                                              
                                                
                                              
                                                                                   
                                                                                              
                                                                                                                                       

  
                                                                                                                                                                          
                                                                                                                                                                                                  
                                                                                                                                                                              
                                                                                                                                                                                                                                      

                                                                                                             
*/


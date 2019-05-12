#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

ostream& operator<< ( ostream& out, const vector<int> my_vector)
{
    out << '{';
    if(my_vector.size()==0)
        return out;
    out << my_vector[0];
    for(int i = 1; i<my_vector.size(); i++)
        out << ',' << my_vector[i];
    out << '}';
}

void swapperoo(vector<int>& my_vector, int i, int j)
{
    //             
    assert(0<=i&&i<my_vector.size()&&0<=j&&j<my_vector.size());
    //               
    //                                                 
    int hold;
    hold = my_vector[i];
    my_vector[i] = my_vector[j];
    my_vector[j] = hold;
}

void push_up(vector<int>& my_vector, int i)
{
    //             
    assert(0<=i&&i<my_vector.size());
    //               
    //                                                                                               
    while(0<i && my_vector[(i-1)/2]<my_vector[i])
    {
        swapperoo(my_vector, (i-1)/2, i);
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& my_vector)
{
    //             
    assert(true);
    //               
    //                                                                
    for(int i = 0; i<my_vector.size(); i++)
        push_up(my_vector, i);
}

int max_index(vector<int>& my_vector, int i, int j)
{
    //              
    assert(0<=i && 0<=j && i<my_vector.size() && j<my_vector.size());
    //              
    //                                                                        
    if(my_vector[i]<my_vector[j])
        return j;
    return i;
}

void push_down(vector<int>& my_vector, int length)
{
    //             
    assert(length>0 && my_vector.size()>0 && length <= my_vector.size());
    //               
    //                                                                
    int i =0;
    while( 2*i+2<length && my_vector[i] < my_vector[ max_index(my_vector, 2*i+1, 2*i+2)] )
    {
        i = max_index(my_vector, 2*i+1, 2*i+2);
        swapperoo(my_vector, i, (i-1)/2);
    }
    if(2*i+2==length && my_vector[i]<my_vector[2*i+1]) //                                                  
        swapperoo( my_vector, i, 2*i+1);
}

void pick_heap(vector<int>& my_vector)
{
    //             
    assert(true);
    //               
    //                                
    //                                                                            
    for(int unsorted = my_vector.size(); unsorted>1; unsorted--)
    {
        swapperoo(my_vector, 0, unsorted-1);
        push_down(my_vector, unsorted-1);
    }
}

int main()
{
    /*
                                                                 
                              
                          
                              
                         
                              
*/
    return 0;
}

/*        
       
                                                                                                                             
                                                                                                                                                                              
                                                                                    

       
  
                      
              
                   
                       
                     
              
                   
                       
                     
              
                   
                       
                     
              
                   
                       
                     
              
                   
                       
                                           
              
                   
                       

                                               
                              
                                   

                              
                                   

                              
                                   

                              
                                   

                              
                                   

                              
         

                                                                                                                                                                           
                                                                                             
                                                                     
                                                                                                                                                                               
                                                                                                    

                                                                                                                         
*/


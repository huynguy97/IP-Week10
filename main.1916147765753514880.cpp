#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                                                                                 

/*
                                                                                                                                                 
                                                                                  
                                                                                    
                                                                                      
                                                                                       
                                                                                        

                                                                                                            
                  

                                                                                                       
                                                                                                
                      

                                                                  
                                                                                    
                          

                                                          
                                                                        
                              

                                                  
                                                            
                                  

                             
                                                 
                                     

                                                                                    
*/

vector<int> toBeSorted{2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
vector<int> sorted;
vector<int> solution{51, 42, 30, 30, 29, 14, 11, 2, 0, -5}; //                                              

void swap(vector<int>& data, int a, int b)
{
//               
    assert (true);
/*                
                                                               
*/
    const int TEMP = data[a];
    data[a] = data[b];
    data[b] = TEMP;
}

void push_up(vector<int>& data, int a)
{
//               
    assert (a < data.size());
/*                
                                                                                                                                           
                          
*/
    if (a <= 0) //                                                                                                     
                //                                                     
        return;
    if (data[(a-1)/2] < data[a])
    {
        swap(data, ((a-1)/2), a);
        push_up(data, (a-1)/2);
    }
}

void build_heap(vector<int>& data)
{
//               
    assert (true);
/*                
                                                                                                                                                    
                                                                      
*/
    for (int i = 0; i < data.size(); i++)
        push_up(data, i);
}

void push_down(vector<int>& data, int a)
{
//               
    assert (a >= 0 && a <= data.size());
/*                
                                                                                
*/
    if (2*a + 1 > data.size())
        return;
    if (!(2*a + 2 > data.size()))
    {
        if (data[2*a+2] > data[a] && data[2*a+2] > data[2*a+1])
        {
            swap(data, a, 2*a+2);
            push_down(data, 2*a+2);
        }
        else if (data[2*a+1] > data[a])
        {
            swap(data, a, 2*a+1);
            push_down(data, 2*a+1);
        }
    }
    else if (data[2*a+1] > data[a])
    {
            swap(data, a, 2*a+1);
            push_down(data, 2*a+1);
    }
}

void pick_heap(vector<int>& toBeSorted, vector<int>& sorted)
{
//               
    assert (toBeSorted != sorted);
/*                
                                                                                                                                                      
*/
    while(!toBeSorted.empty())
    {
        sorted.push_back(toBeSorted[0]);
        swap(toBeSorted, 0, toBeSorted.size());
        toBeSorted.pop_back();
        push_down(toBeSorted, 0);
    }
}

int main()
{
    cout << "Initial vector:\t\t";
    for (int i: toBeSorted)
        cout << i << " ";
    cout << endl;
    build_heap(toBeSorted);
    cout << "Vector after heaping:\t";
    for (int i: toBeSorted)
        cout << i << " ";
    cout << endl;
    pick_heap(toBeSorted, sorted);
    cout << "Sorted vector:\t\t";
    for (int i: sorted)
        cout << i << " ";
    return 0;
}


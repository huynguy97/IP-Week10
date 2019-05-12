#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;
/*
                                                           

           
                                                             
                                                                                                                     

           
                 
             
              
                
                 
                  
             
              
                
                 
                  
             
              
                
                 
                  
             
              
                
                 
                  
            
                                                                                 
                                                                                 
                                                                                 
                                                                                 

                                                                                                                                                     
                                                                                                                                     
                                                                                         
                                                                                                                                                       
                                                                                        
                                                                                                                             

                                                                                                                                                                             

*/
int breaker = 1000;
void swap(vector<int>& data, int i, int j)
{   //                   
    assert (  i >= 0 && j >= 0 ) ;
    //                                              
    //                                          
    const int HELP = data [i] ;
    data [i]  =  data [j] ;
    data [j] =  HELP ;
}
void push_up(int i, vector<int>& data)
{
    assert(i >= 0);
    //                
    //                                                                        
    if (static_cast<int>((i-1)/2) >= 0)
    {
        while(data[i] > data[(i-1)/2])
        {
            swap(data, i, static_cast<int>((i-1)/2));
            if(static_cast<int>((i-1)/2) >= 0)
                i = static_cast<int>((i-1)/2);
        }
    }
}
void build_heap(vector<int>& data)
{
    assert(true);
    //                
    //                                                    
    for(int i = 0 ; i < data.size() ; i++)
    {
        push_up(i, data);
    }
}
void push_down(vector<int>& data, int i, int j)
{
    assert(i >= 0 && j >= 0);
    //                
    //                                                                                
    int helpswap = 0;
    while((data[i] < data[2 * i + 1] || data[i] < data[2 * i + 2] )&& 2 * i + 2 <= j + 1)
    {
        if(2 * i + 1 == j)
        {
            if(data[i] < data[j])
                swap(data,i,j);
                i = breaker; //                                                                                                                                       
        }
        else
        {
            if(data[2 * i + 1] >= data[2 * i + 2])
                helpswap = 2 * i + 1;
            else
                helpswap = 2 * i + 2;
            swap(data, i, helpswap);
            if(helpswap < data.size())
                i = helpswap;
        }
    }
}
void pick_heap (vector<int>& data)
{
    assert(true);
    //                
    //                                                                                             
    int until;
    for(int i = 1; i < data.size(); i++)
    {
        swap(data, 0, data.size() - i);
        until = data.size() - i - 1;
        push_down(data,0,until);
    }
}

int main()
{
    cout << "How many elements do you want to sort?" << endl;
    int input, amount_of_elements;
    cin >> amount_of_elements;
    cout << "What selection of numbers do you want to sort using the heap method? (please enter after every element)" << endl;
    vector<int> v;
    for(int k = 0 ; k < amount_of_elements; k++)
    {
        if (cin >> input)
            v.push_back(input);
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter only integer values" << endl;
            k = k - 1;
        }
    }
    cout << "The elements you added are: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    breaker = v.size() + 12;
    build_heap(v);
    cout << "The heap version of this vector: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    pick_heap(v);
    cout << "The sorted vector : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}


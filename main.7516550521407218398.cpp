#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

/*       
                                                               
                                                                                                                                                                 
       
  
  
        
         
           
            
            

        
         
           
            
            

        
         
           
            
            

        
         
           
            
            
  
                                                                                                                                                               
                                                                                                                                                               
                                                                                            

  
                                                                                                                                             
                                                                                                                             
                                                                                 
                                                                                                                                               
                                                                                
                                                                                                                     
                                                                                                                                                                                   

*/
int breaker = 1000;
void swap(std::vector<int>& data, int i, int j)
{   //                   
    assert (  i >= 0 && j >= 0 ) ;
    //                                              
    //                                          
    const int HELP = data [i] ;
    data [i]  =  data [j] ;
    data [j] =  HELP ;
}
void push_up(int i, std::vector<int>& data)
{
    if ((i-1)/2 >= 0)
    {
        while(data[i] > data[(i-1)/2])
        {
            swap(data, i, (i-1)/2);
            if((i-1)/2 >= 0)
                i = (i-1)/2;
        }
    }
}

void build_heap(std::vector<int>& data)
{
    for(int i = 0 ; i < data.size() ; i++)
    {
        push_up(i, data);
    }
}

void push_down(std::vector<int>& data, int i, int j)
{
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
void pick_heap (std::vector<int>& data)
{
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
    std::cout << "How many elements do you want to sort?" << std::endl;
    int input, amount_of_elements;
    std::cin >> amount_of_elements;
    std::cout << "What selection of numbers do you want to sort using the heap method? (please enter after every element)" << std::endl;
    std::vector<int> v;
    for(int k = 0 ; k < amount_of_elements; k++)
    {
        if (std::cin >> input)
            v.push_back(input);
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter only integer values" << std::endl;
            k = k - 1;
        }
    }
    std::cout << "The elements you added are: " << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    breaker = v.size() + 12;
    build_heap(v);
    std::cout << "The heap version of this vector: " << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    pick_heap(v);
    std::cout << "The sorted vector : " << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    return 0;
}


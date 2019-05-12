/*
                             
                                      
*/

#include <iostream> //         
#include <cassert> //         
#include <vector> //        

void push_up (std::vector<int> & numbers, int i, int length)
{
    /*             */ assert(i >= 0);
    /*              */
    //                                               
    while (i-1 >= 0)
    {
        if (numbers[i-1] < numbers[i])
            std::swap(numbers[i-1], numbers [i]);
        i--;
    }
}

void build_heap(std::vector<int> & numbers)
{
    /*             */ assert (true);
    /*              */
    //                                                                    

    int length = numbers.size();
    for (int i = 1; i < length; i++)
        push_up(numbers, i, length);
}

void push_down(std::vector<int> & numbers, int i, int length)
{
    /*             */ assert(i >= 0);
    /*              */
    //                                               
    while (i+1 <= length)
    {
        if (numbers[i] > numbers[i+1])
            std::swap(numbers[i], numbers [i+1]);
        i++;
    }
}

void pick_heap(std::vector<int> & numbers)
{
    /*             */ assert (true);
    /*              */
    //                                                                        

    int length = numbers.size();
    std::swap(numbers[0], numbers[length-1]);
    for (int i = 0; i < length; i++)
        push_down(numbers, i, length);
}

int main()
{
    //               
    std::vector<int> numbers = {0,2,3,1,8};

    //                                                           
    std::cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << " " << numbers[3] << " " << numbers[4] << std::endl;
    build_heap(numbers);
    std::cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << " " << numbers[3] << " " << numbers[4] << std::endl;
    pick_heap(numbers);
    std::cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << " " << numbers[3] << " " << numbers[4] << std::endl;

    return 0;
}

/*                                                                            
       
                                                                           
                                                                              

                                                                             
                                                          

       
  
                               
                                                 
                                                                          
                         
                                                 
                                                 
                                                                                         
                                                 
                         

                               
                                                 
                                 
                                                                              
                                  
                                                          
                                  
                                                                     
                                                 
                            

  
                                                                             
                                                                            */


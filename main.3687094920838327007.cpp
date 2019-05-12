/*                                                                    
                              
                    
                                                                                
                                                                              
                                                                                        
                                                                     */
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

/*
                                                                                                                                                            
                                                                                                 
                                                    
                                                                                                                                                                
                                                                       
                                                                                                                   
                                                                                                                       
                                                                                                                       
                        
             
              
              
                                                                                                                                                                                               
                                                                                                                                                                         
*/

/*                                                                    
                                                 
                                                                                                             
                                                                     */

/*
                                 
               
                              
                 
                         
                     
                       
                       
 

                         
 
                      
                
     
                          
                                    
                              
         
                            
                            
         
     
 

                                                                                           
                          
 
                        
                    
                 
                     
 

                              
 
                          
                    
     
                                      
                                  
             
                                
                                 
             
     
 

                        
 
                    
                             
                    
     
                        
                             
     
 

  
                                   
      
          
                   
                                                                                       
      
          
                   
                                                                                 
                                                                                                                                              
                                                               
                                                                                              
                                         
                                                                                                                   
                                         
                                                                               
                                                                               
                                                                               
                                                                             
                                                          
  
                                                                                         
                                                                          
                                                 
                                                                                                                                             

*/
/*                                                                    
                                                          
                                                                     */

void create_vector (vector<int>& numbers)
{//              
    assert (true) ;
//                
//                                                              
    cout << "Note: creating a vector in the console is a bit tedious, as you have to list all elements one by one." << endl;
    cout << "Would you like to create a vector in the console? Select N if you already have one, Y otherwise. (Y/N)" << endl;
    char check ;
    cin >> check ;
    if (check == 'Y' || check == 'y')
    {
        cout << "Enter the number of elements that should be in the vector." << endl;
        int no ;
        cin >> no ;
        for ( int i = 0; i < no ; i++ )
        {
            cout << "Give an element for the vector" << endl;
            int el ;
            cin >> el ;
            numbers.push_back(el) ;
        }
    }
}

void show_vector (vector<int>& numbers)
{
    int s = numbers.size () ;
    for (int i = 0; i < s; i++)
    {
        cout << numbers[i] << " , " ;
    }
    cout << "end." << endl;
}

void push_up (vector<int>& numbers, int i)
{//              
    assert (numbers[i] > numbers[(i-1)/2]) ;
//                
//                         
//                             
    int help = numbers[i] ;
    numbers[i] = numbers[(i-1)/2] ;
    numbers[(i-1)/2] = help ;
}

void build_heap (vector<int>& numbers, int s)
{//              
    assert (s > 0) ;
//                
//                                      
//                                
    bool con = true ;
    while (con)
    {
        con = false ;
        for (int i = 1 ; i <= s ; i++)
        if (numbers[i] > numbers[(i-1)/2])
        {
            push_up (numbers, i) ;
            con = true;
        }
    }
}

void vswap (vector<int>& numbers, int& s)
{//              
    assert (s > 0) ;
//                
//                                                                                  
//                                                                                     
    int help = numbers[s] ;
    numbers[s] = numbers[0] ;
    numbers[0] = help ;
    s = s - 1 ;
}

void push_down (vector<int>& numbers, int s)
{//              
    assert (s > 0) ;
//                
//                                       
//                               
    bool con = true ;
    while (con)
    {
        con = false ;
        for (int i = 1 ; i <= s ; i++)
            if (numbers[i] > numbers[(i-1)/2])
            {
                push_up (numbers, i) ;
                con = true ;
            }
    }
}

void pick_heap (vector<int>& numbers)
{//              
    assert (true) ;
//                
//                                   
//                               
    int s = numbers.size() - 1;
    build_heap (numbers, s) ;
    while (s > 0)
    {
        vswap (numbers, s) ;
        if (s > 0)
            push_down (numbers, s) ;
    }
}

int main()
{
    vector<int> numbers ;
    create_vector (numbers) ;
    cout << " The (unsorted) vector is:" << endl;
    show_vector (numbers) ;
    pick_heap (numbers) ;
    cout << " The sorted vector is: " << endl;
    show_vector (numbers) ;
    return 0;
}

/*                                                                    
                                                     
                               
                                                                     */

//                         
//                                                     
//         
//                                 
//                                                        
//                                             
//                                                                 
//                                                                                                     
//                                       
//                                                        
//                                                                         
//                                                 
//                                 
//                                                                                                     
//                                                                
//                                                                                       
//                                                                                               
//                                                                                               


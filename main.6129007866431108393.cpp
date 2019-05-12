#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                                              
//                                                   

/*                                                                       
         
      
  

                                                                                                              

  

                                                                                                                                      

      
  

       
         
           
             
             
              

         
           
             
             
              

         
           
             
             
              

         
           
             
             
              

       
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      

  

                                                                                                                                                                      

                                                                                                        

                                                               

                                                                                                      

                                                                       */

vector<int> testDB = {15,40,42,-15,30,35,5};

int length = testDB.size();

void swap_db(vector<int>& testDB, int a, int b)
{
//               
    assert ( true );
/*                 
                                                                       
*/
    int help = testDB[a];
    testDB[a] = testDB[b];
    testDB[b] = help;
}

int build_heap (vector<int>& testDB, int length)
{
//               
    assert (length >= 0);
/*                 
                                                                                                                  
*/
    int i = 0;
    for(int i = 0; i < length; i++)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        if(2*i+1 < length || 2*i+2 < length)
        {
            if(testDB[i] < testDB[left])
            {
                swap_db(testDB, i, left);
                i = 0;
            }
            if(testDB[i] < testDB[right])
            {
                swap_db(testDB, i, right);
                i = 0;
            }

        }
    }
}

void sorting (vector<int>& testDB, int length)
{
//               
    assert ( length >= 0 );
/*                 
                                                                                                                                                           
                                                
*/
    for(int i = 0; i < length; i++)
    {
        int maximum = length - 1 - i;

        build_heap(testDB, maximum);
        swap_db(testDB, 0, maximum);
    }
}

int main()
{
//               
    assert (true);
/*                 
                                       
*/
    cout << "unsorted list:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << testDB[i] << " ";
    }
    cout << endl;

    build_heap(testDB, length);
    sorting(testDB, length);

    cout << "sorted list:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << testDB[i] << " ";
    }
    cout << endl;
}


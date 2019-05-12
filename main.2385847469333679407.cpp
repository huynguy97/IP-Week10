#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
vector <int> unsorted;
//                                                 
//                          

/*
          
                                                                                                                                         
                                                                                                                                                 
                                                                                                                                   
                 
  
                                                                                                                                         
                                                                                                                                        
                                                                                             
  
  
          
      
           
          
              
                
                                
           
           
              
                
  
           
           
              
                
  
           
           
              
                
  
                       
                             
         
           
              
                
  
          
              
                   
  
          
              
                   
  
           
              
                   
  
           
              
                  
                                                                              
  
         
           
              
                  
  
          
              
                     
  
           
              
                    
                                                                                          
  
         
           
              
                    
  
           
              
                      
  
           
              
                      
                                                                                         
  
         
           
              
                      
  
            
              
                       
  
            
               
                       
                                                                                          
  
         
            
               
                       
  
           
                    
                       
                                                                                         
  
         
            
                    
                       
  
             
                    
                       
                                                                                        
  
                                                     
               
                    
                       
                              
  
  
      
                                    
                                                                                                                                             
                                                                                                                                         
                                                                                                                                                           
                                                             
  
                                                                                                                                         
                                                                                                                            
                                                                                                  
  
                                                                                                                                                
                                                                                                                                        
                                                                                        
  
                                                                                                           
                                                                                                                           
                             
                                                               
 */
void heapify(vector<int>& unsorted, int n, int i)
{
    assert(true);
    //                                                                   

    int largest = i; //                           
    int l = 2*i + 1; //               
    int r = 2*i + 2; //                

    //                                  
    if (l < n && unsorted[l] > unsorted[largest])
        largest = l;

    //                                             
    if (r < n && unsorted[r] > unsorted[largest])
        largest = r;

    //                       
    if (largest != i)
    {
        swap(unsorted[i], unsorted[largest]);

        //                                          
        heapify(unsorted, n, largest);
    }
}

//                              
void heapSort(vector<int>& unsorted, int n)
{
    assert(n>0);
    //                                                                     

    //                              
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(unsorted, n, i);

    //                                        
    for (int i=n-1; i>=0; i--)
    {
        //                         
        swap(unsorted[0], unsorted[i]);

        //                                     
        heapify(unsorted, i, 0);
    }
}

/*                                             */
void printVector (vector<int>& unsorted, int n)
{
    for (int i=0; i<n; ++i)
        cout << unsorted[i] << " ";
    cout << "\n";
}

//               
int main()
{

    int total = 0;
    int number = 0;
    cout << "How many elements do you want to sort?" << '\n' << ">";
    cin >> total;
    for(int i = 0; i < total; i++){
        cout << "Please enter a number." << '\n' << ">";
        cin >> number;
        unsorted.push_back(number);
    }

    heapSort(unsorted, total);

    cout << "Sorted Vector is \n";
    printVector(unsorted, total);
}

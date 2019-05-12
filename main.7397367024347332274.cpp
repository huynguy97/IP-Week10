//
//          
//                     
//
//                                 
//                                                 
//

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

int enter_vector(vector<int>& numberstring)
{
    //              
    assert(true);
    //               
    //                           
    int length;
    int elementvalue;
    
    cout<< "Please enter the number of elements of the array: ";
    cin >> length;
    while(!cin)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "please enter the number of elements again: ";
        cin>> length;
    }
    
    for (int i = 0; i<= length -1; i++)
    {
        
        cout<< "Please enter the value of the "<<i+1<<" element: ";
        cin>>elementvalue;
        while(!cin)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "please enter the value of the element again: ";
            cin>> elementvalue;
        }
        numberstring.push_back(elementvalue);
    }
    return length;
}

void push_up(int i, vector<int>& numberstring)
{
    //              
    assert(true);
    //               
    //                                                                                                         
        while (numberstring[i] > numberstring[(i-1)/ 2])
        {
            swap(numberstring[i] , numberstring[(i-1)/2]);
            i = (i-1)/2;
            if (i == 0) break;
        }
}

void build_heap(vector<int>& numberstring, int length)
{
    //              
    assert(true);
    //               
    //                                 
    for (int i = 0; i<=length-1; i++)
    {
        push_up(i,numberstring);
    }
}

void push_down(int i, vector<int>& numberstring)
{
    //              
    assert(true);
    //               
    //                                                                                             
    int a = 0;
    
    //                                                                                                    
    while((((numberstring[a] < numberstring[2*a+1]) || ((numberstring[a] < numberstring[2*a+2]))) && (2*a+1 <= i)))
    {
        //                                
        if((numberstring[a] < numberstring[2*a+1])&& ((numberstring[2*a+1]>=numberstring[2*a+2])||(2*a+2 > i)))
        {
            swap(numberstring[a], numberstring[2*a+1]);
            a = 2*a+1;
        }
        else
            //                                      
            if(2*a+2 <= i)
            {
                swap(numberstring[a], numberstring[2*a+2]);
                a= 2*a+2;
            }
        else break;
    }
}

void pick_heap(vector<int>& numberstring, int length)
{
    //              
    assert(true);
    //               
    //                                         
    for (int i = length-1; i >= 0; i = i-1)
    {
        swap(numberstring[0], numberstring[i]);
        push_down(i-1, numberstring);
    }
}

int main(int argc, const char * argv[]) {
    //                     
    vector<int> numberstring;
    //                                                                                
    int length  =  enter_vector(numberstring);
    
    //             
    build_heap(numberstring, length);
    pick_heap(numberstring, length);
    
    //                                   
    for (int i = 0; i<= length-1; i++)
        cout << numberstring[i] <<" ";
    
    return 0;
}

/*
                                                
                                          
       
                           
                                                                                                    
                                                                                                   
 
                    
                                
                                             
                                                
                                      

       
   
        
                
                 
                   
                    
                     

  
              
               
                 
                   
                    
  
              
               
                 
                  
                   
  
            
             
               
                
                 
 
        
                             
                             
                             
                             
                             
                             
                             
                             
                             
 
   
                                                 
                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                                               
                                                                                                                                                                                         
                                                                                                                                                                      
 */


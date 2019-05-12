#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//                             
//                        

const int arrayLength = 7;
//                                       

void push_up(vector<int>& uArray)
{
    /*              */
    assert(true);
    /*                
                                                                                                  
                                                                                                    
                            */

    //                   
    //                                                            
    //                                                             
    //                                                                                    
    int tempValue = 0;
    for(int i = 0; i < arrayLength; i++)
    {
        if(((i-1)/2) >= 0)
        {
            if(uArray[i] > uArray[(i-1)/2])
            {
                tempValue = uArray[i];
                uArray[i] = uArray[(i-1)/2];
                uArray[(i-1)/2] = tempValue;
            }
        }
    }
}

void build_heap(vector<int>& uArray)
{
    //             

    assert(true);

    //              
    //              

    /*           
            
           
            
                
                  
                    

           
            
            
               
                  
                    

                                                                                        

                                                                                    

                                                                                         
    */
    int coutNo = 1;
    for(int i = 0; i < arrayLength; i+= coutNo)
    {
        for(int j = 0; j < coutNo; j++)
        {
            for(int k = 0; k < (arrayLength - coutNo)/2; k++)
                cout << "   ";
            cout << uArray[i - (coutNo - j)+1];
        }
        cout << endl;
        if(i != arrayLength - 1)
        for(int j = 0; j < coutNo; j++)
        {
            for(int k = 0; k < (arrayLength - coutNo)/2; k++)
                cout << "   ";
            cout << "/ \\";
        }
        cout << endl;
        coutNo*=2;
    }
}

void push_down(vector<int>& uArray)
{
    //             

    assert(true);

    //              
    //                                                                              

    //                  
    //                                                             
    //                                                             
    //                                                                                    
    int tempValue = 0;
    for(int i = 0; i < arrayLength; i++)
    {
        if(i < arrayLength){
            if(uArray[i] > uArray[i+1])
            {
                tempValue = uArray[i];
                uArray[i] = uArray[i+1];
                uArray[i+1] = tempValue;
            }
        }
    }
}

void pick_heap(vector<int>& uArray)
{
    //             

    assert(true);

    //              
    //                                                                     

    //                                               
    //                                 
    //                                                       
    //                                                            
    //                                                   
    for(int j = 0; j < arrayLength; j++)
    {
        swap(uArray[0], uArray[arrayLength-1]);
        for(int i = 0; i < arrayLength; i++)
            push_down(uArray);
    }
}

int main()
{
    vector<int> uArray = {15,40,42,-15,30,35,5};
    push_up(uArray);
    build_heap(uArray);
    pick_heap(uArray);
    build_heap(uArray);

    return 0;
}


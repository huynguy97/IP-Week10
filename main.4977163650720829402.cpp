#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

/*                                                  
                                    
                 

              

                                                                                   
                                                                                                                                      

              

  

           
             
              
               
                

           
             
              
               
                

           
             
              
               
                

           
             
              
               
                

           
             
              
               
                

                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          

                                                       
                                    
                                                         
                                   

                                                   */

void swapInt (int& a, int& b)
{
    //                            
    int temp = a;
    a = b;
    b = temp;
}

int childOne (vector<int>& data, int i, int upBound)
{
    assert (i >= 0 && i < upBound && upBound <= data.size());
    //                                                                                
    if (2 * i + 1 < upBound)
        return 2 * i + 1;
    else return 0;
}

int childTwo (vector<int>& data, int i, int upBound)
{
    assert (i >= 0 && i < upBound && upBound <= data.size());
    //                                                                                 
    if ((2 * i) + 2 < upBound)
        return 2 * i + 2;
    else return 0;
}

int parent (vector<int>& data, int i)
{
    assert(i < data.size() && i > 0);
    //                                          
    return (i-1) / 2;
}

bool checkUp(vector<int>& data, int el)
{
    assert (el < data.size());
    //                                                         
    if (el <= 0)
        return false;
    else return (data[parent(data, el)] < data[el]);
}

bool checkDown (vector<int>& data, int el, int upBound)
{
    //                                                                  
    int c1 = childOne(data, el, upBound);
    int c2 = childTwo(data, el, upBound);
    if (c1 <= 0)
    {
        if (c2 <= 0)
            return false;
        else return (data[c2] > data[el]);
    }
    if (c2 <= 0)
        return (data[c2] > data[el]);
    return (data[c2] > data[el] || data[c1] > data[el]);
}

void pushUp (vector<int>& data, int el)
{
    //                        
    do
    {
        swapInt(data[el],data[parent(data,el)]);
        el = parent(data, el);
        cout << "Vector is {";
        for (int i = 0; i < data.size(); i++)
            cout << data[i] << ",";
        cout << "}\n";
    } while (checkUp(data, el));
}
void pushDown (vector<int>& data, int upBound)
{
    //                                                                    
    int el = 0;
    while (checkDown(data, data[el], upBound))
    {
        int c1 = childOne(data, el, upBound);
        int c2 = childTwo (data, el, upBound);
        int el2;
        if (c1 <= 0)
            el2 = c2;
        else if (c2 <= 0 || data[c1] > data[c2])
            el2 = c1;
        else
            el2 = c2;
        swap(data[el],data[el2]);
        el = el2;
    }
}

void buildHeap (vector<int>& data)
{
    for (int i = 1; i < data.size(); i++)
    {
        if (checkUp(data, i))
        {
            pushUp(data, i);
        }
    }
}

void pickHeap (vector <int>& data)
{
    for (int upBound = data.size(); upBound > 1; upBound--)
    {
        swap(data[0],data[upBound-1]);
        pushDown(data, upBound);
    }
}

void heapSort (vector<int>& data)
{
    buildHeap(data);
    pickHeap (data);
}

int main()
{
    vector<int> testV = {15,40,42,-15,30,35,5};
    heapSort(testV);
    for (int i = 0; i < testV.size(); i++)
        cout << testV[i] << endl;

    cout << "End of code";

    return 0;
}


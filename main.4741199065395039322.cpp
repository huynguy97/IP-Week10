/*
                
                           
                       
                           
   */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//                                                    

vector<int> list = {15, 40, 42, -15, 30, 35, 5};

const int MAX = list.size();

void swap (vector<int>& list, int first,int second)
{
    //              
    assert(first >= 0 && first < MAX);
    assert(second >= 0 && second < MAX);
    //                                                                       

    int temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

void push_up(vector<int>& list, int i)
{
    //              
    assert(i >= 0 && i < MAX);
    //                                                              

    while (list[i] > list[(i-1)/2])
    {
        swap (list, i , (i-1)/2);
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& list)
{
    //              
    assert(true);
    //                                                                     

    for (int i = 1 ; i < MAX ; i ++)
    {
        push_up(list,i);
    }
}

void push_down(vector<int>& list, int MAX_EL)
{
    //              
    assert(MAX_EL >= 0);
    //               
    //                                                                           
    //                                                       
    while (MAX_EL > 0)
    {
        int i = 0;
        while (2*i+1 < MAX_EL)
        {
            if(2*i+2 < MAX_EL && (list[2*i+1] >= list[2*i+2]))
            {
                if (list[i] <= list[2*i+1])
                {
                    swap (list, i , 2*i + 1);
                    i = 2*i + 1;
                }
            }
            else if (2*i+2 < MAX_EL && (list[2*i+1] < list[2*i+2]))
            {
                if (list[i] <= list[2*i+2])
                {
                    swap (list, i , 2*i + 2);
                    i = 2*i + 2;
                }
            }
            else if (list[i] <= list[2*i+1])
            {
                swap (list, i , 2*i + 1);
                i = 2*i + 1;
            }
            i++;
        }
        for (int i = 0 ; i < MAX_EL; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl ;

        MAX_EL--;
    }
}

void pick_heap(vector<int>& list)
{
    //              
    assert(true);
    //              
    //                                                                         
    //                        
    int MAX_EL = MAX;

    for (int i = 0; i < MAX ; i++)
    {
        swap (list ,0, MAX_EL-1);
        cout<<"swapped: "<<endl;
        for (int j = 0 ; j< MAX; j++)
        {
            cout << list[j] << " ";
        }
        cout << endl ;
        MAX_EL--;
        push_down(list ,MAX_EL);
    }
}

int main() {
    //              
    assert(true);
    //               
    //                                                    
    //                       
    build_heap(list);

    cout << "Heaped array: " << endl;

    for (int i = 0; i < MAX; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    pick_heap(list);

    cout << "Sorted array: " << endl;

    for (int i = 0; i < MAX; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
           
  
          
                                             
                                                                                                    
  
          
                              
     
                                                          
                                                             
                                                                         
                                                                         
                                                                
  */


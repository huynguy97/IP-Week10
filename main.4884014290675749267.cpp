#include <iostream>
#include <cmath>

using namespace std;

/*
                                                                            

                               
                                                                                                                              
                                                                                                                                                              
                                                                                                      
*/

//                                          
//             
int arr[] = {15,40,42,-15,30,35,5};
int last = 6;

void push_up()
{
    for (int i = 1; i < 7; i++)
    {
        if (arr[i] > arr[(i-1)/2])
        {
            swap(arr[i], arr[(i-1)/2]);
            i = 0;
        }
        //                                                                                                                                                                                                                    
        cout << "Tussenstand: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << endl;
    }
}
void push_down()
{
    for(int i = 0; i <= ((last - 1) / 2) ; i++)
    {
        if ((i*2 +2) <= last)
        {
            if (arr[i] < arr[2*i+1] || arr[i] < arr[2*i+2])
            {
                if (arr[2*i+1] < arr[2*i+2])
                {
                    swap(arr[i], arr[2*i+2]);
                    i = -1;
                }
                else
                {
                    swap(arr[i], arr[2*i+1]);
                    i = -1;
                }
            }
        }
        else
        {
            if (arr[i] < arr [2*i+1])
            {
                swap (arr[i], arr[2*i+1]);
                i = -1;
            }
        }
    }

    //                                                                                                                                                                                                                    
    cout << "Final product: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << endl;
}

void pick_heap()
{
    while (last >= 1)
    {
        swap(arr[0], arr[last]);
        cout << "Final product: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << endl;

        last--;
        push_down();
        cout << "Last is: " << last << endl;
    }
}

int main()
{
    push_up();
    cout << "Push up done! Going to Push down now!" << endl;
    pick_heap();
    //                                                                                                                                                                                                                     
    cout << "Final product:" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << endl;
    return 0;
}


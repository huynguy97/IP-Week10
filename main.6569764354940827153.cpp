/*
                                                                                                                                             
          
                                                                                                           
*/

#include <iostream>
#include <vector>

using namespace std;

//                            
//                               

vector<int> sorting;

int size (vector<int>& sorting){
    return static_cast<int>(sorting.size());
}
int unsorted = sorting.size();

void swap(vector<int>& sorting, int& i, int k){
    int temp = sorting[i];
    sorting[i] = sorting[k];
    sorting[k] = temp;
}

void push_up(vector<int>& sorting, int& i){
    while(sorting[(i-1)/2] < sorting[i]){
        if ((i-1)/2 >= 0 && i < sorting.size() && sorting[i] > sorting[(i-1)/2]){
        int k = (i-1)/2;
        swap(sorting, i, k);
        }
    }
}

void push_down(vector<int>& sorting, int i, int size){
    //                           
    //                    

    bool heap = false;
    while (!heap){
            //     
            //     
        if (2*i+2 < size){
            if (sorting[2*i+1] < sorting[2*i+2]){
               if (sorting[i] < sorting[2*i+2])
                   swap(sorting, i, 2*i+2);
            }
        }
        else if (2*i+1 < size){
            if (sorting[2*i+1] > sorting[i]){
                swap(sorting, i, 2*i+1);
                i = 2*i+1;
            }
            else
                heap = true;
        }
        else {
            heap = true;
        }
    }
}

void pick_heap(vector<int>& sorting){
    for (int j = 0; j < unsorted; j++){
        swap(sorting[j], size-1);
        while(sorting[j] < sorting[unsorted - 1]){
            push_down(sorting, j);
        }
    }
}

int main()
{
    push_up();
    cout << "Pls give bonus points for the moeite xo" << endl;

    return 0;
}


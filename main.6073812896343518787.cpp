#include <iostream>
#include <cassert>
#include <vector>

//                                                                                                                                                  

using namespace std;

vector<int> VEC = {5,8,3,8,2,1,0,555,-4,-38-953,15,3434,11,50,2154,1254,515,73,1,5,2,4,8,8,8,5,4,31,64,72,15,7,7,7,7,151,15,-5,-8,-6,-4,-10,-9,-8,8,5};

int vSize(vector<int>& v)
{
    //             
    assert(true);
    //                                                       
    return static_cast<int>(v.size());
}

void swapEl(vector<int>& v, int indexA, int indexB)
{
    //             
    int vecSize = vSize(v);
    assert(vecSize > 0 && indexA >= 0 && indexA < vecSize && indexB >= 0 && indexB < vecSize);
    //                                                  

    int temp = v[indexA];
    v[indexA] = v[indexB];
    v[indexB] = temp;
}

void push_up(vector<int>& v, int index)
{
    //             
    assert (index >= 0 && vSize(v) > 0);
    //                                                                                                                                                                      

    int parent = (index-1)/2;

    while(parent >= 0 && v[parent] < v[index]){
        swapEl(v, index, parent);
        index = parent;
        parent = (index-1)/2;
    }
}

void build_heap(vector<int>& v)
{
    //             
    assert (vSize(v) > 0);
    //                                                                                               
    int vectorSize = vSize(v);
    for (int i = 0; i < vectorSize; i++){
        push_up(v,i);
    }
}

struct Child
{
    bool inScope;
    int index;
};

void push_down(vector<int>& v, int sortedIndex)
{
    //             
    assert(vSize(v) > 0 && sortedIndex >= 0 && sortedIndex < vSize(v));
    //                                                                                                   

    bool noSwapped = false;
    int index = 0;
    Child child1 = {false, index*2+1};
    Child child2 = {false, index*2+2};

    if (child1.index < sortedIndex){
        child1.inScope = true;
    }
    if (child2.index < sortedIndex){
        child2.inScope = true;
    }

    while ((child1.inScope || child2.inScope) && !noSwapped){
        if (!child2.inScope){ //            
            if (v[child1.index] > v[index])
            {
                swapEl(v, index, child1.index);
                index = child1.index;
            } else {
                noSwapped = true;
            }
        } else { //            
            if (v[child1.index] > v[index] || v[child2.index] > v[index]){
                if (v[child1.index] >= v[child2.index]){
                    swapEl(v, index, child1.index);
                    index = child1.index;
                } else {
                    swapEl(v, index, child2.index);
                    index = child2.index;
                }
            } else {
                noSwapped = true;
            }
        }

        //                   
        child1 = {false, index*2+1};
        child2 = {false, index*2+2};

        if (child1.index < sortedIndex){
            child1.inScope = true;
        }
        if (child2.index < sortedIndex){
            child2.inScope = true;
        }
    }

}

void pick_heap(vector<int>& v)
{
    //             
    assert (vSize(v) > 0);
    //                                                                                                                             
    int vectorSize = vSize(v);
    for (int i = 0; i < (vectorSize-1); i++){ //                                                               
        int sortedIndex = vectorSize-1-i;
        swapEl(v, 0, sortedIndex); //                               
        push_down(v, sortedIndex);
    }
}

void print_vec(vector<int>& v)
{
    //             
    assert (vSize(v) > 0);
    //                                               

    cout << "{";
    int vectorSize = vSize(v);
    for (int i = 0; i < vectorSize; i++){
        cout << v[i];
        if (i != vectorSize-1){
                cout << ",";
        }
    }
    cout << "}" << endl;
}

void heap_sort(vector<int>& v)
{
   //             
    assert (vSize(v) > 0);
    //                                                                                           
    build_heap(v);

    cout << "Result of Phase 1, heap:" << endl;
    print_vec(v);
    pick_heap(v);
}

int main()
{
    //            
    assert(true);
    //                                                  

    cout << "This program sorts a integer Vector in non-decreasing order." << endl;
    heap_sort(VEC);
    cout << "Final result, sorted vector: " << endl;
    print_vec(VEC);
    return 0;
}

/*

                                                             

                                                                                                                                                     
                                                                                                                                                          

                                                                                                                                                               
                                                                                                                                              

                                                     

                                        
                                          
                                           
                                            
                                             

                                        
                                          
                                           
                                            
                                             

                                        
                                          
                                           
                                            
                                             

                                        
                                          
                                           
                                            
                                             

                                        
                                          
                                           
                                            
                                             

                                    
                                   

                                   
                                   
                                   

                                   
                                   
                                   

                                   
                                   

                                   
                                   

                                   

                                   
                                         

                                                                                                                                                                                           
                                                                                                                                                                   
                                                                                                                                                                              
                                                                                                                                                                                                       

                                                                                                                                                                                               

                                                                                                                                               
                                                                                                                                                                                              

                                                                                                                                                                      

*/


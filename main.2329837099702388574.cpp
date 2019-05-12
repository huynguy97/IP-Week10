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

//                         
vector<int> vi;

void load_values(vector<int>& vi)
{
    //             
    assert(true);
    //             
    //                                     

    vi.push_back(2);
    vi.push_back(9);
    vi.push_back(-1);
    vi.push_back(8);
    vi.push_back(6);
    vi.push_back(-3);
    vi.push_back(4);
}

void print_vi(const vector<int>& vi)
{
    //             
    assert(true);
    //             
    //                 

    cout << "{";
    for(int i = 0; i < vi.size(); i++){
        cout << vi[i] << ", ";
    }
    cout << "}";
}

void swap(vector<int>& data, int i, int j)
{
    //             
    assert(i >= 0 || j >= 0);
    //             
    //                        

	const int temp = data.at(i);
	data [i] = data.at(j) ;
	data [j] = temp;
}

void push_up(vector<int>& vi, int pos)
{
    //             
    assert(pos >= 0);
    //             
    //                

    if(vi[pos] > vi[(pos-1)/2]){
        swap(vi, pos, (pos-1)/2);
    }
}

void build_heap(vector<int>& vi)
{
    //             
    assert(true);
    //             
    //                      

    for(int i = 1; i < vi.size(); i++){
        push_up(vi, i);
    }
}

void push_down(vector<int>& vi, int pos, int& new_pos, int active_size)
{
    //             
    assert(pos >= 0 || new_pos >= 0);
    //             
    //                  

    if(active_size <= 2*pos+1){
        new_pos = pos;
        return;
    }

    if(active_size <= 2*pos+2){
        if(vi[2*pos+1] > vi[pos]){
            swap(vi, 2*pos+1, pos);
            new_pos = 2*pos+1;
        }
        else{
          new_pos = pos;
        }
        return;
    }

    if(vi[2*pos+1] < vi[2*pos+2]){
        if(vi[2*pos+2] > vi[pos]){
            swap(vi, 2*pos+2, pos);
            new_pos = 2*pos+2;
        }
        else{
            new_pos = pos;
        }
    }
    else{
        if(vi[2*pos+1] > vi[pos]){
            swap(vi, 2*pos+1, pos);
            new_pos = 2*pos+1;
        }
        else{
          new_pos = pos;
        }
    }

}

void pick_heap(vector<int>& vi)
{
    //             
    assert(true);
    //             
    //            

    int new_pos, pos;
    int active_size =  static_cast<int>(vi.size());

    while(active_size > 0){
        active_size--;
        swap(vi, 0, active_size);
        pos = -1;
        new_pos = 0;
        while(pos != new_pos){
            pos = new_pos;
            push_down(vi, pos, new_pos, active_size);
            print_vi(vi);
            cout << endl;
        }
    }
}

int main()
{

    load_values(vi);
    build_heap(vi);
    print_vi(vi);
    cout << endl;
    pick_heap(vi);
    return 0;
}


#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//                                                                             
//                                                                             
//                                                                             
//                                                                             
//                                                                             

/*
       

                                                                                                                       
                                                                                     

                                                                                                                         

        

   

                                 

           
            
              
              
               

         

           
            
              
              
               

           
            
              
              
               

           
            
              
              
               

           
            
              
              
               

        

                      

                      

                      

                      

                      

                      

                      

                      

                      

                      

                      

                      

                                                                                                                                                                                                   
                                                                               

                                                                                                                                                                                                                            

                                                                                                                                                                                                          

                                                                                                                                                                   

 */

 vector<int> array_test={15, 40, 42, -15, 30, 35, 5};

void swap(vector<int>& array, int a, int b) {

    assert(a>=0 && b>=0);

    int save=array[a];
    array[a]=array[b];
    array[b]=save;
}

 void push_up(vector<int>& array, int i){

     assert(i>=0);

     if(array[2*i+1]> array[i] && 2*i+1<(array.size()-1))
     {
        swap(array, i, 2*i+1);
     }

     if(array[2*i+2]> array[i] && 2*i+2<(array.size()-1))
     {
         swap(array, i, 2*i+2);
     }
 }

 void build_heap(vector<int>&array){

     for(int i=0;i<array.size();i++){
         push_up(array,i);
     }
 }

 void push_down(vector<int>& array, int i, int max) {

    assert(i>=0 && max>=0);

    bool done=false;

     int compare;
     int place;
     while (!done) {
         if(2*i+1>max){
             done=true;
         }
         else if(2*i+2>max){
             done=true;
         }

         if(array[2*i+1]>array[2*i+2]){
             compare=array[2*i+1];
             place=2*i+1;
         }
         else {
             compare=array[2*i+2];
             place=2*i+2;
         }

         if(compare>array[i]&& place<max){
             swap(array,i,place);
             i=place;
         }
         else{
             done=true;
         }

 }
}

 void pick_heap(vector<int>& array){

     int unsorted=array.size()-1;
     for (int i = unsorted; i >= 0 ; i--) {
         swap(array,0,i);
         push_down(array,0,i);
     }
 }

int main() {

    cout<<"The array before sorting: ";

    cout<<"{";
    for(int i=0; i<array_test.size();i++)
    {
        cout<<array_test[i]<<",";
    }
    cout<<"}"<<endl;
    //                                           

    build_heap(array_test);
    pick_heap(array_test);

    cout<< "The array after sorting: ";

    cout<<"{";
    for(int i=0; i<array_test.size();i++)
    {
        cout<<array_test[i]<<",";
    }
    cout<<"}";

    //                                                 
}

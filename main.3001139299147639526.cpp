#include <iostream>
#include <vector>

/*                                                     
                                                        
                
                                                   
                                                                                            
                                                                                                                                      
                                                                                                                                 
                                  
                                               
                                                    
                        
                              
                                 
                    
                       
                              
                                 
                    
                        
                              
                                 
                    
                        
                              
                                 
                    
                        
                              
                                 
                    
                        
                              
                                 
  
                    
                        
                              
                                 
                                                       
  
            
                         
                                
                                  
                                  
                                  
                                    
                                      
                                      
                                        
                                        
                                          
                                              
  
     
                                                                                                          
                                                                                                                                     
                                 
  
                                                                                                                                                
                                                             
  
                                                                                                                                        
                                 
  
                                                                                                                                  
                                                                                                                                                   
                                                                                           
  
                                                                                                             
                                                                                                                                
  
  
  
  
  
 */
using namespace std;

void heapify (vector <int>& vector1, int size, int i){
    int biggest = i;
    int a = 2 * i + 1;
    int b = 2 * i + 2;

    if (a < size && vector1[a] > vector1[biggest]){
        biggest = a;
    }
    if (b < size && vector1[b] > vector1[biggest]){
        biggest = b;
    }

    if (biggest != i){
        swap(vector1[i], vector1[biggest]);
        heapify(vector1, size, biggest);
    }
}

void heap_sort ( vector <int>& vector1, const int size) {
    //              
    for (int i = ((size / 2 )- 1); i >= 0; i-- ){
        heapify(vector1, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(vector1[0], vector1[i]);
        heapify(vector1, i, 0);
    }
}

void display_vector(vector <int> vector1) {
    for (int i =0; i < vector1.size(); i++) {
        cout << vector1[i] << " ";
    }
    cout << endl;

}

int main() {
       vector <int> unsorted;
       string input;

      do {
          cout << "Enter the operation (Show, Add, Sort, Stop): ";
          getline(cin, input);
          if (input == "Show") {
              if (unsorted.empty()){
                  cout << "The list is still empty, you should add some numbers!" << endl;
              }
              display_vector(unsorted);
          } else if(input == "Add") {
              int amount;
              int number;
              cout << "Enter the amount of numbers you want to add to the list: " << endl;
              cin >> amount;

              for (int i = 0; i < amount; i++){
                  cout << "Enter number:  ";
                  cin >> number;
                  cout << endl;
                  unsorted.push_back(number);
              }
              cout << "Succesfully added numbers to the list" << endl;
          } else if(input == "Sort") {
              int size = unsorted.size();
              heap_sort(unsorted, size);
              cout << "Succesfully sorted" << endl;
          }
          cout << endl;
      }
      while (input != "Stop");

     return -1;

}

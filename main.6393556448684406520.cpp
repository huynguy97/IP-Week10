#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<int> numbers = {15,40,42,-15,30,35,5};
const int NUMSIZE = numbers.size();

void print_heap(vector<int>& numbers) {
	cout << '{';
	for (int i = 0; i<NUMSIZE; i++) {
		cout << numbers[i];
		if (i != NUMSIZE-1) 
			cout << ',';
	}
	cout << "}\n";
}

void swap(vector<int>& numbers, int n0, int n1) {
	//                         
	
	int temp = numbers[n0];
	numbers[n0] = numbers[n1];
	numbers[n1] = temp;
	print_heap(numbers);
}

void push_up(vector<int>& numbers, int i) {
	//                          
	swap(numbers, i, (i-1)/2);
}

void push_down(vector<int>& numbers, int i, int heapsize) {
	//                                        
	bool swapped;
	do {
		swapped = false;
		if (2*i+2 <= heapsize-1){
			if (numbers[2*i+1] > numbers[2*i+2] || 2*i+2 == heapsize-1) {
				if (i < numbers[2*i+1]) {
					swap(numbers, i, 2*i+1);
					i = 2*i+1;
					swapped = true;
				}
			}
			else if (i < numbers[2*i+2]) {
				swap(numbers, i, 2*i+2);
				i = 2*i+2;
				swapped = true;
			}
		}
	} while (swapped);
}

void build_heap(vector<int>& numbers, int heapsize) {
	//                              
	for (int i = NUMSIZE-1; i>0; i--) {
		cout << i << ' '<< numbers[i] << ' ' << numbers[(i-1)/2] <<'\n';
		//                                                
		int j = i; 
		while (numbers[j] > numbers[(j-1)/2]) {
			push_up(numbers, j);
			j = (j-1)/2;
		}
	}
	cout << "\n\n";
}

void pick_heap(vector<int>& numbers) {
	int heapsize = NUMSIZE;
	while (heapsize > 1) {
		swap(numbers, 0, heapsize-1);
		push_down(numbers, 0, heapsize);
		cout << "heapsize: " << heapsize << "\n";
		heapsize--;
	}
}

int main() {	
	build_heap(numbers, NUMSIZE);
	pick_heap(numbers);
	return 0;
}

//             

/*                                                            
	   	  
	        
	  	       
                 
                   

	  	  
	        
	  	       
                 
                           

		 
	        
	  	       
                 
                    

		                       
	        
	  	       
                 
                  

                        
	        
	  	       
                 
                   

	                        
	        
	  	      
                 
                   

                       
	        
	  	      
                 
                   

                            
	        
	  	      
                 
                   

                        
	        
	  	      
                 
                  

	                        
	        
	   	      
                 
                  

	                  
	        
	   	       
                 
                  

		                   
	        
	   	       
                 
                  

		                
	        
	 	       
              
                  

                                                                                            
                                                                                                                                                                                     
                                                                                                                                
                                                                                                                                                                                                */


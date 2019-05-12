//                                                     
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/*
      
                      
                                                                                                
   
        
                                                                                                                                                

      
              
	             
	              
	               
	               
                                                                                 

              
	             
	              
	               
	               
                                                                
              
	             
	              
	               
	               
                                                                                                     
              
	             
	              
	               
	               
                                                                                                     
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  
                                                             
                                                                                                                                                                                                                                                                                             
                                                    
                                                                                                                                     

 */

void swap(int& l, int& r){
	//              
	assert(true);
	//                                                     
	const int TEMP = l;
	l = r;
	r = TEMP;
}

void push_up(vector<int>& heap, int n){
	//              
	assert(n>=0&&n<heap.size());
	//                                                                                                           
	if(n==0){
		//              
	} else {
		const int TEMP = heap[n];
		heap[n] = heap[(n-1)/2];
		heap[(n-1)/2] = TEMP;
	}
}

int push_down(vector<int>& heap, int heapsz, int n){
	//              
	assert(n>=0&&n<heapsz);
	//               
	//                                                                                                                                                                                                                                                     
	if(n*2+2<heapsz){
		int l = heap[n*2+1], r=heap[n*2+2];
		if(l>=r&&l>heap[n]){
			swap(heap[n], heap[n*2+1]);
			return n*2+1;
		} else if(r>=l&&r>heap[n]){
			swap(heap[n], heap[n*2+2]);
			return n*2+2;
		} else {
			return n;
		}
	} else if(n*2+1<heapsz){
		//                                                                          
		if(heap[n*2+1]>heap[n]){
			swap(heap[n], heap[n*2+1]);
			return n*2+1;
		} else {
			return n;
		}

	} else {
		//                                   
		return n;
	}
}

void build_heap(vector<int>& heap){
	//              
	assert(true);
	//               
	//                                                           
	for(int i=0; i<heap.size(); i++){
		int n = i;
		bool right_spot = false;
		while(n!=0&&!right_spot){
			//                                                                   
			if(heap[(n-1)/2]<heap[n]){
				//                               
				swap(heap[(n-1)/2], heap[n]);
				n = (n-1)/2;
			} else {
				right_spot = true;
			}
		}
	}
}

void pick_heap(vector<int>& heap){
	//              
	assert(true);
	//                                                                                                            
	int heapsz = heap.size();
	for(int i=0; i<heap.size(); i++){
		swap(heap[0], heap[heapsz-1]);
		heapsz--;
		int n=0;
		bool right_spot = false;
		while(!right_spot&&heapsz>0){
			//                                                       
			int nn = push_down(heap, heapsz, n);
			if(nn==n)
				right_spot = true;
			else
				n = nn;
		}
	}
}

void heap_sort(vector<int>& a){
	//              
	assert(true);
	//                                                
	build_heap(a);
	pick_heap(a);
}

int main(){
	int N;
	vector<int> v;
	cin>>N;
	v.assign(N, 0);
	for(int n=0; n<N; n++)
		cin>>v[n];
	heap_sort(v);
	for(int x=0; x<N; x++)
		cout << v[x] << endl;
}


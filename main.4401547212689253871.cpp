#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//                          
//                       

/*                                                                   
                                                  
 */
void easter(int year, int& day, int& month) {
    const int a = year % 19 ;
    const int b = year / 100 ;
    const int c = year % 100 ;
    const int d = b / 4 ;
    const int e = b % 4 ;
    const int f = (b + 8) / 25 ;
    const int g = (b - f + 1) / 3 ;
    const int h = (19 * a + b - d - g + 15) % 30 ;
    const int i = c / 4 ;
    const int k = c % 4 ;
    const int L = (32 + 2 * e + 2 * i - h - k) % 7 ;
    const int m = (a + 11 * h + 22 * L) / 451 ;
    month       =  (h + L - 7 * m + 114) / 31 ;
    day         = ((h + L - 7 * m + 114) % 31) + 1 ;
}

/*                                                                         
                                                                  
 */
bool is_prime(int x, int& divisor) {
    if (x <= 1)
        return false ;
    for (divisor = 2 ; divisor <= sqrt(static_cast<double>(x)); divisor++) {
        if (x % divisor == 0)
            return false ;
    }
    return true ;
}

/*        
              
            
              
                
                 
                  
  
            
              
                
                 
                  
  
            
              
                
                 
                  
  
            
              
                
                 
                  
  
             
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
  
                                                                          
                                
 */

/*                   
 */
void swap(int& a, int& b) {
    int c = b;
    b = a;
    a = c;
}

/*                                                                       
                                                
 */
void push_up(vector<int>& v, int i) {
    assert(i >= 0);
    assert(i < (int)v.size());

    if (i == 0)
        return;

    if (v[i] > v[(i-1)/2]) {
        swap(v[i], v[(i-1)/2]);
        push_up(v, (i-1)/2);
    }
}

/*                                                                           
                                       
 */
void build_heap(vector<int>& v) {
    assert(true);

    for (int i = 1; i < (int)v.size(); i++)
        push_up(v, i);
}

/*                                                                          
 */
void push_down(vector<int>& v, int i, int e) {
    assert(i >= 0);
    assert(i < (int)v.size());

    if (2*i+2 < e) {
        if (v[2*i+1] >= v[2*i+2] &&
                v[i] < v[2*i+1]) {
            swap(v[i], v[2*i+1]);
            push_down(v, 2*i+1, e);
        } else if (v[i] < v[2*i+2]) {
            swap(v[i], v[2*i+2]);
            push_down(v, 2*i+2, e);
        }
    } else if (2*i+1 < e) {
        if (v[i] < v[2*i+1]) {
            swap(v[i], v[2*i+1]);
        }
    }
}

/*                                                                              
 */
void pick_heap(vector<int>& v) {
    assert(true);

    for (int i = v.size() - 1; i >= 0;) {
        swap(v[0], v[i]);
        push_down(v, 0, --i);
    }
}

/*                                                                              
                                                                  
 */
int main(int argc, char* argv[]) {
    vector<int> v;

    for (int i = 1; i < argc; i++)
        v.push_back(stoi(argv[i]));

    build_heap(v);

    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;

    pick_heap(v);

    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;

    return 0;
}



// https://www.geeksforgeeks.org/rank-elements-array/
#include<bits/stdc++.h> 
  

  
int main() 
{
    std::vector<int> v = {0, 1, 2, 5, 2, 1, 25, 2};

    std::vector<int> v2(v);
    std::sort(v.begin(), v.end());
    std::map<int, float> mapping;
    int index_counter = 0;
    // for(int i = 1 ; i < v.size() ; i++){
    //     std::cout << i << " " ;
    // }
    // std::cout << std::endl;
    // for(int i = 1 ; i < v.size() ; i++){
    //     std::cout << v[i] << " " ;
    // }
    // std::cout << std::endl;


    for(auto i = v.begin()+1 ; i != v.end() ;  ){
        auto index =  std::upper_bound( i, v.end(), *i );
        int n2 = index-v.begin();
        int n1 = i-v.begin();
        // std::cout << n1 <<" = " << n2  << " >> ";

        int sumn1 = (n1*(n1-1))/2;
        int sumn2 = (n2*(n2-1))/2;
        // std::cout << sumn1 << " " << sumn2 << " = " << (sumn2-sumn1)/(float)(n2-n1) << std::endl;
        mapping.insert(std::make_pair(*i, (sumn2-sumn1)/(float)(n2-n1) ) );
        i = index;
    }
    for(int i = 1  ;  i  < v.size() ; i++){
        if( mapping.find( v2[i] ) != mapping.end() ){
            std::cout << mapping.find( v2[i] )->second << " ";
        }
    }
    std::cout << std::endl;
    return 0; 
} 

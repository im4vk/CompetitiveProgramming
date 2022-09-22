#include "headers.h"

vector<int> z_algorithm(const string& s)
{
  vector<int> v(s.size());
  v[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i + j < s.size() && s[j] == s[i + j]) j++;
    v[i] = j;
 
    if(j == 0){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && k + v[k] < j){
      v[i + k] = v[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return v;
}

#include <bits/stdc++.h>
using namespace std;
class SparseTable{
private:
  typedef int t_st;	
  vector<vector<t_st> > st;
  vector<int> log2;
  t_st neutral = 0x3f3f3f3f;
  int nLog;
  t_st join(t_st a, t_st b){
    return min(a, b);
  }
public:
  template <class MyIterator>
	SparseTable(MyIterator begin, MyIterator end){
    int n = end-begin;
    nLog = 20;
    log2.resize(n+1);
		log2[1] = 0;
		for (int i = 2; i <=n; i++)
			log2[i] = log2[i/2] + 1;
    st.resize(n, vector<t_st>(nLog, neutral));
    for(int i=0; i<n; i++, begin++)
      st[i][0] = (*begin);
    for(int j=1; j<nLog; j++)
      for(int i=0; (i+(1<<(j-1))) < n; i++)
        st[i][j] = join(st[i][j-1], st[i+(1<<(j-1))][j-1]);					
	}	
	//0-indexed [a, b]
  t_st query(int a, int b){
    int d = b - a + 1;
    t_st ans = neutral;
    for(int j=nLog-1; j>=0; j--){
      if(d & (1<<j)){
        ans = join(ans, st[a][j]);
        a = a + (1<<(j));
      }
    }
    return ans;
  }
	//0-indexed [a, b]
  t_st queryRMQ(int a, int b){
		int j = log2[b - a + 1];
		return join(st[a][j], st[b - (1 << j) + 1][j]);	
  }
};
#include <bits/stdc++.h>
using namespace std;
struct StackQuery{
	typedef int t_stack;
	stack<pair<t_stack, t_stack> > st;	
  t_stack cmp(t_stack a, t_stack b){
    return min(a, b);
  }
	void push(t_stack x){
		t_stack new_value = st.empty() ? x : cmp(x, st.top().second);
		st.push({x, new_value});	
	}
	void pop(){
		st.pop();
	}
	t_stack top(){
		return st.top().first;
	}
	t_stack query(){
		return st.top().second;
	}
	t_stack size(){
		return st.size();
	}		
};
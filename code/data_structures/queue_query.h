#include <bits/stdc++.h>
using namespace std;
class QueueQuery{
private:
	typedef int t_queue;
	stack<pair<t_queue, t_queue> > s1, s2;
   t_queue cmp(t_queue a, t_queue b){
      return min(a, b);
   }
   void move(){
		if (s2.empty()) {
			while (!s1.empty()) {
				t_queue element = s1.top().first;
				s1.pop();
				t_queue result = s2.empty() ? element : cmp(element, s2.top().second);
				s2.push({element, result});
			}
		}
   }
public:
	void push(t_queue x){
		t_queue result = s1.empty() ? x : cmp(x, s1.top().second);
		s1.push({x, result});	
	}
	void pop(){
    move();
		s2.pop();	
	}
	t_queue front(){
    move();
		return s2.top().first;
	}
	t_queue query(){
		if (s1.empty() || s2.empty()) 
			return s1.empty() ? s2.top().second : s1.top().second;
		else
			return cmp(s1.top().second, s2.top().second);
	}	
	t_queue size(){
		return s1.size() + s2.size();
	}	
};
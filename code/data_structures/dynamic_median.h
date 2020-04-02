#include <bits/stdc++.h>
using namespace std;
class DinamicMedian{
	typedef int t_median;
private:
	priority_queue<t_median> mn;
	priority_queue<t_median, vector<t_median>, greater<t_median>> mx;
public:
	double median(){
		if (mn.size() > mx.size())
			return mn.top();
		else
			return (mn.top() + mx.top()) / 2.0;
	}
	void push(t_median x){
		if (mn.size() <= mx.size())
			mn.push(x);
		else
			mx.push(x);
		if ((!mx.empty()) and (!mn.empty())){
			while (mn.top() > mx.top()){
				t_median a = mx.top();
				mx.pop();
				t_median b = mn.top();
				mn.pop();
				mx.push(b);
				mn.push(a);
			}
		}
	}
};

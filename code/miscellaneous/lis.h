#include <bits/stdc++.h>
using namespace std;
vector<int> lis(vector<int> &v){	
	vector<int> st, ans;
	vector<int> pos(v.size()+1), dad(v.size()+1);
	for(int i=0; i < (int)v.size(); i++){		
		auto it = lower_bound(st.begin(), st.end(), v[i]); // Do not accept repeated values
		//auto it = upper_bound(st.begin(), st.end(), v[i]); //Accept repeated values		
		int p = it-st.begin();		
		if(it==st.end()) 
			st.push_back(v[i]);
		else 
			*it = v[i];		
		pos[p] = i;		
		dad[i] = (p==0)? -1 : pos[p-1]; 			
	}	
	int p = pos[st.size() - 1];	
	while(p >= 0){
		ans.push_back(v[p]);
		p=dad[p];
	}	
	reverse(ans.begin(), ans.end());	
	return ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef int32_t intB; 
typedef int64_t longB;
typedef vector<intB> vib;
class BigInt{
private:
	vib vb;
	bool neg;
	const int BASE_DIGIT = 9;
	const intB base = 1000000LL*1000;//000LL*1000000LL;
	void fromString(string &s){
		if(s[0] == '-'){
			neg = true;
			s = s.substr(1);
		}else{
			neg = false;
		}
		vb.clear();
		vb.reserve((s.size()+BASE_DIGIT-1)/BASE_DIGIT);
		for(int i=(int)s.length(); i>0; i-=BASE_DIGIT){
			if(i < BASE_DIGIT)
				vb.push_back(stol(s.substr(0, i)));
			else
				vb.push_back(stol(s.substr(i-BASE_DIGIT, BASE_DIGIT)));		
		}
		fix(vb);
	}
	void fix(vib &v){
		while(v.size()>1 && v.back()==0)
			v.pop_back();
		if(v.size() == 0)
			neg = false;
	}
	bool comp(vib &a, vib &b){
		fix(a); fix(b);
		if(a.size() != b.size()) return a.size() < b.size();
		for(int i=(int)a.size()-1; i>=0; i--) {
			if(a[i] != b[i]) return a[i] < b[i];
		}
		return false;
	}
	vib sum(vib a, vib b){
		int carry = 0;
		for(size_t i=0; i<max(a.size(), b.size()) or carry; i++){
			if(i == a.size())
				a.push_back(0);
			a[i] += carry + (i<b.size() ? b[i] : 0);
			carry = (a[i] >= base);
			if(carry) a[i] -= base;
		}
		fix(a);
		return a;
	}
	vib sub(vib a, vib b){
		int carry = 0;
		for(size_t i=0; i<b.size() or carry; i++){
			a[i] -= carry + (i<b.size() ? b[i] : 0);
			carry = a[i] < 0;
			if(carry) a[i] += base;
		}
		fix(a);		
		return a;
	}	

public:
	BigInt(){}
	BigInt(intB n){ 
		neg = (n<0);
		vb.push_back(abs(n)); 
		fix(vb);
	}
	BigInt(string s){
		fromString(s);
	}
	BigInt operator =(BigInt oth){
		this->neg = oth.neg;
		this->vb = oth.vb;
		return *this;
	}
	BigInt operator +(BigInt &oth){
		vib &a = vb, &b = oth.vb;
		BigInt ans;
		if(neg == oth.neg){
			ans.vb = sum(vb, oth.vb);
			ans.neg = neg;
		}else{
			if(comp(a, b)){
				ans.vb = sub(b, a);
				ans.neg = oth.neg; 
			}else{
				ans.vb = sub(a, b);
				ans.neg = neg; 
			}
		}
		return ans;
	}
	BigInt operator -(BigInt oth){
		oth.neg ^= true;
		return (*this) + oth;	
	}
	BigInt operator *(intB b){
		bool negB = false;
		if(b < 0){
			negB = true;
			b = -b;
		}
		BigInt ans = *this;
		auto &a = ans.vb;
		intB carry = 0;
		for(size_t i=0; i<a.size() or carry; i++){
			if(i == a.size()) a.push_back(0);
			longB cur = carry + a[i] *(longB) b;
			a[i] = intB(cur%base);
			carry = intB(cur/base);
		}
		ans.neg ^= negB;
		fix(ans.vb);
		return ans;	
	}
	BigInt operator *(BigInt &oth){
		BigInt ans;
		auto a = vb, &b = oth.vb, &c = ans.vb;
		c.assign(a.size() + b.size(), 0);
		for(size_t i=0; i<a.size(); i++){
			intB carry=0;
			for(size_t j=0; j<b.size() or carry; j++){
				longB cur = c[i+j] + a[i]*(longB)(j<b.size() ? b[j] : 0);
				cur += carry;
				c[i+j] = intB(cur%base);
				carry = intB(cur/base);
			}
		}
		ans.neg = neg^oth.neg;
		fix(ans.vb);
		return ans;
	}
	BigInt operator /(intB b){
		bool negB = false;
		if(b < 0){
			negB = true;
			b = -b;
		}
		BigInt ans = *this;
		auto &a = ans.vb;
		intB carry = 0;
		for(int i=(int)a.size()-1; i>=0; i--){
			longB cur = a[i] + (longB)carry * base;
			a[i] = intB(cur/b);
			carry = intB(cur%b);
		}
		ans.neg ^= negB;
		fix(ans.vb);
		return ans;	
	}
	void shiftL(int b){
		vb.resize(vb.size() + b);
		for(int i=(int)vb.size()-1; i>=0; i--) {
			if(i>=b) vb[i] = vb[i-b];
			else vb[i] = 0;
		}
		fix(vb);
	}
	void shiftR(int b) {
		if((int)vb.size() <= b){
			vb.clear();
			vb.push_back(0);
			return;
		}
		for(int i=0; i<((int)vb.size() - b); i++)
			vb[i] = vb[i+b];		
		vb.resize((int)vb.size() - b);
		fix(vb);
	}
	void divide(BigInt a, BigInt b, BigInt &q, BigInt &r){
		BigInt z(0), p(1);
		while(b < a) {
			p.shiftL(max(1, int(a.vb.size()-b.vb.size())));
			b.shiftL(max(1, int(a.vb.size()-b.vb.size())));
		}
		while(true) {
			while ((a < b) && (z < p)) {
				p = p/10;
				b = b/10;
			}
			if(!(z < p)) break;
			a = a - b;
			q = q + p;
		}
		r = a;
	}
	BigInt operator /(BigInt &oth){
		BigInt q, r;
		divide(*this, oth, q, r); 
		return q;
	}
	BigInt operator %(BigInt &oth){
		BigInt q, r;
		divide(*this, oth, q, r); 
		return r;
	}	
	bool operator <(BigInt &oth){
		BigInt ans = (*this) - oth;
		return ans.neg;
	}
	bool operator ==(BigInt &oth){
		BigInt ans = (*this) - oth;
		return (ans.vb.size()==1) and (ans.vb.back()==0);
	}
	friend ostream &operator<<(ostream &out, const BigInt &D){
		if(D.neg)
			out << '-';
		out << (D.vb.empty() ? 0 : D.vb.back());
		for(int i=(int)D.vb.size()-2; i>=0; i--)
			out << setfill('0') << setw(D.BASE_DIGIT) << D.vb[i];
		return out;            
	}
	string to_string(){
		std::stringstream ss;
		ss << (*this);
		return ss.str();
	}
	friend istream &operator>>(istream  &input, BigInt &D) { 
		string s;
		input >> s;
		D.fromString(s);
		return input;            
	}
};
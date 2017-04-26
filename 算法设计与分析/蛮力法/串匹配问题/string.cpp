//串匹配问题
 
#include <iostream>
#include <string>

using namespace std; 

class Match {
	public:
		virtual int String_Match(string s, string t) = 0;
};

class BF_Match:Match {
	public:
		int String_Match(string s, string t) {
			int s_length = s.length(), t_length = t.length(), i , j, locate = -1;
			for (i = 0; i<=s_length; i++) {
				for (j = 0; j<t_length; j++) {
					if(s[i+j] == t[j]) {
						continue;
					} else {
						break;
					}
				}
				if(j == t_length) {
					locate = i;
					break;
				}
			}
			return locate;
		}
		
};

class KMP_Match:Match {
	public:
		void Get_Next(string s, int* next) {
			int s_length = s.length(), index, len, j;
			next[0] = 0;
			for (index = 1; index < s_length; index++) {
				for (len = index-1; len >= 1; len--) {		//index-1,因为算的是下标index之前的子串长度 
					for (j = 0; j < len; j++) {			//依次比较 
						if (s[j] != s[index-len+j]){			//画图理解 
							break;
						}
					}
					if (j == len){
						next[index]= len;
						break;
					}
				}
				if (len < 1) {
					next[index]=0;
				}
			}
		}
		
		int String_Match(string s, string t) {
			int locate = -1, s_length = s.length(), t_length = t.length();
			int *next = new int[s_length];
			Get_Next(t, next);
			int i = 0, j = 0;
			while (i < s_length && j < t_length) {
				if (s[i] == t[j]) {
					i++;
					j++;
				} else {
					if (next[j]!=0){
						j = j-next[j];
					}
					else {
						i = i+j+1;
						j = 0;
					}
				}
				if( j == t_length) {
					locate = i-t_length;
					break;
				}
			}
			return locate;
		}
};

int main () {
	//输入
	string s, t;
	cout << "input Source_String :";
	cin>>s;
	cout<<endl;
	cout << "input Target_String :";
	cin>>t;
	cout<<endl;
	//匹配
	
	BF_Match a;
	int bf = a.String_Match(s, t);
	
	KMP_Match b;
	int kmp = b.String_Match(s,t);
	//输出
	cout<< bf<< endl;
	cout<< kmp<< endl;
	 
	return 0;
}


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

int kase;
int T[10], S[10], W[10], F[5], O[4];

bool Input() {
	memset(T, 0, sizeof(T));
	memset(S, 0, sizeof(S));
	memset(W, 0, sizeof(W));
	memset(F, 0, sizeof(F));
	memset(O, 0, sizeof(O));
	
	for(rgi i = 1; i <= 13; ++i) {
		string str; cin >> str;
		
		if(str == "0")	return 0;
	
		if(str == "ZHONG")	O[1]++;
		if(str == "FA")		O[2]++;
		if(str == "BAI")	O[3]++;
		
		if(str == "DONG")	F[1]++;
		if(str == "NAN")	F[2]++;
		if(str == "XI")		F[3]++;
		if(str == "BEI")	F[4]++;
		
		if(str[1] == 'T')	T[str[0] - '0']++;
		if(str[1] == 'S')	S[str[0] - '0']++;
		if(str[1] == 'W')	W[str[0] - '0']++;
	}
	
	return 1;
}

bool Judge(int cur) {
	if(cur == 3) {
		for(rgi i = 1; i <= 7; ++i)	if(T[i] == 1 && T[i + 1] == 1 && T[i + 2] == 1)	return 1;
		for(rgi i = 1; i <= 7; ++i)	if(S[i] == 1 && S[i + 1] == 1 && S[i + 2] == 1)	return 1;
		for(rgi i = 1; i <= 7; ++i)	if(W[i] == 1 && W[i + 1] == 1 && W[i + 2] == 1)	return 1;
		
		for(rgi i = 1; i <= 9; ++i)	if(T[i] == 3)	return 1;
		for(rgi i = 1; i <= 9; ++i)	if(S[i] == 3)	return 1;
		for(rgi i = 1; i <= 9; ++i)	if(W[i] == 3)	return 1;
		for(rgi i = 1; i <= 4; ++i)	if(F[i] == 3)	return 1;
		for(rgi i = 1; i <= 3; ++i)	if(O[i] == 3)	return 1;
		
		return 0;
	}
	for(rgi i = 1; i <= 7; ++i)	if(T[i] >= 1 && T[i + 1] >= 1 && T[i + 2] >= 1) {
		T[i]--, T[i + 1]--, T[i + 2]--;
		if(Judge(cur - 3)) {T[i]++, T[i + 1]++, T[i + 2]++;return 1;}
		T[i]++, T[i + 1]++, T[i + 2]++;
	}
	for(rgi i = 1; i <= 7; ++i)	if(S[i] >= 1 && S[i + 1] >= 1 && S[i + 2] >= 1) {
		S[i]--, S[i + 1]--, S[i + 2]--;
		if(Judge(cur - 3)) {S[i]++, S[i + 1]++, S[i + 2]++;return 1;}
		S[i]++, S[i + 1]++, S[i + 2]++;
	}
	for(rgi i = 1; i <= 7; ++i)	if(W[i] >= 1 && W[i + 1] >= 1 && W[i + 2] >= 1) {
		W[i]--, W[i + 1]--, W[i + 2]--;
		if(Judge(cur - 3)) {W[i]++, W[i + 1]++, W[i + 2]++;return 1;}
		W[i]++, W[i + 1]++, W[i + 2]++;
	}
	
	for(rgi i = 1; i <= 9; ++i)	if(T[i] >= 3) {
		T[i] -= 3;
		if(Judge(cur - 3)) {T[i] += 3;return 1;}
		T[i] += 3;
	}
	for(rgi i = 1; i <= 9; ++i)	if(S[i] >= 3) {
		S[i] -= 3;
		if(Judge(cur - 3)) {S[i] += 3;return 1;}
		S[i] += 3;
	}
	for(rgi i = 1; i <= 9; ++i)	if(W[i] >= 3) {
		W[i] -= 3;
		if(Judge(cur - 3)) {W[i] += 3;return 1;}
		W[i] += 3;
	}
	for(rgi i = 1; i <= 4; ++i) if(F[i] >= 3) {
		F[i] -= 3;
		if(Judge(cur - 3)) {F[i] += 3;return 1;}
		F[i] += 3;
	}
	for(rgi i = 1; i <= 3; ++i)	if(O[i] >= 3) {
		O[i] -= 3;
		if(Judge(cur - 3)) {O[i] += 3;return 1;}
		O[i] += 3;
	}
	
	return 0;
}

bool Check() {
	for(rgi i = 1; i <= 9; ++i) if(T[i] > 4)	return 0;
	for(rgi i = 1; i <= 9; ++i) if(S[i] > 4)	return 0;
	for(rgi i = 1; i <= 9; ++i) if(W[i] > 4)	return 0;
	for(rgi i = 1; i <= 4; ++i)	if(F[i] > 4)	return 0;
	for(rgi i = 1; i <= 3; ++i)	if(O[i] > 4)	return 0;
	
	for(rgi i = 1; i <= 9; ++i)	if(T[i] >= 2) {
		T[i] -= 2;
		if(Judge(12)) {T[i] += 2;return 1;}
		T[i] += 2;
	}
	for(rgi i = 1; i <= 9; ++i)	if(S[i] >= 2) {
		S[i] -= 2;
		if(Judge(12)) {S[i] += 2;return 1;}
		S[i] += 2;
	}
	for(rgi i = 1; i <= 9; ++i)	if(W[i] >= 2) {
		W[i] -= 2;
		if(Judge(12)) {W[i] += 2;return 1;}
		W[i] += 2;
	}
	for(rgi i = 1; i <= 4; ++i)	if(F[i] >= 2) {
		F[i] -= 2;
		if(Judge(12)) {F[i] += 2;return 1;}
		F[i] += 2;
	}
	for(rgi i = 1; i <= 3; ++i) if(O[i] >= 2) {
		O[i] -= 2;
		if(Judge(12)) {O[i] += 2;return 1;}
		O[i] += 2;
	}
	
	return 0;
}

int main() {
	while(Input()) {
		printf("Case %d:", ++kase); int flag = 0;
		for(rgi i = 1; i <= 9; ++i) {// T
			T[i]++;
			if(Check()) cout << " " << i << "T", flag = 1;
			T[i]--;
		}
		for(rgi i = 1; i <= 9; ++i) {// S
			S[i]++;
			if(Check()) cout << " " << i << "S", flag = 1;
			S[i]--;
		}
		for(rgi i = 1; i <= 9; ++i) {// W
			W[i]++;
			if(Check()) cout << " " << i << "W", flag = 1;
			W[i]--;
		}
		for(rgi i = 1; i <= 4; ++i) {// F
			F[i]++;
			if(Check()) {
				if(i == 1)	cout << " " << "DONG";
				if(i == 2)	cout << " " << "NAN";
				if(i == 3)	cout << " " << "XI";
				if(i == 4)	cout << " " << "BEI";
				flag = 1;
			}
			F[i]--;
		}
		for(rgi i = 1; i <= 3; ++i) {// O
			O[i]++;
			if(Check()) {
				if(i == 1)	cout << " " << "ZHONG";
				if(i == 2)	cout << " " << "FA";
				if(i == 3)	cout << " " << "BAI";
				flag = 1;
			}
			O[i]--;
		}
		if(!flag)	cout << " Not ready";
		cout << endl;
	}
	return 0;
}
/*
1S 1S 2S 2S 2S 3S 3S 3S 7S 8S 9S FA FA
1S 2S 3S 4S 5S 6S 7S 8S 9S 1T 3T 5T 7T
0

*/

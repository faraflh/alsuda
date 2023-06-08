#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

void addQ(int x) {
	s1.push(x);
}

void removeQ() {
	if(s2.empty()) {
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
}

int front() {
	if(s2.empty()) {
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}

bool isEmpty() {
	return (s1.empty() && s2.empty());
}

void Tampil() {
	int x;
	cout<<"Front -> ";
	while(!isEmpty()) {
		x = front();
		removeQ();
		cout<<x<<" ";
	}
	cout<<"<- Rear\n";
}

main() {
	addQ(1);
	addQ(2);
	addQ(3);
	addQ(4);
	addQ(5);
	removeQ();
	Tampil();
}

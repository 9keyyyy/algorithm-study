#include <iostream>
#include <list>
using namespace std;

void josephus(int n, int k) {
	list<int> survivors;
	for (int i = 0; i <= n; i++) survivors.push_back(i);
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		// erase는 지운 원소의 다음 원소 반환
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin(); //end는 마지막 노드 다음을 가리킴
		--n;
		for (int i = 0; i < k - 1; i++) {
			++kill;
			if (kill == survivors.end()) kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}
#include <iostream>
#include <string>
using namespace std;

class Group_of_Molecules {
	class Molecule {
	public:
		string name;
		string formula;
		double mass;
	};
private:
	int n;
	Molecule *a = new Molecule[n];
public:
	Group_of_Molecules(int n) {
		this->n = n;
		for (int i = 0; i < 6; i++) {
			cin >> (a + i)->name; 
			cin >> (a + i)->formula;
			cin >> (a + i)->mass;
		}
	}
	void Qsort() {
		Qsort(a, a->mass, (a+n-1)->mass);
	}
	void Qsort(Molecule* a, int left, int right) {
		if (left < right) {
			int i = left, j = right + 1, pivot = (a+left)->mass;
			do {
				do i++; while ((a + i)->mass < pivot);
				do j--; while ((a + j)->mass > pivot);
				if(i<j) 
			}
		}
	}
	void Print() {

	}

};

int main() {
	system("pause");
	return 0;
}


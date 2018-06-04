#include <iostream>
#include <utility>  //C++98: <algorithm>, C++11: <utility> (swap)
#include <string>
#include <cctype>
#include <stack>
#include <iomanip> //setprecision
using namespace std;

class Group_of_Molecules {
	class Molecule {
	public:
		string name;
		string formula;
		double mass;
	};
	class AtomicMass {
	public:
		string atom;
		double mass;
	};
private:
	int n;
	int n_swap = 0;
	Molecule *a;
	void Qsort(int left, int right) {
		if (left < right) {
			int i = left, j = right + 1;
			double pivot = a[left].mass;
			do {
				do i++; while (i<n && a[i].mass < pivot);	//int the first time: i++ jump over the pivot
				do j--; while (j>=0 && a[j].mass > pivot);
				if (i < j) {
					swap(a[i], a[j]);
					n_swap++;
				}
			} while (i < j);
			swap(a[left], a[j]);
			Qsort(left, j - 1);	//jth need to compare
			Qsort(j + 1, right);
		}
	}
public:
	Group_of_Molecules() {
	}
/*	void PeriodicTable() {


	}*/
	void ReadMolecules() {
		cin >> n;
		cout << n << endl;
		a = new Molecule[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].name;
			cin >> a[i].formula;
			cin >> a[i].mass;
			/*if ((a + i)->mass == 0) {
			string element;
			for (int i = 0; i < (a + i)->formula.length(); i++) {
			element += (a + i)->formula.at(i);
			char c = (a + i)->formula.at(i);
			if (islower(c)) {

			}

			}
			}
			*/
		}
	}
	void Qsort() {
		Qsort(0, n - 1);
	}
	void Print() {
		int n_digits = 0;	//number of digits of mass (integral part only)
		for (int i = 0; i < n; i++) {
			double mass = a[i].mass;
			cout.width(40);
			cout <<left<< a[i].name;
			cout.width(25);
			cout <<left<< a[i].formula;
			cout.width(10);
			cout <<right<<fixed << setprecision(2) << a[i].mass<<endl;
		}
		cout << n_swap <<" swaps during qsort\n";
	}
};

int main() {
	int n_group;
	cin >> n_group;
	cout << n_group << endl;
	for (int i = 0; i < n_group; i++) {
		int n_molecule;
		Group_of_Molecules gom;
		gom.ReadMolecules();
		gom.Qsort();
		gom.Print();
	}
	system("pause");
	return 0;
}

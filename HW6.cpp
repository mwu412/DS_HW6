#include <iostream>
#include <utility>  //C++98: <algorithm>, C++11: <utility> (swap)
#include <string>
#include <iomanip> //setprecision
#include <map>
#include <cctype>
using namespace std;

class Group_of_Molecules {	
private:
	class Molecule {
	public:
		string name;
		string formula;
		double mass;
	};
	int n;
	int n_swap = 0;
	Molecule *a;
	map<string, double> mapTable;	//<element, atomic mass>

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
			if(left!=j) n_swap++;
			Qsort(left, j - 1);	//jth need to compare
			Qsort(j + 1, right);
		}
	}
public:
	Group_of_Molecules() {
		mapTable["H"] = 1; mapTable["He"] = 4; mapTable["Li"] = 7; mapTable["Be"] = 9;
		mapTable["B"] = 11; mapTable["C"] = 12; mapTable["N"] = 14; mapTable["O"] = 16;
		mapTable["F"] = 19; mapTable["Ne"] = 20; mapTable["Na"] = 23; mapTable["Mg"] = 24;
		mapTable["Al"] = 27; mapTable["Si"] = 28; mapTable["P"] = 31; mapTable["S"] = 32;
		mapTable["Cl"] = 35; mapTable["Ar"] = 40; mapTable["K"] = 39; mapTable["Ca"] = 40;
		mapTable["Sc"] = 45; mapTable["Ti"] = 48; mapTable["V"] = 51; mapTable["Cr"] = 52;
		mapTable["Mn"] = 55; mapTable["Fe"] = 56; mapTable["Co"] = 59; mapTable["Ni"] = 59;
		mapTable["Cu"] = 64; mapTable["Zn"] = 65; mapTable["Ga"] = 70; mapTable["Ge"] = 73;
		mapTable["As"] = 75; mapTable["Se"] = 79; mapTable["Br"] = 80; mapTable["Kr"] = 84;
		mapTable["Rb"] = 85; mapTable["Sr"] = 88; mapTable["Y"] = 89; mapTable["Zr"] = 91;
		mapTable["Nb"] = 93; mapTable["Mo"] = 96; mapTable["Tc"] = 97; mapTable["Ru"] = 101;
		mapTable["Rh"] = 103; mapTable["Pd"] = 106; mapTable["Ag"] = 108; mapTable["Cd"] = 112;
		mapTable["In"] = 115; mapTable["Sn"] = 119; mapTable["Sb"] = 122; mapTable["Te"] = 128;
		mapTable["I"] = 127; mapTable["Xe"] = 131; mapTable["Cs"] = 133; mapTable["Ba"] = 137;
		mapTable["La"] = 139; mapTable["Ce"] = 140; mapTable["Pr"] = 141; mapTable["Nd"] = 144;
		mapTable["Pm"] = 145; mapTable["Sm"] = 150; mapTable["Eu"] = 152; mapTable["Gd"] = 157;
		mapTable["Tb"] = 159; mapTable["Dy"] = 163; mapTable["Ho"] = 165; mapTable["Er"] = 167;
		mapTable["Tm"] = 169; mapTable["Yb"] = 173; mapTable["Lu"] = 175; mapTable["Hf"] = 178;
		mapTable["Ta"] = 181; mapTable["W"] = 184; mapTable["Re"] = 186; mapTable["Os"] = 190;
		mapTable["Ir"] = 192; mapTable["Pt"] = 195; mapTable["Au"] = 197; mapTable["Hg"] = 201;
		mapTable["Tl"] = 204; mapTable["Pb"] = 207; mapTable["Bi"] = 209; mapTable["Po"] = 209;
		mapTable["At"] = 210; mapTable["Rn"] = 222; mapTable["Fr"] = 223; mapTable["Ra"] = 226;
		mapTable["Ac"] = 227; mapTable["Th"] = 232; mapTable["Pa"] = 231; mapTable["U"] = 238;
		mapTable["Np"] = 237; mapTable["Pu"] = 244; mapTable["Am"] = 243; mapTable["Cm"] = 247;
		mapTable["Bk"] = 247; mapTable["Cf"] = 251; mapTable["Es"] = 252; mapTable["Fm"] = 257;
		mapTable["Md"] = 258; mapTable["No"] = 259; mapTable["Lr"] = 262; mapTable["Rf"] = 267;
		mapTable["Db"] = 270; mapTable["Sg"] = 269; mapTable["Bh"] = 270; mapTable["Hs"] = 270;
		mapTable["Mt"] = 278; mapTable["Ds"] = 281; mapTable["Rg"] = 281; mapTable["Cn"] = 285;
		mapTable["Nh"] = 286; mapTable["Fl"] = 289; mapTable["Mc"] = 289; mapTable["Lv"] = 293;
		mapTable["Ts"] = 293; mapTable["Og"] = 294;
	}
	void ReadMolecules() {
		cin >> n;
		cout << n << endl;
		a = new Molecule[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].name;
			cin >> a[i].formula;
			cin >> a[i].mass;
			if (a[i].mass == 0) {
				string element;
				double massTotal = 0, mass1, mass2;
				map<string, double>:: iterator mapFind;
				char state;
				bool multiply;
				for (size_t j = 0; j < a[i].formula.length(); j++) {
					if (a[i].formula.at(j) == ('[' || ']' || '(' || ')')) {
						state = a[i].formula.at(j);			
					}
					else {
						switch (state) {
						case 'x':

						case '[':
							element += a[i].formula.at(j);
							char c = a[i].formula.at(j);
							if (isupper(c)) {		//isalpha, isdigit
								mapFind = mapTable.find(element);
								massTotal += mapFind->second;
							}
							break;
						case ']':
							state = 'x';
							break;
						case '(':
						case ')':
						}
						
					}
				}
			}
			
		}
	}
	void CalculateMass() {

	}
	void Qsort() {
		Qsort(0, n - 1);
	}
	void Print() {
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
		Group_of_Molecules gom;
		gom.ReadMolecules();
		gom.Qsort();
		gom.Print();
	}
	system("pause");
	return 0;
}

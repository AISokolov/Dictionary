#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
struct dictionary
{
	int number; //номер телефона
	string name; //имя
	int pass; //паспортные данные
};
void input_file(dictionary a[], int& n)
{
	ifstream fin;
	fin.open("Input.txt");
	while (!fin.eof()) {
		n++;
		fin >> a[n - 1].number;
		fin >> a[n - 1].name;
		fin >> a[n - 1].pass;
	}
	fin.close();
	for (int i = 0; i < n; i++)
	{
		cout << "\nNumber: " << a[i].number;
		cout << "\nName: " << a[i].name;
		cout << "\nPassport data: " << a[i].pass;
		cout << "\n----------------\n";
	}
}
void add(dictionary a[], int &n) {
		string name = "";
		string number = "";
		string pass = "";
		cout << "New number: ";
		cin >> number;
		cout << "New Name: ";
		cin >> name;
		cout << "New passport data: ";
		cin >> pass;
		if (name == "" || is_number(name)|| number == "" || !is_number(number)|| pass == "" || !is_number(pass)) 
		{
			cout << "Incorrect Input! Try again! \n";
			add(a,n);
		}
		else {
			n++;
			a[n - 1].number = stoi(number);
			a[n - 1].name = name;
			a[n - 1].pass = stoi(pass);
			return;
		}
}
void remove(dictionary a[], int &n) {
	int key;
	cout << "Enter key for searching data wich you want to remove: ";
	cin >> key;
	for (int i = 0; i < n; i++) {
		if (a[i].number == key) {
			cout << a[i].number << " " << a[i].name << " " << a[i].pass << endl;
			for (i; i < n - 1; i++) {
				a[i] = a[i + 1];
			}
			n--;
			return;
		}
	}
	cout << "No elements with this key! Try again!\n";
	remove(a, n);
}
void sort(dictionary a[], int n) {
	int temp;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j].number > a[j + 1].number)
			{
				struct dictionary tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	cout << "Done!\n";
}
void output(dictionary a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\nNumber " << a[i].number;
		cout << "\nName: " << a[i].name;
		cout << "\nProduct: " << a[i].pass;
		cout << "\n----------------\n";
	}
}
void edit(dictionary a[], int n) {
	string name = "";
	string number = "";
	string pass = "";
	int key;
	cout << "Enter key for searching data wich you want to change: ";
	cin >> key;
	for (int i = 0; i < n; i++) {
		if (a[i].number == key) {
			cout << a[i].number << " " << a[i].name << " " << a[i].pass << endl;
			while(true){
				cout << "New number: ";
				cin >> number;
				cout << "New Name: ";
				cin >> name;
				cout << "New passport data: ";
				cin >> pass;
				if (name == "" || is_number(name) || number == "" || !is_number(number) || pass == "" || !is_number(pass))
				{
					cout << "Incorrect Input! Try again! \n";
				}
				else {
					a[i].number = stoi(number);
					a[i].name = name;
					a[i].pass = stoi(pass);
					return;
				}
			}
		}
	}
	cout << "No elements with this key! Try again!\n";
	edit(a, n);
}
void search(dictionary a[], int n) {
	int key;
	cout << "Enter key for searching: ";
	cin >> key;
	for (int i = 0; i < n; i++) {
		if (a[i].number == key) {
			cout << a[i].number << " " << a[i].name << " " << a[i].pass << endl;
			return;
		}
	}
	cout << "No elements with this key! Try again!\n";
}
void output_file(dictionary a[], int n)
{
	ofstream f;
	f.open("Output.txt");
	for (int i = 0; i < n; i++)
	{
		f << a[i].number << " " << a[i].name << " " << a[i].pass;
		if (i != n - 1) {
			f << endl;
		}
	}
	f.close();
	cout << "Done!\n";
}
int main()
{
	int choice;
	dictionary* a = new dictionary [5000];
	int n = 0;
	cout << "Make your choice\n";
	cout << "1.Input data \n";
	cout << "2.Sort data \n";
	cout << "3.Output data \n";
	cout << "4.Edit data \n";
	cout << "5.Search data \n";
	cout << "6.Save data in file \n";
	cout << "7.Add new data \n";
	cout << "8.Remove data \n";
	cout << "9.New file \n";
	cout << "0.Exit \n";
	while (true) {
		cin >> choice;
		switch (choice)
		{
		case 1:
			input_file(a, n);
			break;
		case 2:
			sort(a, n);
			break;
		case 3:
			output(a, n);
			break;
		case 4:
			edit(a, n);
			break;
		case 5:
			search(a, n);
			break;
		case 6:
			output_file(a, n);
			break;
		case 7:
			add(a, n);
			break;
		case 8:
			remove(a, n);
			break;
		case 9:
			n = 0;
			break;
		case 0:
			return 0;
		default:
			cout << "Incorrect input";
			break;
		}
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    double a1, a2;
    cout << "Digite o 1° ângulo:" << endl;
    cin >> a1;
    cout << "Digite o 2° ângulo:" << endl;
    cin >> a2;
    
    cout << "O terceiro ângulo é: " << (180.0 - (a1 + a2)) <<  setprecision(1) << endl ;
    
	return 0;
}
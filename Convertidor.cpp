#include <iostream>

#include <string> 

using namespace std;


string a_binario(int n)
{
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	string r_uso(r.rbegin(), r.rend());
	return r_uso;
}

void logic( ) {

	//Float
	
		int constante = 2047; //2^n-1 -1 
		int significand = 52;
		int sign = 0;
		int baised = 0;
		float numero = 0.00;
		string result_dec;
		cout << "Ingrese el n?mero: " << endl;
		cin >> numero;

		if (numero < 0)
			sign = 1;

		int part_entera = (int)numero;
		double part_dec = numero - (double)part_entera;

		string bin_entero = a_binario(part_entera);
		int exp = bin_entero.length() - 1;

		baised = exp + constante;

		significand = significand - exp;

		string bin_baised = a_binario(baised);

		for (int i = 1; i < bin_entero.length(); i++) {
			result_dec += bin_entero[i];
		}

		for (int i = 0; i < significand; i++) {
			part_dec = part_dec * 2;
			if (part_dec > 1) {
				result_dec += "1";
				part_dec -= 1;
			}
			else {
				result_dec += "0";
			}

		}


		cout << "El resultado en binario del punto flotante es: " << endl;
		cout << sign << '\t';
		cout << bin_baised << '\t';
		cout << result_dec << endl;
	

}

int main() {
	logic( );
	return 0;
}

//Decimal to any base converter
#include<iostream>

using namespace std;

int main(){
	int dec;
	int temp;
	int bin[100];
	int oct[100];
	char hex[100];
	int a = 0;
	int b = 0;
	int c = 0;

	cout << " Enter a Decimal number : ";
	cin >> dec;
	temp = dec;


	if(dec == 0){
		cout<<"  Decimal : 0";
		cout<<endl;
		cout<<"  Binary : 0";
		cout<<endl;
		cout<<"  Octal : 0";
		cout<<endl;
		cout<<"  Hexadecimal : 0";
		cout<<endl;
	}
	else{
	while (dec){
		bin [a] = dec % 2;
		dec = dec / 2;
		a++;
	}
	dec = temp;

	while(dec){
		oct[b] = dec % 8;
		dec = dec / 8;
		b++;
	}
	dec = temp;
	int r;
	while(dec){
		r = dec % 16;
		switch(r){
			case 10:
				hex[c] = 'A';
				break;
			case 11:
				hex[c] = 'B';
				break;
			case 12:
				hex[c] = 'C';
				break;
			case 13:
				hex[c] = 'D';
				break;
			case 14:
				hex[c] = 'E';
				break;
			case 15:
				hex[c] = 'F';
				break;
			default :
				hex[c] = r+0x30;
		}
		c++;
		dec= dec / 16;
	}
	a -= 1;
	cout << "  Decimal : "<<temp<<endl;
	cout << "  Binary : ";
	while(a >=0 ){
		cout << bin[a];
		a--;
	}
	b--;
	cout << endl << "  Octal : ";
	while(b >= 0){
		cout << oct[b];
		b--;
	}
	c--;
	cout << endl <<"  Hexadecimal : ";
	while(c >= 0){
		cout << hex[c];
		c--;
	}
	return 0;
  }
}


//@RC

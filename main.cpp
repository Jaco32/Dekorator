#include <string>
#include <iostream>

using namespace std;

class Samochod {
protected:
	string marka;
	int cena;
public:
	virtual string about() {
		return marka;
	}
	
	virtual int cena_get() {
		return cena;
	}
	
	virtual ~Samochod() {
		cout << "To ja, Destruktor Samochodu" << endl;
	}
};

class Mercedes: public Samochod {
public:
	Mercedes() {
		marka = static_cast<string>("Merol");
		cena = 130000;	
	}
	
	~Mercedes() {
		cout << "To ja, destruktor Mercedesa" << endl;
	}
};

class Fiat: public Samochod {
public:
	Fiat() {
		marka = static_cast<string>("Fiacik");
		cena = 50000;
	}

	~Fiat() { 
		cout << "To ja, destruktor Fiata" << endl;
	}
};

class Dekorator: public Samochod {
public:
	~Dekorator() {
		cout << "To ja, Destruktor Dekoratora" << endl;
	}
};

class Klimatyzacja: public Dekorator {
	Samochod *car;
public:
	Klimatyzacja(Samochod* c): car(c) { }
	
	string about() {
		return (car->about() + " z klima");
	}
	
	int cena_get() {
		return (car->cena_get() + 2500);
	}
	
	~Klimatyzacja() {
		cout << "To ja, Destruktor Klimatyzacji" << endl;
		delete car;
	}
};

class Navigacja: public Dekorator {
	Samochod *car;
public:
	Navigacja(Samochod* c): car(c) {
	}
	
	string about() {
		return (car->about() + " z klima");
	}
	
	int cena_get() {
		return (car->cena_get() + 1800);
	}
	
	~Navigacja() {
		cout << "To ja, Destruktor Navigacji" << endl;
		delete car;
	}
};

int main()
{
	Samochod *s1 = new Mercedes();
	Samochod *s2 = new Fiat();
	
	s1 = new Klimatyzacja(s1);
	s2 = new Klimatyzacja(s2);
	cout << s1->about() << " o cenie " << s1->cena_get() << endl;
	cout << s2->about() << " o cenie " << s2->cena_get() << endl;

	s1 = new Navigacja(s1);
	s2 = new Navigacja(s2);
	cout << s1->about() << " o cenie " << s1->cena_get() << endl;
	cout << s2->about() << " o cenie " << s2->cena_get() << endl;

	cout << endl;
	delete s1;
	cout << endl;
	delete s2;

	Samochod *s3 = new Navigacja(new Klimatyzacja(new Mercedes()));
	cout << endl;
	delete s3;
	
	return 0;
}

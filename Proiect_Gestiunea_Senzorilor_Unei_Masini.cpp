#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Senzor
{
private:
	const int id;
	static int contor;
	string nume = "";
	char* locatie = nullptr;
	int nrInteractiuni = 0;
	float* timpRaspunsInteractiune = nullptr;
	int distanta = 0;
	string situatieCritica = "";
	bool interconectare = 0;
	int nrSenzoriConect = 0;
	string* senzoriConect = nullptr;
public:
	//CONSTRUCTOR DEFAULT
	Senzor() :id(contor++)
	{
		this->locatie = new char[strlen("Random") + 1];
		strcpy_s(this->locatie, strlen("Random") + 1, "Random");
	}
	
	//CONSTRUCTOR CU TOTI PARAMETRII
	Senzor(string nume, const char* locatie, int nrInteractiuni, float* timpRaspunsInteractiune, int distanta, string situatieCritica, bool interconectare, int nrSenzoriConect, string* senzoriConect) :id(contor++)
	{
		this->nume = nume;
		this->locatie = new char[strlen(locatie) + 1];
		strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
		this->nrInteractiuni = nrInteractiuni;
		this->timpRaspunsInteractiune = new float[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++)
			this->timpRaspunsInteractiune[i] = timpRaspunsInteractiune[i];
		this->distanta = distanta;
		this->situatieCritica = situatieCritica;
		this->interconectare = interconectare;
		this->nrSenzoriConect = nrSenzoriConect;
		this->senzoriConect = new string[nrSenzoriConect];
		for (int i = 0; i < nrSenzoriConect; i++)
			this->senzoriConect[i] = senzoriConect[i];
	}

	//CONSTRUCTOR DE COPIERE
	Senzor(const Senzor& s) :id(contor++)
	{
		this->nume = s.nume;
		if (this->locatie != nullptr)
			delete this->locatie;
		this->locatie = new char[strlen(s.locatie) + 1];
		strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);
		this->nrInteractiuni = s.nrInteractiuni;
		if (this->timpRaspunsInteractiune != nullptr)
			delete[]this->timpRaspunsInteractiune;
		this->timpRaspunsInteractiune = new float[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++)
			this->timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i];
		this->distanta = s.distanta;
		this->situatieCritica = s.situatieCritica;
		this->interconectare = s.interconectare;
		this->nrSenzoriConect = s.nrSenzoriConect;
		if (this->senzoriConect != nullptr)
			delete[]this->senzoriConect;
		this->senzoriConect = new string[s.nrSenzoriConect];
		for (int i = 0; i < s.nrSenzoriConect; i++)
			this->senzoriConect[i] = s.senzoriConect[i];
	}
	
	//DESTRUCTOR
	~Senzor()
	{
		if (this->locatie != nullptr)
			delete[]this->locatie;
		if (this->timpRaspunsInteractiune != nullptr)
			delete[]this->timpRaspunsInteractiune;
		if (this->senzoriConect != nullptr)
			delete[]this->senzoriConect;
	}

	//GETTERI SI SETTERI
	int getid()
	{
		return this->id;
	}

	string getnume()
	{
		return this->nume;
	}
	void setnume(string nume)
	{
		this->nume = nume;
	}

	char* getlocatie()
	{
		if (this->locatie != nullptr)
			return this->locatie;
		else
			throw "Nu exista locatia";
	}
	void setlocatie(char* locatie)
	{
		this->locatie = locatie;
	}

	int getnrInteractiuni()
	{
		return this->nrInteractiuni;
	}
	void setnrInteractiuni(int nrInteractiuni)
	{
		this->nrInteractiuni = nrInteractiuni;
	}

	float* gettimpRaspunsInteractiune()
	{
		if (this->timpRaspunsInteractiune != nullptr)
			return this->timpRaspunsInteractiune;
		else
			throw "Nu exista";
	}
	float gettimpRaspunsInteractiune(int index)
	{
		if (this->timpRaspunsInteractiune != nullptr && index <= this->nrInteractiuni)
			return this->timpRaspunsInteractiune[index];
		else
			throw "Nu exista pozitionarea";
	}
	void settimpRaspunsInteractiune(int nrInteractiuni,float* timpRaspunsInteractiune)
	{
		this->nrInteractiuni = nrInteractiuni;
		if (this->timpRaspunsInteractiune != nullptr)
			delete[]this->timpRaspunsInteractiune;
		this->timpRaspunsInteractiune = new float[this->nrInteractiuni];
		for (int i = 0; i < nrInteractiuni; i++)
			this->timpRaspunsInteractiune[i] = timpRaspunsInteractiune[i];
	}
	void settimpRaspunsInteractiune(int index, float val)
	{
		this->timpRaspunsInteractiune[index] = val;
	}

	int getdistanta()
	{
		return this->distanta;
	}
	void setdistanta(int distanta)
	{
		this->distanta = distanta;
	}

	string getsituatieCritica()
	{
		return this->situatieCritica;
	}
	void setsituatieCritica(string situatieCritica)
	{
		this->situatieCritica = situatieCritica;
	}

	bool getinterconectare()
	{
		return this->interconectare;
	}
	void setinterconectare(bool interconectare)
	{
		this->interconectare = interconectare;
	}

	int getnrSenzoriConect()
	{
		return this->nrSenzoriConect;
	}
	void setnrSenzoriConect(int nrSenzoriConect)
	{
		this->nrSenzoriConect = nrSenzoriConect;
	}

	string* getsenzoriConect()
	{
		if (this->senzoriConect != nullptr)
			return this->senzoriConect;
		else
			throw "Nu exista senzor(i)";
	}
	string getsenzoriConect(int index)
	{
		if (this->senzoriConect != nullptr && index <= this->nrSenzoriConect)
			return this->senzoriConect[index];
		else
			throw "Nu exista aceasta pozitionare";
	}
	void setsenzoriConect(bool interconectare,int nrSenzoriConect,string* senzoriConect)
	{
		setinterconectare(interconectare);
		if (this->interconectare == true)
		{
			setnrSenzoriConect(nrSenzoriConect);
			if (this->senzoriConect != nullptr)
				delete[]this->senzoriConect;
			this->senzoriConect = new string[this->nrSenzoriConect];
			for (int i = 0; i < this->nrSenzoriConect; i++)
				this->senzoriConect[i] = senzoriConect[i];
		}

	}
	
	//SUPRAINCARCARE OPERATORI
	Senzor operator=(const Senzor& s)
	{
		this->nume = s.nume;
		if (this->locatie != nullptr)
			delete this->locatie;
		this->locatie = new char[strlen(s.locatie) + 1];
		strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);
		this->nrInteractiuni = s.nrInteractiuni;
		if (this->timpRaspunsInteractiune != nullptr)
			delete[]this->timpRaspunsInteractiune;
		this->timpRaspunsInteractiune = new float[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++)
			this->timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i];
		this->distanta = s.distanta;
		this->situatieCritica = s.situatieCritica;
		this->interconectare = s.interconectare;
		this->nrSenzoriConect = s.nrSenzoriConect;
		if (this->senzoriConect != nullptr)
			delete[]this->senzoriConect;
		this->senzoriConect = new string[s.nrSenzoriConect];
		for (int i = 0; i < s.nrSenzoriConect; i++)
			this->senzoriConect[i] = s.senzoriConect[i];
		return *this;
	}
	Senzor operator+(const Senzor& s)
	{
		Senzor se = *this;
		delete[]se.timpRaspunsInteractiune;
		se.nrInteractiuni = this->nrInteractiuni + s.nrInteractiuni;
		se.timpRaspunsInteractiune = new float[se.nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++)
			se.timpRaspunsInteractiune[i] = this->timpRaspunsInteractiune[i];
		for (int i = this->nrInteractiuni; i < se.nrInteractiuni; i++)
			se.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i-this->nrInteractiuni];
		return se;
	}
	Senzor operator-(const Senzor& s)
	{
		Senzor se = *this;
		
		if (this->nrInteractiuni == s.nrInteractiuni)
		{
			for (int i = 0; i < se.nrInteractiuni; i++)
			{
				if (se.timpRaspunsInteractiune[i] > s.timpRaspunsInteractiune[i])
					se.timpRaspunsInteractiune[i] = se.timpRaspunsInteractiune[i] - s.timpRaspunsInteractiune[i];
				else
					se.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i] - se.timpRaspunsInteractiune[i];
			}
		}
		else if (this->nrInteractiuni > s.nrInteractiuni)
		{
			for (int i = 0; i < s.nrInteractiuni; i++)
			{
				if (this->timpRaspunsInteractiune[i] > s.timpRaspunsInteractiune[i])
					se.timpRaspunsInteractiune[i] = this->timpRaspunsInteractiune[i] - s.timpRaspunsInteractiune[i];
				else
					se.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i] - this->timpRaspunsInteractiune[i];
			}
			for (int i = s.nrInteractiuni; i < se.nrInteractiuni; i++)
				se.timpRaspunsInteractiune[i] = this->timpRaspunsInteractiune[i];

		}
		else if (this->nrInteractiuni < s.nrInteractiuni)
		{
			se.nrInteractiuni = s.nrInteractiuni;
			delete[]se.timpRaspunsInteractiune;
			se.timpRaspunsInteractiune = new float[se.nrInteractiuni];
			for (int i = 0; i < this->nrInteractiuni; i++)
			{
				if (this->timpRaspunsInteractiune[i] > s.timpRaspunsInteractiune[i])
					se.timpRaspunsInteractiune[i] = this->timpRaspunsInteractiune[i] - s.timpRaspunsInteractiune[i];
				else
					se.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i] - this->timpRaspunsInteractiune[i];
			}
			for (int i = this->nrInteractiuni; i < se.nrInteractiuni; i++)
				se.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i];
		}
		return se;
	}
	Senzor operator*(int n)
	{
		Senzor s = *this;
		for (int i = 0; i < s.nrInteractiuni; i++)
			s.timpRaspunsInteractiune[i] = s.timpRaspunsInteractiune[i] * n;
		return s;
	}
	float operator/(int n)
	{
		if (n != 0 && n <= this->nrInteractiuni)
		{
			float s = 0;
			for (int i = 0; i < n; i++)
				s = s + this->timpRaspunsInteractiune[i];
			s = s / n;
			return s;
		}
		else
			throw "Imposibil de aflat";
	} 
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrInteractiuni)
			return this->timpRaspunsInteractiune[index];
		else
			throw "Imposibil de aflat";
	}
	friend ostream& operator<<(ostream& scriere, const Senzor& s)
	{
		scriere << "Id: " << s.id << endl;
		scriere << "Nume: " << s.nume << endl;
		scriere << "Locatie: "<<s.locatie;
		scriere << endl << "Numar interactiuni: " << s.nrInteractiuni << endl;
		if (s.nrInteractiuni > 0)
			for (int i = 0; i < s.nrInteractiuni; i++)
			{
				scriere << "Timp raspuns Interactiune " << i + 1 << ": " << s.timpRaspunsInteractiune[i] << " ms" << endl;
			}
		else
			scriere << "Nu are interactiuni" << endl;
		scriere << "Distanta dintre alti senzori: " << s.distanta <<" cm" << endl;
		scriere << "Situatie critica in caz ca nu merge: " << s.situatieCritica << endl;
		if (s.interconectare == true)
		{
			scriere << "Interconectare: Da" << endl;
			scriere << "Numar senzori cu care este conectat: " << s.nrSenzoriConect << endl;
			for (int i = 0; i < s.nrSenzoriConect; i++)
				scriere << "Senzorul " << i + 1 << " cu care e conectat: " << s.senzoriConect[i] << endl;
		}
		else
			scriere << "Interconectare: Nu" << endl;
		return scriere;
	}
	friend fstream& operator<<(fstream& file, const Senzor& s)
	{
		file << s.nume << endl;
		file << s.locatie << endl;
		file <<  s.nrInteractiuni << endl;
		if (s.nrInteractiuni > 0)
			for (int i = 0; i < s.nrInteractiuni; i++)
			{
				file << s.timpRaspunsInteractiune[i] << endl;
			}
		else
			file << endl;
		file << s.distanta << endl;
		file << s.situatieCritica << endl;
		file << s.interconectare << endl;
		if (s.interconectare == true)
		{
			file << s.nrSenzoriConect << endl;
			for (int i = 0; i < s.nrSenzoriConect; i++)
				file << s.senzoriConect[i] << endl;
		}
		return file;
	}

	friend istream& operator>>(istream& citire, Senzor& s)
	{
		cout << "Introduceti numele senzorului: ";
		getline(citire>>ws, s.nume);
		cout << "Introduceti locatia in care se afla senzorul: ";
		char buffer[20];
		cin.get(buffer, 20);
		if (s.locatie != nullptr)
			delete[]s.locatie;
		s.locatie = new char[strlen(buffer)+1];
		strcpy_s(s.locatie, strlen(buffer) + 1, buffer);
		cout << "Introduceti cate interactiuni a avut senzorul cu utilizatorul: ";
		citire >> s.nrInteractiuni;
		if (s.nrInteractiuni > 0)
		{
			cout << "Introduceti timpul de raspuns pentru fiecare interactiune: " << endl;
			if (s.timpRaspunsInteractiune != nullptr)
				delete[]s.timpRaspunsInteractiune;
			s.timpRaspunsInteractiune = new float[s.nrInteractiuni];
			for (int i = 0; i < s.nrInteractiuni; i++)
			{
				cout << "Pentru interactiunea " << i + 1 << ": ";
				citire >> s.timpRaspunsInteractiune[i];
			}
		}
		cout << "Introduceti distanta dintre alti senzori: ";
		citire >> s.distanta;
		cout << "Introduceti care este situatia critica in cazul in care nu functioneaza: ";
		getline(citire>>ws, s.situatieCritica);
		cout << "Se interconecteaza cu alti senzori? ";
		citire >> s.interconectare;
		if (s.interconectare == true)
		{
			cout << "Introduceti numarul de senzori cu care este interconectat acesta: ";
			citire >> s.nrSenzoriConect;
			cout << "Introduceti senzorii cu care este conectat: " << endl;
			if(s.senzoriConect!=nullptr)
				delete[]s.senzoriConect;
			s.senzoriConect = new string[s.nrSenzoriConect];
			for (int i = 0; i < s.nrSenzoriConect; i++)
			{
				cout << "Senzorul " << i + 1 << " cu care e conectat: ";
				getline(citire >> ws, s.senzoriConect[i]);
			}
			cout << endl;
		}
		else
			cout << "Nu este interconectat cu niciun senzor" << endl;
		return citire;
	}
	friend ifstream& operator>>(ifstream& filei, Senzor& s)
	{
		getline(filei>>ws, s.nume);
		char buffer[20];
		filei.get(buffer, 20);
		s.locatie = new char[strlen(buffer) + 1];
		strcpy_s(s.locatie, strlen(buffer) + 1, buffer);
		filei >> s.nrInteractiuni;
		if (s.nrInteractiuni > 0)
		{
			if (s.timpRaspunsInteractiune != nullptr)
				delete[]s.timpRaspunsInteractiune;
			s.timpRaspunsInteractiune = new float[s.nrInteractiuni];
			for (int i = 0; i < s.nrInteractiuni; i++)
				filei >> s.timpRaspunsInteractiune[i];
		}
		filei >> s.distanta;
		getline(filei >> ws, s.situatieCritica);
		filei >> s.interconectare;
		if (s.interconectare == true)
		{
			filei >> s.nrSenzoriConect;
			if (s.senzoriConect != nullptr)
				delete[]s.senzoriConect;
			s.senzoriConect = new string[s.nrSenzoriConect];
			for (int i = 0; i < s.nrSenzoriConect; i++)
				getline(filei >> ws, s.senzoriConect[i]);
		}
		return filei;
	}

};

class SenzorOptional :public Senzor //CLASA SenzorOptional MOSTENESTE CLASA Senzro
{
private:
	int pretSO=1;
public:
	//CONSTRUCTOR DEFAULT
	SenzorOptional() {};
	
	//CONSTRUCTOR CU TOTI PARAMETRII
	SenzorOptional(string nume, const char* locatie, int nrInteractiuni, float* timpRaspunsInteractiune, int distanta, string situatieCritica, bool interconectare, int nrSenzoriConect, string* senzoriConect, int pretSO) :Senzor(nume, locatie, nrInteractiuni, timpRaspunsInteractiune, distanta, situatieCritica, interconectare, nrSenzoriConect, senzoriConect)
	{
		this->pretSO = pretSO;
	}
	
	//CONSTRUCTOR DE COPIERE
	SenzorOptional(const SenzorOptional& so) :Senzor(so)
	{
		this->pretSO = so.pretSO;
	}
	
	//GETTERI SI SETTERI
	int getpretSO()
	{
		return this->pretSO;
	}
	void setpretSOt(int pretSO)
	{
		this->pretSO = pretSO;
	}

	//METODA DE AFLARE A TIMPULUI TOTAL DE RASPUNS A TUTUROR INTERACTIUNILOR UNUI SENZOR OPTIONAL
	float getTotalTimp()
	{
		float s = 0;
		for (int i = 0; i < this->getnrInteractiuni(); i++)
			s += this->gettimpRaspunsInteractiune(i);
		return s;
	}
	
	//SUPRAINCARCARE OPERATORI
	SenzorOptional operator=(const SenzorOptional& so)
	{
		Senzor::operator=(so);
		this->pretSO = so.pretSO;
		return *this;
	}
	friend ostream& operator<<(ostream& scriere, const SenzorOptional& so)
	{
		scriere << endl << (Senzor&)so;
		scriere << "Pretul de vanzare: " << so.pretSO <<endl<<endl;
		return scriere;
	}
	friend fstream& operator<<(fstream& fileo, const SenzorOptional& so)
	{
		fileo << (Senzor&)so << endl;
		fileo <<  so.pretSO << endl;
		return fileo;
	}

	friend istream& operator>>(istream& citire, SenzorOptional& so)
	{
		citire >> (Senzor&)so;
		cout << "Introduceti pretul de vanzare al senzorului: ";
		citire >> so.pretSO;
		return citire;
	}
	friend ifstream& operator>>(ifstream& filei, SenzorOptional& so)
	{
		filei >> (Senzor&)so;
		filei >> so.pretSO;
		return filei;
	}
	//PRE
	SenzorOptional operator++()
	{
		float* v = new float[this->getnrInteractiuni()];
		for (int i = 0; i < this->getnrInteractiuni(); i++)
		{
			v[i] = this->gettimpRaspunsInteractiune(i);
			v[i]++;
			this->settimpRaspunsInteractiune(i,v[i]);
		}
		return *this;
	}
	SenzorOptional operator--()
	{
		int d = this->getdistanta();
		d--;
		this->setdistanta(d);
		return *this;
	}
	//POST
	SenzorOptional operator++(int)
	{
		SenzorOptional so = *this;
		float* v = new float[this->getnrInteractiuni()];
		for (int i = 0; i < this->getnrInteractiuni(); i++)
		{
			v[i] = this->gettimpRaspunsInteractiune(i);
			v[i]++;
			this->settimpRaspunsInteractiune(i, v[i]);
		}
		return so;
	}
	SenzorOptional operator--(int)
	{
		SenzorOptional so = *this;
		int d = this->getdistanta();
		d--;
		this->setdistanta(d);
		return so;
	}
	float operator()()
	{
		return this->getTotalTimp();
	}
	
};

enum Combustibil { BENZINA, MOTORINA, HIBRID, ELECTRIC, HIDROGEN };
class Vehicul
{
private:
	Combustibil combustibil;
	int pretV = 0;
public:
	//CONSTRUCTOR DEFAULT
	Vehicul()
	{
		this->combustibil = Combustibil::BENZINA;
	}

	//CONSTRUCTOR CU TOTI PARAMETRII
	Vehicul(Combustibil combustibil,int pretV)
	{
		this->combustibil = combustibil;
		this->pretV = pretV;
	}

	//CONSTRUCTOR DE COPIERE
	Vehicul(const Vehicul& v)
	{
		this->combustibil = v.combustibil;
		this->pretV = v.pretV;
	}

	//FUNCTIE VIRTUALA PURA
	virtual int CA() = 0;

	
	//GETTERI SI SETTERI
	Combustibil getcombustibil()
	{
		return this->combustibil;
	}
	void setcombustibil(Combustibil combustibil)
	{
		this->combustibil = combustibil;
	}

	int getpretV()
	{
		return this->pretV;
	}
	void setpretV(int pretV)
	{
		this->pretV = pretV;
	}

	//SUPRAINCARCARE OPERATORI
	Vehicul& operator=(const Vehicul& v)
	{
		this->combustibil = v.combustibil;
		this->pretV = v.pretV;
		return *this;
	}
	friend ostream& operator<<(ostream& scriere, const Vehicul& v)
	{
		scriere << "Vehiculul ";
		if (v.combustibil == Combustibil::BENZINA)
			scriere << "merge pe benzina";
		else if (v.combustibil == Combustibil::ELECTRIC)
			scriere << "este electric";
		else if (v.combustibil == Combustibil::HIBRID)
			scriere << "este hibrid";
		else if (v.combustibil == Combustibil::MOTORINA)
			scriere << "merge pe motorina";
		scriere << " si costa " << v.pretV << " euro." << endl;
		return scriere;
	}
	friend ofstream& operator<<(ofstream& fileo, Vehicul& v)
	{
		fileo << "Vehiculul ";
		if (v.combustibil == Combustibil::BENZINA)
			fileo << "merge pe benzina";
		else if (v.combustibil == Combustibil::ELECTRIC)
			fileo << "este electric";
		else if (v.combustibil == Combustibil::HIBRID)
			fileo << "este hibrid";
		else if (v.combustibil == Combustibil::MOTORINA)
			fileo << "merge pe motorina";
		fileo << " si costa " << v.pretV << " euro." << endl;
		return fileo;
	}
	
	friend istream& operator>>(istream& citire,Vehicul& v)
	{
		cout << "Introduceti combustibilul: ";
		int c;
		citire >> c;
		v.combustibil = Combustibil(c);
		cout << "Introduceti pretul de vanzare al masinii: ";
		citire >> v.pretV;
		return citire;
	}
	friend ifstream& operator>>(ifstream& filei, Vehicul& v)
	{
		int c;
		filei >> c;
		v.combustibil = Combustibil(c);
		filei >> v.pretV;
		return filei;
	}
};

class Masina:public Vehicul //CLASA Masina MOSTENESTE CLASA Vehicul
{
private:
	string nume;
	string model;
	int nrSenzori;
	Senzor* vectorSenzori;
	int nrSenzoriOpt;
	SenzorOptional* vectorSenzoriOpt;
	int CostTotalSO=0;
	string CondusAutonom = "Nu are functia de condus autonom.";
	float rating=0;

public:
	//CONSTRUCTOR DEFAULT
	Masina() :Vehicul()
	{
		this->nume = "TBD";
		this->model = "TBD";
		this->nrSenzori = 0;
		this->vectorSenzori = nullptr;
		this->nrSenzoriOpt = 0;
		this->vectorSenzoriOpt = nullptr;
	}

	//CONSTRUCTOR CU TOTI PARAMETRII
	Masina(string nume, string model, int nrSenzori, Senzor* vectorSenzori,int nrSenzoriOpt, SenzorOptional* vectorSenzoriOpt, Combustibil combustibil,int pretV):Vehicul(combustibil,pretV)
	{
		this->nume = nume;
		this->model = model;
		this->nrSenzori = nrSenzori;
		this->vectorSenzori = new Senzor[this->nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++)
			this->vectorSenzori[i] = vectorSenzori[i];
		this->nrSenzoriOpt = nrSenzoriOpt;
		this->vectorSenzoriOpt = new SenzorOptional[this->nrSenzoriOpt];
		for (int i = 0; i < this->nrSenzoriOpt; i++)
			this->vectorSenzoriOpt[i] = vectorSenzoriOpt[i];
		this->CostTotalSO = this->getCostTotalSO();
		this->CondusAutonom = this->getCondusAutonom();
		this->rating = this->getrating();
	}
	
	//CONSTRUCTOR DE COPIERE
	Masina(const Masina& m) :Vehicul(m)
	{
		this->nume = m.nume;
		this->model = m.model;
		this->nrSenzori = m.nrSenzori;
		this->vectorSenzori = new Senzor[this->nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++)
			this->vectorSenzori[i] = m.vectorSenzori[i];
		this->nrSenzoriOpt = m.nrSenzoriOpt;
		this->vectorSenzoriOpt = new SenzorOptional[this->nrSenzoriOpt];
		this->CostTotalSO = m.CostTotalSO;
		this->CondusAutonom = m.CondusAutonom;
		this->rating = m.rating;
	}
	
	//DESTRUCTOR
	~Masina()
	{
		if (this->vectorSenzori != nullptr)
			delete[]this->vectorSenzori;
		if (this->vectorSenzoriOpt != nullptr)
			delete[]this->vectorSenzoriOpt;
	}

	//GETTERI SI SETTERI
	string getnume()
	{
		return this->nume;
	}
	void setnume(string nume)
	{
		this->nume = nume;
	}

	string getmodel()
	{
		return this->model;
	}
	void setmodel(string model)
	{
		this->model = model;
	}

	float getrating()
	{
		this->rating = this->DeducereRating();
		return this->rating;
	}
	void setrating(float rating)
	{
		this->rating = rating;
	}

	int getnrSenzori()
	{
		return this->nrSenzori;
	}
	void setnrSenzori(int nr)
	{
		this->nrSenzori = nr;
	}

	Senzor* getvectorSenzori()
	{
		if (this->vectorSenzori != nullptr)
			return this->vectorSenzori;
		else
			throw "Vector null.";
	}
	void setvectorSenzori(int nrSenzori, Senzor* s)
	{
		this->nrSenzori = nrSenzori;
		if (this->vectorSenzori != nullptr)
			delete[]this->vectorSenzori;
		this->vectorSenzori = new Senzor[this->nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++)
			this->vectorSenzori[i] = s[i];
	}

	SenzorOptional* getvectorSenzoriOpt()
	{
		if (this->vectorSenzoriOpt != nullptr)
			return this->vectorSenzoriOpt;
		else
			throw "Vector null.";
	}
	void setvectorSenzoriOpt(int nrSenzoriOpt, SenzorOptional* so)
	{
		this->CostTotalSO = 0;
		this->nrSenzoriOpt = nrSenzoriOpt;
		if (this->vectorSenzoriOpt != nullptr)
			delete[]this->vectorSenzoriOpt;
		this->vectorSenzoriOpt = new SenzorOptional[this->nrSenzoriOpt];
		for (int i = 0; i < this->nrSenzoriOpt; i++)
		{
			this->vectorSenzoriOpt[i] = so[i];
			this->CostTotalSO += so[i].getpretSO();
		}
	}

	int getCostTotalSO()
	{
		if (this->CostTotalSO != 0)
			this->CostTotalSO = 0;
		for (int i = 0; i < this->nrSenzoriOpt; i++)
			this->CostTotalSO += this->vectorSenzoriOpt[i].getpretSO();
		return this->CostTotalSO;
	}
	string getCondusAutonom()
	{
		int autonom = this->CA();
		if (autonom == 12)
		{
			this->CondusAutonom = "Masina are functia de condus autonom.";
		}
		else if (autonom < 12)
		{
			this->CondusAutonom = "Masina nu are functia de condus autonom.";
		}
		return this->CondusAutonom;
	}

	//SUPRAINCARCARE OPERATORI
	Masina operator=(const Masina& m)
	{
		Vehicul::operator=(m);
		this->nume = m.nume;
		this->model = m.model;
		if (this->vectorSenzori != nullptr)
			delete[]this->vectorSenzori;
		this->nrSenzori = m.nrSenzori;
		this->vectorSenzori = new Senzor[this->nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++)
			this->vectorSenzori[i] = m.vectorSenzori[i];
		this->nrSenzoriOpt = m.nrSenzoriOpt;
		this->vectorSenzoriOpt = new SenzorOptional[this->nrSenzoriOpt];
		for (int i = 0; i < this->nrSenzoriOpt; i++)
			this->vectorSenzoriOpt[i] = m.vectorSenzoriOpt[i];
		this->CostTotalSO = m.CostTotalSO;
		this->CondusAutonom = m.CondusAutonom;
		this->rating = m.rating;
	}
	float operator+=(float rating)
	{
		this->rating += rating;
		return this->rating;
	}
	float operator-=(float rating)
	{
		this->rating -= rating;
		return this->rating;
	}
	bool operator>(Masina m)
	{
		return this->rating > m.rating;
	}
	bool operator<(Masina m)
	{
		return this->getpretV() < m.getpretV();
	}
	bool operator!=(Masina m)
	{
		return this->nrSenzori != m.nrSenzori;
	}

	friend ostream& operator<<(ostream& scriere, const Masina& m)
	{
		scriere << endl << "Numele masinii: " << m.nume << endl;
		scriere << "Modelul masinii: " << m.model << endl<<endl;
		if (m.nrSenzori > 0)
		{
			scriere << "Contine: " << m.nrSenzori << " senzor(i)." << endl << endl;
			for (int i = 0; i < m.nrSenzori; i++)
			{
				scriere << "Senzorul " << i + 1 << ": " << endl << endl;
				scriere << m.vectorSenzori[i] << endl;
			}
		}
		else
			scriere << "Masina nu are senzori." << endl << endl;
		if (m.nrSenzoriOpt > 0)
		{
			scriere << "Contine: " << m.nrSenzoriOpt << " senzor(i) optional(i)." << endl << endl;
			for (int i = 0; i < m.nrSenzoriOpt; i++)
			{
				scriere << "Senzorul optional " << i + 1 << ": " << endl << endl;
				scriere << m.vectorSenzoriOpt[i] << endl;
			}
			scriere << "Costul total pentru senzorii optionali este: " << m.CostTotalSO << " lei." << endl;
		}
		else
			scriere << "Masina nu are senzori optionali." << endl << endl;
		scriere << m.CondusAutonom << endl;
		scriere << endl << (Vehicul&)m;
		scriere << "RATING-UL FINAL AL MASINII ESTE DE: " << m.rating << "/10."<<endl;
		return scriere;
	}
	friend ofstream& operator<<(ofstream& fileo, const Masina& m)
	{
		fileo << "Numele masinii: " << m.nume << endl;
		fileo << "Modelul masinii: " << m.model << endl<<endl;
		if (m.nrSenzori > 0)
		{
			fileo << "Contine: " << m.nrSenzori << " senzor(i)" << endl;
			for (int i = 0; i < m.nrSenzori; i++)
			{
				fileo << "Senzorul " << i + 1 << ": " << endl << endl;
				fileo << m.vectorSenzori[i] << endl;
			}
		}
		else
			fileo << "Masina nu are senzori." << endl << endl;
		if (m.nrSenzoriOpt > 0)
		{
			fileo << "Contine: " << m.nrSenzoriOpt << " senzor(i) optional(i)" << endl;
			for (int i = 0; i < m.nrSenzoriOpt; i++)
			{
				fileo << "Senzorul optional " << i + 1 << ": " << endl << endl;
				fileo << m.vectorSenzoriOpt[i] << endl;
			}
			fileo << "Costul total pentru senzorii optionali este: " << m.CostTotalSO << " lei" << endl;
		}
		else
			fileo << "Masina nu are senzori optionali." << endl << endl;
		fileo << m.CondusAutonom << endl;
		fileo << endl << (Vehicul&)m;
		fileo << "RATING-UL FINAL AL MASINII ESTE DE: " << m.rating << "/10." << endl;
		return fileo;
	}

	friend istream& operator>>(istream& citire, Masina& m)
	{
		ifstream filei("senzori.txt", ios::in);
		cout << "Introduceti numele masinii: ";
		getline(citire >> ws, m.nume);
		cout << "Introduceti modelul masinii: ";
		getline(citire >> ws, m.model);
		filei >> m.nrSenzori;
		if (m.nrSenzori > 0)
		{
			cout << "S-a(u) adaugat " << m.nrSenzori << " senzor(i)." << endl << endl;
			if (m.vectorSenzori != nullptr)
				delete[]m.vectorSenzori;
			m.vectorSenzori = new Senzor[m.nrSenzori];
			for (int i = 0; i < m.nrSenzori; i++)
			{
				filei >> m.vectorSenzori[i];
			}
		}
		else
			cout << "Masina nu are senzori." << endl << endl;
		filei >> m.nrSenzoriOpt;
		if (m.nrSenzoriOpt > 0)
		{
			cout << "S-a(u) adaugat " << m.nrSenzoriOpt << " senzor(i) optional(i)." << endl << endl;
			if (m.vectorSenzoriOpt != nullptr)
				delete[]m.vectorSenzoriOpt;
			m.vectorSenzoriOpt = new SenzorOptional[m.nrSenzoriOpt];
			for (int i = 0; i < m.nrSenzoriOpt; i++)
			{
				filei >> m.vectorSenzoriOpt[i];
			}
		}
		else
			cout << "Masina nu are senzori optionali." << endl << endl;
		m.getCostTotalSO();
		citire >> (Vehicul&)m;
		m.getCondusAutonom();
		m.getrating();
		return citire;
	}
	friend ifstream& operator>>(ifstream& filei, Masina& m)
	{
		getline(filei >> ws, m.nume);
		getline(filei >> ws, m.model);
		filei >> m.nrSenzori;
		if (m.vectorSenzori != nullptr)
			delete[]m.vectorSenzori;
		for (int i = 0; i < m.nrSenzori; i++)
			filei >> m.vectorSenzori[i];
		filei >> m.nrSenzoriOpt;
		if (m.vectorSenzoriOpt != nullptr)
			delete[]m.vectorSenzoriOpt;
		for (int i = 0; i < m.nrSenzoriOpt; i++)
			filei >> m.vectorSenzoriOpt[i];
		filei >> (Vehicul&)m;
		m.getCostTotalSO();
		m.getCondusAutonom();
		m.getrating();
		return filei;
	}
	

	//FUNCTIA VIRTUALA
	int CA() // Daca Masina contine urmatorii Senzori(deja in dotare sau optionali): Radar, Ultrasonic, Lidar si Video si sunt toti interconectati intre ei, Masina are functia de CA (Condus Autonom)
	{
		int autonom=0;
		if(this->nrSenzori>=4)
			for (int i = 0; i < this->nrSenzori; i++)
			{
				if (this->vectorSenzori[i].getnume() == "Radar" || this->vectorSenzori[i].getnume() == "Ultrasonic" || this->vectorSenzori[i].getnume() == "Lidar" || this->vectorSenzori[i].getnume() == "Video")
					if (this->vectorSenzori[i].getinterconectare() == true)
						if (this->vectorSenzori[i].getnrSenzoriConect() >= 3)
							for (int j = 0; j < this->vectorSenzori[i].getnrSenzoriConect(); j++)
								if (this->vectorSenzori[i].getsenzoriConect(j) == "Radar" || this->vectorSenzori[i].getsenzoriConect(j) == "Ultrasonic" || this->vectorSenzori[i].getsenzoriConect(j) == "Lidar" || this->vectorSenzori[i].getsenzoriConect(j) == "Video")
									autonom++;
			}
		if(autonom==0)
			if(this->nrSenzoriOpt>=4)
				for (int i = 0; i < this->nrSenzoriOpt; i++)
				{
					if (this->vectorSenzoriOpt[i].getnume() == "Radar" || this->vectorSenzoriOpt[i].getnume() == "Ultrasonic" || this->vectorSenzoriOpt[i].getnume() == "Lidar" || this->vectorSenzoriOpt[i].getnume() == "Video")
						if (this->vectorSenzoriOpt[i].getinterconectare() == true)
							if (this->vectorSenzoriOpt[i].getnrSenzoriConect() >= 3)
								for (int j = 0; j < this->vectorSenzoriOpt[i].getnrSenzoriConect(); j++)
									if (this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Radar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Ultrasonic" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Lidar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Video")
										autonom++;
				}
		else if (autonom == 3)
			if (this->nrSenzoriOpt >= 3)
				for (int i = 0; i < this->nrSenzoriOpt; i++)
				{
					if (this->vectorSenzoriOpt[i].getnume() == "Radar" || this->vectorSenzoriOpt[i].getnume() == "Ultrasonic" || this->vectorSenzoriOpt[i].getnume() == "Lidar" || this->vectorSenzoriOpt[i].getnume() == "Video")
						if (this->vectorSenzoriOpt[i].getinterconectare() == true)
							if (this->vectorSenzoriOpt[i].getnrSenzoriConect() >= 3)
								for (int j = 0; j < this->vectorSenzoriOpt[i].getnrSenzoriConect(); j++)
									if (this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Radar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Ultrasonic" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Lidar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Video")
										autonom++;
				}
		else if (autonom == 6)
			if (this->nrSenzoriOpt >= 2)
				for (int i = 0; i < this->nrSenzoriOpt; i++)
				{
					if (this->vectorSenzoriOpt[i].getnume() == "Radar" || this->vectorSenzoriOpt[i].getnume() == "Ultrasonic" || this->vectorSenzoriOpt[i].getnume() == "Lidar" || this->vectorSenzoriOpt[i].getnume() == "Video")
						if (this->vectorSenzoriOpt[i].getinterconectare() == true)
							if (this->vectorSenzoriOpt[i].getnrSenzoriConect() >= 3)
								for (int j = 0; j < this->vectorSenzoriOpt[i].getnrSenzoriConect(); j++)
									if (this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Radar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Ultrasonic" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Lidar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Video")
										autonom++;
				}
		else if (autonom == 9)
			if (this->nrSenzoriOpt >= 1)
				for (int i = 0; i < this->nrSenzoriOpt; i++)
				{
					if (this->vectorSenzoriOpt[i].getnume() == "Radar" || this->vectorSenzoriOpt[i].getnume() == "Ultrasonic" || this->vectorSenzoriOpt[i].getnume() == "Lidar" || this->vectorSenzoriOpt[i].getnume() == "Video")
						if (this->vectorSenzoriOpt[i].getinterconectare() == true)
							if (this->vectorSenzoriOpt[i].getnrSenzoriConect() >= 3)
								for (int j = 0; j < this->vectorSenzoriOpt[i].getnrSenzoriConect(); j++)
									if (this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Radar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Ultrasonic" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Lidar" || this->vectorSenzoriOpt[i].getsenzoriConect(j) == "Video")
										autonom++;
				}
		return autonom;
	}
	//Cu aceasta metoda se va deduce rating-ul(gradul de inteligenta) masinii. Rating-ul este pe o scala de la 0 la 10. Si se deduce in functii de mai multe criterii.
	float DeducereRating()
	{
		if (this->nrSenzori >= 2)
			this->rating++;
		for (int i = 0; i < this->nrSenzori; i++)
		{
			for (int j = 0; j < this->vectorSenzori[i].getnrInteractiuni(); j++)
				if (this->vectorSenzori[i].gettimpRaspunsInteractiune(j) <= 2)
					this->rating+=0.5;
			if (this->vectorSenzori[i].getinterconectare() == true)
			{
				this->rating+=0.25;
				if (this->vectorSenzori[i].getnrSenzoriConect() >= 3)
					this->rating+=0.25;
			}
		}
		if (this->nrSenzoriOpt >= 1)
			this->rating++;
		int autonom = this->CA();
		if (autonom == 12)
		{
			this->rating = this->rating + 3;
		}
		else if (autonom < 12 && autonom > 0)
		{
			this->rating++;
		}
		if (this->rating <= 10)
			return this->rating;
		else
			return 10;
	}
};
/* !!!!!!! Se citeste de la tastatura in felul urmator
pentru bool:
0 pentru false
1 pentru true
pentru enum:
0 pentru benzina
1 pentru motorina
2 pentru hibrid
3 pentru electric
4 pentru hidrogen*/
int Senzor::contor = 1;
void main()
{
	fstream fisIn;
	ofstream fisOut;

	Senzor* s = nullptr;
	int nrS;
	cout << "Introduceti numarul de senzori pe care vreti sa ii adaugati in fisier: ";
	cin >> nrS;
	if (nrS > 0)
		s = new Senzor[nrS];

	SenzorOptional* so = nullptr;
	int nrSO;
	cout << "Introduceti numarul de senzori optionali pe care vreti sa ii adaugati in fisier: ";
	cin >> nrSO;
	if (nrSO > 0)
		so = new SenzorOptional[nrSO];
	Masina m;

	fisIn.open("senzori.txt", ios::out);
	fisIn << nrS<<endl;
	cout << "Se introduc senzorii, daca acestia exista: " << endl<<endl;
	if (nrS > 0)
	{
		for (int i = 0; i < nrS; i++)
		{
			cin >> s[i];
			fisIn << s[i];
			cout << "S-a adaugat senzorul " << i + 1 << " in fisier." << endl<<endl;
		}
		cout << "S-au adaugat toti senzorii." << endl<<endl;
	}
	else
		cout << "Masina nu are senzori." << endl<<endl;
	fisIn << nrSO<<endl;
	cout << "Acum se introduc senzorii optionali, daca acestia exista: " << endl<<endl;
	if (nrSO > 0)
	{
		for (int i = 0; i < nrSO; i++)
		{
			cin >> so[i];
			fisIn << so[i];
		}
		cout << "S-au adaugat toti senzorii optionali." << endl << endl;
	}
	else
		cout << "Masina nu are senzori optionali." << endl<<endl;
	cout << "Se citesc datele de la tastatura de aici: " << endl << endl;;

	fisIn.close();
	fisIn.open("senzori.txt", ios::in);
	cin >> m;
	string caleFisier;
	cout << "Introduceti calea fisierului: ";
	cin >> caleFisier;
	fisIn.close();
	cout << m;
	fisOut.open(caleFisier, ios::out);
	cout << "In acest moment se introduc datele in " << caleFisier << endl;
	fisOut << m;
	fisOut.close();
	
	
	//DIVERSE TESTE
	


	//Senzor s1;
	//("Miscare", "Bara spate", 2, new float[2]{ 3.2,2.9 },5, "Bubuie masina", true, 2, new string[2]{ "Presiune","Radar"},300);
	//SenzorOptional s3 = s1;
	//cout << s1();
	//cin>> s1;
	//s1.settimpRaspunsInteractiune(0, 7.9);
	/*cout << s1;
	SenzorOptional s2=s1--;
	cout << s1;
	cout << s2;*/
	//Senzor s2("Miscare", "Bara fata", 4, new float[4]{ 1.2,7.5,0.3,5 }, 7, "Bum", false, 0, new string[0]{});
	//cout << s2;
	//s1 = s1 + s2;
	/*Senzor s3;
	cin >> s3;
	cout << s3;*/
	//Senzor s4 = s1;
	//cout << s4;
	//int n = 3;
	//cout << s2 / n << endl;
	//cout << s2[0];
	/*Senzor* vector;
	int dim = 3;
	vector = new Senzor[3];
	for (int i = 0; i < dim; i++)
		cin >> vector[i];
	for (int i = 0; i < dim; i++)
	{
		cout << vector[i] << endl;
	}*/
	/*Vehicul v1;
	cin >> v1;
	cout << v1;*/
	//Masina m3("Rolls", "Royce", 1, new Senzor[1]{ s2 }, 1, new SenzorOptional[1]{ s1 }, BENZINA, 7200);
	//cin >> m;
	//cout << m;
	//cout << m;
	//Masina m2 = m3;
	//cout << m2;
	//m.setvectorSenzoriOpt(2, new SenzorOptional[2]{ s1,s3 });
	//m -= 1;
	//m += 8;
	/*if (m < m2)
		cout << "m este mai ieftina."<<endl;
	else
		cout << "m2 este mai ieftina."<<endl;
	if (m != m2)
		cout << "Nu au acelasi numar de senzori.";
	else
		cout << "Au acelasi numar de senzori.";*/
	
}
#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class Carte {
private:
	char* titlu;
	char* autor;
	int an;
	int disponibilitate;
public:
	Carte();
	Carte(char* titlu, char* autor, int an, int disponibilitate);
	Carte(const Carte& c);
	~Carte();
	char* getTitlu();
	char* getAutor();
	int getAn();
	int getDisponibilitate();
	void setTitlu(char* titlu);
	void setAutor(char* autor);
	void setAn(int an);
	void setDisponibilitate(int disponibilitate);

	Carte& operator=(const Carte& c);
	bool operator==(const Carte& c);
	friend ostream& operator<<(ostream& os, const Carte& c);
};

#pragma once
#include <string>
#include <numeric>
#include <vector>
#include "Carte.h"
#include "RepoFile.h"
using namespace std;

class Service {
private:
	RepoFile R;
public:
	Service();
	~Service();
	Service(RepoFile& R);
	void setRepo(RepoFile& R);

	int Add(char* titlu, char* autor, int an);
	int Delete(char* titlu, char* autor, int an, int disponibilitate);
	int Update(int poz, char* titlu, char* autor, int an, int disponibilitate);

	int getSize();
	vector<Carte> getAll();

	int Find(Carte c);
	int Imprumut(char* titlu, char* autor, int an);
	int Returnare(char* titlu, char* autor, int an);
};

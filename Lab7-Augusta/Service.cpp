#include "Service.h"

Service::Service() {
}

Service::Service(RepoFile& R)
{
	this->R = R;
}

Service::~Service() {
}

void Service::setRepo(RepoFile& R)
{
	this->R = R;
}

int Service::Add(char* titlu, char* autor, int an) {
	int disponibilitate = 0;
	if (an <= 0) {
		return -1;
	}
	Carte c(titlu, autor, an, disponibilitate);
	R.Add(c);
	return 0;
}

int Service::Delete(char* titlu, char* autor, int an, int disponibilitate) {

	Carte c(titlu, autor, an, disponibilitate);
	int poz = R.getPoz(c);
	if (poz < 0 || poz > R.getSize()) {
		return -1;
	}
	R.Delete(poz, c);
	return 0;
}

int Service::Update(int poz, char* titlu, char* autor, int an, int disponibilitate) {
	if (an <= 0) {
		return -1;
	}
	Carte c1(titlu, autor, an, disponibilitate);
	R.Update(poz, c1);
	return 0;
}

//------------------------------------------------------------

int Service::getSize() {
	return R.getSize();
}

vector<Carte> Service::getAll() {
	return R.getAll();
}

//------------------------------------------------------------

int Service::Find(Carte c) {
	return R.getPoz(c);
}

int Service::Imprumut(char* titlu, char* autor, int an)
{
	vector<Carte> carti = getAll();
	for (Carte c : carti) {
		if ((strcmp(c.getTitlu(), titlu) == 0) && (strcmp(c.getAutor(), autor) == 0) && (c.getAn() == an) && (c.getDisponibilitate() == 0)) {
			int poz = Find(c);
			Update(poz, titlu, autor, an, -1);
			return 0;
		}
	}
	return -1;
}

int Service::Returnare(char* titlu, char* autor, int an)
{
	vector<Carte> carti = getAll();
	for (Carte c : carti) {
		if ((strcmp(c.getTitlu(), titlu) == 0) && (strcmp(c.getAutor(), autor) == 0) && (c.getAn() == an) && (c.getDisponibilitate() == -1)) {
			int poz = Find(c);
			Update(poz, titlu, autor, an, 0);
			return 0;
		}
	}
	return -1;
}


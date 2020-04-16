#include "Carte.h"

Carte::Carte() {
	this->titlu = NULL;
	this->autor = NULL;
	this->an = 0;
	this->disponibilitate = 0;
}

Carte::Carte(char* titlu, char* autor, int an, int disponibilitate)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, 1 + strlen(autor), autor);
	this->an = an;
	this->disponibilitate = disponibilitate;
}

Carte::Carte(const Carte& c) {
	this->titlu = new char[strlen(c.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(c.titlu), c.titlu);
	this->autor = new char[strlen(c.autor) + 1];
	strcpy_s(this->autor, 1 + strlen(c.autor), c.autor);
	this->an = c.an;
	this->disponibilitate = c.disponibilitate;
}

Carte::~Carte() {
	this->titlu = NULL;
	this->autor = NULL;
	this->an = 0;
	this->disponibilitate = 0;
}

char* Carte::getTitlu() {
	return this->titlu;
}

char* Carte::getAutor() {
	return this->autor;
}

int Carte::getAn() {
	return this->an;
}

int Carte::getDisponibilitate() {
	return this->disponibilitate;
}

void Carte::setTitlu(char* titlu)
{
	if (this->titlu) {
		delete[] this->titlu;
	}
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
}

void Carte::setAutor(char* autor) {
	if (this->autor) {
		delete[]this->autor;
	}
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
}

void Carte::setAn(int an) {
	this->an = an;
}

void Carte::setDisponibilitate(int disponibilitate) {
	this->disponibilitate = disponibilitate;
}

Carte& Carte::operator=(const Carte& c) {
	this->setTitlu(c.titlu);
	this->setAutor(c.autor);
	this->setAn(c.an);
	this->setDisponibilitate(c.disponibilitate);
	return *this;
}

bool Carte:: operator==(const Carte& c) {
	return (strcmp(this->titlu, c.titlu) == 0) && (strcmp(this->autor, c.autor) == 0) && (this->an == c.an) && (this->disponibilitate == c.disponibilitate);
}

ostream& operator<<(ostream& os, const Carte& c)
{
	os << "Titlu: " << c.titlu << "  Autor: " << c.autor << "  An: " << c.an << "  Diponibila: " << c.disponibilitate;
	return os;
}

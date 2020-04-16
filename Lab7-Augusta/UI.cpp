#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() {
}

UI::UI(Service& S)
{
	this->S = S;
}

UI::~UI() {
}

void UI::Meniu() {
	cout << endl;
	cout << "         MENIU" << endl;
	cout << endl;
	cout << " 0. Iesire" << endl;
	cout << " 1. Add" << endl;
	cout << " 2. Delete" << endl;
	cout << " 3. Update" << endl;
	cout << " 4. Afisare" << endl;
	cout << " 5. Imprumut" << endl;
	cout << " 6. Returnare" << endl;
}

//------------------------------------------------------------------------------------------------------------

void UI::Add() {
	char titlu[100];
	char autor[100];
	int an;
	cout << endl;
	cout << "Introduceti numele: ";
	cin >> titlu;
	cout << "Introduceti autorul: ";
	cin >> autor;
	cout << "Introduceti anul: ";
	cin >> an;
	int r = S.Add(titlu, autor, an);
	if (r == 0) {
		cout << endl;
		cout << "Carte adaugata!   " << endl;
	}
	if (r == -1) {
		cout << endl;
		cout << "Date invalide" << endl;
	}
}

void UI::Delete()
{
	ShowAll();
	char titlu[100];
	char autor[100];
	int an;
	int disponibilitate;
	cout << endl;
	cout << "Introduceti numele cartii: ";
	cin >> titlu;
	cout << "Introduceti autorul cartii: ";
	cin >> autor;
	cout << "Introduceti anul cartii: ";
	cin >> an;
	cout << "Introduceti disponibilitatea cartii (0.Da / -1. Nu): ";
	cin >> disponibilitate;
	int r = S.Delete(titlu, autor, an, disponibilitate);
	if (r == 0) {
		cout << endl;
		cout << "Carte stearsa!" << endl;
	}
	if (r == -1) {
		cout << endl;
		cout << "Date invalide!" << endl;
	}
}

void UI::Update()
{
	ShowAll();
	char titlu[100];
	char autor[100];
	int an;
	int disponibilitate;
	cout << endl;
	cout << "Introduceti numele: ";
	cin >> titlu;
	cout << "Introduceti autorul: ";
	cin >> autor;
	cout << "Introduceti anul: ";
	cin >> an;
	cout << "Introduceti disponibilitatea cartii (0. Da / -1. Nu): ";
	cin >> disponibilitate;
	Carte c(titlu, autor, an, disponibilitate);
	int poz = S.Find(c);
	if (poz < 0 || poz > S.getSize()) {
		cout << endl;
		cout << "Date invalide!" << endl;
	}
	else {
		char ntitlu[100];
		char nautor[100];
		int nan;
		int ndisponibilitate;
		cout << endl;
		cout << "Introduceti noul nume: ";
		cin >> ntitlu;
		cout << "Introduceti noul autor: ";
		cin >> nautor;
		cout << "Introduceti noul an: ";
		cin >> nan;
		cout << "Introduceti noua disponibilitate (0. Da / -1. Nu): ";
		cin >> ndisponibilitate;
		int r = S.Update(poz, ntitlu, nautor, nan, ndisponibilitate);
		if (r == -1) {
			cout << endl;
			cout << "Date invalide!" << endl;
		}
		if (r == 0) {
			cout << endl;
			cout << "Carte updatata!" << endl;
		}
	}
}

void UI::ShowAll()
{
	cout << endl;
	cout << "	    Carti" << endl;
	cout << endl;
	for (int i = 0; i < S.getSize(); i++)
	{
		Carte c = S.getAll()[i];
		if (c.getDisponibilitate() == 0) {
			cout << "Titlu: " << c.getTitlu() << " Autor: " << c.getAutor() << " An: " << c.getAn() << " Disponibila: Da" << endl;
		}
		if (c.getDisponibilitate() == -1) {
			cout << "Titlu: " << c.getTitlu() << " Autor: " << c.getAutor() << " An: " << c.getAn() << " Disponibila: Nu" << endl;
		}
	}
}

//------------------------------------------------------------------------------------------------------------

void UI::Imprumut() {
	ShowAll();
	char titlu[100];
	char autor[100];
	int an;
	cout << endl;
	cout << "Introduceti titlul cartii: ";
	cin >> titlu;
	cout << "Introduceti autorul cartii: ";
	cin >> autor;
	cout << "Introduceti anul cartii: ";
	cin >> an;
	int r = S.Imprumut(titlu, autor, an);
	if (r == 0) {
		cout << endl;
		cout << "Carte imprumutata cu succes! " << endl;
	}
	if (r == -1) {
		cout << endl;
		cout << "Cartea aleasa nu exista sau a fost deja imprumutata!" << endl;
	}
}

void UI::Returnare() {
	ShowAll();
	char titlu[100];
	char autor[100];
	int an;
	cout << endl;
	cout << "Introduceti titlul cartii: ";
	cin >> titlu;
	cout << "Introduceti autorul cartii: ";
	cin >> autor;
	cout << "Introduceti anul cartii: ";
	cin >> an;
	int r = S.Returnare(titlu, autor, an);
	if (r == -1) {
		cout << endl;
		cout << "Cartea nu apartine acestei librari!" << endl;
	}
	if (r == 0) {
		cout << endl;
		cout << "Carte returnata cu succes!" << endl;
	}
}

//------------------------------------------------------------------------------------------------------------

void UI::Run()
{
	bool ok = false;
	while (!ok) {
		Meniu();
		int cmd;
		cout << endl;
		cout << "  Insert your option: ";
		cin >> cmd;
		switch (cmd)
		{
		case(0): { ok = true; break; }
		case(1): { Add(); break; }
		case(2): { Delete(); break; }
		case(3): { Update(); break; }
		case(4): { ShowAll(); break; }
		case(5): {Imprumut(); break; }
		case(6): {Returnare(); break; }
		default:
			cout << endl;
			cout << "Optiune invalida!" << endl;
		}
	}
}
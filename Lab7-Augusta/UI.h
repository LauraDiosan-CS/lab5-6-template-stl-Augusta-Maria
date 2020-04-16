#pragma once
#include<string>
#include<sstream>
#include<iterator>
#include<numeric>
#include <stdio.h>
#include <queue>
#include "Service.h"
#include "Carte.h"
using namespace std;

class UI {
private:
	Service S;
	void Meniu();
	//--------------------------------------------------------------------
	void Add();
	void Delete();
	void Update();
	void ShowAll();
	//--------------------------------------------------------------------
	void Imprumut();
	void Returnare();

public:
	UI();
	~UI();
	UI(Service& S);
	void Run();
};

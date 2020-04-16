#pragma once
#include <vector>
#include <fstream>
#include "Carte.h"
#include "Repo.h"

class RepoFile : public Repo<Carte> {
private:
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoFile();
	RepoFile(const char* fileNameIn, const char* fileNameOut);
	~RepoFile();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);
	void loadFromFile();
	void saveToFile();

	void Add(Carte c);
	void Delete(int poz, Carte c);
	void Update(int poz, Carte c);
};
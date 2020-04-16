#include "RepoFile.h"

RepoFile::RepoFile() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoFile::RepoFile(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

RepoFile::~RepoFile() {
}

//----------------------------------------------------------------------------

void RepoFile::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoFile::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoFile::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->Repo::items.clear();
		ifstream f(this->fileNameIn);
		char titlu[50];
		char autor[50];
		int an;
		int disponibilitate;
		while (!f.eof())
		{
			f >> titlu >> autor >> an >> disponibilitate;
			if (strlen(titlu) > 0)
			{
				this->Repo::Add(Carte(titlu, autor, an, disponibilitate));
			}
		}
		f.close();
	}
}

void RepoFile::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->Repo::items.size(); i++)
		{
			f << this->Repo::items[i] << endl;
		}
		f.close();
	}
}

void RepoFile::Add(Carte c) {
	Repo::Add(c);
	saveToFile();
}

void RepoFile::Delete(int poz, Carte c) {
	Repo::Delete(poz, c);
	saveToFile();
}

void RepoFile::Update(int poz, Carte c) {
	Repo::Update(poz, c);
	saveToFile();
}


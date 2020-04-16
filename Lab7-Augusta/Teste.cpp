#include "Teste.h"

void TestCarte() {
	char t1[2] = "1";
	char t2[2] = "2";
	char t3[2] = "3";
	char a1[2] = "1";
	char a2[2] = "2";
	char a3[2] = "3";

	Carte c1(t1, a1, 1, 0);
	Carte c2(t2, a2, 2, 0);
	c2.setTitlu(t3);
	c2.setAutor(a3);
	c2.setAn(3);
	c2.setDisponibilitate(-1);

	assert(strcmp(c1.getTitlu(), t1) == 0);
	assert(strcmp(c1.getAutor(), a1) == 0);
	assert(c1.getAn() == 1);
	assert(c1.getDisponibilitate() == 0);
	assert(strcmp(c2.getTitlu(), t3) == 0);
	assert(strcmp(c2.getAutor(), a3) == 0);
	assert(c2.getAn() == 3);
	assert(c2.getDisponibilitate() == -1);
}

void TestRepo() {
	char t1[2] = "1";
	char t2[2] = "2";
	char t3[2] = "3";
	char a1[2] = "1";
	char a2[2] = "2";
	char a3[2] = "3";

	Carte c1(t1, a1, 1, 0);
	Carte c2(t2, a2, 2, 0);
	Carte c3(t3, a3, 3, -1);
	Repo<Carte> R;
	R.Add(c1);
	R.Add(c2);
	R.Add(c3);
	R.Update(1, c3);
	R.Delete(2, c3);

	assert(R.getSize() == 2);
	assert(R.getAll()[1] == c3);
	assert(R.getPoz(c1) == 0);
}

void TestService() {
	char t1[2] = "1";
	char t2[2] = "2";
	char t3[2] = "3";
	char tu[2] = "4";
	char a1[2] = "1";
	char a2[2] = "2";
	char a3[2] = "3";
	char au[2] = "4";

	Carte c1(t1, a1, 1, 0);
	Carte c2(t2, a2, 2, 0);
	Carte c3(t3, a3, 3, -1);
	Carte c4(tu, au, 4, -1);
	Service S;
	S.Add(t1,a1,1);
	S.Add(t2,a2,2);
	S.Add(t3,a3,3);
	S.Update(1, tu, au, 4, -1);
	S.Delete(t3,a3,3,-1);

	assert(S.getSize() == 3);
	assert(S.getAll()[1] == c4);
	assert(S.Find(c1) == 0);
	assert(S.Imprumut(tu, au, 4) == -1);
	assert(S.Returnare(tu, au, 4) == 0);
}

void TestRepoFile() {
	char t1[2] = "1";
	char a1[2] = "1";

	RepoFile R("TestCartiIn.txt", "TestCartiOut.txt");
	Carte c1(t1, a1, 1, 0);
	R.saveToFile();

	assert(R.getSize() == 2);
	assert(R.getAll()[0] == c1);
}
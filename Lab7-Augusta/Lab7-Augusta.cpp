#include <iostream>
#include "RepoFile.h"
#include "Service.h"
#include "Teste.h"
#include "UI.h"

int main()
{
    TestCarte();
    TestRepo();
    TestService();
    TestRepoFile();
    RepoFile R("CartiIn.txt", "CartiOut.txt");
    Service S(R);
    UI UI(S);
    UI.Run();
    return 0;
}

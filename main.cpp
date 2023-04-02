#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct aut
{
    char numeA[25], prenume[25];
};


struct CARTI
{

    aut autor;
    char nume[26];
    int pagini;
    int exemplare
    int pret;

} carte[101];



void citire (int &nr)
{
    ifstream fin("date.in");

    fin>>nr;

    for(int i=1; i<=nr; i++)
    {
        fin.get();
        fin.getline(carte[i].nume, 26);
        fin>>carte[i].autor.numeA>>carte[i].autor.prenume>>carte[i].pagini>>carte[i].exemplare>>carte[i].pret;
    }
    fin.close();

}
void afisare (int nr)
{


    for(int i=1; i<=nr; i++)
    {
        cout<<carte[i].nume<<endl;
        cout<<carte[i].autor.numeA<<" "<<carte[i].autor.prenume<<endl;
        cout<<carte[i].pagini<<endl<<carte[i].exemplare<<endl<<carte[i].pret<<endl;
    }


}

void rescriere(int nr)
{
    ofstream fout("date.in");
    fout<<nr<<endl;
    for(int i=1; i<=nr; i++)
    {
        fout<<carte[i].nume<<endl;
        fout<<carte[i].autor.numeA<<" "<<carte[i].autor.prenume<<endl;
        fout<<carte[i].pagini<<endl<<carte[i].exemplare<<endl<<carte[i].pret<<endl;
    }
    fout.close();

}


void adaugare( CARTI c)
{
    fstream fout("date.in", ios::app);



    fout<<c.nume<<endl;
    fout<<c.autor.numeA<<" "<<c.autor.prenume<<endl;
    fout<<c.pagini<<endl<<c.exemplare<<endl<<c.pret<<endl;
    fout.close();

}

int main()
{
    int nr;

    citire(nr);

    int raspuns;

    do
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 32);
        cout << "            ~Libraria GobTim~            \n\n";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "Afisare fond de carte. Apasati 1\n";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Daca ...cerinta 2... apasati tasta 2\n";


        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"4. Ordonare descrescatoare in functie de numarul de capitole"<<endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"5. Ordonare crescatoare a numarului de pagini estimate per capitol"<<endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "Daca vreti sa iesiti apasati tasta 0\n";

        cin >> raspuns;
        Sleep(100);
        system("CLS");




        switch(raspuns)
        {
        case 1:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<" Fond de carte."<<endl;
            afisare(nr);
            //system("Color 4D");
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;
        }


        case 2:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 18);
            cout<<"cerinta 2"<<endl;
            adaugare();
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;
        }


        case 3:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<"cerinta 3"<<endl;
            //..............
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 4:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout<<"cerinta 4"<<endl;
            for(int i = 1; i < nr ; i++)
            {
                for(int j = i + 1; j <=nr; j++)
                {
                    if(carte[i].exemplare < carte[j].exemplare)
                    {
                        CARTI aux = carte[i];
                        carte[i]= carte[j];
                        carte[j]= aux;
                    }
                }
            }
            rescriere(carte, nr);
            for(int i = 1; i <= nr; i++)
                cout << carte[i].exemplare << " ";
            cout << '\n';
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 5:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 17);
            cout<<"cerinta 5"<<endl;
            int* pag_cap = new int[nr];
            for(int i = 0; i < nr; i++)
            {
                pag_cap[i] = carte[i].pagini/carte[i].exemplare;
            }
            for(int i = 0; i < nr-1; i++)
            {
                for(int j = i + 1; j < nr; j++)
                {
                    if(pag_cap[i] > pag_cap[j])
                    {
                        int aux = pag_cap[i];
                        pag_cap[i] = pag_cap[j];
                        pag_cap[j] = aux;
                    }
                }
            }
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 6:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 21);
            cout<<"cerinta 6"<<endl;
            //..............
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 7:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout<<"cerinta 7"<<endl;
            //..............
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }
        case 0:
            break;
        default:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << "Tasta incorecta!\nApasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
        }

        }


    }
    while ( raspuns != 0);




}




/*
3
Crima din Orient Express
Agatha Cristie
 342
 5
 30
Ion
Liviu Rebreanu
412
5
 43
abc def
AAA BBB
 34
 2
 3
*/

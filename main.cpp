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


struct Carte
{

    aut autor;
    char nume[101];
    int pagini;
    int exemplare;
    int pret;


    void afisare()
    {
        cout<<"Nume carte: \t"<<nume<<endl;
        cout<<"Autor:\t"<<autor.numeA<<" "<<autor.prenume<<endl;
        cout<<"Pagini:\t"<<pagini<<endl;
        cout<<"Exemplare:\t"<<exemplare<<endl;
        cout<<"Pret:\t"<<pret<<endl;
        cout << "----------------------------------------------------"<<endl<<endl;
    }

};



void citire (Carte carti[], int &nr)
{
    ifstream fin("date.in");

    fin>>nr;

    for(int i=1; i<=nr; i++)
    {
        fin.get();
        fin.getline(carti[i].nume, 26);
        fin>>carti[i].autor.numeA>>carti[i].autor.prenume>>carti[i].pagini>>carti[i].exemplare>>carti[i].pret;
    }
    fin.close();

}
void afisare (Carte carti[], int nr)
{


    for(int i=1; i<=nr; i++)
    {
        carti[i].afisare();
    }


}

void rescriere(Carte carti[], int nr)
{
    ofstream fout("date.in");
    fout<<nr<<endl;
    for(int i=1; i<=nr; i++)
    {
        fout<<carti[i].nume<<endl;
        fout<<carti[i].autor.numeA<<" "<<carti[i].autor.prenume<<endl;
        fout<<carti[i].pagini<<endl<<carti[i].exemplare<<endl<<carti[i].pret<<endl;
    }
    fout.close();

}


void adaugare(Carte carti[], Carte c, int &nrcarti)
{
    nrcarti++;
    carti[nrcarti] = c;
    /*fstream fout("date.in", ios::app);
    fout<<c.nume<<endl;
    fout<<c.autor.numeA<<" "<<c.autor.prenume<<endl;
    fout<<c.pagini<<endl<<c.exemplare<<endl<<c.pret<<endl;
    fout.close();
    */

}

int main()
{
    int nr;
    Carte carti[101];
    citire(carti, nr);

    int raspuns;

    do
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 32);
        cout << "            ~Libraria GobTim~            \n\n";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "1. Afisare fond de carte\n";

        cout << "2. Adaugati o carte la fondul de Carte\n";

        cout << "3. Cumapara carti\n";

        cout << "4. Ordonare descrescatoare in functie de numarul de exemplare" << endl;

        cout << "5. Numarul total de carti" << endl;

        cout << "6. Cea mai scumpa carte si cea mai scumpa pereche de doua carti" << endl;

        cout << "Daca vreti sa iesiti apasati tasta 0\n";

        //cin >> raspuns;
        //Sleep(100);
        raspuns = getch();
        raspuns = raspuns - '0';
        system("CLS");




        switch(raspuns)
        {
        case 1:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<" Fond de carte."<<endl;
            afisare(carti, nr);
            //system("Color 4D");
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;
        }


        case 2:
        {
            ///SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 18);
            cout<<"Carte noua"<<endl;
            Carte carte;
            cout << "Introdu numele cartii" << endl;
            ///int a =getch();
            cin.clear();
            cin.sync();
            cin.getline(carte.nume, 100);
            cout << "Introdu numele si prenumele autorului" << endl;
            cin >> carte.autor.numeA >> carte.autor.prenume;
            cout << "Introdu numarul de pagini ale cartii" << endl;
            cin >> carte.pagini;
            cout << "Introdu numarul de exemplare" << endl;
            cin >> carte.exemplare;
            cout << "Introdu pretul cartii" << endl;
            cin >> carte.pret;
            adaugare(carti, carte, nr);
            rescriere(carti, nr);
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;
        }


        case 3:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<"Carti cumparate"<<endl;
            //..............
            int n;
            int alegeri_carti, nr_exemplare;
            cout << "Introdu numarul de carti cumparate" << endl;
            cin >> n;

            for(int i = 0; i < n; i++)
            {
                cout << "Introdu indexul cartii dorite: " << endl;
                cin >> alegeri_carti;
                if(alegeri_carti > nr)
                    cout << "Nu avem cartea dorita";
                else
                {
                    cout << "Cate exemplare doresti: " << endl;
                    cin >> nr_exemplare;
                    char varianta[5];
                    if(carti[alegeri_carti].exemplare < nr_exemplare)
                    {
                        cout << "Nu avem numarul acela de exemplare. Doriti sa cumparati doar " << carti[alegeri_carti].exemplare << " exemplare? ";
                        cin >> varianta;
                        if(stricmp(varianta, "Da") == 0)
                            carti[alegeri_carti].exemplare = 0;
                    }
                    else
                    {
                        carti[alegeri_carti].exemplare -= nr_exemplare;
                    }
                }

            }
            rescriere(carti, nr);

            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 4:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout<<"Lista de carti ordonata dupa numarul de exemplare"<<endl;
            for(int i = 1; i < nr ; i++)
            {
                for(int j = i + 1; j <=nr; j++)
                {
                    if(carti[i].exemplare < carti[j].exemplare)
                    {
                        Carte aux = carti[i];
                        carti[i]= carti[j];
                        carti[j]= aux;
                    }
                }
            }
            rescriere(carti, nr);
            afisare(carti, nr);
            cout << '\n';
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 5:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<"Numar de carti existente"<<endl;
            int tot = 0;
            for(int i = 1; i <= nr; i++)
                tot += carti[i].exemplare;
            cout << "Numarul total de carti disponibile este: " << tot <<endl;
            cout << "\n Apasati orice tasta pentru a va reintoarce la meniu!";
            getch();
            system("CLS");
            break;

        }


        case 6:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout<<"Cea mai scumpa carte si pereche de carti"<<endl;
            //..............
            int maxpret1 = max(carti[1].pret, carti[2].pret), maxpret2 = min(carti[1].pret, carti[2].pret), pozcarte[2];
            if(carti[1].pret > carti[2].pret)
            {
                maxpret1 = carti[1].pret;
                maxpret2 = carti[2].pret;
                pozcarte[0] = 1;
                pozcarte[1] = 2;
            }
            else{
                maxpret1 = carti[2].pret;
                maxpret2 = carti[1].pret;
                pozcarte[0] = 2;
                pozcarte[1] = 1;
            }
            for(int i = 3; i <= nr; i++){
                if(carti[i].pret > maxpret1){
                    maxpret2 = maxpret1;
                    pozcarte[1] = pozcarte[0];
                    maxpret1 = carti[i].pret;
                    pozcarte[0] = i;
                }
                else if(carti[i].pret > maxpret2){
                    maxpret2 = carti[i].pret;
                    pozcarte[1] = i;
                }
            }
            cout << "cea mai scumpa carte este: \"" << carti[pozcarte[0]].nume;
            cout << "\" si cea mai scumpa pereche de carti este : \"" << carti[pozcarte[0]].nume << "\" si \"" << carti[pozcarte[1]].nume << "\"";
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

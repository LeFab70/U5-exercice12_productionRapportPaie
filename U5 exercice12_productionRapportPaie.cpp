/*
	 Programmer: Fabrice Kouonang
	 Date:      07/10/2024
	 But:       Le programme demande le num employe, le nbre heure travail, taux horaire, le code du poste
				et calcul et affiche un rapport de paie de l'employe

*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


//Liste des constantes
const double TAUX_IMPOT_REGULIER    = (double)30 / 100;
const double TAUX_IMPOT_TPS_PARTIEL = (double)25 / 100;
const double TAUX_IMPOT_SUPERVISEUR = (double)35 / 100;
const double TAUX_PENSION           = (double)5 / 100;
const double TAUX_SYNDICAT_REGULIER = (double)2 / 100;
const double TAUX_SYNDICAT_PARTIEL  = (double)1 / 100;
const double TAUX_ASSURANCE_EMPLOI  = (double)2 / 100;

int main(void)
{
	
	//Liste des inputs du programmes
	unsigned int numEmploye   = 0;
	double   nbreHeureTravail = 0.0;
	double   tauxHoraire      = 0.0;
	string   codePoste        = "";
	string   nomEmploye       = "";
	char     displayChar      = ' ';
	string   displayString    = "1234567890";
	string   titre            = "RAPPORT DE PAIE";
	//Liste des variables intermedieres
	double   totalRetenues = 0.0;
	unsigned short i       = 9;  //pour affichage  setw()

	//liste des outputs
	string typePoste    = "";
	double salaireBrut = 0.0;
	double impot       = 0.0;
	double pension     = 0.0;
	double syndicat    = 0.0;
	double assurance   = 0.0;
	
	cout << "\t\t Bienvenu dans votre plateforme"
		<< endl
		<< "\t\t qui vous permet de generer les rapports de paies"
		<< endl << endl
		<< "Pour commencer, merci de fournir les informations sur l'employe: "
		<< endl;


	//Recuperation des data 
	cout << "Entrez le nom d'employe > ";
	getline(cin, nomEmploye);
	cout << "Entrez le numero d'employe > ";
	cin >> numEmploye;
	cout << "Entrez le nombre d'heures travaillees par l'employer > ";
	cin >> nbreHeureTravail;
	cout << "Entrez le taux horaire > ";
	cin >> tauxHoraire;
	cout << "Entrez le code de l'employe <R ouTP ou S>  > ";
	cin >> codePoste;

	//calcul et affichage
	salaireBrut = tauxHoraire * nbreHeureTravail;
	pension = salaireBrut * TAUX_PENSION;
	assurance = salaireBrut * TAUX_ASSURANCE_EMPLOI;


	if (codePoste == "TP")
	{
		typePoste = "Temps partiel";
		impot     = salaireBrut * TAUX_IMPOT_TPS_PARTIEL;
		syndicat  = salaireBrut * TAUX_SYNDICAT_PARTIEL;
		
	}
	else if (codePoste == "R")
	{
		typePoste = "Regulier";
		impot     = salaireBrut * TAUX_IMPOT_REGULIER;
		syndicat  = salaireBrut * TAUX_SYNDICAT_REGULIER;
	}
	else if (codePoste == "S")
	{
		typePoste = "Superviseur";
		impot     = salaireBrut * TAUX_IMPOT_SUPERVISEUR;

	}
	else
	{
		cout << "choix indisponible";
		return 0;
	}		
	totalRetenues = impot + pension + syndicat + assurance;

	cout << endl << endl
		<<fixed<<setprecision(2)
		<< setfill(displayChar) << setw(i) << displayChar
		<< "1"
		<< setw(i) << displayChar
		<< "2"
		<< setw(i) << displayChar
		<< "3"
		<< setw(i) << displayChar
		<< "4"
		<< setw(i) << displayChar
		<< "5"
		<< setw(i) << displayChar
		<< "6"
		<< setw(i) << displayChar
		<< "7"
		<< endl
		<< displayString
		<< displayString
		<< displayString
		<< displayString
		<< displayString
		<< displayString
		<< displayString
		<< endl<<endl
		<< setfill(displayChar) << setw(25) << displayChar
		<<titre
		<<endl;
	cout << setfill(' ') << setw(25) << displayChar;
	i = titre.size();
	displayChar = '=';
	cout << setfill(displayChar) << setw(i) << displayChar
		<< endl << endl
		<< "Nom employe: "
		<< nomEmploye
		<< endl
		<<setfill('_')<<setw(70)<<"_"
		<<endl<<endl
		<< "Employe #"
		<< numEmploye;
	displayChar = ' ';
	cout << setfill(displayChar) << setw(25) << displayChar
		<< "Type d'employe: "
		<< typePoste
		<< endl << endl
		<< "Nombre d'heures travaillees:\t"
		<< nbreHeureTravail
		<< endl
		<< "Taux a l'heure:\t\t\t"
		<< tauxHoraire << " $"
		<< endl << endl
		<< "SALAIRE BRUT:"
		<< setw(33) << displayChar
		<< salaireBrut << " $"
		<< endl << endl
		<< "DEDUCTIONS: "
		<< endl
		<< setw(27) << displayChar
		<< "Impot:"
		<< setw(5) << displayChar
		<< impot << " $"
		<< endl
		<< setw(14) << displayChar
		<< "Pensions du Canada:"
		<< setw(5) << displayChar
		<< pension << " $"
		<< endl
		<< setw(24) << displayChar
		<< "Syndicat:"
		<< setw(5) << displayChar
		<< syndicat << " $"
		<< endl
		<< setw(16) << displayChar
		<< "Assurance emploi:"
		<< setw(5) << displayChar
		<< assurance << " $"
		<< endl
		<< setw(12) << displayChar
		<< "Total des deductions:"
		<< setw(5) << displayChar
		<< totalRetenues << " $"
		<< endl << endl
		<< setfill('_') << setw(70) << "_"
		<<endl
		<< "SALAIRE NET: "
		<<setfill(' ')<< setw(32) << displayChar
		<< salaireBrut-totalRetenues << " $"
		<<endl
		<< setfill('_') << setw(70) << "_"
		<<endl<< endl;
	
	system("pause");
	return 0;
}

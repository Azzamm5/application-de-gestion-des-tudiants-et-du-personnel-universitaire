#include <iostream>
#include "uni.hpp"
#include <vector>
#include <string>
#include<iomanip>
using namespace std;

//############################################### Class Etudiant ##############################################
//---| Constructeur Parametrer | --------------------------------
Etudiant::Etudiant(string mat,string nom,string prenom,string niveau,string filiere,string site):
Mat(mat),Nom(nom),Prenom(prenom),Niveau(niveau),Filiere(filiere),Site(site){
        coursinscrits = "Aucune Cours Inscrit";
        status = "";
       
}


//---| Methode Getters | -----------------------------------------

string Etudiant::getMat(){return Mat;}

string Etudiant::getNom(){return Nom;} 

string Etudiant::getPrenom(){return Prenom;}

string Etudiant::getNiveau(){return Niveau;}

string Etudiant::getFiliere(){return Filiere;}

string Etudiant::getSite(){return Site;}

string Etudiant::getCoursinscrits(){return coursinscrits;}

void Etudiant::setCoursinscrits(string C){coursinscrits = C;}

void Etudiant::setFiliere(string filiere){Filiere = filiere;}
void Etudiant::setSite(string site){Site = site;}
void Etudiant::setMat(string mat){Mat = mat;}

string Etudiant::getStatus(){return status;}
void Etudiant::setStatus(string s){status = s;}


                            //---| Methode Affiche | -----------------------------------------

void Etudiant::AfficherEtudiant() {
        cout << "|------------------------------------------------------|" << endl;
        cout << "|----------|         ETUDIANT           |--------------|" << endl;
        cout << "|------------------------------------------------------|" << endl;
        cout << "| - Mat     : "<< Mat<<endl;
        cout << "|                                                      |" << endl;
        cout << "| - Nom     : "<< Nom<<endl;
        cout << "|                                                      |" << endl;
        cout << "| - Prenom  : "<< Prenom<<endl;
        cout << "|                                                      |" << endl;
        cout << "| - Niveau  : "<< Niveau<<endl;
        cout << "|                                                      |" << endl;
        cout << "| - Filiere : "<< Filiere<<endl;
        cout << "|                                                      |" << endl;
        cout << "| - Site    : "<< Site<<endl;
        cout << "|                                                      |" << endl;
        cout << "|------------|     INSCRIPRION AU COURS      |---------|" << endl;
        cout << "|                                                      |" << endl;
        cout << "| - Cours   : " << coursinscrits << endl;
        cout << "|                                                      |" << endl;
        cout << "| - Status  : " << status <<  endl;
        cout << "|------------------------------------------------------|" << endl;

}

void Etudiant::ModifierEtudiant(string F, string S){
        Filiere = F;
        Site = S;
}


void Etudiant::afficheinscription(){
        cout << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|------- | INSCRIPRION AU COURS |-------|" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "| - Nom    : "<< Nom<<endl;
        cout << "|                                       |" << endl;
        cout << "| - Cours  : " << coursinscrits << endl;
        cout << "|                                       |" << endl;
        cout << "| - Status : " << endl;
        cout << "|                                       |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << endl;
}



//##########################################################################################################################################
//########################################## Class Gestion Etudiant ##############################################
GestionEtudiant::GestionEtudiant(){}; 

vector<Etudiant>& GestionEtudiant::getEtudiants(){
        return Etudiants;
}
void GestionEtudiant::CreationEtudiant(Etudiant& E){
        Etudiants.push_back(E);

}

void  GestionEtudiant::AfficherDetailsEtudiant(){
        for(auto& E : Etudiants){
                E.AfficherEtudiant();
        }
} 
void GestionEtudiant::ModifierEtudiant(){
        cout << "Entrer le matricule : ";
        string mat;
        cin >> mat;
        for(auto i = Etudiants.begin(); i != Etudiants.end(); ++i){
                if(i->getMat() == mat){
                string F,S;
                cout << "Entrer New Filliere : ";
                cin >> F;
                cout << "Entrer New Site : ";
                cin >> S;
                i->setFiliere(F);
                i->setSite(S);
        }
        }   
}
void GestionEtudiant::SupprimerEtudiant(string mat){
        bool Etudianttrouver = false;
        for(auto i = Etudiants.begin(); i != Etudiants.end(); ++i){
                if(i->getMat() == mat){
                        Etudianttrouver = true;
                        Etudiants.erase(i);
                        
                        cout << "Etudiant avec le matricule " << mat << " supprimÃ©." << endl;
                        break;
                }
        }if (!Etudianttrouver){
                cout << "Matricule Introuvable" << endl;
        }

}


void GestionEtudiant::RechercheEtudiant(string m){
        bool etudianttrouver = false;
        for(auto& E : Etudiants){
        if(E.getMat() == m){
                E.AfficherEtudiant();
                etudianttrouver = true;
        }
        }
        if(!etudianttrouver){
        cout << "Etudiant n'existe pas" << endl;
        }
}


Etudiant* GestionEtudiant::rechercherEtudiantParNom(string matricule) {
        for (auto& etudiant : Etudiants) {
                if (etudiant.getMat() == matricule) {
                        return &etudiant; 
                }
        }
        return nullptr;
}

//##########################################################################################################################################

//############################################### Class Personnel ##############################################
Personnel::Personnel(string mate,string nom,string prenom,string dep):MatE(mate),Nom(nom),Prenom(prenom),Dep(dep){}

        string Personnel::getMatE(){
                return MatE;
                }
        string Personnel::getNom(){
                return Nom;
                }    
        string Personnel :: getPrenom(){
                return Prenom;
                } 
        string Personnel::getDep(){
                return Dep;
                }
        void Personnel::setDep(string d){
                Dep = d;
        }

                          //---| Methode Affiche | -----------------------------------------


void Personnel::AfficherPersonnel() {
        cout << "| - Matricule  : "<< MatE<<endl;
        cout << "| - Nom        : "<< Nom<<endl;
        cout << "| - Prenom     : "<< Prenom<<endl;
        cout << "| - Dep        : "<< Dep<<endl;
        


}
//##########################################################################################################################################

//############################################### Class Enseignant ##############################################
Enseignant::Enseignant(string mate,string nom,string prenom,string dep,string mat):Matiere(mat),Personnel(mate,nom,prenom,dep){}


                            //---| Methode Getters | -----------------------------------------
string Enseignant::getMatiere(){
return Matiere;
}
void  Enseignant::setMatiere(string m){
        Matiere = m;
}

                            //---| Methode Affiche | -----------------------------------------

void Enseignant::AfficherEnseignant() {
        cout << "|-------------------------------|" << endl;
        cout << "|           Enseignant          |" << endl;
        cout << "|-------------------------------|" << endl;
        Personnel::AfficherPersonnel();
        cout << "| - Matiere    : "<<Matiere<<endl;
        cout << "|-------------------------------|" << endl;
}

//##########################################################################################################################################

//############################################### Class Administratif ##############################################

Administratif::Administratif(string mate, string nom, string prenom,  string dep, string poste):Poste(poste),Personnel(mate,nom,prenom,dep){}

                            //---| Methode Getters | -----------------------------------------


string Administratif::getPoste(){
return Poste;

}

void Administratif::setPoste(string p){
        Poste = p;
}

                            //---| Methode Affiche | -----------------------------------------

void Administratif::AfficherAdministratif() {
        cout << "|-------------------------------|" << endl;
        cout << "|          Administratif        |" << endl;
        cout << "|-------------------------------|" << endl;
        Personnel::AfficherPersonnel(); 
        cout << "| - Poste : "<< Poste <<endl;
        cout << "|-------------------------------|" << endl;


}
//########################################## Class  Gestion Personnel ##############################################
GestionPersonnel::GestionPersonnel(){};



vector<Enseignant>& GestionPersonnel::getListEnsignant(){return ListEnsignant;}


void GestionPersonnel::CreationEnseignant(Enseignant& E){
        ListEnsignant.push_back(E);

}
void GestionPersonnel::CreationAdministratif(Administratif& a){
        ListAdministratif.push_back(a);
}
void GestionPersonnel::SupprimerEnseignant(string m){
        bool EnsExiste = false;
        for(auto E = ListEnsignant.begin() ; E != ListEnsignant.end(); ++E){
        if(E->getMatE() == m){
        EnsExiste = true;
        ListEnsignant.erase(E);
        break;
        }
        }
        if(!EnsExiste){
        cout << "L'enseignant n'existe pas" << endl;
}
}
void GestionPersonnel::SupprimerAdministratif(string m){
        bool AdmExiste = false;
        for(auto A = ListAdministratif.begin() ; A != ListAdministratif.end(); ++A){
        if(A->getMatE() == m){
        AdmExiste = true;
        ListAdministratif.erase(A);
        break;
        }
}
        if(!AdmExiste){
        cout << "L'enseignant n'existe pas" << endl;
}
}

void GestionPersonnel::AfficherTousLesEnseignant(){
for(auto enseignant : ListEnsignant){
        enseignant.AfficherEnseignant();
}
}
void GestionPersonnel::AfficherTousLesAdmin(){
for(auto administratif : ListAdministratif){
        administratif.AfficherAdministratif();
}
}
void GestionPersonnel::RechercheEnseignant(string mate){
        bool existe = false;
        for(auto& E : ListEnsignant){
        if(E.getMatE() == mate){
                E.AfficherEnseignant();
                existe = true;
        }
        }
        if(!existe){
                cout << "Enseignant n'existe pas" << endl;
        }
}  


void GestionPersonnel::RechercheAdministratif(string mate){
        bool existe = false;

        for(auto& A : ListAdministratif){
        if(A.getMatE() == mate){
                A.AfficherAdministratif();
                existe = true;
        }
        }
        if(!existe){
        cout << "Administratif n'existe pas" << endl;
        }
}  

void GestionPersonnel::ModifierEnseigant(){
        string matricule;
        cout << "Entrer le Matricule ";
        cin >> matricule;
        bool existe = false;
        for(auto e = ListEnsignant.begin(); e != ListEnsignant.end(); ++e){
                if(e->getMatE() == matricule){
                        existe = true;
                        string d,m;
                        cout << "Entrer Le Nouveau Departement : ";
                        cin >> d;
                        cout << "Entrer la Nouvelle Matiere :  ";
                        cin >> m;
                        e->setDep(d);
                        e->setMatiere(m);
                        
                }
        }if(!existe){
                cout << "Enseigant Introuvable " << endl;
        }
}
void GestionPersonnel::ModifierAdmin(){
        string mat;
        cout << "Entrer le Matricule ";
        cin >> mat;
        bool existe = false;
        for(auto e = ListAdministratif.begin(); e != ListAdministratif.end(); ++e){
                if(e->getMatE() == mat){
                        existe = true;
                        string d,p;
                        cout << "Entrer Le Nouveau Departement : ";
                        cin >> d;
                        cout << "Entrer Le Nouveau Poste :  ";
                        cin >> p;
                        e->setDep(d);
                        e->setPoste(p);
                }
        }if(!existe){
                cout << "Administratif Introuvable " << endl;
        }
}



//##########################################################################################################################################

//########################################## Class Cours ##############################################
Cours::Cours(int i, string nom, string f, string n) : 
IdCours(i), NomCours(nom), FiliereCours(f), NiveauCours(n) {}


void Cours::AfficherCours(){
        cout << "|-------------------------------|" << endl;
        cout << "|             COURS             |" << endl;
        cout << "|-------------------------------|" << endl;
        cout << "| - Id cours : "<< IdCours <<endl;
        cout << "| - Nom du Cours : " << NomCours << endl;
        cout << "| - Fillier : " << FiliereCours << endl;
        cout << "| - Niveau D'etude : " << NiveauCours << endl;
}

int Cours::getIdCours()   {return IdCours; }
string Cours::getNomCours()   {return NomCours;}
string Cours::getFilierCours(){return FiliereCours;}
string Cours::getNiveauCours(){return NiveauCours;}
void Cours::setNiveauCours(string n){NiveauCours = n;}


        string Cours::getHeure(){return heure;}
        string Cours::getJour(){return jour;}
        void Cours::setHeure(string h){
                heure = h;
        }
        void Cours::setJour(string j){
                jour = j;
        }

//Enseignant& Cours::getEnseignantCours(){return EnseignantCours;}
//##########################################################################################################################################



//##########################################################################################################################################





//#######################################################   Class Gestion cours ####################################################################################

void Gestion_Cours::CreationCours(Cours& c){
        ListeDesCours.push_back(c);
}
Enseignant* Gestion_Cours::getEnseignantCours(){
        return EnseignantCours;
}
vector<Cours>& Gestion_Cours::getListeDesCours(){
        return ListeDesCours;
}


void Gestion_Cours::SupprimerCours(int i){
        bool existe = false;
        for(auto c = ListeDesCours.begin(); c != ListeDesCours.end(); ++c){
                if(c->getIdCours() == i){
                        ListeDesCours.erase(c);
                        existe = true;
                        break;
                }
        }
        if(!existe){
                cout << "-> Cours Introuvable <-" << endl;
        
        }
}

Cours* Gestion_Cours::rechercherCoursParNom(string nom) {
        for (auto& cours : ListeDesCours) {
        if (cours.getNomCours() == nom) {
                return &cours;
        }
        }
        return nullptr;
}


void Gestion_Cours::ConsulterCours(string d,string n){
        bool cours = false;
        for(auto c : ListeDesCours){
                if(c.getFilierCours() == d && c.getNiveauCours() == n){
                        cout << "---------------------------------------------" << endl;
                        c.AfficherCours();
                        cout << "-> Enseignant : " << EnseignantCours->getNom() << endl; 
                        cout << "---------------------------------------------" << endl;
                        cours = true;
                }
        }
        if(!cours){
                cout << "-> Cours Introuvable <-" << endl;
        }
}


void Gestion_Cours::attribuerenseignant(int id,Enseignant* ens){
        for(auto c : ListeDesCours){
                if(c.getIdCours() == id){
                        EnseignantCours = ens;
                        //cout << "Enseignant attribué au cours avec succès." << endl;
                }
        } 
}

void Gestion_Cours::ModifierCours(string cours){
        bool existe = false;
        for(auto& c : ListeDesCours){
                if(c.getNomCours() == cours){
                        existe = true; 
                        string niv;
                        cout << "Entrer Le Nouveau niveau de ce Cours : ";
                        cin >> niv;
                        c.setNiveauCours(niv);
                }
        }if(!existe){
                cout << "-> Cours Introuvable <-" << endl;
        }
}

void Gestion_Cours::affichertouslescours(){
        cout << "----------------------------------------------------------------" << endl;
        for(auto& c : ListeDesCours){
                cout << "       Nom Du cours : " << c.getNomCours() << endl;
                cout << "       Niveau Du cours : " << c.getNiveauCours() << endl;
                cout << "----------------------------------------------------------------" << endl;
        }
}



//  |-> | for pointeur
//##################################################################################################################

//****************************************************************************************************************
//************************************| Class Note |*****************************************************
Note::Note(Etudiant& etudiant,Cours& nomcours,double N):Nometudiant(etudiant),Nomcours(nomcours),note(N){}


Etudiant& Note::getNometudiant(){return Nometudiant;}
Cours& Note::getNomcours(){return Nomcours;}
double Note::getNote(){return note;}
void Note::setNote(double n){
        note = n;
}
void Note::afficheNote(){
        cout << "----------------------------------------------------------------" << endl;
        cout << "       Nom d'etudiant : " << Nometudiant.getNom() << endl;
        cout << "       Nom Du cours : " << Nomcours.getNomCours() << endl;
        cout << "       Note : " << note << endl;
        cout << "----------------------------------------------------------------" << endl;
}


//****************************************************************************************************************
//************************************| Class Gestion Note |*****************************************************

Gestion_Notes::Gestion_Notes(){};
void Gestion_Notes::CreationNote(Note& n) {
        ListNote.push_back(n);
}

void Gestion_Notes::ModifierNote(double NouvelleNote){
        for(auto& n : ListNote){
                        n.setNote(NouvelleNote);
                }
        }


void Gestion_Notes::ConsulterlesNote(){
        for(auto& n : ListNote){
                n.afficheNote();
        }
}
//****************************************************************************************************************
//************************************| Class Absence|*****************************************************
Absence::Absence(Etudiant* e, Cours* c, string d,string h) : etudiant(e), cours(c), Date(d), Heure(h) {
        motif = "Non Justifier";
}
// Absence::~Absence() {
//         delete etudiant;
//         delete cours;
// }
Etudiant* Absence::getEtudiant()  { return etudiant; }
Cours* Absence::getCours()  { return cours; }
string Absence::getDate()  { return Date; }
string Absence::getMotif(){return motif;}
void Absence::setMotif(string m){motif = m;}
string Absence::getHeure(){
        return Heure;
}
void Absence::afficherAbsence() {
        cout << "---------------------- Abscence ----------------------" << endl;
        cout << "- Nom de l'étudiant " << etudiant->getNom() ;
        cout << "- Cours " << cours->getNomCours() ;
        cout << "- Date " << Date << endl;
        cout << "- Heure : " << Heure << endl;
        cout << "- Motif : " << motif << endl;
        cout << "-------------------------------------------------------" << endl;
}


//****************************************************************************************************************



//************************************| Class gestion Absence|*****************************************************
GestionAbsence::GestionAbsence(){};
void GestionAbsence::creerAbsence(Etudiant* etudiant, Cours* cours,string date,string heure) {
        Listabsences.push_back(Absence(etudiant, cours, date,heure));
}

void GestionAbsence::Abscenceetudiant(){
        for(auto& c : Listabsences){
                c.afficherAbsence();
        }
}

void GestionAbsence::modifierStatutAbsenceParMatricule(string matricule, string newStatus,string date) {
        for (auto& absence : Listabsences) {
                if (absence.getEtudiant()->getMat() == matricule && absence.getDate() == date) {
                        if(newStatus == "Oui"){
                                absence.setMotif("Justifie");
                        }else if(newStatus == "Non") {
                                absence.setMotif("Non justifie");
                        }else{
                                cout << "Le statut de l'absence n'est pas valide." << endl;
                        }
                        return;
                }
        }
        cout << "Aucune absence correspondante au matricule n'a été trouvée." << endl;
}
//****************************************************************************************************************

//************************************| Class EMPLOI DU TEMPS|*****************************************************

EmploiDuTemps:: EmploiDuTemps(Gestion_Cours& c,GestionPersonnel& ens): cours(c),enseignant(ens){
        jour = "";
        horaire = "";
};
string EmploiDuTemps::getJour(){return jour;}
string EmploiDuTemps::getHoraire(){return horaire;}
void   EmploiDuTemps::setJour(string nouveauJour){ jour = nouveauJour; }
void   EmploiDuTemps::setHoraire(string nouvelHoraire){horaire = nouvelHoraire;}
void   EmploiDuTemps::afficherEmploiDuTemps(){
        cout << "|-------------------------------------------------------------------------------------------|" << endl;
        cout << "|                                   EMPLOI DU TEMPS                                         |" << endl;
        cout << "|-------------------------------------------------------------------------------------------|" << endl;
        cout << "|     COURS                    |          JOUR              |            HEURE              |" << endl;
        for(auto c : cours.getListeDesCours()){
        cout << "|-------------------------------------------------------------------------------------------|" << endl;
        // Utilisation de setw() pour fixer la largeur de chaque colonne
        cout << "| " << setw(28) << left << c.getNomCours() << " | " << setw(27) << left << c.getJour() << " | " << setw(30) << left << c.getHeure() << " |" << endl;
        }
        cout << "|-------------------------------------------------------------------------------------------|" << endl;
}




void EmploiDuTemps::remplirEmploi(){
        string mat;
        cout << "Entrer Votre matricule : ";
        cin >> mat;

        for(auto& e : enseignant.getListEnsignant()){
                if(e.getMatE() == mat){
                        for(auto& c : cours.getListeDesCours()){
                                if(e.getMatiere() == c.getNomCours()){
                                        cout << "| - " << c.getNomCours() << endl;
                                        cout << "Entrer le jour : ";
                                        string jour,h;
                                        cin >> jour;    
                                        cout << "Entrer l'horaire : ";
                                        cin >> h;
                                        c.setJour(jour);
                                        c.setHeure(h);
                                }
                        }
                }
        }
}

void EmploiDuTemps::modifierEmploi() {
        string nomCours;
        cout << "Entrer le Nom du cours à modifier : ";
        cin >> nomCours;
        bool emploiModifie = false; // Pour suivre si l'emploi du temps a été modifié
        for (auto& c :cours.getListeDesCours()) {
                if (c.getNomCours() == nomCours) {
                        string nouveauJour, nouvelHoraire;
                        cout << "| - " << nomCours << endl;
                        cout << "| - Entrer le nouveau jour : ";
                        cin >> nouveauJour;
                        cout << "| - Entrer le nouvel horaire : ";
                        cin >> nouvelHoraire;
                        c.setJour(nouveauJour); // Mettre à jour le jour du cours
                        c.setHeure(nouvelHoraire); // Mettre à jour l'horaire du cours
                        cout << "Emploi du temps modifié pour le cours " << nomCours << endl;
                        cout << "Nouveau jour : " << c.getJour() << endl;
                        cout << "Nouvel horaire : " << c.getHeure() << endl;
                        emploiModifie = true;
                        break;
                }
        }
        if (!emploiModifie) {
                cout << "Aucun cours trouvé avec le nom spécifié." << endl;
        }
}
//****************************************************************************************************************




void MENU_PRINCIPALE() {
        cout << endl;
        cout << endl;
        cout << "|=======================================================================|" << endl;
        cout << "|             Bienvenue dans le système de gestion scolaire             |" << endl;
        cout << "|                 de l'École Marocaine des Sciences de                  |" << endl;
        cout << "|                         l'Ingénieur (EMSI)                            |" << endl;
        cout << "|=======================================================================|" << endl;
        cout << "|                            MENU PRINCIPAL                             |" << endl;
        cout << "|=======================================================================|" << endl;
        cout << "| |1| - Gestion des étudiants                                           |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |2| - Gestion des enseignants                                         |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |3| - Gestion du personnel administratif                              |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |4| - Gestion des cours                                               |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |5| - Gestion des notes et absences                                   |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |6| - Inscription au cours                                            |" << endl;
        cout << "|                                                                       |" << endl;
        cout << "| |7| - Quitter                                                         |" << endl;
        cout << "|=======================================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MENU_GESTION_ETUDIANT(){
        cout << endl;
        cout << endl;
        cout << "|=================================================================|" << endl;
        cout << "|                      MENU GESTION DES ETUDIANTS                 |" << endl;
        cout << "|=================================================================|" << endl;
        cout << "| |1| - Ajouter un nouvel étudiant                                |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |2| - Modifier les informations d'un étudiant existant          |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |3| - Supprimer un étudiant                                     |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |4| - Rechercher un étudiant                                    |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |5| - Afficher tous les étudiants                               |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |6| - Retour au menu principal                                  |" << endl;
        cout << "|=================================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MENU_GESTION_DES_ENSEIGNANTS(){
        cout << endl;
        cout << endl;
        cout << "|=================================================================|" << endl;
        cout << "|                  MENU GESTION DES ENSEIGNANTS                   |" << endl;
        cout << "|=================================================================|" << endl;
        cout << "| |1| - Ajouter un nouvel enseignant                              |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |2| - Modifier les informations d'un enseignant existant        |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |3| - Supprimer un enseignant                                   |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |4| - Rechercher un enseignant                                  |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |5| - Afficher tous les enseignant                              |" << endl;
        cout << "|                                                                 |" << endl;
        cout << "| |6| - Retour au menu principal                                  |" << endl;
        cout << "|=================================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;       
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MENU_GESTION_DU_PERSONNEL_ADMINISTRATIF(){
        cout << endl;
        cout << endl;
        cout << "|==================================================================================|" << endl;
        cout << "|               MENU GESTION DU PERSONNEL ADMINISTRATIF                            |" << endl;
        cout << "|==================================================================================|" << endl;
        cout << "| |1| - Ajouter un nouveau membre du personnel administratif                       |" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "| |2| - Modifier les informations d'un membre du personnel administratif existant  |" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "| |3| - Supprimer un membre du personnel administratif                             |" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "| |4| - Rechercher un membre du personnel administratif                            |" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "| |5| - Afficher tous les membres du personnel administratif                       |" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "| |6| - Retour au menu principal                                                   |" << endl;
        cout << "|==================================================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MENU_GESTION_DES_COURS(){
        cout << endl;
        cout << endl;
        cout << "|======================================================|" << endl;
        cout << "|               MENU GESTION GESTION DES COURS         |" << endl;
        cout << "|======================================================|" << endl;
        cout << "| |1| - Ajouter un nouveau cours                       |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |2| - Modifier les informations d'un cours existant  |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |3| - Supprimer un cours                             |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |4| - Rechercher un cours                            |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |5| - Consulter Un Cours                             |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |6| - Retour au menu principal                       |" << endl;
        cout << "|======================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;
        }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MENU_GESTION_DES_NOTES(){
        cout << endl;
        cout << endl;
        cout << "|======================================================|" << endl;
        cout << "|            MENU Gestion des notes et absences        |" << endl;
        cout << "|======================================================|" << endl;
        cout << "| |1| - Consulter Les Notes                            |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |2| - Modifier une Note                              |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |3| - Ajouter une absence                            |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |4| - Afficher Les AbsenseS                          |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |5| - Motif d'absence                                |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |6| - Retour au menu principal                       |" << endl;
        cout << "|======================================================|" << endl;
        cout << "|-> | Entrer Votre Choix | : " ;

}



void INSCRIPTION(){
        cout << endl;
        cout << endl;
        cout << "|======================================================|" << endl;
        cout << "|            INSCRIPTION / EMPLOI DU TEMPS             |" << endl;
        cout << "|======================================================|" << endl;
        cout << "| |1| - Inscription Au Cours [->  ETUDIANT  <-]        |" << endl;
        cout << "|                                                      |" << endl;
        cout << "| |2|- Valider L'inscription [-> ENSEIGNANT <-]        |"<< endl;
        cout << "|                                                      |" << endl;                        
        cout << "| |3|- Emploi du Temps                                 |"<< endl;
        cout << "|                                                      |" << endl;
        cout << "| |4|- Plannifier L'emploi                             |"<< endl;
        cout << "|                                                      |" << endl;
        cout << "| |5|- Modifier Emploi                                 |"<< endl;
        cout << "|                                                      |" << endl;
        cout << "| |6|- Retour au menu principal.                       |"<< endl;;
        cout << "|                                                      |" << endl;
        cout << "|======================================================|" << endl;
        cout << "Entrer votre choix : ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




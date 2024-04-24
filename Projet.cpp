#include <iostream>
#include "projet.hpp"
#include <vector>
#include <string>

using namespace std;

//############################################### Class Etudiant ##############################################

//---| Constructeur Parametrer | ---------------------------------
etudiant::etudiant(string na, string pre, string mat, string fill) 
: name(na), prenom(pre), matricule(mat), filliere(fill) {};


//---| Methode Affiche | -----------------------------------------
void etudiant::affichEtudiant() const {
    cout << "*********** | Etudiant | ***********" << endl;
    cout << "* Name : " << name << endl;
    cout << "* Prenom : " << prenom << endl;
    cout << "* Matricule  : " << matricule << endl;
    cout << "* Filliere : " << filliere << endl;
    cout << "************************************" << endl;
}


//---| Methode Getters | -----------------------------------------
string etudiant::getMatricule()const  {  return matricule;   }
string etudiant::getName()const { return name; }
string etudiant::getFilliere() const {return filliere;}
string etudiant::getPrenom() const { return prenom; }
    
//---| Modification d'etudiant | -----------------------------------------

void etudiant::modifierEtudiant(string na, string pre, string mat, string fill) {
    name = na;
    prenom = pre;
    matricule = mat;
    filliere = fill;
}
//##########################################################################################################################################






//########################################## Class Gestion Etudiant ##############################################

void Gestion_etudiant::ajouterEtudiant(const etudiant& e) {
    listeEtudiants.push_back(e);
}

void Gestion_etudiant::supprimerEtudiant(const string& matricule,const string& name) {
    for (auto i = listeEtudiants.begin(); i != listeEtudiants.end(); i++) {
        if (i->getMatricule() == matricule && i->getName() == name) {
            listeEtudiants.erase(i);
            cout << "Étudiant -> | " << name <<" | Dont le Matricule -> | " <<matricule << " | est supprimé avec succès !" << endl;                
            return;
        }
    }
     cout << "avec le matricule " << matricule << " non trouvé." << endl;
}

void Gestion_etudiant::afficherTousLesEtudiants() const {
    for (const auto& etudiant : listeEtudiants) {
        etudiant.affichEtudiant();
     }
}


void Gestion_etudiant::rechercherEtudiantParNom(const string& name,const string& filliere ,const string& matricule) {
    bool exist = false;
    for (const auto& etudiant : listeEtudiants) {
        if ((etudiant.getName() == name && etudiant.getFilliere() == filliere) || (etudiant.getMatricule() == matricule)){
                //etudiant.affichEtudiant();
                cout << "[ Resultat de Recharche D'etudiant ]" << endl;
                cout << "Nom : " << etudiant.getName() << " | " << "Prenom : " << etudiant.getPrenom()  << " | Matricule : " << etudiant.getMatricule() << " | " << "Fillierre : " << etudiant.getFilliere() << endl;
               
                exist = true;
        }
    }
        if (!exist) {
            cout << "!!!!! [ Etudiant Inexitant ] !!!!!"<< endl;
            cout << "-------------------------------------" << endl;
            cout << "* Etudiant : " << name << endl;
            cout << "* Matricule : " << matricule  << endl;
            cout << "* Filliere : " << filliere <<  endl;
            cout << "-------------------------------------" << endl;
        }
}
//##########################################################################################################################################







//############################################### Class Personnel ##############################################

Personnel::Personnel(string n, int num, string dep) 
: nom(n), numero(num), departement(dep) {}

void Personnel::afficherDetailPerso() const {
    cout << "**** | Personnel Universitaire | ****" << endl;
    cout << "* Nom : " << nom << endl;
    cout << "* Numéro : " << numero << endl;
    cout << "* Département : " << departement << endl;
    cout << "*****************" << endl;
}

string Personnel::getNom() const { return nom; }
              
int Personnel::getNumero() const { return numero; }
                    
string Personnel::getDepartement() const {  return departement;}
              
void Personnel::modifierPerso(string n, int num, string dep) {
    nom = n;
    numero = num;
    departement = dep;
}
//##########################################################################################################################################





//############################################### Class Enseignant ##############################################

Enseignant::Enseignant(string n, int num, string dep, string spec) 
: Personnel(n, num, dep), specialite(spec) {}

void Enseignant::afficher() const {
    Personnel::afficherDetailPerso();
    cout << "* Spécialité : " << specialite << endl;
    cout << "*****************" << endl;
}

string Enseignant::getSpecialite() const { 
    return specialite;
}

void Enseignant::modifierEns(string n, int num, string dep, string spec) {
    Personnel::modifierPerso(n, num, dep);
    specialite = spec;
}

//##########################################################################################################################################






//############################################### Class Administratif ##############################################

Administratif::Administratif(string n, int num, string dep, string post) : Personnel(n, num, dep), poste(post) {}

void Administratif::afficherAdmin() const {
    Personnel::afficherDetailPerso();
    cout << "* Poste : " << poste << endl;
    cout << "*****************" << endl;
}

string Administratif::getPoste() const { 
    return poste;         
}

void Administratif::modifierAdmin(string n, int num, string dep, string post) {
    Personnel::modifierPerso(n, num, dep);
    poste = post;
}
//##########################################################################################################################################





//########################################## Class Gestion Personnel ##############################################

void Gestion_personnel::ajouterPersonnel(const Personnel& p) {
    listePersonnel.push_back(p);
}

void Gestion_personnel::afficherTousLesPersonnel() const {
    for (const auto& personnel : listePersonnel) {
        personnel.afficherDetailPerso();
   }
}

void Gestion_personnel::ajouterEnseigant(const Enseignant& e){
    listePersonnel.push_back(e);
}


void Gestion_personnel::ajouterAdministratif(const Administratif& a){
     listePersonnel.push_back(a);
}
 //##########################################################################################################################################







//########################################## Class Cours ##############################################

cours::cours(string n, int code, string dep,string niveau, Enseignant* enseignant) {
    nom_cours = n;
    code_cours = code;
    departement = dep;
    niveau_etude = niveau;
    Enseignant_associe = enseignant;
}
string cours::getNom_cours(){return nom_cours;}
int cours::getCode_cours(){return code_cours;}
void cours::setNom_cours(string s){nom_cours = s;}
string cours::getDepartement(){ return departement;}
void cours::setDepartement(string d){departement = d;}
string cours::getNiveau_etude(){return niveau_etude;}
void cours::setNiveau_etude(string niv){niveau_etude = niv;}
void cours::affichecours() const{
    cout << "************* Cours Universitaite *************" << endl;
    cout << "Nom du cours: " << nom_cours << endl;
    cout << "Code du cours: " << code_cours << endl;
    cout << "Département: " << departement << endl;
    cout << "Niveau D'etude : " << niveau_etude << endl;
    if (Enseignant_associe != nullptr) {
        cout << "Enseignant associé: " << Enseignant_associe->getNom() << endl;
    } else {
        cout << "Aucun enseignant associé." << endl;
    }
}

//##########################################################################################################################################





//########################################## Class Gestion cours ##############################################
void gestion_cours::ajouter_cours(const cours& c){
    liste_cours.push_back(c);
}
void gestion_cours::supprimerCours(const int code_cours) {
    for (auto i = liste_cours.begin(); i != liste_cours.end(); i++) {
        if (i->getCode_cours() == code_cours) {
            liste_cours.erase(i);
            cout << "Cours Dont le code  -> | " <<code_cours << " | est supprimé avec succès !" << endl;                
            return;
        }
    }
     cout << " le code " << code_cours << " non trouvé." << endl;
}

void gestion_cours::afficherTousCours() const {
    for (const auto& cours : liste_cours) {
        cours.affichecours();
     }
}


void gestion_cours::modifierCours(const int code_cours, const string& nouveau_nom,const string& nouveau_departement,const string& niv_etude) {
    for (auto& cours : liste_cours) {
        if (cours.getCode_cours() == code_cours) {
            cours.setNom_cours(nouveau_nom);
            cours.setDepartement(nouveau_departement);
            cours.setNiveau_etude(niv_etude);
            break;
        }
    }
}

void gestion_cours::consulter_cours(const string& departement, const string& niveau) {
    bool exist = false;
    for ( auto& cours : liste_cours) {
        if (cours.getDepartement() == departement || cours.getNiveau_etude() == niveau) {
            cout << "[ Résultat de la Recherche du Cours ]" << endl;
            cours.affichecours(); 
            exist = true;
        }
    }
    if (!exist) {
        cout << "!!!!! [ Cours Inexistant ] !!!!!" << endl;
    }
}
//##########################################################################################################################################

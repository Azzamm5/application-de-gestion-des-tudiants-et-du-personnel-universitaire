#include<iostream>
#include <vector>

#include "projet.hpp"

using namespace std;

int main() {
    GestionEtudiant G1;
    GestionPersonnel G2;
    Gestion_Cours G3;
    Gestion_Notes G4;
    GestionAbsence G5;
    Etudiant E1("1","Mohamed","azzam","3IIR", "Informatique", "EMSI HASSAN");
    Etudiant E2("2","Riyad", "maj","2IIR", "Informatique", "EMSI HASSAN");
    G1.CreationEtudiant(E1);
    G1.CreationEtudiant(E2);
    Enseignant Ens1("AECSWE","Siham","s","INFO","POO");
    Enseignant Ens2("Porf1","Hamza","a","TCPIP","Linux");
    Administratif Admin1("AGWSEHIS","Ayoub","s","Direction","chawch");
    G2.CreationEnseignant(Ens1);
    G2.CreationEnseignant(Ens2);
    G2.CreationAdministratif(Admin1);
    Cours C1(1,"POO","Informatique","3IIR");
    Cours C2(2,"Linux","Genie Civil","3IIR");
    Cours C3(3,"Mecanic","IFA","5IFA");
    Cours C4(4,"TCPIP","Reseau","2ap");
    Cours C5(5,"Compta","Gesion","3IIR");
    G3.CreationCours(C1);
    G3.CreationCours(C2);
    G3.CreationCours(C3);
    G3.CreationCours(C4);
    G3.CreationCours(C5);
    G3.attribuerenseignant(1,&Ens1);
    G3.attribuerenseignant(2,&Ens2);
    Note note1(E1,C2,16);
    G4.CreationNote(note1);
    EmploiDuTemps Emp1(G3,G2);
    
    int choix;
    do{
        MENU_PRINCIPALE();
        cin >> choix;
        switch(choix){
                case 1:{
                    int choixEtudiant;
                    do{
                        MENU_GESTION_ETUDIANT();
                        cin >> choixEtudiant;
                        switch(choixEtudiant){
                            case 1:{
                                string  mat ,nom, prenom, filiere, niveau, site;
                                cout << "Entrer le matricule de l'etudiant : ";
                                cin >> mat;
                                cout << "Entrer le nom de l'etudiant : ";
                                cin >> nom;
                                cout << "Entrer le prenom de l'etudiant : ";
                                cin >> prenom;
                                cout << "Entrer la filiere de l'etudiant : ";
                                cin >> filiere;
                                cout << "Entrer le niveau de l'etudiant : ";
                                cin >> niveau;
                                cout << "Entrer le site de l'etudiant : ";
                                cin >> site;
                                Etudiant nouvelEtudiant(mat,nom, prenom,niveau,filiere,site);
                                G1.CreationEtudiant(nouvelEtudiant);
                                break;
                            }case 2:{
                                G1.ModifierEtudiant();
                                break;
                            }case 3:{
                                string mat;
                                cout << "Entrer le matricule de l'etudiant a supprimer : ";
                                cin >> mat;
                                G1.SupprimerEtudiant(mat);
                                break;
                            }case 4:{
                                string mat;
                                cout << "Entrer le matricule de l'etudiant : ";
                                cin >> mat;
                                G1.RechercheEtudiant(mat);
                                break;
                            }case 5:{
                                G1.AfficherDetailsEtudiant();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    } while (choixEtudiant != 6); 
                    break;
                }case 2:{
                    int choixEnseignant;;
                    do {
                        MENU_GESTION_DES_ENSEIGNANTS();
                        cin >> choixEnseignant;
                        switch (choixEnseignant) {
                            case 1:{
                                string matri,n,p,d,matiere;
                                cout << "Entrer le Matricule : ";
                                cin >> matri;
                                cout << "Entrer le Nom D'enseignant : ";
                                cin >> n;
                                cout << "Entrer le Prenom D'enseignant : ";
                                cin >> p;
                                cout << "Entrer le Departement : ";
                                cin >> d;
                                cout << "Entrer la matiere : ";
                                cin >> matiere;
                                Enseignant Ens2(matri,n,p,d,matiere);
                                G2.CreationEnseignant(Ens2);
                                break;
                            }case 2:{
                                G2.ModifierEnseigant();
                                break;
                            }case 3:{
                                string mat;
                                cout << "Entrer le matricule de l'enseignant : ";
                                cin >> mat;
                                G2.SupprimerEnseignant(mat);
                                break;
                            }case 4:{
                                string mat;
                                cout << "Matricule d'enseignant a chercher : ";
                                cin >> mat;
                                G2.RechercheEnseignant(mat);
                                break;
                            }case 5:{
                                G2.AfficherTousLesEnseignant();
                                break;
                            }case 6:{
                                cout << "Retour au menu principal." << endl;
                                break;
                            }default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    }while (choixEnseignant != 6); 
                    break;
                }case 3:{
                    int choixAdmin;
                    do {
                        MENU_GESTION_DU_PERSONNEL_ADMINISTRATIF();
                        cin >> choixAdmin;
                        switch(choixAdmin) {
                            case 1:{
                                string matri,n,p,d,poste;
                                cout << "Entrer le Matricule : ";
                                cin >> matri;
                                cout << "Entrer le Nom D'Administratif : ";
                                cin >> n;
                                cout << "Entrer le Prenom D'Administratif : ";
                                cin >> p;
                                cout << "Entrer le Departement : ";
                                cin >> d;
                                cout << "Entrer le poste : ";
                                cin >> poste;
                                Administratif Admin2(matri,n,p,d,poste);
                                G2.CreationAdministratif(Admin2);
                                cout << "Nouveau membre du personnel administratif ajouté avec succès !" << endl;
                                break;
                            }case 2:{
                                G2.ModifierAdmin();
                                break;
                            } case 3:{
                                string mate;
                                cout <<"Entrer le matricule de l'administratif : " <<  endl;
                                cin >> mate;
                                G2.SupprimerAdministratif(mate);
                                break;
                            }
                                break;
                            case 4:{
                                string mat;
                                cout << "Matricule d'Administratif a chercher : ";
                                cin >> mat;
                                G2.RechercheAdministratif(mat);
                                break;
                            }case 5:{
                                G2.AfficherTousLesAdmin();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    }while (choixAdmin != 6);
                    break;
                }case 4:{
                    int choixCours;
                    do {
                        MENU_GESTION_DES_COURS();
                        cin >> choixCours;
                        switch(choixCours) {
                            case 1:{
                                int i;
                                string nom, f,n;
                                cout << "Entrer l'identifiant du cours : ";
                                cin >> i;
                                cout << "Entrer le nom du cours : ";
                                cin >> nom;
                                cout << "Entrer la Filliere du cours: ";
                                cin >> f;
                                cout << "Entrer le niveau d'etude du cours : ";
                                cin >> n;
                                Cours C6(i,nom,f,n);
                                G3.CreationCours(C6);
                                break;
                            }case 2:{
                                string cours;
                                cout << "Entrer le nom du cours a modifier : ";
                                cin >> cours;
                                G3.ModifierCours(cours);
                                break;
                            }case 3:{
                                int cours;
                                cout << "Entrer l' ID cours a supprimer : ";
                                cin >> cours;
                                G3.SupprimerCours(cours);
                                break;
                            }case 4:{
                                string dep,niv;
                                cout << "Entrer le Departement : ";
                                cin >> dep;
                                cout << "Entrer Le Niveau D'etude : ";
                                cin >> niv;
                                G3.ConsulterCours(dep,niv);
                                break;
                            }case 5:{
                                G3.affichertouslescours();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    }while (choixCours != 6);
                        break;
                }case 5:{
                    int choixnote;
                    do{
                        MENU_GESTION_DES_NOTES();
                        cin >> choixnote;
                        switch (choixnote){
                            case 1:{
                                G4.ConsulterlesNote();
                                break;
                            }case 2:{
                                string matricule;
                                cout << "Entrer le matricule de l'etudiant : " << endl;
                                cin >> matricule;
                                bool existeetudiant = false;
                                for (auto e : G1.getEtudiants()){
                                    if (e.getMat() == matricule) {
                                        existeetudiant = true;
                                        string cours;
                                        cout << "Entrer le Nom du cours : ";
                                        cin >> cours;
                                        bool co = false;
                                        for (auto c : G3.getListeDesCours()) {
                                            if (c.getNomCours() == cours) {
                                                co = true;
                                                double note;
                                                cout << "Entrer la Nouvelle note : ";
                                                cin >> note;
                                                G4.ModifierNote(note);
                                                break;
                                            }
                                        }
                                        if (!co) {
                                            cout << "Cours n'existe pas" << endl;
                                            break;
                                        }
                                    }
                                }
                                if (!existeetudiant) {
                                    cout << "Etudiant n'existe pas" << endl;
                                }
                                break;
                            }case 3:{
                                string m,c,d,h;
                                cout << "Entrer Le Matricule D'etudiant : ";
                                cin >> m;
                                cout << "Entrer Le Cours D'etudiant : ";
                                cin >> c;
                                cout << "Entrer La Date D'etudiant : ";
                                cin >> d;
                                cout << "Entrer l'heure : ";
                                cin >>h;
                                Etudiant* etudiant = G1.rechercherEtudiantParNom(m);
                                Cours* cours = G3.rechercherCoursParNom(c);
                                G5.creerAbsence(etudiant,cours,d,h);
                                break;
                            }case 4:{
                                G5.Abscenceetudiant();
                                break;
                            }case 5:{
                                string matricule;
                                cout << "Entrer le matricule de l'étudiant : ";
                                cin >> matricule;
                                cout << "Entrer La Date D'abscence : ";
                                string date;
                                cin >> date;
                                cout << "Motif (justifiée [Oui] ou non justifiée [Non]) : ";
                                string newStatus;
                                cin >> newStatus;
                                G5.modifierStatutAbsenceParMatricule(matricule,newStatus,date);
                                break;
                            }case 6 :
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    }while (choixnote != 6);
                    break;
                }case 6:{
                    int choixinsciption;
                    do{
                        INSCRIPTION();
                        cin >> choixinsciption;
                        switch (choixinsciption){
                            case 1 :{
                                cout << "------------------ INSCRIPTION AU COURS --------------" << endl;
                                cout << "Entrer Votre Matricule : ";
                                string matricule;
                                cin >> matricule;
                                bool existetudiant = false;
                                for (auto& e : G1.getEtudiants()) {
                                        if (e.getMat() == matricule) {
                                            existetudiant = true;
                                            bool coursexiste = false;
                                            cout << "|-------------- Inscription Au cours --------------|" << endl;
                                            for (auto& c : G3.getListeDesCours()) {
                                                if (e.getNiveau() == c.getNiveauCours()) {
                                                    coursexiste = true;
                                                    cout << "| - " << c.getNomCours() << endl;
                                                }   
                                            }
                                            if (!coursexiste) {
                                                cout << "Aucun cours trouvé pour le niveau de l'étudiant" << endl;
                                            } 
                                            cout << "Nom du cours à choisir : ";
                                            string nomCoursChoisi;
                                            cin >> nomCoursChoisi;
                                            e.setCoursinscrits(nomCoursChoisi);
                                                break;
                                        }
                                }
                                    if(!existetudiant) {
                                    cout << "Etudiant Inexistant" << endl;
                                    }
                                    break;
                            }case 2:{
                                for (auto& e : G1.getEtudiants()){
                                    e.afficheinscription();
                                }
                                string name,val;
                                cout << "------- | Consultation des Inscription au cours |-------" << endl;
                                cout << "| - Entrer le nom d'etudiant : ";
                                cin >> name;
                                cout << "| - [ Valider | Refuser ] ";
                                cin >> val;
                                for (auto& e : G1.getEtudiants()){
                                    if (e.getNom() == name){
                                        if (val == "V"){
                                            e.setStatus("Valider");
                                        }else if (val == "R"){
                                            e.setStatus("Refuser");
                                        }
                                    }
                                }
                                break;
                            }case 3:{
                                Emp1.afficherEmploiDuTemps();
                                break;
                            }case 4:{
                                Emp1.remplirEmploi();
                                break;
                            }case 5:{
                                Emp1.modifierEmploi();
                            }
                            case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                                break;
                        }
                    }while(choixinsciption != 6);
                    break;
                }case 7 :{
                    cout << "Au REVOIR " << endl;
                    break;
                }default:{
                    cout << "Option invalide. Veuillez entrer un numéro valide." << endl;
                    break;
                }
                }
        }while(choix != 7);
}
    

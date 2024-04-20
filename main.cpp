#include "projet.hpp"

int main(){

// declaration des deux objet -> |e1| |e2|
   etudiant e1("Nour","Ouzdou","NOUNOU","7anouta") ,e2("Amine","Ouzdou","Bassl","Darhom");

// Affichage des etudiants
    //e1.affichEtudiant();
    //cout << "_____________________________________________" << endl;
    //e2.affichEtudiant();

   Gestion_etudiant g1;
   g1.ajouterEtudiant(e1);  // ajout du Premier etudiant
   g1.ajouterEtudiant(e2);  // ajout du deuxieme etudiant
   g1.supprimerEtudiant("Bassl","Amine");
   //g1.afficherTousLesEtudiants();
   g1.rechercherEtudiantParNom("","","NOUNOU"); 
   //g1.afficherTousLesEtudiants();





   //Création d'objets Enseignant 
    Enseignant enseignant1("marwan", 123, "informatique", "Programmation");
    
    enseignant1.afficherDetailPerso();
    cout<<"cet Enseignant est modifier avec succes"<<endl;
    enseignant1.modifierEns("aya",111,"economie","finance");
    enseignant1.afficher();

//Création d'objets administratif
    Administratif administratif1("marwa", 210, "Gestion", "Secrétaire");
    
    administratif1.afficherAdmin();
    cout<<"cet Adminstratif est modifier avec succes"<<endl;
    administratif1.modifierAdmin("riyad",333,"direction","responsable general");
    administratif1.afficherAdmin();
    
    Gestion_personnel gestionPerso;
    // Ajout de quelques personnels
    gestionPerso.ajouterPersonnel(enseignant1);
    gestionPerso.afficherTousLesPersonnel();
    
    return 0;
}

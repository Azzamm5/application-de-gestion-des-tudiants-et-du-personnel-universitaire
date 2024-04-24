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
   cout << endl;
   g1.rechercherEtudiantParNom("","","NOUNOU"); 
   //g1.afficherTousLesEtudiants();
   cout << endl << endl;





   //Création d'objets Enseignant 
    Enseignant enseignant1("marwan", 123, "informatique", "Programmation");
    
    //enseignant1.afficherDetailPerso();
    cout << endl << endl;
    cout<<"cet Enseignant est modifier avec succes"<<endl;
    enseignant1.modifierEns("aya",111,"economie","finance");
    //enseignant1.afficher();
    cout << endl << endl;


//Création d'objets administratif
    Administratif administratif1("marwa", 210, "Gestion", "Secrétaire");
    
    //administratif1.afficherAdmin();
    cout << endl << endl;
    cout<<"Cet Adminstratif est modifier avec succes"<<endl;
    administratif1.modifierAdmin("riyad",333,"direction","responsable general");
    //administratif1.afficherAdmin();
    cout << endl << endl;
    
    Gestion_personnel gestionPerso;
    // Ajout de quelques personnels
    gestionPerso.ajouterPersonnel(enseignant1);
    //gestionPerso.afficherTousLesPersonnel();
    cout << endl << endl;

     



    cout << "******** Les tests Final *********" << endl;

    Enseignant E1("Mohamed",1980,"Info","Technicien");
    E1.afficher();
    cout << endl << endl;
    gestionPerso.ajouterAdministratif(administratif1);
    gestionPerso.ajouterEnseigant(E1);

   gestionPerso.afficherTousLesPersonnel();



   cours c1("C++ POO",123,"informatique",&E1);
   cours c2("anglais",1234,"algo",&E1);
   //c1.affichecours();
   gestion_cours gestion;
   gestion.ajouter_cours(c1);
   gestion.ajouter_cours(c2);
   //gestion.afficherTousCours();
   gestion.modifierCours(1234,"SQL SERVER","Maintenance");
   gestion.afficherTousCours();



    return 0;
}

#ifndef DEF_PROJET
#define DEF_PROJET

#include <iostream>
#include <vector>

using namespace std;

// ************************************| Class etudiant |*******************************************************
class etudiant{
protected:
    string name;
    string prenom;
    string matricule;
    string filliere;

public:
    etudiant(string na, string pre, string mat, string fill);
    void affichEtudiant() const;
    string getMatricule() const ;
    string getName() const ;
    string getPrenom() const;
    string getFilliere() const;
     void modifierEtudiant(string na, string pre, string mat, string fill);

};
//**********************************************|**********************************************|************





//************************************| Class Gestion Etudiant |*******************************************************
class Gestion_etudiant {
private:
    vector<etudiant> listeEtudiants;

public:
    void ajouterEtudiant(const etudiant& e);
    void supprimerEtudiant(const string& matricule,const string& name);
    void afficherTousLesEtudiants() const ;
    void rechercherEtudiantParNom(const string& name,const string& filliere ,const string& matricule);
};
//**********************************************|**********************************************|************






//************************************| Class Personnel |*******************************************************
class Personnel {
protected:
    string nom;
    int numero;
    string departement;

public:
    Personnel(string n, int num, string dep);
    void afficherDetailPerso() const;
    string getNom() const;
    int getNumero() const;
    string getDepartement() const;
    void modifierPerso(string n, int num, string dep);
};
//**********************************************|**********************************************|************







//************************************| Class Enseignant |*******************************************************
class Enseignant : public Personnel {
private:
    string specialite;

public:
    Enseignant(string n, int num, string dep, string spec);
    void afficher() const;
    string getSpecialite() const;
    void modifierEns(string n, int num, string dep, string spec);
};

//**********************************************|**********************************************|************







//************************************| Class Administratif |*******************************************************
class Administratif : public Personnel {
private:
    string poste;

public:
    Administratif(string n, int num, string dep, string post);
    void afficherAdmin() const;
    string getPoste() const;
    void modifierAdmin(string n, int num, string dep, string post);
};
//**********************************************|**********************************************|************






//************************************| Class Gestion Personnel |*******************************************************
class Gestion_personnel{
    private:
        vector<Personnel> listePersonnel;
    
    public:
        void ajouterPersonnel(const Personnel& p);
        void afficherTousLesPersonnel() const;
        void ajouterEnseigant(const Enseignant& e);
        void ajouterAdministratif(const Administratif& a);
};
//**********************************************|**********************************************|************





//************************************| Class Gours |*******************************************************

class cours {
    private:
        string nom_cours;
        int code_cours;
        string departement;
        Enseignant* Enseignant_associe;
    public:
        cours(string n, int code, string dep, Enseignant* enseignant);
        string getNom_cours();
        void setNom_cours(string s);
        void setDepartement(string d);
        int getCode_cours();
        string getDepartement();
        void affichecours() const;

};
//**********************************************|**********************************************|************



//************************************| Class Gestion Cours |*******************************************************

class gestion_cours{
    private:
        vector<cours>liste_cours;
    public:
        void ajouter_cours(const cours& c);
        void supprimerCours(const int code_cours);
        void afficherTousCours() const;
        void modifierCours(const int code_cours, const string& nouveau_nom,const string& nouveau_departement);

};
//**********************************************|**********************************************|************





#endif

#pragma once
#include "Vecteur2D.h"
#include "Montagne.h"
#include <vector>

class Potentiel{
private:
    Vecteur2D potentiel;
    Vecteur2D laplacien;
public:
    Vecteur2D get_potentiel() const;
    Vecteur2D get_laplacien() const;
    void set_potentiel(double,double);
    void set_laplacien(double,double);
};

class ChampPotentiels{
private:
    std::vector<std::vector<std::vector<Potentiel>>> collection3D;
    unsigned int Nx;
    unsigned int Ny;
    unsigned int Nz;
    double lambda;
    std::vector<double> X,Y,Z;
    static double epsilon;
public:
    //La taille du tableau a été initialisé et c'est constructeur par défaut et par valeur, et on appelle la fonction set_xyz() qui initialise X,Y,Z
    // les vecteur positions des données en X,Y et en Z;

    ChampPotentiels(int Nx=0,int Ny=0, int Nz=0, double lambda=0.0)
            :Nx(Nx),Ny(Ny),Nz(Nz),lambda(lambda),collection3D(Nx, std::vector<std::vector<Potentiel>>(Ny, std::vector<Potentiel>(Nz))){ set_xyz();}

    void initialise(double const& v_inf, Montagne const& everest);
    void calcule_laplaciens();
    void set_xyz();
    //affiche le vecteur potentiel;
    void affichage();
    //affiche le vecteur laplacien;
    void lapla_affichage();


    // méthode erreur() qui renvoie la somme des carrés des normes des vecteurs laplacien ;
    double erreur();
    //une méthode iteration() qui applique l'équation (6) du complément mathématique en tout point
    void iteration();
    //une méthode resolution() qui répète l'itération précédente tant que l'erreur est plus grande qu'un seuil donné et le nombre d'itérations plus petit qu'un maximum donné.
    void resolution(double seuil, unsigned int max_iterations, bool verbeuse);
    //une méthode vitesse() qui prend trois paramètres i, j et k et retourne un tableau de trois double qui sont les coordonnées de la vitesse du vent en (xi, yj, zk)
    std::vector<double> vitesse(unsigned int i, unsigned int j, unsigned int k);

    //la fonction qui calcule la norme d'un tableau (un vecteur 3D);
    double norme3D_2(std::vector<double> test);
    //La fonction qui affiche le tout (Tests point après P7.3);
    void affiche_total();

};
// je pense qu'il faut créer une super classe boite contenant lambda les Nx,Ny,Nz et on l'hérite sur champpotentiel
//et CubedAir pour récuperer ces valeurs
// Super Classe Boite
class Boite{
protected:
    unsigned int Nx, Ny, Nz;
    double lambda;
public:
    //constructeur non testé
    Boite( unsigned int Nx = 0.0, unsigned int Ny = 0.0, unsigned int Nz = 0.0, double lambda = 0.0)
    :Nx(Nx), Ny(Ny), Nz(Nz), lambda(lambda){}
};
    
class CubedAir: public Boite{
private:
    struct Cellule{ // petite structure pour rassembler ce que contient chaque cellule du ciel, aka chaque cube d'air
        double v_vent; //vitesse du vent
        double h;
        double T;
        double pression;
        double p_eau; // pression partielle de vapeur d'eau
        double tau; // taux d'humidité
        double p_rosee;
        bool nuage;// vrai = nuage, faux = pas nuage

    };
    std::vector<std::vector<std::vector<Cellule>>> Cube; // trois coordonnées donc tableau en trois dimensions

public:
    // constructeur:
    //CubedAir()
    //:Cube(Nx, std::vector<std::vector<Cellule>>(Ny, std::vector<Cellule>(Nz)))
    // calcul de la vitesse
    void v_vent();
    // calcul de l'enthalpie
    void h();
    // calcul de la température
    void T();
    // calcul de la pression
    void pression();
    // calcul de la pression partielle de vapeur d'eau
    void p_eau();
    // calcul de la pression vapeur saturante d'eau
    void p_rosee(double P_ref);

};

class Ciel : public Champ_potentiel{
private:
    // attributs spécifiques à la sous-classe
    std::vector<std::vector<std::vector<CubedAir>>> boite3D;
public:
    //Ciel(unsigned int Nx = 0.0, unsigned int Ny = 0.0, unsigned int Nz = 0.0, double lambda = 0.0)
    //: Champ_potentiel(Nx(Nx), Ny(Ny), Nz(Nz), lambda(lambda),collection3D(Nx, std::vector<std::vector<Potentiel>>(Ny, std::vector<Potentiel>(Nz))))

};


#pragma once
#include "ChampPotentiel.h"
#include <vector>


//------- Classe CubedAir ------------------
class CubedAir : Champ_potentiel{
private:
        double v_vent; //vitesse du vent
//        double h;
//        double T;
//        double pression;
//        double p_eau; // pression partielle de vapeur d'eau
        double tau; // taux d'humidité
//        double p_rosee;
//        bool nuage;// vrai = nuage, faux = pas nuage
//        , h(h), T(T), pression(p), p_eau(p_e), tau(to), p_rosee(p_r), nuage(n)


public:
    // constructeur:
    CubedAir( unsigned int Nx = 0.0, unsigned int Ny = 0.0, unsigned int Nz = 0.0, double lambda = 0.0, double v = 0, double to = 0)
    :Champ_potentiel(Nx,Ny,Nz,lambda), v_vent(v), tau(to) {}
    // calcul de l'enthalpie
    double h();
    // calcul de la température
    double T();
    // calcul de la pression
    double pression();
    // calcul de la pression partielle de vapeur d'eau
    double p_eau();
    // calcul de la pression vapeur saturante d'eau
    double p_rosee();
    // nuage ou non
    bool etat();

};
class Ciel : public Champ_potentiel{
private:
     // attributs spécifiques à la sous-classe
    std::vector<std::vector<std::vector<CubedAir>>> Cube;
public:
    //Ciel(unsigned int Nx = 0.0, unsigned int Ny = 0.0, unsigned int Nz = 0.0, double lambda = 0.0)
    //: Champ_potentiel(Nx(Nx), Ny(Ny), Nz(Nz), lambda(lambda),collection3D(Nx, std::vector<std::vector<Potentiel>>(Ny, std::vector<Potentiel>(Nz))))

};




#pragma once
#include "ChampPotentiel.h"
#include <vector>


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
    void p_rosee();
    // nuage ou non
    void etat();

};

class Ciel : public Champ_potentiel{
private:
    // attributs spécifiques à la sous-classe
    std::vector<std::vector<std::vector<CubedAir>>> boite3D;
public:
    //Ciel(unsigned int Nx = 0.0, unsigned int Ny = 0.0, unsigned int Nz = 0.0, double lambda = 0.0)
    //: Champ_potentiel(Nx(Nx), Ny(Ny), Nz(Nz), lambda(lambda),collection3D(Nx, std::vector<std::vector<Potentiel>>(Ny, std::vector<Potentiel>(Nz))))

};





#include "Ciel.h"
#include "cmath"


// ----------- P8: Ciel et Nuages ----------------

// calcul de la vitesse
void CubedAir:: v_vent(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].v_vent= ; // pas fini
            }
        }
    }
}
// calcul de l'enthalpie
void CubedAir:: h(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].h = bernouilli - g*z - 1/2 * Cube[i][j][k].v_vent * Cube[i][j][k].v_vent ; // c'est quoi z?
            }
        }
    }
}
// calcul de la température
void CubedAir::T(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].T = 2/7 * (M_airsec/R) * Cube[i][j][k].h ;
            }
        }
    }
}
// calcul de la pression
void CubedAir:: pression(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].pression = P_inf * pow(T_inf, -7/2) * pow(Cube[i][j][k].T, 7/2);
            }
        }
    }
}
// calcul de la pression partielle de vapeur d'eau
void CubedAir:: p_eau(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].p_eau = Cube[i][j][k].tau* Cube[i][j][k].pression / (M_eau/M_airsec+ Cube[i][j][k].tau) ;
            }
        }
    }
}
// calcul de la pression vapeur saturante d'eau
void CubedAir:: p_rosee(){
    for (int i(0); i < Nx; ++i) {
        for (int j(0); i < Ny; ++j) {
            for (int k(0); i < Nz; ++k) {
                Cube[i][j][k].p_rosee = P_ref * exp(13.96 - 5208/Cube[i][j][k].T) ;
            }
        }
    }
}

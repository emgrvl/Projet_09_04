
#include "Ciel.h"
#include "cmath"


// P8: Ciel et Nuages

// calcul de l'enthalpie
double CubedAir:: h(){
    double h;
    //return h = bernouilli - g* Z[k] - 1/2 * v_vent * v_vent ; // c'est quoi z? z_k?
}
// calcul de la température
double CubedAir::T(){
    double T;
    return T = 2/7 * (M_airsec/R) * h() ;
}
// calcul de la pression
double CubedAir:: pression(){
    double pression;
    return pression = P_inf * pow(T_inf, -7/2) * pow(T(), 7/2);
}
// calcul de la pression partielle de vapeur d'eau
double CubedAir:: p_eau(){
    double p_eau;
    return p_eau = tau* pression() / (M_eau/M_airsec+ tau) ;
}
// calcul de la pression vapeur saturante d'eau
double CubedAir:: p_rosee(){
    double p_rosee;
    return p_rosee = P_ref * exp(13.96 - 5208/T()) ;
}

bool CubedAir:: etat(){
    bool nuage;
    if (p_rosee() < p_eau()){
        nuage = true;
    }
    else {nuage = false;}
    return nuage;

}

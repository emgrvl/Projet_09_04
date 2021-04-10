#pragma once
#include "ChampPotentiel.h"
using  namespace Physique;


//Pour toutes les constantes physiques nécessaires (R, masses molaires, g,
// pression de référence (à ne pas confondre avec P∞, même si dans les documents elles sont égales)),

double const& v_inf = 20; // vent au loin, valeur arbitraire en m/s
double const& T_inf = 284.5; // en kelvin, température au sol au loin dans la plaine
double const& R = 8.3144621; //constante des gaz parfaits
double const& M_airsec = 0.02896;
double const& h_inf = 7/2 * (R/M_airsec) * T_inf; // enthalpie à l'infini
double const& bernouilli = 1/2*(v_inf*v_inf) + h_inf; // cte
double const& g = 9.81;// g constante de gravité
double const& P_inf(101325); //pression de l’air au sol au loin dans la plaine en Pa
double const& P_ref(P_inf); // pression de référence
double const& tau_inf(0.008); // taux d'humidité
double const& M_eau(0.0180153); // masse molaire de  l'eau en kg/mol

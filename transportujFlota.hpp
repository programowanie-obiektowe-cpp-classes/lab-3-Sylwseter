#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    // Sprawdzenie, czy wymagany towar do transportu to 0 - wtedy nie robimy nic.
    if (towar == 0) {
        return 0;
    }

    Stocznia     stocznia{}; // Tworzymy fabryk� statk�w
    unsigned int przetransportowanyTowar = 0;
    unsigned int liczbaZaglowcow         = 0;

    // Dop�ki nie przetransportowano wystarczaj�cej ilo�ci towaru, tw�rz nowe statki.
    while (przetransportowanyTowar < towar) {
        Statek* statek = stocznia(); // Tworzymy nowy statek

        // Transportujemy towar i dodajemy do sumy przetransportowanego towaru.
        przetransportowanyTowar += statek->transportuj();

        // Sprawdzamy, czy statek jest typu Zaglowiec za pomoc� dynamic_cast.
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            liczbaZaglowcow++; // Je�li statek to �aglowiec, zwi�kszamy licznik �aglowc�w.
        }

        delete statek; // Usuwamy statek, �eby nie by�o wyciek�w pami�ci.
    }

    return liczbaZaglowcow; // Zwracamy liczb� stworzonych �aglowc�w.
}

#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    // Sprawdzenie, czy wymagany towar do transportu to 0 - wtedy nie robimy nic.
    if (towar == 0) {
        return 0;
    }

    Stocznia     stocznia{}; // Tworzymy fabrykê statków
    unsigned int przetransportowanyTowar = 0;
    unsigned int liczbaZaglowcow         = 0;

    // Dopóki nie przetransportowano wystarczaj¹cej iloœci towaru, twórz nowe statki.
    while (przetransportowanyTowar < towar) {
        Statek* statek = stocznia(); // Tworzymy nowy statek

        // Transportujemy towar i dodajemy do sumy przetransportowanego towaru.
        przetransportowanyTowar += statek->transportuj();

        // Sprawdzamy, czy statek jest typu Zaglowiec za pomoc¹ dynamic_cast.
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            liczbaZaglowcow++; // Jeœli statek to ¿aglowiec, zwiêkszamy licznik ¿aglowców.
        }

        delete statek; // Usuwamy statek, ¿eby nie by³o wycieków pamiêci.
    }

    return liczbaZaglowcow; // Zwracamy liczbê stworzonych ¿aglowców.
}

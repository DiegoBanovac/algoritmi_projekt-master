#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktura podataka
typedef struct {
    char ime[50];
    char liga[50];
    char stadion[50];
    int kapacitet;
    int godina_osnivanja;
    int broj_naslova;
} Nogometni_klub;

typedef struct Celija {
    Nogometni_klub element;
    struct Celija* psljedeca;
} CelijaNogometniKlub;

// Funkcije

CelijaNogometniKlub* pronadjiZadnju(CelijaNogometniKlub* ppolaznaCelija) {
    CelijaNogometniKlub* pzadnjaCelija = ppolaznaCelija;

    while (pzadnjaCelija->psljedeca != NULL) {
        pzadnjaCelija = pzadnjaCelija->psljedeca;
    }

    return pzadnjaCelija;
}

// Unos kluba
void unosKlub(CelijaNogometniKlub* ppolaznaCelija) {
    Nogometni_klub noviKlub;
    
    char c;
    
    while ((c = getchar()) != '\n');
    printf("\n Unesite ime kluba: ");
    scanf_s("%49s", noviKlub.ime, (unsigned)_countof(noviKlub.ime));
    
    while ((c = getchar()) != '\n');
    printf("\n Unesite ligu kluba: ");
    scanf_s("%49s", noviKlub.liga, (unsigned)_countof(noviKlub.liga));
   
    while ((c = getchar()) != '\n');
    printf("\n Unesite stadion kluba: ");
    scanf_s("%49s", noviKlub.stadion, (unsigned)_countof(noviKlub.stadion));
    
    while ((c = getchar()) != '\n');
    printf("\n Unesite kapacitet stadiona kluba: ");
    scanf_s("%d", &noviKlub.kapacitet);
    
    while ((c = getchar()) != '\n');
    printf("\n Unesite godinu osnivanja kluba: ");
    scanf_s("%d", &noviKlub.godina_osnivanja);
    
    while ((c = getchar()) != '\n');
    printf("\n Unesite broj osvojenih naslova kluba: ");
    scanf_s("%d", &noviKlub.broj_naslova);

    CelijaNogometniKlub* novaCelija = (CelijaNogometniKlub*)malloc(sizeof(CelijaNogometniKlub));
    novaCelija->element = noviKlub;
    novaCelija->psljedeca = NULL;

    if (ppolaznaCelija->psljedeca == NULL) {
        ppolaznaCelija->psljedeca = novaCelija;
    }
    else {
        CelijaNogometniKlub* pzadnjaCelija = pronadjiZadnju(ppolaznaCelija);
        pzadnjaCelija->psljedeca = novaCelija;
    }
}




// Ispis kluba
void ispisKlub(CelijaNogometniKlub* ppolaznaCelija) {
    CelijaNogometniKlub* ptrenutnaCelija = ppolaznaCelija->psljedeca;

    while (ptrenutnaCelija != NULL) {
        printf("\n Ime kluba: %s", ptrenutnaCelija->element.ime);
        printf("\n Liga: %s", ptrenutnaCelija->element.liga);
        printf("\n Stadion: %s", ptrenutnaCelija->element.stadion);
        printf("\n Kapacitet stadiona: %d", ptrenutnaCelija->element.kapacitet);
        printf("\n Godina osnivanja kluba: %d", ptrenutnaCelija->element.godina_osnivanja);
        printf("\n Broj naslova: %d\n", ptrenutnaCelija->element.broj_naslova);

        ptrenutnaCelija = ptrenutnaCelija->psljedeca;
    }
}

void menu() {
    printf("\n-------------ODABERI OPCIJU-------------\n\n");
    printf("1: Unos");
    printf("\n2: Ispis");
    printf("\n3: Izmjena");
    printf("\n4: Brisanje");
    printf("\n5: Pretrazivanje");
    printf("\n6: IZLAZ\n\n");
}

// Izmjena elementa
void izmjena(Nogometni_klub izmijenjeniElement, CelijaNogometniKlub* pcelijaZaIzmjenu) {
    pcelijaZaIzmjenu->element = izmijenjeniElement;
}

// Brisanje elementa
void obrisiKlub(CelijaNogometniKlub* ppolaznaCelija) {
    char imeZaBrisanje[50];
    printf("\n Unesite ime kluba koji zelite obrisati: ");
    scanf_s("%49s", imeZaBrisanje, (unsigned)_countof(imeZaBrisanje));

    CelijaNogometniKlub* ptrenutnaCelija = ppolaznaCelija;
    CelijaNogometniKlub* prethodnaCelija = NULL;

    while (ptrenutnaCelija != NULL && strcmp(ptrenutnaCelija->element.ime, imeZaBrisanje) != 0) {
        prethodnaCelija = ptrenutnaCelija;
        ptrenutnaCelija = ptrenutnaCelija->psljedeca;
    }

    if (ptrenutnaCelija != NULL) {
        if (prethodnaCelija == NULL) {
            
            ppolaznaCelija->psljedeca = ptrenutnaCelija->psljedeca;
        }
        else {
            
            prethodnaCelija->psljedeca = ptrenutnaCelija->psljedeca;
        }
        free(ptrenutnaCelija);
        printf("\n Klub je uspjesno obrisan.\n");
    }
    else {
        printf("\n Klub s tim imenom nije pronadjen.\n");
    }
}

int main() {
    int odabir;
    CelijaNogometniKlub* ppolaznaCelija;

    ppolaznaCelija = (CelijaNogometniKlub*)malloc(sizeof(CelijaNogometniKlub));
    ppolaznaCelija->psljedeca = NULL;

    do {
        menu();
        scanf_s("%d", &odabir);
        switch (odabir) {
        case 1:
            unosKlub(ppolaznaCelija);
            break;

        case 2:
            ispisKlub(ppolaznaCelija);
            break;

        case 3:
            
            break;

        case 4:
            obrisiKlub(ppolaznaCelija);
            break;

        case 5:
            
            break;
        }
    } while (odabir != 6);

  

    return 0;
}

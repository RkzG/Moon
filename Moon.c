#include <stdio.h>
#include <string.h>
#include <ctype.h>

void characterCalculate(const char *moon, int *vokal, int *nonVokal) {
    *vokal = 0;
    *nonVokal = 0;
    while (*moon) {
        char a = tolower(*moon);
        if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') {
            (*vokal)++;
        } else if (isalpha(a)) {
            (*nonVokal)++;
        }
        moon++;
    }
}

int main() {

    const char *moon[] = {
        "Januari", "Februari", "Maret", "April", "Mei",
        "Juni", "Juli", "Agustus", "September", "Oktober",
        "November", "Desember"
    };
    
    char input;
    int i, vokal, nonVokal;
    int numMoon = 0;
    int choice = 0;

    printf("Masukkan huruf awal (A-Z): ");
    scanf(" %c", &input);
    
    input = toupper(input); 
    
    printf("Bulan-bulan yang dimulai dengan huruf '%c':\n", input);
    int indexMoon[12];
    for (i = 0; i < 12; i++) {
        if (moon[i][0] == input) {
            printf("%d. %s\n", numMoon + 1, moon[i]);
            indexMoon[numMoon] = i;
            numMoon++;
        }
    }

    if (numMoon == 0) {
        printf("Tidak ada bulan yang dimulai dengan huruf '%c'.\n", input);
        return 1;
    }
    
   if (numMoon == 1) {
        characterCalculate(moon[indexMoon[0]], &vokal, &nonVokal);
        printf("Jumlah vokal pada bulan '%s': %d\n", moon[indexMoon[0]], vokal);
        printf("Jumlah non-vokal pada bulan '%s': %d\n", moon[indexMoon[0]], nonVokal);
    } else {
        printf("Pilih bulan (masukkan nomor): ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > numMoon) {
            printf("Pilihan tidak valid.\n");
            return 1;
        }

        characterCalculate(moon[indexMoon[choice - 1]], &vokal, &nonVokal);
        printf("Jumlah vokal pada bulan '%s': %d\n", moon[indexMoon[choice - 1]], vokal);
        printf("Jumlah non-vokal pada bulan '%s': %d\n", moon[indexMoon[choice - 1]], nonVokal);
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Ozan�n �zelliklerini tan�mlamak i�in global de�i�kenler
char ozanAdi[50];
char calgiAdi[50];
int can = 100, tokluk = 100, uyku = 100, para = 10;
int guc = 3, ceviklik = 3, dayaniklilik = 3, karizma = 3, toplayicilik = 3;

// Fonksiyon prototipleri
void kampAlani();
void sifahane();
void han();
void macera();
void seviyeAtla();
void durumuGoster();
int oyundanCik(); // D�ng�y� k�r�p k�rmama kontrol� i�in int d�ner

int main() {
    // Oyun ba�lang�c�: Ozan�n ad�n� ve �alg�s�n� al
    printf("Ozanin adini girin: ");
    scanf("%s", ozanAdi);
    printf("Calginin adini girin: ");
    scanf("%s", calgiAdi);

    printf("\nHos geldin %s! %s adli calgini kullanarak maceralara atilacaksin.\n", ozanAdi, calgiAdi);

    // Ana men� sonsuz d�ng�s�
    while (1) {
        int secim;

        // Men� se�eneklerini g�ster
        printf("\n--- ANA MENU ---\n");
        printf("1. Kamp alanina git\n");
        printf("2. Sifahane\n");
        printf("3. Han\n");
        printf("4. Maceraya atil\n");
        printf("5. Seviye atla\n");
        printf("6. Durumu goster\n");
        printf("7. Oyundan cik\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        // Se�ime g�re i�lemleri y�nlendir
        switch (secim) {
            case 1:
                kampAlani();
                break;
            case 2:
                sifahane();
                break;
            case 3:
                han();
                break;
            case 4:
                macera();
                break;
            case 5:
                seviyeAtla();
                break;
            case 6:
                durumuGoster();
                break;
            case 7:
                if (oyundanCik()) { // E�er kullan�c� ��kmay� onaylarsa d�ng�y� k�r
                    printf("Oyun kapatiliyor...\n");
                    return 0; // Program� sonland�r
                }
                break;
            default:
                printf("Gecersiz bir secim yaptiniz. Lutfen 1 ile 7 arasinda bir secim yapin.\n");
        }
    }

    return 0;
}

// Fonksiyon tan�mlar� (bo� olarak b�rak�lm��)
void kampAlani() {
    printf("Kamp alani fonksiyonu calisiyor...\n");
}

void sifahane() {
    printf("Sifahane fonksiyonu calisiyor...\n");
}

void han() {
    printf("Han fonksiyonu calisiyor...\n");
}

void macera() {
    int secim;

    printf("\nMaceraya atildiniz!\n");
    while (1) { // Alt se�enekler i�in d�ng�
        printf("\n--- MACERA ---\n");
        printf("1. Yakin cevrede sifali bitki topla ve avlan\n");
        printf("2. Ormani kesfe cik (kolay)\n");
        printf("3. Kayaliklari kesfe cik (orta)\n");
        printf("4. Vadiyi kesfe cik (zor)\n");
        printf("5. Koy meydanina don\n");
        printf("Seciminizi girin (1-5): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                // �ifal� bitki ve avlanma mekani�i
                printf("Yakin cevrede sifali bitki topluyorsunuz...\n");
                if ((rand() % 100) < (toplayicilik * 4)) { // �ifal� bitki bulma ihtimali
                    printf("Bir sifali bitki buldunuz! Caniniz 10 puan artti.\n");
                    can += 10;
                    if (can > 100) can = 100; // Maksimum s�n�r� kontrol et
                } else {
                    printf("Sifali bitki bulamadiniz.\n");
                }

                if ((rand() % 100) < 50) { // %50 ihtimalle avlanma
                    printf("Av yaptiniz ve bir hayvan eti buldunuz! Toklugunuz 20 puan artti.\n");
                    tokluk += 20;
                    if (tokluk > 100) tokluk = 100; // Maksimum s�n�r� kontrol et
                } else {
                    printf("Avda sansiniz yaver gitmedi, bir sey bulamadiniz.\n");
                }
                break;
            case 2:
                // Kolay ke�if
                printf("Ormani kesfe cikiyorsunuz...\n");
                if ((rand() % 100) < 80) { // Kolay ke�if ba�ar� ihtimali
                    printf("Ormanda bir ganimet buldunuz! 15 altin kazandiniz ve 30 tecrube puani kazandiniz.\n");
                    para += 15;
                    guc += 1;
                } else {
                    printf("Bir orman canavari size saldirdi! Caniniz 10 puan azaldi.\n");
                    can -= 10;
                }
                break;
            case 3:
                // Orta ke�if
                printf("Kayaliklari kesfe cikiyorsunuz...\n");
                if ((rand() % 100) < 60) { // Orta ke�if ba�ar� ihtimali
                    printf("Kayaliklarda bir hazine buldunuz! 30 altin kazandiniz ve 60 tecrube puani kazandiniz.\n");
                    para += 30;
                    guc += 2;
                } else {
                    printf("Bir haydut size pusu kurdu! Caniniz 20 puan azaldi.\n");
                    can -= 20;
                }
                break;
            case 4:
                // Zor ke�if
                printf("Vadiyi kesfe cikiyorsunuz...\n");
                if ((rand() % 100) < 40) { // Zor ke�if ba�ar� ihtimali
                    printf("Vadide bir define buldunuz! 50 altin kazandiniz ve 90 tecrube puani kazandiniz.\n");
                    para += 50;
                    guc += 3;
                } else {
                    printf("Dev bir haydut size saldirdi! Caniniz 30 puan azaldi.\n");
                    can -= 30;
                }
                break;
            case 5:
                // K�y meydan�na d�n
                printf("Koy meydanina donuyorsunuz...\n");
                return; // D�ng�den ��k ve ana men�ye d�n
            default:
                printf("Gecersiz bir secim yaptiniz! Lutfen 1 ile 5 arasinda bir secim yapin.\n");
        }

        // Can s�n�r� kontrol�
        if (can <= 0) {
            printf("\nOzanin cani t�kendi. Oyun sona erdi!\n");
            exit(0); // Program� sonland�r
        }
    }
}

void seviyeAtla() {
    printf("Seviye atlama fonksiyonu calisiyor...\n");
}

void durumuGoster() {
    printf("\n--- DURUM ---\n");
    printf("Can: %d, Tokluk: %d, Uyku: %d, Para: %d\n", can, tokluk, uyku, para);
    printf("Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n", guc, ceviklik, dayaniklilik);
    printf("Karizma: %d, Toplayicilik: %d\n", karizma, toplayicilik);
}

// Oyundan ��k�� kontrol�
int oyundanCik() {
    char cevap;
    printf("\nOyundan cikmak istediginize emin misiniz? (E/H): ");
    scanf(" %c", &cevap); // ' %c' ba�taki bo�luk ile �nceki giri�ten kalan newline karakterini temizler

    if (cevap == 'E' || cevap == 'e') {
        return 1; // Kullan�c� ��kmak istiyor
    } else {
        printf("Oyuna devam ediliyor...\n");
        return 0; // Kullan�c� ��kmak istemiyor
    }
}

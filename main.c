#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ozanin özelliklerini tanimlamak için global degiskenler
char ozanAdi[50];
char calgiAdi[50];
int can = 100, tokluk = 100, uyku = 100, para = 10;
int guc = 3, ceviklik = 3, dayaniklilik = 3, karizma = 3, toplayicilik = 3;
int moral = 100, enerji = 100, hijyen = 100; // Yeni nitelikler
int ekmekFiyat = 5, yahniFiyat = 20; // Yemeklerin fiyatları
int ekmekTokluk = 10, yahniTokluk = 50, elmaTokluk = 5; // Tokluk etkileri
int tecrube = 0; // Tecrübe puanı
int seviye = 1;  // Karakterin seviyesi

// Fonksiyon prototipleri
void kampAlani();
void sifahane();
void han();
void macera();
void seviyeAtla();
void durumuGoster();
void moralArtir();
int oyundanCik(); // Döngüyü kirip kirmama kontrolü için int döner
void kontrolNitelikler();
void yemekYemek();
void uyumak();

int main() {
    // Rastgele sayı üreteci başlatılır
    srand(time(NULL));

    // Oyun baslangici: Ozanin adini ve çalgisini al
    printf("Ozanin adini girin: ");
    scanf("%s", ozanAdi);
    printf("Calginin adini girin: ");
    scanf("%s", calgiAdi);

    printf("\nHos geldin %s! %s adli calgini kullanarak maceralara atilacaksin.\n", ozanAdi, calgiAdi);

    // Ana menü sonsuz döngüsü
    while (1) {
        int secim;

        // Menü seçeneklerini göster
        printf("\n--- ANA MENU ---\n");
        printf("1. Kamp alanina git\n");
        printf("2. Sifahane\n");
        printf("3. Han\n");
        printf("4. Maceraya atil\n");
        printf("5. Seviye atla\n");
        printf("6. Durumu goster\n");
        printf("7. Oyundan cik\n");
        printf("8. Yemek ye\n");
        printf("9. Uyku cek\n");
        printf("10. Moral artir\n");

        printf("Seciminizi girin: ");
        while (scanf("%d", &secim) != 1) {
            printf("Lutfen gecerli bir sayi girin: ");
            while (getchar() != '\n'); // Girişi temizle
        }
        // Seçime göre iþlemleri yönlendir
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
                if (oyundanCik()) { // Eðer kullanici cikmayi onaylarsa döngüyü kir
                    printf("Oyun kapatiliyor...\n");
                    return 0; // Programi sonlandir
                }
                break;
            case 8:
                yemekYemek();
                break;
            case 9:
                uyumak();
                break;
            case 10:
                moralArtir();
                break;
            default:
                printf("Gecersiz bir secim yaptiniz. Lutfen 1 ile 10 arasinda bir secim yapin.\n");
        }
        // Moral ve enerji kontrolü
        if (moral < 0) moral = 0;
        if (enerji < 0) enerji = 0;
    }

    return 0;
}

void kampAlani() {
    printf("Kamp alani fonksiyonu calisiyor...\n");
}

void sifahane() {
    printf("Sifahane fonksiyonu calisiyor...\n");
}

//han'da kontrolTecrube olmali
void han() {
    int secim;
    printf("\n--- HAN ---\n");
    printf("1. Sarki soyle (Para kazanmak icin)\n");
    printf("2. Han'dan ayril\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1: // Şarkı söyleme eylemi
            if (hijyen <= 20) {
                printf("Hijyen seviyeniz cok dusuk! Sarki soyleyebilmek icin hijyeninizi artirmalisiniz.\n");
            } else {
                int kazanilanPara = 10 + karizma * (hijyen / 100.0);
                para += kazanilanPara;
                hijyen -= 5; // Şarkı söylemek biraz hijyen kaybına neden olur
                enerji -= 10; // Şarkı söylemek enerji tüketir
                printf("Sarki soylediniz! Kazandiginiz para: %d altin\n", kazanilanPara);
                printf("Hijyeniniz 5 puan azaldi, enerjiniz 10 puan azaldi.\n");
            }
            break;

        case 2: // Han'dan çıkış
            printf("Han'dan ayriliyorsunuz...\n");
            return;

        default:
            printf("Gecersiz bir secim yaptiniz. Lutfen tekrar deneyin.\n");
    }

    // Hijyen sınırlarını kontrol et
    if (hijyen < 0) hijyen = 0;
    if (enerji < 0) enerji = 0;

    // Kritik seviyelerde uyarı
    if (hijyen <= 20) printf("UYARI: Hijyen seviyeniz kritik seviyede!\n");
    if (enerji <= 20) printf("UYARI: Enerji seviyeniz kritik seviyede!\n");

    kontrolNitelikler(); // Merkezi kontrol
}
void macera() {
    int secim;

    printf("\nMaceraya atildiniz!\n");
    while (1) {
        printf("\n--- MACERA ---\n");
        printf("1. Yakin cevrede sifali bitki topla ve avlan\n");
        printf("2. Ormani kesfe cik (kolay)\n");
        printf("3. Kayaliklari kesfe cik (orta)\n");
        printf("4. Vadiyi kesfe cik (zor)\n");
        printf("5. Koy meydanina don\n");
        printf("Seciminizi girin (1-5): ");
        scanf("%d", &secim);

        // Enerji ve hijyen kontrolü
        if (enerji <= 10) {
            printf("Enerji seviyeniz cok dusuk! Maceraya atilmak icin dinlenmelisiniz.\n");
            break;
        }
        if (hijyen <= 10) {
            printf("Hijyen seviyeniz cok dusuk! Boyle bir durumda maceraya cikamazsiniz.\n");
            break;
        }

        // Haydut özellikleri
        int haydutGuc, haydutCeviklik, haydutDayaniklilik;

        switch (secim) {
            case 2: // Kolay keşif
                printf("Ormani kesfe cikiyorsunuz...\n");
                haydutGuc = 1 + rand() % 3;
                haydutCeviklik = 1 + rand() % 3;
                haydutDayaniklilik = 1 + rand() % 3;
                enerji -= 5;  // Enerji tüketimi
                hijyen -= 3;  // Hijyen kaybı
                savas(haydutGuc, haydutCeviklik, haydutDayaniklilik, 30);
                break;

            case 3: // Orta keşif
                printf("Kayaliklari kesfe cikiyorsunuz...\n");
                haydutGuc = 4 + rand() % 3;
                haydutCeviklik = 4 + rand() % 3;
                haydutDayaniklilik = 4 + rand() % 3;
                enerji -= 10; // Enerji tüketimi
                hijyen -= 5;  // Hijyen kaybı
                savas(haydutGuc, haydutCeviklik, haydutDayaniklilik, 60);
                break;

            case 4: // Zor keşif
                printf("Vadiyi kesfe cikiyorsunuz...\n");
                haydutGuc = 7 + rand() % 4;
                haydutCeviklik = 7 + rand() % 4;
                haydutDayaniklilik = 7 + rand() % 4;
                enerji -= 15; // Enerji tüketimi
                hijyen -= 8;  // Hijyen kaybı
                savas(haydutGuc, haydutCeviklik, haydutDayaniklilik, 90);
                break;

            case 1: // Şifalı bitki toplama ve avlanma
                printf("Yakin cevrede sifali bitki topluyorsunuz...\n");
                enerji -= 5;  // Enerji tüketimi
                int sifaliBitkiSans = (toplayicilik * 4);

                if ((rand() % 100) < sifaliBitkiSans) {
                    printf("Bir sifali bitki buldunuz! Caniniz 10 puan artti.\n");
                    can += 10;
                    if (can > 100) can = 100;
                } else {
                    printf("Sifali bitki bulamadiniz.\n");
                }

                if ((rand() % 100) < (sifaliBitkiSans / 2)) {
                    printf("Meyve topladiniz! Toklugunuz 10 puan artti.\n");
                    tokluk += 10;
                    if (tokluk > 100) tokluk = 100;
                } else {
                    printf("Meyve toplamakta sansiniz yaver gitmedi.\n");
                }

                if ((rand() % 100) < 50) {
                    printf("Av yaptiniz ve bir hayvan eti buldunuz! Toklugunuz 50 puan artti.\n");
                    tokluk += 50;
                    if (tokluk > 100) tokluk = 100;
                } else {
                    printf("Avda sansiniz yaver gitmedi, bir sey bulamadiniz.\n");
                }
                break;

            case 5: // Köy meydanına dönüş
                printf("Koy meydanina donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz bir secim yaptiniz! Lutfen 1 ile 5 arasinda bir secim yapin.\n");
        }

        kontrolNitelikler(); // Oyuncu niteliklerini kontrol et
        kontrolTecrube();    // Tecrübe kontrolü
    }
}


void yemekYemek() {
    int secim;
    printf("\n--- YEMEK MENUSU ---\n");
    printf("1. Ekmek (5 altin, +10 tokluk, -5 uyku)\n");
    printf("2. Yahni (20 altin, +50 tokluk, -10 uyku)\n");
    printf("3. Elma (Ucretsiz, +5 tokluk, -2 uyku)\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1: // Ekmek
            if (para >= ekmekFiyat) {
                para -= ekmekFiyat;
                tokluk += ekmekTokluk;
                uyku -= 5; // Yemek yeme uyku kaybına sebep olur
                printf("Ekmek yediniz. Toklugunuz %d puan artti. Uykunuz 5 puan azaldi.\n", ekmekTokluk);
            } else {
                printf("Yeterli paraniz yok!\n");
            }
            break;

        case 2: // Yahni
            if (para >= yahniFiyat) {
                para -= yahniFiyat;
                tokluk += yahniTokluk;
                uyku -= 10; // Daha ağır yemek, daha fazla uyku kaybı
                printf("Yahni yediniz. Toklugunuz %d puan artti. Uykunuz 10 puan azaldi.\n", yahniTokluk);
            } else {
                printf("Yeterli paraniz yok!\n");
            }
            break;

        case 3: // Elma
            tokluk += elmaTokluk;
            uyku -= 2; // Elma yemek hafif bir eylem
            printf("Elma yediniz. Toklugunuz %d puan artti. Uykunuz 2 puan azaldi.\n", elmaTokluk);
            break;

        default:
            printf("Gecersiz secim yaptiniz! Lutfen tekrar deneyin.\n");
    }

    // Nitelik sınırlarını kontrol et
    if (tokluk > 100) tokluk = 100;
    if (uyku > 100) uyku = 100;
    if (tokluk < 0) tokluk = 0;
    if (uyku < 0) uyku = 0;

    // Kritik seviye uyarıları
    if (uyku <= 20) printf("UYARI: Uyku seviyeniz kritik derecede dusuk!\n");
    if (tokluk <= 20) printf("UYARI: Tokluk seviyeniz kritik derecede dusuk!\n");

    // Can kaybı mekanizması (herhangi bir nitelik sıfırsa)
    if (tokluk == 0) {
        printf("Tokluk 0'a dustu! Caniniz 20 puan azaldi.\n");
        can -= 20;
    }
    if (uyku == 0) {
        printf("Uyku 0'a dustu! Caniniz 10 puan azaldi.\n");
        can -= 10;
    }

    // Nitelikleri kontrol et
    kontrolNitelikler();
}

void savas(int dusmanGuc, int dusmanCeviklik, int dusmanDayaniklilik, int tecrubeKazan) {
    printf("\nBir haydutla karsilastiniz!\n");
    printf("Haydut Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n", dusmanGuc, dusmanCeviklik, dusmanDayaniklilik);

    while (can > 0 && dusmanDayaniklilik > 0) {
        int secim;
        printf("\n--- SAVAS TURU ---\n");
        printf("1. Saldir\n");
        printf("2. Kacmaya Calis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        if (secim == 2) { // Kaçma girişimi
            int kacmaSans = (4 * ceviklik) / 100.0 * 100; // Formüle göre kaçma şansı
            if ((rand() % 100) < kacmaSans) {
                printf("Basariyla kactiniz! Savas sona erdi.\n");
                return; // Başarılı kaçış
            } else {
                printf("Kacamadiniz! Turunuzu harcadiniz ve rakip saldiriya geciyor...\n");
            }
        }

        // Savaş sırası kontrolü
        int ozanIlkSaldiri = ceviklik > dusmanCeviklik || (ceviklik == dusmanCeviklik && rand() % 2);

        if (ozanIlkSaldiri) { // Ozan saldırıyor
            int verilenHasar = 4 * guc; // Rakibe verilen hasar
            dusmanDayaniklilik -= verilenHasar;
            printf("Saldirdiniz! Rakibe %d hasar verdiniz. Dusman Dayanikliligi: %d\n", verilenHasar, dusmanDayaniklilik);
        } else { // Rakip saldırıyor
            int RVH = 4 * dusmanGuc; // Rakibin verdiği ham hasar
            int alinanHasar = RVH - (RVH * (dayaniklilik * 4 / 100) - 1); // Alınan hasar formülü
            if (alinanHasar < 0) alinanHasar = 0; // Negatif hasarı sıfıra ayarla
            can -= alinanHasar;
            printf("Rakip saldirdi! %d hasar aldiniz. Caniniz: %d\n", alinanHasar, can);
        }

        if (dusmanDayaniklilik <= 0) { // Düşman yenildi
            printf("Dusmani yendiniz! %d tecrube kazandiniz.\n", tecrubeKazan);
            tecrube += tecrubeKazan;
            break;
        }

        if (can <= 0) { // Ozan yenildi
            printf("Haydut sizi yendi! Macera sona erdi.\n");
            break;
        }

        // Durum özeti
        printf("Caniniz: %d | Dusman Dayanikliligi: %d\n", can, dusmanDayaniklilik);
    }
}


void uyumak() {
    int secim;
    printf("\n--- UYKU MENUSU ---\n");
    printf("1. Kisa uyku (+20 uyku, -10 tokluk)\n");
    printf("2. Orta uyku (+50 uyku, -20 tokluk)\n");
    printf("3. Uzun uyku (+100 uyku, -30 tokluk)\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1: // Kısa uyku
            if (uyku == 100) {
                printf("Zaten tamamen dinlenmişsiniz, daha fazla uyuyamazsınız!\n");
                break;
            }
            uyku += 20;
            enerji += 10;
            tokluk -= 10;
            printf("Kisa bir uyku cektiniz. Uyku seviyeniz 20 puan artti. Toklugunuz 10 puan azaldi.\n");
            break;

        case 2: // Orta uyku
            if (uyku == 100) {
                printf("Zaten tamamen dinlenmişsiniz, daha fazla uyuyamazsınız!\n");
                break;
            }
            uyku += 50;
            enerji += 25;
            tokluk -= 20;
            printf("Orta uzunlukta bir uyku cektiniz. Uyku seviyeniz 50 puan artti. Toklugunuz 20 puan azaldi.\n");
            break;

        case 3: // Uzun uyku
            if (uyku == 100) {
                printf("Zaten tamamen dinlenmişsiniz, daha fazla uyuyamazsınız!\n");
                break;
            }
            uyku += 100;
            enerji += 50;
            tokluk -= 30;
            printf("Uzun bir uyku cektiniz. Uyku seviyeniz 100 puan artti. Toklugunuz 30 puan azaldi.\n");
            break;

        default:
            printf("Gecersiz secim yaptiniz! Lutfen tekrar deneyin.\n");
            return; // İşlemi tekrar başlat
    }

    // Nitelik sınırlarını kontrol et
    if (uyku > 100) uyku = 100;
    if (enerji > 100) enerji = 100;
    if (tokluk < 0) tokluk = 0;

    // Kritik seviye uyarıları
    if (tokluk <= 20) printf("UYARI: Tokluk seviyeniz kritik derecede dusuk!\n");

    // Can kaybı mekanizması
    if (tokluk == 0) {
        printf("Tokluk 0'a dustu! Caniniz 20 puan azaldi.\n");
        can -= 20;
    }

    // Nitelikleri kontrol et
    kontrolNitelikler();
}


void moralArtir() {
    int secim;
    printf("\n1. Kamp Atesi (+10 moral)\n");
    printf("2. Hikaye Anlatma (+20 moral)\n");
    printf("3. Sarki Soyleme (+50 moral, 5 enerji harcar)\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            moral += 10;
            printf("Kamp atesinde vakit gecirdiniz. Moraliniz 10 puan artti.\n");
            break;
        case 2:
            moral += 20;
            printf("Hikaye anlattiniz. Moraliniz 20 puan artti.\n");
            break;
        case 3:
            if (enerji >= 5) {
                moral += 50;
                enerji -= 5;
                if (enerji < 0) enerji = 0;
                printf("Sarki soylediniz. Moraliniz 50 puan artti ve 5 enerji harcadiniz.\n");
            } else {
                printf("Yeterli enerjiniz yok!\n");
            }
            break;
        default:
            printf("Gecersiz secim yaptiniz!\n");
    }

    if (moral > 100) moral = 100; // Maksimum moral kontrolü
}

void seviyeAtla() {
    printf("\nSeviye atlama fonksiyonu calisiyor...\n");
    int puan = 5;
    while (puan > 0) {
        int secim;
        printf("Kalan puan: %d\n", puan);
        printf("1. Guc\n2. Ceviklik\n3. Dayaniklilik\n4. Karizma\n5. Toplayicilik\n6. Yaraticilik\n");
        printf("7. Ana menuye don\n");
        printf("Hangi ozellige puan eklemek istersiniz? ");
        scanf("%d", &secim);

        if (secim == 7) {
            printf("Ana menuye donuluyor...\n");
            return; // Ana menüye döner
        }

        switch (secim) {
            case 1:
                if (guc <25 ) {
                        guc++;
                        printf("Guc artirildi!\n");
                }
                else printf("Guc maksimum seviyede ! \n");
                break;
            case 2:
                if (ceviklik < 25) {
                        ceviklik++;
                        printf("Ceviklik artirildi!\n");
                }
                else printf("Ceviklik maksimum seviyede!\n");
                break;
            case 3:
                if (dayaniklilik <25) {
                        dayaniklilik++;
                        printf("Dayaniklilik artirildi!\n");
                }
                else printf("Dayaniklilik maksimum seviyede!\n");
                break;
            case 4:
                if (karizma < 25 )  {
                        karizma++;
                        printf("Karizma artirildi!\n");
                }
                else printf("Karizma maksimum seviyede!\n");
                break;
            case 5:
                if (toplayicilik< 25) {
                        toplayicilik++;
                        printf("Toplayicilik artirildi!\n");
                }
                else printf("Toplayicilik maksimum seviyede!\n");
                break;
            case 6:
                moral += 10;
                if (moral > 100) moral = 100;
                printf("Moral artirildi!\n");
                break;
            default:
                printf("Gecersiz secim! Lutfen 1 ile 7 arasinda bir secim yapin.\n");
                continue;
        }
        puan--;
    }
    printf("Seviye atlama islemi tamamlandi. Ana menüye donuluyor...\n");
}

void kontrolTecrube() {
    if (tecrube >= 100) {
        printf("\nTebrikler! Tecrube puaniniz 100'e ulasti. Seviye atliyorsunuz!\n");
        tecrube = 0; // Tecrübe sıfırlanır
        seviye++;
        printf("Yeni seviyeniz: %d\n", seviye);
        seviyeAtla(); // Seviye atlama menüsüne geçiş
    }
}

void kontrolNitelikler() {
    // Temel nitelikler sınır kontrolü
    if (tokluk > 100) tokluk = 100;
    if (tokluk < 0) tokluk = 0;

    if (uyku > 100) uyku = 100;
    if (uyku < 0) uyku = 0;

    if (moral > 100) moral = 100;
    if (moral < 0) moral = 0;

    if (enerji > 100) enerji = 100;
    if (enerji < 0) enerji = 0;

    if (hijyen > 100) hijyen = 100;
    if (hijyen < 0) hijyen = 0;

    // Kritik seviyelerde uyarı mesajları
    if (tokluk <= 20 && tokluk > 0) printf("UYARI: Tokluk kritik seviyede!\n");
    if (uyku <= 20 && uyku > 0) printf("UYARI: Uyku kritik seviyede!\n");
    if (moral <= 20 && moral > 0) printf("UYARI: Moral kritik seviyede!\n");

    // Nitelikler 0'a düştüğünde can kaybı
    if (tokluk == 0) {
        printf("Tokluk 0! Caniniz 20 puan azaldi.\n");
        can -= 20;
    }
    if (uyku == 0) {
        printf("Uyku 0! Caniniz 10 puan azaldi.\n");
        can -= 10;
    }
    if (moral == 0) {
        printf("Moral 0! Caniniz 5 puan azaldi.\n");
        can -= 5;
    }
    if (hijyen == 0) {
        printf("Hijyen 0! Caniniz 5 puan azaldi.\n");
        can -= 5;
    }

    // Can kontrolü
    if (can > 100) can = 100;
    if (can <= 0) { // Can sıfır olduğunda oyunun bitmesi
        printf("\nOzanin cani tükendi. Oyun sona erdi!\n");
        printf("Oyunu tekrar baslatmak ister misiniz? (E/H): ");

        char cevap;
        scanf(" %c", &cevap);

        if (cevap == 'E' || cevap == 'e') {
            // Değerleri yeniden başlat
            can = 100; tokluk = 100; uyku = 100; moral = 100; enerji = 100; hijyen = 100; para = 10;
            guc = 3; ceviklik = 3; dayaniklilik = 3; karizma = 3; toplayicilik = 3;

            printf("Oyun yeniden basliyor...\n");
        } else {
            printf("Oyun kapatiliyor...\n");
            exit(0); // Programı sonlandir
        }
    }
}

void durumuGoster() {
    printf("\n--- DURUM ---\n");
    kontrolNitelikler(); // Merkezi kontrol
    printf("Can: %d, Tokluk: %d, Uyku: %d, Moral: %d, Enerji: %d, Hijyen: %d, Para: %d\n",
           can, tokluk, uyku, moral, enerji, hijyen, para);
    printf("Guc: %d, Ceviklik: %d, Dayaniklilik: %d, Karizma: %d, Toplayicilik: %d\n",
           guc, ceviklik, dayaniklilik, karizma, toplayicilik);
}

// Oyundan çikisi kontrolü
int oyundanCik() {
    char cevap;
    printf("\nOyundan cikmak istediginize emin misiniz? (E/H): ");
    scanf(" %c", &cevap); // ' %c' bastaki bosluk ile önceki giristen kalan newline karakterini temizler

    if (cevap == 'E' || cevap == 'e') {
        return 1; // Kullanici cikmak istiyor
    } else {
        printf("Oyuna devam ediliyor...\n");
        return 0; // Kullanici çikmak istemiyor
    }
}

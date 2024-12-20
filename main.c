#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char instrument[50];
    int health;
    int hunger;
    int sleep;
    int hygiene;
    int moral;
    int energy;
    int thirst;
    int level;
    int experience;
    int money;
    int strength;
    int agility;
    int endurance;
    int charisma;
    int gathering_skill;
} Character;

void displayMainMenu();
void goToCamp(Character *character);
void goToHealer(Character *character);
void goToInn(Character *character);
void goOnAdventure(Character *character);
void hype(Character *character);
void sleep(Character *character);
void eat(Character *character);
void levelUp(Character *character);
void showStatus(Character *character);
void drinkWater(Character *character);
void gatherEnergy(Character *character);
void specialMoralBoost(Character *character);
void resolveCombat(Character *character, int enemyStrength, int enemyAgility, int enemyEndurance, int minGold, int maxGold, int xpReward);
void checkLevelUp(Character *character);

int main() {

    Character player = {0};

    printf("Ozanin adini girin: ");
    fgets(player.name, 50, stdin);
    player.name[strcspn(player.name, "\n")] = '\0';

    printf("Ozanin kullandigi calgiyi girin: ");
    fgets(player.instrument, 50, stdin);
    player.instrument[strcspn(player.instrument, "\n")] = '\0';

    player.health = 100;
    player.hunger = 50;
    player.sleep = 50;
    player.hygiene = 50;
    player.moral = 50;
    player.energy = 50;
    player.thirst = 50;
    player.level = 1;
    player.experience = 0;
    player.money = 10;
    player.strength = 3;
    player.agility = 3;
    player.endurance = 3;
    player.charisma = 3;
    player.gathering_skill = 3;

    int choice;
    while (1) {
    displayMainMenu();
    printf("\nSeciminizi yapin: ");

    if (scanf("%d", &choice) != 1) {
        printf("Gecersiz giris! Lutfen bir sayi girin.\n");
        while (getchar() != '\n');
        continue;
    }

        switch (choice) {
            case 1: goToCamp(&player); break;
            case 2: goToHealer(&player); break;
            case 3: goToInn(&player); break;
            case 4: goOnAdventure(&player); break;
            case 5: hype(&player); break;
            case 6: eat(&player); break;
            case 7: sleep(&player); break;
            case 8: drinkWater(&player); break;
            case 9: gatherEnergy(&player); break;
            case 10: specialMoralBoost(&player); break;
            case 11: levelUp(&player); break;
            case 12: showStatus(&player); break;
            case 13:
                printf("Oyundan cikmak istediginize emin misiniz? (E/h): ");
                char exitChoice;
                scanf(" %c", &exitChoice);
                if (exitChoice == 'E' || exitChoice == 'e') {
                    printf("Oyundan cikiliyor...\n");
                    exit(0);
                } else {
                    printf("Ana menuye donuluyor...\n");
                }
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    }


    return 0;
}

void displayMainMenu() {

    printf("\n=== Ana Menu ===\n");
    printf("1. Kamp alanina git\n");
    printf("2. Sifahaneye git\n");
    printf("3. Hana git\n");
    printf("4. Maceraya atil\n");
    printf("5. Moral artir\n");
    printf("6. Yemek ye\n");
    printf("7. Uyu\n");
    printf("8. Su ic\n");
    printf("9. Enerji topla\n");
    printf("10. Moral artirici aktivite\n");
    printf("11. Seviye atla\n");
    printf("12. Karakterin durumunu goster\n");
    printf("13. Oyundan cik\n");
}

void goToCamp(Character *character) {

    int choice;
    while (1) {
        printf("\n=== Kamp Alani ===\n");
        printf("1. Kamp atesinin basinda calgi cal/sarki soyle\n");
        printf("2. Nehirde yikan\n");
        printf("3. Cadirina girip uyu\n");
        printf("4. Koy meydanina don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Kamp atesinin basinda calgi caliyor ve sarki soyluyorsunuz...\n");
                character->charisma += 2;
                character->hygiene -= 5;
                character->hunger -= 5;
                character->experience += 10;
                printf("Karizma +2, Hijyen -5, Tokluk -5, Tecrube +10\n");
                checkLevelUp(character);
                break;

            case 2:
                printf("Nehirde yikaniyorsunuz...\n");
                character->hygiene += 20;
                character->health += 5;
                character->hunger -= 5;
                printf("Hijyen +20, Can +5, Tokluk -5\n");
                break;

            case 3:
                printf("Cadiriniza girip uyuyorsunuz...\n");
                character->sleep += 30;
                character->hunger -= 10;
                character->health += 10;
                printf("Uyku +30, Tokluk -10, Can +10\n");
                break;

            case 4:
                printf("Kamp alanindan ayrilarak koy meydanina donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

        if (character->hygiene > 100) character->hygiene = 100;
        if (character->hygiene < 0) character->hygiene = 0;

        if (character->health > 100) character->health = 100;
        if (character->health < 0) character->health = 0;

        if (character->hunger > 100) character->hunger = 100;
        if (character->hunger < 0) character->hunger = 0;

        if (character->sleep > 100) character->sleep = 100;
        if (character->sleep < 0) character->sleep = 0;
    }
}

void goToHealer(Character *character) {

    int choice;
    while (1) {
        printf("\n=== Sifahane ===\n");
        printf("1. Sifacidan yaralarini sarmasini iste (5 altin)\n");
        printf("2. Sifacidan merhem yapip surmesini iste (10 altin)\n");
        printf("3. Koy meydanina don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (character->money >= 5) {
                    printf("Sifaci yaralarinizi sardi.\n");
                    character->money -= 5;
                    character->health += 20;
                    printf("Can +20, Para -5\n");
                } else {
                    printf("Yeterli paraniz yok! (Gerekli: 5 altin)\n");
                }
                break;

            case 2:
                if (character->money >= 10) {
                    printf("Sifaci size ozel bir merhem yapti ve surdu.\n");
                    character->money -= 10;
                    character->health += 40;
                    printf("Can +40, Para -10\n");
                } else {
                    printf("Yeterli paraniz yok! (Gerekli: 10 altin)\n");
                }
                break;

            case 3:
                printf("Sifahaneden ayrilarak koy meydanina donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

        if (character->health > 100) character->health = 100;
        if (character->health < 0) character->health = 0;
    }
}

void goToInn(Character *character) {

    int choice;
    while (1) {
        printf("\n=== Han ===\n");
        printf("1. Yiyecek satin al ve ye (10 altin)\n");
        printf("2. Icecek satin al, ic ve eglen (5 altin)\n");
        printf("3. Enstruman cal ve sarki soyle\n");
        printf("4. Koy meydanina don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (character->money >= 10) {
                    printf("Yemek yediniz. Kendinizi daha iyi hissediyorsunuz!\n");
                    character->money -= 10;
                    character->hunger += 30;
                    character->health += 10;
                    printf("Tokluk +30, Can +10, Para -10\n");
                } else {
                    printf("Yeterli paraniz yok! (Gerekli: 10 altin)\n");
                }
                break;

            case 2:
                if (character->money >= 5) {
                    printf("Icecek ictiniz ve eglendiniz. Ruh haliniz duzeldi!\n");
                    character->money -= 5;
                    character->hunger += 10;
                    character->charisma += 5;
                    character->hygiene -= 10;
                    printf("Tokluk +10, Karizma +5, Hijyen -10, Para -5\n");
                } else {
                    printf("Yeterli paraniz yok! (Gerekli: 5 altin)\n");
                }
                break;

            case 3:
                if (character->hygiene > 20) {
                    printf("Enstruman calip sarki soylediniz. Han sakinleri cok eglendi!\n");
                    int earnedMoney = 10 + (character->charisma * character->hygiene) / 100;
                    character->money += earnedMoney;
                    character->experience += 20;
                    printf("Para +%d, Tecrube +20\n", earnedMoney);
                    checkLevelUp(character);
                } else {
                    printf("Hijyeniniz cok dusuk (20 veya alti)! Handa sarki soyleyemezsiniz.\n");
                }
                break;

            case 4:
                printf("Handan ayrilarak koy meydanina donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

        if (character->hunger > 100) character->hunger = 100;
        if (character->hunger < 0) character->hunger = 0;

        if (character->health > 100) character->health = 100;
        if (character->health < 0) character->health = 0;

        if (character->charisma > 25) character->charisma = 25;
        if (character->charisma < 3) character->charisma = 3;

        if (character->hygiene > 100) character->hygiene = 100;
        if (character->hygiene < 0) character->hygiene = 0;
    }
}

void goOnAdventure(Character *character) {

    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n=== Macera ===\n");
        printf("1. Yakin cevreden sifali bitki topla ve avlan\n");
        printf("2. Ormani kesfe cik (Kolay)\n");
        printf("3. Kayaliklari kesfe cik (Orta)\n");
        printf("4. Vadiyi kesfe cik (Zor)\n");
        printf("5. Koy meydanina don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Yakin cevrede bitki ve avlanma denemesi yapiyorsunuz...\n");
                int gatherChance = (character->gathering_skill * 4);
                int randomValue = rand() % 100 + 1;
                if (randomValue <= gatherChance) {
                    printf("Sifali bir bitki buldunuz! Caniniz 10 artti.\n");
                    character->health += 10;
                } else if (randomValue <= gatherChance * 2) {
                    printf("Meyve buldunuz! Toklugunuz 10 artti.\n");
                    character->hunger += 10;
                } else if (randomValue <= gatherChance * 3 / 2) {
                    printf("Av hayvani yakaladiniz! Toklugunuz 50 artti.\n");
                    character->hunger += 50;
                } else {
                    printf("Hicbir sey bulamadiniz.\n");
                }
                character->hunger -= 10;
                printf("Tokluk -10\n");
                break;
            }

            case 2: {
                printf("Ormani kesfe cikiyorsunuz (Kolay)...\n");
                int enemyStrength = rand() % 3 + 1;
                int enemyAgility = rand() % 3 + 1;
                int enemyEndurance = rand() % 3 + 1;
                printf("Dusman Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n", enemyStrength, enemyAgility, enemyEndurance);
                resolveCombat(character, enemyStrength, enemyAgility, enemyEndurance, 15, 25, 30);
                checkLevelUp(character);
                break;
            }

            case 3: {
                printf("Kayaliklari kesfe cikiyorsunuz (Orta)...\n");
                int enemyStrength = rand() % 3 + 4;
                int enemyAgility = rand() % 3 + 4;
                int enemyEndurance = rand() % 3 + 4;
                printf("Dusman Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n", enemyStrength, enemyAgility, enemyEndurance);
                resolveCombat(character, enemyStrength, enemyAgility, enemyEndurance, 30, 50, 60);
                checkLevelUp(character);
                break;
            }

            case 4: {
                printf("Vadiyi kesfe cikiyorsunuz (Zor)...\n");
                int enemyStrength = rand() % 4 + 7;
                int enemyAgility = rand() % 4 + 7;
                int enemyEndurance = rand() % 4 + 7;
                printf("Dusman Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n", enemyStrength, enemyAgility, enemyEndurance);
                resolveCombat(character, enemyStrength, enemyAgility, enemyEndurance, 55, 75, 90);
                checkLevelUp(character);
                break;
            }

            case 5:
                printf("Macera alanindan ayrilarak koy meydanina donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

        if (character->health > 100) character->health = 100;
        if (character->health < 0) character->health = 0;

        if (character->hunger > 100) character->hunger = 100;
        if (character->hunger < 0) character->hunger = 0;
    }
}

void resolveCombat(Character *character, int enemyStrength, int enemyAgility, int enemyEndurance, int minGold, int maxGold, int xpReward) {

    int escapeChance = (character->agility * 4);
    int randomValue = rand() % 100 + 1;
    if (randomValue <= escapeChance) {
        printf("Kacmayi basardiniz! Guvenli bir sekilde uzaklastiniz.\n");
        return;
    } else {
        printf("Kacmayi basaramadiniz! Dusman sizi fark etti ve saldiriya geciyor...\n");
    }

    int characterAttack = 4 * character->strength;
    int enemyAttack = 4 * enemyStrength;
    while (character->health > 0 && enemyStrength > 0) {
        if (character->agility >= enemyAgility) {

            int damage = characterAttack - (characterAttack * enemyEndurance / 100);
            if (damage > 0) enemyStrength -= damage;
            printf("Dusmana %d hasar verdiniz. (Kalan Guc: %d)\n", damage, enemyStrength);
        }
            else {
            int damage = enemyAttack - (enemyAttack * character->endurance / 100);
            if (damage > 0) character->health -= damage;
            printf("Dusmandan %d hasar aldiniz. (Kalan Can: %d)\n", damage, character->health);
        }

        if (character->agility == enemyAgility) {
            if (rand() % 2 == 0) continue;
        }
    }


    if (character->health > 0) {
        printf("Savasi kazandiniz!\n");
        int goldEarned = rand() % (maxGold - minGold + 1) + minGold;
        character->money += goldEarned;
        character->experience += xpReward;
        printf("Para +%d, Tecrube +%d\n", goldEarned, xpReward);
    } else {
        printf("Savasi kaybettiniz...\n");
    }
}

void levelUp(Character *character) {
    int remainingPoints = 5;
    int choice, points;

    printf("\n=== Seviye Atladiniz! ===\n");
    character->level += 1;
    character->experience = 0;
    printf("Yeni seviyeniz: %d\n", character->level);
    printf("Beceri puani dagitmak icin toplam 5 puaniniz var.\n");

    while (remainingPoints > 0) {
        printf("\nKalan puan: %d\n", remainingPoints);
        printf("Hangi becerinize puan eklemek istersiniz? (Cikmak icin 0 girin)\n");
        printf("1. Guc (Su anki: %d)\n", character->strength);
        printf("2. Ceviklik (Su anki: %d)\n", character->agility);
        printf("3. Dayaniklilik (Su anki: %d)\n", character->endurance);
        printf("4. Karizma (Su anki: %d)\n", character->charisma);
        printf("5. Toplayicilik (Su anki: %d)\n", character->gathering_skill);
        printf("Seciminizi yapin (0-5): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Puan dagitimi iptal edildi. Ana menuye donuluyor...\n");
            return;
        }

        if (choice < 1 || choice > 5) {
            printf("Gecersiz secim! Lutfen 1-5 arasinda bir deger girin.\n");
            continue;
        }

        printf("Bu beceriye kac puan eklemek istersiniz? (1-%d): ", remainingPoints);
        scanf("%d", &points);

        if (points <= 0 || points > remainingPoints) {
            printf("Gecersiz puan miktari! Lutfen 1-%d arasinda bir deger girin.\n", remainingPoints);
            continue;
        }

        switch (choice) {
            case 1:
                character->strength += points;
                printf("Guc +%d (Yeni: %d)\n", points, character->strength);
                break;
            case 2:
                character->agility += points;
                printf("Ceviklik +%d (Yeni: %d)\n", points, character->agility);
                break;
            case 3:
                character->endurance += points;
                printf("Dayaniklilik +%d (Yeni: %d)\n", points, character->endurance);
                break;
            case 4:
                character->charisma += points;
                printf("Karizma +%d (Yeni: %d)\n", points, character->charisma);
                break;
            case 5:
                character->gathering_skill += points;
                printf("Toplayicilik +%d (Yeni: %d)\n", points, character->gathering_skill);
                break;
        }

        remainingPoints -= points;

    }

    printf("\nBeceri puanlarinizi basariyla dagittiniz! Ana menuye donuluyor...\n");
}

void checkLevelUp(Character *character) {
    while (character->experience >= 100) {
        printf("\n=== Seviye Atlama ===\n");
        character->experience -= 100;
        character->level += 1;
        printf("Tebrikler! Seviye atladiniz. Su anki seviye: %d\n", character->level);
        levelUp(character);
    }
}

void showStatus(Character *character) {
    printf("\n=== Karakter Durumu ===\n");
    printf("Ad: %s\n", character->name);
    printf("Calgi: %s\n", character->instrument);
    printf("Seviye: %d\n", character->level);
    printf("Tecrube Puani: %d/100\n", character->experience);
    printf("Para: %d altin\n", character->money);
    printf("Can: %d/100\n", character->health);
    printf("Tokluk: %d/100\n", character->hunger);
    printf("Uyku: %d/100\n", character->sleep);
    printf("Hijyen: %d/100\n", character->hygiene);
    printf("Moral: %d/100\n", character->moral);
    printf("Enerji: %d/100\n", character->energy);
    printf("Susuzluk: %d/100\n", character->thirst);

    printf("\n=== Beceri Durumu ===\n");
    printf("Guc: %d/25\n", character->strength);
    printf("Ceviklik: %d/25\n", character->agility);
    printf("Dayaniklilik: %d/25\n", character->endurance);
    printf("Karizma: %d/25\n", character->charisma);
    printf("Toplayicilik: %d/25\n", character->gathering_skill);

    printf("\n=== Genel Durum ===\n");
    if (character->health <= 20) {
        printf("Uyari: Can seviyeniz kritik! Sifahaneye gitmeyi veya dinlenmeyi dusunun.\n");
    }
    if (character->hunger <= 20) {
        printf("Uyari: Tokluk seviyeniz dusuk! Yemek yemeniz gerekiyor.\n");
    }
    if (character->thirst <= 20) {
        printf("Uyari: Susuzluk seviyeniz dusuk! Su icmelisiniz.\n");
    }
    if (character->sleep <= 20) {
        printf("Uyari: Uyku seviyeniz dusuk! Dinlenmeniz gerekiyor.\n");
    }
    if (character->hygiene <= 20) {
        printf("Uyari: Hijyen seviyeniz dusuk! Nehirde yikanmayi veya temizlenmeyi dusunun.\n");
    }
    if (character->moral <= 20) {
        printf("Uyari: Moral seviyeniz cok dusuk! Moral artirici aktiviteler yapmalisiniz.\n");
    }
    if (character->energy <= 20) {
        printf("Uyari: Enerji seviyeniz dusuk! Dinlenmeniz gerekiyor.\n");
    }

    printf("\nDurum bilgileri gosterildi. Ana menuye donmek icin bir tusa basin...\n");
    getchar();
    getchar();
}

void hype(Character *character) {

    int choice;
    while (1) {
        printf("\n=== Moral Artirma Aktiviteleri ===\n");
        printf("1. Enstruman cal ve sarki soyle (Moral +10, Hijyen -10, Enerji -5)\n");
        printf("2. Dans et ve eglen (Moral +20, Hijyen -15, Enerji -10, Susuzluk -5)\n");
        printf("3. Doga yuruyusune cik (Moral +15, Enerji -10, Susuzluk -10)\n");
        printf("4. Ana menuye don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (character->hygiene > 20) {
                    printf("Enstruman calip sarki soylediniz. Moraliniz yukseldi!\n");
                    character->moral += 10;
                    character->hygiene -= 10;
                    character->energy -= 5;
                    printf("Moral +10, Hijyen -10, Enerji -5\n");
                } else {
                    printf("Hijyeniniz cok dusuk (20 veya alti)! Enstruman calmak icin hijyeninizi artirmaniz gerekiyor.\n");
                }
                break;

            case 2:
                printf("Dans edip eglendiniz. Kendinizi daha iyi hissediyorsunuz!\n");
                character->moral += 20;
                character->hygiene -= 15;
                character->energy -= 10;
                character->thirst -= 5;
                printf("Moral +20, Hijyen -15, Enerji -10, Susuzluk -5\n");
                break;

            case 3:
                printf("Doga yuruyusune ciktiniz. Doganin icinde moral buldunuz!\n");
                character->moral += 15;
                character->energy -= 10;
                character->thirst -= 10;
                printf("Moral +15, Enerji -10, Susuzluk -10\n");
                break;

            case 4:
                printf("Moral artirma etkinliklerinden ayrilarak ana menuye donuyorsunuz...\n");
                return;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

        if (character->moral > 100) character->moral = 100;
        if (character->moral < 0) character->moral = 0;

        if (character->hygiene > 100) character->hygiene = 100;
        if (character->hygiene < 0) character->hygiene = 0;

        if (character->energy > 100) character->energy = 100;
        if (character->energy < 0) character->energy = 0;

        if (character->thirst > 100) character->thirst = 100;
        if (character->thirst < 0) character->thirst = 0;
    }
}

void eat(Character *character) {
    int choice;
    while (1) {
        printf("\n=== Yemek Secenekleri ===\n");
        printf("1. Ekmek (Fiyat: 5 altin, Tokluk +10, Susuzluk +5, Enerji +3)\n");
        printf("2. Yahni (Fiyat: 20 altin, Tokluk +50, Susuzluk +10, Enerji +10)\n");
        printf("3. Elma (Fiyat: 3 altin, Tokluk +5, Susuzluk +2, Enerji +2)\n");
        printf("4. Ana menuye don\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (character->money >= 5) {
                    character->money -= 5;
                    character->hunger += 10;
                    character->thirst += 5;
                    character->energy += 3;
                    printf("Ekmek yediniz. Tokluk +10, Susuzluk +5, Enerji +3, Para -5\n");
                } else {
                    printf("Yeterli paraniz yok!\n");
                }
                break;
            case 2:
                if (character->money >= 20) {
                    character->money -= 20;
                    character->hunger += 50;
                    character->thirst += 10;
                    character->energy += 10;
                    printf("Yahni yediniz. Tokluk +50, Susuzluk +10, Enerji +10, Para -20\n");
                } else {
                    printf("Yeterli paraniz yok!\n");
                }
                break;
            case 3:
                if (character->money >= 3) {
                    character->money -= 3;
                    character->hunger += 5;
                    character->thirst += 2;
                    character->energy += 2;
                    printf("Elma yediniz. Tokluk +5, Susuzluk +2, Enerji +2, Para -3\n");
                } else {
                    printf("Yeterli paraniz yok!\n");
                }
                break;
            case 4:
                printf("Yemek yeme islemi sonlandiriliyor...\n");
                return;
            default:
                printf("Gecersiz secim!\n");
        }

        if (character->hunger > 100) character->hunger = 100;
        if (character->thirst > 100) character->thirst = 100;
        if (character->energy > 100) character->energy = 100;
    }
}

void drinkWater(Character *character) {

    printf("\n=== Su Icme ===\n");
    printf("Su iciyorsunuz...\n");

    character->thirst -= 30;
    character->hunger -= 5;
    character->energy += 5;

    printf("Susuzluk -30, Tokluk -5, Enerji +5\n");

    if (character->thirst > 100) character->thirst = 100;
    if (character->hunger < 0) character->hunger = 0;
    if (character->energy > 100) character->energy = 100;
}

void gatherEnergy(Character *character) {

    printf("Kisa bir mola verip enerji topluyorsunuz...\n");
    character->energy += 20;
    character->hunger += 5;
    character->sleep -= 5;

    if (character->energy > 100) character->energy = 100;
    if (character->hunger < 0) character->hunger = 0;
    if (character->sleep < 0) character->sleep = 0;

    printf("Enerji +20, Tokluk +5, Uyku -5\n");
}

void specialMoralBoost(Character *character) {

    printf("Arkadaslarinizla zaman geciriyor ve moral topluyorsunuz...\n");
    character->moral += 15;
    character->energy -= 10;

    if (character->moral > 100) character->moral = 100;
    if (character->energy < 0) character->energy = 0;

    printf("Moral +15, Enerji -10\n");
    printf("Kendinizi daha iyi hissediyorsunuz! Enerjiniz azalsa da moraliniz yukseliyor.\n");
}

void sleep(Character *character) {
    int sleepDuration;
    printf("\n=== Uyuma ===\n");
    printf("Ne kadar sure uyumak istersiniz? (1-10 saat): ");
    scanf("%d", &sleepDuration);

    if (sleepDuration < 1 || sleepDuration > 10) {
        printf("Gecersiz sure! Lutfen 1 ile 10 saat arasinda bir deger girin.\n");
        return;
    }

    character->sleep += sleepDuration * 5;
    character->energy += sleepDuration * 3;
    character->thirst += sleepDuration * 2;
    character->moral += sleepDuration * 2;

    printf("Uyudunuz: %d saat\n", sleepDuration);
    printf("Uyku +%d, Enerji +%d, Susuzluk +%d, Moral +%d\n",
           sleepDuration * 5, sleepDuration * 3, sleepDuration * 2, sleepDuration * 2);

    if (character->sleep > 100) character->sleep = 100;
    if (character->energy > 100) character->energy = 100;
    if (character->thirst < 0) character->thirst = 0;
    if (character->moral > 100) character->moral = 100;
}

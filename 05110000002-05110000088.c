#include <stdio.h>
#include <stdlib.h>
void sans_oyunlari();
int sayi_al(int,int);
void ana_menu();
void sayisal(int *,int[]);
void sans_topu(int *,int []);
void on_numara(int *, int[]);
void super_loto(int *,int []);
void siralama(int *,int );
void yer_degistir(int *, int *);
void istatistik_sayisal(int[],int[],int);
void istatistik_on_numara(int [], int[],int);
void istatistik_super(int [], int [], int);
int tekrar_sordurma();

int main()
{
    char cevap;
    char cikis;
    int secimimiz,sayisal_sayac[49]= {0},sayisal_indeks[49];
    int on_numara_sayac[80]= {0},on_numara_indeks[80];
    int super_sayac[54]= {0},super_indeks[54];
    int choosen;
    int static kazanilan_odul=0;
    int i;
    int sans_topu_sayac[34]= {0},sans_topu_indeks[34]= {0};

    unsigned besleme;//program icin genel cekirdek(besleme) degeri alma kismi//
    printf("Bir besleme degeri giriniz:");
    scanf("%u",&besleme);
    srand(besleme);


    do
    {
        ana_menu();//siraya gore islem yapmaya basliyor
        secimimiz=sayi_al(1,3);
        for (i=0; i<49; i++)//sayisal indeks'e atama yapiyor//
        {
            sayisal_indeks[i]=i+1;
        }
        for(i=0; i<80; i++)
        {
            on_numara_indeks[i]=i+1;
        }
        for(i=0; i<54; i++)
        {
            super_indeks[i]=i+1;
        }
        switch(secimimiz)
        {
        case 1:
            do//do while dongusuyle tekrar sordurma,ana menuye donme yaptýrýlýyor
            {
                sans_oyunlari();//sans oyunlari fonksiyonunu cagiriyor.//
                printf("(Toplam odulunuz:%d puan)Seciminizi giriniz:",kazanilan_odul);
                choosen=sayi_al(1,5);
                if(choosen==1)
                {
                    do
                    {
                        sayisal(&kazanilan_odul,sayisal_sayac);//sayisal fonksiyonu cagiriliyor//
                        cevap=tekrar_sordurma();
                    }
                    while(cevap=='e' || cevap=='E');

                }
                else if(choosen==2)
                {
                    do
                    {
                        sans_topu(&kazanilan_odul,sans_topu_sayac);//sans topu oyunu cagiriliyor//
                        cevap=tekrar_sordurma();
                    }
                    while(cevap=='e' || cevap=='E');

                }
                else if(choosen==3)
                {
                    do
                    {
                        on_numara(&kazanilan_odul,on_numara_sayac);//on numara cagiriliyor//
                        cevap=tekrar_sordurma();
                    }
                    while(cevap=='e' || cevap=='E');

                }
                else if(choosen==4)
                {
                    do
                    {
                        super_loto(&kazanilan_odul,super_sayac);//super loto cagiriliyor//
                        cevap=tekrar_sordurma();
                    }
                    while(cevap=='e' || cevap=='E');

                }
                else if(choosen==5)
                    break;//ana menuye donus//
            }
            while(cevap=='h' || cevap=='H');
            break;

        case 2:
            printf("sayisal icin\n");
            istatistik_sayisal(sayisal_sayac,sayisal_indeks,49);//en cok cikan sayilar yazdiriliyor//
            printf("on numara icin\n");
            istatistik_on_numara(on_numara_sayac,on_numara_indeks,80);//en cok cikan sayilar yazdiriliyor//
            printf("super loto icin\n");
            istatistik_super(super_sayac,super_indeks,54);//en cok cikan sayilar yazdiriliyor//

            break;
        case 3://programdan cikmak icin//
            do
            {
                printf("Cikmak istediginize emin misiniz(e/E/h/H)?:");
                fflush(stdin);
                scanf("%c",&cikis);
            }
            while (cikis != 'e' && cikis != 'E' && cikis!='h' && cikis!='H');
            break;
        }
    }
    while (!(cikis == 'E' || cikis == 'e'));
    return 0;
}
void ana_menu()//ana menudeki yazilari iceriyor//
{

    printf("\n    ANA MENU\n");
    printf("\n1.Sans oyunlari\n");
    printf("2.Cekilis istatistikleri\n");
    printf("3.Cikis\n");
    printf("\nLutfen seciminizi giriniz:");
}
int sayi_al(int alt_sinir, int ust_sinir)//aralik kontrolu yapiyor//
{
    int sayi;
    scanf("%d",&sayi);
    while (sayi<alt_sinir || sayi>ust_sinir)
    {
        printf("\nHatali veri girdiniz,lutfen tekrar giriniz:\n");
        scanf("%d",&sayi);
    }
    return sayi;
}
void sans_oyunlari()//sans oyunlari menusundeki yazilari iceriyor//
{
    printf("\n        SANS OYUNLARI ALT MENUSU \n");
    printf("\n1 .Sayisal loto oynama\n");
    printf("2. Sans topu oynama\n");
    printf("3. On numara oynama\n");
    printf("4. Super loto oynama\n");
    printf("5. Ana menu\n");
}
void sayisal(int *toplam_odul, int sayac[])
{
    int uretim_sayisal[6]= {0};
    int kullanici_sayisal[6]= {0};
    int sayi,i,j;
    int sayisal_tuttu_sayan=0;
    int odul=0;
    int static sayisal_toplam_odul=0;
    printf("\n    ----->SAYISAL LOTO OYNAMA<-----\n");
    for(i=0; i<6; i++)
    {
        do
        {
            printf("\n-->lutfen 1-49 arasinda bir sayi giriniz:");
            scanf("%d",&kullanici_sayisal[i]);//kullanici tahminlerini aliyor//
            if(kullanici_sayisal[i]<1 || kullanici_sayisal[i]>49)
                printf("\n!!Aralik disi deger girdiniz.\n");
        }
        while(kullanici_sayisal[i]<1 || kullanici_sayisal[i]>49);
        for(j=0; j<i; j++)
        {
            if(kullanici_sayisal[i]==kullanici_sayisal[j])//kullanici degerlerinin daha once girilip girilmedigini kontrol etmek icin//
            {
                printf("\n!!Bu sayiyi daha once girdiniz.\n");
                i--;
                break;
            }
        }
    }
    for(i=0; i<6; i++)//sayi uretimi yapiyor//
    {
        uretim_sayisal[i]=1+(rand()%49);
        for(j=0; j<i; j++)
        {
            if(uretim_sayisal[i]==uretim_sayisal[j])
            {
                uretim_sayisal[i]=1+(rand()%49);
            }
        }
    }
    for(i=0; i<6; i++)
    {


        printf("\ngirdiginiz sayilar:\n\n");
        siralama(kullanici_sayisal,6);//sayilarimizi siraliyor//
        for(i=0; i<6; i++)
        {
            printf("%d    ",kullanici_sayisal[i]);
        }
        printf("\ncikan sayilar:\n");
        siralama(uretim_sayisal,6);//cikan sayilari siraliyor//
        for(i=0; i<=5; i++)
        {
            printf("%d    ",uretim_sayisal[i]);
        }
        for (i=0; i<6; i++)//sayacimizi saydirma islemi//
        {
            sayi=uretim_sayisal[i];
            sayac[sayi-1]++;
        }
        for(i=0; i<6; i++)//dogru tahmin edilen sayiyi hesapliyor//
        {
            for(j=0; j<=5; j++)
            {
                if(uretim_sayisal[i]==kullanici_sayisal[j])
                    sayisal_tuttu_sayan++;
            }
        }


    }
    printf("\ndogru tahmin edilen sayi sayisi:%d\n",sayisal_tuttu_sayan);


    if(sayisal_tuttu_sayan==6)//odul hesaplama basliyor//
    {
        odul=256;
        *toplam_odul+=256;
        sayisal_toplam_odul=sayisal_toplam_odul+odul;

    }
    else if(sayisal_tuttu_sayan==5)
    {
        odul=128;
        *toplam_odul+=128;
        sayisal_toplam_odul=sayisal_toplam_odul+odul;
    }
    else if(sayisal_tuttu_sayan==4)
    {
        odul=64;
        *toplam_odul+=64;
        sayisal_toplam_odul=sayisal_toplam_odul+odul;
    }
    else if(sayisal_tuttu_sayan==3)
    {
        odul=32;
        *toplam_odul+=32;
        sayisal_toplam_odul=sayisal_toplam_odul+odul;
    }
    else if(sayisal_tuttu_sayan<3)
    {
        odul=0;
        *toplam_odul+=0;
        sayisal_toplam_odul=sayisal_toplam_odul+odul;
    }
    if(odul==0)
    {
        printf("Maalesef odul kazanamadiniz\n");
    }
    else
    {
        printf("%d puan odul kazandiniz\n",odul);
    }

    printf("\n sayisal toplam odulu:%d\n",sayisal_toplam_odul);
    printf("\n Butun oyunlardan elde edilen toplam odul:%d\n",*toplam_odul);



}
void sans_topu(int *toplam_odul,int sayac[])
{
    int uretim_sans[5];
    int tek;
    int kullanici_sans_topu34[5]= {0},kullanici_sans_topu14[1]= {0};
    int i,j;
    int sans_topu_5tuttu_sayan=0;
    int sans_topu_1tuttu_sayan=0;
    int odul=0;
    int sayi;
    int static sans_toplam_odul=0;
    printf("\n    -----SANS TOPU OYNAMA<-----\n");
    for(i=0; i<5; i++)
    {
        do
        {
            printf("\n-->lutfen 1-34 arasinda bir sayi giriniz:");//kullanicidan tahminler aliniyor//
            scanf("%d",&kullanici_sans_topu34[i]);
            if(kullanici_sans_topu34[i]<1 || kullanici_sans_topu34[i]>34)
                printf("!!\nAralik disi sayi girdiniz\n");

        }
        while(kullanici_sans_topu34[i]<1 || kullanici_sans_topu34[i]>34);

        for(j=0; j<i; j++)//kullanici degerleri onceki degerleri ile kontrol ediliyor//
        {
            if(kullanici_sans_topu34[i]==kullanici_sans_topu34[j])
            {
                printf("\n!!Bu sayiyi daha once girdiniz\n");
                i--;
                break;
            }
        }
    }
    do
    {
        printf("\n\n-->lutfen 1-14 arasinda bir sayi giriniz:\n");//+1 sayisi aliniyor//
        scanf("%d",&kullanici_sans_topu14[0]);
        if(kullanici_sans_topu14[0]<1 || kullanici_sans_topu14[0]>14)
            printf("\n!!Aralik disi sayi girdiniz\n");

    }
    while(kullanici_sans_topu14[0]<1 || kullanici_sans_topu14[0]>14);

    for(i=0; i<5; i++)//makine tarafýndan sayilar uretiliyor//
    {
        uretim_sans[i]=1+(rand()%34);
        for(j=0; j<i; j++)
        {
            if(uretim_sans[i]==uretim_sans[j])
            {
                uretim_sans[i]=1+(rand()%34);
            }
        }
    }
    tek=1+(rand()%14);//+1 sayi uretiliyor//

    for(i=0; i<5; i++)
    {


        printf("\ngirdiginiz 5+1 sayi:\n");
        siralama(kullanici_sans_topu34,5);//kullanicinin sayilari siralaniyor//
        for(i=0; i<5; i++)
        {
            printf("%d    ",kullanici_sans_topu34[i]);
        }
        for (i=0; i<5; i++)
        {
            sayi=uretim_sans[i];
            sayac[sayi-1]++;
        }
        printf("+%d    ",kullanici_sans_topu14[0]);

        printf("\ncikan 5+1 sayi:\n");
        siralama(uretim_sans,5);//makinenin degerli siralaniyor//
        for(i=0; i<5; i++)
        {
            printf("%d    ",uretim_sans[i]);
        }



        printf("+%d    ",tek);

        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(uretim_sans[i]==kullanici_sans_topu34[j])
                    sans_topu_5tuttu_sayan++;
            }
        }
        if(tek==kullanici_sans_topu14[0])
            sans_topu_1tuttu_sayan++;
    }
    printf("\ndogru tahmin edilen sayi sayisi:%d\n",sans_topu_5tuttu_sayan);
    printf("\ndogru tahmin edilen +1 sayi sayisi:%d\n",sans_topu_1tuttu_sayan);

    if(sans_topu_5tuttu_sayan==5 && sans_topu_1tuttu_sayan==1)//odul hesaplaniyor//
    {
        odul=256;
        *toplam_odul+=256;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==5)
    {
        odul=128;
        *toplam_odul+=128;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==4 && sans_topu_1tuttu_sayan==1)
    {
        odul=64;
        *toplam_odul+=64;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==4)
    {
        odul=32;
        *toplam_odul+=32;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==3 && sans_topu_1tuttu_sayan==1)
    {
        odul=16;
        *toplam_odul+=16;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==3)
    {
        odul=8;
        *toplam_odul+=8;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==2 && sans_topu_1tuttu_sayan==1)
    {
        odul=4;
        *toplam_odul+=4;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==1 && sans_topu_1tuttu_sayan==1)
    {
        odul=2;
        *toplam_odul+=2;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    else if(sans_topu_5tuttu_sayan==1 || sans_topu_5tuttu_sayan==2)
    {
        odul=0;
        *toplam_odul+=0;
        sans_toplam_odul=sans_toplam_odul+odul;
    }
    if(odul==0)
    {
        printf("\nMaalesef odul kazanamadiniz");
    }
    else
    {
        printf("%d puan odul kazandiniz",odul);
    }

    printf("\n sans topundan elde edilen toplam odul:%d\n",sans_toplam_odul);
    printf("\n Butun oyunlardan elde edilen toplam odul:%d\n",*toplam_odul);//odulu yazdiriyoruz//
}

void super_loto(int *toplam_odul, int sayac[])
{
    int uretim_super[6]= {0};//dizilerimiz sifirlaniyor//
    int kullanici_super_loto[6]= {0};
    int i,j,sayi;
    int super_loto_tuttu_sayan=0;
    int odul=0;
    int static super_toplam_odul=0;
    printf("\n    ----->SUPER LOTO OYNAMA<-----\n");
    for(i=0; i<6; i++)
    {
        do
        {
            printf("\n-->lutfen 1-54 arasinda bir sayi giriniz:");
            scanf("%d",&kullanici_super_loto[i]);
            if(kullanici_super_loto[i]<1 || kullanici_super_loto[i]>54)
                printf("!!\nAralik disi sayi girdiniz\n");

        }
        while(kullanici_super_loto[i]<1 || kullanici_super_loto[i]>54);

        for(j=0; j<i; j++)
        {
            if(kullanici_super_loto[i]==kullanici_super_loto[j])
            {
                printf("\n!!Bu sayiyi daha once girdiniz\n");
                i--;
                break;
            }
        }
    }
    for(i=0; i<6; i++)//makine sayilarimizi uretiyor//
    {
        uretim_super[i]=1+(rand()%54);
        for(j=0; j<i; j++)
        {
            if(uretim_super[i]==uretim_super[j])
            {
                uretim_super[i]=1+(rand()%54);
            }
        }
    }
    for(i=0; i<6; i++)
    {


        printf("\ngirdiginiz sayilar:\n");
        siralama(kullanici_super_loto,6);//kullanici sayilari siralaniyor//
        for(i=0; i<6; i++)
        {
            printf("%d    ",kullanici_super_loto[i]);
        }
        printf("\ncikan sayilar:\n");
        siralama(uretim_super,6);//uretilen sayilar siralaniyor//
        for(i=0; i<=5; i++)
        {
            printf("%d    ",uretim_super[i]);
        }
        for (i=0; i<6; i++)
        {
            sayi=uretim_super[i];
            sayac[sayi-1]++;
        }
        for(i=0; i<6; i++)
        {
            for(j=0; j<=5; j++)
            {
                if(uretim_super[i]==kullanici_super_loto[j])
                    super_loto_tuttu_sayan++;
            }
        }
    }
    printf("\ndogru tahmin edilen sayi sayisi:%d\n",super_loto_tuttu_sayan);


    if(super_loto_tuttu_sayan==6)//odul hesaplaniyor//
    {
        odul=256;
        *toplam_odul+=256;
        super_toplam_odul=super_toplam_odul+odul;
    }
    else if(super_loto_tuttu_sayan==5)
    {
        odul=128;
        *toplam_odul+=128;
        super_toplam_odul=super_toplam_odul+odul;
    }
    else if(super_loto_tuttu_sayan==4)
    {
        odul=64;
        *toplam_odul+=64;
        super_toplam_odul=super_toplam_odul+odul;
    }
    else if(super_loto_tuttu_sayan==3)
    {
        odul=32;
        *toplam_odul+=32;
        super_toplam_odul=super_toplam_odul+odul;
    }
    else if(super_loto_tuttu_sayan<3)
    {
        odul=0;
        *toplam_odul+=0;
        super_toplam_odul=super_toplam_odul+odul;
    }
    if(odul==0)
    {
        printf("Maalesef odul kazanamadiniz\n");
    }
    else
    {
        printf("%d puan odul kazandiniz\n",odul);
    }

    printf("\n super lotodan elde edilen toplam odul:%d\n",super_toplam_odul);
    printf("\n Butun oyunlardan elde edilen toplam odul:%d\n",*toplam_odul);

}

void on_numara(int *toplam_odul,int sayac[])
{
    int uretim_on_numara[22];
    int kullanici_on_numara[10]= {0};
    int i,j;
    int on_numara_tuttu_sayan=0;
    int odul=0;
    int sayi;
    int static on_numara_toplam_odul=0;
    printf("\n    ----->ON NUMARA OYNAMA<-----\n");
    for(i=0; i<10; i++)
    {
        do
        {
            printf("\n-->lutfen 1-80 arasinda bir sayi giriniz:");
            scanf("%d",&kullanici_on_numara[i]);//kullanici tahminleri alniyor//
            if(kullanici_on_numara[i]<1 || kullanici_on_numara[i]>80)
                printf("!!\nAralik disi sayi girdiniz\n");

        }
        while(kullanici_on_numara[i]<1 || kullanici_on_numara[i]>80);
        for(j=0; j<i; j++)
        {
            if(kullanici_on_numara[i]==kullanici_on_numara[j])
            {
                printf("\n!!Bu sayiyi daha once girdiniz\n");
                i--;
                break;
            }
        }
    }
    for(i=0; i<22; i++)//makine degerleri uretiliyor//
    {
        uretim_on_numara[i]=1+(rand()%80);
        for(j=0; j<i; j++)
        {
            if(uretim_on_numara[i]==uretim_on_numara[j])
            {
                uretim_on_numara[i]=1+(rand()%80);
            }
        }
    }
    for(i=0; i<10; i++)
    {


        printf("\nirdiginiz sayilar:\n\n");
        siralama(kullanici_on_numara,10);//kullanicinin degerleri siralaniyor//
        for(i=0; i<10; i++)
        {
            printf("%d    ",kullanici_on_numara[i]);
        }
        printf("\ncikan sayilar:\n\n");
        siralama(uretim_on_numara,22);//makine degerleri siralaniyor//
        for(i=0; i<=21; i++)
        {
            printf("%d    ",uretim_on_numara[i]);
        }
        for (i=0; i<=21; i++)
        {
            sayi=uretim_on_numara[i];
            sayac[sayi-1]++;
        }
        for(i=0; i<22; i++)//kac deger tutturuldugu kontrol ediliyor//
        {
            for(j=0; j<=9; j++)
            {
                if(uretim_on_numara[i]==kullanici_on_numara[j])
                    on_numara_tuttu_sayan++;
            }
        }
    }
    printf("\n\ndogru tahmin edilen sayi sayisi:%d\n",on_numara_tuttu_sayan);


    if(on_numara_tuttu_sayan==10)//oduller hesaplaniyor//
    {
        odul=256;
        *toplam_odul+=256;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan==9)
    {
        odul=128;
        *toplam_odul+=128;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan==8)
    {
        odul=64;
        *toplam_odul+=64;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan==7)
    {
        odul=32;
        *toplam_odul+=32;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan==6)
    {
        odul=16;
        *toplam_odul+=16;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan==0)
    {
        odul=8;
        *toplam_odul+=8;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    else if(on_numara_tuttu_sayan<6 && on_numara_tuttu_sayan!=0)
    {
        odul=0;
        *toplam_odul+=0;
        on_numara_toplam_odul=on_numara_toplam_odul+odul;
    }
    if(odul==0)
    {
        printf("Maalesef odul kazanamadiniz\n");
    }
    else
    {
        printf("%d puan odul kazandiniz\n",odul);
    }

    printf("\n on numara oyunundan elde edilen toplam odul:%d\n",on_numara_toplam_odul);
    printf("\n  Butun oyunlardan elde edilen toplam odul:%d\n",*toplam_odul);

}
void siralama(int *sayisal,int a)//siralama fonksiyonumuz//
{
    int i, j, temp;
    for (i=0; i<a-1; i++)
    {
        for (j =0; j<a-1; j++)
        {
            if (sayisal[j] > sayisal[j+1])
            {
                temp = sayisal[j];
                sayisal[j] = sayisal[j+1];
                sayisal[j+1] = temp;
            }
        }
    }
}

void istatistik_sayisal (int V[], int I[], int el_say)//istatistik icin parametre islemleri asagida yapilacak//
{
    int sayisal_sayac[el_say],sayisal_indeks[el_say],a,b;
    for (a=0; a<el_say; a++)
    {
        sayisal_sayac[a]=V[a];
        sayisal_indeks[a]=I[a];
    }
    for (a=0; a<el_say; a++)
    {
        for (b=a+1; b<el_say; b++)
        {
            if (sayisal_sayac[a]<sayisal_sayac[b])
            {
                yer_degistir(&sayisal_sayac[a],&sayisal_sayac[b]);
                yer_degistir(&sayisal_indeks[a],&sayisal_indeks[b]);
            }
        }
    }
    for(a=0; a<6; a++) //son cikanla ayni cikan varsa yazdirma//
    {
        printf("%d (%d kere cikti)\n",sayisal_indeks[a],sayisal_sayac[a]);
        while (sayisal_sayac[a]=sayisal_sayac[a+1])
        {
            printf("%d (%d kere cikti)\n",sayisal_indeks[a+1],sayisal_sayac[a+1]);
            a++;
        }
    }
    printf("\n");
}
void istatistik_on_numara(int V[],int I[],int el_say)//istatistik icin parametre islemleri asagida yapilacak//

{
    int on_numara_sayac[el_say],on_numara_indeks[el_say],a,b;
    for (a=0; a<el_say; a++)
    {
        on_numara_sayac[a]=V[a];
        on_numara_indeks[a]=I[a];
    }
    for (a=0; a<el_say; a++)
    {
        for (b=a+1; b<el_say; b++)
        {
            if (on_numara_sayac[a]<on_numara_sayac[b])
            {
                yer_degistir(&on_numara_sayac[a],&on_numara_sayac[b]);
                yer_degistir(&on_numara_indeks[a],&on_numara_indeks[b]);
            }
        }
    }
    for(a=0; a<10; a++) //son cikanla ayni cikan varsa yazdirma
    {
        printf("%d (%d kere cikti)\n",on_numara_indeks[a],on_numara_sayac[a]);
        while (on_numara_sayac[a]=on_numara_sayac[a+1])
        {
            printf("%d (%d kere cikti)\n",on_numara_indeks[a+1],on_numara_sayac[a+1]);
            a++;
        }
    }
}
void istatistik_super(int V[], int I[], int el_say)//istatistik icin parametre islemleri asagida yapilacak//
{
    int super_sayac[el_say],super_indeks[el_say],a,b;
    for (a=0; a<el_say; a++)
    {
        super_sayac[a]=V[a];
        super_indeks[a]=I[a];
    }
    for (a=0; a<el_say; a++)
    {
        for (b=a+1; b<el_say; b++)
        {
            if (super_sayac[a]<super_sayac[b])
            {
                yer_degistir(&super_sayac[a],&super_sayac[b]);
                yer_degistir(&super_indeks[a],&super_indeks[b]);
            }
        }
    }
    for(a=0; a<6; a++) //son cikanla ayni cikan varsa yazdirma
    {
        printf("%d (%d kere cikti)\n",super_indeks[a],super_sayac[a]);
        while (super_sayac[a]=super_sayac[a+1])
        {
            printf("%d (%d kere cikti)\n",super_indeks[a+1],super_sayac[a+1]);
            a++;
        }
    }
    printf("\n");
}

void yer_degistir(int *sayi1, int *sayi2)//dizileri istatistikte yer degistirmek icin yer degistirme fonksiyonu//
{
    int gecici_sayi;

    gecici_sayi=*sayi1;
    *sayi1=*sayi2;
    *sayi2=gecici_sayi;

    return;
}
int tekrar_sordurma()//oyunlari tekrar oynamak isteyip istemedigimizi soran fonksiyon//
{
    char cevap;
    printf("\ntekrar oynamak ister misiniz?:(e/E/h/H)\n");
    scanf("%c",&cevap);
    cevap=getchar();
    return cevap;
}


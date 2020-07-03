#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char ime[32];
    char prezime[32];
    int index;
};

int num_st = 0;
struct student st[200];
struct student st_tmp;



void novi_student (){
    FILE * fp;
    struct student st_tmp;

    printf("Unesi informacije:\n");

    printf("Unos - Ime: ");
    scanf("%s", st_tmp.ime);

    printf("Unos - Prezime: ");
    scanf("%s", st_tmp.prezime);

    printf("Unos - Index: ");
    scanf("%d", &st_tmp.index);

    printf("%s %s %d", st_tmp.ime, st_tmp.prezime, st_tmp.index );
    st[num_st] = st_tmp;
    num_st++;


}

void pretraga(){

    char pretrazi[32];

    printf("Unesi pretragu:\n");
    scanf("%s", &pretrazi);

    for(int i=0; i<num_st; i++){

        if ( strncmp(pretrazi, st[i].prezime, strlen(pretrazi) ) == 0){  // string number compare
            printf("%s %s %d\n", st[i].ime, st[i].prezime, st[i].index );
        }

    }

}

void spisak_studenata (){

    for(int i=0; i<num_st; i++){
        printf("\n %d %s %s %d", i+1, st[i].ime, st[i].prezime, st[i].index);
    }

}

void izmeni_studenta(){


    int rednibr;
    printf("\nUnesi redni broj:");
    scanf ("%d",&rednibr);

    if (0<rednibr<=num_st){
        printf("-------------------\n");

        printf("\n-------------------\n");
        printf("1. Izmenite Ime\n");
        printf("2. Izmenite Prezime\n");
        printf("3. Izmenite broj index-a\n");

        int opcija;
        int index;
        printf("Izaberite opciju:");
        scanf ("%d",&opcija);

        switch(opcija){

            case 1:

                printf("Unos - Ime: ");
                scanf("%s", st[rednibr-1].ime);
                break;

            case 2:
                printf("Unos - Prezime: ");
                scanf("%s", st[rednibr-1].prezime);
                break;

            case 3:
                printf("Unos - Broj index-a: ");
                scanf("%d", &st[rednibr-1].index);
                //scanf("%d", index);
                //st[rednibr-1].index = atoi(index);
                break;

            default:
                printf("\n---------- Uneli ste pogresan broj ---------\n");

        }
    }// if petlja

}



void save_and_exit (){

    FILE *fp;


    fp = fopen ("studenti.txt","w");

    for(int i=0; i<=num_st-1; i++){

        fprintf (fp, "%s\n", st[i].ime);
        fprintf (fp, "%s\n", st[i].prezime);
        fprintf (fp, "%d\n", st[i].index);

    }


    fclose (fp);


    printf("NOVI STUDENTI SU SACUVANI U .TXT FILE!!!\n");

}


int main() {

    char meni;
    int running = 1;



    char buffer[32];
    FILE * fp;

    fp = fopen ("studenti.txt","r");
    if (fp == NULL){
        printf("Cannot open file \n");
        exit(0);
    }

    int korak = 0;

    while(fgets(buffer, 32, (FILE*) fp)) {
        strtok(buffer, "\n"); // izbrisi nove redove

        if(buffer==""){
            break;
        }

        korak++;

        if(korak==1){
            strcpy(st_tmp.ime , buffer);  // kopiranje stringa u string
        }
        if(korak==2){
            strcpy(st_tmp.prezime , buffer);
        }
        if(korak==3){
            st_tmp.index = atoi(buffer); // array to int

            st[num_st] = st_tmp;
            num_st++;
            korak = 0;
        }

    }
    fclose(fp);



    while(running){


        printf("\n\n\n-----------------------------------------\n");
        printf("----------------- MENU ------------------\n");
        printf("-----------------------------------------\n");
        printf("1) Unos novog studenta\n");
        printf("2) Pretraga studenta po prezimenu\n");
        printf("3) Ispis svih studenata\n");
        printf("4) Korigovanje podataka o studentu\n");
        printf("5) Izlaz (sacuvaj i izadji)\n");


        fseek(stdin,0,SEEK_END);
        scanf("%c", &meni);



        switch(meni){
            case '1':
                novi_student();
                break;

            case '2':
                pretraga();
                break;

            case '3':
                spisak_studenata();
                break;

            case '4':

                spisak_studenata();
                izmeni_studenta();

                break;

            case '5':
                running = 0;
                save_and_exit();
                break;

            default:
                printf("Uneli ste pogresan broj!");
        }

    }


    return 0;
}



//ledica
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
        FILE* fp;
        float percentage;
        long int period = 20000L;
        sscanf(argv[1],"%f",&percentage); 
		
		  int rval;
		  FILE *fp1;
		  FILE *fp2;
		  char *str;
		  int tval1,tval2;
		  size_t num_of_bytes = 1;
		  
		  
        while(1)
        {
                
		//Citanje vrednosti prvog tastera
         fp1 = fopen ("/sys/class/gpio/gpio956/value", "r");
         if(fp1==NULL)
         puts("Problem pri otvaranju 1. fajla");
			
			
		str = (char *)malloc(num_of_bytes+1);
		getline(&str, &num_of_bytes, fp1);		
				
		if(fclose(fp1))
        puts("Problem pri zatvaranju 1. fajla");		
				
		sscanf(str, "%d", &tval1);
		free(str);	

		
		//Citanje vrednosti drugog tastera
		fp2 = fopen ("/sys/class/gpio/gpio957/value", "r");
		 if(fp2==NULL)
			 puts("Problem pri otvaranju 2. fajla");

		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp2); 

		 if(fclose(fp2))
			 puts("Problem pri zatvaranju 2. fajla");

		sscanf(str, "%d", &tval2); 
		free(str);
		
		
		
		//logika 
		if(tval1 == 1) { //pomocna?
			if(percentage < 1) {
				percentage += 0.1;
			} 
		}
		
		if(tval2 == 1) { //pomocna?
			percentage -= 0.1;
		}
		
		if(percentage > 1) {
			//limit 100%
			percentage = 1;
		}
		
		if(percentage < 0) {
			//ne radi dioda
			percentage = 0;
		}
		
		
		
		
				//ledica
				fp = fopen("/proc/myled", "w");
                if(fp == NULL)
                {
                        printf("Cannot open /proc/myled for write\n");
                        return -1;
                }
                fputs("0x0F\n", fp);
                fclose(fp);
                usleep(percentage*period);

                fp = fopen("/proc/myled", "w");
                if(fp == NULL)
                {
                        printf("Cannot open /proc/myled for write\n");
                        return -1;
                }
                fputs("0x00\n", fp);
                fclose(fp);
                usleep((1-percentage)*period);
				
				
				
				
		//Ispis procitanih vrednosti
		printf("\n:Taster1: %d		Taster2: %d", tval1, tval2);
		usleep(100000);
		
	
				
				
        }
        return 0;
}

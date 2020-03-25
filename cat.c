/*alperen inci 18120205016
 * asli gul inan 18120205022
 * nursena kilic 18120205014
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int down=1;
int metinoku(FILE *f){
char c;
while((c = fgetc(f)) != EOF){
		
		printf("%c", c);
		
	}
	
	printf("\n");
	fclose(f);
	
	return 0;
}

int metinkopyala(FILE *f, FILE *f2){
char c; 
	while((c = fgetc(f)) != EOF){
	
		fputc(c, f2);
	}
	
	return 0;
}

int main(int argc, char *argv[]){
int t=0;	
int m=0;
	for(int i = 1; i<argc; i++){
		if((strcmp(argv[i], ">")) == 0){
			t=1;
			m=i;
	}
		if((strcmp(argv[1],"-h")) == 0){ 
				t=2;
	}
}
				
			
if(t == 0){		
for(int j=1; j<argc; j++){
		if(((strcmp(argv[1], "-b")) == 0) || ((strcmp(argv[1], "-n")) == 0)){
			j=2;
		
		if(strcmp(argv[1],"-n")==0){
			for(int i=2;i<argc;i++){
				FILE *f=fopen(argv[i],"r+");
				if(f==NULL){
					return 0;
				} 
				char s[100][250];
				while(fgets (s[down],250,f) != NULL && down <100){
					printf("%d-",down);
					printf("%s.250s",s[down]);
					down++;
				}
				printf("\n");
			}
		}
		else if(strcmp(argv[1],"-b") == 0){
			for (int i=2;i<argc;i++){
				FILE *f=fopen(argv[i],"r+");
				if(f==NULL){
					return 0;
				}
				char s[100][250];
				while(fgets(s[down],250,f)!= NULL && down <100){
				if((strcmp(s[down],"\t")!=0) && (strcmp(s[down],"\n") != 0) && (strcmp(s[down]," ") != 0)){
					printf("%d",down);
					printf("%.250s",s[down]);
					down++;
				}
				else{
					printf("%.250s",s[down]);
				}
			}
			printf("\n");
		}
	}
}
else{								
FILE *f = fopen(argv[j], "r+");
	 if(f == NULL){
		printf("Dosyada veri bulunamadi !");
			return 0;
			}
			metinoku(f);
		}
		return 0;		 	
	}		
}	
	
if(t == 1){		
	if(m == 1){
	FILE *f = fopen(argv[2], "w");
	char e;
	while((e = fgetc(stdin)) != EOF){
	fputc(e, f);				
			
	 }			
	  return 0;
}
   else if(m == argc-1){ 
		printf(" operator kullanim hatasi.\n");
		printf("bu operator cat file.txt \">\" file2.txt seklinde veya cat file.txt file2.txt \">\" file3.txt seklinde kullanilir..");
			return 0;
		}
    else{
	    for(int l=1; l<m; l++){
		if(((strcmp(argv[1], "-b")) == 0) || ((strcmp(argv[1], "-n")) == 0)){
			l=2;
	    if(strcmp(argv[1],"-n")==0){
			for(int i=2;i<argc;i++){
				FILE *f = fopen(argv[i], "r"); 
				FILE *f2= fopen(argv[argc-1],"w");
				if(f==NULL){
					return 0;
				}
				char s[100];
				while(fgets(s,100,f)!=NULL){
					  fprintf(f2,"%d-",down);
					  fprintf(f2,"%.250s", s);
					  down++;
				}
				fclose(f);
				return 0;
		 }
	  }
}  
else{	    			  			
FILE *f, *f2;
f = fopen(argv[l], "r+");
f2 = fopen(argv[argc-1], "w+");
         
           metinkopyala(f, f2);
			
				return 0;
	    }
     }
  }
}	
if(t == 2){
   if(argv[2] != NULL){
		printf("bu opsiyon herhangi bir dosya ile kullanilamaz. \n"
				   "bu opsiyonu sadece cat progmininin nasıl kullanilmasi gerektigini gosterir");
	    }
				
        else{
			   printf(" cat programi dosyalari okumayi ve kopyalamayi saglar. \">\" operatorunu de kullanarak cesitli islemler yapabilirsiniz."
				     " cat \">\" file.txt yazarak komut satirindan giris yapabilirsiniz.Bu islemide ctrl z komutuyla durdurabilirsiniz."
				     "aynı zamanda \">\" operatorunden once kullandiginiz dosyalari bir sonrakine kopyalayabilirsiniz."
				     "yanlis kullanim yaparsaniz hata mesaji alirsiniz" );
		}


		return 0;
	}
}
	




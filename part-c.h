#include <string.h> 
#include <math.h>
struct route {
    char startpoint[50];
    int length;
    int ypsan;
    int ypskat;
    int maxyps;
    int minyps;
    char endpoint[50];
};
void shortData(struct route A[500],int n){
    int i,j;
    struct route temp;
    for (i=0;i<n-1;i++){
        for (j=0; j< (n-1-i);j++){
            if (A[j].length < A[j + 1].length){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        
    }
}
struct route* readFromInput(int* a){
    static struct route A[500];
    int N,i;
    scanf("%d",&N);
    *a=N;
    for (i=0;i<N;i++){
        scanf(" ");
        fgets(A[i].startpoint,50,stdin);
        A[i].startpoint[strcspn(A[i].startpoint,"\n")]='\0';
        scanf("%d %d %d %d %d",&A[i].length,&A[i].ypsan,&A[i].ypskat,&A[i].maxyps,&A[i].minyps);
        scanf(" ");
        fgets(A[i].endpoint,50,stdin);
        A[i].endpoint[strcspn(A[i].endpoint,"\n")]='\0';
    }
    shortData(A,N);//expeeeeeeeer
    return A;

}

int time_walk(int length, int ypsan){
    return (round((length*1.0/65)+(ypsan*1.0/10)));
}

float time_walk_2(int length, int ypsan){
    return ((length*1.0/65)+(ypsan*1.0/10));
}

void printData(struct route A[500],int n){
    int i;
    for (i=0;i<n;i++){
        printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
        printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
        printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
        printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
        printf("\n");
        if (strcmp(A[i].startpoint,A[i].endpoint)!=0){
            printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
            printf("\n");  
        }
    }
}



void findShort(struct route A[500],int n){
    int L,i;
    scanf("%d",&L);
    for (i=0;i<n;i++){
        if(A[i].length<=L){
                printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
                printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
                printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
                printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
                printf("\n");
                if (strcmp(A[i].startpoint,A[i].endpoint)!=0){
                    printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
                    printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
                    printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
                    printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
                    printf("\n");
        }
        }
    }
    
}


void findLocation(struct route A[500],int n){
    int i;
    char place[50];
    fgets(place,50,stdin);
    place[strcspn(place,"\n")]='\0';
    for (i=0;i<n;i++){
        if (strcmp(A[i].startpoint,place)==0){
            printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
            printf("\n");
        }
        else if (strcmp(A[i].endpoint,place)==0){
            printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
            printf("\n");
            
        }
    }
}

void findUpHill(struct route A[500],int n){
    int i;
    for (i=0;i<n;i++){
        if (A[i].ypsan>A[i].ypskat){
            printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
            printf("\n");
        }
        else if (A[i].ypskat>A[i].ypsan){
            printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
            printf("\n");
        }
    }
}

void findDownHill(struct route A[500],int n){
    int i;
    for (i=0;i<n;i++){
        if (A[i].ypskat>A[i].ypsan){
            printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
            printf("\n");
        }
        else if(A[i].ypsan>A[i].ypskat){
            printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
            printf("\n");            
        }
    }
}

void findAltitude(struct route A[500],int n){
    int i,min,max;
    scanf("%d %d",&min,&max);
    for (i=0;i<n;i++){
        if(A[i].minyps>=min && A[i].maxyps<=max){
                printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
                printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
                printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
                printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
                printf("\n");
                if (strcmp(A[i].startpoint,A[i].endpoint)!=0){
                    printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
                    printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
                    printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
                    printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
                    printf("\n");
        }
    }
}
}

void findTimely(struct route A[500],int n){
    int i,T;
    scanf("%d",&T);
    for (i=0;i<n;i++){
        if (time_walk(A[i].length,A[i].ypsan)<=T){
            printf("From %s to %s\n",A[i].startpoint,A[i].endpoint);
            printf("Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
            printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
            printf("\n");
        }
        if (strcmp(A[i].startpoint,A[i].endpoint)!=0){
            if (time_walk_2(A[i].length,A[i].ypskat)<=T){
                printf("From %s to %s\n",A[i].endpoint,A[i].startpoint);
                printf("Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
                printf("Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
                printf("Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
                printf("\n");
            
        }
        
    }
}
}

struct route* readFromFile(int* a){
    static struct route A[500];
    char Strt[51];
    fgets(Strt,50,stdin);
    Strt[strcspn(Strt,"\n")]='\0';
    FILE *S;
    int N,i;
    S = fopen(Strt,"r");
    if (S!=NULL){
        fscanf(S,"%d",&N);
        *a=N;
        for (i=0;i<N;i++){
        fscanf(S," ");
        fgets(A[i].startpoint,50,S);
        A[i].startpoint[strcspn(A[i].startpoint,"\n")]='\0';
        fscanf(S,"%d",&A[i].length);
        fscanf(S,"%d",&A[i].ypsan);
        fscanf(S,"%d",&A[i].ypskat);
        fscanf(S,"%d",&A[i].maxyps);
        fscanf(S,"%d",&A[i].minyps);
        fscanf(S," ");
        fgets(A[i].endpoint,50,S);
        A[i].endpoint[strcspn(A[i].endpoint,"\n")]='\0';
    }
    shortData(A,N);
    fclose(S);
    }
    return A;
}


void saveData(struct route A[500], int n){
    char Strt[51];
    fgets(Strt,50,stdin);
    Strt[strcspn(Strt,"\n")]='\0';
    FILE *S;
    int i;
    S = fopen(Strt,"w");
    if (S!=NULL){
        for (i=0;i<n;i++){
        fprintf(S,"From %s to %s\n",A[i].startpoint,A[i].endpoint);
        fprintf(S,"Uphill %d, Downhill %d\n",A[i].ypsan,A[i].ypskat);
        fprintf(S,"Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
        fprintf(S,"Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypsan));
        fprintf(S,"\n");
        if (strcmp(A[i].startpoint,A[i].endpoint)!=0){
            fprintf(S,"From %s to %s\n",A[i].endpoint,A[i].startpoint);
            fprintf(S,"Uphill %d, Downhill %d\n",A[i].ypskat,A[i].ypsan);
            fprintf(S,"Max altitude %d, Min altitude %d\n",A[i].maxyps,A[i].minyps);
            fprintf(S,"Length %d, Estimated time %d min\n",A[i].length,time_walk(A[i].length,A[i].ypskat));
            fprintf(S,"\n");  
        }
    }
    fclose(S);
    }
}
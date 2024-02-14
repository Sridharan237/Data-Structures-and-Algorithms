#include<stdio.h>

//structure declaration
struct student{
       char name[15];
       int pm;
       int cm;
       int mm;
       float cutoff;
       int rank;
};

int main(){
    int n,count;
    printf("Enter the no. of students:");
    scanf("%d",&n);

    struct student s[n];

    for(int i=0;i<n;i++){
        printf("Enter the student name:");
        scanf("%s",s[i].name);
        printf("Enter the physics mark:");
        scanf("%d",&s[i].pm);
        printf("Enter the chemistry mark:");
        scanf("%d",&s[i].cm);
        printf("Enter the maths mark:");
        scanf("%d",&s[i].mm);

        s[i].cutoff = s[i].pm/2 + s[i].cm/2 + s[i].mm;
    }
    for(int i=0;i<n;i++){
        count = 0;
        for(int j=0;j<n-1;i++){
            if(s[i].cutoff<s[j].cutoff){
                  count++;
              }
          }
        s[i].rank=count;
     }
    printf("\n\n\n");
    for(int i=0;i<n;i++){
        printf("student name: %s\n",s[i].name);
        printf("physics mark: %d\n",s[i].pm);
        printf("chemistry mark: %d\n",s[i].cm);
        printf("maths mark: %d\n",s[i].mm);
        printf("Cutoff: %.0f\n\n\n",s[i].cutoff);
        printf("Rank: %d\n\n\n",s[i].rank);
    }


}

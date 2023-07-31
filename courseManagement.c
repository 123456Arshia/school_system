//
//  main.c
//  new day new life
//
//  Created by Arshia Taghavinejad on 2023-01-22.
//

#include <stdio.h>
#include <string.h>
#define max_st 150
#define max_co 100
#define max_prof 150
#define max_per 300
int i=0,c=0,z=0,t=0,q=0,qq=0;
struct student{
    char name[50];
    char lname[50];
    int sd;
    char minor[5];
    char pass[40];
    char vahed[10];
    int p_vahed;
}st[max_st];
struct course{
    char course_code[10];
    char course_name[30];
    int point;
}co[max_co];
struct prof{
    char pname[50];
    
    char pl[50];
    int os;
    char role[30];
    char minor[5];
    char pass[40];
    char vahed[10];
}pi[max_prof];
struct authp{
    int username;
    char pass[40];
    
}atp[max_per];
struct auth{
    int username;
    char pass[40];
    
}at[max_per];
void get_c(){
    FILE *stud;
    if((stud=fopen("courses.txt", "r"))==NULL){
        puts("file did not opend");
    }else{
        while (!feof(stud)) {
            
            fscanf(stud, "%s , %s , %d",co[c].course_code,co[c].course_name,&co[c].point);
            c++;
        }
    }c--;
    fclose(stud);
}
    void get_st(){
    FILE *stud,*auth;
        auth=fopen("auth.txt", "r");
    if((stud=fopen("student.txt", "r"))==NULL){
        puts("file did not opend");
    }else{
        while (!feof(stud)) {
            
            fscanf(stud, "%s , %s , %d , %s",st[i].name,st[i].lname,&st[i].sd,st[i].minor);
            
            i++;
        }
        int yy=0;
        while (!feof(auth)) {
            fscanf(auth, "%d %s",&at[yy].username,at[yy].pass);
           
            yy++; }
        
        i--;
    }
    fclose(stud);
    
}
void get_p(){
    FILE *stud;
    if((stud=fopen("prof.txt", "r"))==NULL){
        puts("file did not opend");
    }else{
        while (!feof(stud)) {
            
            fscanf(stud, "%s , %s , %s , %s , %d",pi[z].pname,pi[z].pl,pi[z].role,pi[z].minor,&pi[z].os);
            z++;
        }z--;
        fclose(stud);
    }}





void add_student()
{
    FILE *student,*auth;
    if((student=fopen("student.txt", "a"))==NULL){
        printf("file did not open");
    }else{if((auth=fopen("auth.txt", "a"))==NULL){
        puts("didnt open");
    }
        printf("Add the Stuºdents Details\n");
        printf("-------------------------\n");
        printf("Enter the first name of student\n");
        scanf("%s", st[i].name);
        printf("Enter the last name of student\n");
        scanf("%s", st[i].lname);
        printf("Enter the student id Number\n");
        scanf("%d", &st[i].sd);
        printf("Enter the field you study\n");
        scanf(" %s", st[i].minor);
        printf("enter your pass");
        scanf("%s",at[i].pass);
      /*  printf("Add the course Details\n");
        printf("-------------------------\n");
        printf("Enter the course code\n");
        scanf("%s", st[i].co[c].course_code);
        printf("Enter the name of the course\n");
        scanf("%s", st[i].co[c].course_name);
        printf("Enter the course point\n");
        scanf("%d", &st[i].co[c].point);*/
        fprintf(student, "%s , %s , %d , %s\n",st[i].name,st[i].lname,st[i].sd,st[i].minor);
//        fprintf(student, "%s , %s, %d \n",st[i].co[c].course_code,st[i].co[c].course_name,st[i].co[c].point);*/
        fprintf(auth, "%d %s\n",st[i].sd,at[i].pass);
        fclose(auth);
        fclose(student);
        i = i + 1;
    }
    t=i;
}

void del_s(){
    int a, idx = -1;
    printf("Enter the student Number which you want to delete\n");
    scanf("%d", &a);
    for (int j = 0; j < i; j++) {
        if (a == st[j].sd)
            idx = j;
    }
    if (idx == -1) {
        printf("not found\n");
        return;
    }
    for (int j = idx + 1; j < i; j++){
        st[j - 1] = st[j];
        at[j-1]=at[j];
    }
    i--;
    FILE *stud,*ath;
    stud=fopen("student.txt", "w");
    ath=fopen("auth.txt", "w");
    for (int j=0; j<i; j++) {
        fprintf(stud, "%s , %s , %d , %s\n",st[j].name,st[j].lname,st[j].sd,st[j].minor);
        fprintf(ath,"%d %s\n",at[j].username,at[j].pass);
    }
    printf("The student Number is removed Successfully\n");
    fclose(stud);
    fclose(ath);
}
    void add_course_s()
    {
        FILE *courses;
        if((courses=fopen("courses.txt", "a"))==NULL){
            printf("file did not open");
        }else{
            printf("Add the course Details\n");
            printf("-------------------------\n");
            printf("Enter the course code\n");
            scanf("%s", co[c].course_code);
            printf("Enter the name of the course\n");
            scanf("%s", co[c].course_name);
            printf("Enter the course point\n");
            scanf("%d", &co[c].point);
            fprintf(courses, "%s , %s , %d\n",co[c].course_code,co[c].course_name,co[c].point);
            fclose(courses);
            c++;
        }}
void del_c(){
    char a[10];
    int idx = -1;
    printf("Enter the course code which you want to delete\n");
    scanf("%s", a);
    for (int j = 0; j < c; j++) {
        if (strcmp(a, co[j].course_code) == 0 )
            idx = j;
    }
    if (idx == -1) {
        printf("this course not found\n");
        return;
    }
    for (int j = idx + 1; j < c; j++)
        co[j - 1] = co[j];
    c--;
    FILE *stud;
    stud=fopen("courses.txt", "w");
    for (int j=0; j<c; j++) {
        fprintf(stud, "%s , %s , %d\n",co[j].course_code,co[j].course_name,co[j].point);
    }
    printf("the course removed successfully\n");
    
    fclose(stud);
    
    
}
void add_prof()
{
    FILE *prof,*auth;
    if((prof=fopen("prof.txt", "a"))==NULL){
        printf("file did not open");
    }else{if((auth=fopen("authp.txt", "a"))==NULL){
        puts("didnt open");}else{
            printf("Add the Students Details\n");
            printf("-------------------------\n");
            printf("Enter the first name of prof\n");
            scanf("%s", pi[z].pname);
            printf("Enter the last name of prof\n");
            scanf("%s", pi[z].pl);
            printf("Enter the prof role\n");
            scanf("%s", pi[z].role);
            printf("Enter the field of teaching\n");
            scanf("%s", pi[z].minor);
            printf("enter prof number");
            scanf("%d",&pi[z].os);
            printf("enter your pass");
            scanf("%s",atp[z].pass);
            fprintf(prof, "%s , %s , %s , %s , %d\n",pi[z].pname,pi[z].pl,pi[z].role,pi[z].minor,pi[z].os);
            fprintf(auth,"%d %s\n",pi[z].os,atp[z].pass);
            fclose(prof);
            fclose(auth);
            z = z + 1;}
    }}
void see_by_student_number(){
    int ssd;
    puts("enter student number:\n");
    scanf("%d",&ssd);
    for (int trr=0; trr<i; trr++) {
        if(st[trr].sd==ssd){
            printf("NAME   LAST NAEM    STUDENT NUMBER  MINOR PASSWORD\n");
            printf("%s     %s           %d              %s    %s",st[trr].name,st[trr].lname,st[trr].sd,st[trr].minor,at[trr].pass);
        }
    }}
void add_cs(int mnm){char cs[10];
    FILE *studentc;
    if((studentc=fopen("studentc.txt", "a"))==NULL){
        puts("file did not opened");
    }else{
        for (int vbm=0; vbm<c; vbm++) {
            
            
            printf("COURSE NAME:%s\tCOURSE CODE:%s\tCOURSE POINT:%d\n",co[vbm].course_name,co[vbm].course_code,co[vbm].point);
        }
        do{printf("chose the course code you want:\n");
            scanf("%s",cs);
            for(int kll=0;kll<c;kll++){
                if(strcmp(cs, co[kll].course_code)==0){
                    st[mnm].p_vahed+=co[kll].point;
                    strcpy(st[mnm].vahed, co[kll].course_code);
                    fprintf(studentc, "%d %s\n",st[mnm].sd,co[kll].course_code);
                }
            }
            
        }while(st[mnm].p_vahed<14||st[mnm].p_vahed>17);
    }fclose(studentc);
    
}
void see_course_student(int xcv){
    FILE *inf;
    if((inf=fopen("studentc.txt", "r"))==NULL){
        printf("file did not opened");
    }else{char aaa[10];
        int rrr;
        while (!feof(inf)) {
            
            fscanf(inf, "%d %s",&rrr,aaa);
            if (xcv==rrr) {
                printf("%s\n",aaa);
            }
        }
    }
    
    
    fclose(inf);
    
    
}
void see_proff_info(){
    int ssd;
    puts("enter prof number:\n");
    scanf("%d",&ssd);
    
    for (int trr=0; trr<z; trr++) {
        if(pi[trr].os==ssd){
            
            printf("NAME:%s\nLASTNAME:%s\nROLE:%s\nMINOR:%s\nPASSWORD:%s\n",pi[trr].pname,pi[trr].pl,pi[trr].role,pi[trr].minor,atp[trr].pass);
            
        }}}

void see_all_sstudent(){
    for (int trr=0; trr<i; trr++) {
        
        printf("%d:",trr+1);
        printf("NAME:%s\nLASTNAME:%s\nSTUDENT NUMBER:%d\nMINOR:%s\nPASSWORD:%s\n",st[trr].name,st[trr].lname,st[trr].sd,st[trr].minor,at[trr].pass);
        printf("---------------------------\n");
        
    }}
void give_course_to_proff(){
    FILE *studentc,*teacherc;
    teacherc=fopen("teacherc.txt", "a");
    if((studentc=fopen("studentc.txt", "r"))==NULL){
        puts("file did not open");
    }else{
        int info;
        char code[10];
        int teacher_code;
        char code_t[10];
        printf("please enter prof code");
        scanf("%d",&teacher_code);
        printf("please enter code of the course that the prof gonna teach:\n");
        scanf("%s",code_t);
        while (!feof(studentc)) {
            fscanf(studentc, "%d %s",&info,code);
            if(strcmp(code, code_t)==0){
                fprintf(teacherc, "%d %s %d\n",info,code,teacher_code);
            }
        }
    }
    fclose(studentc);
    fclose(teacherc);
}

void show_course_prof(int x){
    
    FILE *teacher;
    if((teacher=fopen("teacherc.txt", "r"))==NULL){
        puts("file did not opened");
    }else{
        int students_;
        char code[10];
        int proff_;
        
        while (!feof(teacher)) {
            fscanf(teacher, "%d %s %d",&students_,code,&proff_);
            if(proff_==x){
                printf("%s\t%d\n",code,students_);
            }
        }
        
        fclose(teacher);
        
        
        
    }
    
    
    
    
    
}



void get_auth(){
    FILE *auth,*authp;
    authp=fopen("authp.txt", "r");
    auth=fopen("auth.txt", "r");
      
    while (!feof(auth)) {
        fscanf(auth, "%d %s",&at[q].username,at[q].pass);
        q++;
    }
    while (!feof(authp)) {
        fscanf(authp, "%d %s",&atp[qq].username,atp[qq].pass);
        qq++;
    }
    fclose(auth);
}
void loggin(){
    int kk,bb=0,cc;
    get_auth();
    char pass[40];
    int sdd;
    printf("Wellcome to login page\n");
    printf("----------------------\n");
    printf("please enter your choice:\n1: student\n2:profesors\n");
    scanf("%d",&kk);
    do{
        
        
        
        if(kk==0){
            puts("please enter your username:\t");
            scanf("%d",&sdd);
            puts("please enter your password:\t");
            scanf("%s",pass);
            if((strcmp(pass, "admin")==0)&&sdd==42){
                puts("wellcome to admin zone\n");
                puts("---------------------------");
                
                while (1) {
                    printf("\n\n\n\nenter your choice:\n");
                    printf("1:add student\n");
                    printf("2:delete student\n");
                    printf("3:add course\n");
                    printf("4:delete course\n");
                    printf("5:add proffesor\n");
                    printf("6:assign course to prof\n");
                    printf("7:see info by student number\n");
                    printf("8:see info by proff number\n");
                    printf("9:see all student\n");
                    printf("10:exit\n");
                    scanf("%d",&cc);
                    switch (cc) {
                        case 1:
                            add_student();
                            break;
                        case 2:del_s();
                            break;
                        case 3:add_course_s();
                            break;
                        case 4:del_c();
                            break;
                        case 5:add_prof();
                            break;
                        case 6:give_course_to_proff();
                            break;
                        case 7:see_by_student_number();
                            break;
                        case 8:see_proff_info();
                            break;
                        case 9:see_all_sstudent();
                            break;
                        case 10:loggin();
                            break;
                        default:
                            break;
                    }
                }
                
                
            }
        
            bb++;
    }
        if(kk==1){
            puts("please enter your username:\t");
            scanf("%d",&sdd);
            puts("please enter your password:\t");
            scanf("%s",pass);
            for (int yo=0; yo<q; yo++) {
            
            
                if((strcmp(pass, at[yo].pass)==0)&&(sdd==at[yo].username)){
                    puts("wellcome!\n");
                    puts("---------------------------");
                    while(1){
                        
                        printf("enter your choice:\n");
                        printf("1:see your info\n");
                        printf("2:add course\n");
                        printf("3:see your course\n");
                        printf("4:exit\n");
                        scanf("%d",&cc);
                        switch (cc) {
                            case 1:
                                printf("NAME:%s\nLASTNAME:%s\nSTUDENT NUMBER:%d\nMINOR:%s\t",st[yo].name,st[yo].lname,st[yo].sd,st[yo].minor);
                                break;
                            case 2:add_cs(yo);
                                break;
                            case 3:see_course_student(st[yo].sd);
                                break;
                            case 4:loggin();
                            
                            
                            default:
                                break;
                        }
                        
                    }
                    
                    
                    bb++;
                }
            }
        }else if(kk==2){
            puts("please enter your username:\t");
            scanf("%d",&sdd);
            puts("please enter your password:\t");
            scanf("%s",pass);
            for (int yo=0; yo<qq; yo++) {
                if((strcmp(pass, atp[yo].pass)==0)&&(sdd==atp[yo].username)){
                    puts("wellcome!\n");bb++;
                    puts("---------------------------");
                   
                    while(1){
                        
                        printf("enter your choice:\n");
                        printf("1:see your info\n");
                        printf("2:see your course\n");
                        printf("3:exit\n");
                        scanf("%d",&cc);
                        switch (cc) {
                            case 1:
                                printf("NAME:%s\nLASTNAME:%s\nPROF NUMBER:%d\nMINOR:%s\nROLE:%s\n",pi[yo].pname,pi[yo].pl,pi[yo].os,pi[yo].minor,pi[yo].role);
                                break;
                            case 2:show_course_prof(pi[yo].os);
                                break;
                            case 3:loggin();
                            
                            
                            default:
                                break;
                        }
                        
                    }
                    
                    
                }
            }
        }
        if(bb==0){
            puts("Try again");
        }
    }while(bb==0);
    
    
    
}

int main(){
    get_c();
    get_p();
    get_st();
    loggin();
    
    
    
}


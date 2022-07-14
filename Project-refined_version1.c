#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){



// toit ha az 0 shomare migiran



    char usernames[100][20];//hadaksar 20 harfi mitune bashe username and had aksar 100 karbar mitunim begirim
    char passwords[100][20];//hadaksar 20 harfi mitune bashe password
    char messages[1000][100];//hadaksar 100 harfi mitune bashe har pm and hadaksar 1000 ta pm ja darim
    char senders[1000][20];


    int arrofeddited[1000];


    for(int i = 0; i<1000; i++){
        arrofeddited[i] = -1;
    }



    int t3;
    int navigation = -1;
    int number_of_users = 0;
    int number_of_messages = 0;
    FILE *fileusernames ;
    FILE *filepasswords ;
    FILE *filepms;
    FILE *filepmsender;
    FILE *filepmidskarbarsender;
    FILE *filePMShistory;
    FILE *fileIdoflasttweet;


char temp_username[20];
    while(navigation != 5){


        int a =0;
        int user_index;

        while(navigation==-1 && a == 0 ){

        printf("Username:\t");

        scanf("%s", temp_username);

    fileusernames = fopen("fileusernames.txt","a+");

rewind(fileusernames);

char *usernamedata;
    usernamedata=(char*)malloc(20*sizeof(char));



             int t1=0 ;
    while( fgets ( usernamedata, 20, fileusernames ) != NULL )
        {

sscanf(usernamedata,"%s",usernames[t1]);

           t1++;
        }
        fclose(fileusernames);

            filepasswords = fopen("filepasswords.txt","a+");
            rewind(filepasswords);

number_of_users= t1;
char *passwordsdata;
    passwordsdata=(char*)malloc(20*sizeof(char));

         int t2=0 ;
    while( fgets ( passwordsdata, 20, filepasswords ) != NULL )
        {
sscanf(passwordsdata,"%s",passwords[t2]);

           t2++;
        }
        fclose(filepasswords);


      filepms = fopen("filepms.txt","a+");
            rewind(filepms);

      filepmsender = fopen("filepmsender.txt","a+");
            rewind(filepmsender);



           t3=0 ;
    while( fscanf(filepms," %100[^\n]",messages[t3])!=EOF)
        {


           t3++;
        }

   fclose(filepms);


    filepmsender = fopen("filepmsender.txt","a+");

rewind(filepmsender);

char *senderdata;
    senderdata=(char*)malloc(20*sizeof(char));



             int t4=0 ;
    while( fgets ( senderdata, 20, filepmsender ) != NULL )
        {

sscanf(senderdata,"%s",senders[t4]);



           t4++;
        }
        fclose(filepmsender);


number_of_messages=t3;

        int repeatition = 0;
        int repeatition_index;
        int flag=0;
        for(int i = 0; i<number_of_users; i++){
            if(strcmp(usernames[i], temp_username)==0){
                repeatition = 1;
                repeatition_index = i;
               a++;
               flag=1;
                break;
            }
        }


        while(repeatition == 1 && navigation == -1){
            printf("\nEnter Password:\t");
            char temp_password[20];
            scanf("%s", temp_password);


            printf("1.login\n2.register\nEnter the number of the action:\n ");
            int LorR;
            scanf("%d",&LorR);
             if(LorR==2){
                printf("username '%s' already exists\n",temp_username);
                navigation=-1;  repeatition = -1;break;

             }




            if(strcmp(temp_password, passwords[repeatition_index]) == 0){

                user_index = repeatition_index;
                navigation = 0;

                printf("welcome %s!",temp_username);

            }

            else{
                printf("\nusername & password don't match!\n");
                navigation=-1;  repeatition = -1;break;
            }
        }


        if(repeatition == 0){




            printf("\nEnter Password:\t");
            char temp_password[20];
            scanf("%s", temp_password);

          printf("1.login\n2.register\nEnter the number of the action:\n");
            int LorR;
            scanf("%d",&LorR);
            if(LorR==1){printf("no username matches '%s'\n",temp_username);
              navigation=-1;  repeatition = -1;break;
            }

                printf("register successful %s,welcome!\n",temp_username);

            strcpy(usernames[number_of_users], temp_username);
            strcpy(passwords[number_of_users], temp_password);
            user_index = number_of_users;
            number_of_users++;
            navigation = 0;

 fileusernames = fopen("fileusernames.txt","a+");

            fprintf(fileusernames,"%s",temp_username);
fputs("\n", fileusernames);
fclose(fileusernames);

        }

    }


        while(navigation==0){
            printf("\nMain Menu:");
            printf("\n1.Send Messages\n2.Edit Messages\n3.View All Messages\n4.Change Password\n5.Exit\nenter number of menu:\n");
            scanf(" %d", &navigation);
            if(navigation > 5 || navigation <= 0){
                printf("\nPlease Enter a Number Between 1 and 5:\n");
                navigation = 0;
            }
        }

        while(navigation == 1){
            printf("\nSend Messages Menu:");
            printf("\n1.Send Messages\n2.Exit\nenter number of menu:\n");
            scanf(" %d", &navigation);
            while(navigation > 2 || navigation<=0){
                printf("\nPlease Enter a Number Between 1 and 2:\n");
                scanf(" %d", &navigation);
            }
            if(navigation == 2){
                navigation = 0;
            }

            while(navigation == 1){
            printf("\nPlease Enter The Message That You Wish to Send\n");


            scanf(" %100[^\n]",messages[number_of_messages]);//pm ye khat v 100 harfe hadaxar



            filepmsender = fopen("filepmsender.txt","a+");

            fprintf(filepmsender,"%s",temp_username);
fputs("\n", filepmsender);
fclose(filepmsender);

strcpy(senders[number_of_messages],temp_username);
            number_of_messages++;


            printf("(If You Wish to Send More Messages, Please Enter '1', Otherwise Enter '0')\n");
            scanf(" %d", &navigation);
            while(navigation!=1 && navigation!=0){
                printf("Please Enter Either '0' or '1'\n");
                scanf(" %d", &navigation);
            }

            }


        }



        while(navigation == 2){
            printf("\nEdit Messages Menu:");
            printf("\n1.Edit Messages\n2.Exit\nenter number of menu:\n");

            scanf(" %d", &navigation);
            while(navigation > 2 || navigation<=0){
                printf("\nPlease Enter a Number Between 1 and 2:\n");
                scanf(" %d", &navigation);
            }
            if(navigation == 2){
                navigation = 0;
            }
            if(navigation == 1){
                     int temp_message_id;
                printf("\nYou Have access to these message IDs:\n");
                for(int i = 0; i<number_of_messages; i++){

                   if(strcmp(senders[i],temp_username)==0){
                    printf("%d\t", i);
                   }



                }
                printf("\nPlease Enter Message ID:\t");

                scanf(" %d", &temp_message_id);





                 if(strcmp(senders[temp_message_id],temp_username)==0){
                    printf("\nPlease Enter the New Message:\n");
                    char temp_message[100];
                    scanf(" %100[^\n]", temp_message);
                    strcpy(messages[temp_message_id], temp_message);
                    arrofeddited[temp_message_id]=1;
                    navigation++;
                }









                else{



                    printf("\nYou Don't Have Access to This Particular Message.");
                    navigation++;
                }
            }
        }


        while(navigation == 3){
            printf("\nView All messages Menu:\n");
            printf("\n1.View All Messages\n2.Exit\nenter number of menu:\n");
            scanf(" %d", &navigation);
            while(navigation > 2 || navigation<=0){
                printf("\nPlease Enter a Number Between 1 and 2:\n");
                scanf(" %d", &navigation);
            }
            if(navigation == 2){
                navigation = 0;
            }else{
                printf("\nHere Is All The Messages:");
                for(int j = 0; j<number_of_messages; j++){
                    printf("\nMessage:\t%s", messages[j]);
                    printf("\nID:\t%d\n", j);
                    printf("Owner:\t%s\t", senders[j]);
                    if (arrofeddited[j]==1){
                        printf("(edited)");
                    }
                    printf("\n");

                }
                navigation = 3;
            }
        }


        while(navigation == 4){
            printf("\nChange Password Menu:");
            printf("\n1.Change Password\n2.Exit\nenter number of menu:\n");
            scanf(" %d", &navigation);
            while(navigation > 2 || navigation<=0){
                printf("\nPlease Enter a Number Between 1 and 2:\n");
                scanf(" %d", &navigation);
            }
            if(navigation == 2){
                navigation = 0;
            }else{
                printf("\nPlease Enter Your New Password:\n");
                char temp_password[20];
                scanf(" %s", temp_password);



                strcpy(passwords[user_index], temp_password);


                navigation = 4;
            }
        }
        if(navigation==5){
            printf("\nThank You for Using Our App!\n\n\n\n");
            navigation = -1;

         filepasswords=fopen("filepasswords.txt","w");

          for(int b=0;b<number_of_users;++b){



                fprintf(filepasswords,"%s",passwords[b]);


             fputs("\n", filepasswords) ;
          }


 fclose(filepasswords);




 filepms=fopen("filepms.txt","w");

  for(int bb=0;bb<number_of_messages;++bb){



                fprintf(filepms,"%s\n",messages[bb]);



          }


 fclose(filepms);


filepmidskarbarsender=fopen("filepmidskarbarsender.txt","w");

  for(int bbb=0;bbb<number_of_users;++bbb){



                fprintf(filepmidskarbarsender,"%s :  ",usernames[bbb]);

int flagofsend=0;
            for(int jk=0;jk<number_of_messages;++jk){
                if(strcmp(senders[jk],usernames[bbb])==0){
                     fprintf(filepmidskarbarsender,"  %d  ",jk);
                     flagofsend=1;

                }

            }

if (flagofsend==0){ fputs("karbar payami ersal nakarde ast", filepmidskarbarsender) ;}
             fputs("\n", filepmidskarbarsender) ;
          }


 fclose(filepmidskarbarsender);


fileIdoflasttweet=fopen("fileIdoflasttweet.txt","w");
if(number_of_messages>0){
  fprintf(fileIdoflasttweet,"ID of the last message is %d",number_of_messages-1);}
else{fputs("hich payami hanuz ersal nashode", fileIdoflasttweet);}

 fclose(fileIdoflasttweet);

 filePMShistory=fopen("filePMShistory.txt","w");

  for(int bb=0;bb<number_of_messages;++bb){



                fprintf(filePMShistory,"ID:  %d      pm:  ",bb);
                fputs(messages[bb], filePMShistory);
                fprintf(filePMShistory,"                    sender:   %s",senders[bb]);
                if (arrofeddited[bb]==1)
                {
                    fputs("(edited)", filepasswords);
                }



                    fputs("\n", filepasswords);

          }


 fclose(filePMShistory);

        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


void login_admin(void);
void mainmenu_admin(void);
void add_med(void);
void show_med(void);
void delete_med(void);
void modify_med(void);
void search_med(void);
void expirydate_med(void);
void login_cust(void);
void mainmenu_cust(void);
void search_med_cust(void);
void purchase_med(void);

int total_med;
int i;
int del_id;
char purchase_string [100];
int quantity_needed;
float total_price = 0;
int chosen_med_id;


struct medinfo
{
    int id;
    char med_name[20];
    char med_comp[20];
    int med_quantity;
    float med_price;
    int dd,mm,yy;
    int mdd,mmm,myy;
    int balance_med;
};
struct mod_medinfo
{
    int modify_id;
    int mod_id;
    char mod_med_name[20];
    char mod_med_comp[20];
    int mod_med_quantity;
    float mod_med_price;
    int mod_dd, mod_mm, mod_yy;
    int mod_mdd, mod_mmm, mod_myy;
};
struct p_medinfo
{
    int p_id;
    char p_med_name[20];
    char p_med_comp[20];
    int p_med_quantity;
    float p_med_price;
    int p_dd,p_mm,p_yy;
    int p_mdd,p_mmm,p_myy;
};
struct medinfo a;

int main()
{
    time_t med_time;
    time(&med_time);
    printf("\t%s\n", ctime(&med_time));

    int choose_user;

    printf("\n\t=======================================================");
    printf("\n\t\tWELCOME TO THE PHARMACY MANAGEMENT SYSTEM");
    printf("\n\t=======================================================");
    printf("\n\n\tLogin as: ");
    printf("\n\n\t1. Admin    2. Customer   3. Exit");
    printf("\n\n\tPick a user: ");
    scanf("%d", &choose_user);

    switch (choose_user)
    {
    case 1:
        login_admin();
        break;
    case 2:
        login_cust();
        break;
    case 3:
        break;
    default:
        {
        printf("Invalid Entry ! Please try again..");
        if(getch())
            main();
        }
    }


    return 0;
}
void login_admin(void)
{
    char username_admin[15];
    char password_admin[15];

    printf("\n\tEnter admin username: ");
    scanf("%s", username_admin);

    printf("\tEnter admin password: ");
    scanf("%s", password_admin);

    if(strcmp(username_admin, "admin")==0){
        if(strcmp(password_admin, "123")==0){

            printf("\n\tLogin Successful !\n");
            mainmenu_admin();
        }
        else
        {
            printf("\nWrong password/n/n");
            main();
        }
    }
    else
    {
        printf("\nWrong username\n\n");
        main();
    }
}
void mainmenu_admin(void)
{
            int choice_menu;

            printf("\n\t--------------------------------------------------------");
            printf("\n\t\tWelcome To The Pharmacy Management User\n\t\t\t     [ADMIN]");
            printf("\n\t--------------------------------------------------------");
            printf("\n\n\t1.Add a new medicine");
            printf("\n\t2.Show all existing medicine");
            printf("\n\t3.Delete an existing medicine");
            printf("\n\t4.Modify an existing medicine");
            printf("\n\t5.Search an existing medicine");
            printf("\n\t6.List out expiry dates (months)");
            printf("\n\t7.Close Application\n\n");


            printf("\tPlease choose an option: ");
            scanf("%d", &choice_menu);
            switch(choice_menu)
            {
                case 1:
                    add_med();
                    break;
                case 2:
                    show_med();
                    break;
                case 3:
                    delete_med();
                    break;
                case 4:
                    modify_med();
                    break;
                case 5:
                    search_med();
                    break;
                case 6:
                    expirydate_med();
                    break;
                case 7:
                    break;

                default:
                    {
                        printf("Invalid Entry ! Please try again..");
                        if(getch())
                            mainmenu_admin();
                    }
            }

}
void add_med(void)
{

    total_med = 0;

    printf("\n\t******************ADDING MEDICINE********************\n");

    char choice = 'y';
    while (choice == 'y')
    {
        printf("\n\tEnter the ID of the medicine: ");
        scanf("%d", &a.id);
        printf("\tEnter the name of the medicine: ");
        scanf("%s", a.med_name);
        printf("\tEnter the company name of the medicine: ");
        scanf("%s", a.med_comp);
        printf("\tEnter the manufacturing date of the medicine: ");
        scanf("%d / %d / %d", &a.mdd, &a.mmm, &a.myy);
        printf("\tEnter the expiry date of the medicine: ");
        scanf("%d / %d / %d", &a.dd, &a.mm, &a.yy);
        printf("\tEnter the price of the medicine: ");
        scanf("%f", &a.med_price);
        printf("\tEnter the quantity of the medicine: ");
        scanf("%d", &a.med_quantity);
        scanf("%*c");

        printf("\n\tAdd another record? (y/n)\n\n");
        choice = getch();

    }
    FILE *originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "a+");

    fprintf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", a.id,
    a.med_name, a.med_comp, a.mdd, a.mmm, a.myy, a.dd, a.mm, a.yy, a.med_price, a.med_quantity );

    fclose(originalFile);
    mainmenu_admin();
}
void show_med(void)
{
    total_med = 0;
    FILE *originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "r");

    while (!feof(originalFile))
    {
       fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
       a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );
       total_med ++;
    }

    struct medinfo a[total_med];
       printf("                                               MEDICINE DATABASE                                               \n");
       printf("\t----------------------------------------------------------------------------------------------------------\n");
       printf("\t| %-8s | %-10s | %-10s | %-17s | %-17s | %-8s      | %-8s  |\n", "Id", "Name", "Company", "Man. Date", "Expire Date", "Price", "Quantity");
       printf("\t----------------------------------------------------------------------------------------------------------\n");

            rewind(originalFile);
            while (!feof(originalFile))
            {
                 for(i=0; i<total_med; i++)
                {
                 fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a[i].id,
                 a[i].med_name, a[i].med_comp, &a[i].mdd, &a[i].mmm, &a[i].myy, &a[i].dd, &a[i].mm, &a[i].yy, &a[i].med_price, &a[i].med_quantity );

                 printf("\t| %-8d | %-10s | %-10s | %-2d/ %-2d/ %-2d      | %-2d/ %-2d/ %-2d      | RM %-7.2f    | %-7d   |\n",
                        a[i].id, a[i].med_name, a[i].med_comp, a[i].mdd, a[i].mmm, a[i].myy, a[i].dd, a[i].mm, a[i].yy, a[i].med_price, a[i].med_quantity);

                }

            }
              printf("\t----------------------------------------------------------------------------------------------------------\n");
        printf("\n\tTotal Medicine Stored: %d\n", total_med);

    fclose(originalFile);
    mainmenu_admin();
}
void delete_med(void)
{
    total_med = 0;

    printf("\n\t******************DELETING MEDICINE********************\n");

    FILE *originalFile;
    FILE *editedFile;

    originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "a+");
    editedFile = fopen("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt", "a+");


    while (!feof(originalFile))
    {
       fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
       a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );
       total_med ++;
    }

    struct medinfo a[total_med];
       printf("                                               MEDICINE DATABASE                                               \n");
       printf("\t-------------------------------------------------------------------------------------------------------\n");
       printf("\t| %-8s | %-10s | %-10s | %-17s | %-17s | %-8s   | %-8s  |\n", "Id", "Name", "Company", "Man. Date", "Expire Date", "Price", "Quantity");
       printf("\t-------------------------------------------------------------------------------------------------------\n");

            rewind(originalFile);
            while (!feof(originalFile))
            {
                 for(i=0; i<total_med; i++)
                {
                 fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a[i].id,
                 a[i].med_name, a[i].med_comp, &a[i].mdd, &a[i].mmm, &a[i].myy, &a[i].dd, &a[i].mm, &a[i].yy, &a[i].med_price, &a[i].med_quantity );

                 printf("\t| %-8d | %-10s | %-10s | %-2d/ %-2d/ %-2d      | %-2d/ %-2d/ %-2d      | RM%-7.2f    | %-7d   |\n",
                        a[i].id, a[i].med_name, a[i].med_comp, a[i].mdd, a[i].mmm, a[i].myy, a[i].dd, a[i].mm, a[i].yy, a[i].med_price, a[i].med_quantity);

                }

            }
              printf("\t-------------------------------------------------------------------------------------------------------\n");
        printf("\n\tTotal Medicine Stored: %d\n", total_med);

        //Delete med
        printf("\tEnter the ID to be deleted: ");
        scanf("%d", &del_id);
        struct medinfo b;
        rewind(originalFile);
        while (!feof(originalFile))
        {
                fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &b.id,
                b.med_name, b.med_comp, &b.mdd, &b.mmm, &b.myy, &b.dd, &b.mm, &b.yy, &b.med_price, &b.med_quantity );

                if(b.id != del_id)
                {
                    fprintf(editedFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", b.id,
                    b.med_name, b.med_comp, b.mdd, b.mmm, b.myy, b.dd, b.mm, b.yy, b.med_price, b.med_quantity );
                }

        }
        printf("\n\tDatabase Updated !");
        fclose(originalFile);
        fclose(editedFile);
        remove("C:\\Users\\User\\Desktop\\Med Storage.txt");
        rename("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt","C:\\Users\\User\\Desktop\\Med Storage.txt");

        mainmenu_admin();

}
void modify_med(void)
{
       struct mod_medinfo mod;
       total_med = 0;

       printf("\n\t******************MODIFYING MEDICINE********************\n");

       FILE *originalFile;
       FILE *editedFile;

       originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "r");
       editedFile = fopen("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt", "a+");

       printf("\n\tContent of the files: \n\n");
           while (!feof(originalFile))
        {
           fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
           a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );
           total_med ++;
        }

        struct medinfo a[total_med];
        printf("                                               MEDICINE DATABASE                                               \n");
        printf("\t-------------------------------------------------------------------------------------------------------\n");
        printf("\t| %-8s | %-10s | %-10s | %-17s | %-17s | %-8s   | %-8s  |\n", "Id", "Name", "Company", "Man. Date", "Expire Date", "Price", "Quantity");
        printf("\t-------------------------------------------------------------------------------------------------------\n");

            rewind(originalFile);
            while (!feof(originalFile))
            {
                 for(i=0; i<total_med; i++)
                {
                 fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a[i].id,
                 a[i].med_name, a[i].med_comp, &a[i].mdd, &a[i].mmm, &a[i].myy, &a[i].dd, &a[i].mm, &a[i].yy, &a[i].med_price, &a[i].med_quantity );

                 printf("\t| %-8d | %-10s | %-10s | %-2d/ %-2d/ %-2d      | %-2d/ %-2d/ %-2d      | RM%-7.2f    | %-7d   |\n",
                        a[i].id, a[i].med_name, a[i].med_comp, a[i].mdd, a[i].mmm, a[i].myy, a[i].dd, a[i].mm, a[i].yy, a[i].med_price, a[i].med_quantity);

                }

            }
              printf("\t-------------------------------------------------------------------------------------------------------\n");
        printf("\n\tTotal Medicine Stored: %d\n", total_med);

        printf("\n\tEnter the ID of the medicine to be modified: ");
        scanf("%d", &mod.modify_id);

           printf("\n\tEnter the ID of the medicine: ");
           scanf("%d", &mod.mod_id);
           printf("\tEnter the name of the medicine: ");
           scanf("%s", mod.mod_med_name);
           printf("\tEnter the company name of the medicine: ");
           scanf("%s", mod.mod_med_comp );
           printf("\tEnter the manufacturing date of the medicine: ");
           scanf("%d / %d / %d", &mod.mod_mdd, &mod.mod_mmm, &mod.mod_myy);
           printf("\tEnter the expiry date of the medicine: ");
           scanf("%d / %d / %d", &mod.mod_dd, &mod.mod_mm, &mod.mod_yy);
           printf("\tEnter the price of the medicine: ");
           scanf("%f", &mod.mod_med_price);
           printf("\tEnter the quantity of the medicine: ");
           scanf("%d", &mod.mod_med_quantity);


        struct medinfo b;
        rewind(originalFile);
        while (!feof(originalFile))
        {
            fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &b.id,
            b.med_name, b.med_comp, &b.mdd, &b.mmm, &b.myy, &b.dd, &b.mm, &b.yy, &b.med_price, &b.med_quantity );

            if(b.id == mod.modify_id)
            {
                continue;
            }
            fprintf(editedFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", b.id,
            b.med_name, b.med_comp, b.mdd, b.mmm, b.myy, b.dd, b.mm, b.yy, b.med_price, b.med_quantity );

        }

            fprintf(editedFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", mod.mod_id,
            mod.mod_med_name, mod.mod_med_comp, mod.mod_mdd, mod.mod_mmm, mod.mod_myy, mod.mod_dd, mod.mod_mm, mod.mod_yy, mod.mod_med_price, mod.mod_med_quantity );

        printf("\n\tDatabase Updated !");
        fclose(originalFile);
        fclose(editedFile);
        remove("C:\\Users\\User\\Desktop\\Med Storage.txt");
        rename("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt","C:\\Users\\User\\Desktop\\Med Storage.txt");

        mainmenu_admin();

}
void search_med(void)
{

            char searched_med[100];
            int line_num = 1;
            int find_result = 0;
            char temp [500];

            printf("\n\t******************SEARCHING MEDICINE********************\n");

            FILE *originalFile;
            originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "r");

            printf("\n\tEnter the name of the medicine: ");
            scanf("%s", searched_med);

            while (fgets(temp, 500, originalFile) != NULL)
            {
                if((strstr(temp, searched_med)) != NULL)
                {
                    printf("\n\tA match found on the line: %d\n", line_num);
                    printf("\n\t%s\n", temp);
                    find_result++;
                }
                line_num++;
            }
            if(find_result == 0)
            {
                printf("\n\tSorry, could not find a match.\n");
            }

            fclose(originalFile);
            mainmenu_admin();

}
void expirydate_med(void)
{
            int total_med = 0;
            int i, j, temp, tempid, chosen_year;

            FILE *originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "r");
            FILE *expiredFile = fopen("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt", "a+");

            printf("\n\tContent of the files: \n\n");
            rewind(originalFile);
            while (!feof(originalFile))
            {
               fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
               a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );
               total_med ++;
            }

            struct medinfo a[total_med];
            printf("                                               MEDICINE DATABASE                                               \n");
            printf("\t-------------------------------------------------------------------------------------------------------\n");
            printf("\t| %-8s | %-10s | %-10s | %-17s | %-17s | %-8s   | %-8s  |\n", "Id", "Name", "Company", "Man. Date", "Expire Date", "Price", "Quantity");
            printf("\t-------------------------------------------------------------------------------------------------------\n");

                rewind(originalFile);
                while (!feof(originalFile))
                {
                     for(i=0; i<total_med; i++)
                    {
                     fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a[i].id,
                     a[i].med_name, a[i].med_comp, &a[i].mdd, &a[i].mmm, &a[i].myy, &a[i].dd, &a[i].mm, &a[i].yy, &a[i].med_price, &a[i].med_quantity );

                     printf("\t| %-8d | %-10s | %-10s | %-2d/ %-2d/ %-2d      | %-2d/ %-2d/ %-2d      | RM%-7.2f    | %-7d   |\n",
                            a[i].id, a[i].med_name, a[i].med_comp, a[i].mdd, a[i].mmm, a[i].myy, a[i].dd, a[i].mm, a[i].yy, a[i].med_price, a[i].med_quantity);

                    }

                }
                  printf("\t-------------------------------------------------------------------------------------------------------\n");
            printf("\n\tEnter the year to be sorted: ");
            scanf("%d", &chosen_year);
            struct medinfo b;
            int total_med_exp = 0;
            rewind(originalFile);
            while (!feof(originalFile))
            {
                 fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &b.id,
                 b.med_name, b.med_comp, &b.mdd, &b.mmm, &b.myy, &b.dd, &b.mm, &b.yy, &b.med_price, &b.med_quantity );

                 if(b.yy == chosen_year)
                 {
                     fprintf(expiredFile, "| ID: %d | Exp.Date: %d / %d |\n", b.id, b.mm, b.yy);
                     total_med_exp++;
                 }
                 else
                 {
                     continue;
                 }
            }

            int sorted_months[total_med_exp];
            int sorted_years[total_med_exp];
            int medid[total_med_exp];

            rewind(expiredFile);
            printf("\n\tBefore Sort in Year %d: \n\n", chosen_year);
            while(!feof(expiredFile))
            {
                for(i=0; i<total_med_exp; i++)
                {
                   fscanf(expiredFile, "| ID: %d | Exp.Date: %d / %d |\n", &medid[i], &sorted_months[i], &sorted_years[i]);
                   printf("\t| ID: %d | Exp.Date: %d / %d |\n", medid[i], sorted_months[i], sorted_years[i]);
                }

            }
            for(i=0; i<total_med_exp-1; i++)
            {
                for(j=i+1; j<total_med_exp; ++j)
                {
                    if(sorted_months[i] > sorted_months[j])
                    {
                        temp = sorted_months[i];
                        tempid = medid[i];
                        sorted_months[i] = sorted_months[j];
                        medid[i] = medid[j];
                        sorted_months[j] = temp;
                        medid[j] = tempid;
                    }
                }
            }
            printf("\n\tSorted Dates in Year %d: \n\n", chosen_year);
            for(i=0; i<total_med_exp; i++)
            {
                printf("\t| ID: %d | Exp.Date: %d / %d |\n", medid[i], sorted_months[i], sorted_years[i]);
            }
            fclose(originalFile);
            fclose(expiredFile);
            remove("C:\\Users\\User\\Desktop\\Temp. Med Storage.txt");
            mainmenu_admin();

}



void login_cust(void)
{
            char username_cust[15];
            char password_cust[15];

            printf("\n\tEnter customer username: ");
            scanf("%s", username_cust);

            printf("\tEnter customer password: ");
            scanf("%s", password_cust);

            if(strcmp(username_cust, "john")==0){
                if(strcmp(password_cust, "123")==0){

                        printf("\n\tLogin Successful !\n");
                        mainmenu_cust();
                }
                else
                {
                    printf("\nWrong Password !\n");
                    main();
                }
            }
            else
            {
                printf("\n Wrong Username\n");
                main();
            }

}
void mainmenu_cust(void)
{
              int choice_menu_cust;
              printf("\n\t--------------------------------------------------------");
              printf("\n\t\tWelcome To The Pharmacy Management User\n\t\t\t     [CUSTOMER]");
              printf("\n\t--------------------------------------------------------");
              printf("\n\n\t1. Search Medicine");
              printf("\n\t2. Checkout");
              printf("\n\t3. Exit");
              printf("\n\n\tChoose an option: ");
              scanf("%d", &choice_menu_cust);

              switch(choice_menu_cust)
              {
                case 1:
                    search_med_cust();
                    break;
                case 2:
                    purchase_med();
                    break;
                case 3:
                    main();
                    break;
              }
}
void search_med_cust(void)
{

     char searched_med_cust[100];
     int line_num_cust = 1;
     int find_result_cust = 0;
     char temp_cust [500];
     int total_med = 0;


     printf("\n\t******************SEARCHING MEDICINE********************\n\n");

     FILE *originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "a+");
     FILE *purchaseFile = fopen("C:\\Users\\User\\Desktop\\Purchased Med.txt", "a+");

    //Print Med
    while (!feof(originalFile))
    {
       fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
       a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );
       total_med ++;
    }

    struct medinfo a[total_med];
       printf("                                               MEDICINE DATABASE                                               \n");
       printf("\t-------------------------------------------------------------------------------------------------------\n");
       printf("\t| %-8s | %-10s | %-10s | %-17s | %-17s | %-8s   | %-8s  |\n", "Id", "Name", "Company", "Man. Date", "Expire Date", "Price", "Quantity");
       printf("\t-------------------------------------------------------------------------------------------------------\n");

            rewind(originalFile);
            while (!feof(originalFile))
            {
                 for(i=0; i<total_med; i++)
                {
                 fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a[i].id,
                 a[i].med_name, a[i].med_comp, &a[i].mdd, &a[i].mmm, &a[i].myy, &a[i].dd, &a[i].mm, &a[i].yy, &a[i].med_price, &a[i].med_quantity );

                 printf("\t| %-8d | %-10s | %-10s | %-2d/ %-2d/ %-2d      | %-2d/ %-2d/ %-2d      | %-7.2f    | %-7d   |\n",
                        a[i].id, a[i].med_name, a[i].med_comp, a[i].mdd, a[i].mmm, a[i].myy, a[i].dd, a[i].mm, a[i].yy, a[i].med_price, a[i].med_quantity);

                }

            }
              printf("\t-------------------------------------------------------------------------------------------------------\n");
        printf("\n\tTotal Medicine Stored: %d\n", total_med);
        rewind(originalFile);
        printf("\n\tEnter the name of the medicine: ");
        scanf("%s", searched_med_cust);

                    while (fgets(temp_cust, 500, originalFile) != NULL)
                    {
                        if((strstr(temp_cust, searched_med_cust)) != NULL)
                        {
                            printf("\n\tA match found on the line: %d\n", line_num_cust);
                            printf("\n\t%s\n", temp_cust);
                            find_result_cust++;

                        }
                        line_num_cust++;
                    }
                    if(find_result_cust == 0)
                    {
                        printf("\n\tSorry, could not find the medicine.\n");
                        mainmenu_cust();
                    }
        struct medinfo b;
        printf("\n\tPlease Enter the ID of the chosen medicine to confirm the purchase: ");
        scanf("%d", &chosen_med_id);
        rewind(originalFile);
        while(!feof(originalFile))
        {
            fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &b.id,
            b.med_name, b.med_comp, &b.mdd, &b.mmm, &b.myy, &b.dd, &b.mm, &b.yy, &b.med_price, &b.med_quantity );

            if (b.id == chosen_med_id)
            {
                    if (b.med_quantity == 0)
                    {
                        printf("\n\tSorry, we are out of stock.\n");
                        printf("\n\tDo you want to continue? (y/n): ");
                        getch();
                        mainmenu_cust();
                    }
                    else
                    {
                        printf("\n\tMedicine has been added to the cart !\n");
                        fprintf(purchaseFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", b.id,
                        b.med_name, b.med_comp, b.mdd, b.mmm, b.myy, b.dd, b.mm, b.yy, b.med_price, b.med_quantity );
                    }
            }
        }

        printf("\n\tThank You !");
        mainmenu_cust();


        fclose(originalFile);
        fclose(purchaseFile);
        mainmenu_cust();
}
void purchase_med(void)
{
        printf("\n\t******************CHECKOUT PROCESS********************\n");

        FILE *purchaseFile = fopen("C:\\Users\\User\\Desktop\\Purchased Med.txt", "r");
        FILE *originalFile = fopen("C:\\Users\\User\\Desktop\\Med Storage.txt", "a+");
        FILE *afterpurchaseFile = fopen ("C:\\Users\\User\\Desktop\\After Purchased.txt", "a+");

        struct p_medinfo p;


        rewind(purchaseFile);
        fscanf(purchaseFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &p.p_id,
        p.p_med_name, p.p_med_comp, &p.p_mdd, &p.p_mmm, &p.p_myy, &p.p_dd, &p.p_mm, &p.p_yy, &p.p_med_price, &p.p_med_quantity );

        printf("\n\t| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", p.p_id,
        p.p_med_name, p.p_med_comp, p.p_mdd, p.p_mmm, p.p_myy, p.p_dd, p.p_mm, p.p_yy, p.p_med_price, p.p_med_quantity );

        printf("\n\tPrice of the medicine: RM %.2f", p.p_med_price);
        printf("\n\tAvailable Quantity: %d", p.p_med_quantity);

        if (p.p_med_quantity != 0)
        {
                    printf("\n\tPlease enter the quantity needed: ");
                    scanf("%d", &quantity_needed);
                    if (p.p_med_quantity < quantity_needed)
                    {
                        printf("\n\n\tInsufficient Stock !");
                        mainmenu_cust();
                    }
                    else
                    {
                        printf("\n\tQuantity needed: %d", quantity_needed);
                        total_price = p.p_med_price * quantity_needed;
                        printf("\n\tTotal Amount: RM %.2f", total_price);
                        printf("\n\n\tCheckout Successful !\n");
                        a.balance_med = p.p_med_quantity - quantity_needed;
                        printf("\n\tBalance medicine available: %d", a.balance_med);
                        printf("\n\n\t~~~~~~~~~~THANK YOU FOR SHOPPING WITH US !~~~~~~~~~~");

                        rewind(originalFile);
                        while (!feof(originalFile))
                        {
                                fscanf(originalFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %f | Med.Quantity: %d |\n", &a.id,
                                a.med_name, a.med_comp, &a.mdd, &a.mmm, &a.myy, &a.dd, &a.mm, &a.yy, &a.med_price, &a.med_quantity );

                                if(a.id != chosen_med_id)
                                {
                                        fprintf(afterpurchaseFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", a.id,
                                        a.med_name, a.med_comp, a.mdd, a.mmm, a.myy, a.dd, a.mm, a.yy, a.med_price, a.med_quantity );
                                }
                                else
                                {
                                        fprintf(afterpurchaseFile,"| ID: %d | Med.Name: %s | Med.Company: %s | Man.Date: %d / %d / %d | Exp.Date: %d / %d / %d | Med.Price: RM %.2f | Med.Quantity: %d |\n", a.id,
                                        a.med_name, a.med_comp, a.mdd, a.mmm, a.myy, a.dd, a.mm, a.yy, a.med_price, a.balance_med);

                                }

                        }

                    }

        }
        else
        {
             printf("\n\n\tWe are out of stock. Sorry !");
             mainmenu_cust();
        }

        fclose(purchaseFile);
        fclose(afterpurchaseFile);
        fclose(originalFile);
        remove("C:\\Users\\User\\Desktop\\Purchased Med.txt");
        remove("C:\\Users\\User\\Desktop\\Med Storage.txt");
        rename("C:\\Users\\User\\Desktop\\After Purchased.txt","C:\\Users\\User\\Desktop\\Med Storage.txt");
        mainmenu_cust();

}




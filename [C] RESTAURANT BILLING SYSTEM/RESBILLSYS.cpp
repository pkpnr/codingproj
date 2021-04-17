#include <stdio.h>
#include <ctype.h>
#include <windows.h>

int category, MainCou, Dessert, Appet, selection;
int quant;

float total_Payment, change, Cash;

void menu_MainCou();
void menu_Dessert();
void menu_Appet();
void menu_Full();
void done();

int main()
{
	menu_Full();
}
void menu_Full()
{	
	int category, MainCou, Dessert, Appet;
	
	printf("\t\t============================================== \n");
	printf("\t\t||\tWELCOME TO CLARK N' NEA RESTAURANT!!    ||\n");
	printf("\t\t============================================== \n");
	printf("\t\t  Select a category: \n\n");
	printf("\t\t\t\t[1] Main Courses \n\t\t\t\t[2] Dessert \n\t\t\t\t[3] Appetizers \n\t\t\t\t[0] QUIT\n\n");
	printf("\t\t============================================== \n");
	printf("\t\t============================================== \n");
	printf("\t\t\t\t Input the number: ");
	
	scanf("%d",&category);
	
	system("cls");
	{
		if(category==1)
		{
			menu_MainCou();	
		} 
		else if(category==2)
		{
			menu_Dessert();
		}
		else if(category==3)
		{
			menu_Appet();
		}
		else if(category==0)
		{
			done();
    	}
		else
		{
			printf("\n\n\t\t\t ==========================\n\n");
			printf("\t\t          PLEASE TRY AGAIN!!");
			printf("\n\n\t\t\t ==========================\n\n");
		}
	}
		
}


void menu_MainCou()
{
	printf("\t\tSelect a Main Course: \n\n");
	printf("\t\t MAIN COURSE \t\t\t\tPRICE\n\n");
	printf("\t\t [1] Grilled Tequila Bangus     \t   Php 150.00\n");
	printf("\t\t [2] Creamy Beef Pasta \t   Php 200.00\n");
	printf("\t\t [3] Roasted Sweet Chili Chicken (Whole) \t\t   Php 300.00\n");
	printf("\t\t [4] QUIT\n");
	printf("\t\t============================================== \n");
	
	printf("\t\t\t\t Input the number: ");
	scanf("%d",&MainCou);
	
	if(MainCou == 1)
	{
		printf("\t\t\t\t Input Quantity: ");
		scanf("%d",&quant);
		
		total_Payment = 150.00  * quant;
		
		printf("\t\t You ordered %d Grilled Tequila Bangus.\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			
			if(Cash > total_Payment)
			{
				change = Cash - total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Your total bill is: %.2f \n", total_Payment);
				printf("\t\t\t    Cash on hand: %.2f  \n", Cash);
				printf("\t\t\t    Your change is: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				
				printf("\t\t\tOrder again?\n");
				printf("\t\t\t    [1] YES  [2] NO \n");
				
				printf("\t\t\t Input the number: ");
				scanf("\%d",&selection);
				
				if(selection == 1)
				{
					system("cls");
					{
						menu_Full();
					}
				}
				else if(selection == 2)
				{
					system("cls");
					{
						done();
					}
				}
			}
			else if (Cash == total_Payment)
			{
				change = Cash - total_Payment;
				
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Your total bill is: %.2f \n", total_Payment);
				printf("\t\t\t    Cash on hand: %.2f  \n", Cash);
				printf("\t\t\t    Your change is: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				
				printf("\t\t\t Input the number: ");
				scanf("\%d",&selection);
					if(selection == 1){
						system("cls");
						{
						menu_Full();
					    }
					}
					else if(selection == 2){
						system("cls");
						{
							done();
						}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();	
		}
	
		
	}else if(MainCou==2){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 200.00  * quant;
		printf("\t\t You ordered %d Creamy Beef Pasta\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash on: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}else if(MainCou==3){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 300.00  * quant;
		printf("\t\t You ordered %d Roasted Sweet Chili Chicken  \n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}else if(MainCou==4){
	system("cls");{
	done();
}
}

	
}
void menu_Dessert(){
	printf("\t\t============================================== \n");
	printf("\t\t||\tWELCOME TO CLARK N' NEA RESTAURANT      ||\n");
	printf("\t\t============================================== \n");
	printf("\t\tSelect a Dessert: \n\n");
	printf("\t\t DESSERT \t\t\t\tPRICE\n\n");
	printf("\t\t [1] Chocolatey Chip Cookies \t\t   Php  60.00/5 pcs.\n");
	printf("\t\t [2] Creamy Vanilla Cupcakes \t\t\t   Php 45.00/3 pcs.\n");
	printf("\t\t [3] Little Ice Cream (with Pepero Stick) \t   Php 30.00\n");
	printf("\t\t [4] EXIT\n");
	printf("\t\t============================================== \n");
	printf("\t\t\t\t Enter Choice: ");scanf("%d",&Dessert);
	
	if(Dessert==1){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 60.00  * quant;
		printf("\t\t You ordered %d Chocolatey Chip Cookies\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
		
	}else if(Dessert==2){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 45.00  * quant;
		printf("\t\t You ordered %d Creamy Vanilla Cupcakes\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}else if(Dessert==3){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 30.00  * quant;
		printf("\t\t You ordered %d Little Ice Cream (with Pepero Stick)\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}else if(MainCou==5){
	system("cls");{
	done();
}
}
}
void menu_Appet(){
	
	printf("\t\t============================================== \n");
	printf("\t\t||\tWELCOME TO CLARK N' NEA RESTAURANT      ||\n");
	printf("\t\t============================================== \n");
	printf("\t\tSelect an Appetizer: \n\n");
	printf("\t\t APPETIZER \t\t\t\tPRICE\n\n");
	printf("\t\t [1] Mini Lasagna Bites \t\t   Php 75.00/5 pcs.\n");
	printf("\t\t [2] Cheesy Dynamite Lumpia \t\t\t   Php 65.00/6 pcs.\n");
	printf("\t\t [3] Buttery Garlic Bread \t\t   Php 70.00/5 pcs.\n");
	printf("\t\t [4] EXIT\n");
	printf("\t\t============================================== \n");
	printf("\t\t\t\t Enter Choice: ");scanf("%d",&Appet);
	
	if(Appet==1){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 75.00  * quant;
		printf("\t\t You ordered %d Mini Lasagna Bites\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
		
	}else if(Appet==2){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 65.00  * quant;
		printf("\t\t You ordered %d Cheesy Dynamite Lumpia\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash<total_Payment){
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}else if(Appet==3){
		printf("\t\t\t\t Enter Quantity: ");
		scanf("%d",&quant);
		total_Payment = 70.00  * quant;
		printf("\t\t You ordered %d Buttery Garlic Bread\n",quant);
		printf("\t\t Your total bill is Php %.2f\n",total_Payment);
		printf("\t\t Cash: ");
		scanf("%f",&Cash);
			if(Cash>total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1){
						system("cls");
						{
						menu_Full();
					    }
					}else if(selection==2){
						system("cls");{
						done();
					}
					}
			}else if(Cash==total_Payment){
				change = Cash-total_Payment;
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t\t    Total Bill: %.2f \n", total_Payment);
				printf("\t\t\t    Cash: %.2f  \n", Cash);
				printf("\t\t\t    Change: %.2f  \n", change);
				printf("\n\t\t\t ==========================\n");
				printf("\t\t\tOrder again?\n", total_Payment);
				printf("\t\t\t    [1] YES  [2] NO \n", total_Payment);
				printf("\t\t\t Input the number: ");scanf("\%d",&selection);
					if(selection==1)
					{
						system("cls");
						{
						menu_Full();
					    }
					}
					else if(selection==2)
					{
						system("cls");
						{
							done();
						}
					}
			}
			else if (Cash < total_Payment)
			{
				printf("\n\n\t\t\t ==========================\n\n");
				printf("\t\t        Insufficient payment!!");
				printf("\n\n\t\t\t ==========================\n\n");
				menu_Full();
			}
}
else if (MainCou == 5)
{
	system("cls");
	{
		done();
	}	
}
	
}
void done()
{
	printf("\n\n\n\n\t\t============================================== \n");
	printf("\t\t||\t\tTHANK YOU FOR ORDERING!!    ||\n");
	printf("\t\t||\t\t COME AGAIN SOON! \t    ||\n");
	printf("\t\t============================================== \n");
}



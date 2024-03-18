#include <stdio.h>
#include <string.h>

struct Consumption{
	char city[20];
	int year;
	double usage; 
};

struct Resource {
	char material[30]; 
	double logitude;
	double latitude;
	double quantity;
	char units[20];
};

int main(){
	struct Resource metal, fuel;
	struct Resource wood ={"Oak", 32.5, 13.2, 5e+8, "hectares"};
	struct Consumption water, power;
	
	metal.logitude = 57.3;
	metal.latitude = 32.1;
	metal.quantity = 3e+10; 
	strcpy(metal.material, "Iron");
	strcpy(metal.units, "cubic meters");
	
	printf("The metal information is : \n%s\n%4.1lf degress longitude\n%4.1lf degress latitude\n%4e %s\n\n", 
	metal.material, metal.logitude, metal.latitude, metal.quantity, metal.units);
	
	printf("Enter water and power : \ncity, year and usage\n");
	scanf("%s%d%lf%s%d%lf",&water.city, &water.year, &water.usage,&power.city,&power.year,&power.usage);
	
	printf("\n\nThe water and power are : \n%s\n%d\n%4.01f million liters\n\n%s\n%d\n%4.01lf mega watts\n", 
	water.city, water.year, water.usage,power.city,power.year,power.usage);

}


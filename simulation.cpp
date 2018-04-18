#include<stdio.h>

float timeFaultNotMod, timeFaultMod, memoryAccessTime, pageMod, pageNotMod;

void faultRate()
{
	float pageFaultRate;
	pageFaultRate = (200 - memoryAccessTime)/(memoryAccessTime - (pageMod*timeFaultMod) - (pageNotMod*timeFaultNotMod));
	printf("Page Fault Rate is : %f",pageFaultRate);
}

int main()
{
	
	printf("Enter TIME TAKEN to service a PAGE FAULT if replaced page is NOT MODIFIED (in milliseconds) :\n");
	scanf("%f", &timeFaultNotMod);
	printf("Enter TIME TAKEN to service a PAGE FAULT if replaced page is MODIFIED (in milliseconds)) :\n");
	scanf("%f", &timeFaultMod);
	timeFaultNotMod = timeFaultNotMod*1000000;		//converted from milliseconds to nanoseconds
	timeFaultMod = timeFaultMod*1000000;
	printf("Enter Memory Access Time :\n");
	scanf("%f",&memoryAccessTime);
	printf("Enter Percentage of Modification in page : \n");
	scanf("%f",&pageMod);
	pageMod = pageMod/100;
	pageNotMod = 1-pageMod;
	faultRate();
}


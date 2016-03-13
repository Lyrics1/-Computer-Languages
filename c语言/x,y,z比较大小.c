#include<stdio.h>
main()
{
	int x,y,z,min;
	printf("please input x y z\n");
	scanf("%d%d%d",&x,&y,&z);
	if (x>y&&z>y)
	min=y;
	if (y>x&&z>x)
	min=x;
	if (x>z&&y>z)
	min=z;
	printf("min=%d",min);

}

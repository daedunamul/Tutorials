#include <stdio.h>
int main( int argc , char **argv )
{
	int Count1 , Count2 , Temp , ArrayToSort[ 10 ] ;
	
	for( Count1 = 0 ; Count1 < 10 ; Count1 ++ )
	{
		printf( "ArrayToSort[ %d ] : " , Count1 ) ;
		scanf( "%d" , ArrayToSort + Count1 ) ;
		printf( "\n" ) ;
	}
	
	// ascending
	for( Count1 = 10 ; Count1 > 1 ; Count1 -- )
	{
		for( Count2 = 0 ; Count2 < ( Count1 - 1 ) ; Count2 ++ )
		{
			if( ArrayToSort[ Count2 ] > ArrayToSort[ Count2 + 1 ] )
			{
				Temp = ArrayToSort[ Count2 ] ;
				ArrayToSort[ Count2 ] = ArrayToSort[ Count2 + 1 ] ;
				ArrayToSort[ Count2 + 1 ] = Temp ;
			}
		}
	}
	
	for( Count1 = 0 ; Count1 < 10 ; Count1 ++ )
		printf( "%d " , ArrayToSort[ Count1 ] ) ;
	printf( "\n" ) ;
	
	return 0 ;
}

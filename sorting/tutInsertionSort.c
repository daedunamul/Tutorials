#include <stdio.h>

int main( int argc , char **argv )
{
	int Count1 , Count2 , Count3 , Key , ArrayToSort[ 10 ] ;
	
	for( Count1 = 0 ; Count1 < 10 ; Count1 ++ )
	{
		printf( "ArrayToSort[ %d ] : " , Count1 ) ;
		scanf( "%d" , ArrayToSort + Count1 ) ;
	}
	
	// ascending
	for( Count1 = 1 ; Count1 < 10 ; Count1 ++ )
	{
		Key = ArrayToSort[ Count1 ] ;
		
		for( Count2 = Count1 - 1 ; Count2 >= 0 && Key < ArrayToSort[ Count2 ] ; Count2 -- )
			ArrayToSort[ Count2 + 1 ] = ArrayToSort[ Count2 ] ;
		ArrayToSort[ Count2 + 1 ] = Key ;
		
		for( Count3 = 0 ; Count3 < 10 ; Count3 ++ )
			printf( "%d " , ArrayToSort[ Count3 ] ) ;
		printf( "\n" ) ;
	}
	
	return 0 ;
}

#include <stdio.h>

int main( int argc , char **argv )
{
	int Count , ResultCount , ArrayToSort[ 10 ] , StartIndex , EndIndex , PivotIndex , LeftIndex , RightIndex , Temp , Stack[ 10 ] ;
	
	for( Count = 0 ; Count < 10 ; Count ++ )
	{
		printf( "ArrayToSort[ %d ] : " , Count ) ;
		scanf( "%d" , ArrayToSort + Count ) ;
	}
	
	// push
	Count = 0 ;
	Stack[ Count ++ ] = 0 ;
	Stack[ Count ++ ] = 9 ;
	
	while( Count > 0 )
	{
		// pop
		EndIndex = Stack[ -- Count ] ;
		StartIndex = Stack[ -- Count ] ;
		if( StartIndex - EndIndex == 0 )
			continue ;
		
		// partition
		PivotIndex = StartIndex ;
		LeftIndex = StartIndex ;
		RightIndex = EndIndex ;
		while( LeftIndex < RightIndex )
		{
			while( LeftIndex < RightIndex && ArrayToSort[ RightIndex ] >= ArrayToSort[ PivotIndex ] )
				RightIndex -- ;
			while( LeftIndex < RightIndex && ArrayToSort[ LeftIndex ] <= ArrayToSort[ PivotIndex ] )
				LeftIndex ++ ;
			
			// swapping Left for Right
			Temp = ArrayToSort[ LeftIndex ] ;
			ArrayToSort[ LeftIndex ] = ArrayToSort[ RightIndex ] ;
			ArrayToSort[ RightIndex ] = Temp ;
		}
		// swapping Pivot for Left
		Temp = ArrayToSort[ PivotIndex ] ; 
		ArrayToSort[ PivotIndex ] = ArrayToSort[ LeftIndex ] ;
		ArrayToSort[ LeftIndex ] = Temp ;
		PivotIndex = LeftIndex ;
		
		// push
		if( PivotIndex - StartIndex > 1 )
		{
			Stack[ Count ++ ] = StartIndex ;
			Stack[ Count ++ ] = PivotIndex - 1 ;
		}
		if( EndIndex - PivotIndex > 1 )
		{
			Stack[ Count ++ ] = PivotIndex + 1 ;
			Stack[ Count ++ ] = EndIndex ;
		}
		
		for( ResultCount = 0 ; ResultCount < 10 ; ResultCount ++ )
			printf( "%d " , ArrayToSort[ ResultCount ] ) ;
		printf( "\n" ) ;
	}
	
	return 0 ;
}

/* HOW TO RUN :
 * 	$ cc <program_name> ;
 * 	$ ./a.out ;
 *
 * WHAT PROG DOES :
 * 	>Example : If given n=3 & r=4 , then it generates this : 1 1 1 1
 * 								 1 1 1 2
 * 								 1 1 1 3
 *
 * 								 1 1 2 1
 * 								 1 1 2 2
 * 								 1 1 2 3
 *
 * 								 1 1 3 1
 * 								 1 1 3 2
 * 								 1 1 3 3
 * 								 ..
 * 								 ..
 * 							
 * 	>So it prints all permutations of first 'n' integers, taken 'r' at a time.
 *
 * NOTES :
 * 	>I have not done error_checking on the values of 'n' and 'r', right now assuming that the user
 * 	of will give it appropriately.
 */

#include<stdio.h>
#include<stdlib.h>

int n,r ;
int *arr;

/***************************************************************/
void print_array( int *arr ){
	int i;
	printf("[ " );
	for( i=0 ; i<r ; i++ ){
		printf("%d " , arr[i] );

	}
	printf("]\n" );

}
/***************************************************************/
void sample_generator( int current_arr_pos ){

	if( current_arr_pos > (r-1) ) return ;

	if( current_arr_pos == (r-1) ){
		/*Here instead of using recursion , we can use a loop to print the final column's numbers */
		while( arr[current_arr_pos] < (n+1)  ){
			sample_generator(current_arr_pos+1);
			print_array( arr );
			arr[current_arr_pos]++;

		}
		printf("**\n" );
		
		arr[current_arr_pos]=1;

	}
	else{
		while( arr[current_arr_pos] < (n+1) ){
			sample_generator(current_arr_pos+1);
			arr[current_arr_pos]++;
		}
		arr[current_arr_pos]=1;

	}
}
/***************************************************************/
int main(){
	n=2;
	r=3;
	arr=(int *)malloc(r*sizeof(int) );

	int i;
	for(i=0 ; i<r ; i++ )
		arr[i]=1;

	sample_generator( 0 );

return 0;

}

/* WHAT PROG DOES :
 * 	>Prints r-bit binary nos.
 * 	>This prog is same as the "./sample_gen.c" , with value of 'n' ranging from 0-1.
 *
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
		while( arr[current_arr_pos] < (n+1)  ){
			sample_generator(current_arr_pos+1);
			print_array( arr );
			arr[current_arr_pos]++;

		}
		printf("**\n" );
		
		arr[current_arr_pos]=0;

	}
	else{
		while( arr[current_arr_pos] < (n+1) ){
			sample_generator(current_arr_pos+1);
			arr[current_arr_pos]++;
		}
		arr[current_arr_pos]=0;

	}
}
/***************************************************************/
int main(){
	n=1;
	/*dont alter this value */

	r=4;
	arr=(int *)malloc(r*sizeof(int) );

	int i;
	for(i=0 ; i<r ; i++ )
		arr[i]=0;

	sample_generator( 0 );

return 0;

}

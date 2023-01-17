#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

float rand_float(float min, float max){
	return rand()/((float) RAND_MAX)*(max-min)+min;
}

int main(){

	srand( time( NULL ) );
	
	size_t N =  100000000;
	
	float x = 0.0f;
	for(size_t i = 0 ; i < N ; i++){

		float old_x = x;
		float vrand = rand_float(0, 20);

		x += vrand;

		if (vrand != 0 && old_x == x){

			printf("Old : %.40f\nNew : %.40f\n\n", old_x, x);
			printf("-1\n");
			return -1;
		}
	}
	x = x / N;
	
	printf("%f\n", x);

	return 0;
}

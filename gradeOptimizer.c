/*
 * =====================================================================================
 *
 *       Filename:  gradeOptimizer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2016 17:30:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

void bcs(double hw, double qz, double mt, double fe);
void wcs(double hw, double qz, double mt, double fe);

int main(){
	double hw;
	double qz;
	double mt;
	double fe;
	
	printf("Homework Average > ");
	scanf("%lf", &hw);
	
	printf("Quizzes Average > ");
	scanf("%lf", &qz);

	printf("Midterm Exam Score > ");
	scanf("%lf", &mt);
	
	printf("Final Exam Score > ");
	scanf("%lf", &fe);

	bcs(hw,qz,mt,fe);
	wcs(hw,qz,mt,fe);
	return 0;
}

void bcs(double hw, double qz, double mt, double fe){
	double max = 0;
	int j;
	for(j = 10; j <=  20; j++){
		int k;
		for(k = 15; k <= 30; k++){
			int l;
			for(l = 15; l <= 30; l++){
				int m;
				for(m = 20; m <= 50; m++){
					int sum = j + k + l + m;
					if(sum == 100){
						double hw_val = hw * j;
						double qz_val = qz * k;
						double mt_val = mt * l;
						double fe_val = fe * m;
						double grade = hw_val + qz_val + mt_val + fe_val;
						if(grade > max){
							max = grade;
						}
						break;
					}
				}
			}
		}
	}

	printf("Best case scenario: %.2lf%%\n", max / 100);
}

void wcs(double hw, double qz, double mt, double fe){
	double min = 10000;
	int j;
	for(j = 10; j <=  20; j++){
		int k;
		for(k = 15; k <= 30; k++){
			int l;
			for(l = 15; l <= 30; l++){
				int m;
				for(m = 20; m <= 50; m++){
					int sum = j + k + l + m;
					if(sum == 100){
						double hw_val = hw * j;
						double qz_val = qz * k;
						double mt_val = mt * l;
						double fe_val = fe * m;
						double grade = hw_val + qz_val + mt_val + fe_val;
						if(grade < min){
							min = grade;
						}
						break;
					}
				}
			}
		}
	}

	printf("Worst case scenario: %.2lf%%\n", min / 100);
}

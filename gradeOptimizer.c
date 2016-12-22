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
#include <stdlib.h>

typedef struct{
	char name[50];
	double hw;
	double qz;
	double mt;
	double fe;
}profile;

void bcs(double hw, double qz, double mt, double fe);
void wcs(double hw, double qz, double mt, double fe);
void save_profile(profile p);
void load_profile(profile *p, char n[50]);

int main(){
	// homework
	double hw;
	// quizzes
	double qz;
	// midterm
	double mt;
	// final exam
	double fe;

	char hasProfile;

	printf("Do you have a profile? [Y/N] > ");
	scanf("%c", &hasProfile);

	profile temp;

	if(!((int)hasProfile % 89 == 0)){
		// enter in terms of percentage
		// i.e. if my homework is 96/100
		// I would enter 96
		// or if my homework was 48/50
	
		// I would also enter 96
		printf("Homework Average > ");
		scanf("%lf", &hw);
	
		printf("Quizzes Average > ");
		scanf("%lf", &qz);

		printf("Midterm Exam Score > ");
		scanf("%lf", &mt);
	
		printf("Final Exam Score > ");
		scanf("%lf", &fe);
		
		char tn[50];
		printf("Profile name(Enter NULL to not make a profile)> ");
		char g;
		scanf("%s%c",tn,&g);
		if(!(strcmp(tn,"NULL")==0)){
			strcpy(temp.name,tn);
			temp.hw = hw;
			temp.qz = qz;
			temp.mt = mt;
			temp.fe = fe;
			save_profile(temp);
		}
	}else{
		char name[50];
		printf("What is your profile name? > ");
		scanf("%s",name);
		load_profile(&temp, name);
		hw = temp.hw;
		qz = temp.qz;
		mt = temp.mt;
		printf("Final Exam Score > ");
		scanf("%lf", &fe);
	}
	// best case scenario grade
	bcs(hw,qz,mt,fe);
	// worst case scenario grade
	wcs(hw,qz,mt,fe);
	return 0;
}

// prints the best case scenario grade based on the data given
void bcs(double hw, double qz, double mt, double fe){
	double max = 0;
	int j;
	// 10% is the minimum weight for hw and 20% is the max
	for(j = 10; j <=  20; j++){
		int k;
		// 15% is the minimum weight for quizzes and 30% is the max
		for(k = 15; k <= 30; k++){
			int l;
			// 15% is the minimum weight for midterm and 30% is the max
			for(l = 15; l <= 30; l++){
				int m;
				// 20% is the minimum weight for final exam and 50% is the max
				for(m = 20; m <= 50; m++){
					int sum = j + k + l + m;
					// the combined weights must equal 100
					if(sum == 100){
						// calculation of the weighted totals
						double hw_val = hw * j;
						double qz_val = qz * k;
						double mt_val = mt * l;
						double fe_val = fe * m;
						double grade = hw_val + qz_val + mt_val + fe_val;
						// if there is a new maximum grade
						if(grade > max){
							max = grade;
						}
						// break so the sum doesn't become > 100
						break;
					}
				}
			}
		}
	}
	// print of result
	printf("Best case scenario: %.2lf%%\n", max / 100);
}

// same as bcs but minimum
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

void save_profile(profile p){
	FILE *op = fopen("profiles.txt", "a+");
	fprintf(op,"%s,%.2lf,%.2lf,%.2lf,%.2lf\n",p.name,p.hw,p.qz,p.mt,p.fe);
	fclose(op);
}

void load_profile(profile *p, char n[50]){
	FILE *ip = fopen("profiles.txt", "r+");
	char buff[1024];

	while(fgets(buff,1024,ip) != NULL){
		char *s = strtok(buff, ",");
		if(strcmp(s,n)==0){
			strcpy(p->name,s);
			p->hw = atof(strtok(NULL,","));
			p->qz = atof(strtok(NULL,","));
			p->mt = atof(strtok(NULL,","));
			p->fe = atof(strtok(NULL,","));
		}
	}

}

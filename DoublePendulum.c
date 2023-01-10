#include <math.h>
#include <stdio.h>

int main(void) {
	double l1 = 15.0, l2 = 10.0;
	double deg1 = 170.0, deg2 = 120.0;
	double m1 = 1.0, m2 = 1.5;
	double g = -9.8, t = 0.0;
	unsigned long i, cmax = 100000;
	double th1, th2, x1, x2, y1, y2;
	double th1_, th2_, thd1_, thd2_;
	double thd1 = 0.0, thd2 = 0.0, dt = 0.01;
	double thd11, thd12, thd13, thd14, thd21, thd22, thd23, thd24;
		
	th1 = M_PI / 180.0 * deg1;
	th2 = M_PI / 180.0 * deg2;
	
	x1 = l1 * sin(th1);
	x2 = x1 + l2 * sin(th2);
	y1 = l1 * cos(th1);
	y2 = y1 + l2 * cos(th2);
	
	for (i=0; i<cmax; i++) {
		printf("(%f,%f) , (%f,%f)\n", x1, y1, x2, y2);
		thd1_ = thd1;
		thd2_ = thd2;
		th1_ = th1;
		th2_ = th2;
		thd11 = (m1*g*sin(th1_)+m2*((g*sin(th2_)-l1*thd1_*thd1_*sin(th1_-th2_))*cos(th1_-th2_)+l2*thd2_*thd2_*sin(th1_-th2_)+g*sin(th1_)))/(m1+m2*sin(th1_-th2_)*sin(th1_-th2_))/l1;
		thd21=((m1+m2)*(g*sin(th2_)+g*sin(th1_)*cos(th1_-th2_)-l1*thd1_*thd1_*sin(th1_-th2_))+m2*l2*thd2_*thd2_*sin(th1_-th2_)*cos(th1_-th2_))/(m1+m2*sin(th1_-th2_)*sin(th1-th2_))/l2;
		th1_+=thd11*dt/2.0;
		th2_+=thd21*dt/2.0;
		thd12=(m1*g*sin(th1_)+m2*((g*sin(th2_)-l1*thd1_*thd1_*sin(th1_-th2_))*cos(th1_-th2_)+l2*thd2_*thd2_*sin(th1_-th2_)+g*sin(th1_)))/(m1+m2*sin(th1_-th2_)*sin(th1_-th2_))/l1;
		thd22=((m1+m2)*(g*sin(th2_)+g*sin(th1_)*cos(th1_-th2_)-l1*thd1_*thd1_*sin(th1_-th2_))+m2*l2*thd2_*thd2_*sin(th1_-th2_)*cos(th1_-th2_))/(m1+m2*sin(th1_-th2_)*sin(th1-th2_))/l2;
		th1_+=(thd12-thd11)*dt/2.0;
		th2_+=(thd22-thd21)*dt/2.0;
		thd13=(m1*g*sin(th1_)+m2*((g*sin(th2_)-l1*thd1_*thd1_*sin(th1_-th2_))*cos(th1_-th2_)+l2*thd2_*thd2_*sin(th1_-th2_)+g*sin(th1_)))/(m1+m2*sin(th1_-th2_)*sin(th1_-th2_))/l1;
		thd23=((m1+m2)*(g*sin(th2_)+g*sin(th1_)*cos(th1_-th2_)-l1*thd1_*thd1_*sin(th1_-th2_))+m2*l2*thd2_*thd2_*sin(th1_-th2_)*cos(th1_-th2_))/(m1+m2*sin(th1_-th2_)*sin(th1-th2_))/l2;
		th1_+=(thd13-thd12/2.0)*dt;
		th2_+=(thd23-thd22/2.0)*dt;
		thd14=(m1*g*sin(th1_)+m2*((g*sin(th2_)-l1*thd1_*thd1_*sin(th1_-th2_))*cos(th1_-th2_)+l2*thd2_*thd2_*sin(th1_-th2_)+g*sin(th1_)))/(m1+m2*sin(th1_-th2_)*sin(th1_-th2_))/l1;
		thd24=((m1+m2)*(g*sin(th2_)+g*sin(th1_)*cos(th1_-th2_)-l1*thd1_*thd1_*sin(th1_-th2_))+m2*l2*thd2_*thd2_*sin(th1_-th2_)*cos(th1_-th2_))/(m1+m2*sin(th1_-th2_)*sin(th1-th2_))/l2;
		thd1+=(thd11+thd12*2.0+thd13*2.0+thd14)/6.0*dt;
		thd2+=(thd21+thd22*2.0+thd23*2.0+thd24)/6.0*dt;
		th1 += thd1 * dt;
		th2 += thd2 * dt;
		t += dt;

		x1 = l1 * sin(th1);
		x2 = x1 + l2 * sin(th2);
		y1 = l1 * cos(th1);
		y2 = y1 + l2 * cos(th2);
	}
	printf("(%f,%f) , (%f,%f)\n", x1, y1, x2, y2);
	return 0;
}
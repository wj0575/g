#include<iostream>
#include<math.h>
using namespace std;

double linearMapping(int in, int in_min, int in_max, float out_min, float out_max){
	double k = (out_max - out_min)/(in_max - in_min);
	return (in - in_min) * k + out_min;
}

int ratio_1 = 19;
int ratio_ = 19;
double ecd_angle_1,delta_ecd_angle_1,last_ecd_angle_1,delta_angle_1,angle_1;
float ecd_angle_,delta_ecd_angle_,last_ecd_angle_,delta_angle_,angle_;

double st(int a){
	ecd_angle_1 = linearMapping(a,0,8191,0,360);
	delta_ecd_angle_1 = ecd_angle_1 - last_ecd_angle_1;
	if(delta_ecd_angle_1 < 0){
        delta_ecd_angle_1 += 360;
    }
    delta_angle_1 = delta_ecd_angle_1 / ratio_1;
	angle_1 += delta_angle_1;
	if(angle_1 > 360){
		angle_1 -= 360;
	}
	return angle_1;
} //标准解析函数 

float test(int b){
	ecd_angle_ = linearMapping(b,0,8191,0,360);
	delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
	if(delta_ecd_angle_ < 0){
        delta_ecd_angle_ += 360;
    }
    delta_angle_ = delta_ecd_angle_ / ratio_;
	angle_ += delta_angle_;
	if(angle_ > 360){
		angle_ -= 360;
	}
	return angle_;
} //float类型下的测试函数 

double dp(){
	int i;
	ecd_angle_1 = delta_ecd_angle_1 = last_ecd_angle_1 = delta_angle_1 = angle_1 = 0;
	ecd_angle_ = delta_ecd_angle_ = last_ecd_angle_ = delta_angle_ = angle_ = 0;
	int r;
	for(i=1; ;i++){
		r = rand() % 8192;
		double ans1 = st(r);
		float ans2 = test(r);
		if(ans1 - ans2 > 1 || ans1 - ans2 < -1){
			break;
		}
		cout<<i<<" ms passed "<<ans1<<" "<<ans2<<endl;
	}
	return i/1000;
} //对比测试函数 

int main(){
	int k = 100;
	int m[k],c,s;
	for(int j=0;j<k;j++){
		m[j] = dp();
		cout<<"test "<<j+1<<" passed "<<m[j]<<" seconds."<<endl;
		c += m[j];
	}
	int ave = c / k;
	for(int j=0;j<k;j++){
		s += (m[j] - ave)*(m[j] - ave);
	}
	cout<<"average time:"<<ave<<" s."<<endl;
	cout<<"deviation:"<<sqrt(s / k)<<endl;
}

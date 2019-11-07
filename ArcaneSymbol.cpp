#include<iostream>
#include<cmath>
using namespace std;
char map_name[6][20]={"소멸의 여로", "츄츄 아일랜드", "레헬른", "아르카나", "모라스", "에스페라"};
int price[20], price0[20], need[20];

class Symbol{
private:
	int level, exp, daily, goal, type;
public:
	void setValue(int _level, int _exp, int _daily, int _goal, int _type){
		level = _level;
		exp = _exp;
		daily = _daily;
		goal = _goal;
		type = _type;
	}
	int getLevel(){
		return level;
	}
	int getExp(){
		return exp;
	}
	int calcTime(){
		int i, exp_sum = 0;
		for(i=level; i<goal;i++){
			exp_sum+= need[i];
		}
		exp_sum -= exp;
		return ceil((double)exp_sum/daily);
	}
	long long calcMeso(){
		int i;
		long long meso_sum = 0;
		if(type == 0){
			for(i=level; i<goal;i++){
				meso_sum += price0[i];
			}
		}
		else{
			for(i=level; i<goal;i++){
				meso_sum += price[i];
			}
		}
		return meso_sum;
	}
};

int main(){
	Symbol sym[6];
	int i, _level, _exp, _daily, _goal, max_date = 0;
    int time[6];
	long long meso[6] ={0}, meso_sum = 0;

    for(i=1;i<20;i++){
		price[i]=12440000+i*6600000;
		price0[i]=2370000+i*7130000;
		need[i]=i*i+11;
	}

	for(i=0;i<6;i++){
		cout << map_name[i] << endl;
		cout << "현재 레벨 : ";
		cin >> _level;
		cout << "경험치 : ";
		cin >> _exp;
		cout << "1일 획득량 : ";
		cin >> _daily;
		cout << "목표 : ";
		cin >> _goal;
		sym[i].setValue(_level, _exp, _daily, _goal, i);
	}
    for(i=0;i<6;i++){
        time[i] = sym[i].calcTime();
        meso[i] = sym[i].calcMeso();
        if(time[i] > max_date) max_date = time[i];
    }
	for(i=0;i<6;i++){
        cout << map_name[i] << endl;
        cout << "업그레이드 시간 : " << time[i] << "일" << endl;
	    cout << "업그레이드 금액 : " << meso[i] << "메소" << endl;
    }

	cout << endl << "업그레이드 금액 합계 : " << meso_sum << endl;
	cout << "최대 소요 시간" << max_date << endl;
	return 0;
}

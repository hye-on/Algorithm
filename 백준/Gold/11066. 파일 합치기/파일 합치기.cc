#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1000000000

int T, K;
int sum[501], file[501], dp[501][501];
//dp[x][y] : x~y번째 파일들을 합치는데 필요한 최소비용.

//sum[x] : 1~x번째 파일까지의 크기 합.

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i <= K; i++) // 파일의 범위
		{
			for (int j = 1; j <= K - i; j++) // 파일구간의 시작 인덱스
			{
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++)// j 부터 j+i까지 구간을 k를 기준으로 분할하기 sum[i + j] - sum[j - 1] 마지막 두 파일을 합치는 비용
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << endl;

	}

}



//#include<iostream>
//#include<algorithm>
//using namespace std;
//int T, n, sum ;
//int file[500];
//int file2[250];
//int main()
//{
//	
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> file[i];
//			//cout << file[i] << endl;
//		}
//		sort(file, file + n);
//		for (int i = 0; i < n; i++)
//			cout << file[i] << "  ";
//		cout << endl;
//	//	cout << file[0] << " " << file[1] << endl;
//		bool check = true; //file 과 file2 를 번갈아 가면서 합치기 위해서
//		int index = 0;
//		int page = n;
//		while (page>=2)
//		{
//
//			if (check)
//			{
//				file2[0] = file[0] + file[1];
//				sum += (file[0] + file[1]);
//				cout <<"sum1     "<< file[0] + file[1] <<"   "<< sum << endl;
//				for (int i = 2; i < page; i++)
//				{
//					/*if ( i == n - 1)
//					{
//						file2[0] += file[n - 1];
//						sum += file2[0];
//						cout << "sum2     " << sum << endl;
//						break;
//					}*/
//					if (file2[index] + file[i] <= file[i] + file[i + 1])//새로운 파일을 두개 합치는 것보다 이전의 합친 파일에 한파일을 합치는 것이 더 작다면
//					{
//						file2[index] += file[i];
//						sum += file2[index];
//						cout << "sum3     " << file2[index]  <<"  "<< sum << endl;
//					}
//					else
//					{
//						file2[index + 1] = file[i] + file[i + 1];
//						sum += file2[index + 1];
//						cout << "sum4     " << file2[index + 1] <<"  "<< sum << endl;
//						index++;
//						i++;
//					}
//				}
//				
//				//for (int i = 0; i < n / 2; i++)
//				//{
//				//	
//				//	file2[i] = file[i * 2] + file[i * 2 + 1];// 0 <-01  1 <- 23  2<- 45 
//				//	sum += file2[i];
//				//}
//
//				////만약 홀수이면 맨 마지막 파일을 file2[0]이랑 합쳐주기
//				//if (n % 2)
//				//{
//				//	sum += (file2[0] + file[n - 1]);
//				//	file2[0] += file[n - 1];
//				//	
//				//}
//				check = false;
//			}
//			else
//			{
//				file[0] = file2[0] + file2[1];
//				sum += (file2[0] + file2[1]);
//				cout << "sum22  " << sum <<"   "<<file[0]<< endl;
//				for (int i = 2; i < page; i++)
//				{
//					/*if (n % 2 == 1 && i == n - 1)
//					{
//						file[0] += file2[n - 1];
//						sum += file[0];
//						cout << "sum5     " << sum << endl;
//						break;
//					}*/
//					if (file[index] + file2[i] <= file2[i] + file2[i + 1])//새로운 파일을 두개 합치는 것보다 이전의 합친 파일에 한파일을 합치는 것이 더 작다면
//					{
//						file[index] += file2[i];
//						sum += file[index];
//						cout << "sum6     " << file[index] <<"  "<< sum << endl;
//					}
//					else
//					{
//						file[index + 1] = file2[i] + file2[i + 1];
//						sum += file[index + 1];
//						cout << "sum7     "<<file[index+1]<<"  " << sum << endl;
//						index++;
//						i++;
//					}
//				}
//
//				//for (int i = 0; i < n / 2; i++)// n=5  <2 0,1
//				//{
//				//	file[i] = file2[i * 2] + file2[i * 2 + 1];// 0 <-01  1 <- 23   
//				//	sum += file[i];
//				//}
//
//				////만약 홀수이면 맨 마지막 파일을 file[0]이랑 합쳐주기
//				//if (n % 2)
//				//{
//				//	sum +=( file[0]+file2[n - 1]);
//				//	file[0] += file2[n - 1]; // file[0]  file2[4]
//				//	
//				//}
//				check = true;
//
//			}
//			for (int i = 0; i <= index; i++)
//			{
//				if(!check)
//					cout << file2[i] << "  ";
//				else
//					cout << file[i] << "  ";
//			}
//			cout << endl;
//			//n /= 2;
//			page = index+1;
//			cout <<" page  "<< page << endl;
//			index = 0;
//			cout << endl;
//		}
//
//		cout << sum << endl;
//		sum = 0;
//	}
//}
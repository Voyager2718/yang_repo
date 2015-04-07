
#include<iostream>
#include<string>
#include<math.h>
#include<Windows.h>
#include<assert.h>

using namespace std;

namespace yang{
	//数组长度
#define ArrLength(s) (sizeof(s) / sizeof(s[0]))

	//数组复制
	template<class T>void ArrCpy(T Destination[], T Origin[], int Size_of_Ori_arr){
		for(int i = 0 ; i < Size_of_Ori_arr ; i++)
			Destination[i] = Origin[i];
	}

	//取最大值
	template<class T>T Max(T a,T b){
		return a>b?a:b;
	}

	//取最大值
	template<class T>T Max(T arr[],int Size_of_arr){
		T m = arr[0];
		for (int k = 0 ; k < Size_of_arr ; k++) m = Max(m,arr[k]);
		return m;
	}

	//取最小值
	template<class T>T Min(T a,T b){
		return a<b?a:b;
	}

	//取最小值
	template<class T>T Min(T arr[],int Size_of_arr){
		T m = arr[0];
		for (int k = 0 ; k < Size_of_arr ; k++) m = Min(m,arr[k]);
		return m;
	}

	//取平均值
	template<class T>float Avg(T arr[],int Size_of_arr){
		float a =(float) arr[0];
		for( int i = 1; i < Size_of_arr; i++){
			a = a + arr[i];
		}
		return a/Size_of_arr;
	}

	//调换A/B的值
	template<class T>void Swap(T &A, T &B){
		T C = A;
		A = B;
		B = C;
	}

	//快速排序法
	template<class T>void QuickSort(T Data[], int Left, int Right){//注意，Right是右界，不是大小。
		int i = Left, j = Right;
		T Pivot = Data[(Left+Right)/2];
		do{
			while (Data[i] < Pivot)
				i++;
			while (Data[j] > Pivot)
				j--;
			if ( i <= j ){
				Swap(Data[i],Data[j]);
				i++;
				j--;
			}
		}while ( i <= j );
		if(Left < j)
			QuickSort( Data, Left, j);
		if(i < Right)
			QuickSort( Data, i, Right);
	}

	//插入排序法
	template<class T>void InsertionSort(T Data[], int Size_of_arr){
		int k, j, itemk, times = 0;
		for( k = 1; k < Size_of_arr; k++){
			itemk = Data[k];
			j = k - 1;
			while (j >= 0 && itemk < Data[j] )
			{
				Data[j+1] = Data[j];
				j--;
			}
			Data[j+1] = itemk;
		}
	}

	//选择排序法
	template<class T>void SelectionSort(T Data[], int Size_of_arr){
		int  min;
		for(int i = 0 ; i < Size_of_arr - 1 ; i++){
			min = i;
			for (int j = i + 1 ; j < Size_of_arr ; j++)
				if( Data[j] < Data[min])
					min = j;
			if( min != i)
				Swap(Data[min], Data[i]);
		}
	}

	//希尔排序
	template<class T>void ShellSort(T Data[], int Size_of_arr){
		int i,j, gap;
		T temp;
		for( gap = Size_of_arr >>1 ; gap >0 ; gap >>= 1 ){
			for ( i = gap ; i < Size_of_arr ; i++){
				temp = Data[i];
				for (j = i - gap; j >= 0 && Data[j] > temp  ; j-= gap)
					Data[ j + gap ] = Data[j];
				Data[j + gap] = temp;
			}
		}
	}

	//归并排序
	template<class T>void FusionSort(T Data[], int Size_of_arr){

	}

	//冒泡排序
	template<class T>void BubbleSort(T Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr ; i++)
			for( int j = 0; j < Size_of_arr - 1 ; j++)
				if ( Data[j] > Data[j+1])
					Swap(Data[j],Data[j+1]);
	}

	//数组倒序
	template<class T>void InvArr(T Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr / 2 ; i++){
			Swap( Data[ i ], Data[ Size_of_arr - i -1 ]);
		}
	}

	//升序？
	template<class T>bool IsAsc(T Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr-1 ; i++)
			if(Data[i]>Data[i+1])
				goto False;
		if(false){
False:
			return false;
		}
		return true;
	}

	//降序？
	template<class T>bool IsDes(T Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr-1 ; i++)
			if(Data[i]<Data[i+1])
				goto False;
		if(false){
False:
			return false;
		}
		return true;
	}

	//打印数组
	template<class T>void PrintArr(T arr[], int Size_of_arr){
		for (int i = 0 ; i < Size_of_arr ; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}

	//阶乘
	__int64 Fact(int Fact){
		__int64 result = 1;
		for(int i = 2 ; i <= Fact ; i++)
			result *= i;
		return result;
	}

	//十进制整数转二进制
	string ToBin(long long Decimal){
		string Binary = "";
		if (Decimal%2==1){
			Binary="1";
			Decimal /= 2;
		}
		while (Decimal != 0){
			if (Decimal%2==1){
				Binary = "1" + Binary;
				Decimal /= 2;
			}
			else{
				Binary = "0" + Binary;
				Decimal /= 2;
			}
		}
		return Binary;
	}

	//二进制整数转十进制-string
	long long ToDec(string Binary){
		long long Decimal = 0;
		for(unsigned int i = 0 ; i < Binary.size() ; i ++ ){
			if (Binary.substr(i,1)=="1"){
				Decimal += long long (pow(2,Binary.size()-i));
			}
		}
		return Decimal/2;
	}

	//返回年份
	int getYear(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wYear;
	}

	//返回月份
	int getMonth(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wMonth;
	}

	//返回日期
	int getDay(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wDay;
	}

	int getHour(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wHour;
	}

	//返回分钟
	int getMinute(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wMinute;
	}

	//返回秒
	int getSecond(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wSecond;
	}

	//返回星期
	int getDayOfWeek(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wDayOfWeek;
	}

	//返回毫秒
	int getMinSec(){
		SYSTEMTIME sys; 
		GetLocalTime( &sys );
		return sys.wMilliseconds;
	}

	//奇数？
	bool IsOdd(int a){
		if(a % 2 == 1)
			return true;
		return false;
	}

	//偶数？
	bool IsEven(int a){
		if(a % 2 == 1)
			return false;
		return true;
	}

	//Complex类
	class Complex{
	private:
		double re, im;

	public:
		Complex(){
			re = 0;
			im = 0;
		}
		Complex(double a){
			this->re = a;
		}
		Complex(const Complex &c){
			this->re = c.re;
			this->im = c.im;
		}
		Complex(double x, double y){
			re = x;
			im = y;
		}
		Complex Plus(Complex a, Complex b){
			return Complex(a.re + b.re,a.im + b.im);
		}
		Complex operator+(Complex a){
			return Complex(this->re + a.re,this->im + a.im);
		}
		Complex Minus(Complex a, Complex b){
			return Complex(a.re - b.re,a.im - b.im);
		}
		Complex operator-(Complex a){
			return Complex(this->re - a.re,this->im - a.im);
		}
		Complex Multiply(Complex a, Complex b){
			return Complex(a.re * b.re - a.im * b.im,a.re * b.im + a.im * b.re);
		}
		Complex operator*(Complex a){
			return Complex(this->re * a.re - this->im * a.im,this->re * a.im + this->im * a.re);
		}
		Complex Divide(Complex a, Complex b){
			return Complex((a.re * b.re + a.im * b.im)/(b.re * b.re + b.im * b.im),(a.im * b.re - a.re * b.im)/(b.re * b.re + b.im * b.im));
		}
		Complex operator/(Complex a){
			return Complex((this->re * a.re + this->im * a.im)/(a.re * a.re + a.im * a.im),(this->im * a.re - this->re * a.im)/(a.re * a.re + a.im * a.im));
		}
		Complex Conjugate(){
			return (Complex(-(this->re),this->im));
		}
		Complex operator!(){
			return (Complex(-(this->re),this->im));
		}
		Complex Square(){
			return Complex((this->re)*(this->re)-(this->im)*(this->im),2*(this->re)*(this->im));
		}
		Complex operator^(int a){
			Complex c(this->re, this->im), d(this->re, this->im);
			for(int i = 0; i < a - 1; i++)
				c = c * d;
			return c;
		}
		double ToDouble(){
			return this->re;
		}
		friend ostream& operator<< (ostream &OST, Complex c);
		friend istream& operator>> (istream &IST, Complex c);
		void printComplex(){
			if(this->re == 0 && this->im == 0)
				printf("0");
			else if(this->re == 0)
				printf("%lfi",this->im);
			else if(this->im>0)
				printf("%lf+%lfi", this->re, this->im);
			else if(this->im==0)
				printf("%lf", this->re);
			else if(this->im<0)
				printf("%lf%lfi", this->re, this->im);
		}
	};

	//Complex类的ostream重载
	ostream& operator<< (ostream &OST, Complex c){
		if(c.re == 0 && c.im == 0)
			OST<<"0";
		else if(c.re == 0)
			OST<<c.im<<"i";
		else if(c.im>0)
			OST<<c.re<<"+"<< c.im<<"i";
		else if(c.im==0)
			OST<<c.re;
		else if(c.im<0)
			OST<<c.re<<c.im<<"i";
		return OST;
	}

	//Complex类的istream重载
	istream& operator>> (istream &IST, Complex c){
		double a, b;
		IST>>a>>b;
		c.re = a;
		c.im = b;
		return IST;
	}

	//任意进制转换

	int getLines(){
		char  ch;
		int i = 0;
		while ((ch = getchar()) != EOF && ch != '\n')
			if (ch == '\n')
				i++;
		return ++i;
	}

	int getBytes(){
		char ch;
		int i = 0;
		while ((ch = getchar()) != EOF && ch != '\n')
			i++;
		return ++i;
	}

	int getWords(){
		char  ch;
		int i = 0;
		while ((ch = getchar()) != EOF && ch != '\n')
			if (ch == ' ')
				i++;
		return ++++i;
	}
};


namespace double_cycle_list{
	struct node{
		int value;
		node *prev, *next;
		node(int value, node *prev = NULL, node *next = NULL) :value(value), prev(prev), next(next){}
	};

	node* CreateList(int value){
		node *List = new node(value);
		List->next = List->prev = List;
		return List;
	}

	void DeleteList(node *List){
		assert(List);
		node *p = List->next, *tmp;
		List->next = p->prev = NULL;
		while (p != List){
			tmp = p->next;
			p->next = tmp->prev = NULL;
			delete p;
			p = tmp;
		}
		delete List;
	}

	node* Find(int value, node *List){
		assert(List);
		node *p = List;
		do{
			if (p->value == value)
				return p;
			else
				p = p->next;
		} while (p != List);
		return NULL;
	}

	//找第n个
	node* Find(int value, int n, node *List){
		assert(List&&n > 0);
		int i = 1;
		node *p = List;
		do{
			if (p->value == value){
				if (i == n)
					return p;
				else{
					i++;
					p = p->next;
				}
			}
			else
				p = p->next;
		} while (p != List);
		return NULL;
	}

	void Delete(int value, node *List){
		assert(List);
		node *p = Find(value, List);
		if (p){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->prev = p->next = NULL;
			delete p;
		}
	}

	void Insert(node *List, int value){
		assert(List);
		node *p = new node(value);
		p->prev = List;
		p->next = List->next;
		List->next->prev = p;
		List->next = p;
	}

	void PrintList(node *List){
		assert(List);
		node *p = List;
		do{
			std::cout << p->value << " ";
			p = p->next;
		} while (p != List);
		std::cout << std::endl;
	}

	int ListSize(node *List){
		assert(List);
		int size = 1;
		node *p = List->next;
		while (p != List)
		{
			size++;
			p = p->next;
		}
		return size;
	}

	void SwitchPlace(int a, int b, node *List){/*有空优化一下*/
		node
			*tmpa = Find(a, List),
			*tmpb = Find(b, List);
		if (!tmpa || !tmpb)
			return;

		node
			*tmp1 = tmpa->next,
			*tmp2 = tmpb->next,
			*tmp3 = tmpa->prev,
			*tmp4 = tmpb->prev,
			*tmp5 = tmpa->prev->next,
			*tmp6 = tmpb->prev->next,
			*tmp7 = tmpa->next->prev,
			*tmp8 = tmpb->next->prev;

		tmpa->prev->next = tmp6;
		tmpb->prev->next = tmp5;
		tmpa->next->prev = tmp8;
		tmpb->next->prev = tmp7;
		tmpa->next = tmp2;
		tmpb->next = tmp1;
		tmpa->prev = tmp4;
		tmpb->prev = tmp3;
	}

	//修改第一个找到的值或改变全部值
	void ChangeValue(int toChange, int value, node *List, bool change_all = false){
		assert(List);
		if (toChange == value)
			return;
		while (Find(toChange, List) != NULL){
			Find(toChange, List)->value = value;
			if (!change_all)
				break;
		}
	}

	//修改第n个的值
	void ChangeValue(int toChange, int value, int n, node *List){
		assert(List&&n > 0);
		int i = 1;
		if (toChange == value)
			return;
		node *p = Find(toChange, n, List);
		if (p)
			p->value = value;
	}

	//直接修改
	void ChangeValue(int value, node *List){
		List->value = value;
	}
}
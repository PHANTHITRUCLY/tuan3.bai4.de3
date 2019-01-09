#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <fstream>
int n=5; // tong so xe o to
int cv[5]; // xe dung hen
int x[5]={1,2,3,4,5};// so thu tu cua xe
int y[5]={6,3,5,7,2};//thoi gian sua chua xe
int z[5]={8,4,15,20,3};//thoi diem ban giao xe
int hieusongay[5]; // songay luu hieu cua z-y;
int tong1;
int tong2;


void Ghifile(FILE *f,const char *duongdan1){ //ghi cac ptu vao file

	f= fopen(duongdan1,"wt");
	if(f==NULL){
		printf("\nKo tao duoc file.");
		exit(0);
	}
	
	printf("\n Nhap tong so luong o to: ");
	scanf("%d",&n);
	fprintf(f,"%d \n",n);
	
	for(int i=0;i<n;i++){
		printf("\nNhap o to thu %d:  ",i+1);
		scanf("%d",&x[i]); // nhap tu phim
		fprintf(f,"%3d",x[i]); //in ra f
	} 
		fprintf(f,"\n");
		printf("\n");
	for(int i=0; i<n; i++){
		printf("\nNhap thoi gian sua chua cua o to thu %d:  ",i+1);
		scanf("%3d",&y[i]); // nhap tu phim
		fprintf(f,"%3d",y[i]); //in ra f
	}
		fprintf(f,"\n");
		printf("\n");
		
	for(int i=0; i<n; i++){
		printf("\nNhap thoi diem ban giao o to thu %d:  ",i+1);
		scanf("%d",&z[i]); // nhap tu phim
		fprintf(f,"%3d",z[i]); //in ra f
	}
			printf("\n");
	fclose(f);
}


void Docfile(const char *duongdan1,const char *duongdan2){
//	int n; // tong so xe o to
//	int x;// so thu tu cua xe
//	int y;//thoi gian sua chua xe
//	int z;//thoi diem ban giao xe
	ifstream doc;
	doc.open(duongdan1);
	fstream ghi;
	ghi.open(duongdan2, ios::out);
	if(doc==NULL) printf("\nKhong doc duoc file");
	else{
		
		printf("\n\nTong sl xe o to la: ");
		doc>>n; // doc tu fghi
		ghi<<n<<endl; // in ra fxuat 
		printf(" %d\n",n); // in ra man hinh
		ghi<<endl;
		
		printf("\n O to: ");
		for(int i=0; i< n; i++){
			
			doc>>x[i];
			ghi<<x[i]<<"\t"; // in ra fxuat
			printf(" %d\t",x[i]);
				
		}
		ghi<<endl;
		
		printf("\nThoi gian sua chua o to: ");
		for(int i=0; i< n; i++){
			
			doc>>y[i];
			ghi<<y[i]<<"\t"; // in ra fxuat
			printf(" %d\t",y[i]);
					
		}
		ghi<<endl;
		
		printf("\nThoi diem ban giao o to: ");
		for(int i=0; i< n; i++){
			
			doc>>z[i];
			ghi<<z[i]<<"\t";
			printf(" %d\t",z[i]);
			
		}
		
	}	
}

void Xuat(){
		for(int i=0; i<n; i++){
			printf("\nXe oto: ");
			printf("%d\t",x[i]);
			printf("\nThoi gian sua xe oto: ");
			printf("%d\t",y[i]);
			printf("\nThoi diem giao xe oto: ");
			printf("%d\t",z[i]);
	
		}
}
void Xuatkq(){
		fstream ghi;
	ghi.open("fxuat.txt", ios::out | ios::app);
		printf("\nTen xe dung hen: ");
		ghi<<"\nTen xe dung hen: "<<endl;
		for(int i=0; i<n;i++){
			printf("%d\t",cv[i]);
			ghi<<cv[i]<<" ";	
		}
			
		printf("\nHieu so ngay xe oto: ");			
		for(int i=0; i<n;i++)
			printf("%d\t",hieusongay[i]);
		
		printf("\nTong so ngay thuc hien: ");	
			printf("%d\t",tong2);
			
		printf("\nTong so xe dung hen: ");
			printf("%d\t",tong1);

	 printf("\nXuat kq thanh cong!\n");
}
void Swap(int &a, int &b)
{
	 int temp;
        temp = a;
     	 a  = b;
         b = temp;
   
}

void Xeptheoz(){
	for(int i=0; i< n-1; i++)
		for(int j=i+1; j < n; j++){
		 if(z[i]>z[j]){
		 	 Swap(x[i],x[j]);
			 Swap(y[i],y[j]);
		 	 Swap(z[i],z[j]);
		 }
		}
}

void Sapxep(){
		int tamx, tamy, tamz;
		tong1=0; // tong so xe giao dung hen
		tong2=0;// tong so ngay thuc hien
	
	 for(int i=0; i< n; i++){
			
		hieusongay[i]= z[i] - y[i];
		
			
			if( (tong2 + y[i]) <= z[i] ){
				tong2+=y[i];
				tong1+=1;
				printf("\nNhap cv thanh cong!\n");
				
				cv[i]=x[i];	
				printf("\n%d",cv[i]);
				
			}
			else{
				if (i== n-1) {
					n--;
					return;
				}
				tamx = x[i];
				tamy = y[i];
				tamz = z[i];
				for(int j = i; j < n; j++)
				if(j== (n-1)){
					x[j] = tamx;
					y[j] = tamy;
					z[j] = tamz;
				}
				else{					
				
				x[j] = x[j+1];
				y[j] = y[j+1];
				z[j] = z[j+1];
			}
			i--;
			}

}
}

int main(){
	FILE*fa;
	const char *duongdan1 = "D:/Thuctap/GIBHUB/tuan3/fghi.txt";
	const char *duongdan2 = "D:/Thuctap/GIBHUB/tuan3/fxuat.txt";
	
//	Ghifile(fa,duongdan1); // tu tao file nhap du lieu tu ban phim
	printf("\nDoc file : \n");
	Docfile(duongdan1,duongdan2);
	printf("Da doc va ghi file xong!");
	Xuat();	
	
	printf("\nBat dau xep: \n"); 
	Xeptheoz();
	printf("\nKQ sau khi sx: \n");
	Xuat();
	
	printf("\nBat dau tinh: \n");
	Sapxep();
	Xuatkq();
	printf("\nKQ: \n");
	Xuat();
	getch();
}

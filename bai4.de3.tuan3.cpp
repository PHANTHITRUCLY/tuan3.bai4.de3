#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <fstream>
#define so 9 // so luong

int n; // tong so xe o to
int cv[so]; // xe dung hen
int x[so];//={1,2,3,4,5};// so thu tu cua xe (ten xe)
int y[so];//={6,3,5,7,2};//thoi gian sua chua xe
int z[so];//={8,4,15,20,3};//thoi diem ban giao xe
int hieusongay[so]; // luu hieu so ngay cua z-y;
int songaythua[so]; // so ngay thua ra sau moi lan sua chua xe
int tong1;
int tong2;
int ktratre[so]; // ktra xe nao tre hen de in ra xe tre han
int demxe=0;
int t;
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
//	 n;  tong so xe o to
//	 x; so thu tu cua xe
//	 y; thoi gian sua chua xe
//	 z; thoi diem ban giao xe
	ifstream doc;
	doc.open(duongdan1);
	fstream ghi;
	ghi.open(duongdan2, ios::out);
	if(doc==NULL) printf("\nKhong doc duoc file");
	else{
		
		printf("\n\nTong sl xe o to la: ");
		doc>>n; // doc tu fghi
		ghi<<n; // in ra fxuat 
		printf(" %d\n",n); // in ra man hinh
		ghi<<endl;
		
		printf("\n O to:\t\t\t ");
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
		
	}	 // ko close file de xuong duoi co the ghi tiep noi dung vao
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

void Xuatfilekq(){ // tiep tuc ghi noi dung vao file kq
		fstream ghi;
		ghi.open("fxuat.txt", ios::out | ios::app); // ios::app khai bao de tiep tuc ghi vao file o tren.
		
		printf("\n+Tong so xe dung hen: ");
		ghi<<"\n+Tong so xe dung hen: ";
		printf("%d\t",tong1);
		ghi<<tong1;
		
		printf("\n-Ten xe dung hen: \t");
		ghi<<"\n-Ten xe dung hen:  ";
		for(int i=0; i<n;i++){
			if(ktratre[i]==0){
				printf("%d\t",cv[i]);
				ghi<<cv[i]<<" ";					
			}

		}
	
			//-----------------------------Phan chi xuat ra man hinh
			printf("\n-Hieu so ngay xe oto:\t");			
			for(int i=0; i<n;i++)
			if(ktratre[i]==0)
			printf("%d\t",hieusongay[i]);					
			printf("\n-So ngay con du\nsau moi lan sua xe oto: ");			
			for(int i=0; i<n;i++)
			if(ktratre[i]==0)
			printf("%d\t",songaythua[i]);
			//------------------------------------------------------
			
		printf("\n-Tong so ngay thuc hien: ");
		ghi<<"\n-Tong so ngay thuc hien: ";	
		printf("%d\t",tong2);
		ghi<<tong2;
			
		printf("\n+Tong so xe tre hen: ");
		ghi<<"\n+Tong so xe tre hen: ";
		printf("%d\t",demxe);
		ghi<<demxe;
			
		if(demxe!=0){
		printf("\n-Ten xe tre hen: ");
		ghi<<"\n-Ten xe tre hen: ";
		for(int i=0; i<n; i++){
		 if(ktratre[i]==1){
		 printf(" %d \t",x[i]);
		 ghi<<x[i]<<"  ";		
		  }
		 }
		}else {
			printf("\nKhong co xe tre hen!");
			ghi<<"\nKhong co xe tre hen!";
		}
			
		printf("\n\nThu tu cua xe oto: \n");
		  printf("\nXe oto:\t\t\t ");
		  ghi<<"\nXe oto:\t\t\t ";
		for(int i=0; i<n; i++){
			printf("%d\t",x[i]);
			ghi<<x[i]<<"  ";
		}
		  printf("\nThoi gian sua xe oto:\t ");
		  ghi<<"\nThoi gian sua xe oto:\t ";
		for(int i=0; i<n; i++){
			printf("%d\t",y[i]);
			ghi<<y[i]<<"  ";
		}
		  printf("\nThoi diem giao xe oto:   ");
		  ghi<<"\nThoi diem giao xe oto:   ";
		for(int i=0; i<n; i++){
			printf("%d\t",z[i]);
			ghi<<z[i]<<"  ";
		}
					
	 printf("\n\nXuat kq thanh cong!\n\n");
	 
}

void Swap(int &a, int &b) 
{
	 int temp;
        temp = a;
     	 a  = b;
         b = temp;
   
}

void Xeptheoz(){ // xep thu tu cua xe oto theo thoi diem giao xe
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
		int tamx, tamy, tamz, tamkt;
		tong1=0; // tong so xe giao dung hen
		tong2=0;// tong so ngay thuc hien
	
	 for(int i=0; i< n; i++){
			
		
					// neu tong so ngay t_hien truoc do + so ngay t_hien cua xe thu i 
			if( (tong2 + y[i]) <= z[i] ){ //< = thoi diem giao xe cua xe thu i, thi:
				tong2+=y[i]; 
				tong1+=1;
				printf("\nNhap cv thanh cong!\n");
				ktratre[i] = 0;
				cv[i]=x[i];	
				printf("\n %d",cv[i]);
				songaythua[i]= z[i] - tong2;
				hieusongay[i]= z[i] - y[i]; 
			}
			else if( ktratre[i] != 1){
			//khong thoa man dkien
				ktratre[i] = 1;
				demxe+=1;	
				tamx = x[i];//gan sang bien tam
				tamy = y[i];
				tamz = z[i];
				tamkt = ktratre[i];
				for(int j = i; j < n; j++){ //xet tai vi tri hien tai cua xe
				if(j== (n-1)){  // neu no dang vi tri cuoi thi = chinh no
					x[j] = tamx;
					y[j] = tamy;
					z[j] = tamz;
					ktratre[j] = tamkt;
						
					//	demxe+=1; // dem tong xe tre hen
						//	ktratre[t]=1;
				} else{				// nguoc lai, chuyen xe ra sau 1 j, vi tri j+1
				
					x[j] = x[j+1];
					y[j] = y[j+1];
					z[j] = z[j+1];
					ktratre[j] = ktratre[j+1];
				
				 }			 
		}
			i--;			
			}

		}
}

int main(){
	FILE*fa;
	const char *duongdan1 = "fghi.txt";
	const char *duongdan2 = "fxuat.txt";
	
//	Ghifile(fa,duongdan1); // tu tao file nhap du lieu tu ban phim
	printf("\nDoc file : \n");
	Docfile(duongdan1,duongdan2);
	printf("\n\nDa doc va ghi file xong!\n");
	Xuat();	
	
	printf("\nBat dau xep: \n"); 
	Xeptheoz();
	printf("\nKQ sau khi sx: \n");
	Xuat();	
	printf("\n\nBat dau tinh: \n");
	Sapxep();
	printf("\nKQ va ghi vao file: \n");
	Xuatfilekq();
	Xuat();
	getch();
}

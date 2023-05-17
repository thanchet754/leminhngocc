#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
int dem=0;
using namespace std;

struct sinhvien
{
    int mssv;
    char ten[30];
    char gioitinh[10];
    float diem1;
    float diem2;
    float diem3;


    // ham nhập thông tin sinh viên
    void Nhap()
    {
        cout <<"Nhap ma so sinh vien: ";
        cin >>mssv;
        cout <<"Nhap ho ten sinh vien: ";
        fflush(stdin);
        gets(ten);
        cout <<"Nhap gioi tinh: ";
        fflush(stdin);
        gets(gioitinh);
        do
        { 
            cout <<"Nhap diem 1: ";
            cin >>diem1;
            cout <<"Nhap diem 2: ";
            cin >>diem2;
            cout <<"Nhap diem 3: ";
            cin >>diem3;
            if(diem1<0||diem2<0||diem3<0||diem1>10||diem2>10||diem3>10)  
                cout <<"Moi ban nhap lai!"<<endl;
            }while(diem1<0||diem2<0||diem3<0||diem1>10||diem2>10||diem3>10);
        
    }

    float DiemTB()
    {
        return (diem1+diem2+diem3)/3;
    }

    //  điều kiện xếp học lực 
    string HocLuc()
    {
        string hl;
        if(DiemTB()>=9)
            hl = "Xuat sac";
        else if(DiemTB()>=8)
            hl = "Gioi";
        else if(DiemTB()>=6.5)
            hl = "Kha";
        else if(DiemTB()>=5)
            hl = "Trung binh";
        else hl = "Yeu";
        return hl;
    }
    void Xuat()
    {
        cout <<setw(2)<<++dem<<setw(8)<<mssv<<setw(10)<<ten<<setw(10)<<gioitinh<<setw(10)<<diem1;
        cout<<setw(10)<<diem2<<setw(10)<<diem3<<setw(10)<<DiemTB()<<setw(10)<<HocLuc()<<endl;
    }
};


typedef sinhvien SV;

void NhapSV(SV sv[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout <<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        sv[i].Nhap();
    }
}

void TieuDe()
{
    cout<<setw(3)<<"STT"<<setw(8)<<"MSSV"<<setw(10)<<"Ho Ten"<<setw(10)<<"Gioi Tinh"<<setw(10)<<"Diem 1";
    cout <<setw(10)<<"Diem 2"<<setw(10)<<"Diem 3"<<setw(10)<<"Diem TB"<<setw(10)<<"Hoc luc"<<endl;
}

void XuatSV(SV *sv, int n)
{
    cout <<"Danh sach sinh vien: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        sv[i].Xuat();
    }
}

// ham them 1 sinh vien
void ThemSV(SV sv[], int &n)
{
   int dem = 0;
    n++;
    cout <<"Nhap thong tin sinh vien can them: "<<endl;
    sv[n-1].Nhap();
}
// hàm xóa 1 sinh viên
void XoaSV(SV *sv, int &n)
{
    int so;
    int dem = 0;
    cout <<"Nhap ma so sinh vien cua sinh vien can xoa: ";
    cin >>so;
    for(int i=0; i<n;i++)
    {
        if(sv[i].mssv == so)
        {
           for(int j=i;j<n;j++)
                sv[j] = sv[j+1];
            dem++;
        }
    }
    if(dem == 0)
        cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
    else n--;
}

// hàm cập nhật thông tinh sinh viên
void CapNhat(SV *sv, int n)
{
    int so;
    int res = 0;
    cout <<"Nhap ma so sinh vien cua sinh vien can cap nhat: ";
    cin >>so;
    for(int i=0; i<n;i++)
    {
        if(sv[i].mssv == so)
        {
           sv[i].Nhap();
           res++;
        }
    }
    if(res == 0)
        cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
}

// hàm trả về điểm max
float Max(SV *sv, int n)
{
    float max = sv[0].DiemTB();
    for(int i=1;i<n;i++)
    {
        if(sv[i].DiemTB() >max)
        {
            max = sv[i].DiemTB();
        }
    }
    return max;
}
// ham in ra sinh vien co diem trung binh cao nhat
void InMax(SV *sv, int n)
{
    dem = 0;
    cout <<"Thong tin nhung sinh vien co diem cao nhat: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        if(sv[i].DiemTB() == Max(sv, n) )
        {
            sv[i].Xuat();
        }
    }
}
// hàm trả về điểm min
float Min(SV *sv, int n)
{
    float min = sv[0].DiemTB();
    for(int i=1;i<n;i++)
    {
        if(sv[i].DiemTB() <min)
        {
            min= sv[i].DiemTB();
        }
    }
    return min;
}

// ham in ra sinh vien co diem trung binh thap nhat
void InMin(SV *sv, int n)
{
    dem = 0;
    cout <<"Thong tin nhung sinh vien co diem thap nhat: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        if(sv[i].DiemTB() == Min(sv, n) )
        {
            sv[i].Xuat();
        }
    }
}

// hàm sắp xếp sinh viên theo mã số sinh viên
void SapXepMSSV(SV *sv, int n)
{
    dem=0;
    cout <<"Danh sach sinh vien theo ma so tang dan: "<<endl;
    TieuDe();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(sv[i].mssv > sv[j].mssv )
            {
                swap(sv[i], sv[j]);
            }
        }
    }
    XuatSV(sv, n);
}

// ham nhap so luong sinh vien
void NhapSL(int &n)
{
    do
    {
        cout <<"Nhap so luong sinh vien: ";
        cin >>n;
        if(n<0)
            cout <<"Moi ban nhap lai!"<<endl;
    }while(n<0);
}

// tim kiem sinh vien thong qua ma so sinh vien
void TimKiem(SV *sv, int n)
{
    int ms,res=0;
    cout <<"Nhap ma so cua sinh vien can tim kiem: ";
    cin >>ms;
    for(int i=0;i<n;i++)
    {
        if(sv[i].mssv == ms)
        {
            sv[i].Xuat();
            res++;
        }
    }
    if(res == 0)
        cout <<"Ma so sinh vien khong co trong danh sach!"<<endl;
}

// Hiển thị lên màn hình với giao diện menu
void Menu(){
    cout<<"=========================================="<<"\n";
    cout<<" MENU "<<"\n";
    cout<<"=========================================="<<"\n";
    cout<<" 1. Nhap danh sach sinh vien"<<"\n";
    cout<<" 2. Hien thi danh sach sinh vien"<<"\n";
    cout<<" 3. Them thong tin 1 sinh vien"<<"\n";
    cout<<" 4. Xoa thong tin 1 sinh vien"<<"\n";
    cout<<" 5. Hien thi thong tin nhung sinh vien co diem trung binh cao nhat"<<"\n";
    cout<<" 6. Hien thi thong tin nhung sinh vien co diem trung binh thap nhat"<<"\n"; 
    cout<<" 7. Tim sinh vien boi ma so sinh vien"<<"\n"; 
    cout<<" 8. Sap xep danh sach sinh vien theo ma so sinh vien tang dan"<<"\n";
    cout<<" 0. Thoat"<<endl;
}

void Press()
{
    system("pause");
    system("cls");
}

int main()
{
    int n = 0;
    char chon;
    int luachon;
    SV *sv;
    sv = new SV[n];
  
    do
    {
        Menu();
        cout <<"Moi ban nhap lua chon: ";
        cin >>luachon;
        switch (luachon)
        {
            case 1:
            system("cls");
                NhapSL(n);
                NhapSV(sv, n);
                Press();
                break;
            case 2:
                XuatSV(sv, n);
                Press();
                break;
            case 3:
                ThemSV(sv, n);
                Press();
                break;
            case 4:
                XoaSV(sv, n);
                Press();
                break;
            case 5:
                InMax(sv, n);
                Press();
                break;
            case 6:
                InMin(sv, n);
                Press();
                break;
            case 7:
                TimKiem(sv, n);
                Press();
                break;
            case 8: 
                SapXepMSSV(sv, n);
                Press();
                break;
           
        default:
            cout <<"Ban da nhap sai lua chon!"<<endl;
            Press();
            break;
        }
        
        cout <<"Ban co muon lua chon tiep khong(y/n): ";
        cin >>chon;
        if(chon == 'n')
            cout <<"Tam biet ban\n";
    } while (chon =='y'||chon == 'Y'); 
    
    delete[] sv;
    return 0;
}

#include <iostream>
using namespace std;


void NhapMang(int a[], int b[], int n, int m) {
    cout << " NHAP SO LUONG NGUOI TRONG MOI NHOM "<<endl;
    for (int i = 1; i <= n; i++) {
        cout << "Nhom " << i << ": ";
        cin >> a[i];
        cout << endl;
    }
    cout << " NHAP SUC CHUA MOI PHONG "<<endl;
    for (int j = 1; j <= m; j++) {
        cout << "Phong " << j << ": ";
        cin >> b[j];
        cout << endl;
    }
}

void XDUT(int a[], int b[], int n, int m, int k1, int k2) {
    for (int i = 1; i <= n; i++) {
        if (i >= k1 && i <= k2) {
            cout << "Nhom duoc uu tien "<<i<<" : " << a[i] << " " << endl;
        }
        else cout << "Nhom khong duoc uu tien " << i << " : " << a[i] << endl;

        
    }
}


void TangDan(int b[], int m) {
    int tg;
    for (int i = 1; i <= m - 1; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (b[i] > b[j]) {
                tg = b[i];
                b[i] = b[j];
                b[j] = tg;
            }
        }
    }
    cout << "SAP XEP PHONG THEO SUC CHUA TANG DAN "<<endl;
    for (int j = 1; j <= m; j++) {
        cout << "Phong " << j << " :";
        cout << b[j] << " ";
        cout << endl;
    }
    cout << endl;
}

void UT(int k1, int k2, int m, int n, int g[][100], int r[][100], int a[], int b[]) {
    for (int i = k1; i <= k2; i++) {
        g[0][i] = i;
        g[1][i] = 0;
        for (int j = 1; j <= m;j++) {
            r[0][j] = j;
            r[1][j] = 0;
            if (a[i] <= b[j]) {
                g[1][i] = j;
                r[1][j] = i;
                break;
            }
        }
    }
    cout << "SAP XEP CHO NHOM UU TIEN: " << endl;
    for (int j = 1; j <= m;j++) {
        for (int i = 1;i <= n; i++) {
            if (g[0][i] >= k1 && g[0][i] <= k2 && r[0][j] == g[1][i]) {
                cout <<"Nhom: " << g[0][i] << " - "<<"Phong " << r[0][j] << endl;
            }
        }
    }

}
void CL(int k1, int k2, int m, int n, int g[][100], int r[][100], int a[], int b[]) {
    for (int i = 1; i <= n; i++) {
        g[0][i] = i;
        if (i < k1 || i > k2) {
            g[1][i] = 0;
        }
        for (int j = 2; j <= m; j++) {
            if (i < k1 || i > k2) {
                r[0][j] = j;
                r[1][j] = 0;
                if (a[i] <= b[j]) {
                    g[1][i] = j;
                    r[1][j] = i;
                    break;
                }
            }
        }
    }
    cout << "NHOM KHONG DUOC UU TIEN" << endl;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m;j++) {
            if (r[0][j] == g[1][i] && (g[0][i]<k1 || g[0][i]> k2) ) {
                cout << "Nhom: " << g[0][i] << " - " << "Phong " << r[0][j] << endl;
            }
            //else cout << "Khong co";
            
            /*else if (g[1][i] == 0 || r[1][i] == 0) {
                cout << "So phong du la: " << r[1][i] << endl;
                cout << "So nhom khong co phongf: " << r[1][i] << endl;
            }*/
        }
    }
}
void Du(int m, int n) {
    if (n - m < 0) {
        cout << "So luong nhom kh co phong: " << abs(n - m)<<endl;
    }
    else if (m - n < 0) {
        cout << "So luong phòng còn trống: "<<abs(m-n)<<endl;
    }
}


int main() {
    int a[100], b[100], g[10][100], r[10][100];
    int n, m, k1, k2;


    system("color 5f");
    cout << "Nhap so luong nhom nguoi: ";
    cin >> n;

    cout << "Nhap so luong phong: ";
    cin >> m;

    cout << "Nhap khoang k1 den k2 : ";
    cin >> k1>>k2;

    




    NhapMang(a, b, n, m);

    system("cls");

    Du(n, m);
    XDUT(a, b, n, m, k1, k2);
    
    //XuatMang(a,b,n, m);


    //XuatMang(a,b,n);

    // Sap xep tang dan:
    TangDan(b, m);

    UT(k1, k2, m, n, g, r, a, b);
    CL(k1, k2, m, n, g, r, a, b);

   
   
     
    //Du(m, n, g, r);
    //Xuat(k1, k2, m, n, g, r);



}
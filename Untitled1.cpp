#include <iostream>
#include <cstring>
#include <string>
#include<vector>
#include<map>
#include <locale.h> 
#include <windows.h>
#include <Shlobj.h>

using namespace std;


void Test1(void);// 数组、指针的经典易错题
void Test2(void);//sizeof和strlen的比较
void Test3(void);//判断自己是32位还是64位
void Test4(void);// 运算符重载
void Test5(void);// windows系统常用路径
void Test6(void);// 算法逆向

int MenuSelect(void)
{
    int cmd=0;
    char str[80]={0};
    cout<<"[00] 退出" << endl;
    cout<<"[01] 数组、指针的经典易错题"<<endl;
    cout<<"[02] sizeof和strlen的比较"<<endl;
    cout<<"[03] 判断自己是32位还是64位"<<endl;
    cout<<"[04] 运算符重载，模板应用， for auto C++11特性"<<endl;
    cout<<"[05] windows系统常用路径"<<endl;
    cout<<"[06] 看雪第二题"<<endl;
    
    do {
        cout<<"请选择：";
        cin>>str;
        cmd=atoi(str);
    }while(cmd<0||cmd>22);
    return cmd;
}

int main(int argc, char *argv[])
{
    int cmd;
    do{
        cmd=MenuSelect();
        switch (cmd) {
            case 1:Test1();break;
            case 2:Test2();break;
            case 3:Test3();break;
            case 4:Test4();break;
            case 5:Test5();break;
            case 6:Test6();break;
            default: break;
        }
    } while (cmd!=0);
    //cout<<"test"<<endl;
    //system("pause");
    return 0;
}

/****************************************************************
 * Function Name : Test1  数组、指针的经典易错题
 * Paramter      : None
 * Return value  : 0
 * Auth          :wangjiawei
 ****************************************************************/
void Test1(void)
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int *p=&a[1];
    int *p1=(int*)(&a+1);
    cout << "{";
    for(auto x:a){
        cout << x <<",";
    }
    cout <<'\x8'<<"}"<< endl;//删除 , 添加括号
    cout<<"-----"<<__FUNCTION__<<"---start-----"<<endl;
    cout<<"p[6]="<<p[6]<<endl;
    cout<<"*(p1-1)="<<*(p1-1)<<endl;
    cout<<"-----"<<__FUNCTION__<<"----end------"<<endl;
}
/****************************************************************
 * Function Name : Test2  sizeof和strlen的比较
 * Paramter      : None
 * Return value  : 0
 * Auth          :wangjiawei
 ****************************************************************/
void Test2(void)
{
    cout<<"-----"<<__FUNCTION__<<"---start-----"<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;
    cout<<"sizeof(char):"<<sizeof(char)<<endl;
    char* a=new char[10];
    cout<<"char* a=new char[10];"<<endl;
    cout<<"sizeof(a):"<<sizeof(a)<<endl;
    cout<<"strlen(a):"<<strlen(a)<<endl;
    delete [] a;
    cout<<"-----"<<__FUNCTION__<<"----end------"<<endl;
}
/****************************************************************
 * Function Name : Test3  判断自己是32位还是64位
 * Paramter      : None
 * Return value  : 0
 * Auth          :wangjiawei
 ****************************************************************/
void Test3(void)
{
    cout<<"-----"<<__FUNCTION__<<"---start-----"<<endl;
    int nNum = 0;
	int nSize = sizeof(&nNum);
    if (nSize == 8)
	{
		cout<<"64"<<endl;
	}
	else
	{
		cout<<"32"<<endl;
	}
    cout<<"-----"<<__FUNCTION__<<"----end------"<<endl;
}

class Stu{
public:
    string name;
    string sc;
    int id;
    friend ostream &operator<<(ostream &o, const Stu &s);
};
ostream& operator<<(ostream& o,const Stu& s)
{
    o << "{" << s.id << "," << s.name << "," << s.sc << "}"<<endl;
    return o;
}
/****************************************************************
 * Function Name : Test4  运算符重载，模板应用， for auto C++11特性
 * Paramter      : None
 * Return value  : 0
 * Auth          :wangjiawei
 ****************************************************************/
void Test4(void)
{
      vector<Stu> v;
      Stu st;
      st.id = 1;
      st.name = "abcdefghijklmnopqrstuvwxyz0123456789987654321";
      st.sc = "100";
      cout <<"string:"<<"\t"<< sizeof(st.name) << endl;
      cout << "Stu:"<<"\t"<<sizeof(st) << endl;
      v.push_back(st);

      Stu st1;
      st1.id = 2;
      st1.name = "0123456789abcdefghijklmnoz78546+425898=504444";
      st1.sc = "95";
      v.push_back(st1);
      cout << "iterator:" << endl;
      for (vector<Stu>::iterator it = v.begin(); it != v.end();it++)
          cout << *it << endl;
    cout << "x:" << endl;
    for(auto x:v)
        cout << x << endl;

    std::map<int, std::string> hash_map = {{1, "c++"}, {2, "java"}, {3, "python"}};
    for(auto it : hash_map) {
        std::cout << it.first << "\t" << it.second << std::endl;
    }

    std::vector<std::string> str_vec = { "i", "like",  "google"};
    for(auto& it : str_vec) { //引用赋值
        it = "c++";
    }


}
/****************************************************************
 * Function Name : Test4  windows系统常用路径
 * Paramter      : None
 * Return value  : 0
 * Auth          :wangjiawei
 ****************************************************************/
void Test5(void)
{
    setlocale(LC_ALL, "chs");
    char szPath[MAX_PATH];
    int CSIDL[] = {
		CSIDL_ADMINTOOLS,		CSIDL_APPDATA,	CSIDL_CDBURN_AREA,		CSIDL_COMMON_ADMINTOOLS,	CSIDL_COMMON_APPDATA,
		CSIDL_COMMON_DESKTOPDIRECTORY,			CSIDL_COMMON_DOCUMENTS,	CSIDL_COMMON_FAVORITES,		CSIDL_COMMON_MUSIC,
		CSIDL_COMMON_PICTURES,	CSIDL_COMMON_PROGRAMS,	CSIDL_COMMON_STARTMENU, CSIDL_COMMON_STARTUP,
		CSIDL_COMMON_TEMPLATES, CSIDL_COMMON_VIDEO,		CSIDL_COOKIES,			CSIDL_FAVORITES,
		CSIDL_HISTORY,			CSIDL_INTERNET_CACHE,	CSIDL_LOCAL_APPDATA,	CSIDL_MYDOCUMENTS,
		CSIDL_MYMUSIC,			CSIDL_MYPICTURES,		CSIDL_MYVIDEO,			CSIDL_PROFILE,		CSIDL_PROGRAM_FILES,
		CSIDL_PROGRAM_FILES_COMMON,						CSIDL_PROGRAMS,			CSIDL_RECENT,		CSIDL_SENDTO,
		CSIDL_STARTMENU,		CSIDL_STARTUP,			CSIDL_SYSTEM,			CSIDL_TEMPLATES,	CSIDL_WINDOWS,
		0
	};
	for (int i=0;CSIDL[i];i++) {
		if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL[i], NULL, SHGFP_TYPE_CURRENT, szPath))) {
			wprintf(L"%d, %s\n", i, szPath);
		}
	}
}

void Test6(void)
{

    int count = 0;
    char v3;          // al
    int v4;           // esi
    int v5;           // ecx
    int v7;           // edx
    int v8;           // eax
    unsigned int v9;  // ecx
    int v10;          // eax
    int i;            // edx
    int v12;          // eax
    char *v13;        // eax
    char *v14;        // eax
    int v15;          // edx
    char *v16;        // ecx
    int v17;          // eax
    int v18;          // eax
    int v19;          // eax
    int v20;          // [esp+1Ch] [ebp-60h]
    unsigned int v21; // [esp+20h] [ebp-5Ch]
    unsigned int v22; // [esp+24h] [ebp-58h]
    char v23;         // [esp+2Bh] [ebp-51h]
    int v24;          // [esp+2Ch] [ebp-50h]
    char v25[76] = { '0'};//'3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0','1', '2'};
    char biao[0x24] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char aS_1[10][9] = {53, 00, 01, 00, 00, 01, 00, 00, 01, 01,
                        01, 01, 00, 00, 01, 00, 00, 01, 00, 00,
                        00, 00, 01, 00, 01, 01, 01, 01, 01, 00,
                        00, 01, 01, 00, 01, 00, 00, 01, 00, 00,
                        00, 00, 01, 00, 00, 01, 00, 00, 01, 01,
                        01, 01, 00, 01, 01, 01, 00, 01, 00, 01,
                        00, 00, 01, 01, 01, 01, 00, 01, 00, 01,
                        00, 01, 01, 00, 00, 01, 00, 01, 00, 01,
                        00, 00, 00, 01, 00, 00, 01, 01, 00, 00};
    if (strlen(v25) <= 0x30)
    {
        v3 = v25[0];
        if (v25[0])
        {
            v4 = 0;
            v21 = 0;
            v22 = 0;
            v24 = 0x24;
            v23 = biao[0];
            LABEL_4:
            if (v24 > 0)
            {
                v5 = 0;
                if (v23 == v3)
                {
                    LABEL_11:
                    v7 = (v4 + v5 / 6) % 6;
                    v8 = v5 + v4;
                    v9 = v22;
                    v20 = v7;
                    v10 = 5 - v8 % 6;
                    for (i = 0;; i = 1)
                    {
                        switch (v10)
                        {
                            case 1:
                                ++v9;
                                cout<<"v9 +1"<<endl;
                                break;
                            case 2:
                                v17 = (v21++ & 1) == 0;
                                v9 += v17;
                                cout<<"v9 +1 & v21 +1"<<endl;
                                break;
                            case 3:
                                v12 = (v21++ & 1) != 0;
                                cout<<"v9 -1 & v21 +1"<<endl;
                                v9 -= v12;
                                break;
                            case 4:
                                --v9;
                                cout<<"v9 -1 "<<endl;
                                break;
                            case 5:
                                v19 = (v21-- & 1) != 0;
                                v9 -= v19;
                                cout<<"v9 -1 & v21 -1"<<endl;
                                break;
                            default:
                                v18 = (v21-- & 1) == 0;
                                v9 += v18;
                                cout<<"v9 +1 & v21 -1"<<endl;
                                break;
                        }
                        if (v9 > 9)
                        {
                            printf("v21 = %d,v9 = %d\n",v21, v9);
                            v3 = v25[count++];
                            //goto LABEL_4;
                            break;
                        }
                        if (v21 > 8)
                        {
                            printf("v21 = %d,v9 = %d\n",v21, v9);
                            v3 = v25[count++];
                            //goto LABEL_4;
                            break;
                        }
                        v13 =(char*) &aS_1[10 * v21 + v9];
                        if (*v13)
                        {
                            printf("v13 = %d   x=%d, y=%d, code=%c\n", *v13,v21,v9,v25[count]);
                            v3 = v25[count++];
                            //goto LABEL_4;
                            break;
                        }
                        *v13 = 1;
                        if (i == 1)
                        {
                            ++v4;
                            v22 = v9;
                            v3 = v25[v4];
                            if (v3)
                            {
                                v3 = v25[count++];
                                goto LABEL_4;
                            }
                            goto LABEL_19;
                        }
                        v10 = v20;
                    }
                }
                else
                {
                    while (v24 != ++v5)
                    {
                        if (biao[v5] == v3)
                            goto LABEL_11;
                    }
                }
            }
        }
        else
        {
            LABEL_19:
            v14 = (char*)aS_1;
            v15 = 0;
            do
            {
                v16 = v14 + 10;
                do
                    v15 += *v14++ == 0;
                while (v16 != v14);
            } while (0 != v16);
            if (!v15)
            {
                printf("good Job\n");
                return ;
            }
        }
    }
    goto LABEL_4;
}

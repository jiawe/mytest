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
    cout<<"[06] etc."<<endl;
    
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

 
}

#include<string>
#include<iostream>
using namespace std;

#define max 1000

struct person
{
    string name;
    string sex;
    string telephone;
    string email;
    string address;
};

struct books
{
    struct person array[max];
    int size;
};


void show_menu(){
    cout<<endl;
    cout<<"help\t帮助"<<endl;
    cout<<"add\t添加联系人"<<endl;
    cout<<"del\t删除联系人"<<endl;
    cout<<"find\t查找联系人"<<endl;
    cout<<"show\t显示联系人"<<endl;
    cout<<"amend\t修改联系人"<<endl;
    cout<<"clear\t清空列表"<<endl;
    cout<<"over\t关闭程序"<<endl;
    cout<<endl;
}

void add(books * abs){
    if (abs->size==max)
    {
        cout<<"记不下更多东西了喵"<<endl;
        return;
    }
    string name,sex,telephone,email,address;
    string temp="1";
    while (temp!="0"){
        cout<<"姓名：";
        cin>>name;
        cout<<"性别：";
        cin>>sex;
        cout<<"电话：";
        cin>>telephone;
        cout<<"邮箱：";
        cin>>email;
        cout<<"地址：";
        cin>>address;
        cout<<endl<<"主人请确认~"<<endl<<"姓名：\t"<<name
            <<endl<<"性别：\t"<<sex
            <<endl<<"电话：\t"<<telephone
            <<endl<<"邮箱：\t"<<email
            <<endl<<"地址：\t"<<address
            <<endl<<"没问题请输入0喵~";
        cin>>temp;
        if(temp=="0"){
            abs->array[abs->size].name=name;
            abs->array[abs->size].sex=sex;
            abs->array[abs->size].telephone=telephone;
            abs->array[abs->size].email=email;
            abs->array[abs->size].address=address;
            abs->size++;
            cout<<"已录入"<<name<<"的信息"<<endl;
            break;
        }
        cout<<endl<<"请重新录入信息"<<endl;
    }
    
}

void show(books *abs){
    if(abs->size==0){
        cout<<endl<<"主人你是没有朋友吗"<<endl;
        return;
    }
    else{
        for (int i = 0; i < abs->size; i++)
        {
            cout<<"通讯人"<<i+1<<endl<<"姓名：\t"<<abs->array[i].name
                <<endl<<"性别：\t"<<abs->array[i].sex
                <<endl<<"电话：\t"<<abs->array[i].telephone
                <<endl<<"邮箱：\t"<<abs->array[i].email
                <<endl<<"地址：\t"<<abs->array[i].address<<endl<<endl;
        }
        
    }

}

void del(books *abs){
    cout<<"主人要删除第几个联系人"<<endl;
    int num;
    cin>>num;
    if (num < 1 || num > abs->size)
    {
        cout<<"查无此人喵~"<<endl;
        return;
    }
    
    cout<<endl<<"是下面这个人类吗"
        <<endl<<"姓名：\t"<<abs->array[num-1].name
        <<endl<<"性别：\t"<<abs->array[num-1].sex
        <<endl<<"电话：\t"<<abs->array[num-1].telephone
        <<endl<<"邮箱：\t"<<abs->array[num-1].email
        <<endl<<"地址：\t"<<abs->array[num-1].address
        <<"是请输入0喵~"<<endl;
    int temp=1;
    cin>>temp;
    if (temp!=0)
    {
        cout<<"取消删除"<<endl;
        return;
    }
    cout<<"正在为主人删除~"<<endl;
    for (int i = num-1; i < abs->size-1; i++)
    {
        abs->array[i].name=abs->array[i+1].name;
        abs->array[i].sex=abs->array[i+1].sex;
        abs->array[i].telephone=abs->array[i+1].telephone;
        abs->array[i].email=abs->array[i+1].email;
        abs->array[i].address=abs->array[i+1].address;
    }
    
    abs->array[abs->size-1].name.clear();
    abs->array[abs->size-1].sex.clear();
    abs->array[abs->size-1].telephone.clear();
    abs->array[abs->size-1].email.clear();
    abs->array[abs->size-1].address.clear();
    abs->size--;
    cout<<"删掉了喵"<<endl;
}

void amend(books *abs){
    cout<<"主人要修改第几个联系人喵~"<<endl;
    int num;
    cin>>num;
    if (num < 1 || num > abs->size)
    {
        cout<<"查无此人喵~"<<endl;
        return;
    }
    
    cout<<endl<<"是下面这个人类吗"
        <<endl<<"姓名：\t"<<abs->array[num-1].name
        <<endl<<"性别：\t"<<abs->array[num-1].sex
        <<endl<<"电话：\t"<<abs->array[num-1].telephone
        <<endl<<"邮箱：\t"<<abs->array[num-1].email
        <<endl<<"地址：\t"<<abs->array[num-1].address
        <<"是请输入0喵~";
    int tempp=1;
    cin>>tempp;
    if (tempp!=0)
    {
        cout<<"取消修改"<<endl;
        return;
    }
    string name,sex,telephone,email,address;
    string temp="1";
    while (temp!="0"){
        cout<<"姓名：";
        cin>>name;
        cout<<"性别：";
        cin>>sex;
        cout<<"电话：";
        cin>>telephone;
        cout<<"邮箱：";
        cin>>email;
        cout<<"地址：";
        cin>>address;
        cout<<endl<<"主人请确认~"<<endl<<"姓名：\t"<<name
            <<endl<<"性别：\t"<<sex
            <<endl<<"电话：\t"<<telephone
            <<endl<<"邮箱：\t"<<email
            <<endl<<"地址：\t"<<address
            <<endl<<"没问题请输入0喵~";
        cin>>temp;
        if(temp=="0"){
            abs->array[num-1].name=name;
            abs->array[num-1].sex=sex;
            abs->array[num-1].telephone=telephone;
            abs->array[num-1].email=email;
            abs->array[num-1].address=address;
            cout<<"已录入"<<name<<"的信息"<<endl;
            break;
        }
        cout<<endl<<"请重新录入信息"<<endl;
    }

}

void find(books *abs){
    cout<<"你要找谁喵~"<<endl;
    string name;
    cin>>name;
    for (int i = 0; i < abs->size; i++)
    {
        if (abs->array[i].name==name)
        {
            cout<<endl<<"姓名：\t"<<abs->array[i].name
            <<endl<<"性别：\t"<<abs->array[i].sex
            <<endl<<"电话：\t"<<abs->array[i].telephone
            <<endl<<"邮箱：\t"<<abs->array[i].email
            <<endl<<"地址：\t"<<abs->array[i].address<<endl<<endl;
            return;
        }
        
    }
    cout<<"查无此人喵~"<<endl;
}

void clear(books *abs){
    cout<<"确定要清除吗？"<<endl<<"确认请输入0"<<endl;
    int a;
    cin>>a;
    if(a!=0){
        cout<<"取消清除"<<endl;
        return;
    }
    cout<<"开始清除~"<<endl;
    for (int i = 0; i < abs->size; i++)
    {
        abs->array[i].address.clear();
        abs->array[i].email.clear();
        abs->array[i].name.clear();
        abs->array[i].sex.clear();
        abs->array[i].telephone.clear();
    }
    cout<<"清除完毕"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(){
    cout<<"欢迎启动通讯录喵~";
    show_menu();
    // help    帮助
    // add     添加联系人
    // del     删除联系人
    // find    查找联系人
    // amend   修改联系人
    // clear   清空列表
    // over    关闭程序
    //show     显示联系人
    cout<<"有什么指示的喵~";
    string opt;
    int count=0;
    books abs;
    abs.size=0;
    while (opt!="over"){  
        cin>>opt;
        if(opt=="help"){
            show_menu();
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="add"){
            cout<<endl;
            add(&abs);
            cout<<endl<<"还有什么要吩咐的喵~";
        }
        else if(opt=="show"){
            show(&abs);
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="del"){
            del(&abs);
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="find"){
            find(&abs);
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="amend"){
            amend(&abs);
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="clear"){
            clear(&abs);
            cout<<"还有什么要吩咐的喵~";
        }
        else if(opt=="over"){
            cout<<endl<<"下次再见哦"<<endl;
        }
        else{
            cout<<endl<<"听不懂喵pwp"<<endl;
            cout<<"还有什么要吩咐的喵~";
        }
    }
    abs.size=0;
    system("pause");
}
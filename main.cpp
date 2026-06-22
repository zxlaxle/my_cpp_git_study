#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct contact {
    string name;
    string sex;      // 改成 string 更友好
    string phone;
    int age;
};

const int Contactmax = 101;
contact contactbook[Contactmax];
int contactcount = 0;

void show() {
    cout << "\n--------------------------" << endl;
    cout << "     通讯录管理系统       " << endl;
    cout << "  1. 添加联系人            " << endl;
    cout << "  2. 查询联系人            " << endl;
    cout << "  3. 修改联系人            " << endl;
    cout << "  4. 删除联系人            " << endl;
    cout << "  5. 显示所有联系人        " << endl;
    cout << "  6. 清空通讯录            " << endl;
    cout << "  0. 退出系统              " << endl;
    cout << "--------------------------" << endl;
    cout << "请输入操作序号：";
}

void addcontact() {
    if (contactcount >= Contactmax) {
        cout << "空间已满" << endl;
        return;
    }
    contact newadder;
    cout << "\n---添加联系人---" << endl;
    cout << "姓名：";
    cin >> newadder.name;
    cout << "性别（男/女）：";
    cin >> newadder.sex;
    cout << "电话：";
    cin >> newadder.phone;
    cout << "年龄：";
    cin >> newadder.age;

    contactbook[contactcount] = newadder;
    contactcount++;
    cout << "添加成功！" << endl;
}

void searchcontact() {
    cout << "\n=== 查询联系人 ===" << endl;
    cout << "请输入要查询的姓名：";
    string target;
    cin >> target;

    bool found = false;
    for (int i = 0; i < contactcount; i++) {
        if (contactbook[i].name == target) {
            cout << "\n姓名：" << contactbook[i].name << endl;
            cout << "年龄：" << contactbook[i].age << endl;
            cout << "性别：" << contactbook[i].sex << endl;
            cout << "手机号：" << contactbook[i].phone << "\n" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "未找到该联系人！\n" << endl;
    }
}

void modifycontact() {
    if (contactcount == 0) {
        cout << "通讯录为空，无法修改！" << endl;
        return;
    }

    cout << "\n=== 修改联系人 ===" << endl;
    cout << "请输入要修改的姓名：";
    string targetName;
    cin >> targetName;

    for (int i = 0; i < contactcount; i++) {
        if (contactbook[i].name == targetName) {
            cout << "找到联系人：" << contactbook[i].name << endl;
            cout << "请输入新姓名（直接回车保留原值）：";
            string newName;
            cin.ignore();
            getline(cin, newName);
            if (!newName.empty()) contactbook[i].name = newName;

            cout << "请输入新性别（男/女）：";
            string newSex;
            getline(cin, newSex);
            if (!newSex.empty()) contactbook[i].sex = newSex;

            cout << "请输入新手机号：";
            string newPhone;
            getline(cin, newPhone);
            if (!newPhone.empty()) contactbook[i].phone = newPhone;

            cout << "请输入新年龄：";
            string newAgeStr;
            getline(cin, newAgeStr);
            if (!newAgeStr.empty()) contactbook[i].age = stoi(newAgeStr);

            cout << "修改成功！" << endl;
            return;
        }
    }
    cout << "未找到该联系人！" << endl;
}

void showperson() {
    cout << "\n=== 所有联系人列表 ===" << endl;
    if (contactcount == 0) {
        cout << "通讯录为空！" << endl;
        return;
    }
    for (int i = 0; i < contactcount; i++) {
        cout << "\n【联系人 " << i + 1 << "】" << endl;
        cout << "姓名：" << contactbook[i].name << endl;
        cout << "年龄：" << contactbook[i].age << endl;
        cout << "性别：" << contactbook[i].sex << endl;
        cout << "手机号：" << contactbook[i].phone << endl;
        cout << "------------------------" << endl;
    }
}

void deleteperson() {
    if (contactcount == 0) {
        cout << "通讯录为空，无法删除！" << endl;
        return;
    }

    cout << "\n=== 删除联系人 ===" << endl;
    cout << "请输入要删除的姓名：";
    string targetName;
    cin >> targetName;

    for (int i = 0; i < contactcount; i++) {
        if (contactbook[i].name == targetName) {
            for (int j = i; j < contactcount - 1; j++) {
                contactbook[j] = contactbook[j + 1];
            }
            contactcount--;
            cout << "删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该联系人！" << endl;
}

void clearContact() {
    contactcount = 0;
    cout << "通讯录已清空！" << endl;
}

int main() {
    int choice;
    while (true) {
        show();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "请输入数字！" << endl;
            continue;
        }

        switch (choice) {
        case 0:
            cout << "感谢使用，再见！" << endl;
            return 0;
        case 1: addcontact(); break;
        case 2: searchcontact(); break;
        case 3: modifycontact(); break;
        case 4: deleteperson(); break;
        case 5: showperson(); break;
        case 6: clearContact(); break;
        default:
            cout << "输入错误，请重新选择！" << endl;
            break;
        }
    }
    return 0;
}

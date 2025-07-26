#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <cctype>
#include <regex>
#include <iomanip>
#include <unordered_map>
using namespace std;

unordered_map<string, string> bangF4 = {
    // Chữ thường
    {"ă", "70"}, {"â", "71"}, {"ê", "72"}, {"ô", "73"},
    {"đ", "74"}, {"ơ", "75"}, {"ư", "76"}, {"á", "77"},
    {"à", "78"}, {"ả", "79"}, {"ã", "7A"}, {"ạ", "7B"},
    {"ấ", "7C"}, {"ầ", "7D"}, {"ẩ", "7E"}, {"ẫ", "7F"},
    {"ậ", "80"}, {"ắ", "81"}, {"ằ", "82"}, {"ẳ", "83"},
    {"ẵ", "84"}, {"ặ", "85"}, {"é", "86"}, {"è", "87"},
    {"ẻ", "88"}, {"ẽ", "89"}, {"ẹ", "8A"}, {"ế", "8B"},
    {"ề", "8C"}, {"ể", "8D"}, {"ễ", "8E"}, {"ệ", "8F"},
    {"í", "90"}, {"ì", "91"}, {"ỉ", "92"}, {"ĩ", "93"},
    {"ị", "94"}, {"ó", "95"}, {"ò", "96"}, {"ỏ", "97"},
    {"õ", "98"}, {"ọ", "99"}, {"ố", "9A"}, {"ồ", "9B"},
    {"ổ", "9C"}, {"ỗ", "9D"}, {"ộ", "9E"}, {"ớ", "9F"},
    {"ờ", "A0"}, {"ở", "A1"}, {"ỡ", "A2"}, {"ợ", "A3"},
    {"ú", "A4"}, {"ù", "A5"}, {"ủ", "A6"}, {"ũ", "A7"},
    {"ụ", "A8"}, {"ứ", "A9"}, {"ừ", "AA"}, {"ử", "AB"},
    {"ữ", "AC"}, {"ự", "AD"}, {"ý", "AE"}, {"ỳ", "AF"},
    {"ỷ", "B0"}, {"ỹ", "B1"}, {"ỵ", "B2"},

    // Chữ hoa
    {"Ă", "B3"}, {"Â", "B4"}, {"Ê", "B5"}, {"Ô", "B6"},
    {"Đ", "B7"}, {"Ơ", "B8"}, {"Ư", "B9"}, {"Á", "BA"},
    {"À", "BB"}, {"Ả", "BC"}, {"Ã", "BD"}, {"Ạ", "BE"},
    {"Ấ", "BF"}, {"Ầ", "C0"}, {"Ẩ", "C1"}, {"Ẫ", "C2"},
    {"Ậ", "C3"}, {"Ắ", "C4"}, {"Ằ", "C5"}, {"Ẳ", "C6"},
    {"Ẵ", "C7"}, {"Ặ", "C8"}, {"É", "C9"}, {"È", "CA"},
    {"Ẻ", "CB"}, {"Ẽ", "CC"}, {"Ẹ", "CD"}, {"Ế", "CE"},
    {"Ề", "CF"}, {"Ể", "D0"}, {"Ễ", "D1"}, {"Ệ", "D2"},
    {"Í", "D3"}, {"Ì", "D4"}, {"Ỉ", "D5"}, {"Ĩ", "D6"},
    {"Ị", "D7"}, {"Ó", "D8"}, {"Ò", "D9"}, {"Ỏ", "DA"},
    {"Õ", "DB"}, {"Ọ", "DC"}, {"Ố", "DD"}, {"Ồ", "DE"},
    {"Ổ", "DF"}, {"Ỗ", "E0"}, {"Ộ", "E1"}, {"Ớ", "E2"},
    {"Ờ", "E3"}, {"Ở", "E4"}, {"Ỡ", "E5"}, {"Ợ", "E6"},
    {"Ú", "E7"}, {"Ù", "E8"}, {"Ủ", "E9"}, {"Ũ", "EA"},
    {"Ụ", "EB"}, {"Ứ", "EC"}, {"Ừ", "ED"}, {"Ử", "EE"},
    {"Ữ", "EF"}, {"Ự", "F0"}, {"Ý", "F1"}, {"Ỳ", "F2"},
    {"Ỷ", "F3"}, {"Ỹ", "F4"}, {"Ỵ", "F5"},
};


void clear_screen() {
    cout << "\033[2J\033[H";
}

bool is_valid_integer(const string& input) {
    if (input.empty()) return false;

    int start = 0;
    if (input[0] == '-' || input[0] == '+') start = 1;

    if (start == 1 && input.size() == 1) return false;

    for (size_t i = start; i < input.size(); ++i) {
        if (!isdigit(input[i])) return false;
    }

    return true;
}

bool hopLe(const string& s) {
    // Regex cho phép tiếng Việt + số + khoảng trắng + các ký tự đặc biệt cho phép
    regex pattern("^[A-Za-zÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠàáâãèéêìíòóôõùúăđĩũơƯĂẠẢẤẦẨẪẬẮẰẲẴẶẸẺẼỀỀỂưăạảấầẩẫậắằẳẵặẹẻẽềềểếỄỆỈỊỌỎỐỒỔỖỘỚỜỞỠỢỤỦỨỪễệỉịọỏốồổỗộớờởỡợụủứừỬỮỰỲỴÝỶỸỳỵỷỹ0-9 !@#\\$%\\^&\\*\\(\\)\\[\\]\\{\\}\\=\\-\\+\\.,]+$");
    return regex_match(s, pattern);
}

void huong_dan_su_dung()
{
	cout<<"\033[1;31mCách sử dụng chương trình:\n";
	cout<<"Các bạn có thể thấy, trong casio fx880btg có rất nhiều cách spell và nhiều ký tự độc lạ chỉ có trên\n";
	cout<<"casio, nhưng cách spell của tôi là cách khá lạ và không ổn định và thêm cái nữa là đây là một chương\n";
	cout<<"trình máy tính cho nên sẽ không chứa được những ký tự đặc biệt! App này rất tốt cho newbie, nếu là pro\n";
	cout<<"thì tốt nhất là đừng dùng =))))) Nếu ai có cách spell ổn định hơn, hãy cho tôi xin =))) để cải thiện chất lượng!\033[0m\n";
	cout<< "\033[0;37m";
}

void doi_chu_thanh_hex()
{
    cout << "\033[1;31;47mWarning: Nếu terminal không hỗ trợ, đừng nhập tiếng Việt hoặc vào link h.20142022.xyz để đổi chữ thành hex!\033[0m";
    string chu;
    do {
        cout << "Nhập chữ bạn muốn đổi thành hex vào\033[1;31m(không nhập ký tự đặc biệt!)\033[0m\033[0;37m: ";
        getline(cin, chu);
        if (chu.length() > 17) {
            cout << "\033[1;31;47mChỉ được nhập 17 ký tự thôi!\033[0m\n";
        }
        clear_screen();
    } while (chu.length() > 17);

    cout << "Đang kiểm tra chữ bạn nhập vào ........\n";
    if (!hopLe(chu)) {
        cout << "\033[1;31;47mXin lỗi, chương trình không chứa được ký tự đặc biệt, vui lòng thử lại!\033[0m\n";
        doi_chu_thanh_hex();
        return;
    }

    cout << "Đã kiểm tra xong!\nĐang đổi thành hex ......\n";

    string hexcasio;
    for (char c : chu) {
        string s(1, c); // chuyển char thành string
        if (bangF4.count(s)) {
            hexcasio += "F4 " + bangF4[s] + " ";
        } else if (isalnum(c) || ispunct(c) || isspace(c)) {
            stringstream ss;
            ss << hex << uppercase << setw(2) << setfill('0') << (int)(unsigned char)c;
            hexcasio += ss.str() + " ";
        }
    }
    cout << "Hex của chuỗi bạn nhập vào là: \033[1;31m" << hexcasio << "\033[0m\n";
}

void batdau()
{
	cout<<"Bot hỗ trợ spell trên CASIO fx-880BTG\nCode by @caominhcasio\nChọn chức năng!\n";	
	string luachonchu;
	int luachonso;
	while (true)
	{

		cout<<"1: Hướng dẫn sử dụng\n";
		cout<<"2: Đổi chữ thành hex\n";
		cout<<"3: AI giúp spell\n";
		cout<<"Lựa chọn của bạn là: ";
		getline(cin, luachonchu);
        	if (is_valid_integer(luachonchu)) {
            		stringstream ss(luachonchu);
            		ss >> luachonso;
			if (luachonso >= 1 && luachonso <= 3) {
                	break; // Hợp lệ, thoát khỏi vòng lặp
            	}	 
		else {
                	cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại!\n";
            	}
        	} 
		else {
            		cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại!\n";
        	}
    	}

    	switch (luachonso) 
	{
        	case 1:
			clear_screen();
        	    	cout << "Bạn đã chọn 1\n";
			cout << "Chương trình đang load.....\n";
			huong_dan_su_dung();
            		break;
        	case 2:
			clear_screen();
            		cout << "Bạn đã chọn 2\n";
			cout << "Chương trình đang load...................\n";
			doi_chu_thanh_hex();
			break;
        	case 3:
			clear_screen();
            		cout << "Bạn đã chọn 3\n";
			break;
    	}

}

int main()
{
	clear_screen();
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	batdau();
	system("pause");
	return 0;
}

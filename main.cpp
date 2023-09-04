#include <iostream>
#include <string>
#include <getopt.h>
#include "Connect.h"

using namespace std;
/** 
* @file main.cpp
* @brief Главный модуль программы для получения параметров от пользователя
* @param rez переменная для работы с параметрами командной строки
* @param optarg переменная для получения парметров командной строки
*/
int main (int argc, char *argv[]){

	const char* short_options = "hi:p::o:r:c::";

	const struct option long_options[] = {
		{ "help", no_argument, NULL, 'h' },
		{ "ip", required_argument, NULL, 'i' },
        { "port", optional_argument, NULL, 'p' },
		{ "fileoriginal", required_argument, NULL, 'o' },
        { "fileresult", required_argument, NULL, 'r' },
        { "config", optional_argument, NULL, 'c' },
		{ NULL, 0, NULL, 0 }
	};

	int rez;
	int option_index;

    string s1 = "1 парметр -h или --help для справки";
    string s2 = "2 параметр -i или --ip сетевой адрес сервера обязательный";
    string s3 = "3 параметр -p или --port порт серевера необязательный";
    string s4 = "4 параметр -o или --fileoriginal файл с векторами обязательный";
    string s5 = "5 параметр -r или --fileresult файл-результат обязательный";
    string s6 = "6 параметр -c или --config файл-аутентификации необязательный";

    // Класс для взаимодействия с клиент-сервером
    Connect MyConnect;

    if(argc == 1){
        cout << "Данная программа клиент-сервер" << endl;
        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        cout << s4 << endl;
        cout << s5 << endl;
        cout << s6 << endl;
        return 1;
    }
    string str1;
    string str2;
	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
				cout << "Данная программа клиент-сервер" << endl;
                cout << s1 << endl;
                cout << s2 << endl;
                cout << s3 << endl;
                cout << s4 << endl;
                cout << s5 << endl;
                cout << s6 << endl;
				return 1;
			};
			case 'i': {
				if (optarg==NULL){
                    cout << s2 << endl;
                    return 2;
                }
				else{
                    str1 = string(optarg);
                }
				break;
			};
	
			case 'p': {
				if (optarg!=NULL){
                    str2 = string(optarg);
                }
				else{
                    str2 = "33333";
                }
				break;
			};
			case 'o': {
				if (optarg==NULL){
                    cout << s4 << endl;
                    return 3;
                }
				else{
                    MyConnect.name_original_file = string(optarg);
                }
				break;
			};

            case 'r': {
				if (optarg==NULL){
                    cout << s5 << endl;
                    return 4;
                }
				else{
                    MyConnect.name_result_file = string(optarg);
                }
				break;
			};

            case 'c': {
				if (optarg!=NULL){
                    MyConnect.name_auto_file = string(optarg);
                }
				else{
                    MyConnect.name_auto_file = "./config/vclient.conf";
                }
				break;
			};

            case '?': default: {
				cout << "Таких опций нет. Запустите программу с параметром h" << endl;
				return 5;
			};
		};
	};

    // запуск
    // ./client -i 2130706433 -p33333 -o my.txt -r resultat.txt -c./config/vclient.conf
    MyConnect.Connect_to_server(str1, str2);


	return 0;
};

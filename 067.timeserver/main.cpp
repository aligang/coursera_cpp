#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
	stringstream error_message;
	error_message << "error is here";

//		throw system_error(error_code());
		throw domain_error(error_message.str());
	return "10:00:00";
}

class TimeServer {
public:
    string GetCurrentTime() {
    	try {
    		LastFetchedTime = AskTimeServer();
    	} catch (system_error& sys_error) {
    		sys_error.what();
    		return LastFetchedTime;
    	};
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    	return LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}

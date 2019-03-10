#include <string>


using namespace std;


class Route{
	public:
		string get_source(){
			return source;
		}
		int get_distance(){
			return distance;
		}
		void set_source(const string& source_input){
			source = source_input;
			update_length();
		}
		void set_destination(const string& destination_input){
			source = destination_input;
			update_length();
		}
	private:
		string source;
		string destination;
		int distance;
		void update_length(){
			distance = calculate_length();
		}
		int calculate_length(){
			return 12345;
		}

};


int main(){

}

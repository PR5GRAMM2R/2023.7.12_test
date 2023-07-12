#include<iostream>			// vector 구현에 'std_lib_facilities.h' 가 방해되어서 이를 배제하고 코드를 작성하였습니다.
#include"vector.h"
#include"vector.cpp"		// 템플릿을 사용할 때 헤더파일과 구현파일을 따로 작성하면 안된다고 하는데, 왜 그런 것인가요?
							// 일단 이렇게 main.cpp 파일에 헤더파일과 구현파일을 같이 위치시키면 실행이 됩니다.
int main()					// 2023.06.10 배주환 작성
{
	try {
		vector<double> a {1, 2, 3};

		std::cout << a.get_size() << "\n";
		std::cout << a.get_space() << "\n";
		std::cout << a[1] << "\n";
		std::cout << a[2] << "\n";
		cout << "\n";

		a.push_back(1);

		std::cout << a.get_size() << "\n";
		std::cout << a.get_space() << "\n";
		std::cout << a[1] << "\n";
		std::cout << a[3] << "\n";
		cout << "\n";

		vector<double> b(10);

		std::cout << b.get_size() << "\n";
		std::cout << b.get_space() << "\n";
		std::cout << b[1] << "\n";
		std::cout << b[3] << "\n";
		cout << "\n";

		b = a;

		std::cout << b.get_size() << "\n";
		std::cout << b.get_space() << "\n";
		std::cout << b[1] << "\n";
		std::cout << b[3] << "\n";
		cout << "\n";

		std::cout << a.get_size() << "\n";
		std::cout << a.get_space() << "\n";
		std::cout << a[1] << "\n";
		std::cout << a[3] << "\n";
		cout << "\n";

		b = move(a);

		std::cout << b.get_size() << "\n";
		std::cout << b.get_space() << "\n";
		std::cout << b[1] << "\n";
		std::cout << b[3] << "\n";
		cout << "\n";

		std::cout << a.get_size() << "\n";
		std::cout << a.get_space() << "\n";
		std::cout << a[1] << "\n";
		std::cout << a[3] << "\n";
		cout << "\n";
	}

	catch (vector<double>::resizing_error) {
		std::cout << "[ ERROR : resizing_error ]\n";
	}
	catch (vector<double>::no_data) {
		std::cout << "[ ERROR : no_data ]\n";
	}
	catch (vector<double>::vector_overflowed) {
		std::cout << "[ ERROR : vector_overflowed ]\n";
	}
	catch (...) {
		std::cout << "[ ERROR : undefined_error ]\n";
	}
}

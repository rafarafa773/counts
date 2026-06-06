#include "crow.h"
#include <gmpxx.h>
#include <sstream>
#include <fstream>

mpz_class fatorial(mpz_class num1) {
	if (num1 <= 1)
		return 1;
	return num1 * fatorial(num1 - 1);
}
std::string ler() {
	std::ifstream arq("index.html");
	if (!arq) return "<html><body>index.html not found</body></html>";
	std::stringstream buff;
	buff << arq.rdbuf();
	return buff.str();
}

mpz_class multi(mpz_class num1, mpz_class num2) {
	return num1*num2;
}

mpz_class divisao(mpz_class num1, mpz_class num2) {
	return num1/num2;
}

mpz_class somado(mpz_class num1, mpz_class num2) {
	return num1 + num2;
}
mpz_class subtraido(mpz_class num1, mpz_class num2) {
	return num1 - num2;
}
mpz_class resto(mpz_class num1, mpz_class num2) {
	return num1%num2;
}

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([]() {
		return ler();
	});

	CROW_ROUTE(app, "/calc")([](const crow::request& req) {
		auto n_fatorial = req.url_params.get("n");
		auto n_divisao1 = req.url_params.get("num1");
		auto n_divisao2 = req.url_params.get("num2");
		auto n_sum1 = req.url_params.get("num_sum1");
		auto n_sum2 = req.url_params.get("num_sum2");
		auto n_dim1 = req.url_params.get("num_dim1");
		auto n_dim2 = req.url_params.get("num_dim2");
		auto n_vez1 = req.url_params.get("num_sub1");
		auto n_vez2 = req.url_params.get("num_sub2");
		try {
			/* division */
			if (n_divisao1 && n_divisao2 && std::string(n_divisao1).size() && std::string(n_divisao2).size()) {
				mpz_class a{ std::string(n_divisao1) };
				mpz_class b{ std::string(n_divisao2) };
				if (b == 0) return crow::response(400, "boboca");
				mpz_class q = divisao(a, b);
				mpz_class r = resto(a, b);
				std::string out_div = ("a divisao eh " + q.get_str() + " e o resto eh " + r.get_str());
				return crow::response(out_div);/* division */
			} else if(n_sum1 && n_sum2 && std::string(n_sum1).size() && std::string(n_sum2).size()) {
				mpz_class a{ std::string(n_sum1) };
				mpz_class b{ std::string(n_sum2) };
				mpz_class r = somado(a, b);
				std::string out_sum = "a soma eh " + r.get_str();
				return crow::response(out_sum);
			} else if(n_dim1 && n_dim2 && std::string(n_dim1).size() && std::string(n_dim2).size()) {
				mpz_class a{ std::string(n_dim1) };
				mpz_class b{ std::string(n_dim2)};
				mpz_class r = subtraido(a, b);
				std::string out_sum = "the subtration is " + r.get_str();
				return crow::response(out_sum);
			} else if(n_vez1 && n_vez2 && std::string(n_vez1).size() && std::string(n_vez2).size()) {
				mpz_class a{ std::string(n_vez1)};
				mpz_class b{ std::string(n_vez2)};
				mpz_class r = multi(a, b);
				std::string out_sum = "the multiplacation is " + r.get_str();
				return crow::response(out_sum);
			}
			else { /* fatorial*/
				int n_int = std::stoi(n_fatorial);
				if (n_int > 65300 || n_int < 1) return crow::response(400, "boboca");
				mpz_class result_fatorial = fatorial(mpz_class(std::string(n_fatorial)));
				std::string out_fat = "fatorial of " + std::string(n_fatorial) + " is " + result_fatorial.get_str();
				return crow::response(out_fat);
			} /* fatorial */
		} catch (...) {
			return crow::response(400, "boboca");
		}
	});

	app.port(8080).run();
}

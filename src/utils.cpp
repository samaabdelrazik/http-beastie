#include "utils.hpp"
#include <fstream>
#include <iostream>

namespace beast = boost::beast;
namespace http = beast::http;

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.keep_alive(false);

  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  if (req.method() == http::verb::get) {
    if (req.target() == "/") {
      res.result(http::status::ok);
      res.body() = parseFile("static/index.html");
    }
    else if(req.target() == "/abdelrazik")
    {
	res.result(http::status::ok);
	res.body() = parseFile("static/abdelrazik.html");
    }
    else {
      res.result(http::status::not_found);
      res.body() = "<h1 style=\"text-align: center;\">404 Not Found</h1>";
    }
  } else {
    res.result(http::status::method_not_allowed);
    res.set(http::field::allow, "GET");
    res.body() = "<h1 style=\"text-align: center;\">405 Method Not Allowed</h1>";
  }

  res.prepare_payload();
  return res;
}

string parseFile(string path)
{
	ifstream file(path);

	string text;
	string content;

	while(getline(file, text))
	{
		content += text ;
	}
	return content;
}

#pragma once

#include <boost/beast/http.hpp>
#include <string>
#include <fstream>
using namespace std;
boost::beast::http::response<boost::beast::http::string_body> handle_request(const boost::beast::http::request<boost::beast::http::string_body>& req);

string parseFile(string path);

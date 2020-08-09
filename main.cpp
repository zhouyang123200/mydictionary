#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <boost//beast/http.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>
#include "Request/Request.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
using namespace std;

int  main(int argc, char** argv) {

    Request req{"www.baidu.com", "80"};
    string response = req.get("/");
    cout << response << endl;


    return EXIT_SUCCESS;
}

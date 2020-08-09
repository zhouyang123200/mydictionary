#pragma onece
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/version.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
using namespace std;

class Request {
    public:
        Request(string hostaddr, string port);
        ~Request();
        string get(string target);
        

    private:
        net::io_context ioc{};
        tcp::resolver resolver{ioc};
        beast::tcp_stream stream{ioc};
        beast::error_code ec;
        string hostaddr;
        string port;
};

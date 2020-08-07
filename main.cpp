#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <boost//beast/http.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>
#include <map>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
using namespace std;

int  main(int argc, char** argv) {

    string sourceWords{""};
    string objWords{""};

    // map<const string, string> dictionary {
    //     {"love", "爱"},
    //     {"death", "死亡"}
    // };

    // cout << "Welcom to my dictionary!!" << endl
    //      << "please input your words:" << endl;

    // cin >> sourceWords;
    // cout << "The result: " << dictionary.at(sourceWords) << endl;

    net::io_context ioc{};
    tcp::resolver resolver{ioc};
    beast::tcp_stream stream{ioc};

    auto const result = resolver.resolve("www.baidu.com", "80");
    stream.connect(result);

    http::request<http::string_body> req{http::verb::get, "/", 11};
    req.set(http::field::host, "www.baidu.com");
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(stream, req);

    beast::flat_buffer buffer;
    http::response<http::string_body> res;
    http::read(stream, buffer, res);

    cout << res << endl;

    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);
     


    return EXIT_SUCCESS;
}

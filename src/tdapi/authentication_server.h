#ifndef _AUTHENTICATIONSVR_H
#define _AUTHENTICATIONSVR_H

#include <httplib.h>

#include <tuple>

namespace tb
{
    namespace tdameritrade
    {
        class OneTimeOauthAgent
        {
        private:

            httplib::Server web_server;
            std::string listen_ip, redirect_uri, consumer_key, authorization_code;
            short listen_port;

        public:
            OneTimeOauthAgent();
            virtual ~OneTimeOauthAgent();

            std::tuple<
                bool,           // success
                std::string,    // authorization_code
                std::string,    // refresh_token
                std::string     // access_token
            >
            authenticateOAuth(
                std::string listen_ip,
                short listen_port,
                std::string redirect_uri,
                std::string consumer_key
            );
        };

        class ContinuousOauthAgent
        {
        private:

            httplib::Server server;
            std::string listen_ip, redirect_uri, consumer_key;

        public:

        };
    }
}

#endif
#ifndef SOCKET_HPP
 #define SOCKET_HPP

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <poll.h>
#include <sstream>
#include <signal.h>
#include <cstdlib>

#include <vector>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <ctime>

using namespace std;

// #include "user.hpp"
// #include "CommanHandler.hpp"

// class Channel;
// class User;
// class Message;
// class CommanHandler;

class Socket
{
	
	private:
		int						_port;
		string					_pass;
		vector<User*> 			_userList;

		vector<std::string>	parseIncomingMsg(std::string buffer);
	

	public:
		int						fd_server;
		string					msg;
		string					serverName;
		static bool 			active;

		struct pollfd 			clients[1024];
		// std::vector<Channel*> 	_channelList;


/*	Costructors and Deconstructors	*/
		Socket();
		~Socket();
		Socket(string pass, int port);

/*	Getters and Setters	*/
		void					setPass(std::string pass);
		std::string				getPass() const;

/*	Actions	*/
		int						createServer();
		void					initClient();
		void					pollLoop();
		void					pingClient();
		int						readInput(int client_no);
		int						acceptCall();

/*
		void					killUser(User * user);
		Channel*				findChannel(std::string name); // finds a channel by name
		void					addChannel(Channel* newChannel);
		User*					findByFd(int clientFd); // finds user by FD
		User*					findByNick(std::string nick); // finds user by nickname

		bool					free_everything();

		// CommanHandler*			handler;
*/
};

#endif
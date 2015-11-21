﻿// /**
// ############################################################################
// # GPL License                                                              #
// #                                                                          #
// # This file is part of the JIM-DB.                                         #
// # Copyright (c) 2015, Benjamin Meyer, <benjamin.meyer@tu-clausthal.de>     #
// # This program is free software: you can redistribute it and/or modify     #
// # it under the terms of the GNU General Public License as                  #
// # published by the Free Software Foundation, either version 3 of the       #
// # License, or (at your option) any later version.                          #
// #                                                                          #
// # This program is distributed in the hope that it will be useful,          #
// # but WITHOUT ANY WARRANTY; without even the implied warranty of           #
// # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
// # GNU General Public License for more details.                             #
// #                                                                          #
// # You should have received a copy of the GNU General Public License        #
// # along with this program. If not, see <http://www.gnu.org/licenses/>.     #
// ############################################################################
// **/
#pragma once
#include "iclient.h"
#define ASIO_STANDALONE
#include <asio.hpp>
namespace jimdb
{
	namespace network
	{
		class ASIOClient : public IClient
		{
		public:
			explicit ASIOClient(std::shared_ptr<asio::ip::tcp::socket> socket);
			~ASIOClient();

			bool send(std::shared_ptr<std::string> s) override;
			bool hasData() override;
			bool isConnected() const override;
			std::shared_ptr<Message> getData() override;
			int getSocketID() const override;
			void close() override;
		private:
			std::shared_ptr<asio::ip::tcp::socket> m_socket;
		};
	}
}
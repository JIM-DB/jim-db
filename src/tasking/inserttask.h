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
#include "task.h"
#include "../meta/metadata.h"

namespace jimdb
{
    namespace tasking
    {
        class InsertTask : public Task
        {
        public:
            explicit InsertTask(const std::shared_ptr<network::IClient>& client, const std::shared_ptr<network::Message> m);
            void operator()() override;
        private:
            std::shared_ptr<network::Message> m_msg;
			
			void insertMeta(const std::string& name,const rapidjson::GenericValue<rapidjson::UTF8<>>& value) const;
        };
    }
}
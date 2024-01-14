#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>

int main()
{
    std::string connectionString = "host=localhost port=5432 dbname=CppConnector user=postgres password =24e8qd";

    try
    {
        pqxx::connection connectionObject(connectionString.c_str());

        pqxx::work worker(connectionObject);

        pqxx::result response = worker.exec("SELECT * FROM testy");

        for (size_t i = 0; i < response.size(); i++)
        {
            std::cout << "id: " << response[i][0] << " username: " << response[i][1] << " user_uuid: " << response[i][2] << " password: " << response[i][3] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    system("pause");
}